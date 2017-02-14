/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 25 "tp.y" /* yacc.c:339  */

#include "tp.h"
#include "tp_y.h"

VarDeclP lvar;
ClassP lclass;

extern int yylex();
extern void yyerror(char *);

#line 77 "tp_y.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "tp_y.h".  */
#ifndef YY_YY_TP_Y_H_INCLUDED
# define YY_YY_TP_Y_H_INCLUDED
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
    IS = 258,
    VAR = 259,
    CLASS = 260,
    AFF = 261,
    DEF = 262,
    ADD = 263,
    SUB = 264,
    MUL = 265,
    DV = 266,
    UNARY = 267,
    AS = 268,
    IF = 269,
    THEN = 270,
    ELSE = 271,
    NEWW = 272,
    DOT = 273,
    EXTENDS = 274,
    OVERRIDE = 275,
    AND = 276,
    Id = 277,
    STRING = 278,
    TYPE = 279,
    RETURN = 280,
    Cste = 281,
    RelOp = 282
  };
#endif

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TP_Y_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 151 "tp_y.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   225

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  137

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   282

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      30,    31,     2,     2,    34,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    33,    32,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    28,     2,    29,     2,     2,     2,     2,
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
      25,    26,    27
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    37,    37,    39,    40,    43,    46,    49,    50,    53,
      54,    57,    60,    61,    64,    65,    66,    67,    68,    71,
      74,    75,    78,    81,    82,    85,    86,    89,    90,    93,
      96,    99,   100,   103,   106,   107,   110,   111,   113,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   131,   134,   137,   138,   141,   142,   145,   148,
     151,   152,   153,   154,   157,   160,   163,   164,   167,   168,
     171
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IS", "VAR", "CLASS", "AFF", "DEF",
  "ADD", "SUB", "MUL", "DV", "UNARY", "AS", "IF", "THEN", "ELSE", "NEWW",
  "DOT", "EXTENDS", "OVERRIDE", "AND", "Id", "STRING", "TYPE", "RETURN",
  "Cste", "RelOp", "'{'", "'}'", "'('", "')'", "';'", "':'", "','",
  "$accept", "Prog", "classLOpt", "classDecl", "classHeader", "extOpt",
  "block", "instList", "instListOpt", "inst", "declList", "declListOpt",
  "decl", "methListOpt", "meth", "overOpt", "isNotBlock", "isBlock",
  "typeOpt", "methHeader", "initInstOpt", "initBlockOpt", "affInst",
  "expression", "message", "instanc", "paramListOpt", "paramList", "cast",
  "select", "opexpr", "bexpr", "construct", "argListOpt", "argList", "arg", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   123,   125,
      40,    41,    59,    58,    44
};
# endif

#define YYPACT_NINF -73

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-73)))

#define YYTABLE_NINF -28

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-28)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,   -10,    17,    -9,     3,    15,    -7,     8,   -73,     7,
     -73,   -73,    -6,     4,    12,    -9,     6,   147,   147,   147,
      14,   -73,   -73,    -1,   -73,    46,   -73,   -73,    10,   137,
      37,    39,   -73,    56,   -73,   -73,   -73,   -73,   -73,   -73,
      39,    11,    19,   -73,    22,    23,   -73,   -73,    24,    -8,
      -8,   170,    30,   -73,    49,   112,   -73,   -73,   137,   -73,
      39,   147,   147,   147,   147,   147,    53,   147,   147,   -73,
       0,    55,   -73,     4,   147,    58,   137,   147,    47,   -73,
      66,   -73,    97,    60,    60,    -8,    -8,    54,    67,   184,
     -73,    68,     0,    34,   -73,   -73,    82,    70,   -73,    81,
      83,    71,   147,   -73,   -73,   147,   -73,   -73,    76,    77,
     147,   -73,   147,    72,   137,   -73,   126,    80,    84,    88,
     -73,   -73,   110,   -73,   198,   -73,   -73,   -73,   -73,     4,
     113,    -9,    94,   147,   -73,   -73,   198
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     0,     3,     0,     0,     7,     1,    12,
       2,     4,     0,    66,     0,    36,     0,     0,     0,     0,
       0,    39,    41,     0,    40,     0,    15,    13,     0,    12,
       0,    20,    17,     0,    51,    50,    49,    48,    42,    45,
      20,     0,     0,    67,    68,     0,    37,     6,     0,    46,
      47,     0,     0,    16,     0,     0,     9,    11,     0,    19,
      20,     0,     0,     0,     0,     0,     0,     0,     0,    14,
      23,     0,    65,     0,    54,     0,     0,    54,     0,    44,
       0,    21,     0,    60,    61,    62,    63,    59,    43,    64,
      28,     0,    23,     0,    70,    69,    56,     0,    55,    34,
       0,     0,     0,    10,    38,    54,     5,    24,     0,    31,
       0,     8,     0,     0,     0,    53,     0,     0,     0,     0,
      26,    25,     0,    57,    35,    22,    18,    58,    52,    66,
      32,     0,     0,     0,    30,    33,    29
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -73,   -73,   122,   -73,   -73,   -73,    -3,    69,   102,   -72,
     -73,   -35,   123,    48,   -73,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,   -16,   -73,   -73,   -71,    28,   -73,   -73,
     -73,   -73,   -73,    13,    75,   -73
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,     5,    15,    26,    27,    28,    29,
      30,    59,    60,    91,    92,    93,   120,   121,   122,   109,
     113,    47,    32,    33,    34,    35,    97,    98,    36,    37,
      38,    39,     7,    42,    43,    44
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      10,    49,    50,    51,   100,    70,   101,   -27,     1,    55,
      66,    16,    46,    67,     6,    17,    18,     8,    12,     9,
      90,    19,    40,    13,    20,    81,    41,    14,    48,    21,
      22,    53,    23,    24,   117,     9,    45,    25,    52,    56,
      58,   108,   126,    16,    71,    82,    83,    84,    85,    86,
      72,    88,    89,    74,    17,    18,    73,    75,    96,    54,
      77,    96,    61,    20,    62,    63,    64,    65,    21,    22,
      64,    65,    24,    78,    66,    87,    25,    67,    66,    94,
     102,    67,    99,    68,   105,    66,   116,   112,    69,    96,
      62,    63,    64,    65,    96,   103,   124,   106,   118,   114,
      66,   111,   115,    67,   125,    62,    63,    64,    65,    68,
     119,   128,   130,   131,   129,    66,   110,   136,    67,   133,
      62,    63,    64,    65,    68,   135,    11,    80,   134,   104,
      66,    57,    31,    67,    62,    63,    64,    65,   123,    68,
     107,     0,   132,    79,    66,    17,    18,    67,    95,     0,
       0,    19,     0,    68,    20,    17,    18,   127,     0,    21,
      22,     0,    23,    24,    20,     9,     0,    25,     0,    21,
      22,     0,     0,    24,     0,     0,     0,    25,    62,    63,
      64,    65,     0,     0,     0,    76,     0,     0,    66,     0,
       0,    67,    62,    63,    64,    65,     0,    68,     0,     0,
       0,     0,    66,     0,     0,    67,    62,    63,    64,    65,
       0,   -28,     0,     0,     0,     0,    66,     0,     0,    67,
       0,     0,     0,     0,     0,    68
};

static const yytype_int16 yycheck[] =
{
       3,    17,    18,    19,    76,    40,    77,     7,     5,    25,
      18,     4,    15,    21,    24,     8,     9,     0,     3,    28,
      20,    14,    28,    30,    17,    60,    22,    19,    22,    22,
      23,    32,    25,    26,   105,    28,    24,    30,    24,    29,
       3,     7,   114,     4,    33,    61,    62,    63,    64,    65,
      31,    67,    68,    30,     8,     9,    34,    33,    74,    13,
      30,    77,     6,    17,     8,     9,    10,    11,    22,    23,
      10,    11,    26,    24,    18,    22,    30,    21,    18,    24,
      33,    21,    24,    27,    30,    18,   102,     6,    32,   105,
       8,     9,    10,    11,   110,    29,   112,    29,    22,    16,
      18,    31,    31,    21,    32,     8,     9,    10,    11,    27,
      33,    31,    24,     3,    30,    18,    34,   133,    21,     6,
       8,     9,    10,    11,    27,    31,     4,    58,   131,    32,
      18,    29,     9,    21,     8,     9,    10,    11,   110,    27,
      92,    -1,   129,    31,    18,     8,     9,    21,    73,    -1,
      -1,    14,    -1,    27,    17,     8,     9,    31,    -1,    22,
      23,    -1,    25,    26,    17,    28,    -1,    30,    -1,    22,
      23,    -1,    -1,    26,    -1,    -1,    -1,    30,     8,     9,
      10,    11,    -1,    -1,    -1,    15,    -1,    -1,    18,    -1,
      -1,    21,     8,     9,    10,    11,    -1,    27,    -1,    -1,
      -1,    -1,    18,    -1,    -1,    21,     8,     9,    10,    11,
      -1,    27,    -1,    -1,    -1,    -1,    18,    -1,    -1,    21,
      -1,    -1,    -1,    -1,    -1,    27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    36,    37,    38,    39,    24,    67,     0,    28,
      41,    37,     3,    30,    19,    40,     4,     8,     9,    14,
      17,    22,    23,    25,    26,    30,    41,    42,    43,    44,
      45,    47,    57,    58,    59,    60,    63,    64,    65,    66,
      28,    22,    68,    69,    70,    24,    41,    56,    22,    58,
      58,    58,    24,    32,    13,    58,    29,    43,     3,    46,
      47,     6,     8,     9,    10,    11,    18,    21,    27,    32,
      46,    33,    31,    34,    30,    33,    15,    30,    24,    31,
      42,    46,    58,    58,    58,    58,    58,    22,    58,    58,
      20,    48,    49,    50,    24,    69,    58,    61,    62,    24,
      44,    61,    33,    29,    32,    30,    29,    48,     7,    54,
      34,    31,     6,    55,    16,    31,    58,    61,    22,    33,
      51,    52,    53,    62,    58,    32,    44,    31,    31,    30,
      24,     3,    68,     6,    41,    31,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    39,    40,    40,    41,
      41,    42,    43,    43,    44,    44,    44,    44,    44,    45,
      46,    46,    47,    48,    48,    49,    49,    50,    50,    51,
      52,    53,    53,    54,    55,    55,    56,    56,    57,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    59,    60,    61,    61,    62,    62,    63,    64,
      65,    65,    65,    65,    66,    67,    68,    68,    69,    69,
      70
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     6,     4,     0,     5,     3,
       5,     2,     0,     1,     2,     1,     2,     1,     6,     2,
       0,     2,     6,     0,     2,     3,     3,     0,     1,     4,
       3,     0,     2,     5,     0,     2,     0,     1,     4,     1,
       1,     1,     1,     3,     3,     1,     2,     2,     1,     1,
       1,     1,     6,     5,     0,     1,     1,     3,     6,     3,
       3,     3,     3,     3,     3,     4,     0,     1,     1,     3,
       3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
      yychar = yylex ();
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 37 "tp.y" /* yacc.c:1646  */
    {  makeProg((yyvsp[-1].pC), (yyvsp[0].pT));}
#line 1340 "tp_y.c" /* yacc.c:1646  */
    break;

  case 3:
#line 39 "tp.y" /* yacc.c:1646  */
    { (yyval.pC) = NIL(Class); }
#line 1346 "tp_y.c" /* yacc.c:1646  */
    break;

  case 4:
#line 40 "tp.y" /* yacc.c:1646  */
    { (yyvsp[-1].pC)->next=(yyvsp[0].pC); (yyval.pC)=(yyvsp[-1].pC); }
#line 1352 "tp_y.c" /* yacc.c:1646  */
    break;

  case 5:
#line 43 "tp.y" /* yacc.c:1646  */
    { (yyvsp[-5].pC)->var=(yyvsp[-2].pV); (yyvsp[-5].pC)->method=(yyvsp[-1].pM); (yyval.pC)=(yyvsp[-5].pC); }
#line 1358 "tp_y.c" /* yacc.c:1646  */
    break;

  case 6:
#line 46 "tp.y" /* yacc.c:1646  */
    { (yyval.pC) = makeClass((yyvsp[-2].pTe), (yyvsp[-1].S), (yyvsp[0].pT)); }
#line 1364 "tp_y.c" /* yacc.c:1646  */
    break;

  case 7:
#line 49 "tp.y" /* yacc.c:1646  */
    { (yyval.S) = NIL(char); }
#line 1370 "tp_y.c" /* yacc.c:1646  */
    break;

  case 8:
#line 50 "tp.y" /* yacc.c:1646  */
    { (yyval.S) = (yyvsp[-3].S); }
#line 1376 "tp_y.c" /* yacc.c:1646  */
    break;

  case 9:
#line 53 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeBlock(NIL(VarDecl) ,(yyvsp[-1].pT)); }
#line 1382 "tp_y.c" /* yacc.c:1646  */
    break;

  case 10:
#line 54 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeBlock((yyvsp[-3].pV), (yyvsp[-1].pT)); }
#line 1388 "tp_y.c" /* yacc.c:1646  */
    break;

  case 11:
#line 57 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeTree(INST, 2, (yyvsp[-1].pT), (yyvsp[0].pT) ); }
#line 1394 "tp_y.c" /* yacc.c:1646  */
    break;

  case 12:
#line 60 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = NIL(Tree); }
#line 1400 "tp_y.c" /* yacc.c:1646  */
    break;

  case 16:
#line 66 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeLeafStr(RETURN, (yyvsp[-1].S)); }
#line 1406 "tp_y.c" /* yacc.c:1646  */
    break;

  case 18:
#line 68 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeTree(ITE, 3, (yyvsp[-4].pT), (yyvsp[-2].pT), (yyvsp[0].pT)); }
#line 1412 "tp_y.c" /* yacc.c:1646  */
    break;

  case 19:
#line 71 "tp.y" /* yacc.c:1646  */
    { (yyvsp[-1].pV)->next=(yyvsp[0].pV); (yyval.pV)=(yyvsp[-1].pV); }
#line 1418 "tp_y.c" /* yacc.c:1646  */
    break;

  case 20:
#line 74 "tp.y" /* yacc.c:1646  */
    { (yyval.pV) = NIL(VarDecl); }
#line 1424 "tp_y.c" /* yacc.c:1646  */
    break;

  case 21:
#line 75 "tp.y" /* yacc.c:1646  */
    {  (yyvsp[-1].pV)->next=(yyvsp[0].pV); (yyval.pV)=(yyvsp[-1].pV); }
#line 1430 "tp_y.c" /* yacc.c:1646  */
    break;

  case 22:
#line 78 "tp.y" /* yacc.c:1646  */
    { (yyval.pV) = makeVarDecl((yyvsp[-4].S) , (yyvsp[-2].S), (yyvsp[-1].pT)); }
#line 1436 "tp_y.c" /* yacc.c:1646  */
    break;

  case 23:
#line 81 "tp.y" /* yacc.c:1646  */
    { (yyval.pM) = NIL(Method); }
#line 1442 "tp_y.c" /* yacc.c:1646  */
    break;

  case 24:
#line 82 "tp.y" /* yacc.c:1646  */
    { (yyvsp[-1].pM)->next=(yyvsp[0].pM); (yyval.pM)=(yyvsp[-1].pM);}
#line 1448 "tp_y.c" /* yacc.c:1646  */
    break;

  case 25:
#line 85 "tp.y" /* yacc.c:1646  */
    { (yyval.pM)=fillMeth((yyvsp[-1].pM), (yyvsp[0].pT), (yyvsp[-2].B));}
#line 1454 "tp_y.c" /* yacc.c:1646  */
    break;

  case 26:
#line 86 "tp.y" /* yacc.c:1646  */
    { (yyval.pM)=fillMeth((yyvsp[-1].pM), (yyvsp[0].pT), (yyvsp[-2].B));}
#line 1460 "tp_y.c" /* yacc.c:1646  */
    break;

  case 27:
#line 89 "tp.y" /* yacc.c:1646  */
    { (yyval.B) = FALSE; }
#line 1466 "tp_y.c" /* yacc.c:1646  */
    break;

  case 28:
#line 90 "tp.y" /* yacc.c:1646  */
    {  (yyval.B) = TRUE; }
#line 1472 "tp_y.c" /* yacc.c:1646  */
    break;

  case 29:
#line 93 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeTree(AFF , 2, makeLeafStr(TYPE, (yyvsp[-2].S)), (yyvsp[0].pT));}
#line 1478 "tp_y.c" /* yacc.c:1646  */
    break;

  case 30:
#line 96 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeTree(IS, 2, (yyvsp[-2].pT), (yyvsp[0].pT)); }
#line 1484 "tp_y.c" /* yacc.c:1646  */
    break;

  case 31:
#line 99 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeLeafStr(TYPE, NIL(char)); }
#line 1490 "tp_y.c" /* yacc.c:1646  */
    break;

  case 32:
#line 100 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeLeafStr(TYPE, (yyvsp[0].S)); }
#line 1496 "tp_y.c" /* yacc.c:1646  */
    break;

  case 33:
#line 103 "tp.y" /* yacc.c:1646  */
    { (yyval.pM) = makeMeth((yyvsp[-3].S), (yyvsp[-1].pV)); }
#line 1502 "tp_y.c" /* yacc.c:1646  */
    break;

  case 34:
#line 106 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = NIL(Tree); }
#line 1508 "tp_y.c" /* yacc.c:1646  */
    break;

  case 35:
#line 107 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeTree(AFFEC,1,(yyvsp[0].pT)); }
#line 1514 "tp_y.c" /* yacc.c:1646  */
    break;

  case 36:
#line 110 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = NIL(Tree); }
#line 1520 "tp_y.c" /* yacc.c:1646  */
    break;

  case 38:
#line 113 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeTree(AFF, 2, (yyvsp[-3].pT), (yyvsp[-1].pT)); }
#line 1526 "tp_y.c" /* yacc.c:1646  */
    break;

  case 39:
#line 116 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeLeafStr(IDVAR, (yyvsp[0].S)); }
#line 1532 "tp_y.c" /* yacc.c:1646  */
    break;

  case 40:
#line 117 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeLeafInt(CONST, (yyvsp[0].I)); }
#line 1538 "tp_y.c" /* yacc.c:1646  */
    break;

  case 41:
#line 118 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeLeafStr(STRING, (yyvsp[0].S)); }
#line 1544 "tp_y.c" /* yacc.c:1646  */
    break;

  case 43:
#line 120 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeTree(AND, 2, (yyvsp[-2].pT), (yyvsp[0].pT)); }
#line 1550 "tp_y.c" /* yacc.c:1646  */
    break;

  case 44:
#line 121 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = (yyvsp[-1].pT);}
#line 1556 "tp_y.c" /* yacc.c:1646  */
    break;

  case 46:
#line 123 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = (yyvsp[0].pT); }
#line 1562 "tp_y.c" /* yacc.c:1646  */
    break;

  case 47:
#line 124 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) =  makeTree(EMINUS, 2, makeLeafInt(CONST,0), (yyvsp[0].pT)); }
#line 1568 "tp_y.c" /* yacc.c:1646  */
    break;

  case 52:
#line 131 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeTree(DOT,3, (yyvsp[-5].pT), makeLeafStr(IDVAR, (yyvsp[-3].S)), (yyvsp[-1].pT)); }
#line 1574 "tp_y.c" /* yacc.c:1646  */
    break;

  case 53:
#line 134 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeTree(NEWW, 2, makeLeafStr(TYPE, (yyvsp[-3].S)), (yyvsp[-1].pT)) ;}
#line 1580 "tp_y.c" /* yacc.c:1646  */
    break;

  case 54:
#line 137 "tp.y" /* yacc.c:1646  */
    { (yyval.pT)=NIL(Tree);}
#line 1586 "tp_y.c" /* yacc.c:1646  */
    break;

  case 57:
#line 142 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeTree(CONCA, 2, (yyvsp[-2].pT), (yyvsp[0].pT)); }
#line 1592 "tp_y.c" /* yacc.c:1646  */
    break;

  case 58:
#line 145 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeTree(AS, 2, makeLeafStr(TYPE, (yyvsp[-3].S)), (yyvsp[-1].pT)); }
#line 1598 "tp_y.c" /* yacc.c:1646  */
    break;

  case 59:
#line 148 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeTree(DOT, 2, (yyvsp[-2].pT), makeLeafStr(IDVAR, (yyvsp[0].S)));}
#line 1604 "tp_y.c" /* yacc.c:1646  */
    break;

  case 60:
#line 151 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeTree(EADD, 2, (yyvsp[-2].pT), (yyvsp[0].pT)); }
#line 1610 "tp_y.c" /* yacc.c:1646  */
    break;

  case 61:
#line 152 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeTree(EMINUS, 2, (yyvsp[-2].pT), (yyvsp[0].pT)); }
#line 1616 "tp_y.c" /* yacc.c:1646  */
    break;

  case 62:
#line 153 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeTree(EMULT, 2, (yyvsp[-2].pT), (yyvsp[0].pT)); }
#line 1622 "tp_y.c" /* yacc.c:1646  */
    break;

  case 63:
#line 154 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeTree(EDIV, 2, (yyvsp[-2].pT), (yyvsp[0].pT)); }
#line 1628 "tp_y.c" /* yacc.c:1646  */
    break;

  case 64:
#line 157 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeTree((yyvsp[-1].C), 2, (yyvsp[-2].pT), (yyvsp[0].pT)); }
#line 1634 "tp_y.c" /* yacc.c:1646  */
    break;

  case 65:
#line 160 "tp.y" /* yacc.c:1646  */
    { (yyval.pTe) = makeTete((yyvsp[-3].S), (yyvsp[-1].pV)); }
#line 1640 "tp_y.c" /* yacc.c:1646  */
    break;

  case 66:
#line 163 "tp.y" /* yacc.c:1646  */
    { (yyval.pV) = NIL(VarDecl); }
#line 1646 "tp_y.c" /* yacc.c:1646  */
    break;

  case 69:
#line 168 "tp.y" /* yacc.c:1646  */
    { (yyvsp[-2].pV)->next=(yyvsp[0].pV); (yyval.pV)=(yyvsp[-2].pV);}
#line 1652 "tp_y.c" /* yacc.c:1646  */
    break;

  case 70:
#line 171 "tp.y" /* yacc.c:1646  */
    { (yyval.pV) = makeVarDecl((yyvsp[-2].S), (yyvsp[0].S), NIL(Tree)); }
#line 1658 "tp_y.c" /* yacc.c:1646  */
    break;


#line 1662 "tp_y.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
