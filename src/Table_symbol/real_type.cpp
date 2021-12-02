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
 * Description: instantiation of real_type class
 *
 * $Log: real_type.cpp,v $
 * Revision 1.2  2005/03/18 19:25:31  quicky2000
 * Update due to the add of a range member in class real_type
 *
 * Revision 1.1  2005/03/13 16:44:25  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 *
 * Revision 1.1.1.1  2005/03/01 22:20:43  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "real_type.h"
#include "base_range.h"

void displayRealTypeId(t_RealTypeId p_RealTypeId)
{
	switch(p_RealTypeId)
	{
		case Real_Type_Floating:printf("Real_Type_Floating");break;
		case Real_Type_Fixed:printf("Real_Type_Fixed");break;
		case Real_Type_Undefined:printf("Real_Type_Undefined");break;
		default:
		printf("ERROR : %s %i : real type id %i is not manage\n",__FILE__,__LINE__,p_RealTypeId);
		my_exit(-1);
		break;
	}
}

void real_type::checkIntegrity(char *p_FileName, int p_LineNumber)
{	
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	int l_Error=0;
	
	if(m_RealTypeId==Real_Type_Undefined)
	{
		printf("ERROR : %s %i : member \"m_RealTypeId\" is \"",p_FileName,p_LineNumber);
		displayRealTypeId(m_RealTypeId);
		printf("\"\n");
		l_Error=1;
	}
	if(m_Range==NULL && m_BoolRange==1)
	{
		errorGeneric(__FILE__,__LINE__,"m_Range is NULL whereas M_BoolRange is true");
		l_Error=1;
	}
	
	if(m_Range!=NULL && m_BoolRange==0)
	{
		errorGeneric(__FILE__,__LINE__,"m_Range is not NULL whereas M_BoolRange is flase");
		l_Error=1;
	}
	
	if(m_Range!=NULL && m_BoolRange==1)
	{
		m_Range->checkIntegrity(p_FileName,p_LineNumber);
	}
	
	scalar_type::checkIntegrity(p_FileName,p_LineNumber);
	if(l_Error!=0)
	{
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
}

t_RealTypeId real_type::getRealTypeId(void)
{
	return m_RealTypeId;
}

char real_type::getBoolRange(void)
{
	this->checkIntegrity(__FILE__,__LINE__);
	return m_BoolRange;
}


	
real_type::real_type(void):scalar_type(Scalar_Type_Real)
{
	#ifdef TRACE
	printfTraceUp("real_type",__FILE__,__LINE__);
	#endif
	m_RealTypeId=Real_Type_Undefined;
	m_Range=new base_range();
	#ifdef TRACE
	printfTraceDown("real_type",__FILE__,__LINE__);
	#endif
	
}

real_type::real_type(t_RealTypeId p_RealTypeId):scalar_type(Scalar_Type_Real)
{
	#ifdef TRACE
	printfTraceUp("real_type",__FILE__,__LINE__);
	#endif
	m_RealTypeId=p_RealTypeId;
	m_BoolRange=0;
	m_Range=NULL;
	#ifdef TRACE
	printfTraceDown("real_type",__FILE__,__LINE__);
	#endif
}

real_type::real_type(t_RealTypeId p_RealTypeId,char *p_Name,main_unit *p_MainUnit):scalar_type(Scalar_Type_Real,p_Name,p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("real_type",__FILE__,__LINE__);
	#endif
	m_RealTypeId=p_RealTypeId;
	m_BoolRange=0;
	m_Range=NULL;
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("real_type",__FILE__,__LINE__);
	#endif
	
}

real_type::real_type(t_RealTypeId p_RealTypeId,char *p_Name,tree *p_LowerBound,tree *p_UpperBound,main_unit *p_MainUnit):scalar_type(Scalar_Type_Real,p_Name,p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("real_type",__FILE__,__LINE__);
	#endif
	m_RealTypeId=p_RealTypeId;
	m_BoolRange=1;
	m_Range=new base_range(p_LowerBound, p_UpperBound);
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("real_type",__FILE__,__LINE__);
	#endif
	
}
