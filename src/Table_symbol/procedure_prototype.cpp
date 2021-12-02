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
 * Description: declaration of procedure_protoype class
 *
 * $Log: procedure_prototype.cpp,v $
 * Revision 1.2  2005/03/19 08:32:04  quicky2000
 * Update to add the cvs log flag
 *
 *
 *****************************************************************************/
#include "procedure_prototype.h"

list<parameter*>* procedure_prototype::getParameters(void)
{
	return m_Parameters;
}
parameter* procedure_prototype::getParameter(char *p_Name)
{
	return getByName(p_Name,m_Parameters)->getItem();
}

void procedure_prototype::checkIntegrity(char *p_FileName, int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	char l_Error=0;
	if(m_BoolEmpty==0 && m_Parameters==NULL)
	{
		errorGeneric(p_FileName,p_LineNumber,"\"m_Parameter\" is NULL whereas \"m_BoolEmpty\" is equal to 0");
		l_Error=1;
	}
	if(m_BoolEmpty!=0 && m_Parameters!=NULL)
	{
		errorGeneric(p_FileName,p_LineNumber,"\"m_Parameter\" is not NULL whereas \"m_BoolEmpty\" is non equal to 0");
		l_Error=1;
	}
	if(l_Error!=0)
	{
		my_exit(1);
	}
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif

}

procedure_prototype::procedure_prototype(void)
{
	#ifdef TRACE
	printfTraceUp("procedure_prototype",__FILE__,__LINE__);
	#endif
	m_BoolEmpty=1;
	m_Parameters=NULL;
	checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("procedure_prototype",__FILE__,__LINE__);
	#endif
}

procedure_prototype::procedure_prototype(tree *p_FormalPartTree,main_unit *p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("procedure_prototype",__FILE__,__LINE__);
	#endif
	m_BoolEmpty=0;
	m_Parameters=NULL;
	if(p_FormalPartTree->getNodeType()!=Node_Ada_C_Empty)
	{
		m_Parameters=getListParameter(p_FormalPartTree->getSon(0),m_Parameters,p_MainUnit);
	}
	else
	{
		m_BoolEmpty=1;
	}
	checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("procedure_prototype",__FILE__,__LINE__);
	#endif
}


