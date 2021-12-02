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
 * Description: instantiation of "value" class
 *****************************************************************************/

/* ========================================================================== */
/* DIRECTIVES D'INCLUSION (include)                                           */
/* ========================================================================== */
#include "value.h"

/* ========================================================================== */
/* PROTOTYPE DES SOUS PROGRAMMES INTERNES		                              */
/* ========================================================================== */
/* $ ------------------------------------------------------------------------ */
/* $ Method name : 															  */
/* $ Input : <parameter_name> - <descritpion>								  */
/* $ Output : 																  */
/* $ Modified variable : 													  */
/* $ Description :															  */
/* $ ------------------------------------------------------------------------ */

/* ========================================================================== */
/* IMPLEMANTATION DES CONSTRUCTEURS										      */
/* ========================================================================== */

/* $ -------------------------------------------------------------------- */
/* $ constructor : value												  */
/* $ Input :	None													  */
/* $ Description :	Empty constructor									  */
/* $ -------------------------------------------------------------------- */
value::value( void )
{
	#ifdef TRACE
	printfTraceUp( "value", __FILE__, __LINE__);
	#endif

	m_Tree = NULL ;
	m_NumValue = 0 ;
	m_BoolComputed = 0 ;
	m_BoolComputable = 0 ;

	#ifdef TRACE
	printfTraceDown( "value", __FILE__, __LINE__);
	#endif
}

/* $ -------------------------------------------------------------------- */
/* $ constructor :	value												  */
/* $ Input :		p_Tree - reference on the tree which represents the   */
/* $	value															  */
/* $ Description :	constructor of value whith a tree whose value is not  */
/* $	at variable build												  */
/* $ -------------------------------------------------------------------- */
value::value(tree *p_Tree)
{
	#ifdef TRACE
	printfTraceUp( "value", __FILE__, __LINE__);
	#endif

	m_Tree = p_Tree ;
	m_NumValue = 0 ;
	m_BoolComputed = 0 ;
	m_BoolComputable = 1 ;

	#ifdef TRACE
	printfTraceDown( "value", __FILE__, __LINE__);
	#endif
}

/* $ -------------------------------------------------------------------- */
/* $ constructor :	value												  */
/* $ Input :		p_Tree - reference on the tree which represents the   */
/* $	value															  */
/* $				p_NumValue - value of tree represented by p_Tree	  */
/* $ Description :	constructor of value whith a tree whose value is	  */
/* $		known at value build										  */
/* $ -------------------------------------------------------------------- */
value::value(tree *p_Tree, double p_NumValue)
{
	#ifdef TRACE
	printfTraceUp( "value", __FILE__, __LINE__);
	#endif

	m_Tree = new tree(Node_Ada_C_Empty,0);
	m_NumValue = p_NumValue ;
	m_BoolComputed = 1 ;
	m_BoolComputable = 1 ;

	#ifdef TRACE
	printfTraceDown( "value", __FILE__, __LINE__);
	#endif
}

/* ========================================================================== */
/* IMPLEMANTATION DES METHODES											      */
/* ========================================================================== */
/* $ ------------------------------------------------------------------------ */
/* $ Method name : checkIntegrity										  */
/* $ Input : p_FileName - Name of the file where the method was called    */
/* $		 p_LineNumber - Line of the file where the method was called  */
/* $ Output : None														  */
/* $ Modified variable : NONE											  */
/* $ Description :	methode wich checks the content of variable class to  */
/* $	detect incoherences												  */
/* $ ------------------------------------------------------------------------ */
void value::checkIntegrity(char *p_FileName, int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp( "checkIntegrity", __FILE__, __LINE__);
	#endif

	if( m_Tree == NULL )
	{
		errorIsNull(__FILE__, __LINE__,"m_Tree");
		my_exit(-1);
	}	

	#ifdef TRACE
	printfTraceDown( "checkIntegrity", __FILE__, __LINE__);
	#endif
}

/* $ -------------------------------------------------------------------- */
/* $ Method name : isBoolComputed										  */
/* $ Input :	NONE					    							  */
/* $ Output :	char - boolean which indicates if numeric value is known  */
/* $ Modified variable :	NONE										  */
/* $ Description :	this method return 0 if numeric value is known and a  */
/* $	non zero value in contrary case									  */
/* $ -------------------------------------------------------------------- */
char value::isBoolComputed(void)
{
	return m_BoolComputed;
}

/* $ -------------------------------------------------------------------- */
/* $ Method name : isBoolComputable										  */
/* $ Input :	NONE					    							  */
/* $ Output :	char - boolean which indicates if numeric value is		  */
/* $			computable												  */
/* $ Modified variable :	NONE										  */
/* $ Description :	this method return 0 if numeric value is computable   */
/* $	and a non zero value in contrary case							  */
/* $ -------------------------------------------------------------------- */
char value::isBoolComputable(void)
{
	return m_BoolComputable;
}

/* $ ------------------------------------------------------------------------ */
/* $ Method name : getTree													  */
/* $ Input :	NONE					    								  */
/* $ Output :	tree* - reference on the tree which represents the value	  */
/* $ Modified variable :	NONE											  */
/* $ Description :	this method return the content of member m_Tree			  */
/* $ ------------------------------------------------------------------------ */
tree* value::getTree(void)
{
	#ifdef TRACE
	printfTraceUp( "getTree", __FILE__, __LINE__);
	#endif

	checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown( "getTree", __FILE__, __LINE__);
	#endif

	return m_Tree;
}

/* $ ------------------------------------------------------------------------ */
/* $ Method name : getNumValue												  */
/* $ Input :	NONE					    								  */
/* $ Output :	double - the numeric value repesented by the tree			  */
/* $ Modified variable :	NONE											  */
/* $ Description :	this method return the content of member m_NumValue		  */
/* $ ------------------------------------------------------------------------ */
double value::getNumValue(void)
{
	#ifdef TRACE
	printfTraceUp( "getNumValue", __FILE__, __LINE__);
	#endif
	
	int l_Error=0;
	
	if(m_BoolComputed == 0)
	{
		errorGeneric(__FILE__,__LINE__,"Numeric value is not calculated");
		l_Error=1;
	}

	if(m_BoolComputable == 0)
	{
		errorGeneric(__FILE__,__LINE__,"Numeric value is not computable");
		l_Error=1;
	}

	if(l_Error!=0)
	{
			my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown( "getNumValue", __FILE__, __LINE__);
	#endif
	return m_NumValue;
}


/* $ ------------------------------------------------------------------------ */
/* $ Method name : setNumValue												  */
/* $ Input :	p_Double -	the numeric value repesented by the tree		  */
/* $ Output :	value*	- reference on itself								  */
/* $ Modified variable :	m_BoolEmpty										  */
/* $ Description :	this affect the value passed in paramter to member		  */
/* $	m_NumValue and return a reference on the modified class variable	  */
/* $ ------------------------------------------------------------------------ */
value* value::setNumValue(double p_Double)
{
	#ifdef TRACE
	printfTraceUp( "setNumValue", __FILE__, __LINE__);
	#endif
	m_NumValue = p_Double;
	m_BoolComputed = 1;
	m_BoolComputable = 1;
	#ifdef TRACE
	printfTraceDown( "setNumValue", __FILE__, __LINE__);
	#endif
	return this;
	
}

/* $ -------------------------------------------------------------------- */
/* $ Method name : setUnComputable										  */
/* $ Input :	NONE												      */
/* $ Output :	value*	- reference on itself							  */
/* $ Modified variable :	m_BoolUnComputable							  */
/* $ Description :	this affect the value passed in paramter to member	  */
/* $	m_BoolUnComputable and return a reference on the modified class   */
/* $	variable														  */
/* $ -------------------------------------------------------------------- */
value* value::setUnComputable(void)
{
	#ifdef TRACE
	printfTraceUp( "setUnComputable", __FILE__, __LINE__);
	#endif
	m_BoolComputable = 0;
	#ifdef TRACE
	printfTraceDown( "setUnComputable", __FILE__, __LINE__);
	#endif
	return this;
	
}

/* ========================================================================== */
/* PROTOTYPE DES OPERATEURS SURCHARGES			                              */
/* ========================================================================== */
