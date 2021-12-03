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
 * Description: instantiation of scalar_type class
 *
 * $Log: scalar_type.cpp,v $
 * Revision 1.1  2005/03/13 16:50:26  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 *
 * Revision 1.1.1.1  2005/03/01 22:20:44  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "scalar_type.h"

void displayScalarTypeId(t_ScalarTypeId p_ScalarTypeId)
{
	switch(p_ScalarTypeId)
	{
		case Scalar_Type_Discrete:printf("Scalar_Type_Discrete");break;
		case Scalar_Type_Real:printf("Scalar_Type_Real");break;
		case Scalar_Type_Undefined:printf("Scalar_Type_Undefined");break;
		default:
		printf("ERROR : %s %i : scalar type id %i is not manage\n",__FILE__,__LINE__,p_ScalarTypeId);
		my_exit(-1);
		break;
	}
}

void scalar_type::checkIntegrity(const char *p_FileName, int p_LineNumber)
{	
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	int error=0;
	
	if(m_ScalarTypeId==Scalar_Type_Undefined)
	{
		printf("ERROR : %s %i : member \"m_ScalarTypeId\" is \"",p_FileName,p_LineNumber);
		displayScalarTypeId(m_ScalarTypeId);
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

t_ScalarTypeId scalar_type::getScalarTypeId(void)
{
	return m_ScalarTypeId;
}
	
scalar_type::scalar_type(void):elementary_type(Elementary_Type_Scalar)
{
	#ifdef TRACE
	printfTraceUp("scalar_type",__FILE__,__LINE__);
	#endif
	m_ScalarTypeId=Scalar_Type_Undefined;
	#ifdef TRACE
	printfTraceDown("scalar_type",__FILE__,__LINE__);
	#endif
	
}

scalar_type::scalar_type(t_ScalarTypeId p_ScalarTypeId):elementary_type(Elementary_Type_Scalar)
{
	#ifdef TRACE
	printfTraceUp("scalar_type",__FILE__,__LINE__);
	#endif
	m_ScalarTypeId=p_ScalarTypeId;
	#ifdef TRACE
	printfTraceDown("scalar_type",__FILE__,__LINE__);
	#endif
}


scalar_type::scalar_type(t_ScalarTypeId p_ScalarTypeId,const char *p_Name,main_unit *p_MainUnit):elementary_type(Elementary_Type_Scalar,p_Name,p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("scalar_type",__FILE__,__LINE__);
	#endif
	m_ScalarTypeId=p_ScalarTypeId;
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("scalar_type",__FILE__,__LINE__);
	#endif
	
}
