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
 * Description: instantiation of type class
 *
 * $Log: type.cpp,v $
 * Revision 1.1  2005/03/13 16:50:27  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 *
 * Revision 1.1.1.1  2005/03/01 22:20:51  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "type.h"
void errorNotManage(char *p_FileName,int p_LineNumber,t_TypeId p_TypeId)
{
	printf("ERROR : %s %i : type id %i is not manage\n",p_FileName,p_LineNumber,p_TypeId);
}

void displayTypeId(t_TypeId p_TypeId)
{
	switch(p_TypeId)
	{
		case Type_Composite:printf("Type_Composite");break;
		case Type_Derived:printf("Type_Derived");break;
		case Type_Elementary:printf("Type_Elementary");break;
		case Type_Subtype:printf("Type_Subtype");break;
		case Type_Undefined:printf("Type_Undefined");break;
		default:
		errorNotManage(__FILE__,__LINE__,p_TypeId);
		break;
	}
}

void type::checkIntegrity(char *p_FileName, int p_LineNumber)
{	
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	int error=0;
	
	if(m_TypeId==Type_Undefined)
	{
		printf("ERROR : %s %i : member \"m_TypeId\" is \"",p_FileName,p_LineNumber);
		displayTypeId(m_TypeId);
		printf("\"\n");
		error=1;
	}
	
	unit::checkIntegrity(p_FileName,p_LineNumber);
	if(error!=0)
	{
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
}

t_TypeId type::getTypeId(void)
{
	return m_TypeId;
}

type::type(void):unit()
{
	#ifdef TRACE
	printfTraceUp("type",__FILE__,__LINE__);
	#endif
	m_TypeId=Type_Undefined;
	#ifdef TRACE
	printfTraceDown("type",__FILE__,__LINE__);
	#endif
}

type::type(t_TypeId p_TypeId):unit()
{
	#ifdef TRACE
	printfTraceUp("type",__FILE__,__LINE__);
	#endif
	m_TypeId=p_TypeId;
	#ifdef TRACE
	printfTraceDown("type",__FILE__,__LINE__);
	#endif
}

type::type(t_TypeId p_TypeId,char *p_Name,main_unit *p_MainUnit):unit(p_Name,p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("type",__FILE__,__LINE__);
	#endif
	m_TypeId=p_TypeId;
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("type",__FILE__,__LINE__);
	#endif
}
