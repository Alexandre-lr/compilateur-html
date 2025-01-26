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
fin return token::END;

"+" return '+';
"*" return '*';
"-" return '-';
"<" return '<';
">" return '>';
"ou" return token::OU;
"et" return token::ET;
"/" return '/';
"(" return '(';
")" return ')';
"==" {
    return token::EGAL;
}
"!=" {
    return token::DIFFERENT;
}
"=" return '=';

[0-9]+(\.[0-9]+)?     {
    yylval->build<double>(std::atof(YYText()));
    return token::NUMBER;
}

(?i:si) {
    return token::SI;
}

(?i:alors) {
    return token::ALORS;
}

(?i:sinon) {
    return token::SINON;
}



[a-z][a-zA-Z0-9]*    {
    yylval->build<std::string>(YYText());
    return token::IDENT;
}

[ \t] {
}

"\n"          {
    loc->lines();
    return token::NL;
}

%%
