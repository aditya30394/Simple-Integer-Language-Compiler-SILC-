/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
    TRUE = 258,
    FALSE = 259,
    AND = 260,
    OR = 261,
    NOT = 262,
    DECL = 263,
    ENDDECL = 264,
    MAIN = 265,
    READ = 266,
    WRITE = 267,
    ASSIGN = 268,
    SEMICOLON = 269,
    WHILE = 270,
    DO = 271,
    ENDWHILE = 272,
    IF = 273,
    THEN = 274,
    ELSE = 275,
    LT = 276,
    EQ = 277,
    LE = 278,
    GE = 279,
    GT = 280,
    NE = 281,
    END = 282,
    ENDIF = 283,
    INT = 284,
    BEGINP = 285,
    BOOL = 286,
    NUMBER = 287,
    ID = 288,
    RETURN = 289
  };
#endif
/* Tokens.  */
#define TRUE 258
#define FALSE 259
#define AND 260
#define OR 261
#define NOT 262
#define DECL 263
#define ENDDECL 264
#define MAIN 265
#define READ 266
#define WRITE 267
#define ASSIGN 268
#define SEMICOLON 269
#define WHILE 270
#define DO 271
#define ENDWHILE 272
#define IF 273
#define THEN 274
#define ELSE 275
#define LT 276
#define EQ 277
#define LE 278
#define GE 279
#define GT 280
#define NE 281
#define END 282
#define ENDIF 283
#define INT 284
#define BEGINP 285
#define BOOL 286
#define NUMBER 287
#define ID 288
#define RETURN 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
