// Copyright (c) 2019 Christoffer Lerno. All rights reserved.
// Use of this source code is governed by the GNU LGPLv3.0 license
// a copy of which can be found in the LICENSE file.

// Only include this from compiler_common.h

typedef enum
{
	BINARYOP_ERROR,
	BINARYOP_MULT,
	BINARYOP_MULT_MOD,
	BINARYOP_SUB,
	BINARYOP_SUB_MOD,
	BINARYOP_ADD,
	BINARYOP_ADD_MOD,
	BINARYOP_DIV,
	BINARYOP_MOD,
	BINARYOP_SHR,
	BINARYOP_SHL,
	BINARYOP_BIT_OR,
	BINARYOP_BIT_XOR,
	BINARYOP_BIT_AND,
	BINARYOP_AND,
	BINARYOP_OR,
	// Don't change the ordering for GT to EQ or things will break
	BINARYOP_GT,
	BINARYOP_GE,
	BINARYOP_LT,
	BINARYOP_LE,
	BINARYOP_NE,
	BINARYOP_EQ,
	// Only "assign" BINOPS after this point
	BINARYOP_ASSIGN,
	BINARYOP_MULT_ASSIGN,
	BINARYOP_MULT_MOD_ASSIGN,
	BINARYOP_ADD_ASSIGN,
	BINARYOP_ADD_MOD_ASSIGN,
	BINARYOP_SUB_ASSIGN,
	BINARYOP_SUB_MOD_ASSIGN,
	BINARYOP_DIV_ASSIGN,
	BINARYOP_MOD_ASSIGN,
	BINARYOP_BIT_AND_ASSIGN,
	BINARYOP_BIT_OR_ASSIGN,
	BINARYOP_BIT_XOR_ASSIGN,
	BINARYOP_SHR_ASSIGN,
	BINARYOP_SHL_ASSIGN,
	BINARYOP_LAST = BINARYOP_SHL_ASSIGN
} BinaryOp;

typedef enum
{
	AST_POISONED,
	AST_ASM_STMT,
	AST_BREAK_STMT,
	AST_CASE_STMT,
	AST_CATCH_STMT,
	AST_COMPOUND_STMT,
	AST_CONTINUE_STMT,
	AST_DEFINE_STMT,
	AST_CT_IF_STMT,
	AST_CT_ELIF_STMT,
	AST_CT_ELSE_STMT,
	AST_CT_FOR_STMT,
	AST_CT_SWITCH_STMT,
	AST_DECLARE_STMT,
	AST_DEFAULT_STMT,
	AST_DEFER_STMT,
	AST_DO_STMT,
	AST_EXPR_STMT,
	AST_TRY_STMT,
	AST_FOR_STMT,
	AST_IF_STMT,
	AST_NOP_STMT,
	AST_RETURN_STMT,
	AST_SWITCH_STMT,
	AST_NEXT_STMT,
	AST_VOLATILE_STMT,
	AST_WHILE_STMT,
	AST_SCOPED_STMT,
} AstKind;

typedef enum
{
	ATTR_INVALID,
	ATTR_UNRESOLVED,
} AttrKind;


typedef enum
{
	CAST_ERROR,
	CAST_EUBOOL,
	CAST_EUER,
	CAST_EREU,
	CAST_XIERR,
	CAST_PTRPTR,
	CAST_PTRXI,
	CAST_VARRPTR,
	CAST_ARRPTR,
	CAST_STRPTR,
	CAST_PTRBOOL,
	CAST_BOOLINT,
	CAST_BOOLFP,
	CAST_FPBOOL,
	CAST_INTBOOL,
	CAST_FPFP,
	CAST_FPSI,
	CAST_FPUI,
	CAST_SISI,
	CAST_SIUI,
	CAST_SIFP,
	CAST_XIPTR,
	CAST_UISI,
	CAST_UIUI,
	CAST_UIFP,
	CAST_ENUMLOW,
	CAST_APTSA,
	CAST_SAPTR,
} CastKind;

typedef enum
{
	CAST_TYPE_EXPLICIT,
	CAST_TYPE_IMPLICIT,
	CAST_TYPE_OPTIONAL_IMPLICIT,
} CastType;



typedef enum
{
	DECL_POISONED = 0,
	DECL_FUNC,
	DECL_VAR,
	DECL_LABEL,
	DECL_ENUM_CONSTANT,
	DECL_TYPEDEF,
	DECL_STRUCT,
	DECL_UNION,
	DECL_ENUM,
	DECL_ERR,
	DECL_ARRAY_VALUE,
	DECL_IMPORT,
	DECL_MACRO,
	DECL_GENERIC,
	DECL_CT_IF,
	DECL_CT_ELSE,
	DECL_CT_ELIF,
	DECL_ATTRIBUTE,
} DeclKind;

// Ordering here is in priority if two branches should have the same exit.
typedef enum
{
	EXIT_NONE = 0,
	EXIT_CONTINUE,
	EXIT_RETURN,
	EXIT_NEXT,
	EXIT_BREAK,
} ExitType;

typedef enum
{
	EXPR_POISONED,
	EXPR_GUARD,
	EXPR_TRY,
	EXPR_CATCH,
	EXPR_ELSE,
	EXPR_CONST,
	EXPR_BINARY,
	EXPR_TERNARY,
	EXPR_UNARY,
	EXPR_POST_UNARY,
	EXPR_TYPEID,
	EXPR_IDENTIFIER,
	EXPR_TYPE_ACCESS,
	EXPR_CALL,
	EXPR_GROUP,
	EXPR_SUBSCRIPT,
	EXPR_SLICE,
	EXPR_SLICE_ASSIGN,
	EXPR_ACCESS,
	EXPR_INITIALIZER_LIST,
	EXPR_EXPRESSION_LIST,
	EXPR_CAST,
	EXPR_TYPEOF,
	EXPR_SCOPED_EXPR,
	EXPR_EXPR_BLOCK,
	EXPR_MACRO_BLOCK,
	EXPR_DESIGNATED_INITIALIZER,
	EXPR_COMPOUND_LITERAL,
	EXPR_FAILABLE,
	EXPR_DECL_LIST,
	EXPR_LEN,
} ExprKind;

typedef enum
{
	FAILABLE_NO,
	FAILABLE_YES,
	FAILABLE_UNWRAPPED
} ExprFailableStatus;


typedef enum
{
	PREC_NONE,
	PREC_ASSIGNMENT,        // =, *=, /=, %=, +=, etc
	PREC_TRY_ELSE,          // try and else
	PREC_TERNARY,           // ?:
	PREC_LOGICAL,           // && ||
	PREC_RELATIONAL,        // < > <= >= == !=
	PREC_ADDITIVE,          // + -
	PREC_BIT,               // ^ | &
	PREC_SHIFT,             // << >> >>>
	PREC_MULTIPLICATIVE,    // * / %
	PREC_UNARY,             // @ ! - + ~ * & prefix ++/--
	PREC_CALL,              // . () [] postfix ++/--
} Precedence;

typedef enum
{
	SCOPE_NONE = 0,
	SCOPE_DEFER = 1 << 4,
	SCOPE_EXPR_BLOCK = 1 << 5,
	SCOPE_MACRO = 1 << 6,
	SCOPE_COND = 1 << 7,
} ScopeFlags;

typedef enum
{
	RESOLVE_NOT_DONE = 0,
	RESOLVE_RUNNING,
	RESOLVE_DONE
} ResolveStatus;

typedef enum
{
	TYPE_INFO_POISON,
	TYPE_INFO_IDENTIFIER,
	TYPE_INFO_EXPRESSION,
	TYPE_INFO_ARRAY,
	TYPE_INFO_INC_ARRAY,
	TYPE_INFO_VARARRAY,
	TYPE_INFO_SUBARRAY,
	TYPE_INFO_POINTER,
} TypeInfoKind;

typedef enum 
{
	TOKEN_INVALID_TOKEN = 0,

	// Single-character tokens.
	TOKEN_AMP,              // &
	TOKEN_AT,               // @
	TOKEN_BIT_NOT,          // ~
	TOKEN_BIT_OR,           // =
	TOKEN_BIT_XOR,          // ^
	TOKEN_COLON,            // :
	TOKEN_COMMA,            // ,
	TOKEN_EOS,              // ;
	TOKEN_EQ,               // =
	TOKEN_GREATER,          // >
	TOKEN_DIV,              // /
	TOKEN_DOLLAR,           // $
	TOKEN_DOT,              // .
	TOKEN_HASH,             // #
	TOKEN_LESS,             // <
	TOKEN_LBRACE,           // {
	TOKEN_LBRACKET,         // [
	TOKEN_LPAREN,           // (
	TOKEN_MINUS,            // -
	TOKEN_MOD,              // %
	TOKEN_BANG,             // !
	TOKEN_OR,               // |
	TOKEN_PLUS,             // +
	TOKEN_QUESTION,         // ?
	TOKEN_RBRACE,           // }
	TOKEN_RBRACKET,         // ]
	TOKEN_RPAREN,           // )
	TOKEN_STAR,             // *

	// two character tokens.
	TOKEN_AND,              // &&
	TOKEN_ARROW,            // -> // Not used but reserved
	TOKEN_BIT_AND_ASSIGN,   // &=
	TOKEN_BIT_OR_ASSIGN,    // |=
	TOKEN_BIT_XOR_ASSIGN,   // ^=
	TOKEN_DIV_ASSIGN,       // /=
	TOKEN_DOTDOT,           // ..
	TOKEN_ELVIS,            // ?:
	TOKEN_EQEQ,             // ==
	TOKEN_GREATER_EQ,       // >=
	TOKEN_LESS_EQ,          // <=
	TOKEN_LPARBRA,          // ({
	TOKEN_MINUS_ASSIGN,     // -=
	TOKEN_MINUS_MOD,        // -%
	TOKEN_MINUSMINUS,       // --
	TOKEN_MOD_ASSIGN,       // %=
	TOKEN_MULT_ASSIGN,      // *=
	TOKEN_MULT_MOD,         // *%
	TOKEN_NOT_EQUAL,        // !=
	TOKEN_PLUS_ASSIGN,      // +=
	TOKEN_PLUS_MOD,         // +%
	TOKEN_PLUSPLUS,         // ++
	TOKEN_RPARBRA,          // })
	TOKEN_SCOPE,            // ::
	TOKEN_SHR,              // >>
	TOKEN_SHL,              // <<
	TOKEN_BANGBANG,         // !!

	// Three or more
	TOKEN_ELLIPSIS,         // ...
	TOKEN_MINUS_MOD_ASSIGN, // -%=
	TOKEN_MULT_MOD_ASSIGN,  // *%=
	TOKEN_PLUS_MOD_ASSIGN,  // +%=
	TOKEN_SHR_ASSIGN,       // >>=
	TOKEN_SHL_ASSIGN,       // >>=

	// Basic types names
	TOKEN_VOID,
	TOKEN_BYTE,
	TOKEN_BOOL,
	TOKEN_CHAR,
	TOKEN_DOUBLE,
	TOKEN_FLOAT,
	TOKEN_HALF,
	TOKEN_INT,
	TOKEN_ISIZE,
	TOKEN_LONG,
	TOKEN_SHORT,
	TOKEN_UINT,
	TOKEN_ULONG,
	TOKEN_USHORT,
	TOKEN_USIZE,
	TOKEN_QUAD,
	TOKEN_TYPEID,

	// C types
	TOKEN_C_SHORT,
	TOKEN_C_INT,
	TOKEN_C_LONG,
	TOKEN_C_LONGLONG,
	TOKEN_C_USHORT,
	TOKEN_C_UINT,
	TOKEN_C_ULONG,
	TOKEN_C_ULONGLONG,


	// Literals.
	TOKEN_IDENT,            // Any normal ident.
	TOKEN_CONST_IDENT,      // Any purely upper case ident,
	TOKEN_TYPE_IDENT,       // Any ident on the format FooBar or __FooBar

	// Asm
	TOKEN_ASM_STRING,
	TOKEN_ASM_CONSTRAINT,

	// We want to parse $foo separately.
	// Otherwise we allow things like "# foo" which would be pretty bad.
	TOKEN_CT_IDENT,         // $foobar
	TOKEN_CT_CONST_IDENT,   // $FOOBAR
	TOKEN_CT_TYPE_IDENT,    // $Foobar

	TOKEN_STRING,           // "Teststring"
	TOKEN_INTEGER,          // 123 0x23 0b10010 0o327
	TOKEN_CHAR_LITERAL,        // 'a' 'FO' 'BARS' '\u1232'
	TOKEN_REAL,             // 0x23.2p-2a 43.23e23

	TOKEN_COMMENT,          // Comment
	TOKEN_DOC_COMMENT,      // Doc Comment

	// Keywords
	TOKEN_ALIAS,            // Reserved
	TOKEN_AS,
	TOKEN_ASM,
	TOKEN_ATTRIBUTE,
	TOKEN_BREAK,
	TOKEN_CASE,
	TOKEN_CAST,
	TOKEN_CATCH,
	TOKEN_CONST,
	TOKEN_CONTINUE,
	TOKEN_DEFINE,
	TOKEN_DEFAULT,
	TOKEN_DEFER,
	TOKEN_DO,
	TOKEN_ELSE,
	TOKEN_ENUM,
	TOKEN_ERR,
	TOKEN_EXTERN,
	TOKEN_FALSE,
	TOKEN_FOR,
	TOKEN_FUNC,
	TOKEN_GENERIC,
	TOKEN_IF,
	TOKEN_IMPORT,
	TOKEN_IN,
	TOKEN_LOCAL,
	TOKEN_MACRO,
	TOKEN_MODULE,
	TOKEN_NEXT,
	TOKEN_NIL,
	TOKEN_PUBLIC,
	TOKEN_RETURN,
	TOKEN_STRUCT,
	TOKEN_SWITCH,
	TOKEN_TRUE,
	TOKEN_TRY,
	TOKEN_TYPEDEF,
	TOKEN_UNION,
	TOKEN_UNTIL,
	TOKEN_VAR,              // Reserved
	TOKEN_VOLATILE,
	TOKEN_WHILE,
	TOKEN_TYPEOF,

	TOKEN_CT_CASE,          // $case
	TOKEN_CT_DEFAULT,       // $default
	TOKEN_CT_FOR,           // $for
	TOKEN_CT_ELIF,          // $elif
	TOKEN_CT_ELSE,          // $else
	TOKEN_CT_IF,            // $if
	TOKEN_CT_SWITCH,        // $switch

	TOKEN_DOCS_START,       // /**
	TOKEN_DOCS_END,         // */ (may start with an arbitrary number of `*`
	TOKEN_DOCS_EOL,         // "\n" only seen in docs.
	TOKEN_DOCS_LINE,        // Any line within /** **/

	TOKEN_EOF,              // \n - SHOULD ALWAYS BE THE LAST TOKEN.

	TOKEN_LAST = TOKEN_EOF,
} TokenType;


// Note that ordering matters here. If ordering is changed,
// So must type_find_max_type and friends.
// The reason is that for binary expressions we can simplify
// by knowing the type_kind of left <= type kind of right
typedef enum
{
	TYPE_POISONED,
	TYPE_VOID,
	TYPE_BOOL,
	TYPE_I8,
	TYPE_I16,
	TYPE_I32,
	TYPE_I64,
	TYPE_U8,
	TYPE_U16,
	TYPE_U32,
	TYPE_U64,
	TYPE_IXX,
	TYPE_F32,
	TYPE_F64,
	TYPE_FXX,
	TYPE_POINTER,
	TYPE_ENUM,
	TYPE_FUNC,
	TYPE_STRUCT,
	TYPE_UNION,
	TYPE_ERRTYPE,
	TYPE_ERR_UNION,
	TYPE_TYPEDEF,
	TYPE_STRING,
	TYPE_ARRAY,
	TYPE_VARARRAY,
	TYPE_SUBARRAY,
	TYPE_TYPEID,
	TYPE_LAST = TYPE_TYPEID
} TypeKind;

#define ALL_INTS TYPE_I8: case TYPE_I16: case TYPE_I32: case TYPE_I64: \
case TYPE_U8: case TYPE_U16: case TYPE_U32: case TYPE_U64: case TYPE_IXX
#define ALL_SIGNED_INTS TYPE_I8: case TYPE_I16: case TYPE_I32: case TYPE_I64
#define ALL_UNSIGNED_INTS TYPE_U8: case TYPE_U16: case TYPE_U32: case TYPE_U64
#define ALL_FLOATS TYPE_F32: case TYPE_F64: case TYPE_FXX

#define TYPE_KINDS (TYPE_LAST + 1)

typedef enum
{
	UNARYOP_ERROR,
	UNARYOP_DEREF,
	UNARYOP_ADDR,
	UNARYOP_NEG,
	UNARYOP_NEGMOD,
	UNARYOP_BITNEG,
	UNARYOP_NOT,
	UNARYOP_INC,
	UNARYOP_DEC,
	UNARYOP_LAST = UNARYOP_DEC
} UnaryOp;

typedef enum
{
	POSTUNARYOP_INC,
	POSTUNARYOP_DEC,
} PostUnaryOp;

typedef enum
{
	VARDECL_CONST = 0,
	VARDECL_GLOBAL = 1,
	VARDECL_LOCAL = 2,
	VARDECL_PARAM = 3,
	VARDECL_MEMBER = 4,
	VARDECL_LOCAL_CT = 5,
	VARDECL_LOCAL_CT_TYPE = 6,
	VARDECL_ALIAS = 7,
} VarDeclKind;

typedef enum
{
	VISIBLE_MODULE,
	VISIBLE_LOCAL,
	VISIBLE_PUBLIC,
	VISIBLE_EXTERN,
} Visibility;


typedef enum
{
	ATTR_FUNC = 1 << 0,
	ATTR_VAR = 1 << 1,
	ATTR_ENUM = 1 << 2,
	ATTR_STRUCT = 1 << 3,
	ATTR_UNION = 1 << 4,
	ATTR_CONST = 1 << 5,
	ATTR_ERROR = 1 << 6,
	ATTR_TYPEDEF = 1 << 7
} AttributeDomain;

typedef enum
{
	ATTRIBUTE_INLINE,
	ATTRIBUTE_NOINLINE,
	ATTRIBUTE_STDCALL,
	ATTRIBUTE_OPAQUE,
	ATTRIBUTE_NORETURN,
	ATTRIBUTE_SECTION,
	ATTRIBUTE_CNAME,
	ATTRIBUTE_WEAK,
	ATTRIBUTE_ALIGN,
	ATTRIBUTE_PACKED,
	NUMBER_OF_ATTRIBUTES = ATTRIBUTE_PACKED + 1,
	ATTRIBUTE_NONE,
} AttributeType;

typedef enum
{
	CALL_CONVENTION_NORMAL = 0,
} CallConvention;

typedef enum
{
	CALL_X86_STD,
	CALL_X86_FAST,
	CALL_X86_THIS,
	CALL_X86_VECTOR,
	CALL_X86_PASCAL,
	CALL_WIN64,
	CALL_X64_SYSV,
	CALL_X86_REG,
	CALL_AAPCS,
	CALL_AAPCS_VFP,
	CALL_INTEL_OCL_BICC,
	CALL_SPIR_FUNCTION,
	CALL_OPENCL_KERNEL,
	CALL_PRESERVE_MOST,
	CALL_PRESERVE_ALL,
	CALL_AARCH64_VECTOR,
} CallABI;

