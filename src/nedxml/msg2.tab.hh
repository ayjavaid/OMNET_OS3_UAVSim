/* A Bison parser, made by GNU Bison 2.5.  */

/* Skeleton interface for Bison GLR parsers in C
   
      Copyright (C) 2002-2011 Free Software Foundation, Inc.
   
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
     NAMESPACE = 258,
     CPLUSPLUS = 259,
     CPLUSPLUSBODY = 260,
     MESSAGE = 261,
     PACKET = 262,
     CLASS = 263,
     STRUCT = 264,
     ENUM = 265,
     NONCOBJECT = 266,
     EXTENDS = 267,
     FIELDS = 268,
     PROPERTIES = 269,
     ABSTRACT = 270,
     READONLY = 271,
     NAME = 272,
     PROPNAME = 273,
     DOUBLECOLON = 274,
     INTCONSTANT = 275,
     REALCONSTANT = 276,
     STRINGCONSTANT = 277,
     CHARCONSTANT = 278,
     TRUE_ = 279,
     FALSE_ = 280,
     BOOLTYPE = 281,
     CHARTYPE = 282,
     SHORTTYPE = 283,
     INTTYPE = 284,
     LONGTYPE = 285,
     DOUBLETYPE = 286,
     UNSIGNED_ = 287,
     STRINGTYPE = 288,
     EQ = 289,
     NE = 290,
     GE = 291,
     LE = 292,
     AND = 293,
     OR = 294,
     XOR = 295,
     NOT = 296,
     BIN_AND = 297,
     BIN_OR = 298,
     BIN_XOR = 299,
     BIN_COMPL = 300,
     SHIFT_LEFT = 301,
     SHIFT_RIGHT = 302,
     CHAR = 303,
     INVALID_CHAR = 304,
     UMIN = 305
   };
#endif


#ifndef YYSTYPE
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{

  int first_line;
  int first_column;
  int last_line;
  int last_column;

} YYLTYPE;
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



extern YYSTYPE msg2yylval;

extern YYLTYPE msg2yylloc;


