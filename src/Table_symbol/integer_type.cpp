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
 * Description: instantiation of integer_type class
 *
 * $Log: integer_type.cpp,v $
 * Revision 1.1  2005/03/13 16:36:27  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 *
 * Revision 1.1.1.1  2005/03/01 22:20:38  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "integer_type.h"

void displayIntegerTypeId(t_IntegerTypeId p_IntegerTypeId)
{
	switch(p_IntegerTypeId)
	{
		case Integer_Type_Modular:printf("Integer_Type_Modular");break;
		case Integer_Type_Signed:printf("Integer_Type_Signed");break;
		case Integer_Type_Undefined:printf("Integer_Type_Undefined");break;
		default:
		printf("INTERNAL ERROR : %s %i : integer type id %i is not manage\n",__FILE__,__LINE__,p_IntegerTypeId);
		my_exit(-1);
		break;
	}
}

void integer_type::checkIntegrity(char *p_FileName, int p_LineNumber)
{	
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	int error=0;
	
	if(m_IntegerTypeId==Integer_Type_Undefined)
	{
		printf("INTERNAL ERROR : %s %i : member \"m_IntegerTypeId\" is \"",p_FileName,p_LineNumber);
		displayIntegerTypeId(m_IntegerTypeId);
		printf("\"\n");
		error=1;
	}
	
	discrete_type::checkIntegrity(p_FileName,p_LineNumber);
	if(error!=0)
	{
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
}

t_IntegerTypeId integer_type::getIntegerTypeId(void)
{
	return m_IntegerTypeId;
}
	
integer_type::integer_type(void):discrete_type(Discrete_Type_Integer)
{
	#ifdef TRACE
	printfTraceUp("integer_type",__FILE__,__LINE__);
	#endif
	m_IntegerTypeId=Integer_Type_Undefined;
	#ifdef TRACE
	printfTraceDown("integer_type",__FILE__,__LINE__);
	#endif
	
}

integer_type::integer_type(t_IntegerTypeId p_IntegerTypeId):discrete_type(Discrete_Type_Integer)
{
	#ifdef TRACE
	printfTraceUp("integer_type",__FILE__,__LINE__);
	#endif
	m_IntegerTypeId=p_IntegerTypeId;
	#ifdef TRACE
	printfTraceDown("integer_type",__FILE__,__LINE__);
	#endif
}


integer_type::integer_type(t_IntegerTypeId p_IntegerTypeId,char *p_Name,main_unit *p_MainUnit):discrete_type(Discrete_Type_Integer,p_Name,p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("integer_type",__FILE__,__LINE__);
	#endif
	m_IntegerTypeId=p_IntegerTypeId;
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("integer_type",__FILE__,__LINE__);
	#endif
	
}
