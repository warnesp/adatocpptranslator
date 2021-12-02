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
 * Description: instantiation of access_subprog_type class
 *
 * $Log: access_subprog_type.cpp,v $
 * Revision 1.4  2005/03/27 00:01:45  quicky2000
 * Update to replace the parameter which represent return type by a tree
 * instead of a string to manage type represents by complex nodes like
 * selected comp...
 *
 * Revision 1.3  2005/03/19 11:03:19  quicky2000
 * Update for code maintenance
 *
 * Revision 1.2  2005/03/17 20:35:04  quicky2000
 * Update:
 * _ to modify the constructor
 * _ for code maintenance
 *
 *
 *****************************************************************************/
#include "access_subprog_type.h"

#include "procedure_prototype.h"

void displayAccessSubprogTypeId(t_AccessSubprogTypeId p_AccessSubprogTypeId)
{
	switch(p_AccessSubprogTypeId)
	{
		case Access_Subprog_Type_Function:printf("Access_Subprog_Type_Function");break;
		case Access_Subprog_Type_Procedure:printf("Access_SubProg_Type_Procedure");break;
		case Access_Subprog_Type_Undefined:printf("Access_Subprog_Type_Undefined");break;
		default:
		printf("INTERNAL ERROR : %s %i : access subprog type id %i is not manage\n",__FILE__,__LINE__,p_AccessSubprogTypeId);
		my_exit(-1);
		break;
	}
}

void access_subprog_type::checkIntegrity(char *p_FileName, int p_LineNumber)
{	
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	int l_Error=0;
	
	if(m_AccessSubprogTypeId==Access_Subprog_Type_Undefined)
	{
		printf("INTERNAL ERROR : %s %i : member \"m_AccessSubprogTypeId\" is \"",p_FileName,p_LineNumber);
		displayAccessSubprogTypeId(m_AccessSubprogTypeId);
		printf("\"\n");
		l_Error=1;
	}
	if(m_Prototype==NULL)
	{
		errorIsNull(__FILE__,__LINE__,"m_Prototype");
		l_Error=1;
	}
	access_type::checkIntegrity(p_FileName,p_LineNumber);
	
	if(l_Error!=0)
	{
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
}

t_AccessSubprogTypeId access_subprog_type::getAccessSubprogTypeId(void)
{
	return m_AccessSubprogTypeId;
}

char access_subprog_type::getProtected(void)
{
	return m_Protected;
}

access_subprog_type::access_subprog_type(void):access_type(Access_Type_Subprog)
{
	#ifdef TRACE
	printfTraceUp("access_subprog_type",__FILE__,__LINE__);
	#endif
	m_AccessSubprogTypeId=Access_Subprog_Type_Undefined;
	m_Protected=0;
	m_Prototype=NULL;
	#ifdef TRACE
	printfTraceDown("access_subprog_type",__FILE__,__LINE__);
	#endif
	
}

access_subprog_type::access_subprog_type(t_AccessSubprogTypeId p_AccessSubprogTypeId):access_type(Access_Type_Subprog)
{
	#ifdef TRACE
	printfTraceUp("access_subprog_type",__FILE__,__LINE__);
	#endif
	m_AccessSubprogTypeId=p_AccessSubprogTypeId;
	m_Protected=0;
	m_Prototype=NULL;
	#ifdef TRACE
	printfTraceDown("access_subprog_type",__FILE__,__LINE__);
	#endif
}


access_subprog_type::access_subprog_type(t_AccessSubprogTypeId p_AccessSubprogTypeId,tree *p_ProtectedTree,char *p_Name,tree *p_FormalPartTree, tree *p_ReturnTypeTree, main_unit *p_MainUnit):access_type(Access_Type_Subprog,p_Name,p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("access_subprog_type",__FILE__,__LINE__);
	#endif
	if(p_FormalPartTree!=NULL && p_ReturnTypeTree!=NULL && p_ProtectedTree!=NULL)
	{
		m_AccessSubprogTypeId=p_AccessSubprogTypeId;
		m_Protected=0;
		if(p_ProtectedTree->getNodeType()==Node_Ada_Protected_Opt)
		{
			m_Protected=1;
		}
		m_Prototype=new function_prototype(p_FormalPartTree,p_ReturnTypeTree,p_MainUnit);
	}
	else
	{
		int l_Error=0;
		if(p_ProtectedTree==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_ProtectedTree");
			l_Error=1;
		}
		if(p_FormalPartTree==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_FormalPartTree");
			l_Error=1;
		}
		if(p_ReturnTypeTree==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_ReturnTypeTree");
			l_Error=1;
		}
		if(l_Error!=0)
		{
			my_exit(-1);
		}
	}
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("access_subprog_type",__FILE__,__LINE__);
	#endif
	
}

access_subprog_type::access_subprog_type(t_AccessSubprogTypeId p_AccessSubprogTypeId,tree *p_ProtectedTree,char *p_Name,tree *p_FormalPartTree, main_unit *p_MainUnit):access_type(Access_Type_Subprog,p_Name,p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("access_subprog_type",__FILE__,__LINE__);
	#endif
	if(p_FormalPartTree!=NULL && p_ProtectedTree!=NULL)
	{
		m_AccessSubprogTypeId=p_AccessSubprogTypeId;
		m_Protected=0;
		if(p_ProtectedTree->getNodeType()==Node_Ada_Protected_Opt)
		{
			m_Protected=1;
		}
		m_Prototype=new procedure_prototype(p_FormalPartTree,p_MainUnit);
	}
	else
	{
		int l_Error=0;
		if(p_ProtectedTree==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_ProtectedTree");
			l_Error=1;
		}
		if(p_FormalPartTree==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_FormalPartTree");
			l_Error=1;
		}
		if(l_Error!=0)
		{
			my_exit(-1);
		}
	}
	
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("access_subprog_type",__FILE__,__LINE__);
	#endif
	
}
