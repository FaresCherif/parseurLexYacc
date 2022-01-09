/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    fin = 258,
    plus = 259,
    moins = 260,
    fois = 261,
    diviser = 262,
    finProgramme = 263,
    baisserCrayon = 264,
    leverCrayon = 265,
    bleu = 266,
    rouge = 267,
    noir = 268,
    colSymb = 269,
    virgule = 270,
    chevronOuvrant = 271,
    chevronFermant = 272,
    assigne = 273,
    parOuvrant = 274,
    parFermant = 275,
    ligne = 276,
    carree = 277,
    nombreD = 278,
    var = 279
  };
#endif
/* Tokens.  */
#define fin 258
#define plus 259
#define moins 260
#define fois 261
#define diviser 262
#define finProgramme 263
#define baisserCrayon 264
#define leverCrayon 265
#define bleu 266
#define rouge 267
#define noir 268
#define colSymb 269
#define virgule 270
#define chevronOuvrant 271
#define chevronFermant 272
#define assigne 273
#define parOuvrant 274
#define parFermant 275
#define ligne 276
#define carree 277
#define nombreD 278
#define var 279

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "dessin.yy"

        int num;
	char *variable;

#line 110 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
