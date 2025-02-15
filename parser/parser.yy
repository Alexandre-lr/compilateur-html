%skeleton "lalr1.cc"
%require "3.0"

%defines
%define api.parser.class { Parser }
%define api.value.type variant
%define parse.assert

%locations

%code requires{
    #include "page.hh"
    #include "variable.hh"
    #include "noeudElement.hh"
    #include "baliseStyle.hh"
    #include "baliseImage.hh"
    #include "baliseTitre.hh"
    #include "baliseParagraphe.hh"
    #include "baliseCommentaire.hh"
    #include "attribut.hh"
    #include "texte.hh"
    #include "couleur.hh"
    #include "propriete.hh"
    #include "style.hh"
    #include "constante.hh"
    #include <iostream>


    class Scanner;
    class Driver;
}

%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%code{
    #include <iostream>
    #include <string>
    
    #include "scanner.hh"
    #include "driver.hh"

    #undef  yylex
    #define yylex scanner.yylex
}

%token NL
%token PARAGRAPHE IMAGE TITREPAGE DEFINE STYLE CLIGNE CMLIGNE
%token QUOTE LPAREN RPAREN COMMA LBRACE RBRACE LBRACKET RBRACKET AT EXCLAMATION COLON SIMPLECOMMENTAIRE MULTILIGNECOMMENTAIRE HASHTAG
%token <std::uint8_t> TITRE
%token <std::string> TEXTE HEX
%token <int> CONSTANTE
%token ENCODAGE ICONE CSS LANGUE
%token LARGEUR HAUTEUR COULEURTEXTE COULEURFOND OPACITE RGB

%type <Propriete::Propriete_t> propriete
%type <Attribut::Attribut_t> attribut
%type <NoeudPtr> page instruction bloc definition quotedtexte texte commentairesimple commentairemultiligne couleur constante /* blocTernaire style_bloc attribut_list attribut_def*/

%left ','

%%

html:
    page {
        std::cout << $1->to_html(driver.getContexte());
        std::dynamic_pointer_cast<Page>($1)->sauvegarder("./final.html", driver.getContexte());
        YYACCEPT;
    }

page:
    instruction NL page {
        if (!$3)
            $$ = std::make_shared<Page>();
        else
            $$ = $3;

        auto page_ptr = std::static_pointer_cast<Page>($$);

        auto element = std::dynamic_pointer_cast<NoeudElement>($1);
        if (element) {
            if (element->type_balise() == NoeudElement::Bloc_t::commentaire)
                page_ptr->ajouter_commentaire($1);
            else
                page_ptr->ajouter_bloc($1);
        }
        else if (std::dynamic_pointer_cast<Style>($1))
            page_ptr->ajouter_style($1);
        else if (std::dynamic_pointer_cast<Propriete>($1))
            page_ptr->modifier_propriete($1);
        else
            page_ptr->modifier_titre($1);
    }
    | instruction NL {
        $$ = std::make_shared<Page>();
        auto page_ptr = std::static_pointer_cast<Page>($$);

        auto element = std::dynamic_pointer_cast<NoeudElement>($1);
        if (element) {
            if (element->type_balise() == NoeudElement::Bloc_t::commentaire)
                page_ptr->ajouter_commentaire($1);
            else
                page_ptr->ajouter_bloc($1);
        }
        else if (std::dynamic_pointer_cast<Style>($1))
            page_ptr->ajouter_style($1);
        else if (std::dynamic_pointer_cast<Propriete>($1))
            page_ptr->modifier_propriete($1);
        else
            page_ptr->modifier_titre($1);
    }

instruction:
    EXCLAMATION bloc {
        $$ = $2;
    }
    | AT definition {
        $$ = $2;
    }
    | SIMPLECOMMENTAIRE commentairesimple {
        $$ = std::make_shared<BaliseCommentaire>($2);
    }
    | MULTILIGNECOMMENTAIRE NL commentairemultiligne NL MULTILIGNECOMMENTAIRE {
        $$ = std::make_shared<BaliseCommentaire>($3);
    }/*
    | affectation {

    }*/

bloc:
    TITRE quotedtexte {
        $$ = std::make_shared<BaliseTitre>($2, std::make_shared<Style>(), $1);
    }
    | PARAGRAPHE quotedtexte {
        $$ = std::make_shared<BaliseParagraphe>($2, std::make_shared<Style>());
    }
    | IMAGE quotedtexte {
        $$ = std::make_shared<BaliseImage>($2);
    }

definition:
    DEFINE propriete LBRACE quotedtexte RBRACE {
        $$ = std::make_shared<Propriete>($2, $4);
    }
    | TITREPAGE quotedtexte {
        $$ = $2;
    }/*
    | STYLE*/

commentairesimple:
    TEXTE {
        $$ = std::make_shared<Texte>($1);
    }

commentairemultiligne:
    TEXTE {
        $$ = std::make_shared<Texte>($1);
    }
    | commentairemultiligne NL TEXTE {
        $$ = std::make_shared<Texte>($1->to_html(driver.getContexte()) + "\n\t\t " + $3);
    }

quotedtexte:
    QUOTE texte QUOTE {
        $$ = $2;
    }

texte:
    TEXTE {
        $$ = std::make_shared<Texte>($1);
    }
    | texte NL TEXTE {
        $$ = std::make_shared<Texte>($1->to_html(driver.getContexte()) + " " + $3);
    }

couleur:
    RGB LPAREN constante COMMA constante COMMA constante RPAREN {
        //TO DO
        // vérifier les valeur >0 et <255
        $$ = std::make_shared<Couleur>($3, $5, $7);
    }
    | HASHTAG HEX {
        $$ = std::make_shared<Couleur>(std::make_shared<Texte>($2));
    }

constante:
    CONSTANTE {
        $$ = std::make_shared<Constante>($1);
    }

//style_bloc:
//    /* epsilon */ {
//        $$ = std::make_shared<Style>(); // Style par défaut
//    }
//    | LBRACKET attribut_list RBRACKET {
//        $$ = $2;
//    }

//attribut_list_bloc:
//    attribut_def {
//        $$ = std::make_shared<Style>();
//        std::static_pointer_cast<Style>($$)->modifier_attribut($1);
//    }
//    | attribut_list_bloc COMMA attribut_def {
//        std::static_pointer_cast<Style>($1)->modifier_attribut($3);
//        $$ = $1;
//    }

//attribut_def:
//    attribut COLON noeud {
//        $$ = std::make_shared<Attribut>($1, $3);
//    }

propriete:
    ENCODAGE {
        $$ = Propriete::Propriete_t::encodage;
    }
    | ICONE {
        $$ = Propriete::Propriete_t::icone;
    }
    | CSS {
        $$ = Propriete::Propriete_t::css;
    }
    | LANGUE {
        $$ = Propriete::Propriete_t::langue;
    }

//attribut:
//    LARGEUR {
//        $$ = Attribut::Attribut_t::largeur;
//    }
//    | HAUTEUR {
//        $$ = Attribut::Attribut_t::hauteur;
//    }
//    | COULEURTEXTE {
//        $$ = Attribut::Attribut_t::couleurTexte;
//    }
//    | COULEURFOND {
//        $$ = Attribut::Attribut_t::couleurFond;
//    }
//    | OPACITE {
//        $$ = Attribut::Attribut_t::opacite;
//    }

%%

void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
