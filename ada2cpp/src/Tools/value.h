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
 * Description: declaration of "value" class
 *****************************************************************************/

/* ================ PROTECTION CONTRE LES DOUBLES DEFINITIONS =============== */
#ifndef VALUE_H
#define VALUE_H

/* ========================================================================== */
/* DIRECTIVES D'INCLUSION (include)                                           */
/* ========================================================================== */
 #include "error.h"
 #include "trace.h"
 
/* ========================================================================== */
/* CLASSES UTILISEES							                              */
/* ========================================================================== */
class tree;

/* ========================================================================== */
/* DECLARATIONS DES CLASSES				                         		      */
/* ========================================================================== */
/* $ ------------------------------------------------------------------------ */
/* $ CLASS			: value													  */
/* $ DESCRIPTION    : class which contains a tree and the numeric value it    */
/* $	represents.															  */
/* $	A boolean value indicate if numeric value is known					  */
/* $ ------------------------------------------------------------------------ */
 class value
  {
  	/* ============ */
	/* PRIVATE PART */
  	/* ============ */
	private:
	/* $ -------------------------------------------------------------------- */
	/* $ MEMBER			: m_Tree                                              */
	/* $ DESCRIPTION    : reference on the tree which represents a numeric	  */
	/* $	value															  */
	/* $ -------------------------------------------------------------------- */
	tree *m_Tree;
	
	/* $ -------------------------------------------------------------------- */
	/* $ MEMBER			: m_NumValue                                          */
	/* $ DESCRIPTION    : double value which is the numeric value represented */
	/* $	by the tree														  */
	/* $ -------------------------------------------------------------------- */
	double m_NumValue;

	/* $ -------------------------------------------------------------------- */
	/* $ MEMBER			: m_BoolComputed                                      */
	/* $ DESCRIPTION    : boolean value which indicates if numeric value	  */
	/* $	repesented by tree is known										  */
	/* $ -------------------------------------------------------------------- */
	char m_BoolComputed;

	/* $ -------------------------------------------------------------------- */
	/* $ MEMBER			: m_BoolComputable                                    */
	/* $ DESCRIPTION    : boolean value which indicates if numeric can be	  */
	/* $	computable														  */
	/* $ -------------------------------------------------------------------- */
	char m_BoolComputable;


	
	/* =========== */
	/* PUBLIC PART */
  	/* =========== */
	public:
	/* ====================================================================== */
	/* PROTOTYPES DES CONSTRUCTEURS				                              */
	/* ====================================================================== */
	/* $ -------------------------------------------------------------------- */
	/* $ constructor : value												  */
	/* $ Input :	None													  */
	/* $ Description :	Empty constructor									  */
	/* $ -------------------------------------------------------------------- */
	value(void);

	/* $ -------------------------------------------------------------------- */
	/* $ constructor :	value												  */
	/* $ Input :		p_Tree - reference on the tree which represents the   */
	/* $	value															  */
	/* $ Description :	constructor of value whith a tree whose value is not  */
	/* $	known at value build											  */
	/* $ -------------------------------------------------------------------- */
	value(tree *p_Tree);

	/* $ -------------------------------------------------------------------- */
	/* $ constructor :	value												  */
	/* $ Input :		p_Tree - reference on the tree which represents the   */
	/* $	value															  */
	/* $				p_NumValue - value of tree represented by p_Tree	  */
	/* $ Description :	constructor of value whith a tree whose value is	  */
	/* $		known at value build										  */
	/* $ -------------------------------------------------------------------- */
	value(tree *p_Tree, double p_NumValue);

	/* ====================================================================== */
	/* PROTOTYPES DES METHODES					                              */
	/* ====================================================================== */
	/* $ -------------------------------------------------------------------- */
	/* $ Method name : checkIntegrity										  */
	/* $ Input : p_FileName - Name of the file where the method was called    */
	/* $		 p_LineNumber - Line of the file where the method was called  */
	/* $ Output : None														  */
	/* $ Modified variable : NONE											  */
	/* $ Description :	methode wich checks the content of variable class to  */
	/* $	detect incoherences												  */
	/* $ -------------------------------------------------------------------- */
	void checkIntegrity(const char *p_FileName, int p_LineNumber);

	/* $ -------------------------------------------------------------------- */
	/* $ Method name : isBoolComputed										  */
	/* $ Input :	NONE					    							  */
	/* $ Output :	char - boolean which indicates if numeric value is known  */
	/* $ Modified variable :	NONE										  */
	/* $ Description :	this method return 0 if numeric value is known and a  */
	/* $	non zero value in contrary case									  */
	/* $ -------------------------------------------------------------------- */
	char isBoolComputed(void);

	/* $ -------------------------------------------------------------------- */
	/* $ Method name : isBoolComputable										  */
	/* $ Input :	NONE					    							  */
	/* $ Output :	char - boolean which indicates if numeric value is		  */
	/* $			computable												  */
	/* $ Modified variable :	NONE										  */
	/* $ Description :	this method return 0 if numeric value is computable   */
	/* $	and a non zero value in contrary case							  */
	/* $ -------------------------------------------------------------------- */
	char isBoolComputable(void);

	/* $ -------------------------------------------------------------------- */
	/* $ Method name : getTree												  */
	/* $ Input :	NONE					    							  */
	/* $ Output :	tree* - reference on the tree which represents the value  */
	/* $ Modified variable :	NONE										  */
	/* $ Description :	this method return the content of member m_Tree		  */
	/* $ -------------------------------------------------------------------- */
	tree* getTree(void);

	/* $ -------------------------------------------------------------------- */
	/* $ Method name : getNumValue											  */
	/* $ Input :	NONE					    							  */
	/* $ Output :	double - the numeric value repesented by the tree		  */
	/* $ Modified variable :	NONE										  */
	/* $ Description :	this method return the content of member m_NumValue	  */
	/* $ -------------------------------------------------------------------- */
	double getNumValue(void);


	/* $ -------------------------------------------------------------------- */
	/* $ Method name : setNumValue											  */
	/* $ Input :	p_Double -	the numeric value repesented by the tree      */
	/* $ Output :	value*	- reference on itself							  */
	/* $ Modified variable :	m_BoolComputed								  */
	/* $						m_BoolUnComputable							  */
	/* $ Description :	this affect the value passed in paramter to member	  */
	/* $	m_NumValue, set m_BoolComputed to 1 and return a reference on the */
	/* $	modified class variable											  */
	/* $ -------------------------------------------------------------------- */
	value* setNumValue(double p_Double);
	
	/* $ -------------------------------------------------------------------- */
	/* $ Method name : setUnComputable										  */
	/* $ Input :	NONE												      */
	/* $ Output :	value*	- reference on itself							  */
	/* $ Modified variable :	m_BoolUnComputable							  */
	/* $ Description :	this affect the value passed in paramter to member	  */
	/* $	m_BoolUnComputable and return a reference on the modified class   */
	/* $	variable														  */
	/* $ -------------------------------------------------------------------- */
	value* setUnComputable(void);
	
  };
 
 value* operator+(value p_Value1,value p_Value2);
/* ================ FIN PROTECTION CONTRE LES DOUBLES DEFINITIONS =========== */
#endif

/* ================ FIN DU FICHIER DE SPECIFICATION ========================= */
