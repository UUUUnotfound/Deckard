/** \file
 *  This C header file was generated by $ANTLR version 3.4
 *
 *     -  From the grammar source file : D:\\Users\\lxjiang\\Documents\\Research\\projects\\Deckard\\CodeInProgress\\src\\dot2d\\grammars\\DotC.g
 *     -                            On : 2012-10-18 04:17:28
 *     -                 for the lexer : DotCLexerLexer
 *
 * Editing it, at least manually, is not wise.
 *
 * C language generator and runtime by Jim Idle, jimi|hereisanat|idle|dotgoeshere|ws.
 *
 *
 * The lexer 
DotCLexer

has the callable functions (rules) shown below,
 * which will invoke the code for the associated rule in the source grammar
 * assuming that the input stream is pointing to a token/text stream that could begin
 * this rule.
 *
 * For instance if you call the first (topmost) rule in a parser grammar, you will
 * get the results of a full parse, but calling a rule half way through the grammar will
 * allow you to pass part of a full token stream to the parser, such as for syntax checking
 * in editors and so on.
 *
 * The parser entry points are called indirectly (by function pointer to function) via
 * a parser context typedef pDotCLexer, which is returned from a call to DotCLexerNew().
 *
 * As this is a generated lexer, it is unlikely you will call it 'manually'. However
 * the methods are provided anyway.
 *
 * The methods in pDotCLexer are  as follows:
 *
 *  - 
 void
      pDotCLexer->COLON(pDotCLexer)
 *  - 
 void
      pDotCLexer->COMMA(pDotCLexer)
 *  - 
 void
      pDotCLexer->C_BRACKET(pDotCLexer)
 *  - 
 void
      pDotCLexer->C_SQR_BRACKET(pDotCLexer)
 *  - 
 void
      pDotCLexer->EQUAL(pDotCLexer)
 *  - 
 void
      pDotCLexer->LPAREN(pDotCLexer)
 *  - 
 void
      pDotCLexer->O_BRACKET(pDotCLexer)
 *  - 
 void
      pDotCLexer->O_SQR_BRACKET(pDotCLexer)
 *  - 
 void
      pDotCLexer->RPAREN(pDotCLexer)
 *  - 
 void
      pDotCLexer->SEMI_COLON(pDotCLexer)
 *  - 
 void
      pDotCLexer->GRAPH(pDotCLexer)
 *  - 
 void
      pDotCLexer->DIGRAPH(pDotCLexer)
 *  - 
 void
      pDotCLexer->STRICT(pDotCLexer)
 *  - 
 void
      pDotCLexer->NODE(pDotCLexer)
 *  - 
 void
      pDotCLexer->EDGE(pDotCLexer)
 *  - 
 void
      pDotCLexer->SUBGRAPH(pDotCLexer)
 *  - 
 void
      pDotCLexer->EDGEOP(pDotCLexer)
 *  - 
 void
      pDotCLexer->ID(pDotCLexer)
 *  - 
 void
      pDotCLexer->ALPHACHAR(pDotCLexer)
 *  - 
 void
      pDotCLexer->VALIDSTR(pDotCLexer)
 *  - 
 void
      pDotCLexer->NUMBER(pDotCLexer)
 *  - 
 void
      pDotCLexer->QUOTEDSTR(pDotCLexer)
 *  - 
 void
      pDotCLexer->STR(pDotCLexer)
 *  - 
 void
      pDotCLexer->ESCAPE_SEQUENCE(pDotCLexer)
 *  - 
 void
      pDotCLexer->HTMLSTR(pDotCLexer)
 *  - 
 void
      pDotCLexer->WS(pDotCLexer)
 *  - 
 void
      pDotCLexer->NEWLINE(pDotCLexer)
 *  - 
 void
      pDotCLexer->COMMENT(pDotCLexer)
 *  - 
 void
      pDotCLexer->LINE_COMMENT(pDotCLexer)
 *  - 
 void
      pDotCLexer->A(pDotCLexer)
 *  - 
 void
      pDotCLexer->B(pDotCLexer)
 *  - 
 void
      pDotCLexer->C(pDotCLexer)
 *  - 
 void
      pDotCLexer->D(pDotCLexer)
 *  - 
 void
      pDotCLexer->E(pDotCLexer)
 *  - 
 void
      pDotCLexer->F(pDotCLexer)
 *  - 
 void
      pDotCLexer->G(pDotCLexer)
 *  - 
 void
      pDotCLexer->H(pDotCLexer)
 *  - 
 void
      pDotCLexer->I(pDotCLexer)
 *  - 
 void
      pDotCLexer->J(pDotCLexer)
 *  - 
 void
      pDotCLexer->K(pDotCLexer)
 *  - 
 void
      pDotCLexer->L(pDotCLexer)
 *  - 
 void
      pDotCLexer->M(pDotCLexer)
 *  - 
 void
      pDotCLexer->N(pDotCLexer)
 *  - 
 void
      pDotCLexer->O(pDotCLexer)
 *  - 
 void
      pDotCLexer->P(pDotCLexer)
 *  - 
 void
      pDotCLexer->Q(pDotCLexer)
 *  - 
 void
      pDotCLexer->R(pDotCLexer)
 *  - 
 void
      pDotCLexer->S(pDotCLexer)
 *  - 
 void
      pDotCLexer->T(pDotCLexer)
 *  - 
 void
      pDotCLexer->U(pDotCLexer)
 *  - 
 void
      pDotCLexer->V(pDotCLexer)
 *  - 
 void
      pDotCLexer->W(pDotCLexer)
 *  - 
 void
      pDotCLexer->X(pDotCLexer)
 *  - 
 void
      pDotCLexer->Y(pDotCLexer)
 *  - 
 void
      pDotCLexer->Z(pDotCLexer)
 *  - 
 void
      pDotCLexer->Tokens(pDotCLexer)
 *
 * The return type for any particular rule is of course determined by the source
 * grammar file.
 */
// [The "BSD license"]
// Copyright (c) 2005-2009 Jim Idle, Temporal Wave LLC
// http://www.temporal-wave.com
// http://www.linkedin.com/in/jimidle
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. The name of the author may not be used to endorse or promote products
//    derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef	_DotCLexer_H
#define _DotCLexer_H
/* =============================================================================
 * Standard antlr3 C runtime definitions
 */
#include    <antlr3.h>

/* End of standard antlr 3 runtime definitions
 * =============================================================================
 */

#ifdef __cplusplus
extern "C" {
#endif

// Forward declare the context typedef so that we can use it before it is
// properly defined. Delegators and delegates (from import statements) are
// interdependent and their context structures contain pointers to each other
// C only allows such things to be declared if you pre-declare the typedef.
//
typedef struct DotCLexer_Ctx_struct DotCLexer, * pDotCLexer;



#ifdef	ANTLR3_WINDOWS
// Disable: Unreferenced parameter,							- Rules with parameters that are not used
//          constant conditional,							- ANTLR realizes that a prediction is always true (synpred usually)
//          initialized but unused variable					- tree rewrite variables declared but not needed
//          Unreferenced local variable						- lexer rule declares but does not always use _type
//          potentially unitialized variable used			- retval always returned from a rule
//			unreferenced local function has been removed	- susually getTokenNames or freeScope, they can go without warnigns
//
// These are only really displayed at warning level /W4 but that is the code ideal I am aiming at
// and the codegen must generate some of these warnings by necessity, apart from 4100, which is
// usually generated when a parser rule is given a parameter that it does not use. Mostly though
// this is a matter of orthogonality hence I disable that one.
//
#pragma warning( disable : 4100 )
#pragma warning( disable : 4101 )
#pragma warning( disable : 4127 )
#pragma warning( disable : 4189 )
#pragma warning( disable : 4505 )
#pragma warning( disable : 4701 )
#endif

/** Context tracking structure for 
DotCLexer

 */
struct DotCLexer_Ctx_struct
{
    /** Built in ANTLR3 context tracker contains all the generic elements
     *  required for context tracking.
     */
    pANTLR3_LEXER    pLexer;

     void
     (*mCOLON)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mCOMMA)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mC_BRACKET)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mC_SQR_BRACKET)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mEQUAL)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mLPAREN)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mO_BRACKET)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mO_SQR_BRACKET)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mRPAREN)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mSEMI_COLON)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mGRAPH)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mDIGRAPH)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mSTRICT)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mNODE)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mEDGE)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mSUBGRAPH)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mEDGEOP)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mID)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mALPHACHAR)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mVALIDSTR)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mNUMBER)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mQUOTEDSTR)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mSTR)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mESCAPE_SEQUENCE)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mHTMLSTR)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mWS)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mNEWLINE)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mCOMMENT)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mLINE_COMMENT)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mA)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mB)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mC)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mD)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mE)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mF)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mG)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mH)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mI)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mJ)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mK)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mL)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mM)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mN)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mO)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mP)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mQ)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mR)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mS)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mT)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mU)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mV)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mW)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mX)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mY)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mZ)	(struct DotCLexer_Ctx_struct * ctx);

     void
     (*mTokens)	(struct DotCLexer_Ctx_struct * ctx);
    const char * (*getGrammarFileName)();
    void            (*reset)  (struct DotCLexer_Ctx_struct * ctx);
    void	    (*free)   (struct DotCLexer_Ctx_struct * ctx);
};

// Function protoypes for the constructor functions that external translation units
// such as delegators and delegates may wish to call.
//
ANTLR3_API pDotCLexer DotCLexerNew         (
pANTLR3_INPUT_STREAM
 instream);
ANTLR3_API pDotCLexer DotCLexerNewSSD      (
pANTLR3_INPUT_STREAM
 instream, pANTLR3_RECOGNIZER_SHARED_STATE state);

/** Symbolic definitions of all the tokens that the 
lexer
 will work with.
 * \{
 *
 * Antlr will define EOF, but we can't use that as it it is too common in
 * in C header files and that would be confusing. There is no way to filter this out at the moment
 * so we just undef it here for now. That isn't the value we get back from C recognizers
 * anyway. We are looking for ANTLR3_TOKEN_EOF.
 */
#ifdef	EOF
#undef	EOF
#endif
#ifdef	Tokens
#undef	Tokens
#endif
#define EOF      -1
#define A      4
#define ALPHACHAR      5
#define ATTR      6
#define ATTR_LIST      7
#define B      8
#define C      9
#define COLON      10
#define COMMA      11
#define COMMENT      12
#define C_BRACKET      13
#define C_SQR_BRACKET      14
#define D      15
#define DIGRAPH      16
#define E      17
#define EDGE      18
#define EDGEOP      19
#define EDGE_STMT      20
#define EQUAL      21
#define ESCAPE_SEQUENCE      22
#define F      23
#define G      24
#define GRAPH      25
#define GRAPH_ROOT      26
#define H      27
#define HTMLSTR      28
#define I      29
#define ID      30
#define J      31
#define K      32
#define L      33
#define LINE_COMMENT      34
#define LPAREN      35
#define M      36
#define N      37
#define NEWLINE      38
#define NODE      39
#define NODE_STMT      40
#define NUMBER      41
#define O      42
#define O_BRACKET      43
#define O_SQR_BRACKET      44
#define P      45
#define Q      46
#define QUOTEDSTR      47
#define R      48
#define RPAREN      49
#define S      50
#define SEMI_COLON      51
#define STMT_LIST      52
#define STR      53
#define STRICT      54
#define SUBGRAPH      55
#define SUBGRAPH_ROOT      56
#define T      57
#define U      58
#define V      59
#define VALIDSTR      60
#define W      61
#define WS      62
#define X      63
#define Y      64
#define Z      65
#ifdef	EOF
#undef	EOF
#define	EOF	ANTLR3_TOKEN_EOF
#endif

#ifndef TOKENSOURCE
#define TOKENSOURCE(lxr) lxr->pLexer->rec->state->tokSource
#endif

/* End of token definitions for DotCLexer
 * =============================================================================
 */
/** } */

#ifdef __cplusplus
}
#endif

#endif

/* END - Note:Keep extra line feed to satisfy UNIX systems */
