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
 * Description: instantiation of ordinary_fixed_type class
 *
 * $Log: ordinary_fixed_type.cpp,v $
 * Revision 1.1  2005/03/13 16:36:28  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 *
 * Revision 1.1.1.1  2005/03/01 22:20:41  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "ordinary_fixed_type.h"

void ordinary_fixed_type::checkIntegrity(char *p_FileName, int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	fixed_type::checkIntegrity(p_FileName,p_LineNumber);
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
}
	
ordinary_fixed_type::ordinary_fixed_type(void):fixed_type(Fixed_Type_Ordinary)
{
	#ifdef TRACE
	printfTraceUp("ordinary_fixed_type",__FILE__,__LINE__);
	#endif
	#ifdef TRACE
	printfTraceDown("ordinary_fixed_type",__FILE__,__LINE__);
	#endif
}

ordinary_fixed_type::ordinary_fixed_type(char *p_Name,tree *p_Delta,tree *p_LowerBound, tree *p_UpperBound, main_unit *p_MainUnit):fixed_type(Fixed_Type_Ordinary,p_Name,p_Delta,p_LowerBound,p_UpperBound,p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("ordinary_fixed_type",__FILE__,__LINE__);
	#endif
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("ordinary_fixed_type",__FILE__,__LINE__);
	#endif
}

ordinary_fixed_type *new_ordinary_fixed_type(char *p_Name,tree *p_Delta,tree *p_Range, main_unit *p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("new_ordinary_fixed_type",__FILE__,__LINE__);
	#endif
	ordinary_fixed_type *result=NULL;
	
	if(p_Delta!=NULL && p_Range!=NULL)
	{
		switch(p_Range->getNodeType())
		{
			case Node_Ada_Range_Constraint:
			result=new_ordinary_fixed_type(p_Name,p_Delta,p_Range->getSon(0),p_MainUnit);
			break;
			case Node_Ada_Range_Inter:
			result=new ordinary_fixed_type(p_Name,p_Delta,p_Range->getSon(0),p_Range->getSon(1),p_MainUnit);
			break;
			default:
			errorNotAllowed(__FILE__,__LINE__,p_Range,"range_spec");
			my_exit(-1);
			break;
		}
	}
	else
	{
		int error=0;
		if(p_Delta==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_Delta");
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
	printfTraceDown("new_ordinary_fixed_type",__FILE__,__LINE__);
	#endif
	return result;
	
}
