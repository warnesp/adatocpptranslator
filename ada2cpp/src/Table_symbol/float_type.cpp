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
 * Description: instantiation of float_type class
 *
 * $Log: float_type.cpp,v $
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
#include "float_type.h"

tree* float_type::getDigit(void)
{
	this->checkIntegrity(__FILE__,__LINE__);
	return m_Digit;
}

void float_type::checkIntegrity(const char *p_FileName, int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	int error=0;
	
	if(m_Digit==NULL)
	{
		errorIsNull(p_FileName,p_LineNumber,"m_Digit");
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

float_type::float_type(void):real_type(Real_Type_Floating)
{
	#ifdef TRACE
	printfTraceUp("float_type",__FILE__,__LINE__);
	#endif
	m_Digit=NULL;
	#ifdef TRACE
	printfTraceDown("float_type",__FILE__,__LINE__);
	#endif
}

float_type::float_type(const char *p_Name,tree *p_Digit,main_unit *p_MainUnit):real_type(Real_Type_Floating,p_Name,p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("float_type",__FILE__,__LINE__);
	#endif
	m_Digit=p_Digit;
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("float_type",__FILE__,__LINE__);
	#endif
}

float_type::float_type(const char *p_Name,tree *p_Digit,tree *p_LowerBound, tree *p_UpperBound, main_unit *p_MainUnit):real_type(Real_Type_Floating,p_Name,p_LowerBound,p_UpperBound,p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("float_type",__FILE__,__LINE__);
	#endif
	m_Digit=p_Digit;
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("float_type",__FILE__,__LINE__);
	#endif
}

float_type* new_float_type(const char *p_Name,tree *p_Digit, tree *p_Range,main_unit *p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("new_float_type",__FILE__,__LINE__);
	#endif
	float_type *result=NULL;
	
	if(p_Digit!=NULL && p_Range!=NULL)
	{
		switch(p_Range->getNodeType())
		{
			case Node_Ada_C_Empty:
			result=new float_type(p_Name,p_Digit,p_MainUnit);
			break;
			case Node_Ada_Range_Constraint:
			result=new_float_type(p_Name,p_Digit,p_Range->getSon(0),p_MainUnit);
			break;
			case Node_Ada_Range_Inter:
			result=new float_type(p_Name,p_Digit,p_Range->getSon(0),p_Range->getSon(1),p_MainUnit);
			break;
			default:
			errorNotAllowed(__FILE__,__LINE__,p_Range,"range_spec_opt, range_constraint");
			my_exit(-1);
			break;
		}
	}
	else
	{
		int error=0;
		if(p_Digit==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_Digit");
			error=1;
		}
		if(p_Range==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_Range");
			error=1;
		}
		
		if(error!=0)
		{
			my_exit(-1);
		}
	}
	#ifdef TRACE
	printfTraceDown("new_float_type",__FILE__,__LINE__);
	#endif
	return result;
	
}
