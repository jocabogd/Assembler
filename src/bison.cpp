/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "src/parser.y"

	
	#include <iostream>
	using namespace std;
	#include <vector>
	#include <string>
	#include <cstdio>
	
	#include "code.h"
	extern Code code;
	
	extern int yylex();
	extern int yyparse();
	extern FILE* yyin;
	
	void yyerror(const char* msg);
	
	extern int line_num;
	extern int first_pass;
	
	vector<string> symbol_list;
	
	short lc = 0;

	bool gloex = true;	// da li je global ili extern -> nisam koristila na kraju
	
	bool symlit;
	typedef struct sym_lit {
		string symbol;
		int literal;
	} sym_lit;
	sym_lit sl;
	vector<sym_lit> symlit_list;

	string instrukcija = "";
	string adresiranje = "";
	short val = 0x00;
	string symb = "";
	short regg = 0x00;


#line 112 "src/bison.cpp"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_INC_BISON_HPP_INCLUDED
# define YY_YY_INC_BISON_HPP_INCLUDED
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
    GLOBAL = 258,
    EXTERN = 259,
    SECTION = 260,
    WORD = 261,
    SKIP = 262,
    EQU = 263,
    END = 264,
    HALT = 265,
    INT = 266,
    IRET = 267,
    CALL = 268,
    RET = 269,
    JMP = 270,
    JEQ = 271,
    JNE = 272,
    JGT = 273,
    PUSH = 274,
    POP = 275,
    XCHG = 276,
    ADD = 277,
    SUB = 278,
    MUL = 279,
    DIV = 280,
    CMP = 281,
    NOT = 282,
    AND = 283,
    OR = 284,
    XOR = 285,
    TEST = 286,
    SHL = 287,
    SHR = 288,
    LDR = 289,
    STR = 290,
    REG = 291,
    NUMBER = 292,
    SYMBOL = 293,
    PLUS = 294,
    MINUS = 295,
    MULTIPLY = 296,
    DIVIDE = 297,
    MOD = 298,
    COLON = 299,
    COMMA = 300,
    DOLLAR = 301,
    LBRACKET = 302,
    RBRACKET = 303,
    LPAREN = 304,
    RPAREN = 305
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 44 "src/parser.y"

	int ival;
	char* sval;
	long long lval;

#line 221 "src/bison.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INC_BISON_HPP_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  59
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   132

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  109

#define YYUNDEFTOK  2
#define YYMAXUTOK   305


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    65,    65,    66,    68,    71,    72,    74,    94,    95,
     112,   113,   120,   214,   223,   229,   236,   243,   250,   257,
     265,   270,   275,   280,   285,   291,   297,   303,   309,   315,
     321,   327,   333,   339,   345,   351,   357,   364,   369,   375,
     386,   407,   429,   439,   460,   468,   476,   486,   508,   516,
     524,   532,   540,   548,   556,   564,   573,   583,   600,   611,
     634,   664,   673,   690,   701,   707,   713,   717,   721,   725,
     730,   731,   732
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "GLOBAL", "EXTERN", "SECTION", "WORD",
  "SKIP", "EQU", "END", "HALT", "INT", "IRET", "CALL", "RET", "JMP", "JEQ",
  "JNE", "JGT", "PUSH", "POP", "XCHG", "ADD", "SUB", "MUL", "DIV", "CMP",
  "NOT", "AND", "OR", "XOR", "TEST", "SHL", "SHR", "LDR", "STR", "REG",
  "NUMBER", "SYMBOL", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "MOD",
  "COLON", "COMMA", "DOLLAR", "LBRACKET", "RBRACKET", "LPAREN", "RPAREN",
  "$accept", "Program", "Line", "Label", "Instruction", "InstrWithoutReg",
  "InstrWithReg", "InstrOperand", "InstrRegs", "InstrRegOp", "OperandJump",
  "Operand", "Directive", "SymbolList", "SymbolLiteralList",
  "SymbolLiteral", "Literal", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

#define YYPACT_NINF (-38)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      94,   -37,   -37,   -30,   -15,    13,   -29,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,   -12,    34,    94,   -38,   -38,   -38,
      -1,   -10,    15,    18,   -38,    -8,   -38,   -38,   -38,   -38,
     -38,    19,    20,   -38,    10,   -38,   -38,    14,   -38,   -38,
     -38,   -38,   -38,   -21,    22,   -38,   -38,    16,    17,   -37,
     -38,   -38,   -15,    13,   -38,   -38,    27,   -38,   -38,    28,
     -33,   -38,   -38,   -38,   -28,   -38,   -38,   -38,    29,     1,
      30,   -38,   -38,     5,   -38,   -38,   -38,   -38,   -27,    23,
      24,     9,   -38,   -38,   -38,    25,    26,   -38,   -38
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    63,    13,    16,
      14,    20,    15,    21,    22,    23,    24,    17,    18,    25,
      26,    27,    28,    29,    30,    19,    31,    32,    33,    34,
      35,    36,    37,    38,     0,     0,     2,     4,     5,     8,
       0,     0,     0,     0,     6,    64,    57,    58,    59,    70,
      68,     0,     0,    60,    66,    69,    61,     0,     7,     1,
       3,     9,    40,     0,     0,    10,    39,     0,     0,     0,
      71,    72,     0,     0,    44,    43,     0,    42,    41,     0,
       0,    65,    67,    62,     0,    11,    53,    51,     0,     0,
       0,    12,    50,     0,    45,    52,    49,    48,     0,     0,
       0,     0,    54,    47,    46,     0,     0,    56,    55
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -38,    40,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,     0,    -7,   -38,    -5
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      65,    91,    44,    46,    53,    54,    55
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      56,    45,    47,    86,    49,    87,    51,    52,    48,    57,
      88,    93,   101,    89,    90,    74,    49,    75,    51,    52,
      94,   102,    49,    50,    51,    52,    76,    49,    62,    51,
      52,    63,    58,    64,    59,    61,    66,    69,    49,    96,
      51,    52,    49,    99,    51,    52,    49,   105,    51,    52,
      49,    67,    51,    52,    68,    72,    70,    71,    77,    73,
      78,    79,    80,    84,    85,    82,    98,    95,    83,    81,
       0,   103,   104,   107,   108,    92,    60,     0,     0,     0,
       0,     0,     0,     0,    97,     0,     0,     0,   100,     0,
       0,     0,     0,     0,     0,     0,   106,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       0,     0,    34
};

static const yytype_int8 yycheck[] =
{
       5,    38,     2,    36,    37,    38,    39,    40,    38,    38,
      43,    39,    39,    46,    47,    36,    37,    38,    39,    40,
      48,    48,    37,    38,    39,    40,    47,    37,    38,    39,
      40,    41,    44,    43,     0,    36,    41,    45,    37,    38,
      39,    40,    37,    38,    39,    40,    37,    38,    39,    40,
      37,    36,    39,    40,    36,    45,    37,    37,    63,    45,
      38,    45,    45,    36,    36,    72,    36,    38,    73,    69,
      -1,    48,    48,    48,    48,    80,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,    93,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   101,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    38,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    63,    38,    64,    64,    38,    37,
      38,    39,    40,    65,    66,    67,    67,    38,    44,     0,
      52,    36,    38,    41,    43,    61,    67,    36,    36,    45,
      37,    37,    45,    45,    36,    38,    47,    67,    38,    45,
      45,    64,    65,    67,    36,    36,    36,    38,    43,    46,
      47,    62,    67,    39,    48,    38,    38,    67,    36,    38,
      67,    39,    48,    48,    48,    38,    67,    48,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    52,    53,    53,    53,    54,    55,    55,
      55,    55,    55,    56,    56,    56,    57,    57,    57,    57,
      58,    58,    58,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    60,    60,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    63,    63,    63,
      63,    63,    63,    63,    64,    64,    65,    65,    66,    66,
      67,    67,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     2,     1,     2,
       2,     4,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     4,     6,     6,     2,     2,
       1,     1,     2,     1,     3,     5,     5,     2,     2,     2,
       2,     2,     4,     1,     1,     3,     1,     3,     1,     1,
       1,     2,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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
  case 7:
#line 74 "src/parser.y"
                    {
			// odmah se umece labela u tabelu simbola
			if (first_pass == 1) {
				if (code.table_symbol.find((yyvsp[-1].sval)) != code.table_symbol.end()) {
					// cout << "zasto ne ovde?" << endl;
					if (code.table_symbol[(yyvsp[-1].sval)].prom == GLOBALNA && 
						code.table_symbol[(yyvsp[-1].sval)].section == "undefined") {
						code.table_symbol[(yyvsp[-1].sval)].section = code.current_section;
						code.table_symbol[(yyvsp[-1].sval)].offset = lc;
					} else {
						cout << "Greska na liniji: " << line_num << ". Simbol: " << (yyvsp[-1].sval) << " je vec u tabeli." << endl;
        				exit(-2);
					}
				} else {
					// cout << "zasto ovde?" << endl;
					code.addSymbol((yyvsp[-1].sval), code.current_section, lc, LOKALNA);
				}
			}
		}
#line 1498 "src/bison.cpp"
    break;

  case 9:
#line 95 "src/parser.y"
                                           {
				if (first_pass == 0) {
					short reg = (yyvsp[0].ival) << 4;
					short sp = 0x06;
					if (instrukcija == "int") {
						code.addByteToCode(reg | 0x0f);
					} else if (instrukcija == "push") {
						code.addByteToCode(reg | sp);
						code.addByteToCode((0x01 << 4) | 0x02);
					} else if (instrukcija == "pop") {
						code.addByteToCode(reg | sp);
						code.addByteToCode((0x04 << 4) | 0x02);
					} else if (instrukcija == "not") {
						code.addByteToCode(reg | 0x0f);
					}
				}
			}
#line 1520 "src/bison.cpp"
    break;

  case 11:
#line 113 "src/parser.y"
                                                  {
				if (first_pass == 0) {
					short regD = (yyvsp[-2].ival) << 4;
					short regS = (yyvsp[0].ival);
					code.addByteToCode(regD | regS);
				}
			}
#line 1532 "src/bison.cpp"
    break;

  case 12:
#line 120 "src/parser.y"
                                                       {
				short regD = (yyvsp[-2].ival) << 4;
				if (first_pass == 0) {
					if (adresiranje == "immedL") {
						code.addByteToCode(regD | 0x0f);
						code.addByteToCode(0x00);
						code.addByteToCode((val >> 8) & 0xff);
						code.addByteToCode(val & 0x00ff);
					} else if (adresiranje == "immedS") {
						code.addByteToCode(regD | 0x0f);
						code.addByteToCode(0x00);
						// relokacioni zapis
						code.current_relocation = {code.current_section, code.current_section, (short)((int)lc-2), "R_X86_64_32", symb, 0};
						if (code.table_symbol.find(symb) != code.table_symbol.end()) {
							if (code.table_symbol[symb].section == "absolute") {
								code.addByteToCode((code.table_symbol[symb].offset >> 8) & 0xff);
								code.addByteToCode(code.table_symbol[symb].offset & 0x00ff);
							} else {
								code.addRelocation(code.current_relocation);
							} 
						} else {
							code.addSymbol(symb, "undefined", (short)((int)lc-2), GLOBALNA);
							code.addRelocation(code.current_relocation);
						}
					} else if (adresiranje == "memL") {
						code.addByteToCode(regD | 0x0f);
						code.addByteToCode(0x04);
						code.addByteToCode((val >> 8) & 0xff);
						code.addByteToCode(val & 0x00ff);
					} else if (adresiranje == "memS") {
						code.addByteToCode(regD | 0x0f);
						code.addByteToCode(0x04);
						// relokacioni zapis
						cout << "ovde 1: " << symb << " i " << lc << endl;
						code.current_relocation = {code.current_section, code.current_section, (short)((int)lc-2), "R_X86_64_32", symb, 0};
						if (code.table_symbol.find(symb) != code.table_symbol.end()) {
							if (code.table_symbol[symb].section == "absolute") {
								code.addByteToCode((code.table_symbol[symb].offset >> 8) & 0xff);
								code.addByteToCode(code.table_symbol[symb].offset & 0x00ff);
							} else {
								code.addRelocation(code.current_relocation);
							} 
						} else {
							code.addSymbol(symb, "undefined", (short)((int)lc-2), GLOBALNA);
							code.addRelocation(code.current_relocation);
						}
					} else if (adresiranje == "pcrel") {
						short pc = 0x07;
						code.addByteToCode(regD | pc);
						code.addByteToCode(0x03);
						// relokacioni zapis
						code.current_relocation = {code.current_section, code.current_section, (short)((int)lc-2), "R_X86_64_PC32", symb, -2};
						if (code.table_symbol.find(symb) != code.table_symbol.end()) {
							if (code.table_symbol[symb].section == "absolute") {
								code.addByteToCode((code.table_symbol[symb].offset >> 8) & 0xff);
								code.addByteToCode(code.table_symbol[symb].offset & 0x00ff);
							} else {
								code.addRelocation(code.current_relocation);
							} 
						} else {
							code.addSymbol(symb, "undefined", (short)((int)lc-2), GLOBALNA);
							code.addRelocation(code.current_relocation);
						}
					} else if (adresiranje == "regdir") {
						code.addByteToCode(regD | regg);
						code.addByteToCode(0x01);
					} else if (adresiranje == "regind") {
						code.addByteToCode(regD | regg);
						code.addByteToCode(0x02);
					} else if (adresiranje == "regindpomL") {
						code.addByteToCode(regD | regg);
						code.addByteToCode(0x03);
						code.addByteToCode((val >> 8) & 0xff);
						code.addByteToCode(val & 0x00ff);
					} else if (adresiranje == "regindpomS") {
						code.addByteToCode(regD | regg);
						code.addByteToCode(0x03);
						// relokacioni zapis
						code.current_relocation = {code.current_section, code.current_section, (short)((int)lc-2), "R_X86_64_32", symb, 0};
						if (code.table_symbol.find(symb) != code.table_symbol.end()) {
							if (code.table_symbol[symb].section == "absolute") {
								code.addByteToCode((code.table_symbol[symb].offset >> 8) & 0xff);
								code.addByteToCode(code.table_symbol[symb].offset & 0x00ff);
							} else {
								code.addRelocation(code.current_relocation);
							} 
						} else {
							code.addSymbol(symb, "undefined", (short)((int)lc-2), GLOBALNA);
							code.addRelocation(code.current_relocation);
						}
					}
				}
			}
#line 1630 "src/bison.cpp"
    break;

  case 13:
#line 214 "src/parser.y"
                      {
					if (first_pass == 0) {
						//cout << "jesam li ovde?" << endl;
						code.addByteToCode(0x00);
						//code.current_code.push_back(0x00);
						//cout << code.current_code.length() << endl;
					}
					lc += 1;
				}
#line 1644 "src/bison.cpp"
    break;

  case 14:
#line 223 "src/parser.y"
                                       {
					if (first_pass == 0) {
						code.addByteToCode(0x20);
					}
					lc += 1;
				}
#line 1655 "src/bison.cpp"
    break;

  case 15:
#line 229 "src/parser.y"
                                      {
					if (first_pass == 0) {
						code.addByteToCode(0x40);
					}
					lc += 1;
				}
#line 1666 "src/bison.cpp"
    break;

  case 16:
#line 236 "src/parser.y"
                  {
				if (first_pass == 0) {
					instrukcija = "int";
					code.addByteToCode(0x10);
				}
				lc += 2;
			}
#line 1678 "src/bison.cpp"
    break;

  case 17:
#line 243 "src/parser.y"
                               {
				if (first_pass == 0) {
					instrukcija = "push";
					code.addByteToCode(0xb0);	
				}
				lc += 3;
			}
#line 1690 "src/bison.cpp"
    break;

  case 18:
#line 250 "src/parser.y"
                              {
				if (first_pass == 0) {
					instrukcija = "pop";
					code.addByteToCode(0xa0);	
				}
				lc += 3;
			}
#line 1702 "src/bison.cpp"
    break;

  case 19:
#line 257 "src/parser.y"
                              {
				if (first_pass == 0) {
					instrukcija = "not";
					code.addByteToCode(0x80);
				}
				lc += 2;
			}
#line 1714 "src/bison.cpp"
    break;

  case 20:
#line 265 "src/parser.y"
                   {
				if (first_pass == 0) {
					code.addByteToCode(0x30);
				}
			}
#line 1724 "src/bison.cpp"
    break;

  case 21:
#line 270 "src/parser.y"
                              {
				if (first_pass == 0) {
					code.addByteToCode(0x50);
				}
			}
#line 1734 "src/bison.cpp"
    break;

  case 22:
#line 275 "src/parser.y"
                              {
				if (first_pass == 0) {
					code.addByteToCode(0x51);
				}
			}
#line 1744 "src/bison.cpp"
    break;

  case 23:
#line 280 "src/parser.y"
                              {
				if (first_pass == 0) {
					code.addByteToCode(0x52);
				}
			}
#line 1754 "src/bison.cpp"
    break;

  case 24:
#line 285 "src/parser.y"
                              {
				if (first_pass == 0) {
					code.addByteToCode(0x53);
				}
			}
#line 1764 "src/bison.cpp"
    break;

  case 25:
#line 291 "src/parser.y"
                {
				if (first_pass == 0) {
					code.addByteToCode(0x60);
				}
				lc += 2;
			}
#line 1775 "src/bison.cpp"
    break;

  case 26:
#line 297 "src/parser.y"
                       {
			if (first_pass == 0) {
				code.addByteToCode(0x70);
			}
			lc += 2;
		 }
#line 1786 "src/bison.cpp"
    break;

  case 27:
#line 303 "src/parser.y"
                       {
			if (first_pass == 0) {
				code.addByteToCode(0x71);
			}
			lc += 2;
		 }
#line 1797 "src/bison.cpp"
    break;

  case 28:
#line 309 "src/parser.y"
                       {
			if (first_pass == 0) {
				code.addByteToCode(0x72);
			}
			lc += 2;
		 }
#line 1808 "src/bison.cpp"
    break;

  case 29:
#line 315 "src/parser.y"
                       {
			if (first_pass == 0) {
				code.addByteToCode(0x73);
			}
			lc += 2;
		 }
#line 1819 "src/bison.cpp"
    break;

  case 30:
#line 321 "src/parser.y"
                       {
			if (first_pass == 0) {
				code.addByteToCode(0x74);
			}
			lc += 2;
		 }
#line 1830 "src/bison.cpp"
    break;

  case 31:
#line 327 "src/parser.y"
                       {
			if (first_pass == 0) {
				code.addByteToCode(0x81);
			}
			lc += 2;
		 }
#line 1841 "src/bison.cpp"
    break;

  case 32:
#line 333 "src/parser.y"
                      {
			if (first_pass == 0) {
				code.addByteToCode(0x82);
			}
			lc += 2;
		 }
#line 1852 "src/bison.cpp"
    break;

  case 33:
#line 339 "src/parser.y"
                       {
			if (first_pass == 0) {
				code.addByteToCode(0x83);
			}
			lc += 2;
		 }
#line 1863 "src/bison.cpp"
    break;

  case 34:
#line 345 "src/parser.y"
                        {
			if (first_pass == 0) {
				code.addByteToCode(0x84);
			}
			lc += 2;
		 }
#line 1874 "src/bison.cpp"
    break;

  case 35:
#line 351 "src/parser.y"
                       {
			if (first_pass == 0) {
				code.addByteToCode(0x90);
			}
			lc += 2;
		 }
#line 1885 "src/bison.cpp"
    break;

  case 36:
#line 357 "src/parser.y"
                       {
			if (first_pass == 0) {
				code.addByteToCode(0x91);
			}
			lc += 2;
		 }
#line 1896 "src/bison.cpp"
    break;

  case 37:
#line 364 "src/parser.y"
                {
				if (first_pass == 0) {
					code.addByteToCode(0xa0);
				}
			}
#line 1906 "src/bison.cpp"
    break;

  case 38:
#line 369 "src/parser.y"
                        {
			if (first_pass == 0) {
				code.addByteToCode(0xb0);
			}
		  }
#line 1916 "src/bison.cpp"
    break;

  case 39:
#line 375 "src/parser.y"
                     {
				// neposredno: jmp broj
				if (first_pass == 0) {
					code.addByteToCode(0xff);	// 1111 ssss
					code.addByteToCode(0x00);	// uuuu aaaa
					// dodamo taj broj u code
					code.addByteToCode(((short)(yyvsp[0].ival) >> 8) & 0xff);
					code.addByteToCode((short)(yyvsp[0].ival) & 0x00ff);
				}
				lc += 5;
			}
#line 1932 "src/bison.cpp"
    break;

  case 40:
#line 386 "src/parser.y"
                            {
				// neposredno: jmp X
				if (first_pass == 0) {
						code.addByteToCode(0xff);	// 1111 ssss
						code.addByteToCode(0x00);	// uuuu aaaa
						// relokacioni zapis?
						code.current_relocation = {code.current_section, code.current_section, (short)((int)lc+3), "R_X86_64_32", (yyvsp[0].sval), 0};
						if (code.table_symbol.find((yyvsp[0].sval)) != code.table_symbol.end()) {
							if (code.table_symbol[(yyvsp[0].sval)].section == "absolute") {
								code.addByteToCode((code.table_symbol[(yyvsp[0].sval)].offset >> 8) & 0xff);
								code.addByteToCode(code.table_symbol[(yyvsp[0].sval)].offset & 0x00ff);
							} else {
								code.addRelocation(code.current_relocation);
							} 
						} else {
							code.addSymbol((yyvsp[0].sval), "undefined", (short)((int)lc+3), GLOBALNA);
							code.addRelocation(code.current_relocation);
						}
				}
				lc += 5;
		   }
#line 1958 "src/bison.cpp"
    break;

  case 41:
#line 407 "src/parser.y"
                                {
			   	short pc = 0x07;
			   	// pc relativno: jmp %X je l' ovako bese... (saberu se pc i X)
				if (first_pass == 0) {
					code.addByteToCode(0xf0 | pc);
					code.addByteToCode(0x05);	// 0000 0101
					// relokacioni zapis
					code.current_relocation = {code.current_section, code.current_section, (short)((int)lc+3), "R_X86_64_PC32", (yyvsp[0].sval), -2};
						if (code.table_symbol.find((yyvsp[0].sval)) != code.table_symbol.end()) {
							if (code.table_symbol[(yyvsp[0].sval)].section == "absolute") {
								code.addByteToCode((code.table_symbol[(yyvsp[0].sval)].offset >> 8) & 0xff);
								code.addByteToCode(code.table_symbol[(yyvsp[0].sval)].offset & 0x00ff);
							} else {
								code.addRelocation(code.current_relocation);
							} 
						} else {
							code.addSymbol((yyvsp[0].sval), "undefined", (short)((int)lc+3), GLOBALNA);
							code.addRelocation(code.current_relocation);
						}
				}
				lc += 5;
		   }
#line 1985 "src/bison.cpp"
    break;

  case 42:
#line 429 "src/parser.y"
                                      {
			   	// memorijsko: jmp *broj
				if (first_pass == 0) {
					code.addByteToCode(0xff);
					code.addByteToCode(0x04); 	// 0000 0100
					code.addByteToCode(((short)(yyvsp[0].ival) >> 8) & 0xff);
					code.addByteToCode((short)(yyvsp[0].ival) & 0x00ff);
				}
				lc += 5;
		   }
#line 2000 "src/bison.cpp"
    break;

  case 43:
#line 439 "src/parser.y"
                                     {
			   	// memorijsko: jmp *X
				if (first_pass == 0) {
					code.addByteToCode(0xff);
					code.addByteToCode(0x04);
					// relokacioni zapis
					code.current_relocation = {code.current_section, code.current_section, (short)((int)lc+3), "R_X86_64_32", (yyvsp[0].sval), 0};
						if (code.table_symbol.find((yyvsp[0].sval)) != code.table_symbol.end()) {
							if (code.table_symbol[(yyvsp[0].sval)].section == "absolute") {
								code.addByteToCode((code.table_symbol[(yyvsp[0].sval)].offset >> 8) & 0xff);
								code.addByteToCode(code.table_symbol[(yyvsp[0].sval)].offset & 0x00ff);
							} else {
								code.addRelocation(code.current_relocation);
							} 
						} else {
							code.addSymbol((yyvsp[0].sval), "undefined", (short)((int)lc+3), GLOBALNA);
							code.addRelocation(code.current_relocation);
						}
				}
				lc += 5;
		   }
#line 2026 "src/bison.cpp"
    break;

  case 44:
#line 460 "src/parser.y"
                                  {
			   	// registarsko direktno: jmp reg
				if (first_pass == 0) {
					code.addByteToCode(0xf0 | (yyvsp[0].ival));
					code.addByteToCode(0x01);	// 0000 0001
				}
				lc += 3;
		   }
#line 2039 "src/bison.cpp"
    break;

  case 45:
#line 468 "src/parser.y"
                                                    {
			   	// registarsko indirektno: jmp [reg]
				if (first_pass == 0) {
					code.addByteToCode(0xf0 | (yyvsp[-1].ival));
					code.addByteToCode(0x02);	// 0000 0010
				}
				lc += 3;
		   }
#line 2052 "src/bison.cpp"
    break;

  case 46:
#line 476 "src/parser.y"
                                                                 {
			   	// registarsko indirektno sa pomerajem: jmp [reg + broj]
				if (first_pass == 0) {
					code.addByteToCode(0xf0 | (yyvsp[-3].ival));
					code.addByteToCode(0x03);	// 0000 0011
					code.addByteToCode(((short)(yyvsp[-1].ival) >> 8) & 0xff);
					code.addByteToCode((short)(yyvsp[-1].ival) & 0x00ff);
				}
				lc += 5;
		   }
#line 2067 "src/bison.cpp"
    break;

  case 47:
#line 486 "src/parser.y"
                                                                {
			   	// registarsko indirektno sa pomerajem: jmp [reg + X]
				if (first_pass == 0) {
					code.addByteToCode(0xf0 | (yyvsp[-3].ival));
					code.addByteToCode(0x03);
					// relokacioni zapis
					code.current_relocation = {code.current_section, code.current_section, (short)((int)lc+3), "R_X86_64_32", (yyvsp[-1].sval), 0};
						if (code.table_symbol.find((yyvsp[-1].sval)) != code.table_symbol.end()) {
							if (code.table_symbol[(yyvsp[-1].sval)].section == "absolute") {
								code.addByteToCode((code.table_symbol[(yyvsp[-1].sval)].offset >> 8) & 0xff);
								code.addByteToCode(code.table_symbol[(yyvsp[-1].sval)].offset & 0x00ff);
							} else {
								code.addRelocation(code.current_relocation);
							} 
						} else {
							code.addSymbol((yyvsp[-1].sval), "undefined", (short)((int)lc+3), GLOBALNA);
							code.addRelocation(code.current_relocation);
						}
				}
				lc += 5;
		   }
#line 2093 "src/bison.cpp"
    break;

  case 48:
#line 508 "src/parser.y"
                        {
			// neposredno: ldr reg, $broj
			if (first_pass == 0) {
				adresiranje = "immedL";
				val = (yyvsp[0].ival);
			}
			lc += 5;
		}
#line 2106 "src/bison.cpp"
    break;

  case 49:
#line 516 "src/parser.y"
                           {
		   // neposredno: ldr reg, $X 
		   if (first_pass == 0) {
			   adresiranje = "immedS";
			   symb = (yyvsp[0].sval);
		   }
		   lc += 5;
	   }
#line 2119 "src/bison.cpp"
    break;

  case 50:
#line 524 "src/parser.y"
                     {
		   // memorijsko: ldr reg, broj
		   if (first_pass == 0) {
			   adresiranje = "memL";
			   val = (yyvsp[0].ival);
		   }
		   lc += 5;
	   }
#line 2132 "src/bison.cpp"
    break;

  case 51:
#line 532 "src/parser.y"
                    {
		   // memorijsko: ldr reg, X
		   if (first_pass == 0) {
			   adresiranje = "memS";
			   symb = (yyvsp[0].sval);
		   }
		   lc += 5;
	   }
#line 2145 "src/bison.cpp"
    break;

  case 52:
#line 540 "src/parser.y"
                        {
		   // pc relativno: ldr reg, %X 
		   if (first_pass == 0) {
			   adresiranje = "pcrel";
			   symb = (yyvsp[0].sval);
		   }
		   lc += 5;
	   }
#line 2158 "src/bison.cpp"
    break;

  case 53:
#line 548 "src/parser.y"
                 {
		   // registarsko direktno: ldr regD, regS
		   if (first_pass == 0) {
			   adresiranje = "regdir";
			   regg = (yyvsp[0].ival);
		   }
		   lc += 3;
	   }
#line 2171 "src/bison.cpp"
    break;

  case 54:
#line 556 "src/parser.y"
                                   {
		   // registarsko indirektno: ldr regD, [regS]
		   if (first_pass == 0) {
			   adresiranje = "regind";
			   regg = (yyvsp[-1].ival);
		   }
		   lc += 3;
	   }
#line 2184 "src/bison.cpp"
    break;

  case 55:
#line 564 "src/parser.y"
                                                {
		   // registarsko indirektno sa pomerajem: ldr regD, [regS + broj]
		   if (first_pass == 0) {
			   adresiranje = "regindpomL";
			   regg = (yyvsp[-3].ival);
			   val = (yyvsp[-1].ival);
		   }
		   lc += 5;
	   }
#line 2198 "src/bison.cpp"
    break;

  case 56:
#line 573 "src/parser.y"
                                               {
		   // registarsko indirektno sa pomerajem: ldr regD, [regS + X]
		   if (first_pass == 0) {
			   adresiranje = "regindpomS";
			   regg = (yyvsp[-3].ival);
			   symb = (yyvsp[-1].sval);
		   }
		   lc += 5;
	   }
#line 2212 "src/bison.cpp"
    break;

  case 57:
#line 583 "src/parser.y"
                             {
				// ne radi se nista u prvom prolazu
				if (first_pass == 1) {
					// cout << "ovde?" << endl;
					gloex = true;
					for (int i = 0; i < symbol_list.size(); i++) {
						// cout << "hm?" << endl;
						code.addSymbol(symbol_list[i], "undefined", lc, GLOBALNA);
					}
				}
				/*if (first_pass == 0) {
					gloex = true;
					for (int i = 0; i < symbol_list.size(); i++) {
						code.table_symbol[symbol_list[i]].prom = GLOBALNA;
					}
				}*/
			}
#line 2234 "src/bison.cpp"
    break;

  case 58:
#line 600 "src/parser.y"
                                     {
			 // isto ko GLOBAL 
			 if (first_pass == 0) {
				gloex = false;
				for (int i = 0; i < symbol_list.size(); i++) {
					if (code.table_symbol.find(symbol_list[i]) == code.table_symbol.end()) {
						code.addSymbol(symbol_list[i], "undefined", 0, GLOBALNA);
					}
				}
			 }
		 }
#line 2250 "src/bison.cpp"
    break;

  case 59:
#line 611 "src/parser.y"
                                  {
			if (first_pass == 1) {
				//if (code.current_section != "") {
					// cout << "current section: " << code.current_section << "; size = " << lc << endl;
				//}
				// postavim size prethodne sekcije
				code.set_size(code.current_section, lc);
				lc = 0;
				// tekuca vrednost simbola je tekuca vrednost pc-a
				// kazem da je current section ova SYMBOL
				code.current_section = (yyvsp[0].sval);
				// dodam simbol u tabelu simbola
				code.addSymbol((yyvsp[0].sval), code.current_section, 0, LOKALNA);
			} else {
				// dodam sekciju u tabelu sekcija
				code.addSection(code.current_section, lc, code.current_code);
				// reset
				lc = 0;
				code.current_code.clear();
				// stavim da je current section ova SYMBOL
				code.current_section = (yyvsp[0].sval);
			}
		 }
#line 2278 "src/bison.cpp"
    break;

  case 60:
#line 634 "src/parser.y"
                                          {
			for (int i = 0; i < symlit_list.size(); i++) {
				if (first_pass == 0) {
					// radi se nesto u zavisnosti da li je simbol ili ne
					if (symlit == true) {
						code.current_relocation = {code.current_section, code.current_section, lc, "R_X86_64_32", symlit_list[i].symbol, 0};
						// code.current_relocation = rel;
						if (code.table_symbol.find(symlit_list[i].symbol) != code.table_symbol.end()) {
							// ako vec postoji simbol u tabeli
							if (code.table_symbol[symlit_list[i].symbol].section == "absolute") {
								// znaci da je konstanta
								short constt = code.table_symbol[symlit_list[i].symbol].offset;
								code.addByteToCode((constt >> 8) & 0xff);
								code.addByteToCode(constt & 0x00ff);
							} else {
								code.addRelocation(code.current_relocation);
							}
						} else {
							code.addSymbol(symlit_list[i].symbol, "undefined", lc, GLOBALNA);
							code.addRelocation(code.current_relocation);
						}
					} else {
						code.addByteToCode((((short)symlit_list[i].literal) >> 8) & 0xff);
						code.addByteToCode(((short)symlit_list[i].literal) & 0x00ff);
					}
				}
				// location counter se uvek povecava za 2 (za svaki word)
				lc += 2;
			}
		 }
#line 2313 "src/bison.cpp"
    break;

  case 61:
#line 664 "src/parser.y"
                                {
			if (first_pass == 0) {
				for (int i = 0; i < (yyvsp[0].ival); i++) {
					// alocira se prostor sa onoliko 0 koliko je vrednost literala
					code.addByteToCode(0x00);
				}
			}
			lc += (yyvsp[0].ival);
		 }
#line 2327 "src/bison.cpp"
    break;

  case 62:
#line 673 "src/parser.y"
                                            {
			// cout << "lit: " << $4 << endl;
			if (first_pass == 1) {
				if (code.table_symbol.find((yyvsp[-2].sval)) != code.table_symbol.end()) {
					if (code.table_symbol[(yyvsp[-2].sval)].section == "undefined" &&
						code.table_symbol[(yyvsp[-2].sval)].prom == GLOBALNA) {
						code.table_symbol[(yyvsp[-2].sval)].section = "absolute";
						code.table_symbol[(yyvsp[-2].sval)].offset = (yyvsp[0].ival);
					} else {
						cout << "Greska na liniji: " << line_num << ". Simbol: " << (yyvsp[-2].sval) << " je vec u tabeli." << endl;
        				exit(-2);
					}
				} else {
					code.addSymbol((yyvsp[-2].sval), "absolute", (unsigned short)(yyvsp[0].ival), LOKALNA);
				}
			}
		 }
#line 2349 "src/bison.cpp"
    break;

  case 63:
#line 690 "src/parser.y"
                       {
			if (first_pass == 1) {
				code.set_size(code.current_section, lc);
			} else {
				code.addSection(code.current_section, lc, code.current_code);
				code.current_code.clear();
				lc = 0;
			}
			// YYACCEPT;
		 }
#line 2364 "src/bison.cpp"
    break;

  case 64:
#line 701 "src/parser.y"
                   {
				if (first_pass == 1) {
					symbol_list.clear();
					symbol_list.push_back((yyvsp[0].sval));
				}
			}
#line 2375 "src/bison.cpp"
    break;

  case 65:
#line 707 "src/parser.y"
                                            {
			    if (first_pass == 1) {
					symbol_list.push_back((yyvsp[-2].sval));
				}
			}
#line 2385 "src/bison.cpp"
    break;

  case 66:
#line 713 "src/parser.y"
                                 {
						symlit_list.clear();
						symlit_list.push_back(sl);
				    }
#line 2394 "src/bison.cpp"
    break;

  case 67:
#line 717 "src/parser.y"
                                                                         {
					 	symlit_list.push_back(sl);
				    }
#line 2402 "src/bison.cpp"
    break;

  case 68:
#line 721 "src/parser.y"
                      {
					symlit = true;
					sl = { (yyvsp[0].sval) };
			    }
#line 2411 "src/bison.cpp"
    break;

  case 69:
#line 725 "src/parser.y"
                                   {
				 	symlit = false;
					sl = { "", (yyvsp[0].ival) };
			    }
#line 2420 "src/bison.cpp"
    break;

  case 70:
#line 730 "src/parser.y"
                { (yyval.ival) = (yyvsp[0].ival); }
#line 2426 "src/bison.cpp"
    break;

  case 71:
#line 731 "src/parser.y"
                         { (yyval.ival) = (yyvsp[0].ival); }
#line 2432 "src/bison.cpp"
    break;

  case 72:
#line 732 "src/parser.y"
                          { (yyval.ival) = (-1) * (yyvsp[0].ival); }
#line 2438 "src/bison.cpp"
    break;


#line 2442 "src/bison.cpp"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 734 "src/parser.y"


void yyerror(const char* msg) {
	cout << "Greska u parseru: " << msg << " i to na liniji: " << line_num << endl;
	exit(-1);
}
