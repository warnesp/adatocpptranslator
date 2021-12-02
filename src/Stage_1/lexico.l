/*****************************************************************************
 *                      Ada_to_C_Cpp_Translator
 *****************************************************************************
 * Adatoccpptranslator is a free software which convert Ada code to C/C++ 
 * source code
 * Copyright (C) 2004 Julien THEVENON
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option) 
 * any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for 
 * more details.
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 * For further informations : adatoccpptranslator@free.fr
 * 
 * Description: Lexical Analyser of Ada language
 *
 * $Log: lexico.l,v $
 * Revision 1.5  2005/03/26 23:29:10  quicky2000
 * Update to remove form feed and modify error message concerning unrecognized token
 *
 * Revision 1.4  2005/03/19 12:45:40  quicky2000
 * Update to correct "LitteralBase" regular expression
 *
 * Revision 1.3  2005/03/19 10:54:02  quicky2000
 * Update to restablish cvs logs
 *
 * Revision 1.1  2005/03/07 23:35:14  quicky2000
 * Update to modify include paths due to to new source organization
 *
 * Revision 1.1.1.1  2005/03/01 22:20:39  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
%{
#include "../src/Tools/tree.h"
#include <string.h>
#define YYSTYPE tree*

//yylex is overload to use an other fonction wich keeps input source commentary
//this define allow to make flex use jt_seq instead of yylex
#define YY_DECL int jt_seq (void)

#define VERBOSE 1

//#define yywrap() 1
#include "../obj/y.tab.h"

int g_LineNumber = 1; /*-- line number */
%}

%option noyywrap

/* Definitions */
Majuscule	[A-Z]
Minuscule	[a-z]
Chiffre		[0-9]
Lettre		{Majuscule}|{Minuscule}
ChiffreGeneral	{Lettre}|{Chiffre}
Entier		{Chiffre}+(_|{Chiffre})*
EntierBase	{ChiffreGeneral}+(_|{ChiffreGeneral})*
Identificateur	{Lettre}({Lettre}|{Chiffre}|_)*

Exposant	(E|e)(\+|-)?{Entier}
LitteralBase	{Entier}\#{EntierBase}(\.{EntierBase})?#({Exposant})?
LitteralDecimal	{Entier}(\.{Entier})?({Exposant})?
LitteralCaractere [\040\041]|[\043-\176]
LitteralChaine	\"({LitteralCaractere}|'""')*\"
Commentaire	\-\-([\0-\11]|[\13\14]|[\16-\377])* 
Separateur      [\t]|[\040]+

/* lexicographic rules */
%%
ABORT		{yylval = new tree( g_LineNumber );
		 return ABORT_Lex;}
ABS		{yylval = new tree( g_LineNumber );
		 return ABS_Lex;}
ABSTRACT	{yylval = new tree( g_LineNumber );
		 return ABSTRACT_Lex;}
ACCEPT		{yylval = new tree( g_LineNumber );
		 return ACCEPT_Lex;}
ACCESS		{yylval = new tree( g_LineNumber );
		 return ACCESS_Lex;}
ALL		{yylval = new tree( g_LineNumber );
		 return ALL_Lex;}
AND		{yylval = new tree( g_LineNumber );
		 return AND_Lex;}
ARRAY		{yylval = new tree( g_LineNumber );
		 return ARRAY_Lex;}
AT		{yylval = new tree( g_LineNumber );
		 return AT_Lex;}
BEGIN		{yylval = new tree( g_LineNumber );
		 return BEGIN_Lex;}
BODY		{yylval = new tree( g_LineNumber );
		 return BODY_Lex;}
CASE		{yylval = new tree( g_LineNumber );
		 return CASE_Lex;}
CONSTANT	{yylval = new tree( g_LineNumber );
		 return CONSTANT_Lex;}
DECLARE		{yylval = new tree( g_LineNumber );
		 return DECLARE_Lex;}
DELAY		{yylval = new tree( g_LineNumber );
		 return DELAY_Lex;}
DELTA		{yylval = new tree( g_LineNumber );
		 return DELTA_Lex;}
DIGITS		{yylval = new tree( g_LineNumber );
		 return DIGITS_Lex;}
DO		{yylval = new tree( g_LineNumber );
		 return DO_Lex;}
ELSE		{yylval = new tree( g_LineNumber );
		 return ELSE_Lex;}
ELSIF		{yylval = new tree( g_LineNumber );
		 return ELSIF_Lex;}
END		{yylval = new tree( g_LineNumber );
		 return END_Lex;}
ENTRY		{yylval = new tree( g_LineNumber );
		 return ENTRY_Lex;}
EXCEPTION	{yylval = new tree( g_LineNumber );
		 return EXCEPTION_Lex;}
EXIT		{yylval = new tree( g_LineNumber );
		 return EXIT_Lex;}
FOR		{yylval = new tree( g_LineNumber );
		 return FOR_Lex;}
FUNCTION	{yylval = new tree( g_LineNumber );
		 return FUNCTION_Lex;}
GENERIC		{yylval = new tree( g_LineNumber );
		 return GENERIC_Lex;}
GOTO		{yylval = new tree( g_LineNumber );
		 return GOTO_Lex;}
IF		{yylval = new tree( g_LineNumber );
		 return IF_Lex;}
IN		{yylval = new tree( g_LineNumber );
		 return IN_Lex;}
IS		{yylval = new tree( g_LineNumber );
		 return IS_Lex;}
LIMITED		{yylval = new tree( g_LineNumber );
		 return LIMITED_Lex;}
LOOP		{yylval = new tree( g_LineNumber );
		 return LOOP_Lex;}
MOD		{yylval = new tree( g_LineNumber );
		 return MOD_Lex;}
NEW		{yylval = new tree( g_LineNumber );
		 return NEW_Lex;}
NOT		{yylval = new tree( g_LineNumber );
		 return NOT_Lex;}
NULL		{yylval = new tree( g_LineNumber );
		 return NULL_Lex;}
OF		{yylval = new tree( g_LineNumber );
		 return OF_Lex;}
OR		{yylval = new tree( g_LineNumber );
		 return OR_Lex;}
OTHERS		{yylval = new tree( g_LineNumber );
		 return OTHERS_Lex;}
OUT		{yylval = new tree( g_LineNumber );
		 return OUT_Lex;}
PACKAGE		{yylval = new tree( g_LineNumber );
		 return PACKAGE_Lex;}
PRAGMA		{yylval = new tree( g_LineNumber );
		 return PRAGMA_Lex;}
PRIVATE		{yylval = new tree( g_LineNumber );
		 return PRIVATE_Lex;}
PROCEDURE	{yylval = new tree( g_LineNumber );
		 return PROCEDURE_Lex;}
RAISE		{yylval = new tree( g_LineNumber );
		 return RAISE_Lex;}
RANGE		{yylval = new tree( g_LineNumber );
		 return RANGE_Lex;}
RECORD		{yylval = new tree( g_LineNumber );
		 return RECORD_Lex;}
REM		{yylval = new tree( g_LineNumber );
		 return REM_Lex;}
RENAMES		{yylval = new tree( g_LineNumber );
		 return RENAMES_Lex;}
RETURN		{yylval = new tree( g_LineNumber );
		 return RETURN_Lex;}
REVERSE		{yylval = new tree( g_LineNumber );
		 return REVERSE_Lex;}
SELECT		{yylval = new tree( g_LineNumber );
		 return SELECT_Lex;}
SEPARATE	{yylval = new tree( g_LineNumber );
		 return SEPARATE_Lex;}
SUBTYPE		{yylval = new tree( g_LineNumber );
		 return SUBTYPE_Lex;}
TASK		{yylval = new tree( g_LineNumber );
		 return TASK_Lex;}
TERMINATE	{yylval = new tree( g_LineNumber );
		 return TERMINATE_Lex;}
THEN		{yylval = new tree( g_LineNumber );
		 return THEN_Lex;}
TYPE		{yylval = new tree( g_LineNumber );
		 return TYPE_Lex;}
USE		{yylval = new tree( g_LineNumber );
		 return USE_Lex;}
WHEN		{yylval = new tree( g_LineNumber );
		 return WHEN_Lex;}
WHILE		{yylval = new tree( g_LineNumber );
		 return WHILE_Lex;}
WITH		{yylval = new tree( g_LineNumber );
		 return WITH_Lex;}
XOR		{yylval = new tree( g_LineNumber );
		 return XOR_Lex;}
ALIASED		{yylval = new tree( g_LineNumber );
		 return ALIASED_Lex;}
PROTECTED	{yylval = new tree( g_LineNumber );
		 return PROTECTED_Lex;}
REQUEUE		{yylval = new tree( g_LineNumber );
		 return REQUEUE_Lex;}
TAGGED		{yylval = new tree( g_LineNumber );
		 return TAGGED_Lex;}
UNTIL		{yylval = new tree( g_LineNumber );
		 return UNTIL_Lex;}




{Identificateur}	{
			#ifdef VERBOSE
			printf("Identificateur: %s\n",yytext);
			#endif
			yylval = new tree(Node_Ada_C_Ident,g_LineNumber,(char *) strdup( yytext ));
			return IDF_Lex;
			}

{Entier}		{
			#ifdef VERBOSE
			printf("Entier: %s\n",yytext);
			#endif
			yylval = new treeInteger(g_LineNumber,(char *) strdup( yytext ));
			return CONSTENT_Lex;
			}
		
{LitteralBase}		{
			#ifdef VERBOSE
			printf("Litteral base: %s\n",yytext);
			#endif
			yylval = new treeBased( g_LineNumber, yytext );
			return CONSTREEL_Lex;
			}
		
{LitteralDecimal}	{
			#ifdef VERBOSE
			printf("Litteral numerique: %s\n",yytext);
			#endif
			yylval = new treeFloat( g_LineNumber, yytext );
			return CONSTREEL_Lex;
			}
		
{LitteralChaine}	{
			#ifdef VERBOSE
			printf("Litteral chaine: %s\n",yytext);
			#endif
			yylval = new tree(Node_Ada_C_String,g_LineNumber,(char *) strdup( yytext ));
			return CONSTCHAINE_Lex;
			}

{Commentaire}		{
			#ifdef VERBOSE
			printf("comment : %s\n",yytext);
			#endif
			yylval = new tree(Node_Ada_C_Comment,g_LineNumber,(char *) strdup( yytext ));
			return COMMENT_Lex;
			}

"'"."'"		{
		#ifdef VERBOSE
		printf("Quote char : %s\n",yytext);
		#endif
		yylval = new tree(Node_Ada_C_Quote_Char,g_LineNumber,(char *) strdup( yytext ));
		return QUOTECHAR_Lex;
		}

		
".."		{yylval = new tree( g_LineNumber );
		return INTER_Lex;
		}
		
"<>"		{yylval = new tree( g_LineNumber );
		return BOX_Lex;
		}		
		
"<<"		{yylval = new tree( g_LineNumber );
		return LABEL_LEFT_Lex;
		}		
		
">>"		{yylval = new tree( g_LineNumber );
		return LABEL_RIGHT_Lex;
		}		

":="		{yylval = new tree( g_LineNumber );
		return AFFECT_Lex;
		}		

"=>"		{yylval = new tree( g_LineNumber );
		return ARROW_Lex;
		}		

">="		{yylval = new tree( g_LineNumber );
		return SUPEGAL_Lex;
		}		

"/="		{yylval = new tree( g_LineNumber );
		return DIFF_Lex;
		}		

"=/"		{yylval = new tree( g_LineNumber );
		return DIFF_Lex;
		}		
"<="		{yylval = new tree( g_LineNumber );
		return INFEGAL_Lex;
		}		
"**"		{yylval = new tree( g_LineNumber );
		return POWER_Lex;
		}		
"|"		{yylval = new tree( g_LineNumber );
		return '|';
		}		
"&"		{yylval = new tree( g_LineNumber );
		return '&';
		}		
"<"		{yylval = new tree( g_LineNumber );
		return '<';
		}		

">"		{yylval = new tree( g_LineNumber );
		return '>';
		}		

\=		{yylval = new tree( g_LineNumber );
		return '=';
		}		

\+		{yylval = new tree( g_LineNumber );
		return '+';
		}		

\-		{yylval = new tree( g_LineNumber );
		return '-';
		}		

\*		{yylval = new tree( g_LineNumber );
		return '*';
		}		

\/		{yylval = new tree( g_LineNumber );
		return '/';
		}		

\.		{yylval = new tree( g_LineNumber );
		 return '.';
		}		

\,		{yylval = new tree( g_LineNumber );
		return ',';
		}		

"'"		{yylval = new tree( g_LineNumber );
		return '\'';
		}		

\:		{yylval = new tree( g_LineNumber );
		return ':';
		}		

\(		{yylval = new tree( g_LineNumber );
		return '(';
		}		

\)		{yylval = new tree( g_LineNumber );
		return ')';
		}		

\;		{yylval = new tree( g_LineNumber );
		return ';';
		}		
		
\r\n		{yylval = new tree( g_LineNumber );
		g_LineNumber=g_LineNumber+1;
		}
\n		{yylval = new tree( g_LineNumber );
		g_LineNumber=g_LineNumber+1;
		}

\f		{ /* on supprime les Form Feed */
		}

{Separateur}		{ /* on supprime et les tabulations.*/
		}

.		{
		// this case occur og_LineNumbery if program has a lexical error
		fprintf(stderr,"(E) ligne %d : lexical error : Unrecognized token '%s'\n", g_LineNumber, yytext);
		exit( EXIT_FAILURE );
		}

%%


