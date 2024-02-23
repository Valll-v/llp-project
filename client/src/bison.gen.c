/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser/bison.y"

    #include <stdio.h>
    #include <stdbool.h>
    #include "tree.h"
    #include "parser.h"
    extern int yylex();

#line 79 "src/bison.gen.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "bison.gen.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOKEN_INT = 3,                  /* TOKEN_INT  */
  YYSYMBOL_TOKEN_FLOAT = 4,                /* TOKEN_FLOAT  */
  YYSYMBOL_TOKEN_BOOL = 5,                 /* TOKEN_BOOL  */
  YYSYMBOL_TOKEN_STRING = 6,               /* TOKEN_STRING  */
  YYSYMBOL_TOKEN_NAME = 7,                 /* TOKEN_NAME  */
  YYSYMBOL_TOKEN_OPEN = 8,                 /* TOKEN_OPEN  */
  YYSYMBOL_TOKEN_CLOSE = 9,                /* TOKEN_CLOSE  */
  YYSYMBOL_TOKEN_DOT = 10,                 /* TOKEN_DOT  */
  YYSYMBOL_TOKEN_COMMA = 11,               /* TOKEN_COMMA  */
  YYSYMBOL_TOKEN_ASSIGNMENT = 12,          /* TOKEN_ASSIGNMENT  */
  YYSYMBOL_TOKEN_SELECT = 13,              /* TOKEN_SELECT  */
  YYSYMBOL_TOKEN_FROM = 14,                /* TOKEN_FROM  */
  YYSYMBOL_TOKEN_WHERE = 15,               /* TOKEN_WHERE  */
  YYSYMBOL_TOKEN_CREATE = 16,              /* TOKEN_CREATE  */
  YYSYMBOL_TOKEN_DROP = 17,                /* TOKEN_DROP  */
  YYSYMBOL_TOKEN_TABLE = 18,               /* TOKEN_TABLE  */
  YYSYMBOL_TOKEN_DELETE = 19,              /* TOKEN_DELETE  */
  YYSYMBOL_TOKEN_INSERT = 20,              /* TOKEN_INSERT  */
  YYSYMBOL_TOKEN_INTO = 21,                /* TOKEN_INTO  */
  YYSYMBOL_TOKEN_UPDATE = 22,              /* TOKEN_UPDATE  */
  YYSYMBOL_TOKEN_SET = 23,                 /* TOKEN_SET  */
  YYSYMBOL_TOKEN_VALUES = 24,              /* TOKEN_VALUES  */
  YYSYMBOL_TOKEN_LEQ = 25,                 /* TOKEN_LEQ  */
  YYSYMBOL_TOKEN_GEQ = 26,                 /* TOKEN_GEQ  */
  YYSYMBOL_TOKEN_LESS = 27,                /* TOKEN_LESS  */
  YYSYMBOL_TOKEN_GREATER = 28,             /* TOKEN_GREATER  */
  YYSYMBOL_TOKEN_EQ = 29,                  /* TOKEN_EQ  */
  YYSYMBOL_TOKEN_NEQ = 30,                 /* TOKEN_NEQ  */
  YYSYMBOL_TOKEN_OR = 31,                  /* TOKEN_OR  */
  YYSYMBOL_TOKEN_AND = 32,                 /* TOKEN_AND  */
  YYSYMBOL_TOKEN_NOT = 33,                 /* TOKEN_NOT  */
  YYSYMBOL_TOKEN_END = 34,                 /* TOKEN_END  */
  YYSYMBOL_TOKEN_INT_FIELD = 35,           /* TOKEN_INT_FIELD  */
  YYSYMBOL_TOKEN_FLOAT_FIELD = 36,         /* TOKEN_FLOAT_FIELD  */
  YYSYMBOL_TOKEN_STRING_FIELD = 37,        /* TOKEN_STRING_FIELD  */
  YYSYMBOL_TOKEN_BOOL_FIELD = 38,          /* TOKEN_BOOL_FIELD  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_QUERIES = 40,                   /* QUERIES  */
  YYSYMBOL_QUERIES_LIST = 41,              /* QUERIES_LIST  */
  YYSYMBOL_QUERY = 42,                     /* QUERY  */
  YYSYMBOL_EXP = 43,                       /* EXP  */
  YYSYMBOL_COMPARE = 44,                   /* COMPARE  */
  YYSYMBOL_FIELD_TYPE = 45,                /* FIELD_TYPE  */
  YYSYMBOL_LOGIC = 46,                     /* LOGIC  */
  YYSYMBOL_SET = 47,                       /* SET  */
  YYSYMBOL_SET_LIST = 48,                  /* SET_LIST  */
  YYSYMBOL_UPDATE_EXP = 49,                /* UPDATE_EXP  */
  YYSYMBOL_REFERENCE_LIST = 50,            /* REFERENCE_LIST  */
  YYSYMBOL_TABLE = 51,                     /* TABLE  */
  YYSYMBOL_COLUMN = 52,                    /* COLUMN  */
  YYSYMBOL_REFERENCE = 53,                 /* REFERENCE  */
  YYSYMBOL_SELECT_EXP = 54,                /* SELECT_EXP  */
  YYSYMBOL_WHERE = 55,                     /* WHERE  */
  YYSYMBOL_DELETE_EXP = 56,                /* DELETE_EXP  */
  YYSYMBOL_FIELD_LIST = 57,                /* FIELD_LIST  */
  YYSYMBOL_FIELD = 58,                     /* FIELD  */
  YYSYMBOL_CREATE_EXP = 59,                /* CREATE_EXP  */
  YYSYMBOL_VALUES_LIST = 60,               /* VALUES_LIST  */
  YYSYMBOL_INSERT_EXP = 61,                /* INSERT_EXP  */
  YYSYMBOL_DROP_EXP = 62,                  /* DROP_EXP  */
  YYSYMBOL_LOGIC_EXP = 63,                 /* LOGIC_EXP  */
  YYSYMBOL_COMPARE_EXP = 64,               /* COMPARE_EXP  */
  YYSYMBOL_VALUE = 65                      /* VALUE  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  25
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   91

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  102

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    46,    46,    46,    51,    53,    63,    64,    65,    66,
      67,    68,    72,    73,    74,    75,    79,    80,    81,    82,
      83,    84,    87,    88,    89,    90,    94,    95,    96,    99,
     106,   113,   120,   130,   137,   144,   150,   156,   163,   173,
     175,   183,   192,   199,   206,   213,   221,   228,   235,   243,
     251,   254,   262,   272,   275,   284,   290,   296,   302
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_INT",
  "TOKEN_FLOAT", "TOKEN_BOOL", "TOKEN_STRING", "TOKEN_NAME", "TOKEN_OPEN",
  "TOKEN_CLOSE", "TOKEN_DOT", "TOKEN_COMMA", "TOKEN_ASSIGNMENT",
  "TOKEN_SELECT", "TOKEN_FROM", "TOKEN_WHERE", "TOKEN_CREATE",
  "TOKEN_DROP", "TOKEN_TABLE", "TOKEN_DELETE", "TOKEN_INSERT",
  "TOKEN_INTO", "TOKEN_UPDATE", "TOKEN_SET", "TOKEN_VALUES", "TOKEN_LEQ",
  "TOKEN_GEQ", "TOKEN_LESS", "TOKEN_GREATER", "TOKEN_EQ", "TOKEN_NEQ",
  "TOKEN_OR", "TOKEN_AND", "TOKEN_NOT", "TOKEN_END", "TOKEN_INT_FIELD",
  "TOKEN_FLOAT_FIELD", "TOKEN_STRING_FIELD", "TOKEN_BOOL_FIELD", "$accept",
  "QUERIES", "QUERIES_LIST", "QUERY", "EXP", "COMPARE", "FIELD_TYPE",
  "LOGIC", "SET", "SET_LIST", "UPDATE_EXP", "REFERENCE_LIST", "TABLE",
  "COLUMN", "REFERENCE", "SELECT_EXP", "WHERE", "DELETE_EXP", "FIELD_LIST",
  "FIELD", "CREATE_EXP", "VALUES_LIST", "INSERT_EXP", "DROP_EXP",
  "LOGIC_EXP", "COMPARE_EXP", "VALUE", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-62)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      41,     7,    -2,     3,     1,     9,     7,    31,   -62,    21,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,    18,    26,    45,
       7,     7,     7,     7,    14,   -62,    41,     7,    52,     7,
      54,   -62,    58,    50,    52,   -62,    58,   -62,   -62,   -62,
      52,     2,   -62,    67,    65,    58,    66,   -62,   -10,    68,
      69,   -62,   -62,   -62,   -62,     2,    71,    39,   -62,   -62,
     -62,   -62,    37,    52,   -62,    37,   -62,   -62,   -62,   -62,
     -62,   -62,    52,    39,    72,    73,     2,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,     2,     2,    74,    75,
     -62,   -62,   -62,   -62,   -62,    20,    39,    39,   -62,    37,
     -62,   -62
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     0,     0,     0,     0,     0,     3,     0,
       7,     6,     9,     8,    10,    11,    35,     0,     0,    34,
       0,     0,     0,     0,     0,     1,     4,     0,     0,     0,
       0,    49,    39,     0,     0,     5,    39,    36,    37,    33,
       0,     0,    41,     0,    31,    39,     0,    38,     0,     0,
      43,    55,    56,    57,    58,     0,     0,    40,    15,    14,
      13,    12,     0,     0,    32,     0,    22,    23,    24,    25,
      44,    45,     0,     0,    14,    13,     0,    16,    17,    18,
      19,    20,    21,    26,    27,    28,     0,     0,     0,    47,
      30,    29,    42,    50,    53,     0,    54,    52,    48,     0,
      51,    46
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -62,   -62,    59,   -62,   -53,   -62,   -62,   -62,   -62,    24,
     -62,    55,    -3,   -28,    10,   -62,   -23,   -62,    16,   -62,
     -62,    -9,   -62,   -62,    34,    36,   -61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     7,     8,     9,    57,    86,    70,    87,    44,    45,
      10,    17,    18,    46,    58,    11,    42,    12,    49,    50,
      13,    88,    14,    15,    59,    60,    61
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      38,    89,    73,    24,    91,    51,    52,    53,    54,    16,
      55,    19,    48,    47,    16,    22,    20,    30,    31,    32,
      33,    21,    64,    95,    36,    66,    67,    68,    69,   100,
      23,    25,    27,    96,    97,    56,    28,    34,    89,    19,
      51,    52,    53,    54,    48,    77,    78,    79,    80,    81,
      82,    83,    84,    85,     1,    26,    29,     2,     3,    37,
       4,     5,    40,     6,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    41,    43,    62,    63,    71,    65,    76,
      72,    93,    94,    98,    39,    35,    99,    90,    92,    74,
     101,    75
};

static const yytype_int8 yycheck[] =
{
      28,    62,    55,     6,    65,     3,     4,     5,     6,     7,
       8,     1,    40,    36,     7,    14,    18,    20,    21,    22,
      23,    18,    45,    76,    27,    35,    36,    37,    38,     9,
      21,     0,    14,    86,    87,    33,    10,    23,    99,    29,
       3,     4,     5,     6,    72,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    13,    34,    11,    16,    17,     7,
      19,    20,     8,    22,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    15,    24,     8,    11,     9,    12,     8,
      11,     9,     9,     9,    29,    26,    11,    63,    72,    55,
      99,    55
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    13,    16,    17,    19,    20,    22,    40,    41,    42,
      49,    54,    56,    59,    61,    62,     7,    50,    51,    53,
      18,    18,    14,    21,    51,     0,    34,    14,    10,    11,
      51,    51,    51,    51,    23,    41,    51,     7,    52,    50,
       8,    15,    55,    24,    47,    48,    52,    55,    52,    57,
      58,     3,     4,     5,     6,     8,    33,    43,    53,    63,
      64,    65,     8,    11,    55,    12,    35,    36,    37,    38,
      45,     9,    11,    43,    63,    64,     8,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    44,    46,    60,    65,
      48,    65,    57,     9,     9,    43,    43,    43,     9,    11,
       9,    60
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    40,    41,    41,    42,    42,    42,    42,
      42,    42,    43,    43,    43,    43,    44,    44,    44,    44,
      44,    44,    45,    45,    45,    45,    46,    46,    46,    47,
      48,    48,    49,    50,    50,    51,    52,    53,    54,    55,
      55,    56,    57,    57,    58,    59,    60,    60,    61,    62,
      63,    63,    63,    64,    64,    65,    65,    65,    65
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     5,     3,     1,     1,     1,     3,     5,     0,
       2,     4,     3,     1,     2,     6,     3,     1,     7,     3,
       3,     4,     3,     3,     3,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        yyerror (tree, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, tree); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, Node **tree)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (tree);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, Node **tree)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, tree);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, Node **tree)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], tree);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, tree); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, Node **tree)
{
  YY_USE (yyvaluep);
  YY_USE (tree);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (Node **tree)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 3: /* QUERIES: QUERIES_LIST  */
#line 46 "parser/bison.y"
                        {
    *tree = (yyvsp[0].node);
}
#line 1204 "src/bison.gen.c"
    break;

  case 4: /* QUERIES_LIST: %empty  */
#line 51 "parser/bison.y"
               {
    (yyval.node) = NULL;
}
#line 1212 "src/bison.gen.c"
    break;

  case 5: /* QUERIES_LIST: QUERY TOKEN_END QUERIES_LIST  */
#line 53 "parser/bison.y"
                                 {
    Node *node = createNode();
    node->type = NTOKEN_QUERIES_LIST;
    node->data.QUERIES_LIST.query = (yyvsp[-2].node);
    node->data.QUERIES_LIST.next = (yyvsp[0].node);
    (yyval.node) = node;
}
#line 1224 "src/bison.gen.c"
    break;

  case 29: /* SET: COLUMN TOKEN_ASSIGNMENT VALUE  */
#line 99 "parser/bison.y"
                                   {
    Node *node = createNode();
    node->type = NTOKEN_SET;
    node->data.SET.column = (yyvsp[-2].node);
    node->data.SET.value = (yyvsp[0].node);
    (yyval.node) = node;
}
#line 1236 "src/bison.gen.c"
    break;

  case 30: /* SET_LIST: SET TOKEN_COMMA SET_LIST  */
#line 106 "parser/bison.y"
                                   {
    Node *node = createNode();
    node->type = NTOKEN_SET_LIST;
    node->data.SET_LIST.set = (yyvsp[-2].node);
    node->data.SET_LIST.next = (yyvsp[0].node);
    (yyval.node) = node;
}
#line 1248 "src/bison.gen.c"
    break;

  case 31: /* SET_LIST: SET  */
#line 113 "parser/bison.y"
    {
    Node *node = createNode();
    node->type = NTOKEN_SET_LIST;
    node->data.SET_LIST.set = (yyvsp[0].node);
    node->data.SET_LIST.next = NULL;
    (yyval.node) = node;
}
#line 1260 "src/bison.gen.c"
    break;

  case 32: /* UPDATE_EXP: TOKEN_UPDATE TABLE TOKEN_SET SET_LIST WHERE  */
#line 120 "parser/bison.y"
                                                        {
    Node *node = createNode();
    node->type = NTOKEN_UPDATE;
    node->data.UPDATE.set_list = (yyvsp[-1].node);
    node->data.UPDATE.table = (yyvsp[-3].node);
    node->data.UPDATE.where = (yyvsp[0].node);
    (yyval.node) = node;
}
#line 1273 "src/bison.gen.c"
    break;

  case 33: /* REFERENCE_LIST: REFERENCE TOKEN_COMMA REFERENCE_LIST  */
#line 130 "parser/bison.y"
                                                     {
    Node *node = createNode();
    node->type = NTOKEN_REFERENCE_LIST;
    node->data.REFERENCE_LIST.reference = (yyvsp[-2].node);
    node->data.REFERENCE_LIST.next = (yyvsp[0].node);
    (yyval.node) = node;
}
#line 1285 "src/bison.gen.c"
    break;

  case 34: /* REFERENCE_LIST: REFERENCE  */
#line 137 "parser/bison.y"
          {
    Node *node = createNode();
    node->type = NTOKEN_REFERENCE_LIST;
    node->data.REFERENCE_LIST.reference = (yyvsp[0].node);
    node->data.REFERENCE_LIST.next = NULL;
    (yyval.node) = node;
}
#line 1297 "src/bison.gen.c"
    break;

  case 35: /* TABLE: TOKEN_NAME  */
#line 144 "parser/bison.y"
                   {
    Node *node = createNode();
    node->type = NTOKEN_TABLE;
    node->data.TABLE.table = (yyvsp[0].stringValue);
    (yyval.node) = node;
}
#line 1308 "src/bison.gen.c"
    break;

  case 36: /* COLUMN: TOKEN_NAME  */
#line 150 "parser/bison.y"
                    {
    Node *node = createNode();
    node->type = NTOKEN_COLUMN;
    node->data.COLUMN.column = (yyvsp[0].stringValue);
    (yyval.node) = node;
}
#line 1319 "src/bison.gen.c"
    break;

  case 37: /* REFERENCE: TABLE TOKEN_DOT COLUMN  */
#line 156 "parser/bison.y"
                                  {
    Node *node = createNode();
    node->type = NTOKEN_REFERENCE;
    node->data.REFERENCE.table = (yyvsp[-2].node);
    node->data.REFERENCE.column = (yyvsp[0].node);
    (yyval.node) = node;
}
#line 1331 "src/bison.gen.c"
    break;

  case 38: /* SELECT_EXP: TOKEN_SELECT REFERENCE_LIST TOKEN_FROM TABLE WHERE  */
#line 163 "parser/bison.y"
                                                               {
    Node *node = createNode();
    node->type = NTOKEN_SELECT;
    node->data.SELECT.reference = (yyvsp[-3].node);
    node->data.SELECT.table = (yyvsp[-1].node);
    node->data.SELECT.where = (yyvsp[0].node);
    (yyval.node) = node;
}
#line 1344 "src/bison.gen.c"
    break;

  case 39: /* WHERE: %empty  */
#line 173 "parser/bison.y"
       {
    (yyval.node) = NULL;
}
#line 1352 "src/bison.gen.c"
    break;

  case 40: /* WHERE: TOKEN_WHERE EXP  */
#line 175 "parser/bison.y"
                    {
    Node *node = createNode();
    node->type = NTOKEN_WHERE;
    node->data.WHERE.logic = (yyvsp[0].node);
    (yyval.node) = node;
}
#line 1363 "src/bison.gen.c"
    break;

  case 41: /* DELETE_EXP: TOKEN_DELETE TOKEN_FROM TABLE WHERE  */
#line 183 "parser/bison.y"
                                                {
    Node *node = createNode();
    node->type = NTOKEN_DELETE;
    node->data.DELETE.table = (yyvsp[-1].node);
    node->data.DELETE.where = (yyvsp[0].node);
    (yyval.node) = node;
}
#line 1375 "src/bison.gen.c"
    break;

  case 42: /* FIELD_LIST: FIELD TOKEN_COMMA FIELD_LIST  */
#line 192 "parser/bison.y"
                                         {
    Node *node = createNode();
    node->type = NTOKEN_FIELD_LIST;
    node->data.FIELD_LIST.field = (yyvsp[-2].node);
    node->data.FIELD_LIST.next = (yyvsp[0].node);
    (yyval.node) = node;
}
#line 1387 "src/bison.gen.c"
    break;

  case 43: /* FIELD_LIST: FIELD  */
#line 199 "parser/bison.y"
      {
    Node *node = createNode();
    node->type = NTOKEN_FIELD_LIST;
    node->data.FIELD_LIST.field = (yyvsp[0].node);
    node->data.FIELD_LIST.next = NULL;
    (yyval.node) = node;
}
#line 1399 "src/bison.gen.c"
    break;

  case 44: /* FIELD: COLUMN FIELD_TYPE  */
#line 206 "parser/bison.y"
                         {
    Node *node = createNode();
    node->type = NTOKEN_FIELD;
    node->data.FIELD.column = (yyvsp[-1].node);
    node->data.FIELD.type = (yyvsp[0].fieldType);
    (yyval.node) = node;
}
#line 1411 "src/bison.gen.c"
    break;

  case 45: /* CREATE_EXP: TOKEN_CREATE TOKEN_TABLE TABLE TOKEN_OPEN FIELD_LIST TOKEN_CLOSE  */
#line 213 "parser/bison.y"
                                                                             {
    Node *node = createNode();
    node->type = NTOKEN_CREATE;
    node->data.CREATE.table = (yyvsp[-3].node);
    node->data.CREATE.field_list = (yyvsp[-1].node);
    (yyval.node) = node;
}
#line 1423 "src/bison.gen.c"
    break;

  case 46: /* VALUES_LIST: VALUE TOKEN_COMMA VALUES_LIST  */
#line 221 "parser/bison.y"
                                           {
    Node *node = createNode();
    node->type = NTOKEN_VALUES_LIST;
    node->data.VALUES_LIST.value = (yyvsp[-2].node);
    node->data.VALUES_LIST.next = (yyvsp[0].node);
    (yyval.node) = node;
}
#line 1435 "src/bison.gen.c"
    break;

  case 47: /* VALUES_LIST: VALUE  */
#line 228 "parser/bison.y"
      {
    Node *node = createNode();
    node->type = NTOKEN_VALUES_LIST;
    node->data.VALUES_LIST.value = (yyvsp[0].node);
    node->data.VALUES_LIST.next = NULL;
    (yyval.node) = node;
}
#line 1447 "src/bison.gen.c"
    break;

  case 48: /* INSERT_EXP: TOKEN_INSERT TOKEN_INTO TABLE TOKEN_VALUES TOKEN_OPEN VALUES_LIST TOKEN_CLOSE  */
#line 235 "parser/bison.y"
                                                                                          {
    Node *node = createNode();
    node->type = NTOKEN_INSERT;
    node->data.INSERT.table = (yyvsp[-4].node);
    node->data.INSERT.values_list = (yyvsp[-1].node);
    (yyval.node) = node;
}
#line 1459 "src/bison.gen.c"
    break;

  case 49: /* DROP_EXP: TOKEN_DROP TOKEN_TABLE TABLE  */
#line 243 "parser/bison.y"
                                       {
    Node *node = createNode();
    node->type = NTOKEN_DROP;
    node->data.DROP.table = (yyvsp[0].node);
    (yyval.node) = node;
}
#line 1470 "src/bison.gen.c"
    break;

  case 50: /* LOGIC_EXP: TOKEN_OPEN LOGIC_EXP TOKEN_CLOSE  */
#line 251 "parser/bison.y"
                                            {
    (yyval.node) = (yyvsp[-1].node);
}
#line 1478 "src/bison.gen.c"
    break;

  case 51: /* LOGIC_EXP: TOKEN_NOT TOKEN_OPEN EXP TOKEN_CLOSE  */
#line 254 "parser/bison.y"
                                     {
    Node *node = createNode();
    node->type = NTOKEN_LOGIC;
    node->data.LOGIC.type = (yyvsp[-3].logicType);
    node->data.LOGIC.left = (yyvsp[-1].node);
    node->data.LOGIC.right = NULL;
    (yyval.node) = node;
}
#line 1491 "src/bison.gen.c"
    break;

  case 52: /* LOGIC_EXP: EXP LOGIC EXP  */
#line 262 "parser/bison.y"
              {
    Node *node = createNode();
    node->type = NTOKEN_LOGIC;
    node->data.LOGIC.type = (yyvsp[-1].logicType);
    node->data.LOGIC.left = (yyvsp[-2].node);
    node->data.LOGIC.right = (yyvsp[0].node);
    (yyval.node) = node;
}
#line 1504 "src/bison.gen.c"
    break;

  case 53: /* COMPARE_EXP: TOKEN_OPEN COMPARE_EXP TOKEN_CLOSE  */
#line 272 "parser/bison.y"
                                                {
    (yyval.node) = (yyvsp[-1].node);
}
#line 1512 "src/bison.gen.c"
    break;

  case 54: /* COMPARE_EXP: EXP COMPARE EXP  */
#line 275 "parser/bison.y"
                {
    Node *node = createNode();
    node->type = NTOKEN_COMPARE;
    node->data.COMPARE.type = (yyvsp[-1].compareType);
    node->data.COMPARE.left = (yyvsp[-2].node);
    node->data.COMPARE.right = (yyvsp[0].node);
    (yyval.node) = node;
}
#line 1525 "src/bison.gen.c"
    break;

  case 55: /* VALUE: TOKEN_INT  */
#line 284 "parser/bison.y"
                 {
    Node *node = createNode();
    node->type = NTOKEN_INT;
    node->data.INT.value = (yyvsp[0].intValue);
    (yyval.node) = node;
}
#line 1536 "src/bison.gen.c"
    break;

  case 56: /* VALUE: TOKEN_FLOAT  */
#line 290 "parser/bison.y"
            {
    Node *node = createNode();
    node->type = NTOKEN_FLOAT;
    node->data.FLOAT.value = (yyvsp[0].floatValue);
    (yyval.node) = node;
}
#line 1547 "src/bison.gen.c"
    break;

  case 57: /* VALUE: TOKEN_BOOL  */
#line 296 "parser/bison.y"
           {
    Node *node = createNode();
    node->type = NTOKEN_BOOL;
    node->data.BOOL.value = (yyvsp[0].boolValue);
    (yyval.node) = node;
}
#line 1558 "src/bison.gen.c"
    break;

  case 58: /* VALUE: TOKEN_STRING  */
#line 302 "parser/bison.y"
             {
    Node *node = createNode();
    node->type = NTOKEN_STRING;
    node->data.STRING.value = (yyvsp[0].stringValue);
    (yyval.node) = node;
}
#line 1569 "src/bison.gen.c"
    break;


#line 1573 "src/bison.gen.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (tree, YY_("syntax error"));
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
                      yytoken, &yylval, tree);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, tree);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (tree, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, tree);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, tree);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 309 "parser/bison.y"
