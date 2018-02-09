/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "s8Compiler.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <malloc.h>
	#include "lex.yy.c"
	#include "tree.h" 
	#include "symt.h"
	#include "cgen.h"

	int type_keeper = -1; // 0 for integer and 1 for boolean
	int declaration; // to differentiate between the actions at the time of function declaration and at the time of definition

#line 80 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
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

/* Copy the second part of user declarations.  */

#line 199 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   388

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  171

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    40,    46,     2,
      44,    45,    38,    36,    41,    37,     2,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    35,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,    48,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    27,    27,    39,    59,    60,    62,    65,    66,    68,
      69,    72,    78,    83,    83,   103,   104,   106,   107,   109,
     112,   113,   115,   124,   134,   135,   137,   157,   187,   137,
     301,   303,   304,   307,   309,   310,   313,   313,   407,   408,
     409,   410,   413,   461,   507,   536,   572,   580,   588,   596,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   642,   692,   693,
     694,   724,   725,   727,   728
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TRUE", "FALSE", "AND", "OR", "NOT",
  "DECL", "ENDDECL", "MAIN", "READ", "WRITE", "ASSIGN", "SEMICOLON",
  "WHILE", "DO", "ENDWHILE", "IF", "THEN", "ELSE", "LT", "EQ", "LE", "GE",
  "GT", "NE", "END", "ENDIF", "INT", "BEGINP", "BOOL", "NUMBER", "ID",
  "RETURN", "'='", "'+'", "'-'", "'*'", "'/'", "'%'", "','", "'['", "']'",
  "'('", "')'", "'&'", "'{'", "'}'", "$accept", "Prog", "GDefBlock",
  "DeclList", "Decl", "Type", "IDlist", "Gid", "$@1", "ArgList", "Args",
  "Arg", "paraNames", "paraName", "Fdeflist", "Fdef", "$@2", "$@3", "$@4",
  "LdefBlock", "LDeclList", "Ldecl", "lnames", "Mainblock", "$@5", "Body",
  "RetStmt", "slist", "stmt", "expr", "FormalParameters", "ExprList", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,    61,    43,    45,    42,    47,
      37,    44,    91,    93,    40,    41,    38,   123,   125
};
# endif

#define YYPACT_NINF -73

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-73)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       8,   -73,    20,   -73,    -4,   -73,    -8,   -73,   -73,   -73,
     -73,    12,    46,    24,   -73,   -73,   -18,   -12,   -73,     9,
      28,    30,   -73,   -73,    12,    52,   -73,    55,    48,   -73,
      26,    48,   -73,    18,    66,   -73,    99,   113,    77,   -73,
      90,   -73,    85,   -73,    48,    48,   -73,    80,   -73,    18,
     -73,    95,   120,    48,   105,   -73,   -73,   -73,   -11,   -73,
     -73,   349,   102,   113,   -73,   104,   103,   107,   108,   109,
      -9,   349,   -73,    15,    98,   -73,   -73,   115,    15,    15,
      15,    15,    15,   -73,   -73,   -73,    15,   -73,    68,    15,
     241,   -73,   105,   -30,    44,    69,    94,   268,   144,   -73,
      15,    15,   119,    15,    15,   111,    15,    15,    15,    15,
      15,    15,    15,    15,    15,    15,    15,   102,    15,   140,
     146,   145,   143,   -73,   150,   167,   213,   126,   -73,   -73,
     348,   317,   -73,   138,   220,   138,   138,   138,   220,    64,
      64,   -73,   -73,   -73,   131,   190,   -73,   -73,   349,   349,
      15,   -73,    15,   -73,   -73,   141,   312,    43,   295,   -73,
     171,   180,   349,   183,   -73,   -73,   -73,   347,   -73,   184,
     -73
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,    24,     0,     1,     0,     3,     7,     8,
       5,     0,     7,     0,    25,     2,    11,     0,     9,     0,
       0,     0,    13,     6,     0,     0,    26,     0,    15,    10,
       0,    15,    12,     0,     0,    16,    17,     0,     0,    22,
       0,    19,    20,    14,     0,    31,    36,     0,    23,     0,
      18,     0,     0,    31,     0,    27,    21,    34,     0,    30,
      32,     0,     0,     0,    33,     0,     0,     0,     0,     0,
       0,    38,    41,     0,     0,    28,    35,     0,     0,     0,
       0,     0,     0,    40,    68,    69,     0,    65,    66,     0,
       0,    37,     0,     0,     0,     0,     0,     0,     0,    63,
       0,    71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    42,     0,     0,    73,     0,    72,    64,
      61,    62,    39,    55,    59,    56,    57,    58,    60,    50,
      51,    54,    52,    53,     0,     0,    44,    46,     0,     0,
       0,    67,     0,    70,    29,     0,     0,     0,     0,    74,
       0,     0,     0,     0,    43,    45,    49,     0,    47,     0,
      48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -73,   -73,   -73,   -73,   -73,     7,   -73,   175,   -73,   169,
     157,   -73,   153,   -73,   -73,   -73,   -73,   -73,   -73,   154,
     155,   -73,   -73,   -73,   -73,   117,   106,   -61,   -71,   -72,
     -73,    70
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    10,    33,    17,    18,    28,    34,
      35,    36,    41,    42,     6,    14,    31,    63,    92,    46,
      52,    53,    58,    15,    54,    62,    74,    71,    72,   126,
     127,   128
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      83,    90,    23,    64,    81,     7,    94,    95,    96,    97,
      98,    11,   118,    13,    99,   119,     1,   102,    84,    85,
       5,    12,    86,     9,    21,     8,    22,     9,   125,    24,
      65,   130,   131,    82,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    16,   145,    87,    88,   103,
     104,    39,    51,    25,    66,    67,    19,    20,    68,    89,
      51,    69,    27,   162,    40,   106,   107,   108,   109,   110,
     111,   163,    26,    37,   103,   104,    70,     8,   158,     9,
     112,   113,   114,   115,   116,    83,    83,   156,   157,   120,
     106,   107,   108,   109,   110,   111,    83,    30,    32,   103,
     104,   167,   114,   115,   116,   112,   113,   114,   115,   116,
     100,    43,   101,    44,   121,   106,   107,   108,   109,   110,
     111,    45,    47,    48,   103,   104,    49,    55,    57,    59,
     112,   113,   114,   115,   116,    61,    73,    76,   132,   122,
     106,   107,   108,   109,   110,   111,    91,    77,    93,   103,
     104,    78,    79,    80,   146,   112,   113,   114,   115,   116,
     147,   148,   149,   150,   129,   106,   107,   108,   109,   110,
     111,   153,   103,   104,   112,   113,   114,   115,   116,   154,
     112,   113,   114,   115,   116,   165,   160,   124,   106,   107,
     108,   109,   110,   111,   166,   103,   104,   168,   170,    29,
      38,    50,    56,   112,   113,   114,   115,   116,    60,   117,
     151,   106,   107,   108,   109,   110,   111,    75,   103,   104,
       0,     0,   159,   144,     0,     0,   112,   113,   114,   115,
     116,     0,     0,   155,   106,   107,   108,   109,   110,   111,
       0,   106,     0,   108,   109,   110,   103,   104,     0,   112,
     113,   114,   115,   116,   152,   105,   112,   113,   114,   115,
     116,     0,   106,   107,   108,   109,   110,   111,     0,     0,
       0,     0,     0,   103,   104,     0,     0,   112,   113,   114,
     115,   116,   123,     0,     0,     0,     0,     0,     0,   106,
     107,   108,   109,   110,   111,     0,     0,     0,     0,     0,
     103,   104,     0,     0,   112,   113,   114,   115,   116,   164,
       0,     0,     0,     0,     0,     0,   106,   107,   108,   109,
     110,   111,   103,    66,    67,     0,     0,    68,     0,   161,
      69,   112,   113,   114,   115,   116,     0,     0,   106,   107,
     108,   109,   110,   111,     0,    70,     0,     0,     0,     0,
       0,     0,     0,   112,   113,   114,   115,   116,    66,    67,
      66,    67,    68,     0,    68,    69,     0,    69,     0,   106,
     107,   108,   109,   110,   111,   169,     0,     0,     0,     0,
      70,     0,    70,     0,   112,   113,   114,   115,   116
};

static const yytype_int16 yycheck[] =
{
      71,    73,    14,    14,    13,     9,    78,    79,    80,    81,
      82,     4,    42,     6,    86,    45,     8,    89,     3,     4,
       0,    29,     7,    31,    42,    29,    44,    31,   100,    41,
      41,   103,   104,    42,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,    33,   118,    32,    33,     5,
       6,    33,    45,    44,    11,    12,    10,    33,    15,    44,
      53,    18,    32,    20,    46,    21,    22,    23,    24,    25,
      26,    28,    44,    47,     5,     6,    33,    29,   150,    31,
      36,    37,    38,    39,    40,   156,   157,   148,   149,    45,
      21,    22,    23,    24,    25,    26,   167,    45,    43,     5,
       6,   162,    38,    39,    40,    36,    37,    38,    39,    40,
      42,    45,    44,    14,    45,    21,    22,    23,    24,    25,
      26,     8,    45,    33,     5,     6,    41,    47,    33,     9,
      36,    37,    38,    39,    40,    30,    34,    33,    27,    45,
      21,    22,    23,    24,    25,    26,    48,    44,    33,     5,
       6,    44,    44,    44,    14,    36,    37,    38,    39,    40,
      14,    16,    19,    13,    45,    21,    22,    23,    24,    25,
      26,    45,     5,     6,    36,    37,    38,    39,    40,    48,
      36,    37,    38,    39,    40,    14,    45,    43,    21,    22,
      23,    24,    25,    26,    14,     5,     6,    14,    14,    24,
      31,    44,    49,    36,    37,    38,    39,    40,    53,    92,
      43,    21,    22,    23,    24,    25,    26,    63,     5,     6,
      -1,    -1,   152,   117,    -1,    -1,    36,    37,    38,    39,
      40,    -1,    -1,    43,    21,    22,    23,    24,    25,    26,
      -1,    21,    -1,    23,    24,    25,     5,     6,    -1,    36,
      37,    38,    39,    40,    41,    14,    36,    37,    38,    39,
      40,    -1,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    -1,     5,     6,    -1,    -1,    36,    37,    38,
      39,    40,    14,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
       5,     6,    -1,    -1,    36,    37,    38,    39,    40,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,    24,
      25,    26,     5,    11,    12,    -1,    -1,    15,    -1,    17,
      18,    36,    37,    38,    39,    40,    -1,    -1,    21,    22,
      23,    24,    25,    26,    -1,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    39,    40,    11,    12,
      11,    12,    15,    -1,    15,    18,    -1,    18,    -1,    21,
      22,    23,    24,    25,    26,    28,    -1,    -1,    -1,    -1,
      33,    -1,    33,    -1,    36,    37,    38,    39,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    50,    51,    52,     0,    63,     9,    29,    31,
      53,    54,    29,    54,    64,    72,    33,    55,    56,    10,
      33,    42,    44,    14,    41,    44,    44,    32,    57,    56,
      45,    65,    43,    54,    58,    59,    60,    47,    58,    33,
      46,    61,    62,    45,    14,     8,    68,    45,    33,    41,
      59,    54,    69,    70,    73,    47,    61,    33,    71,     9,
      69,    30,    74,    66,    14,    41,    11,    12,    15,    18,
      33,    76,    77,    34,    75,    68,    33,    44,    44,    44,
      44,    13,    42,    77,     3,     4,     7,    32,    33,    44,
      78,    48,    67,    33,    78,    78,    78,    78,    78,    78,
      42,    44,    78,     5,     6,    14,    21,    22,    23,    24,
      25,    26,    36,    37,    38,    39,    40,    74,    42,    45,
      45,    45,    45,    14,    43,    78,    78,    79,    80,    45,
      78,    78,    27,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    75,    78,    14,    14,    16,    19,
      13,    43,    41,    45,    48,    43,    76,    76,    78,    80,
      45,    17,    20,    28,    14,    14,    14,    76,    14,    28,
      14
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    52,    52,    53,    54,    54,    55,
      55,    56,    56,    57,    56,    58,    58,    59,    59,    60,
      61,    61,    62,    62,    63,    63,    65,    66,    67,    64,
      68,    69,    69,    70,    71,    71,    73,    72,    74,    75,
      76,    76,    77,    77,    77,    77,    77,    77,    77,    77,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    79,    79,    80,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     0,     2,     3,     1,     1,     1,
       3,     1,     4,     0,     5,     0,     1,     1,     3,     2,
       1,     3,     1,     2,     0,     2,     0,     0,     0,    13,
       3,     0,     2,     3,     1,     3,     0,    10,     2,     4,
       2,     1,     4,     7,     5,     8,     5,     8,    10,     8,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     1,     1,     4,     1,     1,
       4,     0,     1,     1,     3
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
#line 27 "s8Compiler.y" /* yacc.c:1646  */
    { if(!error){
						printf("\n-----------------------------------------\n \t\tPROGRAM ENDS HERE \n");
						printf("-----------------------------------------\n");
						fclose(outfile);
						exit(0);
						}
				    else{
						printf("....Please Correct Your Code...\n");
						exit(0);
					}
				   }
#line 1443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 39 "s8Compiler.y" /* yacc.c:1646  */
    {printf("REACHING HERE 1\n"); 
							
					/* start
					mov SP , main_loc
					push
					call main
					call
					halt */
								
					fprintf(outfile,"START\n");
					// SP points to the last element ont the stack.
					//-1 bcz main_mem is the location
					//on which new variable would have been placed
					fprintf(outfile,"MOV SP, %d\n",main_mem-1);
					fprintf(outfile,"MOV BP, SP\n");
					fprintf(outfile,"PUSH R0\n"); // create space for return value
					fprintf(outfile,"CALL main\n");
					fprintf(outfile,"HALT\n");
					
			          }
#line 1468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 65 "s8Compiler.y" /* yacc.c:1646  */
    {type_keeper=VAR_TYPE_INT;}
#line 1474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 66 "s8Compiler.y" /* yacc.c:1646  */
    {type_keeper=VAR_TYPE_BOOL;}
#line 1480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 72 "s8Compiler.y" /* yacc.c:1646  */
    {
		Ginstall((yyvsp[0])->NAME,type_keeper,1);
		Gtable* entry = Glookup((yyvsp[0])->NAME);
		(yyvsp[0])->Gentry=entry;
		printf("REACHING HERE 2\n");
	}
#line 1491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 78 "s8Compiler.y" /* yacc.c:1646  */
    {
					Ginstall((yyvsp[-3])->NAME,type_keeper,(yyvsp[-1])->VALUE); //array defined here
					Gtable* entry = Glookup((yyvsp[-3])->NAME);
					(yyvsp[-3])->Gentry=entry;
				}
#line 1501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 83 "s8Compiler.y" /* yacc.c:1646  */
    { //functions ----  SEE THE USE OF EMBEDDED ACTIONS ON PAGE 39 of lex-yacc tutorial
	
				Ginstall((yyvsp[-1])->NAME,type_keeper,0); 
				Gtable* entry = Glookup((yyvsp[-1])->NAME);
				(yyvsp[-1])->Gentry=entry;
				(yyvsp[-1])->Gentry->defined_flag = 0; // not yet defined i.e.
				(yyvsp[-1])->Gentry->is_function=1;
				declaration = 1; //declaration started
				argHead = NULL;
						
		}
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 93 "s8Compiler.y" /* yacc.c:1646  */
    {
				(yyvsp[-4])->Gentry->ARGLIST = argHead;
				Gtable *temp = Glookup((yyvsp[-4])->NAME); 
				printLinkedList(temp->ARGLIST);				
				argHead = NULL; // done with the arglist by now
				declaration = 0; // declaration done
				printf("REACHING HERE 2\n");
				}
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 115 "s8Compiler.y" /* yacc.c:1646  */
    {// This is argument list

			if(declaration){ // if its the time of declaration, we need to create only the argument list
				addToArgList(&argHead,(yyvsp[0])->NAME,type_keeper,0);
			}
			else{
				addToArgList(&defArgHead,(yyvsp[0])->NAME,type_keeper,0);
			    }
		  }
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 124 "s8Compiler.y" /* yacc.c:1646  */
    {
			if(declaration){ // if its the time of declaration, we need to create only the argument list
				addToArgList(&argHead,(yyvsp[0])->NAME,type_keeper,1);
			}
			else{
				addToArgList(&defArgHead,(yyvsp[0])->NAME,type_keeper,1);	
	          	    }
		  }
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 137 "s8Compiler.y" /* yacc.c:1646  */
    { 
			if(checkexists((yyvsp[-1])->NAME)){
				Gtable* entry = Glookup((yyvsp[-1])->NAME);				
				if(entry->is_function){
					checkReturnType(type_keeper, (yyvsp[-1])->NAME);
					checkDefinedAlready((yyvsp[-1])->NAME);
				}else{
					error = 1;
					printf("%d ERROR : %s is not a function. \n",yylineno,(yyvsp[-1])->NAME);
				}
			}else {
				error = 1;
				printf("%d ERROR : Function %s was not declared. \n",yylineno,(yyvsp[-1])->NAME);
									
         		      }
			Gtable *temp = Glookup((yyvsp[-1])->NAME);
			temp->defined_flag=1;					  
			defArgHead=NULL;	  
			
		    }
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 157 "s8Compiler.y" /* yacc.c:1646  */
    {
		
				if(checkexists((yyvsp[-5])->NAME)){
					Gtable *temp = Glookup((yyvsp[-5])->NAME);
					ArgStruct *declArgList = temp->ARGLIST;
					printf("\n\n -------------------In function definition ------\n\n");					
					//printLinkedList(temp->ARGLIST);	
					//printf("\n\n In function definition \n\n");
					//printLinkedList(defArgHead);				
					if(getArgCount(defArgHead) != getArgCount(declArgList)){
					
						error = 1;
						printf("%d ERROR : Problem in argument list (nos of args doesn't match) \n",yylineno);
							
					
					}
					else{
						//printf("TYPE OF x is %d\n",defArgHead->TYPE);					
						checkArgListForMismatch(defArgHead, declArgList);
										
					}
				}
				
				defArgHead = NULL;
				localVarList = NULL;
				Lhead = NULL;
	
		
		
			}
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 187 "s8Compiler.y" /* yacc.c:1646  */
    { 
				printf("\n\nLOCALBLOCK IS reached\n\n");

				Gtable *temp = Glookup((yyvsp[-7])->NAME);
				ArgStruct *declArgList = temp->ARGLIST;
				int arguments = getArgCount(declArgList);
				
				if(arguments !=0){
					int n = arguments;
					int binding = -1*n;
					binding = binding - 2;
					int i=0;
					for(i=0;i<n;i++){
						Linstall(declArgList->NAME,declArgList->TYPE,binding);
						binding = binding + 1;
						declArgList = declArgList->NEXT;
					
					
					}
				
				}
				//printLinkedList(localVarList);
				int locals = getArgCount(localVarList);
				ArgStruct *localHeadOfFunction = localVarList;				
				if(locals != 0){
						int n = locals;
						int i=0;						
						for(i=1;i<=n;i++){
							Linstall(localHeadOfFunction->NAME,localHeadOfFunction->TYPE,i);
							localHeadOfFunction = localHeadOfFunction->NEXT;
						
						}
					
				}
				(yyvsp[-7])->Lentry = Lhead;
				LtableGlobal = Lhead;
				printLocalTable(Lhead);				
				
				
				printf("\nLOCAL DECL BLOCK IS OK\n");
		}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 227 "s8Compiler.y" /* yacc.c:1646  */
    {  
				
				printf("----------------BODY-----------\n");
				
				Gtable *retType = Glookup((yyvsp[-11])->NAME);
				
				if(retType->TYPE == VAR_TYPE_INT){
					//printf("\nReturned type cleared\n");	
					check_if_int((yyvsp[-1]));
					//printf("\nReturned type cleared\n");
				
				}else{
				
					check_if_bool((yyvsp[-1]));
				
				} 
				
				
			fprintf(outfile,"%s:\n",(yyvsp[-11])->NAME);
			fprintf(outfile,"PUSH BP\n");
			fprintf(outfile,"MOV BP, SP\n");
			int locals = getArgCount(localVarList);
			printf("\n\nNo. of local variables %d\n\n",locals);
			localVarList=NULL;
			if(locals !=0 ){
				int i=0;
				for(i=0;i<locals;i++){
					fprintf(outfile,"PUSH R0\n");//space for local variables
				
				}
			
			}

			printf("Just before codegen 1\n");				
			codegen((yyvsp[-2]));
			printf("Just before codegen 2\n");
			int res =codegen((yyvsp[-1]));
			int r0 = getreg();
			int r1 = getreg();
			fprintf(outfile,"MOV R%d, BP\n",r0);
			fprintf(outfile,"MOV R%d, 2\n",r1);
			fprintf(outfile,"SUB R%d, R%d\n",r0,r1);
			freereg(r1);
			fprintf(outfile,"MOV [R%d], R%d\n",r0,res);
			freereg(r0);
			freereg(res);
			
			if(locals !=0 ){
				int i=0;
				for(i=0;i<locals;i++){
					fprintf(outfile,"POP R0\n");//space for local variables
				
				}
			
			}
			fprintf(outfile,"MOV SP, BP\n");
			fprintf(outfile,"POP BP\n");
			fprintf(outfile,"RET\n");
			printf("\n\n HERE COUNT SHOULD BECOME -1 AGAIN. count = %d\n\n",count);
			localVarList=NULL;
			LtableGlobal = NULL;
			Lhead = NULL;
			printf("\n\n -------------------------------NO PROBLEM WITH FUNCTION DEFINITION----------------------------\n\n");							
			/*local install args 
			printf("REACHING HERE \n");
			label: push BP 
			localsvars
			codegen
			pop locals
			sp,bp
			pop bp
			ret*/
				}
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 309 "s8Compiler.y" /* yacc.c:1646  */
    {addToArgList(&localVarList,(yyvsp[0])->NAME,type_keeper,0);printf("REACHING HERE local localVarList %s\n",localVarList->NAME);}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 310 "s8Compiler.y" /* yacc.c:1646  */
    {addToArgList(&localVarList,(yyvsp[0])->NAME,type_keeper,0);}
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 313 "s8Compiler.y" /* yacc.c:1646  */
    {

				Ginstall("main",VAR_TYPE_INT,0); 
				Gtable* entry = Glookup((yyvsp[-4])->NAME);
				(yyvsp[-4])->Gentry=entry;
				(yyvsp[-4])->Gentry->defined_flag = 1; // main is not required to be declared
				(yyvsp[-4])->Gentry->ARGLIST = NULL;
				(yyvsp[-4])->Gentry->is_function=1;
				
				printf("\n\n-------------------MAIN FUNCTION ------------------\n\n");
				printLinkedList(localVarList);
				//-----------------------------------------------------------------
				int locals = getArgCount(localVarList);
				ArgStruct *localHeadOfFunction = localVarList;				
				if(locals != 0){
						int n = locals;
						int i=0;						
						for(i=1;i<=n;i++){
							Linstall(localHeadOfFunction->NAME,localHeadOfFunction->TYPE,i);
							localHeadOfFunction = localHeadOfFunction->NEXT;
						
						}
					
				}
				(yyvsp[-4])->Lentry = Lhead;
				LtableGlobal = Lhead;
				printLocalTable(Lhead);				
				
				
				printf("\nLOCAL DECL BLOCK IS OK\n");

				//------------------------------------------------------------------
				
						
		}
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 347 "s8Compiler.y" /* yacc.c:1646  */
    {
				printf("\n-----BODY OF MAIN-----\n");	
				
				printf("\n check return type of main\n");			
				check_if_int((yyvsp[-1]));
				printf("\n checked return type of main\n");
				 
				
				
			fprintf(outfile,"main:\n");
			
			fprintf(outfile,"PUSH BP\n");
			fprintf(outfile,"MOV BP, SP\n");
			int locals = getArgCount(localVarList);
			printf("main local counts %d\n",locals);	
			localVarList=NULL;
			if(locals !=0 ){
				int i=0;
				for(i=0;i<locals;i++){
					fprintf(outfile,"PUSH R0\n");//space for local variables
				
				}
			
			}
			printf("Just before codegen 1\n");
			codegen((yyvsp[-2]));
			printf("Just before codegen 2\n");
			int res =codegen((yyvsp[-1]));
			int r0 = getreg();
			int r1 = getreg();
			fprintf(outfile,"MOV R%d, BP\n",r0);
			fprintf(outfile,"MOV R%d, 2\n",r1);
			fprintf(outfile,"SUB R%d, R%d\n",r0,r1);
			freereg(r1);
			fprintf(outfile,"MOV [R%d], R%d\n",r0,res);
			freereg(r0);
			freereg(res);
			
			if(locals !=0 ){
				int i=0;
				for(i=0;i<locals;i++){
					fprintf(outfile,"POP R0\n");//space for local variables
				
				}
			
			}
			fprintf(outfile,"MOV SP, BP\n");
			fprintf(outfile,"POP BP\n");
			fprintf(outfile,"RET\n");
			
			
			printf("\n\n HERE COUNT SHOULD BECOME -1 AGAIN. count = %d\n\n",count);
			localVarList=NULL;
			LtableGlobal = NULL;
			Lhead = NULL;
			printf("\n\n NO pROBLEM WITH FUNCTION DEFINITION\n\n");							
			

	}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 407 "s8Compiler.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 408 "s8Compiler.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-2]);}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 409 "s8Compiler.y" /* yacc.c:1646  */
    {(yyval)=TreeCreate(TYPE_DUMMY, NODETYPE_DUMMY, 0 , NULL, (yyvsp[-1]), (yyvsp[0]), NULL,NULL,NULL);}
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 410 "s8Compiler.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 413 "s8Compiler.y" /* yacc.c:1646  */
    { 	Ltable *localTemp = Llookup(LtableGlobal, (yyvsp[-3])->NAME);
					
					if(localTemp==NULL){
					    	Gtable *temp = Glookup((yyvsp[-3])->NAME);
		 			        if(temp==NULL){
		 				  	error = 1;
		 				  	printf("%d ERROR : Identifier with name %s does not exists\n",yylineno,(yyvsp[-3])->NAME);
	 						  	
		 				}else{	(yyvsp[-3])->Gentry=temp;
		 					if(temp->TYPE == VAR_TYPE_INT){
		 				 		if(check_if_int((yyvsp[-1]))){
				  				  	(yyvsp[-2])->left=(yyvsp[-3]);
				  					(yyvsp[-2])->right=(yyvsp[-1]);
				  					(yyval)=(yyvsp[-2]);	
					  			}
				  			}
					  		else{
									  		
					  			if(check_if_bool((yyvsp[-1]))){
							  				
				  					(yyvsp[-2])->left=(yyvsp[-3]);
				  					(yyvsp[-2])->right=(yyvsp[-1]);
				  					(yyval)=(yyvsp[-2]);
					  			}
         			  			}
					  	     }
				       }else{   printf("%d :in assignment Found locally %s\n",yylineno,(yyvsp[-3])->NAME);	
						(yyvsp[-3])->Lentry=localTemp;
						if(localTemp->TYPE == VAR_TYPE_INT){
		 				 		if(check_if_int((yyvsp[-1]))){
				  				  	(yyvsp[-2])->left=(yyvsp[-3]);
				  					(yyvsp[-2])->right=(yyvsp[-1]);
				  					(yyval)=(yyvsp[-2]);	
					  			}
				  			}
					  		else{
									  		
					  			if(check_if_bool((yyvsp[-1]))){
							  				
				  					(yyvsp[-2])->left=(yyvsp[-3]);
				  					(yyvsp[-2])->right=(yyvsp[-1]);
				  					(yyval)=(yyvsp[-2]);
					  			}
         			  			}


					}
				}
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 461 "s8Compiler.y" /* yacc.c:1646  */
    { 

				Ltable *localTemp = Llookup(LtableGlobal, (yyvsp[-6])->NAME);

				if(localTemp==NULL){
				Gtable *temp = Glookup((yyvsp[-6])->NAME);
			  	if(temp==NULL){
			  		error = 1;
			  		printf("%d ERROR : Identifier with name %s does not exists \n",yylineno,(yyvsp[-6])->NAME);
 						  			
			  	}else{ (yyvsp[-6])->Gentry=temp;
			  		if(temp->TYPE == VAR_TYPE_INT) {
		  				if(check_if_int((yyvsp[-1]))){
	  						if(check_if_int((yyvsp[-4]))){
	 											(yyvsp[-2])->left=(yyvsp[-6]);
	 			  								(yyvsp[-2])->right=(yyvsp[-1]);
	 			  								(yyvsp[-2])->middle=(yyvsp[-4]);
	 			  								(yyval)=(yyvsp[-2]);
	 						}else{
								(yyvsp[-6])->Gentry=temp;(yyval)=(yyvsp[-2]);
							}
	  					}
  					}
	  				else{
	  					if(check_if_bool((yyvsp[-1]))){
	  						if(check_if_int((yyvsp[-4]))){
				  								(yyvsp[-2])->left=(yyvsp[-6]);
				  								(yyvsp[-2])->right=(yyvsp[-1]);
				  								(yyvsp[-2])->middle=(yyvsp[-4]);
				  								(yyval)=(yyvsp[-2]);
 								  						
	  						}else{
								(yyvsp[-6])->Gentry=temp;(yyval)=(yyvsp[-2]);
							}

	  					}
      					   }
	 			}

				}
				else{
					error = 1;
			  		printf("%d ERROR : Local variables cannot be arrays \n",yylineno);
					 								  			
	 		   }
			}
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 507 "s8Compiler.y" /* yacc.c:1646  */
    {
					Ltable *localTemp = Llookup(LtableGlobal, (yyvsp[-2])->NAME);
					if (localTemp==NULL){
						Gtable *temp = Glookup((yyvsp[-2])->NAME);
	 					if(temp==NULL){
	 						error=1;
	 						printf("%d ERROR: Identifier with name %s does not exists \n",yylineno,(yyvsp[-2])->NAME);
	 							  				
	 					}else {(yyvsp[-2])->Gentry=temp;
	 						if(temp->TYPE==VAR_TYPE_BOOL){
	 							error=1;
	 							printf("%d ERROR : I/O operations not allowed on booleans\n",yylineno);
	 							  				
	 						}else{
								(yyvsp[-4])->left=(yyvsp[-2]);
	 							(yyval)=(yyvsp[-4]);
	 				        	     }
	 						}
					}else{(yyvsp[-2])->Lentry=localTemp;
						if(localTemp->TYPE==VAR_TYPE_BOOL){
	 							error=1;
	 							printf("%d ERROR : I/O operations not allowed on booleans\n",yylineno);
	 							  				
	 						}else{
								(yyvsp[-4])->left=(yyvsp[-2]);
	 							(yyval)=(yyvsp[-4]);
	 				        	     }
						}
	 								   							 		    		               }
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 536 "s8Compiler.y" /* yacc.c:1646  */
    { 
				Ltable *localTemp = Llookup(LtableGlobal, (yyvsp[-5])->NAME);

				if(localTemp==NULL){	
				Gtable *temp = Glookup((yyvsp[-5])->NAME);
					if(temp==NULL){
						error=1;
						printf("%d ERROR: Identifier with name %s does not exists \n",yylineno,(yyvsp[-5])->NAME);
 							  				
					}else {(yyvsp[-5])->Gentry=temp;
						if(temp->TYPE==VAR_TYPE_BOOL){
			 				error=1;
			  				printf("%d ERROR : I/O operations not allowed on booleans\n",yylineno);
 							  				
						}else{
							if(check_if_int((yyvsp[-3]))){
									(yyvsp[-7])->left=(yyvsp[-5]);
									(yyvsp[-7])->right=(yyvsp[-3]);
									(yyval)=(yyvsp[-7]);	 	 									
	  										  
							}else{
								//for error propagation
								(yyvsp[-7])->Gentry=temp;
								(yyval)=(yyvsp[-7]);		
              						     }
						    }
	 					}
	 				}else{
					error = 1;
			  		printf("%d ERROR : Local variables cannot be arrays \n",yylineno);
					 								  			
	 		   		}

				  			
	 		 			}
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 572 "s8Compiler.y" /* yacc.c:1646  */
    { if(check_if_int((yyvsp[-2]))){
						(yyvsp[-4])->left=(yyvsp[-2]);
	 					(yyval)=(yyvsp[-4]);
	 										 
	 					}
	 								
	 				}
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 580 "s8Compiler.y" /* yacc.c:1646  */
    { if(check_if_bool((yyvsp[-5]))){
	 							(yyvsp[-7])->left = (yyvsp[-5]);
								(yyvsp[-7])->middle=(yyvsp[-2]);
								(yyval)=(yyvsp[-7]);
													
											  
	 							}
						      }
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 588 "s8Compiler.y" /* yacc.c:1646  */
    { if(check_if_bool((yyvsp[-7]))){
	 							  	   (yyvsp[-9])->left=(yyvsp[-7]);
	 								   (yyvsp[-9])->middle=(yyvsp[-4]);
	 								   (yyvsp[-9])->right=(yyvsp[-2]);
	 								   (yyval)=(yyvsp[-9]);
	 												   
	 							    }
	 							 }
#line 2097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 596 "s8Compiler.y" /* yacc.c:1646  */
    { if(check_if_bool((yyvsp[-5]))){
					 			   (yyvsp[-7])->left = (yyvsp[-5]);
								   (yyvsp[-7])->right = (yyvsp[-2]);
								   (yyval)=(yyvsp[-7]);
								 }
							 }
#line 2108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 605 "s8Compiler.y" /* yacc.c:1646  */
    {if(check_if_int((yyvsp[-2])) && check_if_int((yyvsp[0]))) { (yyval)=(yyvsp[-1]); (yyval)->left = (yyvsp[-2]); (yyval)->right = (yyvsp[0]); (yyval)->TYPE=TYPE_INT;}}
#line 2114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 606 "s8Compiler.y" /* yacc.c:1646  */
    {if(check_if_int((yyvsp[-2])) && check_if_int((yyvsp[0]))) { (yyval)=(yyvsp[-1]); (yyval)->left = (yyvsp[-2]); (yyval)->right = (yyvsp[0]); (yyval)->TYPE=TYPE_INT;}}
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 607 "s8Compiler.y" /* yacc.c:1646  */
    {if(check_if_int((yyvsp[-2])) && check_if_int((yyvsp[0]))) { (yyval)=(yyvsp[-1]); (yyval)->left = (yyvsp[-2]); (yyval)->right = (yyvsp[0]); (yyval)->TYPE=TYPE_INT;}}
#line 2126 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 608 "s8Compiler.y" /* yacc.c:1646  */
    {if(check_if_int((yyvsp[-2])) && check_if_int((yyvsp[0]))) { (yyval)=(yyvsp[-1]); (yyval)->left = (yyvsp[-2]); (yyval)->right = (yyvsp[0]); (yyval)->TYPE=TYPE_INT;}}
#line 2132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 609 "s8Compiler.y" /* yacc.c:1646  */
    {if(check_if_int((yyvsp[-2])) && check_if_int((yyvsp[0]))) { (yyval)=(yyvsp[-1]); (yyval)->left = (yyvsp[-2]); (yyval)->right = (yyvsp[0]); (yyval)->TYPE=TYPE_INT;}}
#line 2138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 610 "s8Compiler.y" /* yacc.c:1646  */
    {if(check_if_int((yyvsp[-2])) && check_if_int((yyvsp[0]))) { (yyval)=(yyvsp[-1]); (yyval)->left = (yyvsp[-2]); (yyval)->right = (yyvsp[0]); (yyval)->TYPE=TYPE_BOOL;}}
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 611 "s8Compiler.y" /* yacc.c:1646  */
    {if(check_if_int((yyvsp[-2])) && check_if_int((yyvsp[0]))) { (yyval)=(yyvsp[-1]); (yyval)->left = (yyvsp[-2]); (yyval)->right = (yyvsp[0]); (yyval)->TYPE=TYPE_BOOL;}}
#line 2150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 612 "s8Compiler.y" /* yacc.c:1646  */
    {if(check_if_int((yyvsp[-2])) && check_if_int((yyvsp[0]))) { (yyval)=(yyvsp[-1]); (yyval)->left = (yyvsp[-2]); (yyval)->right = (yyvsp[0]); (yyval)->TYPE=TYPE_BOOL;}}
#line 2156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 613 "s8Compiler.y" /* yacc.c:1646  */
    {if(check_if_int((yyvsp[-2])) && check_if_int((yyvsp[0]))) { (yyval)=(yyvsp[-1]); (yyval)->left = (yyvsp[-2]); (yyval)->right = (yyvsp[0]); (yyval)->TYPE=TYPE_BOOL;}}
#line 2162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 614 "s8Compiler.y" /* yacc.c:1646  */
    {if(typeCheck((yyvsp[-2]),(yyvsp[0]))) { (yyval)=(yyvsp[-1]); (yyval)->left = (yyvsp[-2]); (yyval)->right = (yyvsp[0]);(yyval)->TYPE=TYPE_BOOL;}}
#line 2168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 615 "s8Compiler.y" /* yacc.c:1646  */
    {if(typeCheck((yyvsp[-2]),(yyvsp[0]))) { (yyval)=(yyvsp[-1]); (yyval)->left = (yyvsp[-2]); (yyval)->right = (yyvsp[0]);(yyval)->TYPE=TYPE_BOOL;}}
#line 2174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 616 "s8Compiler.y" /* yacc.c:1646  */
    {if(check_if_bool((yyvsp[-2])) && check_if_bool((yyvsp[0]))){ (yyval)=(yyvsp[-1]); (yyval)->left = (yyvsp[-2]); (yyval)->right = (yyvsp[0]);(yyval)->TYPE=TYPE_BOOL;}}
#line 2180 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 617 "s8Compiler.y" /* yacc.c:1646  */
    {if(check_if_bool((yyvsp[-2])) && check_if_bool((yyvsp[0]))){ (yyval)=(yyvsp[-1]); (yyval)->left = (yyvsp[-2]); (yyval)->right = (yyvsp[0]);(yyval)->TYPE=TYPE_BOOL;}}
#line 2186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 618 "s8Compiler.y" /* yacc.c:1646  */
    {if(check_if_bool((yyvsp[0]))){ (yyval)=(yyvsp[-1]); (yyval)->left = (yyvsp[0]); (yyval)->TYPE=TYPE_BOOL;}}
#line 2192 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 619 "s8Compiler.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 2198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 620 "s8Compiler.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);(yyval)->TYPE=TYPE_INT;}
#line 2204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 621 "s8Compiler.y" /* yacc.c:1646  */
    {  Ltable *localTemp = Llookup(LtableGlobal, (yyvsp[0])->NAME);
 
		if(localTemp==NULL){

		Gtable *temp = Glookup((yyvsp[0])->NAME);
	 	if(temp==NULL){
	 		error=1;
	 		printf("%d ERROR : Identifier with name %s does not exists \n",yylineno,(yyvsp[0])->NAME);
	 					
	 	}else{
	 			
	 		(yyvsp[0])->Gentry=temp;
	 		(yyval)=(yyvsp[0]);	 	 				
	 		}
		}else{  printf("%d : Found locally %s\n",yylineno,(yyvsp[0])->NAME); 
			(yyvsp[0])->Lentry=localTemp;
	 		(yyval)=(yyvsp[0]);

		}
	 	 	
	   }
#line 2230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 642 "s8Compiler.y" /* yacc.c:1646  */
    {
			Ltable *localTemp = Llookup(LtableGlobal, (yyvsp[-3])->NAME);
 
			if(localTemp==NULL){
				

/*				Ltable *index = Llookup(LtableGlobal, $3->NAME);
				
 				if(index==NULL){
/*
				Gtable *temp = Glookup($1->NAME);
					if(temp==NULL){
	 					error = 1;
	 					printf("%d ERROR : Identifier with name %s does not exists \n",yylineno,$1->NAME);
	 				 }else{
						if(check_if_int($3)+validate_array_index(temp->SIZE,Evaluate($3),temp->NAME)==2){
							$1->Gentry=temp;
							$1->middle=$3;
							$$=$1;
	 									
						}else{//for error propagation
							$1->Gentry=temp;
							$$=$1;
						
        					     }	 						 
	 				      }//////////////////
					Gtable *temp = Glookup($1->NAME);
					$1->Gentry=temp;
					check_if_int($3);
					$1->middle=$3;
					$$=$1;


				}else{	Gtable *temp = Glookup($1->NAME);
					$1->Gentry=temp;
					check_if_int($3);
					$1->middle=$3;
					$$=$1;
					}*/
				Gtable *temp = Glookup((yyvsp[-3])->NAME);
					(yyvsp[-3])->Gentry=temp;
					check_if_int((yyvsp[-1]));
					(yyvsp[-3])->middle=(yyvsp[-1]);
					(yyval)=(yyvsp[-3]);
	 		}else{
					error = 1;
			  		printf("%d ERROR : Local variables cannot be arrays \n",yylineno);
					 								  			
	 		     }			  
	 		}
#line 2285 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 692 "s8Compiler.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 693 "s8Compiler.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 694 "s8Compiler.y" /* yacc.c:1646  */
    {printTreeList((yyvsp[-1]));	
					Gtable *temp = Glookup((yyvsp[-3])->NAME);
					if(temp==NULL){
	 					error = 1;
	 					printf("%d ERROR : Identifier with name %s does not exists \n",yylineno,(yyvsp[-3])->NAME);
	 				 }else{
						printf("\nin the FNCTION CALL type for function is %d\n",temp->TYPE);
						if(temp->is_function ){
							if(temp->defined_flag){
								printf("\nFunction call being checked\n");            			
								checkFunctionCall((yyvsp[-3])->NAME,(yyvsp[-1]));
								printf("\nFunction call checked\n");
								(yyvsp[-3])->right=(yyvsp[-1]);
								(yyvsp[-3])->Gentry=temp;
								(yyval)=(yyvsp[-3]);
							}else{
			 					error = 1;
			 					printf("%d ERROR : Function %s is not defined \n",yylineno,(yyvsp[-3])->NAME);
							
							}

						}else{
	 					error = 1;
	 					printf("%d ERROR : %s is not a function \n",yylineno,(yyvsp[-3])->NAME);

						}	
					     }	
				
			       	       }
#line 2331 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 724 "s8Compiler.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 2337 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 725 "s8Compiler.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2343 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 727 "s8Compiler.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2349 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 728 "s8Compiler.y" /* yacc.c:1646  */
    {(yyvsp[-2])->next=(yyvsp[0]); (yyval)=(yyvsp[-2]);}
#line 2355 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2359 "y.tab.c" /* yacc.c:1646  */
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
#line 731 "s8Compiler.y" /* yacc.c:1906  */


yyerror()
{
	printf("Parsing Error in line no. %d\n",yylineno);
}

int main(int argc, char *argv[ ])
{
	char file[20];
	printf("Enter an input file name\n");
	scanf("%s",file);
	yyin=fopen(file,"r");
	outfile= fopen("code","w");
	yyparse();
	fclose(yyin);
	
}
