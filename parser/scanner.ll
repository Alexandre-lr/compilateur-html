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

"'"                return token::QUOTE;
"("                return token::LPAREN;
")"                return token::RPAREN;
","                return token::COMMA;
"{"                return token::LBRACE;
"}"                return token::RBRACE;
"["                return token::LBRACKET;
"]"                return token::RBRACKET;
"@"                return token::AT;
"!"                return token::EXCLAMATION;
":"                return token::COLON;

T{1,9}             {
    yylval->build<std::uint8_t>(YYLeng());
    return token::TITRE;
}
"P"                return token::PARAGRAPHE;
"I"                return token::IMAGE;
"TITREPAGE"        return token::TITREPAGE;
"DEFINE"           return token::DEFINE;
"STYLE"           return token::STYLE;
"%%"               return token::CLIGNE;
"%%%"              return token::CMLIGNE;

(?i:encodage)      return token::ENCODAGE;
(?i:icone)         return token::ICONE;
(?i:css)           return token::CSS;
(?i:langue)        return token::LANGUE;
(?i:largeur)       return token::LARGEUR;
(?i:hauteur)       return token::HAUTEUR;
(?i:couleurfond)   return token::COULEURFOND;
(?i:couleurtexte)  return token::COULEURTEXTE;
(?i:opacite)       return token::OPACITE;
(?i:rgb)           return token::RGB;

#[a-zA-Z0-9]{6}    {
    yylval->build<std::string>(YYText());
    return token::HEX;
}

[0-9]+ {
    yylval->build<int>(std::atoi(YYText()));
    return token::CONSTANTE;
}

[a-zA-Z0-9-]*  {
    yylval->build<std::string>(YYText());
    return token::TEXTE;
}

[ \t]              ; // Ignorer les espaces et tabulations

"\n"               {
    loc->lines();
    return token::NL;
}

%%
