/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse         expryyparse
#define yylex           expryylex
#define yyerror         expryyerror
#define yylval          expryylval
#define yychar          expryychar
#define yydebug         expryydebug
#define yynerrs         expryynerrs


/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 43 "expr.y"


#include <stdio.h>
#include <stdlib.h>
#include "expryydefs.h"
#include "commonutil.h"

#define YYDEBUG 1           /* allow debugging */
#define YYDEBUGGING_ON 0    /* turn on/off debugging */

#if YYDEBUG != 0
#define YYERROR_VERBOSE     /* more detailed error messages */
#include <string.h>         /* YYVERBOSE needs it */
#endif

#define yyin expryyin
#define yyout expryyout
#define yyrestart expryyrestart
#define yy_scan_string expryy_scan_string
#define yy_delete_buffer expryy_delete_buffer
extern FILE *yyin;
extern FILE *yyout;
struct yy_buffer_state;
struct yy_buffer_state *yy_scan_string(const char *str);
void yy_delete_buffer(struct yy_buffer_state *);
void yyrestart(FILE *);
int yylex();
void yyerror (const char *s);

LineColumn xpos, xprevpos;


#include "cdynamicexpression.h"
#include "cpar.h"
#include "cxmlelement.h"
#include "cexception.h"
#include "globals.h"
#include "cnedmathfunction.h"
#include "cnedfunction.h"
#include "nedsupport.h"
#include "stringutil.h"
#include "unitconversion.h"

USING_NAMESPACE

static cDynamicExpression::Elem *e;

static char *expryyconcat(char *s1, char *s2, char *s3=NULL)
{
    char *d = new char[strlen(s1)+strlen(s2)+strlen(s3?s3:"")+4];
    strcpy(d, s1);
    strcat(d, " ");
    strcat(d, s2);
    if (s3) {strcat(d, " "); strcat(d, s3);}
    delete [] s1; delete [] s2; delete [] s3;
    return d;
}

static void addFunction(const char *funcname, int argc)
{
    cNEDMathFunction *f = cNEDMathFunction::find(funcname, argc);
    if (f) {
        *e++ = f;
        return;
    }
    cNEDFunction *nf = cNEDFunction::find(funcname);
    if (nf) {
        if (argc < nf->getMinArgs() || (argc > nf->getMaxArgs() && !nf->hasVarArgs()))
            yyerror(opp_stringf("function `%s' does not accept %d arguments", nf->getSignature(), argc).c_str());
        (e++)->set(nf,argc);
        return;
    }
    yyerror(opp_stringf("function `%s()' (with %d args) not found (Define_NED_Function() or Define_NED_Math_Function() missing from C++ code?)", funcname, argc).c_str());
}

static double parseQuantity(const char *text, std::string& unit)
{
    try {
        // evaluate quantities like "5s 230ms"
        return UnitConversion::parseQuantity(text, unit);
    }
    catch (std::exception& e) {
        yyerror(e.what());
        return 0;
    }
}



/* Line 268 of yacc.c  */
#line 169 "expr.tab.cc"

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


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 283 "expr.tab.cc"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  49
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   778

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNRULES -- Number of states.  */
#define YYNSTATES  162

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    44,     2,     2,
      47,    48,    42,    40,    49,    41,    50,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    37,     2,
      39,     2,    38,    36,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    52,    45,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    14,    16,    20,    25,
      29,    33,    37,    41,    45,    49,    52,    56,    60,    64,
      68,    72,    76,    80,    84,    88,    91,    95,    99,   103,
     106,   110,   114,   120,   125,   130,   135,   139,   144,   151,
     160,   171,   184,   199,   216,   235,   256,   279,   281,   283,
     285,   287,   289,   291,   293,   297,   301,   308,   310,   314,
     319,   326,   333,   343,   345,   347,   349,   351,   353,   355,
     357,   359,   361,   365,   369,   372
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      54,     0,    -1,    55,    -1,    11,    -1,    12,    -1,    12,
      47,    55,    48,    -1,    56,    -1,    47,    55,    48,    -1,
      13,    47,    55,    48,    -1,    55,    40,    55,    -1,    55,
      41,    55,    -1,    55,    42,    55,    -1,    55,    43,    55,
      -1,    55,    44,    55,    -1,    55,    45,    55,    -1,    41,
      55,    -1,    55,    21,    55,    -1,    55,    22,    55,    -1,
      55,    38,    55,    -1,    55,    23,    55,    -1,    55,    39,
      55,    -1,    55,    24,    55,    -1,    55,    25,    55,    -1,
      55,    26,    55,    -1,    55,    27,    55,    -1,    28,    55,
      -1,    55,    29,    55,    -1,    55,    30,    55,    -1,    55,
      31,    55,    -1,    32,    55,    -1,    55,    33,    55,    -1,
      55,    34,    55,    -1,    55,    36,    55,    37,    55,    -1,
       4,    47,    55,    48,    -1,     3,    47,    55,    48,    -1,
       5,    47,    55,    48,    -1,    57,    47,    48,    -1,    57,
      47,    55,    48,    -1,    57,    47,    55,    49,    55,    48,
      -1,    57,    47,    55,    49,    55,    49,    55,    48,    -1,
      57,    47,    55,    49,    55,    49,    55,    49,    55,    48,
      -1,    57,    47,    55,    49,    55,    49,    55,    49,    55,
      49,    55,    48,    -1,    57,    47,    55,    49,    55,    49,
      55,    49,    55,    49,    55,    49,    55,    48,    -1,    57,
      47,    55,    49,    55,    49,    55,    49,    55,    49,    55,
      49,    55,    49,    55,    48,    -1,    57,    47,    55,    49,
      55,    49,    55,    49,    55,    49,    55,    49,    55,    49,
      55,    49,    55,    48,    -1,    57,    47,    55,    49,    55,
      49,    55,    49,    55,    49,    55,    49,    55,    49,    55,
      49,    55,    49,    55,    48,    -1,    57,    47,    55,    49,
      55,    49,    55,    49,    55,    49,    55,    49,    55,    49,
      55,    49,    55,    49,    55,    49,    55,    48,    -1,    58,
      -1,    59,    -1,    60,    -1,    17,    -1,    16,    -1,     7,
      -1,    17,    -1,    10,    50,    17,    -1,    17,    50,    17,
      -1,    17,    51,    54,    52,    50,    17,    -1,    15,    -1,
      15,    47,    48,    -1,    14,    47,    17,    48,    -1,    14,
      47,    10,    50,    17,    48,    -1,    14,    47,    17,    50,
      17,    48,    -1,    14,    47,    17,    51,    54,    52,    50,
      17,    48,    -1,    61,    -1,    62,    -1,    63,    -1,    20,
      -1,     8,    -1,     9,    -1,    18,    -1,    19,    -1,    64,
      -1,    64,    18,    17,    -1,    64,    19,    17,    -1,    18,
      17,    -1,    19,    17,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   135,   135,   136,   138,   140,   145,   146,   147,   150,
     152,   154,   156,   158,   160,   163,   167,   169,   171,   173,
     175,   177,   180,   182,   184,   187,   191,   193,   195,   198,
     201,   203,   205,   208,   210,   212,   215,   217,   219,   221,
     223,   225,   227,   229,   231,   233,   235,   240,   241,   242,
     246,   247,   249,   254,   256,   258,   260,   265,   267,   269,
     271,   273,   275,   280,   281,   282,   286,   291,   293,   298,
     300,   302,   313,   315,   317,   319
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DOUBLETYPE", "INTTYPE", "STRINGTYPE",
  "BOOLTYPE", "XMLTYPE", "TRUE_", "FALSE_", "THIS_", "ASK_", "DEFAULT_",
  "CONST_", "SIZEOF_", "INDEX_", "XMLDOC_", "NAME", "INTCONSTANT",
  "REALCONSTANT", "STRINGCONSTANT", "EQ_", "NE_", "GE_", "LE_", "AND_",
  "OR_", "XOR_", "NOT_", "BINAND_", "BINOR_", "BINXOR_", "BINCOMPL_",
  "SHIFTLEFT_", "SHIFTRIGHT_", "INVALID_CHAR", "'?'", "':'", "'>'", "'<'",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "UMIN_", "'('", "')'", "','",
  "'.'", "'['", "']'", "$accept", "expression", "expr", "simple_expr",
  "funcname", "identifier", "special_expr", "literal", "stringliteral",
  "boolliteral", "numliteral", "quantity", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,    63,    58,    62,    60,
      43,    45,    42,    47,    37,    94,   291,    40,    41,    44,
      46,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    54,    54,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    56,    56,    56,
      57,    57,    57,    58,    58,    58,    58,    59,    59,    59,
      59,    59,    59,    60,    60,    60,    61,    62,    62,    63,
      63,    63,    64,    64,    64,    64
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     4,     1,     3,     4,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     2,
       3,     3,     5,     4,     4,     4,     3,     4,     6,     8,
      10,    12,    14,    16,    18,    20,    22,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     6,     1,     3,     4,
       6,     6,     9,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,    52,    67,    68,     0,     3,     4,
       0,     0,    57,    51,    53,    69,    70,    66,     0,     0,
       0,     0,     0,     2,     6,     0,    47,    48,    49,    63,
      64,    65,    71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,    75,    25,    29,    15,     0,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    54,     0,     0,
       0,     0,    58,    55,     0,     7,    16,    17,    19,    21,
      22,    23,    24,    26,    27,    28,    30,    31,     0,    18,
      20,     9,    10,    11,    12,    13,    14,    36,     0,    72,
      73,    34,    33,    35,     5,     8,     0,    59,     0,     0,
       0,     0,    37,     0,     0,     0,     0,     0,    32,     0,
      60,    61,     0,    56,    38,     0,     0,     0,     0,    39,
       0,    62,     0,    40,     0,     0,    41,     0,     0,    42,
       0,     0,    43,     0,     0,    44,     0,     0,    45,     0,
       0,    46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -39
static const yytype_int16 yypact[] =
{
     139,   -33,   -16,    10,   -39,   -39,   -39,   -37,   -39,    15,
      16,    25,    29,   -39,   -29,    11,    63,   -39,   174,   174,
     174,   174,    82,   683,   -39,    46,   -39,   -39,   -39,   -39,
     -39,   -39,    72,   174,   174,   174,    77,   174,   174,    -5,
      47,    79,   139,   -39,   -39,   -39,   -39,   -39,   462,   -39,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,    51,    80,    85,   490,   518,   546,   -39,   574,   602,
      54,   -21,   -39,   -39,    61,   -39,    44,    44,    44,    44,
     733,   733,   733,    67,    67,    67,   -34,   -34,   658,    44,
      44,   -19,   -19,    69,    69,    69,    69,   -39,   201,   -39,
     -39,   -39,   -39,   -39,   -39,   -39,    89,   -39,    98,   139,
      66,   174,   -39,   174,    70,    71,    68,   104,   708,   230,
     -39,   -39,    73,   -39,   -39,   174,   107,   259,    83,   -39,
     174,   -39,   288,   -39,   174,   317,   -39,   174,   346,   -39,
     174,   375,   -39,   174,   404,   -39,   174,   433,   -39,   174,
     630,   -39
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -39,   -38,   -18,   -39,   -39,   -39,   -39,   -39,   -39,   -39,
     -39,   -39
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -51
static const yytype_int16 yytable[] =
{
      45,    46,    47,    48,    84,    80,    65,    66,    67,    68,
      69,    70,    81,    36,    33,    74,    75,    76,   -50,    78,
      79,    41,    42,    67,    68,    69,    70,   117,    43,   118,
     119,    34,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   108,     1,     2,     3,    35,     4,     5,
       6,     7,    37,    38,    10,    11,    12,    13,    14,    15,
      16,    17,    39,    57,    58,    59,    40,    60,    61,    18,
      44,   126,    49,    19,    65,    66,    67,    68,    69,    70,
      72,    73,    20,    71,    77,    82,    83,   109,    21,   107,
      60,    61,   110,   128,   116,   129,   124,    65,    66,    67,
      68,    69,    70,   120,    70,   125,   127,   137,   130,   131,
     132,   133,   142,   136,   138,     0,   145,     0,     0,   148,
       0,   141,   151,     0,     0,   154,     0,     0,   157,     0,
       0,   160,     1,     2,     3,     0,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
       0,     0,     0,     0,     0,     0,     0,    18,     0,     0,
       0,    19,     0,     0,     0,     0,     0,     1,     2,     3,
      20,     4,     5,     6,     7,     0,    21,    10,    11,    12,
      13,    14,    15,    16,    17,     0,     0,     0,     0,     0,
       0,     0,    18,     0,     0,     0,    19,     0,     0,     0,
       0,     0,     0,     0,     0,    20,     0,     0,     0,     0,
       0,    21,    50,    51,    52,    53,    54,    55,    56,     0,
      57,    58,    59,     0,    60,    61,     0,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,     0,     0,   122,
     123,    50,    51,    52,    53,    54,    55,    56,     0,    57,
      58,    59,     0,    60,    61,     0,    62,     0,    63,    64,
      65,    66,    67,    68,    69,    70,     0,     0,   134,   135,
      50,    51,    52,    53,    54,    55,    56,     0,    57,    58,
      59,     0,    60,    61,     0,    62,     0,    63,    64,    65,
      66,    67,    68,    69,    70,     0,     0,   139,   140,    50,
      51,    52,    53,    54,    55,    56,     0,    57,    58,    59,
       0,    60,    61,     0,    62,     0,    63,    64,    65,    66,
      67,    68,    69,    70,     0,     0,   143,   144,    50,    51,
      52,    53,    54,    55,    56,     0,    57,    58,    59,     0,
      60,    61,     0,    62,     0,    63,    64,    65,    66,    67,
      68,    69,    70,     0,     0,   146,   147,    50,    51,    52,
      53,    54,    55,    56,     0,    57,    58,    59,     0,    60,
      61,     0,    62,     0,    63,    64,    65,    66,    67,    68,
      69,    70,     0,     0,   149,   150,    50,    51,    52,    53,
      54,    55,    56,     0,    57,    58,    59,     0,    60,    61,
       0,    62,     0,    63,    64,    65,    66,    67,    68,    69,
      70,     0,     0,   152,   153,    50,    51,    52,    53,    54,
      55,    56,     0,    57,    58,    59,     0,    60,    61,     0,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
       0,     0,   155,   156,    50,    51,    52,    53,    54,    55,
      56,     0,    57,    58,    59,     0,    60,    61,     0,    62,
       0,    63,    64,    65,    66,    67,    68,    69,    70,     0,
       0,   158,   159,    50,    51,    52,    53,    54,    55,    56,
       0,    57,    58,    59,     0,    60,    61,     0,    62,     0,
      63,    64,    65,    66,    67,    68,    69,    70,     0,     0,
      85,    50,    51,    52,    53,    54,    55,    56,     0,    57,
      58,    59,     0,    60,    61,     0,    62,     0,    63,    64,
      65,    66,    67,    68,    69,    70,     0,     0,   111,    50,
      51,    52,    53,    54,    55,    56,     0,    57,    58,    59,
       0,    60,    61,     0,    62,     0,    63,    64,    65,    66,
      67,    68,    69,    70,     0,     0,   112,    50,    51,    52,
      53,    54,    55,    56,     0,    57,    58,    59,     0,    60,
      61,     0,    62,     0,    63,    64,    65,    66,    67,    68,
      69,    70,     0,     0,   113,    50,    51,    52,    53,    54,
      55,    56,     0,    57,    58,    59,     0,    60,    61,     0,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
       0,     0,   114,    50,    51,    52,    53,    54,    55,    56,
       0,    57,    58,    59,     0,    60,    61,     0,    62,     0,
      63,    64,    65,    66,    67,    68,    69,    70,     0,     0,
     115,    50,    51,    52,    53,    54,    55,    56,     0,    57,
      58,    59,     0,    60,    61,     0,    62,     0,    63,    64,
      65,    66,    67,    68,    69,    70,     0,     0,   161,    50,
      51,    52,    53,    54,    55,    56,     0,    57,    58,    59,
       0,    60,    61,     0,    62,   121,    63,    64,    65,    66,
      67,    68,    69,    70,    50,    51,    52,    53,    54,    55,
      56,     0,    57,    58,    59,     0,    60,    61,     0,    62,
       0,    63,    64,    65,    66,    67,    68,    69,    70,    50,
      51,    52,    53,    54,    55,    56,     0,    57,    58,    59,
       0,    60,    61,     0,     0,     0,    63,    64,    65,    66,
      67,    68,    69,    70,    50,    51,    52,    53,     0,     0,
       0,     0,    57,    58,    59,     0,    60,    61,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,    70
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-39))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      18,    19,    20,    21,    42,    10,    40,    41,    42,    43,
      44,    45,    17,    50,    47,    33,    34,    35,    47,    37,
      38,    50,    51,    42,    43,    44,    45,    48,    17,    50,
      51,    47,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     3,     4,     5,    47,     7,     8,
       9,    10,    47,    47,    13,    14,    15,    16,    17,    18,
      19,    20,    47,    29,    30,    31,    47,    33,    34,    28,
      17,   119,     0,    32,    40,    41,    42,    43,    44,    45,
      18,    19,    41,    47,    17,    48,    17,    17,    47,    48,
      33,    34,    17,   121,    50,   123,    17,    40,    41,    42,
      43,    44,    45,    52,    45,    17,    50,   135,    48,    48,
      52,    17,   140,    50,    17,    -1,   144,    -1,    -1,   147,
      -1,    48,   150,    -1,    -1,   153,    -1,    -1,   156,    -1,
      -1,   159,     3,     4,     5,    -1,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      41,     7,     8,     9,    10,    -1,    47,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,
      -1,    47,    21,    22,    23,    24,    25,    26,    27,    -1,
      29,    30,    31,    -1,    33,    34,    -1,    36,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    -1,    -1,    48,
      49,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      30,    31,    -1,    33,    34,    -1,    36,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,    -1,    48,    49,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    30,
      31,    -1,    33,    34,    -1,    36,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    -1,    -1,    48,    49,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    30,    31,
      -1,    33,    34,    -1,    36,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    48,    49,    21,    22,
      23,    24,    25,    26,    27,    -1,    29,    30,    31,    -1,
      33,    34,    -1,    36,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    -1,    -1,    48,    49,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    30,    31,    -1,    33,
      34,    -1,    36,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    48,    49,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,    30,    31,    -1,    33,    34,
      -1,    36,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,    48,    49,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    30,    31,    -1,    33,    34,    -1,
      36,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    48,    49,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    30,    31,    -1,    33,    34,    -1,    36,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      -1,    48,    49,    21,    22,    23,    24,    25,    26,    27,
      -1,    29,    30,    31,    -1,    33,    34,    -1,    36,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    -1,    -1,
      48,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      30,    31,    -1,    33,    34,    -1,    36,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,    -1,    48,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    30,    31,
      -1,    33,    34,    -1,    36,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    48,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    30,    31,    -1,    33,
      34,    -1,    36,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    48,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    30,    31,    -1,    33,    34,    -1,
      36,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    48,    21,    22,    23,    24,    25,    26,    27,
      -1,    29,    30,    31,    -1,    33,    34,    -1,    36,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    -1,    -1,
      48,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      30,    31,    -1,    33,    34,    -1,    36,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,    -1,    48,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    30,    31,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    30,    31,    -1,    33,    34,    -1,    36,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    30,    31,
      -1,    33,    34,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    29,    30,    31,    -1,    33,    34,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    28,    32,
      41,    47,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    47,    47,    47,    50,    47,    47,    47,
      47,    50,    51,    17,    17,    55,    55,    55,    55,     0,
      21,    22,    23,    24,    25,    26,    27,    29,    30,    31,
      33,    34,    36,    38,    39,    40,    41,    42,    43,    44,
      45,    47,    18,    19,    55,    55,    55,    17,    55,    55,
      10,    17,    48,    17,    54,    48,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    48,    55,    17,
      17,    48,    48,    48,    48,    48,    50,    48,    50,    51,
      52,    37,    48,    49,    17,    17,    54,    50,    55,    55,
      48,    48,    52,    17,    48,    49,    50,    55,    17,    48,
      49,    48,    55,    48,    49,    55,    48,    49,    55,    48,
      49,    55,    48,    49,    55,    48,    49,    55,    48,    49,
      55,    48
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
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
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
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
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
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
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:

/* Line 1806 of yacc.c  */
#line 137 "expr.y"
    { yyerror("\"ask\" is not supported here"); }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 139 "expr.y"
    { yyerror("\"default\" is not supported here"); }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 141 "expr.y"
    { yyerror("\"default()\" is not supported here"); }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 148 "expr.y"
    { yyerror("const() is not supported here"); }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 151 "expr.y"
    { *e++ = cDynamicExpression::ADD; }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 153 "expr.y"
    { *e++ = cDynamicExpression::SUB; }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 155 "expr.y"
    { *e++ = cDynamicExpression::MUL; }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 157 "expr.y"
    { *e++ = cDynamicExpression::DIV; }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 159 "expr.y"
    { *e++ = cDynamicExpression::MOD; }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 161 "expr.y"
    { *e++ = cDynamicExpression::POW; }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 165 "expr.y"
    { *e++ = cDynamicExpression::NEG; }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 168 "expr.y"
    { *e++ = cDynamicExpression::EQ; }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 170 "expr.y"
    { *e++ = cDynamicExpression::NE; }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 172 "expr.y"
    { *e++ = cDynamicExpression::GT; }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 174 "expr.y"
    { *e++ = cDynamicExpression::GE; }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 176 "expr.y"
    { *e++ = cDynamicExpression::LT; }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 178 "expr.y"
    { *e++ = cDynamicExpression::LE; }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 181 "expr.y"
    { *e++ = cDynamicExpression::AND; }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 183 "expr.y"
    { *e++ = cDynamicExpression::OR; }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 185 "expr.y"
    { *e++ = cDynamicExpression::XOR; }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 189 "expr.y"
    { *e++ = cDynamicExpression::NOT; }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 192 "expr.y"
    { *e++ = cDynamicExpression::BIN_AND; }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 194 "expr.y"
    { *e++ = cDynamicExpression::BIN_OR; }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 196 "expr.y"
    { *e++ = cDynamicExpression::BIN_XOR; }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 200 "expr.y"
    { *e++ = cDynamicExpression::BIN_NOT; }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 202 "expr.y"
    { *e++ = cDynamicExpression::LSHIFT; }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 204 "expr.y"
    { *e++ = cDynamicExpression::RSHIFT; }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 206 "expr.y"
    { *e++ = cDynamicExpression::IIF; }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 209 "expr.y"
    { addFunction("int",1); }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 211 "expr.y"
    { addFunction("double",1); }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 213 "expr.y"
    { addFunction("string",1); }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 216 "expr.y"
    { addFunction((yyvsp[(1) - (3)]),0); delete [] (yyvsp[(1) - (3)]); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 218 "expr.y"
    { addFunction((yyvsp[(1) - (4)]),1); delete [] (yyvsp[(1) - (4)]); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 220 "expr.y"
    { addFunction((yyvsp[(1) - (6)]),2); delete [] (yyvsp[(1) - (6)]); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 222 "expr.y"
    { addFunction((yyvsp[(1) - (8)]),3); delete [] (yyvsp[(1) - (8)]); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 224 "expr.y"
    { addFunction((yyvsp[(1) - (10)]),4); delete [] (yyvsp[(1) - (10)]); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 226 "expr.y"
    { addFunction((yyvsp[(1) - (12)]),5); delete [] (yyvsp[(1) - (12)]); }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 228 "expr.y"
    { addFunction((yyvsp[(1) - (14)]),6); delete [] (yyvsp[(1) - (14)]); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 230 "expr.y"
    { addFunction((yyvsp[(1) - (16)]),7); delete [] (yyvsp[(1) - (16)]); }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 232 "expr.y"
    { addFunction((yyvsp[(1) - (18)]),8); delete [] (yyvsp[(1) - (18)]); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 234 "expr.y"
    { addFunction((yyvsp[(1) - (20)]),9); delete [] (yyvsp[(1) - (20)]); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 236 "expr.y"
    { addFunction((yyvsp[(1) - (22)]),10); delete [] (yyvsp[(1) - (22)]); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 248 "expr.y"
    { (yyval) = opp_strdup("xmldoc"); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 250 "expr.y"
    { (yyval) = opp_strdup("xml"); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 255 "expr.y"
    { *e++ = new NEDSupport::ParameterRef((yyvsp[(1) - (1)]), true, false); delete [] (yyvsp[(1) - (1)]); }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 257 "expr.y"
    { *e++ = new NEDSupport::ParameterRef((yyvsp[(3) - (3)]), false, true); delete [] (yyvsp[(3) - (3)]); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 259 "expr.y"
    { *e++ = new NEDSupport::SiblingModuleParameterRef((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), true, false); delete [] (yyvsp[(1) - (3)]); delete [] (yyvsp[(3) - (3)]); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 261 "expr.y"
    { *e++ = new NEDSupport::SiblingModuleParameterRef((yyvsp[(1) - (6)]), (yyvsp[(6) - (6)]), true, true); delete [] (yyvsp[(1) - (6)]); delete [] (yyvsp[(6) - (6)]); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 266 "expr.y"
    { *e++ = new NEDSupport::ModuleIndex(); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 268 "expr.y"
    { *e++ = new NEDSupport::ModuleIndex(); }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 270 "expr.y"
    { *e++ = new NEDSupport::Sizeof((yyvsp[(3) - (4)]), true, false); delete [] (yyvsp[(3) - (4)]); }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 272 "expr.y"
    { *e++ = new NEDSupport::Sizeof((yyvsp[(5) - (6)]), false, false); delete [] (yyvsp[(5) - (6)]); }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 274 "expr.y"
    { delete [] (yyvsp[(3) - (6)]); delete [] (yyvsp[(5) - (6)]); yyerror("sizeof(submodule.gate) notation not supported here"); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 276 "expr.y"
    { delete [] (yyvsp[(3) - (9)]); delete [] (yyvsp[(8) - (9)]); yyerror("sizeof(submodule[index].gate) notation not supported here"); }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 287 "expr.y"
    { *e++ = opp_parsequotedstr((yyvsp[(1) - (1)])).c_str(); delete [] (yyvsp[(1) - (1)]); }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 292 "expr.y"
    { *e++ = true; }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 294 "expr.y"
    { *e++ = false; }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 299 "expr.y"
    { *e++ = opp_atol((yyvsp[(1) - (1)])); delete [] (yyvsp[(1) - (1)]); }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 301 "expr.y"
    { *e++ = opp_atof((yyvsp[(1) - (1)])); delete [] (yyvsp[(1) - (1)]); }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 303 "expr.y"
    {
                  std::string unit;
                  *e++ = parseQuantity((yyvsp[(1) - (1)]), unit);
                  if (!unit.empty())
                      (e-1)->setUnit(unit.c_str());
                  delete [] (yyvsp[(1) - (1)]);
                }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 314 "expr.y"
    { (yyval) = expryyconcat((yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)])); }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 316 "expr.y"
    { (yyval) = expryyconcat((yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)])); }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 318 "expr.y"
    { (yyval) = expryyconcat((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)])); }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 320 "expr.y"
    { (yyval) = expryyconcat((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)])); }
    break;



/* Line 1806 of yacc.c  */
#line 2232 "expr.tab.cc"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 323 "expr.y"


//----------------------------------------------------------------------

void doParseExpression(const char *nedtext, cDynamicExpression::Elem *&elems, int& nelems)
{
    NONREENTRANT_PARSER();

    elems = NULL;
    nelems = 0;

    // reset the lexer
    xpos.co = 0;
    xpos.li = 1;
    xprevpos = xpos;

    yyin = NULL;
    yyout = stderr; // not used anyway

    // alloc buffer
    struct yy_buffer_state *handle = yy_scan_string(nedtext);
    if (!handle)
        throw std::runtime_error("parser is unable to allocate work memory");

    cDynamicExpression::Elem *v = new cDynamicExpression::Elem[100]; // overestimate for now; XXX danger of overrun
    e = v;

    // parse
    try
    {
        yyparse();
    }
    catch (std::exception& e)
    {
        yy_delete_buffer(handle);
        delete [] v;
        throw;
    }
    yy_delete_buffer(handle);

    // copy v[] and return
    nelems = e - v;
    elems = new cDynamicExpression::Elem[nelems];
    for (int i=0; i<nelems; i++)
        elems[i] = v[i];
    delete [] v;
}

void yyerror(const char *s)
{
    // chop newline
    char buf[250];
    strcpy(buf, s);
    if (buf[strlen(buf)-1] == '\n')
        buf[strlen(buf)-1] = '\0';

    throw std::runtime_error(buf);
}


