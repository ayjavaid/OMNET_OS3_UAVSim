/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DOUBLETYPE = 258,
     INTTYPE = 259,
     STRINGTYPE = 260,
     BOOLTYPE = 261,
     XMLTYPE = 262,
     TRUE_ = 263,
     FALSE_ = 264,
     THIS_ = 265,
     ASK_ = 266,
     DEFAULT_ = 267,
     CONST_ = 268,
     SIZEOF_ = 269,
     INDEX_ = 270,
     XMLDOC_ = 271,
     NAME = 272,
     INTCONSTANT = 273,
     REALCONSTANT = 274,
     STRINGCONSTANT = 275,
     EQ_ = 276,
     NE_ = 277,
     GE_ = 278,
     LE_ = 279,
     AND_ = 280,
     OR_ = 281,
     XOR_ = 282,
     NOT_ = 283,
     BINAND_ = 284,
     BINOR_ = 285,
     BINXOR_ = 286,
     BINCOMPL_ = 287,
     SHIFTLEFT_ = 288,
     SHIFTRIGHT_ = 289,
     INVALID_CHAR = 290,
     UMIN_ = 291
   };
#endif
/* Tokens.  */
#define DOUBLETYPE 258
#define INTTYPE 259
#define STRINGTYPE 260
#define BOOLTYPE 261
#define XMLTYPE 262
#define TRUE_ 263
#define FALSE_ 264
#define THIS_ 265
#define ASK_ 266
#define DEFAULT_ 267
#define CONST_ 268
#define SIZEOF_ 269
#define INDEX_ 270
#define XMLDOC_ 271
#define NAME 272
#define INTCONSTANT 273
#define REALCONSTANT 274
#define STRINGCONSTANT 275
#define EQ_ 276
#define NE_ 277
#define GE_ 278
#define LE_ 279
#define AND_ 280
#define OR_ 281
#define XOR_ 282
#define NOT_ 283
#define BINAND_ 284
#define BINOR_ 285
#define BINXOR_ 286
#define BINCOMPL_ 287
#define SHIFTLEFT_ 288
#define SHIFTRIGHT_ 289
#define INVALID_CHAR 290
#define UMIN_ 291




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE expryylval;


