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
 * Description: conservation of input source commentary
 *
 * $Log: jt_seq.cpp,v $
 * Revision 1.1  2005/03/07 23:32:35  quicky2000
 * Update to modify include paths due to to new source organization
 *
 * Revision 1.1.1.1  2005/03/01 22:20:39  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/

#include "../../src/Tools/tree.h"
#define YYSTYPE tree*

#include <stdlib.h>

//make sure this is after tree import
#include "../../obj/y.tab.h"

 //reference on the tree where commentary will be stocked
comment* commentaire=NULL;

//reference on a tree used to run through the tree referenced by "comentaire"
comment* current=NULL;

//jt_seq is the original yylex function
extern int jt_seq(void);

//myToken receive the token given by original yylex function
int myToken;

/*****************************************************************************
 * Function name : yylex 
 *
 * Input : none
 * Output : int
 * Modified variable : none
 * Description : function wich overloads yylex function of flex and allows to 
 * keep the commentary of input source file. it calls original yylex function
 * renamed into jt_seq ( cf #define YY_LEX in lexico.l ) if the token given by
 * jt_seq is a commentary, it is stocked in "commentaire"  tree. when an 
 * identifier token is given by jt_seq, the tree "commentaire" is add to this 
 * token.
 *****************************************************************************/
int yylex(void)
{
	
	do
	{
		myToken=jt_seq();
		
		if(myToken==COMMENT_Lex)
		{
		
			if(commentaire!=NULL)
			{
			current->addComment(new comment(static_cast<tree*>(yylval)->getNumLine(),static_cast<tree*>(yylval)->getString()));
			current=current->getNext();
			}
			else
			{
			commentaire=new comment(((tree*)yylval)->getNumLine(),((tree*)yylval)->getString());
			current=commentaire;
			}
		}

	}while(myToken==COMMENT_Lex);
	
	
	if(commentaire!=NULL && myToken==IDF_Lex)
	{
		((tree*)yylval)->addComment(commentaire);
		current=commentaire;
		do
		{
		current=current->getNext();
		}while(current!=NULL);
		
		commentaire=NULL;
		current=NULL;
		
	}
	return myToken;
}
