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
#line 1 "yacc.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern FILE *yyin;
FILE *inter;
FILE *assembly;



struct Operation
{
	char* operand1;
	char* operator;
	char* operand2;
}conds;

int yyerror(char *s);
char *truelabel, *falselabel, *nextlabel; 
char* createTemp()
{
  static int tempcount=0;
  char* temp = malloc(10);
  sprintf(temp,"t%d",tempcount++);
  return temp;
}

char* createRegister()
{
  static int registercount=0;
  char* temp = malloc(10);
  sprintf(temp,"R%d",registercount++);
  return temp;
}
char* createLabel()
{
  static int labelcount=100;
  char* temp = malloc(10);
  sprintf(temp,"L%d",labelcount++);
  return temp;
}




#line 119 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    ID = 258,                      /* ID  */
    INT = 259,                     /* INT  */
    FLOAT = 260,                   /* FLOAT  */
    UMINUS = 261,                  /* UMINUS  */
    REL_LT = 262,                  /* REL_LT  */
    REL_LTEQ = 263,                /* REL_LTEQ  */
    REL_EQ = 264,                  /* REL_EQ  */
    REL_NEQ = 265,                 /* REL_NEQ  */
    REL_GT = 266,                  /* REL_GT  */
    REL_GTEQ = 267,                /* REL_GTEQ  */
    IF = 268,                      /* IF  */
    ELSE = 269,                    /* ELSE  */
    NUM = 270,                     /* NUM  */
    WHILE = 271,                   /* WHILE  */
    STAR_STAR = 272                /* STAR_STAR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ID 258
#define INT 259
#define FLOAT 260
#define UMINUS 261
#define REL_LT 262
#define REL_LTEQ 263
#define REL_EQ 264
#define REL_NEQ 265
#define REL_GT 266
#define REL_GTEQ 267
#define IF 268
#define ELSE 269
#define NUM 270
#define WHILE 271
#define STAR_STAR 272

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 50 "yacc.y"

int intval;
float floatval;
char* addr;

#line 212 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_3_ = 3,                         /* '+'  */
  YYSYMBOL_4_ = 4,                         /* '-'  */
  YYSYMBOL_5_ = 5,                         /* '*'  */
  YYSYMBOL_6_ = 6,                         /* '/'  */
  YYSYMBOL_ID = 7,                         /* ID  */
  YYSYMBOL_INT = 8,                        /* INT  */
  YYSYMBOL_FLOAT = 9,                      /* FLOAT  */
  YYSYMBOL_UMINUS = 10,                    /* UMINUS  */
  YYSYMBOL_REL_LT = 11,                    /* REL_LT  */
  YYSYMBOL_REL_LTEQ = 12,                  /* REL_LTEQ  */
  YYSYMBOL_REL_EQ = 13,                    /* REL_EQ  */
  YYSYMBOL_REL_NEQ = 14,                   /* REL_NEQ  */
  YYSYMBOL_REL_GT = 15,                    /* REL_GT  */
  YYSYMBOL_REL_GTEQ = 16,                  /* REL_GTEQ  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_ELSE = 18,                      /* ELSE  */
  YYSYMBOL_NUM = 19,                       /* NUM  */
  YYSYMBOL_WHILE = 20,                     /* WHILE  */
  YYSYMBOL_STAR_STAR = 21,                 /* STAR_STAR  */
  YYSYMBOL_22_ = 22,                       /* ';'  */
  YYSYMBOL_23_ = 23,                       /* ','  */
  YYSYMBOL_24_ = 24,                       /* '='  */
  YYSYMBOL_25_ = 25,                       /* '('  */
  YYSYMBOL_26_ = 26,                       /* ')'  */
  YYSYMBOL_27_ = 27,                       /* '{'  */
  YYSYMBOL_28_ = 28,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 29,                  /* $accept  */
  YYSYMBOL_SS = 30,                        /* SS  */
  YYSYMBOL_P = 31,                         /* P  */
  YYSYMBOL_D = 32,                         /* D  */
  YYSYMBOL_DD = 33,                        /* DD  */
  YYSYMBOL_T = 34,                         /* T  */
  YYSYMBOL_S = 35,                         /* S  */
  YYSYMBOL_E = 36,                         /* E  */
  YYSYMBOL_NUM_E = 37,                     /* NUM_E  */
  YYSYMBOL_REL_E = 38,                     /* REL_E  */
  YYSYMBOL_39_1 = 39,                      /* $@1  */
  YYSYMBOL_40_2 = 40,                      /* $@2  */
  YYSYMBOL_41_3 = 41,                      /* $@3  */
  YYSYMBOL_BLOCK = 42,                     /* BLOCK  */
  YYSYMBOL_43_4 = 43                       /* $@4  */
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   114

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  41
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  82

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   272


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
      25,    26,     5,     3,    23,     4,     2,     6,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    22,
       2,    24,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,     2,    28,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    64,    64,    65,    69,    70,    73,    74,    77,    78,
      81,    81,    84,    88,    93,   126,   138,   169,   201,   213,
     225,   235,   236,   242,   243,   244,   245,   246,   247,   250,
     257,   263,   269,   276,   282,   290,   323,   328,   290,   341,
     344,   344
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
  "\"end of file\"", "error", "\"invalid token\"", "'+'", "'-'", "'*'",
  "'/'", "ID", "INT", "FLOAT", "UMINUS", "REL_LT", "REL_LTEQ", "REL_EQ",
  "REL_NEQ", "REL_GT", "REL_GTEQ", "IF", "ELSE", "NUM", "WHILE",
  "STAR_STAR", "';'", "','", "'='", "'('", "')'", "'{'", "'}'", "$accept",
  "SS", "P", "D", "DD", "T", "S", "E", "NUM_E", "REL_E", "$@1", "$@2",
  "$@3", "BLOCK", "$@4", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-65)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -65,    59,   -65,   -16,   -65,   -65,    -8,    -5,   -65,   -65,
      36,   -65,    44,    44,    44,    19,    27,    44,   -65,   -65,
      44,     9,    67,    79,    98,    24,    29,    36,     2,    39,
      47,    35,    44,    44,    44,    44,    44,   -65,     0,     0,
       0,     0,   -65,    44,    44,    44,    44,    44,    44,   -65,
     -65,   -65,   -65,   -65,    -3,    -3,    39,    39,    39,     0,
      47,    47,   -65,   -65,    93,    93,    93,    93,    93,    93,
      31,    31,    47,   -65,   -65,   -65,    37,    46,   -65,   -65,
      31,   -65
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,    10,    11,     0,     0,     3,     4,
       0,     5,     0,     0,     0,     9,     0,     0,    21,    28,
       0,     0,    22,     0,    22,     0,     0,     0,     7,    19,
      22,     0,     0,     0,     0,     0,     0,    12,     0,     0,
       0,     0,    13,     0,     0,     0,     0,     0,     0,    35,
      40,     8,     6,    20,    14,    15,    17,    18,    16,     0,
      23,    24,    25,    26,    29,    30,    31,    32,    33,    34,
       0,     0,    27,     2,    36,    41,     0,     0,    39,    37,
       0,    38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -65,     1,   -65,    34,    48,   -65,   -65,   -11,   -12,    63,
     -65,   -65,   -65,   -64,   -65
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     8,     9,    16,    10,    11,    23,    24,    25,
      70,    77,    80,    74,    71
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      22,    21,    34,    35,    59,    30,    29,    75,    12,    31,
       4,     5,    32,    33,    34,    35,    81,    13,    36,    19,
      14,    54,    55,    56,    57,    58,    60,    61,    62,    63,
      36,    37,    64,    65,    66,    67,    68,    69,    32,    33,
      34,    35,    27,    15,     3,     4,     5,    72,    17,    28,
      49,    18,    40,    41,     6,    50,    36,     7,    73,     2,
      36,    53,    52,    19,    79,    78,     3,     4,     5,    20,
      38,    39,    40,    41,    76,    51,     6,    26,     0,     7,
       0,     0,    32,    33,    34,    35,     0,     0,     0,    42,
      43,    44,    45,    46,    47,    48,    32,    33,    34,    35,
      36,    38,    39,    40,    41,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    36
};

static const yytype_int8 yycheck[] =
{
      12,    12,     5,     6,     4,    17,    17,    71,    24,    20,
       8,     9,     3,     4,     5,     6,    80,    25,    21,    19,
      25,    32,    33,    34,    35,    36,    38,    39,    40,    41,
      21,    22,    43,    44,    45,    46,    47,    48,     3,     4,
       5,     6,    23,     7,     7,     8,     9,    59,     4,    22,
      26,     7,     5,     6,    17,    26,    21,    20,    27,     0,
      21,    26,    28,    19,    18,    28,     7,     8,     9,    25,
       3,     4,     5,     6,    73,    27,    17,    14,    -1,    20,
      -1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,    22,
      11,    12,    13,    14,    15,    16,     3,     4,     5,     6,
      21,     3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    30,     0,     7,     8,     9,    17,    20,    31,    32,
      34,    35,    24,    25,    25,     7,    33,     4,     7,    19,
      25,    36,    37,    36,    37,    38,    38,    23,    22,    36,
      37,    36,     3,     4,     5,     6,    21,    22,     3,     4,
       5,     6,    22,    11,    12,    13,    14,    15,    16,    26,
      26,    33,    32,    26,    36,    36,    36,    36,    36,     4,
      37,    37,    37,    37,    36,    36,    36,    36,    36,    36,
      39,    43,    37,    27,    42,    42,    30,    40,    28,    18,
      41,    42
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    29,    30,    30,    31,    31,    32,    32,    33,    33,
      34,    34,    35,    35,    36,    36,    36,    36,    36,    36,
      36,    36,    36,    37,    37,    37,    37,    37,    37,    38,
      38,    38,    38,    38,    38,    39,    40,    41,    35,    42,
      43,    35
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     4,     0,     3,     1,
       1,     1,     4,     4,     3,     3,     3,     3,     3,     2,
       3,     1,     1,     3,     3,     3,     3,     2,     1,     3,
       3,     3,     3,     3,     3,     0,     0,     0,    10,     3,
       0,     6
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
        yyerror (YY_("syntax error: cannot back up")); \
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
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
                 int yyrule)
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
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
yyparse (void)
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
  case 12: /* S: ID '=' E ';'  */
#line 84 "yacc.y"
                 { fprintf(inter,"%s := %s\n",(yyvsp[-3].addr),(yyvsp[-1].addr)); 

fprintf(assembly,"MOV %s,%s\n",(yyvsp[-3].addr),(yyvsp[-1].addr));
}
#line 1289 "y.tab.c"
    break;

  case 13: /* S: ID '=' NUM_E ';'  */
#line 88 "yacc.y"
                     { fprintf(inter,"%s := %d\n",(yyvsp[-3].addr),(yyvsp[-1].intval)); 
  fprintf(assembly,"MOV %s,#%d\n",(yyvsp[-3].addr),(yyvsp[-1].intval));
}
#line 1297 "y.tab.c"
    break;

  case 14: /* E: E '+' E  */
#line 93 "yacc.y"
            { 
  (yyval.addr) = createTemp();
  
  if(!strcmp((yyvsp[-2].addr),"0"))
  {
      fprintf(inter,"%s := %s\n",(yyval.addr),(yyvsp[0].addr)); 
      char* temp = createRegister();
      fprintf(assembly,"MOV %s,%s\n",temp,(yyvsp[0].addr));
      fprintf(assembly,"MOV %s,%s\n",(yyval.addr),temp);
  }
  else if(!strcmp((yyvsp[0].addr),"0"))
  {
  	fprintf(inter,"%s := %s\n",(yyval.addr),(yyvsp[-2].addr)); 
  	
      char* temp = createRegister();
      fprintf(assembly,"MOV %s,%s\n",temp,(yyvsp[-2].addr));
      fprintf(assembly,"MOV %s,%s\n",(yyval.addr),temp);
  }
  else
    {
      char* temp1 = createRegister();
      char* temp2 = createRegister();
      fprintf(inter,"%s := %s + %s\n",(yyval.addr),(yyvsp[-2].addr),(yyvsp[0].addr)); 
      fprintf(assembly,"MOV %s,%s\n",temp1,(yyvsp[-2].addr));
      fprintf(assembly,"MOV %s,%s\n",temp2,(yyvsp[0].addr));
      fprintf(assembly,"ADD %s,%s\n",temp1,temp2);
      fprintf(assembly,"MOV %s,%s\n",(yyval.addr),temp1);
    }

  
 
  }
#line 1334 "y.tab.c"
    break;

  case 15: /* E: E '-' E  */
#line 126 "yacc.y"
            { 
  (yyval.addr) = createTemp();
  fprintf(inter,"%s := %s - %s\n",(yyval.addr),(yyvsp[-2].addr),(yyvsp[0].addr)); 
  
      char* temp1 = createRegister();
      char* temp2 = createRegister();
      fprintf(assembly,"MOV %s,%s\n",temp1,(yyvsp[-2].addr));
      fprintf(assembly,"MOV %s,%s\n",temp2,(yyvsp[0].addr));
      fprintf(assembly,"SUB %s,%s\n",temp1,temp2);
      fprintf(assembly,"MOV %s,%s\n",(yyval.addr),temp1);
  }
#line 1350 "y.tab.c"
    break;

  case 16: /* E: E STAR_STAR E  */
#line 138 "yacc.y"
                   {  
      (yyval.addr) = createTemp();
      
      
      char* temp1 = createRegister();
     
      truelabel = createLabel();
      nextlabel = createLabel();
      char* temp2 = createTemp();
      fprintf(inter,"%s := %s\n",(yyval.addr),(yyvsp[-2].addr)); 
      fprintf(inter,"%s := %s\n",temp2,(yyvsp[0].addr)); 
 
      fprintf(inter,"%s:\n",truelabel);
      fprintf(inter,"if_false %s == 0 goto %s \n",temp2,nextlabel); 
      fprintf(inter,"%s := %s * %s \n",(yyval.addr),(yyval.addr),(yyvsp[-2].addr)); 
      fprintf(inter,"%s := %s - 1 \n",temp2,temp2); 
      fprintf(inter,"goto %s \n",truelabel); 
      fprintf(inter,"%s: \n",nextlabel); 
      
      
      fprintf(assembly,"MOV %s,%s\n",temp1,(yyvsp[0].addr));
      fprintf(assembly,"MOV %s,%s\n",(yyval.addr),(yyvsp[-2].addr));
      fprintf(assembly,"%s:\n",truelabel);
      fprintf(assembly,"CMP %s,#0\n",temp1);
      fprintf(assembly,"JZ %s\n",nextlabel);
      fprintf(assembly,"MUL %s,%s\n",(yyval.addr),(yyvsp[-2].addr));
      fprintf(assembly,"SUB %s,#1\n",temp1);
      fprintf(assembly,"JMP %s\n",truelabel);
      fprintf(assembly,"%s:\n",nextlabel);
  }
#line 1385 "y.tab.c"
    break;

  case 17: /* E: E '*' E  */
#line 169 "yacc.y"
            { 
  (yyval.addr) = createTemp();
  
   if(!strcmp((yyvsp[-2].addr),"1"))
  {
      fprintf(inter,"%s := %s\n",(yyval.addr),(yyvsp[0].addr)); 
      char* temp = createRegister();
      fprintf(assembly,"MOV %s,%s\n",temp,(yyvsp[0].addr));
      fprintf(assembly,"MOV %s,%s\n",(yyval.addr),temp);
  }
  else if(!strcmp((yyvsp[0].addr),"1"))
  {
      fprintf(inter,"%s := %s\n",(yyval.addr),(yyvsp[-2].addr)); 
      char* temp = createRegister();
      fprintf(assembly,"MOV %s,%s\n",temp,(yyvsp[-2].addr));
      fprintf(assembly,"MOV %s,%s\n",(yyval.addr),temp);
  }
  else{
      char* temp1 = createRegister();
      char* temp2 = createRegister();
        fprintf(inter,"%s := %s * %s\n",(yyval.addr),(yyvsp[-2].addr),(yyvsp[0].addr)); 
      fprintf(assembly,"MOV %s,%s\n",temp1,(yyvsp[-2].addr));
      fprintf(assembly,"MOV %s,%s\n",temp2,(yyvsp[0].addr));
      fprintf(assembly,"MUL %s,%s\n",temp1,temp2);
      fprintf(assembly,"MOV %s,%s\n",(yyval.addr),temp1);
  
  }
  

  
  
  }
#line 1422 "y.tab.c"
    break;

  case 18: /* E: E '/' E  */
#line 201 "yacc.y"
            { 
  (yyval.addr) = createTemp();
  fprintf(inter,"%s := %s / %s\n",(yyval.addr),(yyvsp[-2].addr),(yyvsp[0].addr)); 
  
     char* temp1 = createRegister();
      char* temp2 = createRegister();
      fprintf(assembly,"MOV %s,%s\n",temp1,(yyvsp[-2].addr));
      fprintf(assembly,"MOV %s,%s\n",temp2,(yyvsp[0].addr));
      fprintf(assembly,"DIV %s,%s\n",temp1,temp2);
      fprintf(assembly,"MOV %s,%s\n",(yyval.addr),temp1);
      
  }
#line 1439 "y.tab.c"
    break;

  case 19: /* E: '-' E  */
#line 213 "yacc.y"
                       { 
  (yyval.addr) = createTemp();
  fprintf(inter,"%s := - %s\n",(yyval.addr),(yyvsp[0].addr)); 
  
      char* temp1 = createRegister();
      char* temp2 = createRegister();
      fprintf(assembly,"MOV %s,%s\n",temp1,(yyvsp[0].addr));
      fprintf(assembly,"NOT %s\n",temp1);
      fprintf(assembly,"ADD %s,#1\n",temp1);
      fprintf(assembly,"MOV %s,%s\n",(yyval.addr),temp1);
  
  }
#line 1456 "y.tab.c"
    break;

  case 20: /* E: '(' E ')'  */
#line 225 "yacc.y"
              {  (yyval.addr) = createTemp();    fprintf(inter,"%s := %s\n",(yyval.addr),(yyvsp[-1].addr));   
  char* temp1 = createRegister();
  fprintf(assembly,"MOV %s,%s\n",temp1,(yyvsp[-1].addr));
  fprintf(assembly,"MOV %s,%s\n",(yyval.addr),temp1);
  
  
  
  
  
  }
#line 1471 "y.tab.c"
    break;

  case 21: /* E: ID  */
#line 235 "yacc.y"
       { (yyval.addr) = strdup((yyvsp[0].addr)); }
#line 1477 "y.tab.c"
    break;

  case 22: /* E: NUM_E  */
#line 236 "yacc.y"
          {
  	(yyval.addr) = malloc(10);
  	sprintf((yyval.addr),"%d",(yyvsp[0].intval));
  }
#line 1486 "y.tab.c"
    break;

  case 23: /* NUM_E: NUM_E '+' NUM_E  */
#line 242 "yacc.y"
                         { (yyval.intval) = (yyvsp[-2].intval) + (yyvsp[0].intval); }
#line 1492 "y.tab.c"
    break;

  case 24: /* NUM_E: NUM_E '-' NUM_E  */
#line 243 "yacc.y"
                         { (yyval.intval) = (yyvsp[-2].intval) - (yyvsp[0].intval); }
#line 1498 "y.tab.c"
    break;

  case 25: /* NUM_E: NUM_E '*' NUM_E  */
#line 244 "yacc.y"
                         { (yyval.intval) = (yyvsp[-2].intval) * (yyvsp[0].intval); }
#line 1504 "y.tab.c"
    break;

  case 26: /* NUM_E: NUM_E '/' NUM_E  */
#line 245 "yacc.y"
                         { (yyval.intval) = (yyvsp[-2].intval) / (yyvsp[0].intval); }
#line 1510 "y.tab.c"
    break;

  case 27: /* NUM_E: '-' NUM_E  */
#line 246 "yacc.y"
                   { (yyval.intval) = -(yyvsp[0].intval); }
#line 1516 "y.tab.c"
    break;

  case 28: /* NUM_E: NUM  */
#line 247 "yacc.y"
             {(yyval.intval) = (yyvsp[0].intval); }
#line 1522 "y.tab.c"
    break;

  case 29: /* REL_E: E REL_LT E  */
#line 250 "yacc.y"
                    { 
  (yyval.addr) = createTemp();
  fprintf(inter,"%s := %s %s %s\n",(yyval.addr),(yyvsp[-2].addr),(yyvsp[-1].addr),(yyvsp[0].addr));
  conds.operand1 = strdup((yyvsp[-2].addr));
  conds.operator = strdup((yyvsp[-1].addr));
  conds.operand2 = strdup((yyvsp[0].addr));
  }
#line 1534 "y.tab.c"
    break;

  case 30: /* REL_E: E REL_LTEQ E  */
#line 257 "yacc.y"
                 {
  (yyval.addr) = createTemp(); fprintf(inter,"%s := %s %s %s\n",(yyval.addr),(yyvsp[-2].addr),(yyvsp[-1].addr),(yyvsp[0].addr)); 
  conds.operand1 = strdup((yyvsp[-2].addr));
  conds.operator = strdup((yyvsp[-1].addr));
  conds.operand2 = strdup((yyvsp[0].addr));
  }
#line 1545 "y.tab.c"
    break;

  case 31: /* REL_E: E REL_EQ E  */
#line 263 "yacc.y"
               { 
  (yyval.addr) = createTemp(); fprintf(inter,"%s := %s %s %s\n",(yyval.addr),(yyvsp[-2].addr),(yyvsp[-1].addr),(yyvsp[0].addr)); 
  conds.operand1 = strdup((yyvsp[-2].addr));
  conds.operator = strdup((yyvsp[-1].addr));
  conds.operand2 = strdup((yyvsp[0].addr));
  }
#line 1556 "y.tab.c"
    break;

  case 32: /* REL_E: E REL_NEQ E  */
#line 269 "yacc.y"
                { 
  (yyval.addr) = createTemp();
  fprintf(inter,"%s := %s %s %s\n",(yyval.addr),(yyvsp[-2].addr),(yyvsp[-1].addr),(yyvsp[0].addr));
  conds.operand1 = strdup((yyvsp[-2].addr));
  conds.operator = strdup((yyvsp[-1].addr));
  conds.operand2 = strdup((yyvsp[0].addr));
  }
#line 1568 "y.tab.c"
    break;

  case 33: /* REL_E: E REL_GT E  */
#line 276 "yacc.y"
               { (yyval.addr) = createTemp();
  fprintf(inter,"%s := %s %s %s\n",(yyval.addr),(yyvsp[-2].addr),(yyvsp[-1].addr),(yyvsp[0].addr)); 
  conds.operand1 = strdup((yyvsp[-2].addr));
  conds.operator = strdup((yyvsp[-1].addr));
  conds.operand2 = strdup((yyvsp[0].addr));
  }
#line 1579 "y.tab.c"
    break;

  case 34: /* REL_E: E REL_GTEQ E  */
#line 282 "yacc.y"
                 { (yyval.addr) = createTemp(); 
  fprintf(inter,"%s := %s %s %s\n",(yyval.addr),(yyvsp[-2].addr),(yyvsp[-1].addr),(yyvsp[0].addr));
  conds.operand1 = strdup((yyvsp[-2].addr));
  conds.operator = strdup((yyvsp[-1].addr));
  conds.operand2 = strdup((yyvsp[0].addr));
  
  }
#line 1591 "y.tab.c"
    break;

  case 35: /* $@1: %empty  */
#line 290 "yacc.y"
                     {
 		truelabel = createLabel();
 		falselabel = createLabel();
		nextlabel = createLabel();
		fprintf(inter, "if_false %s %s %s goto %s\n", conds.operand1,conds.operator,conds.operand2, nextlabel); 
		fprintf(assembly, "CMP %s,%s\n", conds.operand1, conds.operand2);
		if (!strcmp(conds.operator,"<"))
		 {
		    fprintf(assembly, "JG %s\n",falselabel);
		 }
		 else if (!strcmp(conds.operator,"<="))
		 {
		    fprintf(assembly, "JGE %s\n",falselabel);
		 }
		 else if (!strcmp(conds.operator,"=="))
		 {
		    fprintf(assembly, "JNE %s\n",falselabel);
		 }
		 else if (!strcmp(conds.operator,"!="))
		 {
		    fprintf(assembly, "JE %s\n",falselabel);
		 }
		 else if (!strcmp(conds.operator,">"))
		 {
		    fprintf(assembly, "JL %s\n",falselabel);
		 }
		 else if (!strcmp(conds.operator,">="))
		 {
		    fprintf(assembly, "JLE %s\n",falselabel);
		 }
		
		
		}
#line 1629 "y.tab.c"
    break;

  case 36: /* $@2: %empty  */
#line 323 "yacc.y"
         {
		fprintf(inter, "goto %s\n", nextlabel);
		 fprintf(assembly, "JMP %s\n",nextlabel);

            }
#line 1639 "y.tab.c"
    break;

  case 37: /* $@3: %empty  */
#line 328 "yacc.y"
           {
         	fprintf(inter, "%s:\n", falselabel); 
         	fprintf(assembly, "%s:\n",falselabel);
          }
#line 1648 "y.tab.c"
    break;

  case 38: /* S: IF '(' REL_E ')' $@1 BLOCK $@2 ELSE $@3 BLOCK  */
#line 333 "yacc.y"
         {
         	fprintf(inter, "%s:\n", nextlabel);
         	fprintf(assembly, "%s:\n", nextlabel); 
          }
#line 1657 "y.tab.c"
    break;

  case 40: /* $@4: %empty  */
#line 344 "yacc.y"
                        {  		
		truelabel = createLabel();
		nextlabel = createLabel();
		fprintf(inter, "%s:\n", truelabel); 
		fprintf(inter, "if_false %s %s %s goto %s\n", conds.operand1,conds.operator,conds.operand2, nextlabel); 
		fprintf(assembly, "%s:\n", truelabel);
		fprintf(assembly, "CMP %s,%s\n", conds.operand1, conds.operand2);
		if (!strcmp(conds.operator,"<"))
		 {
		    fprintf(assembly, "JG %s\n",nextlabel);
		 }
		 else if (!strcmp(conds.operator,"<="))
		 {
		    fprintf(assembly, "JGE %s\n",nextlabel);
		 }
		 else if (!strcmp(conds.operator,"=="))
		 {
		    fprintf(assembly, "JNE %s\n",nextlabel);
		 }
		 else if (!strcmp(conds.operator,"!="))
		 {
		    fprintf(assembly, "JE %s\n",nextlabel);
		 }
		 else if (!strcmp(conds.operator,">"))
		 {
		    fprintf(assembly, "JL %s\n",nextlabel);
		 }
		 else if (!strcmp(conds.operator,">="))
		 {
		    fprintf(assembly, "JLE %s\n",nextlabel);
		 }
		
		
		
		}
#line 1697 "y.tab.c"
    break;

  case 41: /* S: WHILE '(' REL_E ')' $@4 BLOCK  */
#line 380 "yacc.y"
         {
         	fprintf(inter, "goto %s\n",truelabel); 
         	fprintf(inter, "%s:\n",nextlabel); 
         	
         	fprintf(assembly, "JMP %s\n",truelabel); 
         	fprintf(assembly, "%s:\n",nextlabel); 
         }
#line 1709 "y.tab.c"
    break;


#line 1713 "y.tab.c"

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
      yyerror (YY_("syntax error"));
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 392 "yacc.y"



int yyerror(char *s)
{
	printf("********** INCORRECT **********");
	exit(1);

}


int main(int argc, char **argv)
{
	yyin = fopen(argv[1], "r");
	inter = fopen("intermediate.i","a+");
	assembly = fopen("assembly.s","a+");
	
	if(!yyin)
	{
		fprintf(stderr, "Can't open source code.");
		exit(1);
	}

	if(yyparse() == 0)
	{
		printf("********** CORRECT **********");
	}
	
	
	fclose(yyin);
	fclose(inter);
	fclose(assembly);
	return 0;
}
