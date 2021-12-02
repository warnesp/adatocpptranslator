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
 * Description: instantiation of variable class
 *
 * $Log: variable.cpp,v $
 * Revision 1.1  2005/03/13 16:50:27  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 *
 * Revision 1.1.1.1  2005/03/01 22:20:52  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "variable.h"

void displayVariableId(t_VariableId p_VariableId)
{
	switch(p_VariableId)
	{
		case Variable_Array:printf("Variable_Array");break;
		case Variable_Object:printf("Variable_Object");break;
		case Variable_Undefined:printf("Variable_Undefined");break;
		default:
		printf("ERROR : %s %i : variable id %i is not manage\n",__FILE__,__LINE__,p_VariableId);
		break;
	}
}

t_VariableId variable::getVariableId(void)
{
	return m_VariableId;
}

char variable::getBoolConstant(void)
{
	return m_BoolConstant;
}

void variable::checkIntegrity(char *p_FileName,int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	int error=0;
	
	if(m_VariableId==Variable_Undefined)
	{
		printf("ERROR : %s %i : member \"m_VariableId\" is \"",p_FileName,p_LineNumber);
		displayVariableId(m_VariableId);
		printf("\"\n");
		error=1;
	}
	unit::checkIntegrity(p_FileName,p_LineNumber);
	object::checkIntegrity(p_FileName,p_LineNumber);
	
	if(error!=0)
	{
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
}

variable::variable(void):unit(),object()
{
	#ifdef TRACE
	printfTraceUp("variable",__FILE__,__LINE__);
	#endif
	m_VariableId=Variable_Undefined;
	m_BoolConstant=0;
	#ifdef TRACE
	printfTraceDown("variable",__FILE__,__LINE__);
	#endif
}

variable::variable(t_VariableId p_VariableId)
{
	#ifdef TRACE
	printfTraceUp("variable",__FILE__,__LINE__);
	#endif
	m_VariableId=p_VariableId;
	m_BoolConstant=0;
	#ifdef TRACE
	printfTraceDown("variable",__FILE__,__LINE__);
	#endif
}	
variable::variable(t_VariableId p_VariableId,char *p_Name,char p_Constant,char p_Aliased,main_unit *p_MainUnit):unit(p_Name,p_MainUnit),object(p_Aliased)
{
	#ifdef TRACE
	printfTraceUp("variable",__FILE__,__LINE__);
	#endif
	m_VariableId=p_VariableId;
	m_BoolConstant=p_Constant;
	#ifdef TRACE
	printfTraceDown("variable",__FILE__,__LINE__);
	#endif
}

variable::variable(t_VariableId p_VariableId,char *p_Name,char p_Constant,char p_Aliased,tree *p_InitTree,main_unit *p_MainUnit):unit(p_Name,p_MainUnit),object(p_Aliased,p_InitTree)
{
	#ifdef TRACE
	printfTraceUp("variable",__FILE__,__LINE__);
	#endif
	m_VariableId=p_VariableId;
	m_BoolConstant=p_Constant;
	#ifdef TRACE
	printfTraceDown("variable",__FILE__,__LINE__);
	#endif
}
