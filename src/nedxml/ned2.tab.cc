/* A Bison parser, made by GNU Bison 2.5.  */

/* Skeleton implementation for Bison GLR parsers in C
   
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

/* C GLR parser skeleton written by Paul Hilfinger.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1


/* Substitute the variable and function names.  */
#define yyparse ned2yyparse
#define yylex   ned2yylex
#define yyerror ned2yyerror
#define yylval  ned2yylval
#define yychar  ned2yychar
#define yydebug ned2yydebug
#define yynerrs ned2yynerrs
#define yylloc  ned2yylloc

/* Copy the first part of user declarations.  */

/* Line 172 of glr.c  */
#line 75 "ned2.y"


#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include "nedyydefs.h"
#include "nederror.h"
#include "nedexception.h"
#include "commonutil.h"
#include "stringutil.h"

#define YYDEBUG 1           /* allow debugging */
#define YYDEBUGGING_ON 0    /* turn on/off debugging */

#if YYDEBUG != 0
#define YYERROR_VERBOSE     /* more detailed error messages */
#include <string.h>         /* YYVERBOSE needs it */
#endif

/* increase GLR stack -- with the default 200 some NED files have reportedly caused a "memory exhausted" error */
#define YYINITDEPTH 500

#define yylloc ned2yylloc
#define yyin ned2yyin
#define yyout ned2yyout
#define yyrestart ned2yyrestart
#define yy_scan_string ned2yy_scan_string
#define yy_delete_buffer ned2yy_delete_buffer
extern FILE *yyin;
extern FILE *yyout;
struct yy_buffer_state;
struct yy_buffer_state *yy_scan_string(const char *str);
void yy_delete_buffer(struct yy_buffer_state *);
void yyrestart(FILE *);
int yylex();
void yyerror (const char *s);

#include "nedparser.h"
#include "nedfilebuffer.h"
#include "nedelements.h"
#include "nedutil.h"
#include "nedyylib.h"

USING_NAMESPACE

static struct NED2ParserState
{
    bool inTypes;
    bool inConnGroup;
    std::stack<NEDElement *> propertyscope; // top(): where to insert properties as we parse them
    std::stack<NEDElement *> blockscope;    // top(): where to insert parameters, gates, etc
    std::stack<NEDElement *> typescope;     // top(): as blockscope, but ignore submodules and connection channels

    /* tmp flags, used with param, gate and conn */
    int paramType;
    int gateType;
    bool isVolatile;
    bool isDefault;
    YYLTYPE exprPos;
    int subgate;
    std::vector<NEDElement *> propvals; // temporarily collects property values

    /* tmp flags, used with msg fields */
    bool isAbstract;
    bool isReadonly;

    /* NED-II: modules, channels */
    NedFileElement *nedfile;
    CommentElement *comment;
    PackageElement *package;
    ImportElement *import;
    PropertyDeclElement *propertydecl;
    ExtendsElement *extends;
    InterfaceNameElement *interfacename;
    NEDElement *component;  // compound/simple module, module interface, channel or channel interface
    ParametersElement *parameters;
    ParamElement *param;
    PropertyElement *property;
    PropertyKeyElement *propkey;
    TypesElement *types;
    GatesElement *gates;
    GateElement *gate;
    SubmodulesElement *submods;
    SubmoduleElement *submod;
    ConnectionsElement *conns;
    ConnectionGroupElement *conngroup;
    ConnectionElement *conn;
    LoopElement *loop;
    ConditionElement *condition;
} ps;


static void resetParserState()
{
    static NED2ParserState cleanps;
    ps = cleanps;
}

static NED2ParserState globalps;  // for error recovery

static void restoreGlobalParserState()  // for error recovery
{
    ps = globalps;
}

static void assertNonEmpty(std::stack<NEDElement *>& somescope)
{
    // for error recovery: STL stack::top() crashes if stack is empty
    if (somescope.empty())
    {
        INTERNAL_ERROR0(NULL, "error during parsing: scope stack empty");
        somescope.push(NULL);
    }
}



/* Line 172 of glr.c  */
#line 184 "ned2.tab.cc"



#include "ned2.tab.hh"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template,
   here we set the default value of $$ to a zeroed-out value.
   Since the default value is undefined, this behavior is
   technically correct.  */
static YYSTYPE yyval_default;

/* Copy the second part of user declarations.  */


/* Line 243 of glr.c  */
#line 219 "ned2.tab.cc"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif
#ifndef YYREALLOC
# define YYREALLOC realloc
#endif

#define YYSIZEMAX ((size_t) -1)

#ifdef __cplusplus
   typedef bool yybool;
#else
   typedef unsigned char yybool;
#endif
#define yytrue 1
#define yyfalse 0

#ifndef YYSETJMP
# include <setjmp.h>
# define YYJMP_BUF jmp_buf
# define YYSETJMP(env) setjmp (env)
# define YYLONGJMP(env, val) longjmp (env, val)
#endif

/*-----------------.
| GCC extensions.  |
`-----------------*/

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5) \
      || (defined __STRICT_ANSI__ && __STRICT_ANSI__))
#  define __attribute__(Spec) /* empty */
# endif
#endif

#define YYOPTIONAL_LOC(Name) Name

#ifndef YYASSERT
# define YYASSERT(condition) ((void) ((condition) || (abort (), 0)))
#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  86
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1338

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  93
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  141
/* YYNRULES -- Number of rules.  */
#define YYNRULES  341
/* YYNRULES -- Number of states.  */
#define YYNSTATES  587
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 22
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYTRANSLATE(X) -- Bison symbol number corresponding to X.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   325

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    92,    78,     2,     2,
      84,    85,    76,    74,    90,    75,    83,    77,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    71,    81,
      73,    91,    72,    70,    86,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    87,     2,    88,    79,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    89,     2,    82,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    80
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     6,     8,    10,    11,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    36,    38,
      42,    46,    50,    54,    58,    62,    66,    70,    74,    78,
      82,    86,    90,    94,    96,   100,   104,   106,   109,   112,
     115,   117,   119,   121,   125,   132,   136,   142,   144,   145,
     149,   151,   153,   156,   157,   163,   164,   169,   170,   173,
     176,   181,   183,   187,   189,   191,   192,   198,   199,   204,
     207,   208,   212,   214,   215,   222,   223,   228,   229,   239,
     240,   245,   246,   256,   257,   262,   263,   270,   271,   276,
     278,   279,   284,   286,   287,   290,   292,   294,   296,   298,
     300,   304,   311,   315,   317,   322,   324,   326,   328,   330,
     332,   334,   335,   337,   342,   344,   346,   348,   349,   352,
     354,   358,   362,   366,   368,   370,   375,   380,   382,   384,
     388,   390,   394,   396,   399,   404,   407,   409,   413,   416,
     419,   422,   424,   429,   432,   438,   440,   444,   446,   450,
     452,   456,   458,   460,   461,   464,   467,   469,   471,   473,
     474,   475,   480,   482,   483,   486,   488,   489,   494,   497,
     502,   506,   508,   512,   515,   517,   519,   521,   523,   524,
     525,   530,   532,   533,   536,   538,   540,   542,   544,   546,
     548,   550,   552,   554,   556,   557,   558,   563,   565,   566,
     569,   571,   574,   575,   583,   588,   595,   597,   600,   603,
     607,   614,   616,   617,   619,   620,   621,   627,   628,   633,
     635,   636,   639,   641,   643,   647,   648,   655,   657,   658,
     662,   664,   666,   668,   675,   679,   685,   689,   695,   699,
     705,   709,   711,   714,   716,   719,   723,   727,   730,   734,
     738,   742,   744,   746,   749,   752,   756,   760,   763,   767,
     771,   774,   775,   777,   778,   784,   786,   789,   794,   795,
     798,   801,   805,   807,   809,   813,   818,   822,   826,   830,
     834,   838,   842,   845,   849,   853,   857,   861,   865,   869,
     873,   877,   881,   884,   888,   892,   896,   899,   903,   907,
     913,   918,   923,   928,   932,   937,   944,   953,   964,   977,
     992,  1009,  1028,  1049,  1072,  1074,  1076,  1078,  1080,  1082,
    1084,  1086,  1090,  1094,  1101,  1103,  1107,  1112,  1114,  1116,
    1118,  1120,  1122,  1124,  1126,  1128,  1130,  1134,  1138,  1141,
    1144,  1146
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const short int yyrhs[] =
{
      94,     0,    -1,    67,   223,    -1,    95,    -1,    96,    -1,
      -1,    96,    97,    -1,    97,    -1,    98,    -1,   100,    -1,
     103,    -1,   108,    -1,   109,    -1,   117,    -1,   123,    -1,
     127,    -1,   131,    -1,   135,    -1,    81,    -1,   119,     1,
      82,    -1,    11,     1,    82,    -1,   125,     1,    82,    -1,
       7,     1,    82,    -1,   129,     1,    82,    -1,     6,     1,
      82,    -1,   133,     1,    82,    -1,     8,     1,    82,    -1,
     137,     1,    82,    -1,    10,     1,    82,    -1,   111,     1,
      82,    -1,     9,     1,    82,    -1,     4,    99,    81,    -1,
      99,    83,    45,    -1,    45,    -1,     3,   101,    81,    -1,
     101,    83,   102,    -1,   102,    -1,   102,    45,    -1,   102,
      76,    -1,   102,    52,    -1,    45,    -1,    76,    -1,    52,
      -1,   104,   151,    81,    -1,   104,    84,   105,    85,   151,
      81,    -1,     5,    86,    46,    -1,     5,    86,    46,    87,
      88,    -1,   106,    -1,    -1,   106,    81,   107,    -1,   107,
      -1,   166,    -1,   159,    81,    -1,    -1,   111,    89,   110,
     139,    82,    -1,    -1,     9,    45,   112,   113,    -1,    -1,
      12,   114,    -1,    13,   115,    -1,    12,   114,    13,   115,
      -1,    99,    -1,   115,    90,   116,    -1,   116,    -1,    99,
      -1,    -1,   119,    89,   118,   139,    82,    -1,    -1,    11,
      45,   120,   121,    -1,    12,   122,    -1,    -1,   122,    90,
     114,    -1,   114,    -1,    -1,   125,    89,   124,   139,   167,
      82,    -1,    -1,     7,    45,   126,   113,    -1,    -1,   129,
      89,   128,   139,   167,   176,   182,   193,    82,    -1,    -1,
       6,    45,   130,   113,    -1,    -1,   133,    89,   132,   139,
     167,   176,   182,   193,    82,    -1,    -1,     8,    45,   134,
     113,    -1,    -1,   137,    89,   136,   139,   167,    82,    -1,
      -1,    10,    45,   138,   121,    -1,   141,    -1,    -1,    15,
      71,   140,   141,    -1,   142,    -1,    -1,   142,   143,    -1,
     143,    -1,   144,    -1,   158,    -1,   145,    -1,   147,    -1,
     146,   151,    81,    -1,   146,   151,    91,   150,   151,    81,
      -1,   149,   148,    45,    -1,    45,    -1,   153,    91,   150,
      81,    -1,    20,    -1,    21,    -1,    22,    -1,    23,    -1,
      24,    -1,    25,    -1,    -1,   222,    -1,    38,    84,   222,
      85,    -1,    38,    -1,    39,    -1,   152,    -1,    -1,   152,
     159,    -1,   159,    -1,   154,    83,   155,    -1,   154,    83,
      43,    -1,   154,    83,   155,    -1,   155,    -1,   156,    -1,
     156,    87,   157,    88,    -1,   156,    87,    76,    88,    -1,
      52,    -1,    45,    -1,    45,    92,    45,    -1,     9,    -1,
      89,   157,    82,    -1,    76,    -1,   156,    45,    -1,   156,
      89,   157,    82,    -1,   156,    76,    -1,    47,    -1,    47,
      34,    47,    -1,    34,    47,    -1,    47,    34,    -1,   159,
      81,    -1,   160,    -1,   160,    84,   161,    85,    -1,    86,
      46,    -1,    86,    46,    87,    46,    88,    -1,   162,    -1,
     162,    81,   163,    -1,   163,    -1,   166,    91,   164,    -1,
     164,    -1,   164,    90,   165,    -1,   165,    -1,   166,    -1,
      -1,   166,    68,    -1,   166,    49,    -1,    68,    -1,    49,
      -1,   168,    -1,    -1,    -1,    16,    71,   169,   170,    -1,
     171,    -1,    -1,   171,   172,    -1,   172,    -1,    -1,   174,
     173,   151,    81,    -1,   175,    45,    -1,   175,    45,    87,
      88,    -1,   175,    45,   221,    -1,    45,    -1,    45,    87,
      88,    -1,    45,   221,    -1,    26,    -1,    27,    -1,    28,
      -1,   177,    -1,    -1,    -1,    14,    71,   178,   179,    -1,
     180,    -1,    -1,   180,   181,    -1,   181,    -1,   103,    -1,
     109,    -1,   117,    -1,   123,    -1,   127,    -1,   131,    -1,
     135,    -1,    81,    -1,   183,    -1,    -1,    -1,    17,    71,
     184,   185,    -1,   186,    -1,    -1,   186,   187,    -1,   187,
      -1,   189,    81,    -1,    -1,   189,    89,   188,   139,   167,
      82,   233,    -1,   190,    71,    99,   192,    -1,   190,    71,
     191,    13,    99,   192,    -1,    45,    -1,    45,   221,    -1,
      73,    72,    -1,    73,   222,    72,    -1,    73,    38,    84,
     222,    85,    72,    -1,   220,    -1,    -1,   194,    -1,    -1,
      -1,    18,    19,    71,   195,   197,    -1,    -1,    18,    71,
     196,   197,    -1,   198,    -1,    -1,   198,   199,    -1,   199,
      -1,   200,    -1,   206,   202,    81,    -1,    -1,   202,    89,
     201,   198,    82,   233,    -1,   203,    -1,    -1,   203,    90,
     204,    -1,   204,    -1,   205,    -1,   220,    -1,    30,    45,
      91,   222,    34,   222,    -1,   207,    31,   211,    -1,   207,
      31,   216,    31,   211,    -1,   207,    32,   211,    -1,   207,
      32,   216,    32,   211,    -1,   207,    33,   211,    -1,   207,
      33,   216,    33,   211,    -1,   208,    83,   209,    -1,   210,
      -1,    45,   221,    -1,    45,    -1,    45,   215,    -1,    45,
     215,   221,    -1,    45,   215,    51,    -1,    45,   215,    -1,
      45,   215,   221,    -1,    45,   215,    51,    -1,   212,    83,
     213,    -1,   214,    -1,    45,    -1,    45,   221,    -1,    45,
     215,    -1,    45,   215,   221,    -1,    45,   215,    51,    -1,
      45,   215,    -1,    45,   215,   221,    -1,    45,   215,    51,
      -1,    92,    45,    -1,    -1,   218,    -1,    -1,   218,    89,
     217,   139,    82,    -1,   219,    -1,   219,    99,    -1,   219,
     191,    13,    99,    -1,    -1,    45,    71,    -1,    29,   222,
      -1,    87,   222,    88,    -1,   223,    -1,   224,    -1,    84,
     223,    85,    -1,    40,    84,   223,    85,    -1,   223,    74,
     223,    -1,   223,    75,   223,    -1,   223,    76,   223,    -1,
     223,    77,   223,    -1,   223,    78,   223,    -1,   223,    79,
     223,    -1,    75,   223,    -1,   223,    53,   223,    -1,   223,
      54,   223,    -1,   223,    72,   223,    -1,   223,    55,   223,
      -1,   223,    73,   223,    -1,   223,    56,   223,    -1,   223,
      57,   223,    -1,   223,    58,   223,    -1,   223,    59,   223,
      -1,    60,   223,    -1,   223,    61,   223,    -1,   223,    62,
     223,    -1,   223,    63,   223,    -1,    64,   223,    -1,   223,
      65,   223,    -1,   223,    66,   223,    -1,   223,    70,   223,
      71,   223,    -1,    21,    84,   223,    85,    -1,    20,    84,
     223,    85,    -1,    22,    84,   223,    85,    -1,   225,    84,
      85,    -1,   225,    84,   223,    85,    -1,   225,    84,   223,
      90,   223,    85,    -1,   225,    84,   223,    90,   223,    90,
     223,    85,    -1,   225,    84,   223,    90,   223,    90,   223,
      90,   223,    85,    -1,   225,    84,   223,    90,   223,    90,
     223,    90,   223,    90,   223,    85,    -1,   225,    84,   223,
      90,   223,    90,   223,    90,   223,    90,   223,    90,   223,
      85,    -1,   225,    84,   223,    90,   223,    90,   223,    90,
     223,    90,   223,    90,   223,    90,   223,    85,    -1,   225,
      84,   223,    90,   223,    90,   223,    90,   223,    90,   223,
      90,   223,    90,   223,    90,   223,    85,    -1,   225,    84,
     223,    90,   223,    90,   223,    90,   223,    90,   223,    90,
     223,    90,   223,    90,   223,    90,   223,    85,    -1,   225,
      84,   223,    90,   223,    90,   223,    90,   223,    90,   223,
      90,   223,    90,   223,    90,   223,    90,   223,    90,   223,
      85,    -1,   226,    -1,   227,    -1,   228,    -1,    45,    -1,
      44,    -1,    24,    -1,    45,    -1,    37,    83,    45,    -1,
      45,    83,    45,    -1,    45,    87,   223,    88,    83,    45,
      -1,    42,    -1,    42,    84,    85,    -1,    41,    84,   226,
      85,    -1,   229,    -1,   230,    -1,   231,    -1,    49,    -1,
      35,    -1,    36,    -1,    47,    -1,    48,    -1,   232,    -1,
     232,    47,    45,    -1,   232,    48,    45,    -1,    47,    45,
      -1,    48,    45,    -1,    81,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   198,   198,   200,   207,   208,   212,   213,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   229,
     231,   233,   235,   237,   239,   241,   243,   245,   247,   249,
     251,   256,   266,   267,   274,   284,   285,   289,   290,   291,
     292,   293,   294,   301,   306,   314,   319,   328,   329,   333,
     334,   338,   350,   362,   361,   385,   384,   393,   395,   396,
     397,   401,   410,   411,   415,   428,   427,   451,   450,   460,
     461,   465,   466,   474,   473,   498,   497,   511,   510,   538,
     537,   551,   550,   578,   577,   594,   593,   618,   617,   630,
     639,   638,   648,   649,   653,   654,   658,   659,   663,   664,
     671,   677,   695,   702,   710,   732,   734,   736,   738,   740,
     745,   748,   752,   754,   756,   760,   768,   769,   773,   774,
     778,   779,   783,   784,   788,   789,   790,   791,   795,   796,
     797,   798,   799,   800,   801,   802,   806,   807,   808,   809,
     816,   824,   825,   829,   835,   845,   849,   850,   854,   863,
     875,   877,   882,   887,   895,   896,   897,   898,   905,   906,
     911,   910,   923,   924,   928,   932,   943,   942,   954,   959,
     965,   972,   976,   981,   990,   992,   994,  1002,  1003,  1008,
    1007,  1024,  1025,  1029,  1030,  1034,  1035,  1036,  1037,  1038,
    1039,  1040,  1041,  1048,  1049,  1054,  1053,  1066,  1067,  1071,
    1072,  1076,  1082,  1081,  1101,  1106,  1116,  1121,  1130,  1132,
    1134,  1139,  1142,  1149,  1150,  1155,  1154,  1166,  1165,  1178,
    1179,  1183,  1184,  1188,  1189,  1202,  1201,  1223,  1226,  1230,
    1235,  1243,  1244,  1248,  1263,  1268,  1273,  1279,  1285,  1289,
    1296,  1297,  1301,  1307,  1315,  1320,  1326,  1335,  1342,  1350,
    1361,  1362,  1366,  1370,  1378,  1383,  1389,  1398,  1403,  1409,
    1418,  1429,  1433,  1435,  1434,  1449,  1450,  1454,  1462,  1464,
    1472,  1485,  1491,  1501,  1502,  1504,  1507,  1509,  1511,  1513,
    1515,  1517,  1520,  1524,  1526,  1528,  1530,  1532,  1534,  1537,
    1539,  1541,  1544,  1548,  1550,  1552,  1555,  1558,  1560,  1562,
    1565,  1567,  1569,  1572,  1574,  1576,  1578,  1580,  1582,  1584,
    1586,  1588,  1590,  1592,  1598,  1599,  1600,  1604,  1605,  1606,
    1610,  1612,  1614,  1616,  1621,  1623,  1625,  1630,  1631,  1632,
    1636,  1641,  1643,  1648,  1650,  1652,  1657,  1658,  1659,  1660,
    1664,  1665
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IMPORT", "PACKAGE", "PROPERTY",
  "MODULE", "SIMPLE", "NETWORK", "CHANNEL", "MODULEINTERFACE",
  "CHANNELINTERFACE", "EXTENDS", "LIKE", "TYPES", "PARAMETERS", "GATES",
  "SUBMODULES", "CONNECTIONS", "ALLOWUNCONNECTED", "DOUBLETYPE", "INTTYPE",
  "STRINGTYPE", "BOOLTYPE", "XMLTYPE", "VOLATILE", "INPUT_", "OUTPUT_",
  "INOUT_", "IF", "FOR", "RIGHTARROW", "LEFTARROW", "DBLARROW", "TO",
  "TRUE_", "FALSE_", "THIS_", "DEFAULT", "ASK", "CONST_", "SIZEOF",
  "INDEX_", "TYPENAME", "XMLDOC", "NAME", "PROPNAME", "INTCONSTANT",
  "REALCONSTANT", "STRINGCONSTANT", "CHARCONSTANT", "PLUSPLUS",
  "DOUBLEASTERISK", "EQ", "NE", "GE", "LE", "AND", "OR", "XOR", "NOT",
  "BIN_AND", "BIN_OR", "BIN_XOR", "BIN_COMPL", "SHIFT_LEFT", "SHIFT_RIGHT",
  "EXPRESSION_SELECTOR", "CHAR", "INVALID_CHAR", "'?'", "':'", "'>'",
  "'<'", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "UMIN", "';'", "'}'",
  "'.'", "'('", "')'", "'@'", "'['", "']'", "'{'", "','", "'='", "'$'",
  "$accept", "startsymbol", "nedfile", "definitions", "definition",
  "packagedeclaration", "dottedname", "import", "importspec", "importname",
  "propertydecl", "propertydecl_header", "opt_propertydecl_keys",
  "propertydecl_keys", "propertydecl_key", "fileproperty",
  "channeldefinition", "$@1", "channelheader", "$@2", "opt_inheritance",
  "extendsname", "likenames", "likename", "channelinterfacedefinition",
  "$@3", "channelinterfaceheader", "$@4", "opt_interfaceinheritance",
  "extendsnames", "simplemoduledefinition", "$@5", "simplemoduleheader",
  "$@6", "compoundmoduledefinition", "$@7", "compoundmoduleheader", "$@8",
  "networkdefinition", "$@9", "networkheader", "$@10",
  "moduleinterfacedefinition", "$@11", "moduleinterfaceheader", "$@12",
  "opt_paramblock", "$@13", "opt_params", "params", "paramsitem", "param",
  "param_typenamevalue", "param_typename", "pattern_value", "paramtype",
  "opt_volatile", "paramvalue", "opt_inline_properties",
  "inline_properties", "pattern", "pattern2", "pattern_elem",
  "pattern_name", "pattern_index", "property", "property_namevalue",
  "property_name", "opt_property_keys", "property_keys", "property_key",
  "property_values", "property_value", "property_literal", "opt_gateblock",
  "gateblock", "$@14", "opt_gates", "gates", "gate", "$@15",
  "gate_typenamesize", "gatetype", "opt_typeblock", "typeblock", "$@16",
  "opt_localtypes", "localtypes", "localtype", "opt_submodblock",
  "submodblock", "$@17", "opt_submodules", "submodules", "submodule",
  "$@18", "submoduleheader", "submodulename", "likeexpr", "opt_condition",
  "opt_connblock", "connblock", "$@19", "$@20", "opt_connections",
  "connections", "connectionsitem", "connectiongroup", "$@21",
  "opt_loops_and_conditions", "loops_and_conditions", "loop_or_condition",
  "loop", "connection", "leftgatespec", "leftmod", "leftgate",
  "parentleftgate", "rightgatespec", "rightmod", "rightgate",
  "parentrightgate", "opt_subgate", "channelspec", "$@22",
  "channelspec_header", "opt_channelname", "condition", "vector",
  "expression", "expr", "simple_expr", "funcname", "identifier",
  "special_expr", "literal", "stringliteral", "boolliteral", "numliteral",
  "quantity", "opt_semicolon", 0
};
#endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    93,    94,    94,    95,    95,    96,    96,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    98,    99,    99,   100,   101,   101,   102,   102,   102,
     102,   102,   102,   103,   103,   104,   104,   105,   105,   106,
     106,   107,   108,   110,   109,   112,   111,   113,   113,   113,
     113,   114,   115,   115,   116,   118,   117,   120,   119,   121,
     121,   122,   122,   124,   123,   126,   125,   128,   127,   130,
     129,   132,   131,   134,   133,   136,   135,   138,   137,   139,
     140,   139,   141,   141,   142,   142,   143,   143,   144,   144,
     145,   145,   146,   146,   147,   148,   148,   148,   148,   148,
     149,   149,   150,   150,   150,   150,   151,   151,   152,   152,
     153,   153,   154,   154,   155,   155,   155,   155,   156,   156,
     156,   156,   156,   156,   156,   156,   157,   157,   157,   157,
     158,   159,   159,   160,   160,   161,   162,   162,   163,   163,
     164,   164,   165,   165,   166,   166,   166,   166,   167,   167,
     169,   168,   170,   170,   171,   171,   173,   172,   174,   174,
     174,   174,   174,   174,   175,   175,   175,   176,   176,   178,
     177,   179,   179,   180,   180,   181,   181,   181,   181,   181,
     181,   181,   181,   182,   182,   184,   183,   185,   185,   186,
     186,   187,   188,   187,   189,   189,   190,   190,   191,   191,
     191,   192,   192,   193,   193,   195,   194,   196,   194,   197,
     197,   198,   198,   199,   199,   201,   200,   202,   202,   203,
     203,   204,   204,   205,   206,   206,   206,   206,   206,   206,
     207,   207,   208,   208,   209,   209,   209,   210,   210,   210,
     211,   211,   212,   212,   213,   213,   213,   214,   214,   214,
     215,   215,   216,   217,   216,   218,   218,   218,   219,   219,
     220,   221,   222,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   224,   224,   224,   225,   225,   225,
     226,   226,   226,   226,   227,   227,   227,   228,   228,   228,
     229,   230,   230,   231,   231,   231,   232,   232,   232,   232,
     233,   233
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     2,     1,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     2,     2,     2,
       1,     1,     1,     3,     6,     3,     5,     1,     0,     3,
       1,     1,     2,     0,     5,     0,     4,     0,     2,     2,
       4,     1,     3,     1,     1,     0,     5,     0,     4,     2,
       0,     3,     1,     0,     6,     0,     4,     0,     9,     0,
       4,     0,     9,     0,     4,     0,     6,     0,     4,     1,
       0,     4,     1,     0,     2,     1,     1,     1,     1,     1,
       3,     6,     3,     1,     4,     1,     1,     1,     1,     1,
       1,     0,     1,     4,     1,     1,     1,     0,     2,     1,
       3,     3,     3,     1,     1,     4,     4,     1,     1,     3,
       1,     3,     1,     2,     4,     2,     1,     3,     2,     2,
       2,     1,     4,     2,     5,     1,     3,     1,     3,     1,
       3,     1,     1,     0,     2,     2,     1,     1,     1,     0,
       0,     4,     1,     0,     2,     1,     0,     4,     2,     4,
       3,     1,     3,     2,     1,     1,     1,     1,     0,     0,
       4,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     0,     4,     1,     0,     2,
       1,     2,     0,     7,     4,     6,     1,     2,     2,     3,
       6,     1,     0,     1,     0,     0,     5,     0,     4,     1,
       0,     2,     1,     1,     3,     0,     6,     1,     0,     3,
       1,     1,     1,     6,     3,     5,     3,     5,     3,     5,
       3,     1,     2,     1,     2,     3,     3,     2,     3,     3,
       3,     1,     1,     2,     2,     3,     3,     2,     3,     3,
       2,     0,     1,     0,     5,     1,     2,     4,     0,     2,
       2,     3,     1,     1,     3,     4,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     2,     3,     3,     5,
       4,     4,     4,     3,     4,     6,     8,    10,    12,    14,
      16,    18,    20,    22,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     6,     1,     3,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     2,     2,
       1,     0
};

/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const unsigned char yydprec[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const unsigned char yymerger[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0
};

/* YYDEFACT[S] -- default reduction number in state S.  Performed when
   YYTABLE doesn't specify something else to do.  Zero means the default
   is an error.  */
static const unsigned short int yydefact[] =
{
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,     0,     0,     3,     4,     7,     8,     9,    10,
     117,    11,    12,     0,    13,     0,    14,     0,    15,     0,
      16,     0,    17,     0,     0,   141,    40,    42,    41,     0,
      36,    33,     0,     0,     0,    79,     0,    75,     0,    83,
       0,    55,     0,    87,     0,    67,     0,     0,     0,   319,
     331,   332,     0,     0,     0,   324,   318,   320,   333,   334,
     330,     0,     0,     0,     0,     2,   273,     0,   314,   315,
     316,   327,   328,   329,   335,   143,     1,     6,    48,     0,
     116,   119,     0,    53,     0,    65,     0,    73,     0,    77,
       0,    81,     0,    85,    52,   153,    34,     0,    37,    39,
      38,    31,     0,    45,    24,    57,    22,    57,    26,    57,
      30,    57,    28,    70,    20,    70,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   338,   339,   292,   296,   282,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   157,   156,     0,    47,
      50,    51,    43,   118,    29,   111,    19,   111,    21,   111,
      23,    93,    25,    93,    27,   111,     0,   145,   147,   149,
     151,   152,    35,    32,     0,     0,     0,    80,    76,    84,
      56,     0,    88,    68,     0,     0,     0,   321,     0,   320,
       0,   325,   322,     0,   274,   283,   284,   286,   288,   289,
     290,   291,   293,   294,   295,   297,   298,     0,   285,   287,
     276,   277,   278,   279,   280,   281,   303,     0,   336,   337,
       0,   117,     0,   155,   154,   130,     0,   110,   128,   127,
     132,     0,     0,    89,    92,    95,    96,    98,   117,    99,
       0,     0,     0,   123,   124,    97,     0,     0,   159,   159,
     159,   159,   142,   153,   153,   153,    46,    61,    58,    64,
      59,    63,    72,    69,   301,   300,   302,   275,   326,     0,
       0,   304,     0,   144,     0,    49,    90,     0,     0,   136,
       0,    54,    94,     0,   105,   106,   107,   108,   109,     0,
       0,     0,   133,   135,     0,     0,   140,    66,     0,     0,
     158,   178,   178,     0,   146,   150,   152,   148,     0,     0,
       0,     0,   299,     0,    44,    93,   129,   138,   139,   131,
     100,     0,   102,   114,   115,     0,   112,   272,   121,   128,
     120,     0,     0,     0,   160,    74,     0,   194,   177,   194,
      86,    60,    62,    71,   323,   305,     0,    91,   137,   117,
       0,   104,   126,   125,   134,   163,   179,     0,   214,   193,
     214,     0,     0,     0,   174,   175,   176,   171,   161,   162,
     165,   166,     0,   182,   195,     0,     0,   213,     0,   306,
       0,   101,   113,     0,   173,   164,   117,   168,     0,     0,
       0,     0,     0,     0,   192,   185,   186,     0,   187,     0,
     188,     0,   189,     0,   190,     0,   191,     0,   180,   181,
     184,   198,     0,   217,    78,    82,     0,   172,     0,     0,
       0,   170,   183,   206,   196,   197,   200,     0,     0,   215,
     220,   307,     0,   271,   167,   169,     0,   207,   199,   201,
     202,     0,   220,     0,     0,   261,   218,   219,   222,   223,
       0,   227,   230,   231,   228,     0,     0,   241,   232,     0,
     111,     0,   212,     0,   216,   270,     0,     0,   247,   242,
     221,   225,     0,     0,   268,   268,   268,     0,   308,     0,
     159,     0,   208,     0,   204,   211,     0,     0,   260,   249,
     248,   228,   229,   224,   261,   234,     0,   251,     0,   262,
     265,   236,     0,   238,     0,   261,   240,     0,     0,     0,
     209,   212,     0,   228,   269,   257,   253,     0,     0,   263,
     266,     0,     0,     0,   244,   309,     0,   341,     0,   205,
       0,   341,   259,   258,   261,   250,   261,   235,   111,     0,
     237,   239,   246,   245,     0,   340,   203,     0,   233,   226,
     254,     0,   267,   310,     0,   210,   256,   255,   264,     0,
     311,     0,     0,   312,     0,     0,   313
};

/* YYPDEFGOTO[NTERM-NUM].  */
static const short int yydefgoto[] =
{
      -1,    13,    14,    15,    16,    17,   277,    18,    39,    40,
      19,    20,   168,   169,   170,    21,    22,   175,    23,   121,
     197,   278,   280,   281,    24,   177,    25,   125,   202,   283,
      26,   179,    27,   117,    28,   181,    29,   115,    30,   183,
      31,   119,    32,   185,    33,   123,   252,   335,   253,   254,
     255,   256,   257,   258,   259,   309,   260,   345,    89,    90,
     261,   262,   263,   264,   300,   265,   266,    35,   186,   187,
     188,   189,   190,   171,   319,   320,   375,   388,   389,   390,
     406,   391,   392,   357,   358,   393,   428,   429,   430,   378,
     379,   431,   444,   445,   446,   480,   447,   448,   483,   504,
     396,   397,   462,   450,   466,   467,   468,   469,   511,   470,
     471,   472,   473,   474,   475,   476,   526,   477,   515,   516,
     555,   517,   535,   518,   558,   519,   520,   478,   536,   438,
     347,    76,    77,    78,    79,    80,    81,    82,    83,    84,
     566
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -458
static const short int yypact[] =
{
      24,    30,    31,    -7,    39,    68,   177,   178,   190,   191,
     541,  -458,    56,   193,  -458,    40,  -458,  -458,  -458,  -458,
     340,  -458,  -458,     9,  -458,    11,  -458,    15,  -458,    18,
    -458,    19,  -458,    20,    87,   130,  -458,  -458,  -458,   350,
     182,  -458,   357,   172,   197,  -458,   201,  -458,   207,  -458,
     225,  -458,   251,  -458,   259,  -458,   266,   297,   298,  -458,
    -458,  -458,   308,   311,   314,   319,  -458,   239,   366,   372,
    -458,   541,   541,   541,   541,  1151,  -458,   341,  -458,  -458,
    -458,  -458,  -458,  -458,   264,   347,  -458,  -458,    -8,   354,
     353,  -458,   359,  -458,   369,  -458,   376,  -458,   377,  -458,
     380,  -458,   381,  -458,  -458,    -8,  -458,    30,  -458,  -458,
    -458,  -458,   409,   383,  -458,   333,  -458,   333,  -458,   333,
    -458,   333,  -458,   452,  -458,   452,   541,   541,   541,   422,
     541,   230,   384,   426,   541,  -458,  -458,  -458,  -458,  -458,
     926,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   352,   428,   435,   436,  -458,  -458,   396,   410,
    -458,   170,  -458,  -458,  -458,   179,  -458,   179,  -458,    78,
    -458,   161,  -458,   161,  -458,    78,   414,   431,  -458,   427,
    -458,   149,   182,  -458,   412,    31,    31,  -458,  -458,  -458,
    -458,    31,  -458,  -458,   959,   992,  1025,  -458,  1058,     3,
     424,  -458,  -458,   898,  -458,   286,   286,   286,   286,  1259,
    1205,  1232,   419,   344,   400,   446,   446,  1124,   286,   286,
     290,   290,   437,   437,   437,   437,  -458,   556,  -458,  -458,
     430,   353,    -8,  -458,  -458,  -458,   456,  -458,   294,  -458,
    -458,    33,   447,  -458,   187,  -458,  -458,  -458,   353,  -458,
     511,   448,   445,  -458,    -6,  -458,   459,   455,   526,   526,
     526,   526,  -458,    -8,    -8,    -8,  -458,   460,   531,   460,
     457,  -458,  -458,   458,  -458,  -458,  -458,  -458,  -458,   462,
     541,  -458,   541,  -458,   465,  -458,  -458,   504,   505,   517,
     471,  -458,  -458,   168,  -458,  -458,  -458,  -458,  -458,   509,
     408,   113,  -458,  -458,   153,    33,  -458,  -458,   484,   474,
    -458,   543,   543,   477,  -458,  -458,   170,   427,    31,    31,
      31,   515,  1151,   594,  -458,   187,  -458,  -458,   519,  -458,
    -458,   408,  -458,   483,  -458,   487,  -458,  1178,  -458,   478,
     486,   485,   491,   490,  -458,  -458,   513,   558,  -458,   558,
    -458,   457,  -458,  -458,  -458,  -458,   541,  -458,  -458,   353,
     541,  -458,  -458,  -458,  -458,   276,  -458,   516,   562,  -458,
     562,   632,   510,   507,  -458,  -458,  -458,   506,  -458,   276,
    -458,  -458,   549,    47,  -458,    58,   514,  -458,   518,  -458,
     541,  -458,  -458,   250,  -458,  -458,   353,   508,   552,   553,
     554,   557,   559,   561,  -458,  -458,  -458,   534,  -458,   535,
    -458,   538,  -458,   547,  -458,   548,  -458,   550,  -458,    47,
    -458,   563,   532,  -458,  -458,  -458,   670,  -458,   555,   539,
     295,  -458,  -458,   520,  -458,   563,  -458,   212,   567,  -458,
      82,  -458,   541,  -458,  -458,  -458,   541,  -458,  -458,  -458,
    -458,    26,    82,   541,   595,   213,  -458,    82,  -458,  -458,
     565,   568,  -458,  -458,   324,   382,   578,  -458,  -458,   708,
      78,   466,    -5,   629,  -458,  -458,   571,   599,     8,  -458,
    -458,  -458,   324,   564,   618,   620,   630,   631,  -458,   541,
     526,   590,  -458,   605,  -458,  -458,    31,   541,  -458,  -458,
    -458,   224,  -458,  -458,   237,  -458,   597,  -458,   647,   592,
      26,  -458,   650,  -458,   659,   591,  -458,   746,   614,   541,
    -458,    -5,   665,    43,  -458,    14,  -458,   655,   656,  -458,
     460,   690,   656,   656,   112,  -458,   541,   633,   627,  -458,
     541,   633,  -458,  -458,   591,  -458,   226,  -458,   179,    31,
    -458,  -458,  -458,  -458,   784,  -458,  -458,   641,  -458,  -458,
     118,   634,   460,  -458,   541,  -458,  -458,  -458,  -458,   822,
    -458,   541,   860,  -458,   541,  1091,  -458
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -458,  -458,  -458,  -458,   700,  -458,    -1,  -458,  -458,   611,
    -213,  -458,  -458,  -458,   479,  -458,  -196,  -458,  -178,  -458,
     285,  -175,   391,   401,  -173,  -458,  -172,  -458,   609,  -458,
    -167,  -458,  -165,  -458,  -163,  -458,  -152,  -458,  -151,  -458,
    -148,  -458,  -145,  -458,  -141,  -458,  -174,  -458,   385,  -458,
     496,  -458,  -458,  -458,  -458,  -458,  -458,   397,  -216,  -458,
    -458,  -458,   440,  -458,    63,  -458,     2,  -458,  -458,  -458,
     464,   481,   467,  -101,  -256,  -458,  -458,  -458,  -458,   363,
    -458,  -458,  -458,   417,  -458,  -458,  -458,  -458,   325,   394,
    -458,  -458,  -458,  -458,   312,  -458,  -458,  -458,   238,   228,
     388,  -458,  -458,  -458,   310,   265,  -444,  -458,  -458,   301,
    -458,   287,  -458,  -458,  -458,  -458,  -458,  -458,  -381,  -458,
    -458,  -458,  -457,  -138,  -458,  -458,  -458,  -446,  -369,  -304,
     -10,  -458,  -458,   646,  -458,  -458,  -458,  -458,  -458,  -458,
     240
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -318
static const short int yytable[] =
{
      75,    42,    34,   267,   191,   268,   346,   269,   488,   270,
      92,   271,    94,   321,   322,   323,    96,    34,   404,    98,
     100,   102,    91,   490,   463,   294,   282,     1,     2,     3,
       4,     5,     6,     7,     8,     9,   505,   346,   441,   312,
      44,   166,   303,     1,     2,     3,     4,     5,     6,     7,
       8,     9,     3,   408,   409,   410,   411,   412,   413,   509,
     167,   137,   138,   139,   140,   552,   383,   298,   544,    46,
     313,    41,   463,   464,   457,    36,    41,   432,   112,    43,
     299,   314,    37,   315,    45,   505,   133,   245,   465,   490,
     134,    10,   173,   246,   -93,   456,   489,   570,    93,   481,
      95,   456,    85,   247,    97,    11,    38,    99,   101,   103,
      12,   463,   464,    47,   521,   523,   204,   205,   206,   510,
     208,    11,   245,   248,   213,   551,    12,   465,   414,   433,
     249,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   237,   382,   250,   363,   348,   557,   349,   485,
     -93,   560,   561,   562,    12,   249,   553,   251,   104,   576,
     245,  -228,   191,   326,   326,   563,   246,   503,    48,    50,
     415,  -111,  -111,  -111,  -111,  -111,   247,   298,   245,   250,
     439,    52,    54,    86,   246,   279,   245,   416,   243,   456,
     299,   577,   251,   532,   247,   456,   248,  -111,  -111,  -111,
    -111,  -111,   247,   249,   105,   417,   415,   244,   113,   243,
     418,   419,    49,    51,   248,   548,   420,   108,   421,   351,
     422,   249,   248,   416,   109,    53,    55,   250,   244,   249,
     275,   423,   424,    91,   528,   425,   568,    12,   426,   340,
     251,   417,   427,   463,   464,   250,   418,   419,   110,   341,
      91,   -93,   420,   250,   421,    12,   422,    62,   251,   465,
      56,    57,    58,    12,    59,   209,   251,   423,   424,   114,
     332,   425,   333,   116,   426,    60,    61,    62,   427,   118,
      63,    64,    65,   459,    66,    67,  -243,    68,    69,    70,
     456,   460,   384,   385,   386,   487,   500,   120,   534,  -252,
      71,   163,   164,   456,    72,    56,    57,    58,   487,    59,
    -252,   387,   133,  -317,   456,    73,   134,   279,   279,   487,
      60,    61,    62,   122,    74,    63,    64,    65,   437,    66,
      67,   124,    68,    69,    70,   195,   196,   148,   149,   150,
     126,   151,   152,   463,   464,    71,   381,   522,   524,    72,
     156,   157,   158,   159,   160,   161,   158,   159,   160,   161,
      73,    91,    56,    57,    58,  -103,    59,   352,   353,    74,
    -103,   127,   128,   455,   571,  -103,   297,    60,    61,    62,
     436,   129,    63,    64,    65,   130,    66,    67,   131,    68,
      69,    70,   198,   132,   199,   148,   200,   150,    91,   151,
     152,   135,    71,   494,   495,   496,    72,   136,   156,   157,
     158,   159,   160,   161,    88,   162,    12,    73,    56,    57,
      58,   106,    59,   107,   165,   172,    74,   236,   111,    12,
     112,   174,   479,    60,    61,    62,   343,   344,    63,    64,
      65,   176,    66,    67,   193,    68,    69,    70,   178,   180,
     482,   148,   182,   184,   201,   151,   152,   207,    71,   211,
     194,   212,    72,   238,   156,   157,   158,   159,   160,   161,
     239,   241,   240,    73,   151,   152,    56,    57,    58,   527,
      59,   242,    74,   156,   157,   158,   159,   160,   161,   272,
     276,    60,    61,    62,   501,   531,    63,    64,    65,   288,
      66,    67,   273,    68,    69,    70,   161,   274,   293,   540,
     156,   157,   158,   159,   160,   161,    71,   296,   311,   301,
      72,   304,   305,   306,   307,   308,   564,   317,   502,   310,
     316,    73,   318,   112,   328,   331,   334,   329,   330,   336,
      74,   338,   337,   339,   342,   354,   355,   356,   572,   360,
     364,    56,    57,    58,   579,    59,   368,   370,   371,  -122,
     297,   582,   374,   372,   585,   377,    60,    61,    62,   373,
     395,    63,    64,    65,   376,    66,    67,   394,    68,    69,
      70,   401,   402,   403,   407,   440,   434,    45,    47,    49,
     435,    71,    51,   449,    53,    72,    55,   456,   443,   141,
     142,   143,   144,   145,   146,   147,    73,   148,   149,   150,
     454,   151,   152,    93,    95,    74,   153,    97,   154,   155,
     156,   157,   158,   159,   160,   161,    99,   101,   461,   103,
     486,   291,   506,   453,   508,   513,   292,   141,   142,   143,
     144,   145,   146,   147,   491,   148,   149,   150,   492,   151,
     152,   497,   507,   514,   153,   514,   154,   155,   156,   157,
     158,   159,   160,   161,   529,   514,   525,   530,   538,   365,
     537,   539,   542,   487,   366,   141,   142,   143,   144,   145,
     146,   147,   543,   148,   149,   150,   547,   151,   152,   550,
     554,   556,   153,   559,   154,   155,   156,   157,   158,   159,
     160,   161,   567,   575,   565,    87,   578,   399,   192,   361,
     367,   295,   400,   141,   142,   143,   144,   145,   146,   147,
     362,   148,   149,   150,   203,   151,   152,   324,   369,   359,
     153,   325,   154,   155,   156,   157,   158,   159,   160,   161,
     302,   350,   405,   380,   442,   451,   327,   458,   541,   549,
     452,   141,   142,   143,   144,   145,   146,   147,   398,   148,
     149,   150,   484,   151,   152,   493,   533,   210,   153,   512,
     154,   155,   156,   157,   158,   159,   160,   161,     0,     0,
       0,   569,     0,   498,     0,     0,     0,     0,   499,   141,
     142,   143,   144,   145,   146,   147,     0,   148,   149,   150,
       0,   151,   152,     0,     0,     0,   153,     0,   154,   155,
     156,   157,   158,   159,   160,   161,     0,     0,     0,     0,
       0,   545,     0,     0,     0,     0,   546,   141,   142,   143,
     144,   145,   146,   147,     0,   148,   149,   150,     0,   151,
     152,     0,     0,     0,   153,     0,   154,   155,   156,   157,
     158,   159,   160,   161,     0,     0,     0,     0,     0,   573,
       0,     0,     0,     0,   574,   141,   142,   143,   144,   145,
     146,   147,     0,   148,   149,   150,     0,   151,   152,     0,
       0,     0,   153,     0,   154,   155,   156,   157,   158,   159,
     160,   161,     0,     0,     0,     0,     0,   580,     0,     0,
       0,     0,   581,   141,   142,   143,   144,   145,   146,   147,
       0,   148,   149,   150,     0,   151,   152,     0,     0,     0,
     153,     0,   154,   155,   156,   157,   158,   159,   160,   161,
       0,     0,     0,     0,     0,   583,     0,     0,     0,     0,
     584,   141,   142,   143,   144,   145,   146,   147,     0,   148,
     149,   150,     0,   151,   152,     0,     0,     0,   153,     0,
     154,   155,   156,   157,   158,   159,   160,   161,     0,   141,
     142,   143,   144,   145,   146,   147,   289,   148,   149,   150,
       0,   151,   152,     0,     0,     0,   153,     0,   154,   155,
     156,   157,   158,   159,   160,   161,     0,     0,     0,     0,
       0,   214,   141,   142,   143,   144,   145,   146,   147,     0,
     148,   149,   150,     0,   151,   152,     0,     0,     0,   153,
       0,   154,   155,   156,   157,   158,   159,   160,   161,     0,
       0,     0,     0,     0,   284,   141,   142,   143,   144,   145,
     146,   147,     0,   148,   149,   150,     0,   151,   152,     0,
       0,     0,   153,     0,   154,   155,   156,   157,   158,   159,
     160,   161,     0,     0,     0,     0,     0,   285,   141,   142,
     143,   144,   145,   146,   147,     0,   148,   149,   150,     0,
     151,   152,     0,     0,     0,   153,     0,   154,   155,   156,
     157,   158,   159,   160,   161,     0,     0,     0,     0,     0,
     286,   141,   142,   143,   144,   145,   146,   147,     0,   148,
     149,   150,     0,   151,   152,     0,     0,     0,   153,     0,
     154,   155,   156,   157,   158,   159,   160,   161,     0,     0,
       0,     0,     0,   287,   141,   142,   143,   144,   145,   146,
     147,     0,   148,   149,   150,     0,   151,   152,     0,     0,
       0,   153,     0,   154,   155,   156,   157,   158,   159,   160,
     161,     0,     0,     0,     0,     0,   586,   141,   142,   143,
     144,   145,   146,   147,     0,   148,   149,   150,     0,   151,
     152,     0,     0,     0,   153,   290,   154,   155,   156,   157,
     158,   159,   160,   161,   141,   142,   143,   144,   145,   146,
     147,     0,   148,   149,   150,     0,   151,   152,     0,     0,
       0,   153,     0,   154,   155,   156,   157,   158,   159,   160,
     161,   141,   142,   143,   144,   145,   146,   147,     0,   148,
     149,   150,     0,   151,   152,     0,     0,     0,   153,     0,
     154,   155,   156,   157,   158,   159,   160,   161,   141,   142,
     143,   144,   145,     0,   147,     0,   148,   149,   150,     0,
     151,   152,     0,     0,     0,     0,     0,   154,   155,   156,
     157,   158,   159,   160,   161,   141,   142,   143,   144,   145,
       0,     0,     0,   148,   149,   150,     0,   151,   152,     0,
       0,     0,     0,     0,   154,   155,   156,   157,   158,   159,
     160,   161,   141,   142,   143,   144,     0,     0,     0,     0,
     148,   149,   150,     0,   151,   152,     0,     0,     0,     0,
       0,   154,   155,   156,   157,   158,   159,   160,   161
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const unsigned char yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     0,     7,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short int yyconfl[] =
{
       0,   272,     0,   261,     0,   268,     0,   268,     0,   268,
       0,   261,     0,   261,     0
};

static const short int yycheck[] =
{
      10,     2,     0,   177,   105,   179,   310,   181,   465,   183,
       1,   185,     1,   269,   270,   271,     1,    15,   387,     1,
       1,     1,    20,   467,    29,   241,   201,     3,     4,     5,
       6,     7,     8,     9,    10,    11,   482,   341,   407,    45,
       1,    49,   258,     3,     4,     5,     6,     7,     8,     9,
      10,    11,     5,     6,     7,     8,     9,    10,    11,    51,
      68,    71,    72,    73,    74,    51,   370,    34,   525,     1,
      76,    45,    29,    30,   443,    45,    45,    19,    83,    86,
      47,    87,    52,    89,    45,   531,    83,     9,    45,   533,
      87,    67,    90,    15,    16,    87,   465,   554,    89,    73,
      89,    87,    46,    25,    89,    81,    76,    89,    89,    89,
      86,    29,    30,    45,   495,   496,   126,   127,   128,   488,
     130,    81,     9,    45,   134,    82,    86,    45,    81,    71,
      52,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   369,    76,   330,    43,   538,    45,   463,
      82,   542,   543,    51,    86,    52,   535,    89,    81,    51,
       9,    89,   273,   274,   275,   544,    15,   481,     1,     1,
     393,    20,    21,    22,    23,    24,    25,    34,     9,    76,
     406,     1,     1,     0,    15,   196,     9,   393,    49,    87,
      47,   570,    89,   507,    25,    87,    45,    20,    21,    22,
      23,    24,    25,    52,    84,   393,   429,    68,    46,    49,
     393,   393,    45,    45,    45,   529,   393,    45,   393,    76,
     393,    52,    45,   429,    52,    45,    45,    76,    68,    52,
      91,   393,   393,   241,   500,   393,   550,    86,   393,    81,
      89,   429,   393,    29,    30,    76,   429,   429,    76,    91,
     258,    82,   429,    76,   429,    86,   429,    37,    89,    45,
      20,    21,    22,    86,    24,    45,    89,   429,   429,    82,
     290,   429,   292,    82,   429,    35,    36,    37,   429,    82,
      40,    41,    42,    81,    44,    45,    83,    47,    48,    49,
      87,    89,    26,    27,    28,    92,   480,    82,    71,    83,
      60,    47,    48,    87,    64,    20,    21,    22,    92,    24,
      83,    45,    83,    84,    87,    75,    87,   328,   329,    92,
      35,    36,    37,    82,    84,    40,    41,    42,    88,    44,
      45,    82,    47,    48,    49,    12,    13,    61,    62,    63,
      84,    65,    66,    29,    30,    60,   366,   495,   496,    64,
      74,    75,    76,    77,    78,    79,    76,    77,    78,    79,
      75,   369,    20,    21,    22,    81,    24,   314,   315,    84,
      86,    84,    84,    88,   558,    91,    92,    35,    36,    37,
     400,    83,    40,    41,    42,    84,    44,    45,    84,    47,
      48,    49,   117,    84,   119,    61,   121,    63,   406,    65,
      66,    45,    60,    31,    32,    33,    64,    45,    74,    75,
      76,    77,    78,    79,    84,    84,    86,    75,    20,    21,
      22,    81,    24,    83,    87,    81,    84,    85,    81,    86,
      83,    82,   452,    35,    36,    37,    38,    39,    40,    41,
      42,    82,    44,    45,    45,    47,    48,    49,    82,    82,
     461,    61,    82,    82,    12,    65,    66,    45,    60,    85,
      87,    45,    64,    45,    74,    75,    76,    77,    78,    79,
      45,    85,    46,    75,    65,    66,    20,    21,    22,   499,
      24,    81,    84,    74,    75,    76,    77,    78,    79,    85,
      88,    35,    36,    37,    38,   506,    40,    41,    42,    85,
      44,    45,    81,    47,    48,    49,    79,    90,    88,   520,
      74,    75,    76,    77,    78,    79,    60,    71,    83,    82,
      64,    20,    21,    22,    23,    24,   546,    82,    72,    91,
      81,    75,    16,    83,    13,    83,    81,    90,    90,    45,
      84,    34,    47,    82,    45,    71,    82,    14,   559,    82,
      45,    20,    21,    22,   574,    24,    47,    84,    81,    83,
      92,   581,    82,    88,   584,    17,    35,    36,    37,    88,
      18,    40,    41,    42,    71,    44,    45,    71,    47,    48,
      49,    81,    85,    87,    45,    87,    82,    45,    45,    45,
      82,    60,    45,    71,    45,    64,    45,    87,    45,    53,
      54,    55,    56,    57,    58,    59,    75,    61,    62,    63,
      81,    65,    66,    89,    89,    84,    70,    89,    72,    73,
      74,    75,    76,    77,    78,    79,    89,    89,    71,    89,
      45,    85,    13,    88,    45,    81,    90,    53,    54,    55,
      56,    57,    58,    59,    89,    61,    62,    63,    90,    65,
      66,    83,    91,    45,    70,    45,    72,    73,    74,    75,
      76,    77,    78,    79,    84,    45,    45,    72,    31,    85,
      83,    89,    32,    92,    90,    53,    54,    55,    56,    57,
      58,    59,    33,    61,    62,    63,    82,    65,    66,    34,
      45,    45,    70,    13,    72,    73,    74,    75,    76,    77,
      78,    79,    85,    72,    81,    15,    82,    85,   107,   328,
     335,   242,    90,    53,    54,    55,    56,    57,    58,    59,
     329,    61,    62,    63,   125,    65,    66,   273,   341,   322,
      70,   274,    72,    73,    74,    75,    76,    77,    78,    79,
     254,   311,   389,   359,   429,    85,   275,   445,   520,   531,
      90,    53,    54,    55,    56,    57,    58,    59,   380,    61,
      62,    63,   462,    65,    66,   474,   511,   131,    70,   492,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    -1,
      -1,   551,    -1,    85,    -1,    -1,    -1,    -1,    90,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    65,    66,    -1,    -1,    -1,    70,    -1,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    -1,    -1,    90,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    -1,    65,
      66,    -1,    -1,    -1,    70,    -1,    72,    73,    74,    75,
      76,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    -1,    -1,    90,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    -1,    65,    66,    -1,
      -1,    -1,    70,    -1,    72,    73,    74,    75,    76,    77,
      78,    79,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,
      -1,    -1,    90,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    -1,    65,    66,    -1,    -1,    -1,
      70,    -1,    72,    73,    74,    75,    76,    77,    78,    79,
      -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,
      90,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    -1,    65,    66,    -1,    -1,    -1,    70,    -1,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    53,
      54,    55,    56,    57,    58,    59,    88,    61,    62,    63,
      -1,    65,    66,    -1,    -1,    -1,    70,    -1,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    -1,    -1,    -1,
      -1,    85,    53,    54,    55,    56,    57,    58,    59,    -1,
      61,    62,    63,    -1,    65,    66,    -1,    -1,    -1,    70,
      -1,    72,    73,    74,    75,    76,    77,    78,    79,    -1,
      -1,    -1,    -1,    -1,    85,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    -1,    65,    66,    -1,
      -1,    -1,    70,    -1,    72,    73,    74,    75,    76,    77,
      78,    79,    -1,    -1,    -1,    -1,    -1,    85,    53,    54,
      55,    56,    57,    58,    59,    -1,    61,    62,    63,    -1,
      65,    66,    -1,    -1,    -1,    70,    -1,    72,    73,    74,
      75,    76,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,
      85,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    -1,    65,    66,    -1,    -1,    -1,    70,    -1,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    -1,
      -1,    -1,    -1,    85,    53,    54,    55,    56,    57,    58,
      59,    -1,    61,    62,    63,    -1,    65,    66,    -1,    -1,
      -1,    70,    -1,    72,    73,    74,    75,    76,    77,    78,
      79,    -1,    -1,    -1,    -1,    -1,    85,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    -1,    65,
      66,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    53,    54,    55,    56,    57,    58,
      59,    -1,    61,    62,    63,    -1,    65,    66,    -1,    -1,
      -1,    70,    -1,    72,    73,    74,    75,    76,    77,    78,
      79,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    -1,    65,    66,    -1,    -1,    -1,    70,    -1,
      72,    73,    74,    75,    76,    77,    78,    79,    53,    54,
      55,    56,    57,    -1,    59,    -1,    61,    62,    63,    -1,
      65,    66,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      75,    76,    77,    78,    79,    53,    54,    55,    56,    57,
      -1,    -1,    -1,    61,    62,    63,    -1,    65,    66,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,    77,
      78,    79,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      61,    62,    63,    -1,    65,    66,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    75,    76,    77,    78,    79
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      67,    81,    86,    94,    95,    96,    97,    98,   100,   103,
     104,   108,   109,   111,   117,   119,   123,   125,   127,   129,
     131,   133,   135,   137,   159,   160,    45,    52,    76,   101,
     102,    45,    99,    86,     1,    45,     1,    45,     1,    45,
       1,    45,     1,    45,     1,    45,    20,    21,    22,    24,
      35,    36,    37,    40,    41,    42,    44,    45,    47,    48,
      49,    60,    64,    75,    84,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,    46,     0,    97,    84,   151,
     152,   159,     1,    89,     1,    89,     1,    89,     1,    89,
       1,    89,     1,    89,    81,    84,    81,    83,    45,    52,
      76,    81,    83,    46,    82,   130,    82,   126,    82,   134,
      82,   112,    82,   138,    82,   120,    84,    84,    84,    83,
      84,    84,    84,    83,    87,    45,    45,   223,   223,   223,
     223,    53,    54,    55,    56,    57,    58,    59,    61,    62,
      63,    65,    66,    70,    72,    73,    74,    75,    76,    77,
      78,    79,    84,    47,    48,    87,    49,    68,   105,   106,
     107,   166,    81,   159,    82,   110,    82,   118,    82,   124,
      82,   128,    82,   132,    82,   136,   161,   162,   163,   164,
     165,   166,   102,    45,    87,    12,    13,   113,   113,   113,
     113,    12,   121,   121,   223,   223,   223,    45,   223,    45,
     226,    85,    45,   223,    85,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,    85,   223,    45,    45,
      46,    85,    81,    49,    68,     9,    15,    25,    45,    52,
      76,    89,   139,   141,   142,   143,   144,   145,   146,   147,
     149,   153,   154,   155,   156,   158,   159,   139,   139,   139,
     139,   139,    85,    81,    90,    91,    88,    99,   114,    99,
     115,   116,   114,   122,    85,    85,    85,    85,    85,    88,
      71,    85,    90,    88,   151,   107,    71,    92,    34,    47,
     157,    82,   143,   151,    20,    21,    22,    23,    24,   148,
      91,    83,    45,    76,    87,    89,    81,    82,    16,   167,
     168,   167,   167,   167,   163,   165,   166,   164,    13,    90,
      90,    83,   223,   223,    81,   140,    45,    47,    34,    82,
      81,    91,    45,    38,    39,   150,   222,   223,    43,    45,
     155,    76,   157,   157,    71,    82,    14,   176,   177,   176,
      82,   115,   116,   114,    45,    85,    90,   141,    47,   150,
      84,    81,    88,    88,    82,   169,    71,    17,   182,   183,
     182,   223,   151,   222,    26,    27,    28,    45,   170,   171,
     172,   174,   175,   178,    71,    18,   193,   194,   193,    85,
      90,    81,    85,    87,   221,   172,   173,    45,     6,     7,
       8,     9,    10,    11,    81,   103,   109,   111,   117,   119,
     123,   125,   127,   129,   131,   133,   135,   137,   179,   180,
     181,   184,    19,    71,    82,    82,   223,    88,   222,   151,
      87,   221,   181,    45,   185,   186,   187,   189,   190,    71,
     196,    85,    90,    88,    81,    88,    87,   221,   187,    81,
      89,    71,   195,    29,    30,    45,   197,   198,   199,   200,
     202,   203,   204,   205,   206,   207,   208,   210,   220,   223,
     188,    73,    99,   191,   197,   222,    45,    92,   215,   221,
     199,    89,    90,   202,    31,    32,    33,    83,    85,    90,
     139,    38,    72,   222,   192,   220,    13,    91,    45,    51,
     221,   201,   204,    81,    45,   211,   212,   214,   216,   218,
     219,   211,   216,   211,   216,    45,   209,   223,   167,    84,
      72,    99,   222,   198,    71,   215,   221,    83,    31,    89,
      99,   191,    32,    33,   215,    85,    90,    82,   222,   192,
      34,    82,    51,   221,    45,   213,    45,   211,   217,    13,
     211,   211,    51,   221,   223,    81,   233,    85,   222,   233,
     215,   139,    99,    85,    90,    72,    51,   221,    82,   223,
      85,    90,   223,    85,    90,   223,    85
};


/* Prevent warning if -Wmissing-prototypes.  */
int yyparse (void);

/* Error token number */
#define YYTERROR 1

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */


#define YYRHSLOC(Rhs, K) ((Rhs)[K].yystate.yyloc)
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))							\
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))

/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# define YY_LOCATION_PRINT(File, Loc)			\
    fprintf (File, "%d.%d-%d.%d",			\
	     (Loc).first_line, (Loc).first_column,	\
	     (Loc).last_line,  (Loc).last_column)
#endif


#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#define YYLEX yylex ()

YYSTYPE yylval;

YYLTYPE yylloc;

int yynerrs;
int yychar;

static const int YYEOF = 0;
static const int YYEMPTY = -2;

typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;

#define YYCHK(YYE)							     \
   do { YYRESULTTAG yyflag = YYE; if (yyflag != yyok) return yyflag; }	     \
   while (YYID (0))

#if YYDEBUG

# ifndef YYFPRINTF
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			    \
do {									    \
  if (yydebug)								    \
    {									    \
      YYFPRINTF (stderr, "%s ", Title);					    \
      yy_symbol_print (stderr, Type,					    \
		       Value, Location);  \
      YYFPRINTF (stderr, "\n");						    \
    }									    \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

#else /* !YYDEBUG */

# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)

#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
# if (! defined __cplusplus \
      || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	  && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL))
#  define YYSTACKEXPANDABLE 1
# else
#  define YYSTACKEXPANDABLE 0
# endif
#endif

#if YYSTACKEXPANDABLE
# define YY_RESERVE_GLRSTACK(Yystack)			\
  do {							\
    if (Yystack->yyspaceLeft < YYHEADROOM)		\
      yyexpandGLRStack (Yystack);			\
  } while (YYID (0))
#else
# define YY_RESERVE_GLRSTACK(Yystack)			\
  do {							\
    if (Yystack->yyspaceLeft < YYHEADROOM)		\
      yyMemoryExhausted (Yystack);			\
  } while (YYID (0))
#endif


#if YYERROR_VERBOSE

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static size_t
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      size_t yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return strlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

#endif /* !YYERROR_VERBOSE */

/** State numbers, as in LALR(1) machine */
typedef int yyStateNum;

/** Rule numbers, as in LALR(1) machine */
typedef int yyRuleNum;

/** Grammar symbol */
typedef short int yySymbol;

/** Item references, as in LALR(1) machine */
typedef short int yyItemNum;

typedef struct yyGLRState yyGLRState;
typedef struct yyGLRStateSet yyGLRStateSet;
typedef struct yySemanticOption yySemanticOption;
typedef union yyGLRStackItem yyGLRStackItem;
typedef struct yyGLRStack yyGLRStack;

struct yyGLRState {
  /** Type tag: always true.  */
  yybool yyisState;
  /** Type tag for yysemantics.  If true, yysval applies, otherwise
   *  yyfirstVal applies.  */
  yybool yyresolved;
  /** Number of corresponding LALR(1) machine state.  */
  yyStateNum yylrState;
  /** Preceding state in this stack */
  yyGLRState* yypred;
  /** Source position of the first token produced by my symbol */
  size_t yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  non-terminal corresponding to this state, threaded through
     *  yynext.  */
    yySemanticOption* yyfirstVal;
    /** Semantic value for this state.  */
    YYSTYPE yysval;
  } yysemantics;
  /** Source location for this state.  */
  YYLTYPE yyloc;
};

struct yyGLRStateSet {
  yyGLRState** yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != YYEMPTY.  */
  yybool* yylookaheadNeeds;
  size_t yysize, yycapacity;
};

struct yySemanticOption {
  /** Type tag: always false.  */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced.  */
  yyGLRState* yystate;
  /** The lookahead for this reduction.  */
  int yyrawchar;
  YYSTYPE yyval;
  YYLTYPE yyloc;
  /** Next sibling in chain of options.  To facilitate merging,
   *  options are chained in decreasing order by address.  */
  yySemanticOption* yynext;
};

/** Type of the items in the GLR stack.  The yyisState field
 *  indicates which item of the union is valid.  */
union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrState;
  /* To compute the location of the error token.  */
  yyGLRStackItem yyerror_range[3];

  YYJMP_BUF yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  size_t yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

#if YYSTACKEXPANDABLE
static void yyexpandGLRStack (yyGLRStack* yystackp);
#endif

static void yyFail (yyGLRStack* yystackp, const char* yymsg)
  __attribute__ ((__noreturn__));
static void
yyFail (yyGLRStack* yystackp, const char* yymsg)
{
  if (yymsg != NULL)
    yyerror (yymsg);
  YYLONGJMP (yystackp->yyexception_buffer, 1);
}

static void yyMemoryExhausted (yyGLRStack* yystackp)
  __attribute__ ((__noreturn__));
static void
yyMemoryExhausted (yyGLRStack* yystackp)
{
  YYLONGJMP (yystackp->yyexception_buffer, 2);
}

#if YYDEBUG || YYERROR_VERBOSE
/** A printable representation of TOKEN.  */
static inline const char*
yytokenName (yySymbol yytoken)
{
  if (yytoken == YYEMPTY)
    return "";

  return yytname[yytoken];
}
#endif

/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
 *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
 *  containing the pointer to the next state in the chain.  */
static void yyfillin (yyGLRStackItem *, int, int) __attribute__ ((__unused__));
static void
yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
{
  yyGLRState* s;
  int i;
  s = yyvsp[yylow0].yystate.yypred;
  for (i = yylow0-1; i >= yylow1; i -= 1)
    {
      YYASSERT (s->yyresolved);
      yyvsp[i].yystate.yyresolved = yytrue;
      yyvsp[i].yystate.yysemantics.yysval = s->yysemantics.yysval;
      yyvsp[i].yystate.yyloc = s->yyloc;
      s = yyvsp[i].yystate.yypred = s->yypred;
    }
}

/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
 * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
 * For convenience, always return YYLOW1.  */
static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
     __attribute__ ((__unused__));
static inline int
yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
{
  if (!yynormal && yylow1 < *yylow)
    {
      yyfillin (yyvsp, *yylow, yylow1);
      *yylow = yylow1;
    }
  return yylow1;
}

/** Perform user action for rule number YYN, with RHS length YYRHSLEN,
 *  and top stack item YYVSP.  YYLVALP points to place to put semantic
 *  value ($$), and yylocp points to place for location information
 *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT.  */
/*ARGSUSED*/ static YYRESULTTAG
yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
	      YYSTYPE* yyvalp,
	      YYLTYPE* YYOPTIONAL_LOC (yylocp),
	      yyGLRStack* yystackp
	      )
{
  yybool yynormal __attribute__ ((__unused__)) =
    (yystackp->yysplitPoint == NULL);
  int yylow;
# undef yyerrok
# define yyerrok (yystackp->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
# undef YYERROR
# define YYERROR return yyerrok, yyerr
# undef YYRECOVERING
# define YYRECOVERING() (yystackp->yyerrState != 0)
# undef yyclearin
# define yyclearin (yychar = YYEMPTY)
# undef YYFILL
# define YYFILL(N) yyfill (yyvsp, &yylow, N, yynormal)
# undef YYBACKUP
# define YYBACKUP(Token, Value)						     \
  return yyerror (YY_("syntax error: cannot back up")),     \
	 yyerrok, yyerr

  yylow = 1;
  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yysval;
  YYLLOC_DEFAULT ((*yylocp), (yyvsp - yyrhslen), yyrhslen);
  yystackp->yyerror_range[1].yystate.yyloc = *yylocp;

  switch (yyn)
    {
        case 2:

/* Line 936 of glr.c  */
#line 199 "ned2.y"
    { ps.nedfile->appendChild((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval)); }
    break;

  case 19:

/* Line 936 of glr.c  */
#line 230 "ned2.y"
    { storePos(ps.component, (*yylocp)); restoreGlobalParserState(); }
    break;

  case 20:

/* Line 936 of glr.c  */
#line 232 "ned2.y"
    { restoreGlobalParserState(); }
    break;

  case 21:

/* Line 936 of glr.c  */
#line 234 "ned2.y"
    { storePos(ps.component, (*yylocp)); restoreGlobalParserState(); }
    break;

  case 22:

/* Line 936 of glr.c  */
#line 236 "ned2.y"
    { restoreGlobalParserState(); }
    break;

  case 23:

/* Line 936 of glr.c  */
#line 238 "ned2.y"
    { storePos(ps.component, (*yylocp)); restoreGlobalParserState(); }
    break;

  case 24:

/* Line 936 of glr.c  */
#line 240 "ned2.y"
    { restoreGlobalParserState(); }
    break;

  case 25:

/* Line 936 of glr.c  */
#line 242 "ned2.y"
    { storePos(ps.component, (*yylocp)); restoreGlobalParserState(); }
    break;

  case 26:

/* Line 936 of glr.c  */
#line 244 "ned2.y"
    { restoreGlobalParserState(); }
    break;

  case 27:

/* Line 936 of glr.c  */
#line 246 "ned2.y"
    { storePos(ps.component, (*yylocp)); restoreGlobalParserState(); }
    break;

  case 28:

/* Line 936 of glr.c  */
#line 248 "ned2.y"
    { restoreGlobalParserState(); }
    break;

  case 29:

/* Line 936 of glr.c  */
#line 250 "ned2.y"
    { storePos(ps.component, (*yylocp)); restoreGlobalParserState(); }
    break;

  case 30:

/* Line 936 of glr.c  */
#line 252 "ned2.y"
    { restoreGlobalParserState(); }
    break;

  case 31:

/* Line 936 of glr.c  */
#line 257 "ned2.y"
    {
                  ps.package = (PackageElement *)createElementWithTag(NED_PACKAGE, ps.nedfile);
                  ps.package->setName(removeSpaces((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yyloc)).c_str());
                  storePos(ps.package,(*yylocp));
                  storeBannerAndRightComments(ps.package,(*yylocp));
                }
    break;

  case 34:

/* Line 936 of glr.c  */
#line 275 "ned2.y"
    {
                  ps.import = (ImportElement *)createElementWithTag(NED_IMPORT, ps.nedfile);
                  ps.import->setImportSpec(removeSpaces((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yyloc)).c_str());
                  storePos(ps.import,(*yylocp));
                  storeBannerAndRightComments(ps.import,(*yylocp));
                }
    break;

  case 43:

/* Line 936 of glr.c  */
#line 302 "ned2.y"
    {
                    storePos(ps.propertydecl, (*yylocp));
                    storeBannerAndRightComments(ps.propertydecl,(*yylocp));
                }
    break;

  case 44:

/* Line 936 of glr.c  */
#line 307 "ned2.y"
    {
                    storePos(ps.propertydecl, (*yylocp));
                    storeBannerAndRightComments(ps.propertydecl,(*yylocp));
                }
    break;

  case 45:

/* Line 936 of glr.c  */
#line 315 "ned2.y"
    {
                  ps.propertydecl = (PropertyDeclElement *)createElementWithTag(NED_PROPERTY_DECL, ps.nedfile);
                  ps.propertydecl->setName(toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yyloc)));
                }
    break;

  case 46:

/* Line 936 of glr.c  */
#line 320 "ned2.y"
    {
                  ps.propertydecl = (PropertyDeclElement *)createElementWithTag(NED_PROPERTY_DECL, ps.nedfile);
                  ps.propertydecl->setName(toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yyloc)));
                  ps.propertydecl->setIsArray(true);
                }
    break;

  case 51:

/* Line 936 of glr.c  */
#line 339 "ned2.y"
    {
                  ps.propkey = (PropertyKeyElement *)createElementWithTag(NED_PROPERTY_KEY, ps.propertydecl);
                  ps.propkey->setName(opp_trim(toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yyloc))).c_str());
                  storePos(ps.propkey, (*yylocp));
                }
    break;

  case 52:

/* Line 936 of glr.c  */
#line 351 "ned2.y"
    {
                  storePos(ps.property, (*yylocp));
                  storeBannerAndRightComments(ps.property,(*yylocp));
                }
    break;

  case 53:

/* Line 936 of glr.c  */
#line 362 "ned2.y"
    {
                  ps.typescope.push(ps.component);
                  ps.blockscope.push(ps.component);
                  ps.parameters = (ParametersElement *)createElementWithTag(NED_PARAMETERS, ps.component);
                  ps.parameters->setIsImplicit(true);
                  ps.propertyscope.push(ps.parameters);
                }
    break;

  case 54:

/* Line 936 of glr.c  */
#line 371 "ned2.y"
    {
                  ps.propertyscope.pop();
                  ps.blockscope.pop();
                  ps.component = ps.typescope.top();
                  ps.typescope.pop();
                  if (np->getStoreSourceFlag())
                      storeComponentSourceCode(ps.component, (*yylocp));
                  storePos(ps.component, (*yylocp));
                  storeTrailingComment(ps.component,(*yylocp));
                }
    break;

  case 55:

/* Line 936 of glr.c  */
#line 385 "ned2.y"
    {
                  ps.component = (ChannelElement *)createElementWithTag(NED_CHANNEL, ps.inTypes ? (NEDElement *)ps.types : (NEDElement *)ps.nedfile);
                  ((ChannelElement *)ps.component)->setName(toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yyloc)));
                }
    break;

  case 56:

/* Line 936 of glr.c  */
#line 390 "ned2.y"
    { storeBannerAndRightComments(ps.component,(*yylocp)); }
    break;

  case 61:

/* Line 936 of glr.c  */
#line 402 "ned2.y"
    {
                  ps.extends = (ExtendsElement *)createElementWithTag(NED_EXTENDS, ps.component);
                  ps.extends->setName(removeSpaces((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yyloc)).c_str());
                  storePos(ps.extends, (*yylocp));
                }
    break;

  case 64:

/* Line 936 of glr.c  */
#line 416 "ned2.y"
    {
                  ps.interfacename = (InterfaceNameElement *)createElementWithTag(NED_INTERFACE_NAME, ps.component);
                  ps.interfacename->setName(removeSpaces((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yyloc)).c_str());
                  storePos(ps.interfacename, (*yylocp));
                }
    break;

  case 65:

/* Line 936 of glr.c  */
#line 428 "ned2.y"
    {
                  ps.typescope.push(ps.component);
                  ps.blockscope.push(ps.component);
                  ps.parameters = (ParametersElement *)createElementWithTag(NED_PARAMETERS, ps.component);
                  ps.parameters->setIsImplicit(true);
                  ps.propertyscope.push(ps.parameters);
                }
    break;

  case 66:

/* Line 936 of glr.c  */
#line 437 "ned2.y"
    {
                  ps.propertyscope.pop();
                  ps.blockscope.pop();
                  ps.component = ps.typescope.top();
                  ps.typescope.pop();
                  if (np->getStoreSourceFlag())
                      storeComponentSourceCode(ps.component, (*yylocp));
                  storePos(ps.component, (*yylocp));
                  storeTrailingComment(ps.component,(*yylocp));
                }
    break;

  case 67:

/* Line 936 of glr.c  */
#line 451 "ned2.y"
    {
                  ps.component = (ChannelInterfaceElement *)createElementWithTag(NED_CHANNEL_INTERFACE, ps.inTypes ? (NEDElement *)ps.types : (NEDElement *)ps.nedfile);
                  ((ChannelInterfaceElement *)ps.component)->setName(toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yyloc)));
                }
    break;

  case 68:

/* Line 936 of glr.c  */
#line 456 "ned2.y"
    { storeBannerAndRightComments(ps.component,(*yylocp)); }
    break;

  case 73:

/* Line 936 of glr.c  */
#line 474 "ned2.y"
    {
                  ps.typescope.push(ps.component);
                  ps.blockscope.push(ps.component);
                  ps.parameters = (ParametersElement *)createElementWithTag(NED_PARAMETERS, ps.component);
                  ps.parameters->setIsImplicit(true);
                  ps.propertyscope.push(ps.parameters);
                }
    break;

  case 74:

/* Line 936 of glr.c  */
#line 484 "ned2.y"
    {
                  ps.propertyscope.pop();
                  ps.blockscope.pop();
                  ps.component = ps.typescope.top();
                  ps.typescope.pop();
                  if (np->getStoreSourceFlag())
                      storeComponentSourceCode(ps.component, (*yylocp));
                  storePos(ps.component, (*yylocp));
                  storeTrailingComment(ps.component,(*yylocp));
                }
    break;

  case 75:

/* Line 936 of glr.c  */
#line 498 "ned2.y"
    {
                  ps.component = (SimpleModuleElement *)createElementWithTag(NED_SIMPLE_MODULE, ps.inTypes ? (NEDElement *)ps.types : (NEDElement *)ps.nedfile );
                  ((SimpleModuleElement *)ps.component)->setName(toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yyloc)));
                }
    break;

  case 76:

/* Line 936 of glr.c  */
#line 503 "ned2.y"
    { storeBannerAndRightComments(ps.component,(*yylocp)); }
    break;

  case 77:

/* Line 936 of glr.c  */
#line 511 "ned2.y"
    {
                  ps.typescope.push(ps.component);
                  ps.blockscope.push(ps.component);
                  ps.parameters = (ParametersElement *)createElementWithTag(NED_PARAMETERS, ps.component);
                  ps.parameters->setIsImplicit(true);
                  ps.propertyscope.push(ps.parameters);
                }
    break;

  case 78:

/* Line 936 of glr.c  */
#line 524 "ned2.y"
    {
                  ps.propertyscope.pop();
                  ps.blockscope.pop();
                  ps.component = ps.typescope.top();
                  ps.typescope.pop();
                  if (np->getStoreSourceFlag())
                      storeComponentSourceCode(ps.component, (*yylocp));
                  storePos(ps.component, (*yylocp));
                  storeTrailingComment(ps.component,(*yylocp));
                }
    break;

  case 79:

/* Line 936 of glr.c  */
#line 538 "ned2.y"
    {
                  ps.component = (CompoundModuleElement *)createElementWithTag(NED_COMPOUND_MODULE, ps.inTypes ? (NEDElement *)ps.types : (NEDElement *)ps.nedfile );
                  ((CompoundModuleElement *)ps.component)->setName(toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yyloc)));
                }
    break;

  case 80:

/* Line 936 of glr.c  */
#line 543 "ned2.y"
    { storeBannerAndRightComments(ps.component,(*yylocp)); }
    break;

  case 81:

/* Line 936 of glr.c  */
#line 551 "ned2.y"
    {
                  ps.typescope.push(ps.component);
                  ps.blockscope.push(ps.component);
                  ps.parameters = (ParametersElement *)ps.component->getFirstChildWithTag(NED_PARAMETERS); // networkheader already created it for @isNetwork
                  ps.parameters->setIsImplicit(true);
                  ps.propertyscope.push(ps.parameters);
                }
    break;

  case 82:

/* Line 936 of glr.c  */
#line 564 "ned2.y"
    {
                  ps.propertyscope.pop();
                  ps.blockscope.pop();
                  ps.component = ps.typescope.top();
                  ps.typescope.pop();
                  if (np->getStoreSourceFlag())
                      storeComponentSourceCode(ps.component, (*yylocp));
                  storePos(ps.component, (*yylocp));
                  storeTrailingComment(ps.component,(*yylocp));
                }
    break;

  case 83:

/* Line 936 of glr.c  */
#line 578 "ned2.y"
    {
                  ps.component = (CompoundModuleElement *)createElementWithTag(NED_COMPOUND_MODULE, ps.inTypes ? (NEDElement *)ps.types : (NEDElement *)ps.nedfile );
                  ((CompoundModuleElement *)ps.component)->setName(toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yyloc)));
                }
    break;

  case 84:

/* Line 936 of glr.c  */
#line 583 "ned2.y"
    {
                  setIsNetworkProperty(ps.component);
                  storeBannerAndRightComments(ps.component,(*yylocp));
                }
    break;

  case 85:

/* Line 936 of glr.c  */
#line 594 "ned2.y"
    {
                  ps.typescope.push(ps.component);
                  ps.blockscope.push(ps.component);
                  ps.parameters = (ParametersElement *)createElementWithTag(NED_PARAMETERS, ps.component);
                  ps.parameters->setIsImplicit(true);
                  ps.propertyscope.push(ps.parameters);
                }
    break;

  case 86:

/* Line 936 of glr.c  */
#line 604 "ned2.y"
    {
                  ps.propertyscope.pop();
                  ps.blockscope.pop();
                  ps.component = ps.typescope.top();
                  ps.typescope.pop();
                  if (np->getStoreSourceFlag())
                      storeComponentSourceCode(ps.component, (*yylocp));
                  storePos(ps.component, (*yylocp));
                  storeTrailingComment(ps.component,(*yylocp));
                }
    break;

  case 87:

/* Line 936 of glr.c  */
#line 618 "ned2.y"
    {
                  ps.component = (ModuleInterfaceElement *)createElementWithTag(NED_MODULE_INTERFACE, ps.inTypes ? (NEDElement *)ps.types : (NEDElement *)ps.nedfile);
                  ((ModuleInterfaceElement *)ps.component)->setName(toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yyloc)));
                }
    break;

  case 88:

/* Line 936 of glr.c  */
#line 623 "ned2.y"
    { storeBannerAndRightComments(ps.component,(*yylocp)); }
    break;

  case 89:

/* Line 936 of glr.c  */
#line 631 "ned2.y"
    {
                  storePos(ps.parameters, (*yylocp));
                  if (!ps.parameters->getFirstChild()) { // delete "parameters" element if empty
                      ps.parameters->getParent()->removeChild(ps.parameters);
                      delete ps.parameters;
                  }
                }
    break;

  case 90:

/* Line 936 of glr.c  */
#line 639 "ned2.y"
    {
                  ps.parameters->setIsImplicit(false);
                  storeBannerAndRightComments(ps.parameters,(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yyloc),(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yyloc));
                }
    break;

  case 91:

/* Line 936 of glr.c  */
#line 644 "ned2.y"
    { storePos(ps.parameters, (*yylocp)); }
    break;

  case 100:

/* Line 936 of glr.c  */
#line 672 "ned2.y"
    {
                  ps.propertyscope.pop();
                  storePos(ps.param, (*yylocp));
                  storeBannerAndRightComments(ps.param,(*yylocp));
                }
    break;

  case 101:

/* Line 936 of glr.c  */
#line 678 "ned2.y"
    {
                  ps.propertyscope.pop();
                  if (!isEmpty(ps.exprPos))  // note: $4 cannot be checked, as it's always NULL when expression parsing is off
                      addExpression(ps.param, "value",ps.exprPos,(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (6))].yystate.yysemantics.yysval));
                  else {
                      // Note: "=default" is currently not accepted in NED files, because
                      // it would be complicated to support in the Inifile Editor.
                      if (ps.isDefault)
                          np->getErrors()->addError(ps.param,"applying the default value (\"=default\" syntax) is not supported in NED files");
                  }
                  ps.param->setIsDefault(ps.isDefault);
                  storePos(ps.param, (*yylocp));
                  storeBannerAndRightComments(ps.param,(*yylocp));
                }
    break;

  case 102:

/* Line 936 of glr.c  */
#line 696 "ned2.y"
    {
                  ps.param = addParameter(ps.parameters, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yyloc));
                  ps.param->setType(ps.paramType);
                  ps.param->setIsVolatile(ps.isVolatile);
                  ps.propertyscope.push(ps.param);
                }
    break;

  case 103:

/* Line 936 of glr.c  */
#line 703 "ned2.y"
    {
                  ps.param = addParameter(ps.parameters, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yyloc));
                  ps.propertyscope.push(ps.param);
                }
    break;

  case 104:

/* Line 936 of glr.c  */
#line 711 "ned2.y"
    {
                  ps.param = addParameter(ps.parameters, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yyloc));
                  ps.param->setIsPattern(true);
                  const char *patt = ps.param->getName();
                  if (strchr(patt,' ') || strchr(patt,'\t') || strchr(patt,'\n'))
                      np->getErrors()->addError(ps.param,"parameter name patterns may not contain whitespace");
                  if (!isEmpty(ps.exprPos))  // note: $3 cannot be checked, as it's always NULL when expression parsing is off
                      addExpression(ps.param, "value",ps.exprPos,(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval));
                  else {
                      // Note: "=default" is currently not accepted in NED files, because
                      // it would be complicated to support in the Inifile Editor.
                      if (ps.isDefault)
                          np->getErrors()->addError(ps.param,"applying the default value (\"=default\" syntax) is not supported in NED files");
                  }
                  ps.param->setIsDefault(ps.isDefault);
                  storePos(ps.param, (*yylocp));
                  storeBannerAndRightComments(ps.param,(*yylocp));
                }
    break;

  case 105:

/* Line 936 of glr.c  */
#line 733 "ned2.y"
    { ps.paramType = NED_PARTYPE_DOUBLE; }
    break;

  case 106:

/* Line 936 of glr.c  */
#line 735 "ned2.y"
    { ps.paramType = NED_PARTYPE_INT; }
    break;

  case 107:

/* Line 936 of glr.c  */
#line 737 "ned2.y"
    { ps.paramType = NED_PARTYPE_STRING; }
    break;

  case 108:

/* Line 936 of glr.c  */
#line 739 "ned2.y"
    { ps.paramType = NED_PARTYPE_BOOL; }
    break;

  case 109:

/* Line 936 of glr.c  */
#line 741 "ned2.y"
    { ps.paramType = NED_PARTYPE_XML; }
    break;

  case 110:

/* Line 936 of glr.c  */
#line 746 "ned2.y"
    { ps.isVolatile = true; }
    break;

  case 111:

/* Line 936 of glr.c  */
#line 748 "ned2.y"
    { ps.isVolatile = false; }
    break;

  case 112:

/* Line 936 of glr.c  */
#line 753 "ned2.y"
    { ((*yyvalp)) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); ps.exprPos = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yyloc); ps.isDefault = false; }
    break;

  case 113:

/* Line 936 of glr.c  */
#line 755 "ned2.y"
    { ((*yyvalp)) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval); ps.exprPos = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yyloc); ps.isDefault = true; }
    break;

  case 114:

/* Line 936 of glr.c  */
#line 757 "ned2.y"
    {
                  ((*yyvalp)) = NULL; ps.exprPos = makeEmptyYYLTYPE(); ps.isDefault = true;
                }
    break;

  case 115:

/* Line 936 of glr.c  */
#line 761 "ned2.y"
    {
                  np->getErrors()->addError(ps.parameters,"interactive prompting (\"=ask\" syntax) is not supported in NED files");
                  ((*yyvalp)) = NULL; ps.exprPos = makeEmptyYYLTYPE(); ps.isDefault = false;
                }
    break;

  case 140:

/* Line 936 of glr.c  */
#line 817 "ned2.y"
    {
                  storePos(ps.property, (*yylocp));
                  storeBannerAndRightComments(ps.property,(*yylocp));
                }
    break;

  case 143:

/* Line 936 of glr.c  */
#line 830 "ned2.y"
    {
                  assertNonEmpty(ps.propertyscope);
                  ps.property = addProperty(ps.propertyscope.top(), toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yyloc)));
                  ps.propvals.clear(); // just to be safe
                }
    break;

  case 144:

/* Line 936 of glr.c  */
#line 836 "ned2.y"
    {
                  assertNonEmpty(ps.propertyscope);
                  ps.property = addProperty(ps.propertyscope.top(), toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yyloc)));
                  ps.property->setIndex(toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yyloc)));
                  ps.propvals.clear(); // just to be safe
                }
    break;

  case 148:

/* Line 936 of glr.c  */
#line 855 "ned2.y"
    {
                  ps.propkey = (PropertyKeyElement *)createElementWithTag(NED_PROPERTY_KEY, ps.property);
                  ps.propkey->setName(opp_trim(toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yyloc))).c_str());
                  for (int i=0; i<(int)ps.propvals.size(); i++)
                      ps.propkey->appendChild(ps.propvals[i]);
                  ps.propvals.clear();
                  storePos(ps.propkey, (*yylocp));
                }
    break;

  case 149:

/* Line 936 of glr.c  */
#line 864 "ned2.y"
    {
                  ps.propkey = (PropertyKeyElement *)createElementWithTag(NED_PROPERTY_KEY, ps.property);
                  ps.propkey->appendChild((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));
                  for (int i=0; i<(int)ps.propvals.size(); i++)
                      ps.propkey->appendChild(ps.propvals[i]);
                  ps.propvals.clear();
                  storePos(ps.propkey, (*yylocp));
                }
    break;

  case 150:

/* Line 936 of glr.c  */
#line 876 "ned2.y"
    { ps.propvals.push_back((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval)); }
    break;

  case 151:

/* Line 936 of glr.c  */
#line 878 "ned2.y"
    { ps.propvals.push_back((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval)); }
    break;

  case 152:

/* Line 936 of glr.c  */
#line 883 "ned2.y"
    {
                  ((*yyvalp)) = createPropertyValue((*yylocp));
                }
    break;

  case 153:

/* Line 936 of glr.c  */
#line 887 "ned2.y"
    {
                  LiteralElement *node = (LiteralElement *)createElementWithTag(NED_LITERAL);
                  node->setType(NED_CONST_SPEC); // and leave both value and text at ""
                  ((*yyvalp)) = node;
                }
    break;

  case 160:

/* Line 936 of glr.c  */
#line 911 "ned2.y"
    {
                  assertNonEmpty(ps.blockscope);
                  ps.gates = (GatesElement *)createElementWithTag(NED_GATES, ps.blockscope.top());
                  storeBannerAndRightComments(ps.gates,(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yyloc),(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yyloc));
                }
    break;

  case 161:

/* Line 936 of glr.c  */
#line 917 "ned2.y"
    {
                  storePos(ps.gates, (*yylocp));
                }
    break;

  case 164:

/* Line 936 of glr.c  */
#line 929 "ned2.y"
    {
                  storeBannerAndRightComments(ps.gate,(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yyloc));
                }
    break;

  case 165:

/* Line 936 of glr.c  */
#line 933 "ned2.y"
    {
                  storeBannerAndRightComments(ps.gate,(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yyloc));
                }
    break;

  case 166:

/* Line 936 of glr.c  */
#line 943 "ned2.y"
    {
                  ps.propertyscope.push(ps.gate);
                }
    break;

  case 167:

/* Line 936 of glr.c  */
#line 947 "ned2.y"
    {
                  ps.propertyscope.pop();
                  storePos(ps.gate, (*yylocp));
                }
    break;

  case 168:

/* Line 936 of glr.c  */
#line 955 "ned2.y"
    {
                  ps.gate = addGate(ps.gates, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yyloc));
                  ps.gate->setType(ps.gateType);
                }
    break;

  case 169:

/* Line 936 of glr.c  */
#line 960 "ned2.y"
    {
                  ps.gate = addGate(ps.gates, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yyloc));
                  ps.gate->setType(ps.gateType);
                  ps.gate->setIsVector(true);
                }
    break;

  case 170:

/* Line 936 of glr.c  */
#line 966 "ned2.y"
    {
                  ps.gate = addGate(ps.gates, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yyloc));
                  ps.gate->setType(ps.gateType);
                  ps.gate->setIsVector(true);
                  addExpression(ps.gate, "vector-size",ps.exprPos,(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));
                }
    break;

  case 171:

/* Line 936 of glr.c  */
#line 973 "ned2.y"
    {
                  ps.gate = addGate(ps.gates, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yyloc));
                }
    break;

  case 172:

/* Line 936 of glr.c  */
#line 977 "ned2.y"
    {
                  ps.gate = addGate(ps.gates, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yyloc));
                  ps.gate->setIsVector(true);
                }
    break;

  case 173:

/* Line 936 of glr.c  */
#line 982 "ned2.y"
    {
                  ps.gate = addGate(ps.gates, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yyloc));
                  ps.gate->setIsVector(true);
                  addExpression(ps.gate, "vector-size",ps.exprPos,(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval));
                }
    break;

  case 174:

/* Line 936 of glr.c  */
#line 991 "ned2.y"
    { ps.gateType = NED_GATETYPE_INPUT; }
    break;

  case 175:

/* Line 936 of glr.c  */
#line 993 "ned2.y"
    { ps.gateType = NED_GATETYPE_OUTPUT; }
    break;

  case 176:

/* Line 936 of glr.c  */
#line 995 "ned2.y"
    { ps.gateType = NED_GATETYPE_INOUT; }
    break;

  case 179:

/* Line 936 of glr.c  */
#line 1008 "ned2.y"
    {
                  assertNonEmpty(ps.blockscope);
                  ps.types = (TypesElement *)createElementWithTag(NED_TYPES, ps.blockscope.top());
                  storeBannerAndRightComments(ps.types,(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yyloc),(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yyloc));
                  if (ps.inTypes)
                     np->getErrors()->addError(ps.types,"more than one level of type nesting is not allowed");
                  ps.inTypes = true;
                }
    break;

  case 180:

/* Line 936 of glr.c  */
#line 1017 "ned2.y"
    {
                  ps.inTypes = false;
                  storePos(ps.types, (*yylocp));
                }
    break;

  case 195:

/* Line 936 of glr.c  */
#line 1054 "ned2.y"
    {
                  assertNonEmpty(ps.blockscope);
                  ps.submods = (SubmodulesElement *)createElementWithTag(NED_SUBMODULES, ps.blockscope.top());
                  storeBannerAndRightComments(ps.submods,(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yyloc),(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yyloc));
                }
    break;

  case 196:

/* Line 936 of glr.c  */
#line 1060 "ned2.y"
    {
                  storePos(ps.submods, (*yylocp));
                }
    break;

  case 201:

/* Line 936 of glr.c  */
#line 1077 "ned2.y"
    {
                  storeBannerAndRightComments(ps.submod,(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yyloc),(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yyloc));
                  storePos(ps.submod, (*yylocp));
                }
    break;

  case 202:

/* Line 936 of glr.c  */
#line 1082 "ned2.y"
    {
                  ps.blockscope.push(ps.submod);
                  ps.parameters = (ParametersElement *)createElementWithTag(NED_PARAMETERS, ps.submod);
                  ps.parameters->setIsImplicit(true);
                  ps.propertyscope.push(ps.parameters);
                  storeBannerAndRightComments(ps.submod,(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yyloc),(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yyloc));
                }
    break;

  case 203:

/* Line 936 of glr.c  */
#line 1092 "ned2.y"
    {
                  ps.blockscope.pop();
                  ps.propertyscope.pop();
                  storePos(ps.submod, (*yylocp));
                  storeTrailingComment(ps.submod,(*yylocp));
                }
    break;

  case 204:

/* Line 936 of glr.c  */
#line 1102 "ned2.y"
    {
                  ps.submod->setType(removeSpaces((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yyloc)).c_str());
                  if ((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval)) ps.submod->appendChild((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval));
                }
    break;

  case 205:

/* Line 936 of glr.c  */
#line 1107 "ned2.y"
    {
                  addOptionalExpression(ps.submod, "like-expr", ps.exprPos, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (6))].yystate.yysemantics.yysval));
                  ps.submod->setLikeType(removeSpaces((((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yyloc)).c_str());
                  ps.submod->setIsDefault(ps.isDefault);
                  if ((((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (6))].yystate.yysemantics.yysval)) ps.submod->appendChild((((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (6))].yystate.yysemantics.yysval));
                }
    break;

  case 206:

/* Line 936 of glr.c  */
#line 1117 "ned2.y"
    {
                  ps.submod = (SubmoduleElement *)createElementWithTag(NED_SUBMODULE, ps.submods);
                  ps.submod->setName(toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yyloc)));
                }
    break;

  case 207:

/* Line 936 of glr.c  */
#line 1122 "ned2.y"
    {
                  ps.submod = (SubmoduleElement *)createElementWithTag(NED_SUBMODULE, ps.submods);
                  ps.submod->setName(toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yyloc)));
                  addExpression(ps.submod, "vector-size",ps.exprPos,(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval));
                }
    break;

  case 208:

/* Line 936 of glr.c  */
#line 1131 "ned2.y"
    { ((*yyvalp)) = NULL; ps.exprPos = makeEmptyYYLTYPE(); ps.isDefault = false; }
    break;

  case 209:

/* Line 936 of glr.c  */
#line 1133 "ned2.y"
    { ((*yyvalp)) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval); ps.exprPos = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yyloc); ps.isDefault = false; }
    break;

  case 210:

/* Line 936 of glr.c  */
#line 1135 "ned2.y"
    { ((*yyvalp)) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (6))].yystate.yysemantics.yysval); ps.exprPos = (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (6))].yystate.yyloc); ps.isDefault = true; }
    break;

  case 211:

/* Line 936 of glr.c  */
#line 1140 "ned2.y"
    { ((*yyvalp)) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 212:

/* Line 936 of glr.c  */
#line 1142 "ned2.y"
    { ((*yyvalp)) = NULL; }
    break;

  case 215:

/* Line 936 of glr.c  */
#line 1155 "ned2.y"
    {
                  assertNonEmpty(ps.blockscope);
                  ps.conns = (ConnectionsElement *)createElementWithTag(NED_CONNECTIONS, ps.blockscope.top());
                  ps.conns->setAllowUnconnected(true);
                  storeBannerAndRightComments(ps.conns,(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yyloc),(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yyloc));
                }
    break;

  case 216:

/* Line 936 of glr.c  */
#line 1162 "ned2.y"
    {
                  storePos(ps.conns, (*yylocp));
                }
    break;

  case 217:

/* Line 936 of glr.c  */
#line 1166 "ned2.y"
    {
                  assertNonEmpty(ps.blockscope);
                  ps.conns = (ConnectionsElement *)createElementWithTag(NED_CONNECTIONS, ps.blockscope.top());
                  storeBannerAndRightComments(ps.conns,(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yyloc),(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yyloc));
                }
    break;

  case 218:

/* Line 936 of glr.c  */
#line 1172 "ned2.y"
    {
                  storePos(ps.conns, (*yylocp));
                }
    break;

  case 224:

/* Line 936 of glr.c  */
#line 1190 "ned2.y"
    {
                  if ((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval)) {
                      transferChildren((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval), ps.conn);
                      delete (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval);
                  }
                  storePos(ps.conn, (*yylocp));
                  storeBannerAndRightComments(ps.conn,(*yylocp));
                }
    break;

  case 225:

/* Line 936 of glr.c  */
#line 1202 "ned2.y"
    {
                  if (ps.inConnGroup)
                      np->getErrors()->addError(ps.conngroup,"nested connection groups are not allowed");
                  ps.conngroup = (ConnectionGroupElement *)createElementWithTag(NED_CONNECTION_GROUP, ps.conns);
                  if ((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval)) {
                      // for's and if's were collected in a temporary UnknownElement, put them under conngroup now
                      transferChildren((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval), ps.conngroup);
                      delete (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval);
                  }
                  ps.inConnGroup = true;
                  storeBannerAndRightComments(ps.conngroup,(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yyloc));
                }
    break;

  case 226:

/* Line 936 of glr.c  */
#line 1215 "ned2.y"
    {
                  ps.inConnGroup = false;
                  storePos(ps.conngroup,(*yylocp));
                  storeTrailingComment(ps.conngroup,(*yylocp));
                }
    break;

  case 227:

/* Line 936 of glr.c  */
#line 1224 "ned2.y"
    { ((*yyvalp)) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 228:

/* Line 936 of glr.c  */
#line 1226 "ned2.y"
    { ((*yyvalp)) = NULL; }
    break;

  case 229:

/* Line 936 of glr.c  */
#line 1231 "ned2.y"
    {
                  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval)->appendChild((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));
                  ((*yyvalp)) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval);
                }
    break;

  case 230:

/* Line 936 of glr.c  */
#line 1236 "ned2.y"
    {
                  ((*yyvalp)) = new UnknownElement();
                  ((*yyvalp))->appendChild((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));
                }
    break;

  case 233:

/* Line 936 of glr.c  */
#line 1249 "ned2.y"
    {
                  ps.loop = (LoopElement *)createElementWithTag(NED_LOOP);
                  ps.loop->setParamName( toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (6))].yystate.yyloc)) );
                  addExpression(ps.loop, "from-value",(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (6))].yystate.yyloc),(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (6))].yystate.yysemantics.yysval));
                  addExpression(ps.loop, "to-value",(((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (6))].yystate.yyloc),(((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (6))].yystate.yysemantics.yysval));
                  storePos(ps.loop, (*yylocp));
                  ((*yyvalp)) = ps.loop;
                }
    break;

  case 234:

/* Line 936 of glr.c  */
#line 1264 "ned2.y"
    {
                  ps.conn->setIsBidirectional(false);
                  ps.conn->setIsForwardArrow(true);
                }
    break;

  case 235:

/* Line 936 of glr.c  */
#line 1269 "ned2.y"
    {
                  ps.conn->setIsBidirectional(false);
                  ps.conn->setIsForwardArrow(true);
                }
    break;

  case 236:

/* Line 936 of glr.c  */
#line 1274 "ned2.y"
    {
                  swapConnection(ps.conn);
                  ps.conn->setIsBidirectional(false);
                  ps.conn->setIsForwardArrow(false);
                }
    break;

  case 237:

/* Line 936 of glr.c  */
#line 1280 "ned2.y"
    {
                  swapConnection(ps.conn);
                  ps.conn->setIsBidirectional(false);
                  ps.conn->setIsForwardArrow(false);
                }
    break;

  case 238:

/* Line 936 of glr.c  */
#line 1286 "ned2.y"
    {
                  ps.conn->setIsBidirectional(true);
                }
    break;

  case 239:

/* Line 936 of glr.c  */
#line 1290 "ned2.y"
    {
                  ps.conn->setIsBidirectional(true);
                }
    break;

  case 242:

/* Line 936 of glr.c  */
#line 1302 "ned2.y"
    {
                  ps.conn = (ConnectionElement *)createElementWithTag(NED_CONNECTION, ps.inConnGroup ? (NEDElement*)ps.conngroup : (NEDElement*)ps.conns );
                  ps.conn->setSrcModule( toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yyloc)) );
                  addExpression(ps.conn, "src-module-index",ps.exprPos,(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval));
                }
    break;

  case 243:

/* Line 936 of glr.c  */
#line 1308 "ned2.y"
    {
                  ps.conn = (ConnectionElement *)createElementWithTag(NED_CONNECTION, ps.inConnGroup ? (NEDElement*)ps.conngroup : (NEDElement*)ps.conns );
                  ps.conn->setSrcModule( toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yyloc)) );
                }
    break;

  case 244:

/* Line 936 of glr.c  */
#line 1316 "ned2.y"
    {
                  ps.conn->setSrcGate( toString( (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yyloc)) );
                  ps.conn->setSrcGateSubg(ps.subgate);
                }
    break;

  case 245:

/* Line 936 of glr.c  */
#line 1321 "ned2.y"
    {
                  ps.conn->setSrcGate( toString( (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yyloc)) );
                  ps.conn->setSrcGateSubg(ps.subgate);
                  addExpression(ps.conn, "src-gate-index",ps.exprPos,(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));
                }
    break;

  case 246:

/* Line 936 of glr.c  */
#line 1327 "ned2.y"
    {
                  ps.conn->setSrcGate( toString( (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yyloc)) );
                  ps.conn->setSrcGateSubg(ps.subgate);
                  ps.conn->setSrcGatePlusplus(true);
                }
    break;

  case 247:

/* Line 936 of glr.c  */
#line 1336 "ned2.y"
    {
                  ps.conn = (ConnectionElement *)createElementWithTag(NED_CONNECTION, ps.inConnGroup ? (NEDElement*)ps.conngroup : (NEDElement*)ps.conns );
                  ps.conn->setSrcModule("");
                  ps.conn->setSrcGate(toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yyloc)));
                  ps.conn->setSrcGateSubg(ps.subgate);
                }
    break;

  case 248:

/* Line 936 of glr.c  */
#line 1343 "ned2.y"
    {
                  ps.conn = (ConnectionElement *)createElementWithTag(NED_CONNECTION, ps.inConnGroup ? (NEDElement*)ps.conngroup : (NEDElement*)ps.conns );
                  ps.conn->setSrcModule("");
                  ps.conn->setSrcGate(toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yyloc)));
                  ps.conn->setSrcGateSubg(ps.subgate);
                  addExpression(ps.conn, "src-gate-index",ps.exprPos,(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));
                }
    break;

  case 249:

/* Line 936 of glr.c  */
#line 1351 "ned2.y"
    {
                  ps.conn = (ConnectionElement *)createElementWithTag(NED_CONNECTION, ps.inConnGroup ? (NEDElement*)ps.conngroup : (NEDElement*)ps.conns );
                  ps.conn->setSrcModule("");
                  ps.conn->setSrcGate(toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yyloc)));
                  ps.conn->setSrcGateSubg(ps.subgate);
                  ps.conn->setSrcGatePlusplus(true);
                }
    break;

  case 252:

/* Line 936 of glr.c  */
#line 1367 "ned2.y"
    {
                  ps.conn->setDestModule( toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yyloc)) );
                }
    break;

  case 253:

/* Line 936 of glr.c  */
#line 1371 "ned2.y"
    {
                  ps.conn->setDestModule( toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yyloc)) );
                  addExpression(ps.conn, "dest-module-index",ps.exprPos,(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval));
                }
    break;

  case 254:

/* Line 936 of glr.c  */
#line 1379 "ned2.y"
    {
                  ps.conn->setDestGate( toString( (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yyloc)) );
                  ps.conn->setDestGateSubg(ps.subgate);
                }
    break;

  case 255:

/* Line 936 of glr.c  */
#line 1384 "ned2.y"
    {
                  ps.conn->setDestGate( toString( (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yyloc)) );
                  ps.conn->setDestGateSubg(ps.subgate);
                  addExpression(ps.conn, "dest-gate-index",ps.exprPos,(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));
                }
    break;

  case 256:

/* Line 936 of glr.c  */
#line 1390 "ned2.y"
    {
                  ps.conn->setDestGate( toString( (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yyloc)) );
                  ps.conn->setDestGateSubg(ps.subgate);
                  ps.conn->setDestGatePlusplus(true);
                }
    break;

  case 257:

/* Line 936 of glr.c  */
#line 1399 "ned2.y"
    {
                  ps.conn->setDestGate( toString( (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yyloc)) );
                  ps.conn->setDestGateSubg(ps.subgate);
                }
    break;

  case 258:

/* Line 936 of glr.c  */
#line 1404 "ned2.y"
    {
                  ps.conn->setDestGate( toString( (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yyloc)) );
                  ps.conn->setDestGateSubg(ps.subgate);
                  addExpression(ps.conn, "dest-gate-index",ps.exprPos,(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));
                }
    break;

  case 259:

/* Line 936 of glr.c  */
#line 1410 "ned2.y"
    {
                  ps.conn->setDestGate( toString( (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yyloc)) );
                  ps.conn->setDestGateSubg(ps.subgate);
                  ps.conn->setDestGatePlusplus(true);
                }
    break;

  case 260:

/* Line 936 of glr.c  */
#line 1419 "ned2.y"
    {
                  const char *s = toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yyloc));
                  if (!strcmp(s,"i"))
                      ps.subgate = NED_SUBGATE_I;
                  else if (!strcmp(s,"o"))
                      ps.subgate = NED_SUBGATE_O;
                  else
                       np->getErrors()->addError(currentLocation(), "invalid subgate spec `%s', must be `i' or `o'", toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yyloc)));
                }
    break;

  case 261:

/* Line 936 of glr.c  */
#line 1429 "ned2.y"
    { ps.subgate = NED_SUBGATE_NONE; }
    break;

  case 263:

/* Line 936 of glr.c  */
#line 1435 "ned2.y"
    {
                  ps.parameters = (ParametersElement *)createElementWithTag(NED_PARAMETERS, ps.conn);
                  ps.parameters->setIsImplicit(true);
                  ps.propertyscope.push(ps.parameters);
                }
    break;

  case 264:

/* Line 936 of glr.c  */
#line 1442 "ned2.y"
    {
                  ps.propertyscope.pop();
                }
    break;

  case 266:

/* Line 936 of glr.c  */
#line 1451 "ned2.y"
    {
                  ps.conn->setType(removeSpaces((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yyloc)).c_str());
                }
    break;

  case 267:

/* Line 936 of glr.c  */
#line 1455 "ned2.y"
    {
                  addOptionalExpression(ps.conn, "like-expr", ps.exprPos, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval));
                  ps.conn->setLikeType(removeSpaces((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yyloc)).c_str());
                  ps.conn->setIsDefault(ps.isDefault);
                }
    break;

  case 269:

/* Line 936 of glr.c  */
#line 1465 "ned2.y"
    { ps.conn->setName(toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yyloc))); }
    break;

  case 270:

/* Line 936 of glr.c  */
#line 1473 "ned2.y"
    {
                  ps.condition = (ConditionElement *)createElementWithTag(NED_CONDITION);
                  addExpression(ps.condition, "condition",(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yyloc),(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval));
                  storePos(ps.condition, (*yylocp));
                  ((*yyvalp)) = ps.condition;
                }
    break;

  case 271:

/* Line 936 of glr.c  */
#line 1486 "ned2.y"
    { ((*yyvalp)) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval); ps.exprPos = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yyloc); }
    break;

  case 272:

/* Line 936 of glr.c  */
#line 1492 "ned2.y"
    {
                  if (np->getParseExpressionsFlag()) ((*yyvalp)) = createExpression((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));
                }
    break;

  case 274:

/* Line 936 of glr.c  */
#line 1503 "ned2.y"
    { ((*yyvalp)) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval); }
    break;

  case 275:

/* Line 936 of glr.c  */
#line 1505 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createFunction("const", (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval)); }
    break;

  case 276:

/* Line 936 of glr.c  */
#line 1508 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createOperator("+", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval)); }
    break;

  case 277:

/* Line 936 of glr.c  */
#line 1510 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createOperator("-", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval)); }
    break;

  case 278:

/* Line 936 of glr.c  */
#line 1512 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createOperator("*", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval)); }
    break;

  case 279:

/* Line 936 of glr.c  */
#line 1514 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createOperator("/", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval)); }
    break;

  case 280:

/* Line 936 of glr.c  */
#line 1516 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createOperator("%", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval)); }
    break;

  case 281:

/* Line 936 of glr.c  */
#line 1518 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createOperator("^", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval)); }
    break;

  case 282:

/* Line 936 of glr.c  */
#line 1522 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = unaryMinus((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval)); }
    break;

  case 283:

/* Line 936 of glr.c  */
#line 1525 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createOperator("==", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval)); }
    break;

  case 284:

/* Line 936 of glr.c  */
#line 1527 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createOperator("!=", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval)); }
    break;

  case 285:

/* Line 936 of glr.c  */
#line 1529 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createOperator(">", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval)); }
    break;

  case 286:

/* Line 936 of glr.c  */
#line 1531 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createOperator(">=", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval)); }
    break;

  case 287:

/* Line 936 of glr.c  */
#line 1533 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createOperator("<", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval)); }
    break;

  case 288:

/* Line 936 of glr.c  */
#line 1535 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createOperator("<=", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval)); }
    break;

  case 289:

/* Line 936 of glr.c  */
#line 1538 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createOperator("&&", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval)); }
    break;

  case 290:

/* Line 936 of glr.c  */
#line 1540 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createOperator("||", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval)); }
    break;

  case 291:

/* Line 936 of glr.c  */
#line 1542 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createOperator("##", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval)); }
    break;

  case 292:

/* Line 936 of glr.c  */
#line 1546 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createOperator("!", (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval)); }
    break;

  case 293:

/* Line 936 of glr.c  */
#line 1549 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createOperator("&", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval)); }
    break;

  case 294:

/* Line 936 of glr.c  */
#line 1551 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createOperator("|", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval)); }
    break;

  case 295:

/* Line 936 of glr.c  */
#line 1553 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createOperator("#", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval)); }
    break;

  case 296:

/* Line 936 of glr.c  */
#line 1557 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createOperator("~", (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval)); }
    break;

  case 297:

/* Line 936 of glr.c  */
#line 1559 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createOperator("<<", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval)); }
    break;

  case 298:

/* Line 936 of glr.c  */
#line 1561 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createOperator(">>", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval)); }
    break;

  case 299:

/* Line 936 of glr.c  */
#line 1563 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createOperator("?:", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval)); }
    break;

  case 300:

/* Line 936 of glr.c  */
#line 1566 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createFunction(toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yyloc)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval)); }
    break;

  case 301:

/* Line 936 of glr.c  */
#line 1568 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createFunction(toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yyloc)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval)); }
    break;

  case 302:

/* Line 936 of glr.c  */
#line 1570 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createFunction(toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yyloc)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval)); }
    break;

  case 303:

/* Line 936 of glr.c  */
#line 1573 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createFunction(toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yyloc))); }
    break;

  case 304:

/* Line 936 of glr.c  */
#line 1575 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createFunction(toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yyloc)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval)); }
    break;

  case 305:

/* Line 936 of glr.c  */
#line 1577 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createFunction(toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (6))].yystate.yyloc)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (6))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval)); }
    break;

  case 306:

/* Line 936 of glr.c  */
#line 1579 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createFunction(toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (8))].yystate.yyloc)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (8))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (8))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (8))].yystate.yysemantics.yysval)); }
    break;

  case 307:

/* Line 936 of glr.c  */
#line 1581 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createFunction(toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (10))].yystate.yyloc)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (10))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (10))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (10))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (10))].yystate.yysemantics.yysval)); }
    break;

  case 308:

/* Line 936 of glr.c  */
#line 1583 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createFunction(toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (12))].yystate.yyloc)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (12))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (12))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (12))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (12))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((11) - (12))].yystate.yysemantics.yysval)); }
    break;

  case 309:

/* Line 936 of glr.c  */
#line 1585 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createFunction(toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (14))].yystate.yyloc)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (14))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (14))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (14))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (14))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((11) - (14))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((13) - (14))].yystate.yysemantics.yysval)); }
    break;

  case 310:

/* Line 936 of glr.c  */
#line 1587 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createFunction(toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (16))].yystate.yyloc)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (16))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (16))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (16))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (16))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((11) - (16))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((13) - (16))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((15) - (16))].yystate.yysemantics.yysval)); }
    break;

  case 311:

/* Line 936 of glr.c  */
#line 1589 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createFunction(toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (18))].yystate.yyloc)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (18))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (18))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (18))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (18))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((11) - (18))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((13) - (18))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((15) - (18))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((17) - (18))].yystate.yysemantics.yysval)); }
    break;

  case 312:

/* Line 936 of glr.c  */
#line 1591 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createFunction(toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (20))].yystate.yyloc)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (20))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (20))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (20))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (20))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((11) - (20))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((13) - (20))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((15) - (20))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((17) - (20))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((19) - (20))].yystate.yysemantics.yysval)); }
    break;

  case 313:

/* Line 936 of glr.c  */
#line 1593 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createFunction(toString((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (22))].yystate.yyloc)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (22))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (22))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (22))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (22))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((11) - (22))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((13) - (22))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((15) - (22))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((17) - (22))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((19) - (22))].yystate.yysemantics.yysval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((21) - (22))].yystate.yysemantics.yysval)); }
    break;

  case 320:

/* Line 936 of glr.c  */
#line 1611 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createIdent((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yyloc)); }
    break;

  case 321:

/* Line 936 of glr.c  */
#line 1613 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createIdent((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yyloc), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yyloc)); }
    break;

  case 322:

/* Line 936 of glr.c  */
#line 1615 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createIdent((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yyloc), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yyloc)); }
    break;

  case 323:

/* Line 936 of glr.c  */
#line 1617 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createIdent((((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (6))].yystate.yyloc), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (6))].yystate.yyloc), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (6))].yystate.yysemantics.yysval)); }
    break;

  case 324:

/* Line 936 of glr.c  */
#line 1622 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createFunction("index"); }
    break;

  case 325:

/* Line 936 of glr.c  */
#line 1624 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createFunction("index"); }
    break;

  case 326:

/* Line 936 of glr.c  */
#line 1626 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createFunction("sizeof", (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval)); }
    break;

  case 330:

/* Line 936 of glr.c  */
#line 1637 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createStringLiteral((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yyloc)); }
    break;

  case 331:

/* Line 936 of glr.c  */
#line 1642 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createLiteral(NED_CONST_BOOL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yyloc), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yyloc)); }
    break;

  case 332:

/* Line 936 of glr.c  */
#line 1644 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createLiteral(NED_CONST_BOOL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yyloc), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yyloc)); }
    break;

  case 333:

/* Line 936 of glr.c  */
#line 1649 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createLiteral(NED_CONST_INT, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yyloc), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yyloc)); }
    break;

  case 334:

/* Line 936 of glr.c  */
#line 1651 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createLiteral(NED_CONST_DOUBLE, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yyloc), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yyloc)); }
    break;

  case 335:

/* Line 936 of glr.c  */
#line 1653 "ned2.y"
    { if (np->getParseExpressionsFlag()) ((*yyvalp)) = createQuantityLiteral((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yyloc)); }
    break;



/* Line 936 of glr.c  */
#line 3822 "ned2.tab.cc"
      default: break;
    }

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
# undef YYERROR
# undef YYBACKUP
# undef yyclearin
# undef YYRECOVERING
}


/*ARGSUSED*/ static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  YYUSE (yy0);
  YYUSE (yy1);

  switch (yyn)
    {
      
      default: break;
    }
}

			      /* Bison grammar-table manipulation.  */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/** Number of symbols composing the right hand side of rule #RULE.  */
static inline int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
}

static void
yydestroyGLRState (char const *yymsg, yyGLRState *yys)
{
  if (yys->yyresolved)
    yydestruct (yymsg, yystos[yys->yylrState],
		&yys->yysemantics.yysval, &yys->yyloc);
  else
    {
#if YYDEBUG
      if (yydebug)
	{
	  if (yys->yysemantics.yyfirstVal)
	    YYFPRINTF (stderr, "%s unresolved ", yymsg);
	  else
	    YYFPRINTF (stderr, "%s incomplete ", yymsg);
	  yy_symbol_print (stderr, yystos[yys->yylrState],
			   NULL, &yys->yyloc);
	  YYFPRINTF (stderr, "\n");
	}
#endif

      if (yys->yysemantics.yyfirstVal)
	{
	  yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
	  yyGLRState *yyrh;
	  int yyn;
	  for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
	       yyn > 0;
	       yyrh = yyrh->yypred, yyn -= 1)
	    yydestroyGLRState (yymsg, yyrh);
	}
    }
}

/** Left-hand-side symbol for rule #RULE.  */
static inline yySymbol
yylhsNonterm (yyRuleNum yyrule)
{
  return yyr1[yyrule];
}

#define yypact_value_is_default(yystate) \
  ((yystate) == (-458))

/** True iff LR state STATE has only a default reduction (regardless
 *  of token).  */
static inline yybool
yyisDefaultedState (yyStateNum yystate)
{
  return yypact_value_is_default (yypact[yystate]);
}

/** The default reduction for STATE, assuming it has one.  */
static inline yyRuleNum
yydefaultAction (yyStateNum yystate)
{
  return yydefact[yystate];
}

#define yytable_value_is_error(yytable_value) \
  YYID (0)

/** Set *YYACTION to the action to take in YYSTATE on seeing YYTOKEN.
 *  Result R means
 *    R < 0:  Reduce on rule -R.
 *    R = 0:  Error.
 *    R > 0:  Shift to state R.
 *  Set *CONFLICTS to a pointer into yyconfl to 0-terminated list of
 *  conflicting reductions.
 */
static inline void
yygetLRActions (yyStateNum yystate, int yytoken,
		int* yyaction, const short int** yyconflicts)
{
  int yyindex = yypact[yystate] + yytoken;
  if (yypact_value_is_default (yypact[yystate])
      || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
    {
      *yyaction = -yydefact[yystate];
      *yyconflicts = yyconfl;
    }
  else if (! yytable_value_is_error (yytable[yyindex]))
    {
      *yyaction = yytable[yyindex];
      *yyconflicts = yyconfl + yyconflp[yyindex];
    }
  else
    {
      *yyaction = 0;
      *yyconflicts = yyconfl + yyconflp[yyindex];
    }
}

static inline yyStateNum
yyLRgotoState (yyStateNum yystate, yySymbol yylhs)
{
  int yyr;
  yyr = yypgoto[yylhs - YYNTOKENS] + yystate;
  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
    return yytable[yyr];
  else
    return yydefgoto[yylhs - YYNTOKENS];
}

static inline yybool
yyisShiftAction (int yyaction)
{
  return 0 < yyaction;
}

static inline yybool
yyisErrorAction (int yyaction)
{
  return yyaction == 0;
}

				/* GLRStates */

/** Return a fresh GLRStackItem.  Callers should call
 * YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
 * headroom.  */

static inline yyGLRStackItem*
yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
{
  yyGLRStackItem* yynewItem = yystackp->yynextFree;
  yystackp->yyspaceLeft -= 1;
  yystackp->yynextFree += 1;
  yynewItem->yystate.yyisState = yyisState;
  return yynewItem;
}

/** Add a new semantic action that will execute the action for rule
 *  RULENUM on the semantic values in RHS to the list of
 *  alternative actions for STATE.  Assumes that RHS comes from
 *  stack #K of *STACKP. */
static void
yyaddDeferredAction (yyGLRStack* yystackp, size_t yyk, yyGLRState* yystate,
		     yyGLRState* rhs, yyRuleNum yyrule)
{
  yySemanticOption* yynewOption =
    &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
  yynewOption->yystate = rhs;
  yynewOption->yyrule = yyrule;
  if (yystackp->yytops.yylookaheadNeeds[yyk])
    {
      yynewOption->yyrawchar = yychar;
      yynewOption->yyval = yylval;
      yynewOption->yyloc = yylloc;
    }
  else
    yynewOption->yyrawchar = YYEMPTY;
  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewOption;

  YY_RESERVE_GLRSTACK (yystackp);
}

				/* GLRStacks */

/** Initialize SET to a singleton set containing an empty stack.  */
static yybool
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates = (yyGLRState**) YYMALLOC (16 * sizeof yyset->yystates[0]);
  if (! yyset->yystates)
    return yyfalse;
  yyset->yystates[0] = NULL;
  yyset->yylookaheadNeeds =
    (yybool*) YYMALLOC (16 * sizeof yyset->yylookaheadNeeds[0]);
  if (! yyset->yylookaheadNeeds)
    {
      YYFREE (yyset->yystates);
      return yyfalse;
    }
  return yytrue;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
  YYFREE (yyset->yylookaheadNeeds);
}

/** Initialize STACK to a single empty stack, with total maximum
 *  capacity for all stacks of SIZE.  */
static yybool
yyinitGLRStack (yyGLRStack* yystackp, size_t yysize)
{
  yystackp->yyerrState = 0;
  yynerrs = 0;
  yystackp->yyspaceLeft = yysize;
  yystackp->yyitems =
    (yyGLRStackItem*) YYMALLOC (yysize * sizeof yystackp->yynextFree[0]);
  if (!yystackp->yyitems)
    return yyfalse;
  yystackp->yynextFree = yystackp->yyitems;
  yystackp->yysplitPoint = NULL;
  yystackp->yylastDeleted = NULL;
  return yyinitStateSet (&yystackp->yytops);
}


#if YYSTACKEXPANDABLE
# define YYRELOC(YYFROMITEMS,YYTOITEMS,YYX,YYTYPE) \
  &((YYTOITEMS) - ((YYFROMITEMS) - (yyGLRStackItem*) (YYX)))->YYTYPE

/** If STACK is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation.  */
static void
yyexpandGLRStack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yynewItems;
  yyGLRStackItem* yyp0, *yyp1;
  size_t yysize, yynewSize;
  size_t yyn;
  yysize = yystackp->yynextFree - yystackp->yyitems;
  if (YYMAXDEPTH - YYHEADROOM < yysize)
    yyMemoryExhausted (yystackp);
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yynewItems = (yyGLRStackItem*) YYMALLOC (yynewSize * sizeof yynewItems[0]);
  if (! yynewItems)
    yyMemoryExhausted (yystackp);
  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
       0 < yyn;
       yyn -= 1, yyp0 += 1, yyp1 += 1)
    {
      *yyp1 = *yyp0;
      if (*(yybool *) yyp0)
	{
	  yyGLRState* yys0 = &yyp0->yystate;
	  yyGLRState* yys1 = &yyp1->yystate;
	  if (yys0->yypred != NULL)
	    yys1->yypred =
	      YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
	  if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != NULL)
	    yys1->yysemantics.yyfirstVal =
	      YYRELOC(yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
	}
      else
	{
	  yySemanticOption* yyv0 = &yyp0->yyoption;
	  yySemanticOption* yyv1 = &yyp1->yyoption;
	  if (yyv0->yystate != NULL)
	    yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
	  if (yyv0->yynext != NULL)
	    yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
	}
    }
  if (yystackp->yysplitPoint != NULL)
    yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
				 yystackp->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
    if (yystackp->yytops.yystates[yyn] != NULL)
      yystackp->yytops.yystates[yyn] =
	YYRELOC (yystackp->yyitems, yynewItems,
		 yystackp->yytops.yystates[yyn], yystate);
  YYFREE (yystackp->yyitems);
  yystackp->yyitems = yynewItems;
  yystackp->yynextFree = yynewItems + yysize;
  yystackp->yyspaceLeft = yynewSize - yysize;
}
#endif

static void
yyfreeGLRStack (yyGLRStack* yystackp)
{
  YYFREE (yystackp->yyitems);
  yyfreeStateSet (&yystackp->yytops);
}

/** Assuming that S is a GLRState somewhere on STACK, update the
 *  splitpoint of STACK, if needed, so that it is at least as deep as
 *  S.  */
static inline void
yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
{
  if (yystackp->yysplitPoint != NULL && yystackp->yysplitPoint > yys)
    yystackp->yysplitPoint = yys;
}

/** Invalidate stack #K in STACK.  */
static inline void
yymarkStackDeleted (yyGLRStack* yystackp, size_t yyk)
{
  if (yystackp->yytops.yystates[yyk] != NULL)
    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yystates[yyk] = NULL;
}

/** Undelete the last stack that was marked as deleted.  Can only be
    done once after a deletion, and only when all other stacks have
    been deleted.  */
static void
yyundeleteLastStack (yyGLRStack* yystackp)
{
  if (yystackp->yylastDeleted == NULL || yystackp->yytops.yysize != 0)
    return;
  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
  yystackp->yytops.yysize = 1;
  YYDPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystackp->yylastDeleted = NULL;
}

static inline void
yyremoveDeletes (yyGLRStack* yystackp)
{
  size_t yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystackp->yytops.yysize)
    {
      if (yystackp->yytops.yystates[yyi] == NULL)
	{
	  if (yyi == yyj)
	    {
	      YYDPRINTF ((stderr, "Removing dead stacks.\n"));
	    }
	  yystackp->yytops.yysize -= 1;
	}
      else
	{
	  yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
	  /* In the current implementation, it's unnecessary to copy
	     yystackp->yytops.yylookaheadNeeds[yyi] since, after
	     yyremoveDeletes returns, the parser immediately either enters
	     deterministic operation or shifts a token.  However, it doesn't
	     hurt, and the code might evolve to need it.  */
	  yystackp->yytops.yylookaheadNeeds[yyj] =
	    yystackp->yytops.yylookaheadNeeds[yyi];
	  if (yyj != yyi)
	    {
	      YYDPRINTF ((stderr, "Rename stack %lu -> %lu.\n",
			  (unsigned long int) yyi, (unsigned long int) yyj));
	    }
	  yyj += 1;
	}
      yyi += 1;
    }
}

/** Shift to a new state on stack #K of STACK, corresponding to LR state
 * LRSTATE, at input position POSN, with (resolved) semantic value SVAL.  */
static inline void
yyglrShift (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
	    size_t yyposn,
	    YYSTYPE* yyvalp, YYLTYPE* yylocp)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yytrue;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yysval = *yyvalp;
  yynewState->yyloc = *yylocp;
  yystackp->yytops.yystates[yyk] = yynewState;

  YY_RESERVE_GLRSTACK (yystackp);
}

/** Shift stack #K of YYSTACK, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE.  */
static inline void
yyglrShiftDefer (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
		 size_t yyposn, yyGLRState* rhs, yyRuleNum yyrule)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yyfalse;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyfirstVal = NULL;
  yystackp->yytops.yystates[yyk] = yynewState;

  /* Invokes YY_RESERVE_GLRSTACK.  */
  yyaddDeferredAction (yystackp, yyk, yynewState, rhs, yyrule);
}

/** Pop the symbols consumed by reduction #RULE from the top of stack
 *  #K of STACK, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved.  Set *VALP to the resulting value,
 *  and *LOCP to the computed location (if any).  Return value is as
 *  for userAction.  */
static inline YYRESULTTAG
yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
	    YYSTYPE* yyvalp, YYLTYPE* yylocp)
{
  int yynrhs = yyrhsLength (yyrule);

  if (yystackp->yysplitPoint == NULL)
    {
      /* Standard special case: single stack.  */
      yyGLRStackItem* rhs = (yyGLRStackItem*) yystackp->yytops.yystates[yyk];
      YYASSERT (yyk == 0);
      yystackp->yynextFree -= yynrhs;
      yystackp->yyspaceLeft += yynrhs;
      yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
      return yyuserAction (yyrule, yynrhs, rhs,
			   yyvalp, yylocp, yystackp);
    }
  else
    {
      /* At present, doAction is never called in nondeterministic
       * mode, so this branch is never taken.  It is here in
       * anticipation of a future feature that will allow immediate
       * evaluation of selected actions in nondeterministic mode.  */
      int yyi;
      yyGLRState* yys;
      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
	= yystackp->yytops.yystates[yyk];
      if (yynrhs == 0)
	/* Set default location.  */
	yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yys->yyloc;
      for (yyi = 0; yyi < yynrhs; yyi += 1)
	{
	  yys = yys->yypred;
	  YYASSERT (yys);
	}
      yyupdateSplit (yystackp, yys);
      yystackp->yytops.yystates[yyk] = yys;
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
			   yyvalp, yylocp, yystackp);
    }
}

#if !YYDEBUG
# define YY_REDUCE_PRINT(Args)
#else
# define YY_REDUCE_PRINT(Args)		\
do {					\
  if (yydebug)				\
    yy_reduce_print Args;		\
} while (YYID (0))

/*----------------------------------------------------------.
| Report that the RULE is going to be reduced on stack #K.  |
`----------------------------------------------------------*/

/*ARGSUSED*/ static inline void
yy_reduce_print (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
		 YYSTYPE* yyvalp, YYLTYPE* yylocp)
{
  int yynrhs = yyrhsLength (yyrule);
  yybool yynormal __attribute__ ((__unused__)) =
    (yystackp->yysplitPoint == NULL);
  yyGLRStackItem* yyvsp = (yyGLRStackItem*) yystackp->yytops.yystates[yyk];
  int yylow = 1;
  int yyi;
  YYUSE (yyvalp);
  YYUSE (yylocp);
  YYFPRINTF (stderr, "Reducing stack %lu by rule %d (line %lu):\n",
	     (unsigned long int) yyk, yyrule - 1,
	     (unsigned long int) yyrline[yyrule]);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(((yyGLRStackItem const *)yyvsp)[YYFILL ((yyi + 1) - (yynrhs))].yystate.yysemantics.yysval)
		       , &(((yyGLRStackItem const *)yyvsp)[YYFILL ((yyi + 1) - (yynrhs))].yystate.yyloc)		       );
      YYFPRINTF (stderr, "\n");
    }
}
#endif

/** Pop items off stack #K of STACK according to grammar rule RULE,
 *  and push back on the resulting nonterminal symbol.  Perform the
 *  semantic action associated with RULE and store its value with the
 *  newly pushed state, if FORCEEVAL or if STACK is currently
 *  unambiguous.  Otherwise, store the deferred semantic action with
 *  the new state.  If the new state would have an identical input
 *  position, LR state, and predecessor to an existing state on the stack,
 *  it is identified with that existing state, eliminating stack #K from
 *  the STACK.  In this case, the (necessarily deferred) semantic value is
 *  added to the options for the existing state's semantic value.
 */
static inline YYRESULTTAG
yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
	     yybool yyforceEval)
{
  size_t yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == NULL)
    {
      YYSTYPE yysval;
      YYLTYPE yyloc;

      YY_REDUCE_PRINT ((yystackp, yyk, yyrule, &yysval, &yyloc));
      YYCHK (yydoAction (yystackp, yyk, yyrule, &yysval,
			 &yyloc));
      YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyrule], &yysval, &yyloc);
      yyglrShift (yystackp, yyk,
		  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
				 yylhsNonterm (yyrule)),
		  yyposn, &yysval, &yyloc);
    }
  else
    {
      size_t yyi;
      int yyn;
      yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
      yyStateNum yynewLRState;

      for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
	   0 < yyn; yyn -= 1)
	{
	  yys = yys->yypred;
	  YYASSERT (yys);
	}
      yyupdateSplit (yystackp, yys);
      yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
      YYDPRINTF ((stderr,
		  "Reduced stack %lu by rule #%d; action deferred.  Now in state %d.\n",
		  (unsigned long int) yyk, yyrule - 1, yynewLRState));
      for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
	if (yyi != yyk && yystackp->yytops.yystates[yyi] != NULL)
	  {
	    yyGLRState* yyp, *yysplit = yystackp->yysplitPoint;
	    yyp = yystackp->yytops.yystates[yyi];
	    while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
	      {
		if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
		  {
		    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
		    yymarkStackDeleted (yystackp, yyk);
		    YYDPRINTF ((stderr, "Merging stack %lu into stack %lu.\n",
				(unsigned long int) yyk,
				(unsigned long int) yyi));
		    return yyok;
		  }
		yyp = yyp->yypred;
	      }
	  }
      yystackp->yytops.yystates[yyk] = yys;
      yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
    }
  return yyok;
}

static size_t
yysplitStack (yyGLRStack* yystackp, size_t yyk)
{
  if (yystackp->yysplitPoint == NULL)
    {
      YYASSERT (yyk == 0);
      yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
    }
  if (yystackp->yytops.yysize >= yystackp->yytops.yycapacity)
    {
      yyGLRState** yynewStates;
      yybool* yynewLookaheadNeeds;

      yynewStates = NULL;

      if (yystackp->yytops.yycapacity
	  > (YYSIZEMAX / (2 * sizeof yynewStates[0])))
	yyMemoryExhausted (yystackp);
      yystackp->yytops.yycapacity *= 2;

      yynewStates =
	(yyGLRState**) YYREALLOC (yystackp->yytops.yystates,
				  (yystackp->yytops.yycapacity
				   * sizeof yynewStates[0]));
      if (yynewStates == NULL)
	yyMemoryExhausted (yystackp);
      yystackp->yytops.yystates = yynewStates;

      yynewLookaheadNeeds =
	(yybool*) YYREALLOC (yystackp->yytops.yylookaheadNeeds,
			     (yystackp->yytops.yycapacity
			      * sizeof yynewLookaheadNeeds[0]));
      if (yynewLookaheadNeeds == NULL)
	yyMemoryExhausted (yystackp);
      yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
    }
  yystackp->yytops.yystates[yystackp->yytops.yysize]
    = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
    = yystackp->yytops.yylookaheadNeeds[yyk];
  yystackp->yytops.yysize += 1;
  return yystackp->yytops.yysize-1;
}

/** True iff Y0 and Y1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols.  */
static yybool
yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  if (yyy0->yyrule == yyy1->yyrule)
    {
      yyGLRState *yys0, *yys1;
      int yyn;
      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
	   yyn = yyrhsLength (yyy0->yyrule);
	   yyn > 0;
	   yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
	if (yys0->yyposn != yys1->yyposn)
	  return yyfalse;
      return yytrue;
    }
  else
    return yyfalse;
}

/** Assuming identicalOptions (Y0,Y1), destructively merge the
 *  alternative semantic values for the RHS-symbols of Y1 and Y0.  */
static void
yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
       yyn = yyrhsLength (yyy0->yyrule);
       yyn > 0;
       yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
    {
      if (yys0 == yys1)
	break;
      else if (yys0->yyresolved)
	{
	  yys1->yyresolved = yytrue;
	  yys1->yysemantics.yysval = yys0->yysemantics.yysval;
	}
      else if (yys1->yyresolved)
	{
	  yys0->yyresolved = yytrue;
	  yys0->yysemantics.yysval = yys1->yysemantics.yysval;
	}
      else
	{
	  yySemanticOption** yyz0p;
	  yySemanticOption* yyz1;
	  yyz0p = &yys0->yysemantics.yyfirstVal;
	  yyz1 = yys1->yysemantics.yyfirstVal;
	  while (YYID (yytrue))
	    {
	      if (yyz1 == *yyz0p || yyz1 == NULL)
		break;
	      else if (*yyz0p == NULL)
		{
		  *yyz0p = yyz1;
		  break;
		}
	      else if (*yyz0p < yyz1)
		{
		  yySemanticOption* yyz = *yyz0p;
		  *yyz0p = yyz1;
		  yyz1 = yyz1->yynext;
		  (*yyz0p)->yynext = yyz;
		}
	      yyz0p = &(*yyz0p)->yynext;
	    }
	  yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
	}
    }
}

/** Y0 and Y1 represent two possible actions to take in a given
 *  parsing state; return 0 if no combination is possible,
 *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
static int
yypreference (yySemanticOption* y0, yySemanticOption* y1)
{
  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
  int p0 = yydprec[r0], p1 = yydprec[r1];

  if (p0 == p1)
    {
      if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
	return 0;
      else
	return 1;
    }
  if (p0 == 0 || p1 == 0)
    return 0;
  if (p0 < p1)
    return 3;
  if (p1 < p0)
    return 2;
  return 0;
}

static YYRESULTTAG yyresolveValue (yyGLRState* yys,
				   yyGLRStack* yystackp);


/** Resolve the previous N states starting at and including state S.  If result
 *  != yyok, some states may have been left unresolved possibly with empty
 *  semantic option chains.  Regardless of whether result = yyok, each state
 *  has been left with consistent data so that yydestroyGLRState can be invoked
 *  if necessary.  */
static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn,
		 yyGLRStack* yystackp)
{
  if (0 < yyn)
    {
      YYASSERT (yys->yypred);
      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp));
      if (! yys->yyresolved)
	YYCHK (yyresolveValue (yys, yystackp));
    }
  return yyok;
}

/** Resolve the states for the RHS of OPT, perform its user action, and return
 *  the semantic value and location.  Regardless of whether result = yyok, all
 *  RHS states have been destroyed (assuming the user action destroys all RHS
 *  semantic values if invoked).  */
static YYRESULTTAG
yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
		 YYSTYPE* yyvalp, YYLTYPE* yylocp)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs;
  int yychar_current;
  YYSTYPE yylval_current;
  YYLTYPE yylloc_current;
  YYRESULTTAG yyflag;

  yynrhs = yyrhsLength (yyopt->yyrule);
  yyflag = yyresolveStates (yyopt->yystate, yynrhs, yystackp);
  if (yyflag != yyok)
    {
      yyGLRState *yys;
      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
	yydestroyGLRState ("Cleanup: popping", yys);
      return yyflag;
    }

  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  if (yynrhs == 0)
    /* Set default location.  */
    yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yyopt->yystate->yyloc;
  yychar_current = yychar;
  yylval_current = yylval;
  yylloc_current = yylloc;
  yychar = yyopt->yyrawchar;
  yylval = yyopt->yyval;
  yylloc = yyopt->yyloc;
  yyflag = yyuserAction (yyopt->yyrule, yynrhs,
			   yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
			   yyvalp, yylocp, yystackp);
  yychar = yychar_current;
  yylval = yylval_current;
  yylloc = yylloc_current;
  return yyflag;
}

#if YYDEBUG
static void
yyreportTree (yySemanticOption* yyx, int yyindent)
{
  int yynrhs = yyrhsLength (yyx->yyrule);
  int yyi;
  yyGLRState* yys;
  yyGLRState* yystates[1 + YYMAXRHS];
  yyGLRState yyleftmost_state;

  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
    yystates[yyi] = yys;
  if (yys == NULL)
    {
      yyleftmost_state.yyposn = 0;
      yystates[0] = &yyleftmost_state;
    }
  else
    yystates[0] = yys;

  if (yyx->yystate->yyposn < yys->yyposn + 1)
    YYFPRINTF (stderr, "%*s%s -> <Rule %d, empty>\n",
	       yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
	       yyx->yyrule - 1);
  else
    YYFPRINTF (stderr, "%*s%s -> <Rule %d, tokens %lu .. %lu>\n",
	       yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
	       yyx->yyrule - 1, (unsigned long int) (yys->yyposn + 1),
	       (unsigned long int) yyx->yystate->yyposn);
  for (yyi = 1; yyi <= yynrhs; yyi += 1)
    {
      if (yystates[yyi]->yyresolved)
	{
	  if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
	    YYFPRINTF (stderr, "%*s%s <empty>\n", yyindent+2, "",
		       yytokenName (yyrhs[yyprhs[yyx->yyrule]+yyi-1]));
	  else
	    YYFPRINTF (stderr, "%*s%s <tokens %lu .. %lu>\n", yyindent+2, "",
		       yytokenName (yyrhs[yyprhs[yyx->yyrule]+yyi-1]),
		       (unsigned long int) (yystates[yyi - 1]->yyposn + 1),
		       (unsigned long int) yystates[yyi]->yyposn);
	}
      else
	yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
    }
}
#endif

/*ARGSUSED*/ static YYRESULTTAG
yyreportAmbiguity (yySemanticOption* yyx0,
		   yySemanticOption* yyx1)
{
  YYUSE (yyx0);
  YYUSE (yyx1);

#if YYDEBUG
  YYFPRINTF (stderr, "Ambiguity detected.\n");
  YYFPRINTF (stderr, "Option 1,\n");
  yyreportTree (yyx0, 2);
  YYFPRINTF (stderr, "\nOption 2,\n");
  yyreportTree (yyx1, 2);
  YYFPRINTF (stderr, "\n");
#endif

  yyerror (YY_("syntax is ambiguous"));
  return yyabort;
}

/** Starting at and including state S1, resolve the location for each of the
 *  previous N1 states that is unresolved.  The first semantic option of a state
 *  is always chosen.  */
static void
yyresolveLocations (yyGLRState* yys1, int yyn1,
		    yyGLRStack *yystackp)
{
  if (0 < yyn1)
    {
      yyresolveLocations (yys1->yypred, yyn1 - 1, yystackp);
      if (!yys1->yyresolved)
	{
	  yySemanticOption *yyoption;
	  yyGLRStackItem yyrhsloc[1 + YYMAXRHS];
	  int yynrhs;
	  int yychar_current;
	  YYSTYPE yylval_current;
	  YYLTYPE yylloc_current;
	  yyoption = yys1->yysemantics.yyfirstVal;
	  YYASSERT (yyoption != NULL);
	  yynrhs = yyrhsLength (yyoption->yyrule);
	  if (yynrhs > 0)
	    {
	      yyGLRState *yys;
	      int yyn;
	      yyresolveLocations (yyoption->yystate, yynrhs,
				  yystackp);
	      for (yys = yyoption->yystate, yyn = yynrhs;
		   yyn > 0;
		   yys = yys->yypred, yyn -= 1)
		yyrhsloc[yyn].yystate.yyloc = yys->yyloc;
	    }
	  else
	    {
	      /* Both yyresolveAction and yyresolveLocations traverse the GSS
		 in reverse rightmost order.  It is only necessary to invoke
		 yyresolveLocations on a subforest for which yyresolveAction
		 would have been invoked next had an ambiguity not been
		 detected.  Thus the location of the previous state (but not
		 necessarily the previous state itself) is guaranteed to be
		 resolved already.  */
	      yyGLRState *yyprevious = yyoption->yystate;
	      yyrhsloc[0].yystate.yyloc = yyprevious->yyloc;
	    }
	  yychar_current = yychar;
	  yylval_current = yylval;
	  yylloc_current = yylloc;
	  yychar = yyoption->yyrawchar;
	  yylval = yyoption->yyval;
	  yylloc = yyoption->yyloc;
	  YYLLOC_DEFAULT ((yys1->yyloc), yyrhsloc, yynrhs);
	  yychar = yychar_current;
	  yylval = yylval_current;
	  yylloc = yylloc_current;
	}
    }
}

/** Resolve the ambiguity represented in state S, perform the indicated
 *  actions, and set the semantic value of S.  If result != yyok, the chain of
 *  semantic options in S has been cleared instead or it has been left
 *  unmodified except that redundant options may have been removed.  Regardless
 *  of whether result = yyok, S has been left with consistent data so that
 *  yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp)
{
  yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
  yySemanticOption* yybest;
  yySemanticOption** yypp;
  yybool yymerge;
  YYSTYPE yysval;
  YYRESULTTAG yyflag;
  YYLTYPE *yylocp = &yys->yyloc;

  yybest = yyoptionList;
  yymerge = yyfalse;
  for (yypp = &yyoptionList->yynext; *yypp != NULL; )
    {
      yySemanticOption* yyp = *yypp;

      if (yyidenticalOptions (yybest, yyp))
	{
	  yymergeOptionSets (yybest, yyp);
	  *yypp = yyp->yynext;
	}
      else
	{
	  switch (yypreference (yybest, yyp))
	    {
	    case 0:
	      yyresolveLocations (yys, 1, yystackp);
	      return yyreportAmbiguity (yybest, yyp);
	      break;
	    case 1:
	      yymerge = yytrue;
	      break;
	    case 2:
	      break;
	    case 3:
	      yybest = yyp;
	      yymerge = yyfalse;
	      break;
	    default:
	      /* This cannot happen so it is not worth a YYASSERT (yyfalse),
		 but some compilers complain if the default case is
		 omitted.  */
	      break;
	    }
	  yypp = &yyp->yynext;
	}
    }

  if (yymerge)
    {
      yySemanticOption* yyp;
      int yyprec = yydprec[yybest->yyrule];
      yyflag = yyresolveAction (yybest, yystackp, &yysval,
				yylocp);
      if (yyflag == yyok)
	for (yyp = yybest->yynext; yyp != NULL; yyp = yyp->yynext)
	  {
	    if (yyprec == yydprec[yyp->yyrule])
	      {
		YYSTYPE yysval_other;
		YYLTYPE yydummy;
		yyflag = yyresolveAction (yyp, yystackp, &yysval_other,
					  &yydummy);
		if (yyflag != yyok)
		  {
		    yydestruct ("Cleanup: discarding incompletely merged value for",
				yystos[yys->yylrState],
				&yysval, yylocp);
		    break;
		  }
		yyuserMerge (yymerger[yyp->yyrule], &yysval, &yysval_other);
	      }
	  }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yysval, yylocp);

  if (yyflag == yyok)
    {
      yys->yyresolved = yytrue;
      yys->yysemantics.yysval = yysval;
    }
  else
    yys->yysemantics.yyfirstVal = NULL;
  return yyflag;
}

static YYRESULTTAG
yyresolveStack (yyGLRStack* yystackp)
{
  if (yystackp->yysplitPoint != NULL)
    {
      yyGLRState* yys;
      int yyn;

      for (yyn = 0, yys = yystackp->yytops.yystates[0];
	   yys != yystackp->yysplitPoint;
	   yys = yys->yypred, yyn += 1)
	continue;
      YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
			     ));
    }
  return yyok;
}

static void
yycompressStack (yyGLRStack* yystackp)
{
  yyGLRState* yyp, *yyq, *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == NULL)
    return;

  for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = NULL;
       yyp != yystackp->yysplitPoint;
       yyr = yyp, yyp = yyq, yyq = yyp->yypred)
    yyp->yypred = yyr;

  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
  yystackp->yynextFree = ((yyGLRStackItem*) yystackp->yysplitPoint) + 1;
  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
  yystackp->yysplitPoint = NULL;
  yystackp->yylastDeleted = NULL;

  while (yyr != NULL)
    {
      yystackp->yynextFree->yystate = *yyr;
      yyr = yyr->yypred;
      yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
      yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
      yystackp->yynextFree += 1;
      yystackp->yyspaceLeft -= 1;
    }
}

static YYRESULTTAG
yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
		   size_t yyposn)
{
  int yyaction;
  const short int* yyconflicts;
  yyRuleNum yyrule;

  while (yystackp->yytops.yystates[yyk] != NULL)
    {
      yyStateNum yystate = yystackp->yytops.yystates[yyk]->yylrState;
      YYDPRINTF ((stderr, "Stack %lu Entering state %d\n",
		  (unsigned long int) yyk, yystate));

      YYASSERT (yystate != YYFINAL);

      if (yyisDefaultedState (yystate))
	{
	  yyrule = yydefaultAction (yystate);
	  if (yyrule == 0)
	    {
	      YYDPRINTF ((stderr, "Stack %lu dies.\n",
			  (unsigned long int) yyk));
	      yymarkStackDeleted (yystackp, yyk);
	      return yyok;
	    }
	  YYCHK (yyglrReduce (yystackp, yyk, yyrule, yyfalse));
	}
      else
	{
	  yySymbol yytoken;
	  yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;
	  if (yychar == YYEMPTY)
	    {
	      YYDPRINTF ((stderr, "Reading a token: "));
	      yychar = YYLEX;
	    }

	  if (yychar <= YYEOF)
	    {
	      yychar = yytoken = YYEOF;
	      YYDPRINTF ((stderr, "Now at end of input.\n"));
	    }
	  else
	    {
	      yytoken = YYTRANSLATE (yychar);
	      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
	    }

	  yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);

	  while (*yyconflicts != 0)
	    {
	      size_t yynewStack = yysplitStack (yystackp, yyk);
	      YYDPRINTF ((stderr, "Splitting off stack %lu from %lu.\n",
			  (unsigned long int) yynewStack,
			  (unsigned long int) yyk));
	      YYCHK (yyglrReduce (yystackp, yynewStack,
				  *yyconflicts, yyfalse));
	      YYCHK (yyprocessOneStack (yystackp, yynewStack,
					yyposn));
	      yyconflicts += 1;
	    }

	  if (yyisShiftAction (yyaction))
	    break;
	  else if (yyisErrorAction (yyaction))
	    {
	      YYDPRINTF ((stderr, "Stack %lu dies.\n",
			  (unsigned long int) yyk));
	      yymarkStackDeleted (yystackp, yyk);
	      break;
	    }
	  else
	    YYCHK (yyglrReduce (yystackp, yyk, -yyaction,
				yyfalse));
	}
    }
  return yyok;
}

/*ARGSUSED*/ static void
yyreportSyntaxError (yyGLRStack* yystackp)
{
  if (yystackp->yyerrState != 0)
    return;
#if ! YYERROR_VERBOSE
  yyerror (YY_("syntax error"));
#else
  yySymbol yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);
  size_t yysize0 = yytnamerr (NULL, yytokenName (yytoken));
  size_t yysize = yysize0;
  size_t yysize1;
  yybool yysize_overflow = yyfalse;
  char* yymsg = NULL;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected").  */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
      yyarg[yycount++] = yytokenName (yytoken);
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for this
             state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;
          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytokenName (yyx);
                yysize1 = yysize + yytnamerr (NULL, yytokenName (yyx));
                yysize_overflow |= yysize1 < yysize;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
#define YYCASE_(N, S)                   \
      case N:                           \
        yyformat = S;                   \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  yysize1 = yysize + strlen (yyformat);
  yysize_overflow |= yysize1 < yysize;
  yysize = yysize1;

  if (!yysize_overflow)
    yymsg = (char *) YYMALLOC (yysize);

  if (yymsg)
    {
      char *yyp = yymsg;
      int yyi = 0;
      while ((*yyp = *yyformat))
        {
          if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
            {
              yyp += yytnamerr (yyp, yyarg[yyi++]);
              yyformat += 2;
            }
          else
            {
              yyp++;
              yyformat++;
            }
        }
      yyerror (yymsg);
      YYFREE (yymsg);
    }
  else
    {
      yyerror (YY_("syntax error"));
      yyMemoryExhausted (yystackp);
    }
#endif /* YYERROR_VERBOSE */
  yynerrs += 1;
}

/* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
   yylval, and yylloc are the syntactic category, semantic value, and location
   of the lookahead.  */
/*ARGSUSED*/ static void
yyrecoverSyntaxError (yyGLRStack* yystackp)
{
  size_t yyk;
  int yyj;

  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (YYID (yytrue))
      {
	yySymbol yytoken;
	if (yychar == YYEOF)
	  yyFail (yystackp, NULL);
	if (yychar != YYEMPTY)
	  {
	    /* We throw away the lookahead, but the error range
	       of the shifted error token must take it into account.  */
	    yyGLRState *yys = yystackp->yytops.yystates[0];
	    yyGLRStackItem yyerror_range[3];
	    yyerror_range[1].yystate.yyloc = yys->yyloc;
	    yyerror_range[2].yystate.yyloc = yylloc;
	    YYLLOC_DEFAULT ((yys->yyloc), yyerror_range, 2);
	    yytoken = YYTRANSLATE (yychar);
	    yydestruct ("Error: discarding",
			yytoken, &yylval, &yylloc);
	  }
	YYDPRINTF ((stderr, "Reading a token: "));
	yychar = YYLEX;
	if (yychar <= YYEOF)
	  {
	    yychar = yytoken = YYEOF;
	    YYDPRINTF ((stderr, "Now at end of input.\n"));
	  }
	else
	  {
	    yytoken = YYTRANSLATE (yychar);
	    YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
	  }
	yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
	if (yypact_value_is_default (yyj))
	  return;
	yyj += yytoken;
	if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
	  {
	    if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
	      return;
	  }
	else if (! yytable_value_is_error (yytable[yyj]))
	  return;
      }

  /* Reduce to one stack.  */
  for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
    if (yystackp->yytops.yystates[yyk] != NULL)
      break;
  if (yyk >= yystackp->yytops.yysize)
    yyFail (yystackp, NULL);
  for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
    yymarkStackDeleted (yystackp, yyk);
  yyremoveDeletes (yystackp);
  yycompressStack (yystackp);

  /* Now pop stack until we find a state that shifts the error token.  */
  yystackp->yyerrState = 3;
  while (yystackp->yytops.yystates[0] != NULL)
    {
      yyGLRState *yys = yystackp->yytops.yystates[0];
      yyj = yypact[yys->yylrState];
      if (! yypact_value_is_default (yyj))
	{
	  yyj += YYTERROR;
	  if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYTERROR
	      && yyisShiftAction (yytable[yyj]))
	    {
	      /* Shift the error token having adjusted its location.  */
	      YYLTYPE yyerrloc;
	      yystackp->yyerror_range[2].yystate.yyloc = yylloc;
	      YYLLOC_DEFAULT (yyerrloc, (yystackp->yyerror_range), 2);
	      YY_SYMBOL_PRINT ("Shifting", yystos[yytable[yyj]],
			       &yylval, &yyerrloc);
	      yyglrShift (yystackp, 0, yytable[yyj],
			  yys->yyposn, &yylval, &yyerrloc);
	      yys = yystackp->yytops.yystates[0];
	      break;
	    }
	}
      yystackp->yyerror_range[1].yystate.yyloc = yys->yyloc;
      if (yys->yypred != NULL)
	yydestroyGLRState ("Error: popping", yys);
      yystackp->yytops.yystates[0] = yys->yypred;
      yystackp->yynextFree -= 1;
      yystackp->yyspaceLeft += 1;
    }
  if (yystackp->yytops.yystates[0] == NULL)
    yyFail (yystackp, NULL);
}

#define YYCHK1(YYE)							     \
  do {									     \
    switch (YYE) {							     \
    case yyok:								     \
      break;								     \
    case yyabort:							     \
      goto yyabortlab;							     \
    case yyaccept:							     \
      goto yyacceptlab;							     \
    case yyerr:								     \
      goto yyuser_error;						     \
    default:								     \
      goto yybuglab;							     \
    }									     \
  } while (YYID (0))


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
  int yyresult;
  yyGLRStack yystack;
  yyGLRStack* const yystackp = &yystack;
  size_t yyposn;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY;
  yylval = yyval_default;

#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif


  if (! yyinitGLRStack (yystackp, YYINITDEPTH))
    goto yyexhaustedlab;
  switch (YYSETJMP (yystack.yyexception_buffer))
    {
    case 0: break;
    case 1: goto yyabortlab;
    case 2: goto yyexhaustedlab;
    default: goto yybuglab;
    }
  yyglrShift (&yystack, 0, 0, 0, &yylval, &yylloc);
  yyposn = 0;

  while (YYID (yytrue))
    {
      /* For efficiency, we have two loops, the first of which is
	 specialized to deterministic operation (single stack, no
	 potential ambiguity).  */
      /* Standard mode */
      while (YYID (yytrue))
	{
	  yyRuleNum yyrule;
	  int yyaction;
	  const short int* yyconflicts;

	  yyStateNum yystate = yystack.yytops.yystates[0]->yylrState;
	  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
	  if (yystate == YYFINAL)
	    goto yyacceptlab;
	  if (yyisDefaultedState (yystate))
	    {
	      yyrule = yydefaultAction (yystate);
	      if (yyrule == 0)
		{
		  yystack.yyerror_range[1].yystate.yyloc = yylloc;
		  yyreportSyntaxError (&yystack);
		  goto yyuser_error;
		}
	      YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue));
	    }
	  else
	    {
	      yySymbol yytoken;
	      if (yychar == YYEMPTY)
		{
		  YYDPRINTF ((stderr, "Reading a token: "));
		  yychar = YYLEX;
		}

	      if (yychar <= YYEOF)
		{
		  yychar = yytoken = YYEOF;
		  YYDPRINTF ((stderr, "Now at end of input.\n"));
		}
	      else
		{
		  yytoken = YYTRANSLATE (yychar);
		  YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
		}

	      yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
	      if (*yyconflicts != 0)
		break;
	      if (yyisShiftAction (yyaction))
		{
		  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
		  yychar = YYEMPTY;
		  yyposn += 1;
		  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval, &yylloc);
		  if (0 < yystack.yyerrState)
		    yystack.yyerrState -= 1;
		}
	      else if (yyisErrorAction (yyaction))
		{
		  yystack.yyerror_range[1].yystate.yyloc = yylloc;
		  yyreportSyntaxError (&yystack);
		  goto yyuser_error;
		}
	      else
		YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue));
	    }
	}

      while (YYID (yytrue))
	{
	  yySymbol yytoken_to_shift;
	  size_t yys;

	  for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
	    yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;

	  /* yyprocessOneStack returns one of three things:

	      - An error flag.  If the caller is yyprocessOneStack, it
		immediately returns as well.  When the caller is finally
		yyparse, it jumps to an error label via YYCHK1.

	      - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
		(&yystack, yys), which sets the top state of yys to NULL.  Thus,
		yyparse's following invocation of yyremoveDeletes will remove
		the stack.

	      - yyok, when ready to shift a token.

	     Except in the first case, yyparse will invoke yyremoveDeletes and
	     then shift the next token onto all remaining stacks.  This
	     synchronization of the shift (that is, after all preceding
	     reductions on all stacks) helps prevent double destructor calls
	     on yylval in the event of memory exhaustion.  */

	  for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
	    YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn));
	  yyremoveDeletes (&yystack);
	  if (yystack.yytops.yysize == 0)
	    {
	      yyundeleteLastStack (&yystack);
	      if (yystack.yytops.yysize == 0)
		yyFail (&yystack, YY_("syntax error"));
	      YYCHK1 (yyresolveStack (&yystack));
	      YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
	      yystack.yyerror_range[1].yystate.yyloc = yylloc;
	      yyreportSyntaxError (&yystack);
	      goto yyuser_error;
	    }

	  /* If any yyglrShift call fails, it will fail after shifting.  Thus,
	     a copy of yylval will already be on stack 0 in the event of a
	     failure in the following loop.  Thus, yychar is set to YYEMPTY
	     before the loop to make sure the user destructor for yylval isn't
	     called twice.  */
	  yytoken_to_shift = YYTRANSLATE (yychar);
	  yychar = YYEMPTY;
	  yyposn += 1;
	  for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
	    {
	      int yyaction;
	      const short int* yyconflicts;
	      yyStateNum yystate = yystack.yytops.yystates[yys]->yylrState;
	      yygetLRActions (yystate, yytoken_to_shift, &yyaction,
			      &yyconflicts);
	      /* Note that yyconflicts were handled by yyprocessOneStack.  */
	      YYDPRINTF ((stderr, "On stack %lu, ", (unsigned long int) yys));
	      YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
	      yyglrShift (&yystack, yys, yyaction, yyposn,
			  &yylval, &yylloc);
	      YYDPRINTF ((stderr, "Stack %lu now in state #%d\n",
			  (unsigned long int) yys,
			  yystack.yytops.yystates[yys]->yylrState));
	    }

	  if (yystack.yytops.yysize == 1)
	    {
	      YYCHK1 (yyresolveStack (&yystack));
	      YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
	      yycompressStack (&yystack);
	      break;
	    }
	}
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack);
      yyposn = yystack.yytops.yystates[0]->yyposn;
    }

 yyacceptlab:
  yyresult = 0;
  goto yyreturn;

 yybuglab:
  YYASSERT (yyfalse);
  goto yyabortlab;

 yyabortlab:
  yyresult = 1;
  goto yyreturn;

 yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;

 yyreturn:
  if (yychar != YYEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
		YYTRANSLATE (yychar),
		&yylval, &yylloc);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems)
    {
      yyGLRState** yystates = yystack.yytops.yystates;
      if (yystates)
	{
	  size_t yysize = yystack.yytops.yysize;
	  size_t yyk;
	  for (yyk = 0; yyk < yysize; yyk += 1)
	    if (yystates[yyk])
	      {
		while (yystates[yyk])
		  {
		    yyGLRState *yys = yystates[yyk];
		    yystack.yyerror_range[1].yystate.yyloc = yys->yyloc;
		    if (yys->yypred != NULL)
		      yydestroyGLRState ("Cleanup: popping", yys);
		    yystates[yyk] = yys->yypred;
		    yystack.yynextFree -= 1;
		    yystack.yyspaceLeft += 1;
		  }
		break;
	      }
	}
      yyfreeGLRStack (&yystack);
    }

  /* Make sure YYID is used.  */
  return YYID (yyresult);
}

/* DEBUGGING ONLY */
#if YYDEBUG
static void yypstack (yyGLRStack* yystackp, size_t yyk)
  __attribute__ ((__unused__));
static void yypdumpstack (yyGLRStack* yystackp) __attribute__ ((__unused__));

static void
yy_yypstack (yyGLRState* yys)
{
  if (yys->yypred)
    {
      yy_yypstack (yys->yypred);
      YYFPRINTF (stderr, " -> ");
    }
  YYFPRINTF (stderr, "%d@%lu", yys->yylrState,
             (unsigned long int) yys->yyposn);
}

static void
yypstates (yyGLRState* yyst)
{
  if (yyst == NULL)
    YYFPRINTF (stderr, "<null>");
  else
    yy_yypstack (yyst);
  YYFPRINTF (stderr, "\n");
}

static void
yypstack (yyGLRStack* yystackp, size_t yyk)
{
  yypstates (yystackp->yytops.yystates[yyk]);
}

#define YYINDEX(YYX)							     \
    ((YYX) == NULL ? -1 : (yyGLRStackItem*) (YYX) - yystackp->yyitems)


static void
yypdumpstack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yyp;
  size_t yyi;
  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
    {
      YYFPRINTF (stderr, "%3lu. ",
                 (unsigned long int) (yyp - yystackp->yyitems));
      if (*(yybool *) yyp)
	{
	  YYFPRINTF (stderr, "Res: %d, LR State: %d, posn: %lu, pred: %ld",
		     yyp->yystate.yyresolved, yyp->yystate.yylrState,
		     (unsigned long int) yyp->yystate.yyposn,
		     (long int) YYINDEX (yyp->yystate.yypred));
	  if (! yyp->yystate.yyresolved)
	    YYFPRINTF (stderr, ", firstVal: %ld",
		       (long int) YYINDEX (yyp->yystate
                                             .yysemantics.yyfirstVal));
	}
      else
	{
	  YYFPRINTF (stderr, "Option. rule: %d, state: %ld, next: %ld",
		     yyp->yyoption.yyrule - 1,
		     (long int) YYINDEX (yyp->yyoption.yystate),
		     (long int) YYINDEX (yyp->yyoption.yynext));
	}
      YYFPRINTF (stderr, "\n");
    }
  YYFPRINTF (stderr, "Tops:");
  for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
    YYFPRINTF (stderr, "%lu: %ld; ", (unsigned long int) yyi,
	       (long int) YYINDEX (yystackp->yytops.yystates[yyi]));
  YYFPRINTF (stderr, "\n");
}
#endif



/* Line 2659 of glr.c  */
#line 1668 "ned2.y"


//----------------------------------------------------------------------
// general bison/flex stuff:
//
int ned2yylex_destroy();  // from lex.XXX.cc file

NEDElement *doParseNED2(NEDParser *p, const char *nedtext)
{
#if YYDEBUG != 0      /* #if added --VA */
    yydebug = YYDEBUGGING_ON;
#endif

    ned2yylex_destroy();

    NONREENTRANT_NED_PARSER(p);

    // reset the lexer
    pos.co = 0;
    pos.li = 1;
    prevpos = pos;

    yyin = NULL;
    yyout = stderr; // not used anyway

    // alloc buffer
    struct yy_buffer_state *handle = yy_scan_string(nedtext);
    if (!handle)
        {np->getErrors()->addError("", "unable to allocate work memory"); return NULL;}

    // create parser state and NEDFileElement
    resetParserState();
    ps.nedfile = new NedFileElement();

    // store file name with slashes always, even on Windows -- neddoc relies on that
    ps.nedfile->setFilename(slashifyFilename(np->getFileName()).c_str());
    ps.nedfile->setVersion("2");

    // storing the start and end position of the whole file for the NedFileElement
    // NOTE: we cannot use storePos() because it strips off the leading spaces
    // and comments from the element.
    YYLTYPE pos = np->getSource()->getFullTextPos();
    NEDSourceRegion region;
    region.startLine = pos.first_line;
    region.startColumn = pos.first_column;
    region.endLine = pos.last_line;
    region.endColumn = pos.last_column;
    ps.nedfile->setSourceRegion(region);

    // store file comment
    storeFileComment(ps.nedfile);

    ps.propertyscope.push(ps.nedfile);

    globalps = ps; // remember this for error recovery

    if (np->getStoreSourceFlag())
        storeSourceCode(ps.nedfile, np->getSource()->getFullTextPos());

    // parse
    try
    {
        yyparse();
    }
    catch (NEDException& e)
    {
        yyerror((std::string("error during parsing: ")+e.what()).c_str());
        yy_delete_buffer(handle);
        return NULL;
    }

    if (np->getErrors()->empty())
    {
        // more sanity checks
        if (ps.propertyscope.size()!=1 || ps.propertyscope.top()!=ps.nedfile)
            INTERNAL_ERROR0(NULL, "error during parsing: imbalanced propertyscope");
        if (!ps.blockscope.empty() || !ps.typescope.empty())
            INTERNAL_ERROR0(NULL, "error during parsing: imbalanced blockscope or typescope");
    }
    yy_delete_buffer(handle);

    return ps.nedfile;
}

void yyerror(const char *s)
{
    // chop newline
    char buf[250];
    strcpy(buf, s);
    if (buf[strlen(buf)-1] == '\n')
        buf[strlen(buf)-1] = '\0';

    np->error(buf, pos.li);
}

