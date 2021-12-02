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
 * Description: instantiation of typed class
 *
 * $Log: typed.cpp,v $
 * Revision 1.2  2005/03/27 01:02:41  quicky2000
 * Update to replace the memeber type name by:
 * _ a reference ont ree which represents the type
 * _ a reference on the type
 * _ boolean to indicate if the reference on type was computed from the representation of type
 *
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
#include "typed.h"

#include "../Tools/tree_string_representation.h"

const char* typed::getTypeName(void)
{
	this->checkIntegrity(__FILE__,__LINE__);
	return getString(m_TypeTree);
}
	
tree* typed::getTypeTree(void)
{
	this->checkIntegrity(__FILE__,__LINE__);
	return m_TypeTree;
}

type* typed::getType(void)
{
	if(m_BoolFound==0)
	{
		errorGeneric(__FILE__,__LINE__,"type not found\n");
		my_exit(-1);
	}
	return m_Type;
}

char typed::isBoolFound(void)
{
	return m_BoolFound;
}

char typed::isBoolSearched(void)
{
	return m_BoolSearched;
}
	
typed* typed::setTypeFound(type *p_Type)
{
	#ifdef TRACE
	printfTraceUp("setTypeFound",__FILE__,__LINE__);
	#endif
	m_BoolFound=1;
	m_BoolSearched=1;
	m_Type=p_Type;
	#ifdef TRACE
	printfTraceDown("setTypeFound",__FILE__,__LINE__);
	#endif
	return this;

}

typed* typed::setTypeNotFound(void)
{
	#ifdef TRACE
	printfTraceUp("setTypeNotFound",__FILE__,__LINE__);
	#endif
	m_BoolSearched=1;
	#ifdef TRACE
	printfTraceDown("setTypeNotFound",__FILE__,__LINE__);
	#endif
	return this;

}

void typed::checkIntegrity(const char *p_FileName,int p_LineNumber)
{
	int l_Error=0;
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	
	if(m_TypeTree==NULL)
	{
		errorIsNull(p_FileName,p_LineNumber,"m_TypeName");
		l_Error=1;
	}
	if(m_Type==NULL && m_BoolFound!=0)
	{
		errorGeneric(p_FileName,p_LineNumber,"\"m_Type\" is NULL whereas \"m_BoolFound\" is not equal to 0");
		l_Error=1;
	}
	if(m_Type!=NULL && m_BoolFound==0)
	{
		errorGeneric(p_FileName,p_LineNumber,"\"m_Type\" is not NULL whereas \"m_BoolFound\" is equal to 0");
		l_Error=1;
	}
	if(l_Error!=0)
	{
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
	
}

typed::typed(void)
{
	m_TypeTree=NULL;
	m_BoolSearched=0;
	m_BoolFound=0;
	m_Type=NULL;
}
	
typed::typed(tree *p_Tree)
{
	#ifdef TRACE
	printfTraceUp("typed",__FILE__,__LINE__);
	#endif
	m_TypeTree = p_Tree;
	m_BoolSearched=0;
	m_BoolFound=0;
	m_Type=NULL;
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("typed",__FILE__,__LINE__);
	#endif
}
