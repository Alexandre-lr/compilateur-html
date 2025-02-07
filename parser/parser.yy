%skeleton "lalr1.cc"
%require "3.0"

%defines
%define api.parser.class { Parser }
%define api.value.type variant
%define parse.assert

%locations

%code requires{
    #include "page.hh"
    #include "noeudCorps.hh"
    #include "noeudEnTete.hh"
#include "variable.hh"
    #include "noeudElement.hh"
    #include "baliseStyle.hh"
    #include "baliseImage.hh"
    #include "baliseTitre.hh"
    #include "baliseParagraphe.hh"
    #include "baliseCommentaire.hh"
    #include "attribut.hh"
    #include "text.hh"
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
%token END
%token PARAGRAPHE
%token BLOC DEFINE TITREPAGE
%token <std::uint8_t> TITRE
%token <std::string> TEXTE
%token ENCODAGE ICONE CSS LANGUE

%type <Propriete_t> propriete
%type <NoeudPtr> noeud instruction html

%%
html:
    instruction NL html {

    }
    | END NL {
        YYACCEPT;
    }

instruction:
    BLOC noeud {
        std::cout << $2->to_html(driver.getContexte());
    }
    | DEFINE noeud {
        std::cout << $2->to_html(driver.getContexte());

    }
    | TITREPAGE noeud {
        std::cout << $2->to_html(driver.getContexte());
    }

instruction:
    BLOC noeud {
        $$ = $2;
    }
    | DEFINE noeud {
        $$ = $2;
    }
    | TITREPAGE noeud {
        $$ = $2;
    }

noeud:
    TEXTE {
        $$ = std::make_shared<Text>($1);
    }
    | TITRE '\'' noeud '\'' {
        $$ = std::make_shared<BaliseTitre>($3, std::make_shared<Style>(), $1);
    }
    | PARAGRAPHE '\'' noeud '\'' {
        $$ = std::make_shared<BaliseParagraphe>($3, std::make_shared<Style>());
    }
    | '(' propriete ')' '{' '\'' noeud '\'' '}' {
        $$ = std::make_shared<Propriete>($2, $6);
    }

propriete:
    ENCODAGE {
        $$ = Propriete_t::encodage;
    }
    | ICONE {
        $$ = Propriete_t::icone;
    }
    | CSS {
        $$ = Propriete_t::css;
    }
    | LANGUE {
        $$ = Propriete_t::langue;
    }



%%

void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
