/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_INCLUDE_BISON_GEN_H_INCLUDED
# define YY_YY_INCLUDE_BISON_GEN_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOKEN_INT = 258,               /* TOKEN_INT  */
    TOKEN_FLOAT = 259,             /* TOKEN_FLOAT  */
    TOKEN_BOOL = 260,              /* TOKEN_BOOL  */
    TOKEN_STRING = 261,            /* TOKEN_STRING  */
    TOKEN_NAME = 262,              /* TOKEN_NAME  */
    TOKEN_OPEN = 263,              /* TOKEN_OPEN  */
    TOKEN_CLOSE = 264,             /* TOKEN_CLOSE  */
    TOKEN_DOT = 265,               /* TOKEN_DOT  */
    TOKEN_COMMA = 266,             /* TOKEN_COMMA  */
    TOKEN_ASSIGNMENT = 267,        /* TOKEN_ASSIGNMENT  */
    TOKEN_SELECT = 268,            /* TOKEN_SELECT  */
    TOKEN_FROM = 269,              /* TOKEN_FROM  */
    TOKEN_WHERE = 270,             /* TOKEN_WHERE  */
    TOKEN_CREATE = 271,            /* TOKEN_CREATE  */
    TOKEN_DROP = 272,              /* TOKEN_DROP  */
    TOKEN_TABLE = 273,             /* TOKEN_TABLE  */
    TOKEN_DELETE = 274,            /* TOKEN_DELETE  */
    TOKEN_INSERT = 275,            /* TOKEN_INSERT  */
    TOKEN_INTO = 276,              /* TOKEN_INTO  */
    TOKEN_UPDATE = 277,            /* TOKEN_UPDATE  */
    TOKEN_SET = 278,               /* TOKEN_SET  */
    TOKEN_VALUES = 279,            /* TOKEN_VALUES  */
    TOKEN_JOIN = 280,              /* TOKEN_JOIN  */
    TOKEN_ON = 281,                /* TOKEN_ON  */
    TOKEN_LEQ = 282,               /* TOKEN_LEQ  */
    TOKEN_GEQ = 283,               /* TOKEN_GEQ  */
    TOKEN_LESS = 284,              /* TOKEN_LESS  */
    TOKEN_GREATER = 285,           /* TOKEN_GREATER  */
    TOKEN_EQ = 286,                /* TOKEN_EQ  */
    TOKEN_NEQ = 287,               /* TOKEN_NEQ  */
    TOKEN_OR = 288,                /* TOKEN_OR  */
    TOKEN_AND = 289,               /* TOKEN_AND  */
    TOKEN_NOT = 290,               /* TOKEN_NOT  */
    TOKEN_END = 291,               /* TOKEN_END  */
    TOKEN_INT_FIELD = 292,         /* TOKEN_INT_FIELD  */
    TOKEN_FLOAT_FIELD = 293,       /* TOKEN_FLOAT_FIELD  */
    TOKEN_STRING_FIELD = 294,      /* TOKEN_STRING_FIELD  */
    TOKEN_BOOL_FIELD = 295         /* TOKEN_BOOL_FIELD  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 11 "parser/bison.y"

    Node * node;
	int intValue;
    float floatValue;
    bool boolValue;
    char * stringValue;
    compareType compareType;
    logicType logicType;
    fieldType fieldType;

#line 115 "./include/bison.gen.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (Node **tree);


#endif /* !YY_YY_INCLUDE_BISON_GEN_H_INCLUDED  */
