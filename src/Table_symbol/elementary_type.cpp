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
 * Description: instantiation of elementary_type class
 *
 * $Log: elementary_type.cpp,v $
 * Revision 1.1  2005/03/13 14:36:02  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 *
 * Revision 1.1.1.1  2005/03/01 22:20:36  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "elementary_type.h"

void displayElementaryTypeId(t_ElementaryTypeId p_ElementaryTypeId)
{
	switch(p_ElementaryTypeId)
	{
		case Elementary_Type_Access:printf("Elementary_Type_Access");break;
		case Elementary_Type_Scalar:printf("Elementary_Type_Scalar");break;
		case Elementary_Type_Undefined:printf("Elementary_Type_Undefined");break;
		default:
		printf("INTERNAL ERROR : %s %i : elementary type id %i is not manage\n",__FILE__,__LINE__,p_ElementaryTypeId);
		my_exit(-1);
		break;
	}
}

void elementary_type::checkIntegrity(char *p_FileName, int p_LineNumber)
{	
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	int error=0;
	
	if(m_ElementaryTypeId==Elementary_Type_Undefined)
	{
		printf("INTERNAL ERROR : %s %i : member \"m_ElementaryTypeId\" is \"",p_FileName,p_LineNumber);
		displayElementaryTypeId(m_ElementaryTypeId);
		printf("\"\n");
		error=1;
	}
	
	type::checkIntegrity(p_FileName,p_LineNumber);
	if(error!=0)
	{
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
}

t_ElementaryTypeId elementary_type::getElementaryTypeId(void)
{
	return m_ElementaryTypeId;
}
	
elementary_type::elementary_type(void):type(Type_Elementary)
{
	#ifdef TRACE
	printfTraceUp("elementary_type",__FILE__,__LINE__);
	#endif
	m_ElementaryTypeId=Elementary_Type_Undefined;
	#ifdef TRACE
	printfTraceDown("elementary_type",__FILE__,__LINE__);
	#endif
	
}

elementary_type::elementary_type(t_ElementaryTypeId p_ElementaryTypeId):type(Type_Elementary)
{
	#ifdef TRACE
	printfTraceUp("elementary_type",__FILE__,__LINE__);
	#endif
	m_ElementaryTypeId=p_ElementaryTypeId;
	#ifdef TRACE
	printfTraceDown("elementary_type",__FILE__,__LINE__);
	#endif
}


elementary_type::elementary_type(t_ElementaryTypeId p_ElementaryTypeId,char *p_Name,main_unit *p_MainUnit):type(Type_Elementary,p_Name,p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("elementary_type",__FILE__,__LINE__);
	#endif
	m_ElementaryTypeId=p_ElementaryTypeId;
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("elementary_type",__FILE__,__LINE__);
	#endif
	
}
