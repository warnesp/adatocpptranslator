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
 * Description: instantiation of fixed_type class
 *
 * $Log: fixed_type.cpp,v $
 * Revision 1.2  2005/03/18 18:34:02  quicky2000
 * Update to modify constructors according to the new class hierarchy
 *
 * Revision 1.1  2005/03/13 16:36:27  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 *
 * Revision 1.1.1.1  2005/03/01 22:20:37  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "fixed_type.h"

void displayFixedTypeId(t_FixedTypeId p_FixedTypeId)
{
	switch(p_FixedTypeId)
	{
		case Fixed_Type_Ordinary:printf("Fixed_Type_Ordinary");break;
		case Fixed_Type_Decimal:printf("Fixed_Type_Decimal");break;
		case Fixed_Type_Undefined:printf("Fixed_Type_Undefined");break;
		default:
		printf("INTERNAL ERROR : %s %i : fixed type id %i is not manage\n",__FILE__,__LINE__,p_FixedTypeId);
		my_exit(-1);
		break;
	}
}

tree* fixed_type::getDelta(void)
{
	this->checkIntegrity(__FILE__,__LINE__);
	return m_Delta;
}

void fixed_type::checkIntegrity(char *p_FileName, int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	int error=0;
	
	if(m_FixedTypeId==Fixed_Type_Undefined)
	{
		printf("INTERNAL ERROR : %s %i : member \"m_FixedTypeId\" value is \"",p_FileName,p_LineNumber);
		displayFixedTypeId(m_FixedTypeId);
		printf("\"\n");
		error=1;
	}
	
	if(m_Delta==NULL)
	{
		errorIsNull(p_FileName,p_LineNumber,"m_Delta");
		error=1;
	}
	
	real_type::checkIntegrity(p_FileName,p_LineNumber);
	
	if(error!=0)
	{
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
}

fixed_type::fixed_type(void):real_type(Real_Type_Fixed)
{
	#ifdef TRACE
	printfTraceUp("fixed_type",__FILE__,__LINE__);
	#endif
	m_FixedTypeId=Fixed_Type_Undefined;
	m_Delta=NULL;
	#ifdef TRACE
	printfTraceDown("fixed_type",__FILE__,__LINE__);
	#endif
}

fixed_type::fixed_type(t_FixedTypeId p_FixedTypeId):real_type(Real_Type_Fixed)
{
	#ifdef TRACE
	printfTraceUp("fixed_type",__FILE__,__LINE__);
	#endif
	m_FixedTypeId=p_FixedTypeId;
	m_Delta=NULL;
	#ifdef TRACE
	printfTraceDown("fixed_type",__FILE__,__LINE__);
	#endif
}

fixed_type::fixed_type(t_FixedTypeId p_FixedTypeId,char *p_Name,tree *p_Delta,main_unit *p_MainUnit):real_type(Real_Type_Fixed,p_Name,p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("fixed_type",__FILE__,__LINE__);
	#endif
	m_FixedTypeId=p_FixedTypeId;
	m_Delta=p_Delta;
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("fixed_type",__FILE__,__LINE__);
	#endif
}

fixed_type::fixed_type(t_FixedTypeId p_FixedTypeId,char *p_Name,tree *p_Delta,tree *p_LowerBound, tree *p_UpperBound, main_unit *p_MainUnit):real_type(Real_Type_Fixed,p_Name,p_LowerBound,p_UpperBound,p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("fixed_type",__FILE__,__LINE__);
	#endif
	m_FixedTypeId=p_FixedTypeId;
	m_Delta=p_Delta;
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("fixed_type",__FILE__,__LINE__);
	#endif
}

