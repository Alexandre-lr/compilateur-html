%{

#include "scanner.hh"
#include <cstdlib>

#define YY_NO_UNISTD_H

using token = yy::Parser::token;

#undef  YY_DECL
#define YY_DECL int Scanner::yylex( yy::Parser::semantic_type * const lval, yy::Parser::location_type *loc )

/* update location on matching */
#define YY_USER_ACTION loc->step(); loc->columns(yyleng);

%}

%option c++
%option yyclass="Scanner"
%option noyywrap

%%
%{
    yylval = lval;
%}
"fin" return token::END;
"'" return '\'';
"(" return '(';
")" return ')';
"," return ',';
"{" return '{';
"}" return '}';

"P" return token::PARAGRAPHE;
"@DEFINE" return token::DEFINE;
"!" return token::BLOC;
"@TITREPAGE" return token::TITREPAGE;

(?i:encodage) {
    return token::ENCODAGE;
}

(?i:icone) {
    return token::ICONE;
}

(?i:css) {
    return token::CSS;
}

(?i:langue) {
    return token::LANGUE;
}

T{1,9} {
    yylval->build<std::uint8_t>(YYLeng());
    return token::TITRE;
}

[a-z][a-zA-Z0-9]*    {
    yylval->build<std::string>(YYText());
    return token::TEXTE;
}

[ \t] { }

"\n" {
    loc->lines();
    return token::NL;
}


%%
