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
 * Description: instantiation of composite_type class
 *
 * $Log: composite_type.cpp,v $
 * Revision 1.1  2005/03/13 14:36:02  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 *
 * Revision 1.1.1.1  2005/03/01 22:20:35  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "composite_type.h"

void displayCompositeTypeId(t_CompositeTypeId p_CompositeTypeId)
{
	switch(p_CompositeTypeId)
	{
		case Composite_Type_Array:printf("Composite_Type_Array");break;
		case Composite_Type_Record:printf("Composite_Type_Record");break;
		case Composite_Type_Undefined:printf("Composite_Type_Undefined");break;
		default:
		printf("INTERNAL ERROR : %s %i : composite type id %i is not manage\n",__FILE__,__LINE__,p_CompositeTypeId);
		break;
	}
}

void composite_type::checkIntegrity(char *p_FileName,int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	int error=0;
	
	if(m_CompositeTypeId==Composite_Type_Undefined)
	{
		printf("INTERNAL ERROR : %s %i :member \"m_CompositeTypeId\" value is \"",p_FileName,p_LineNumber);
		displayCompositeTypeId(m_CompositeTypeId);
		printf("\"\n");
		error=1;
	}
	if(error!=0)
	{
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
}

t_CompositeTypeId composite_type::getCompositeTypeId(void)
{
	return m_CompositeTypeId;
}
	
composite_type::composite_type(void):type(Type_Composite)
{
	#ifdef TRACE
	printfTraceUp("composite_type",__FILE__,__LINE__);
	#endif
	m_CompositeTypeId=Composite_Type_Undefined;
	#ifdef TRACE
	printfTraceDown("composite_type",__FILE__,__LINE__);
	#endif
}

composite_type::composite_type(t_CompositeTypeId p_CompositeTypeId):type(Type_Composite)
{
	#ifdef TRACE
	printfTraceUp("composite_type",__FILE__,__LINE__);
	#endif
	m_CompositeTypeId=p_CompositeTypeId;
	#ifdef TRACE
	printfTraceDown("composite_type",__FILE__,__LINE__);
	#endif
}

composite_type::composite_type(t_CompositeTypeId p_CompositeTypeId,char *p_Name,main_unit *p_MainUnit):type(Type_Composite,p_Name,p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("composite_type",__FILE__,__LINE__);
	#endif
	m_CompositeTypeId=p_CompositeTypeId;
	#ifdef TRACE
	printfTraceDown("composite_type",__FILE__,__LINE__);
	#endif
}
