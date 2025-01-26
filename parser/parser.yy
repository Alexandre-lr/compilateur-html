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
    #include "contexte.hh"
    #include "variable.hh"
    #include "noeudElement.hh"
    #include "baliseStyle.hh"
    #include "baliseImage.hh"
    #include "baliseTitre.hh"
    #include "baliseParagrahpe.hh"
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

%token                  NL
%token                  END
%token                  SI

%token                  ALORS
%token                  SINON
%token                  EGAL
%token                  DIFFERENT
%token <double>         NUMBER
%token <std::string>    IDENT

%type <ExpressionPtr>   expressionTernaire
%type <ConditionPtr>    comparaison
%type <ExpressionPtr>   operation
%left OU
%left ET
%left '-' '+'
%left '*' '/'
%precedence  NEG

%%

programme:
    instruction NL programme
    | END NL {
        YYACCEPT;
    }

instruction:
    expression  {
    }
    | affectation {
    }
    | expressionTernaire {
        double res = $1->calculer(driver.getContexte());
        std::cout << "Le résultat de l'expression ternaire est : " << res << std::endl;
    }


expressionTernaire:
    SI '(' comparaison ')' ALORS operation SINON operation {
        $$ = std::make_shared<ExpressionTernaire>($3,$6,$8);
    }

expression:
    operation {
        //Modifier cette partie pour prendre en compte la structure avec expressions
        try{
        std::cout << "#-> " << $1->calculer(driver.getContexte()) << std::endl;
        } catch (const std::exception& err){
            std::cerr << "#-> " << err.what() << std::endl;
        }
    }

affectation:
    IDENT '=' operation { 
        double val = $3->calculer(driver.getContexte());
        driver.setVariable($1,val);
    }

operation:
    NUMBER {
        $$ = std::make_shared<Constante>($1);
    }
    | IDENT {
        $$ = std::make_shared<Variable>($1);
    }
    | '(' operation ')' {
        $$ = $2;
    }
    | operation '+' operation {
        $$ = std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::plus);
    }
    | operation '-' operation {
        $$ = std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::moins);
    }
    | operation '*' operation {
        $$ = std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::multiplie);
    }
    | operation '/' operation {
        $$ = std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::divise);
    }
    | '-' operation %prec NEG {
        $$ = std::make_shared<ExpressionUnaire>($2,OperateurUnaire::neg);
    }

comparaison:
    operation EGAL operation {
        $$=std::make_shared<TestBinaire>($1,$3,OperateurBool::egal);
    }
    | operation DIFFERENT operation {
        $$=std::make_shared<TestBinaire>($1,$3,OperateurBool::different);
    }
    | operation '<' operation {
        $$=std::make_shared<TestBinaire>($1,$3,OperateurBool::pluspetit);
    }
    | operation '>' operation {
        $$=std::make_shared<TestBinaire>($1,$3,OperateurBool::plusgrand);
    }
    | comparaison ET comparaison {
        $$=std::make_shared<ConditionBinaire>($1,$3,OperateurBinaireBool::et);
    }
    | comparaison OU comparaison {
        $$=std::make_shared<ConditionBinaire>($1,$3,OperateurBinaireBool::ou);
    }
    
%%

void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
