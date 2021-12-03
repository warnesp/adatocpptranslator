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
 * Description: instantiation of access_type class
 *
 * $Log: access_type.cpp,v $
 * Revision 1.2  2005/03/17 22:25:17  quicky2000
 * Update to add cvs log flag
 *
 *
 *****************************************************************************/
#include "access_type.h"

void displayAccessTypeId(t_AccessTypeId p_AccessTypeId)
{
	switch(p_AccessTypeId)
	{
		case Access_Type_Object:printf("Access_Type_Object");break;
		case Access_Type_Subprog:printf("Access_Type_Subprog");break;
		case Access_Type_Undefined:printf("Access_Type_Undefined");break;
		default:
		printf("INTERNAL ERROR : %s %i : access type id %i is not manage\n",__FILE__,__LINE__,p_AccessTypeId);
		my_exit(-1);
		break;
	}
}

void access_type::checkIntegrity(const char *p_FileName, int p_LineNumber)
{	
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	int error=0;
	
	if(m_AccessTypeId==Access_Type_Undefined)
	{
		printf("INTERNAL ERROR : %s %i : member \"m_AccessTypeId\" is \"",p_FileName,p_LineNumber);
		displayAccessTypeId(m_AccessTypeId);
		printf("\"\n");
		error=1;
	}
	
	elementary_type::checkIntegrity(p_FileName,p_LineNumber);
	if(error!=0)
	{
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
}

t_AccessTypeId access_type::getAccessTypeId(void)
{
	return m_AccessTypeId;
}
	
access_type::access_type(void):elementary_type(Elementary_Type_Access)
{
	#ifdef TRACE
	printfTraceUp("access_type",__FILE__,__LINE__);
	#endif
	m_AccessTypeId=Access_Type_Undefined;
	#ifdef TRACE
	printfTraceDown("access_type",__FILE__,__LINE__);
	#endif
	
}

access_type::access_type(t_AccessTypeId p_AccessTypeId):elementary_type(Elementary_Type_Access)
{
	#ifdef TRACE
	printfTraceUp("access_type",__FILE__,__LINE__);
	#endif
	m_AccessTypeId=p_AccessTypeId;
	#ifdef TRACE
	printfTraceDown("access_type",__FILE__,__LINE__);
	#endif
}


access_type::access_type(t_AccessTypeId p_AccessTypeId,const char *p_Name,main_unit *p_MainUnit):elementary_type(Elementary_Type_Access,p_Name,p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("access_type",__FILE__,__LINE__);
	#endif
	m_AccessTypeId=p_AccessTypeId;
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("access_type",__FILE__,__LINE__);
	#endif
	
}
