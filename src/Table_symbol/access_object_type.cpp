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
 * Description: instantiation of access_object_type class
 *
 * $Log: access_object_type.cpp,v $
 * Revision 1.3  2005/03/26 23:54:10  quicky2000
 * Update to replace the parameter which represent type by a tree instead of a string to manage type represents by complex nodes like selected comp...
 *
 * Revision 1.2  2005/03/17 20:30:24  quicky2000
 * Update to add cvs log flag
 *
 *
 *****************************************************************************/
#include "access_object_type.h"

void displayAccessObjectTypeId(t_AccessObjectTypeId p_AccessObjectTypeId)
{
	switch(p_AccessObjectTypeId)
	{
		case Access_Object_Type_All: printf("Access_Object_Type_All");break;
		case Access_Object_Type_Constant: printf("Access_Object_Type_Constant");break;
		case Access_Object_Type_Normal: printf("Access_Object_Type_Normal");break;
		case Access_Object_Type_Undefined: printf("Access_Object_Type_Undefined");break;
		default:
		printf("INTERNAL ERROR : %s %i : access object type id %i is not manage\n",__FILE__,__LINE__,p_AccessObjectTypeId);
		my_exit(-1);
		break;
	}
}

t_AccessObjectTypeId access_object_type::getAccessObjectTypeId(void)
{
	return m_AccessObjectTypeId;
}

void access_object_type::checkIntegrity(const char *p_FileName,int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp("access_object_type",__FILE__,__LINE__);
	#endif
	int error=0;
	
	if(m_AccessObjectTypeId==Access_Object_Type_Undefined)
	{
		printf("INTERNAL ERROR : %s %i : member \"m_AccessObjectTypeId\" is \"",p_FileName,p_LineNumber);
		displayAccessObjectTypeId(m_AccessObjectTypeId);
		printf("\"\n");
		error=1;
	}
	
	access_type::checkIntegrity(p_FileName,p_LineNumber);
	typed::checkIntegrity(p_FileName,p_LineNumber);
	
	if(error!=0)
	{
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
}
	
access_object_type::access_object_type(void):access_type(Access_Type_Object),typed()
{
	#ifdef TRACE
	printfTraceUp("access_object_type",__FILE__,__LINE__);
	#endif
	m_AccessObjectTypeId=Access_Object_Type_Undefined;
	#ifdef TRACE
	printfTraceDown("access_object_type",__FILE__,__LINE__);
	#endif
}

access_object_type::access_object_type(t_AccessObjectTypeId p_AccessObjectTypeId,const char *p_Name,tree *p_TypeTree,main_unit *p_MainUnit):access_type(Access_Type_Object,p_Name,p_MainUnit),typed(p_TypeTree)
{
	#ifdef TRACE
	printfTraceUp("access_object_type",__FILE__,__LINE__);
	#endif
	m_AccessObjectTypeId=p_AccessObjectTypeId;
	#ifdef TRACE
	printfTraceDown("access_object_type",__FILE__,__LINE__);
	#endif
}

access_object_type* new_access_object_type(const char *p_Name,tree *p_AccessTree,main_unit *p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("new_access_object_type",__FILE__,__LINE__);
	#endif
	access_object_type *result =NULL;
	t_AccessObjectTypeId p_AccessObjectTypeId=Access_Object_Type_Undefined;
	
	if(p_AccessTree!=NULL)
	{
		switch(p_AccessTree->getNodeType())
		{
			case Node_Ada_Access_Type:p_AccessObjectTypeId=Access_Object_Type_Normal;break;
			case Node_Ada_Access_Constant_Type:p_AccessObjectTypeId=Access_Object_Type_Constant;break;
			case Node_Ada_Access_All_Type:p_AccessObjectTypeId=Access_Object_Type_All;break;
			default:
			errorNotAllowed(__FILE__,__LINE__,p_AccessTree,"access_type");
			my_exit(-1);
			break;
		}
		result=new access_object_type(p_AccessObjectTypeId,p_Name,p_AccessTree->getSon(0)->getSon(0),p_MainUnit);
		
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_AccessTree");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("new_access_object_type",__FILE__,__LINE__);
	#endif
	
	return result;
}
