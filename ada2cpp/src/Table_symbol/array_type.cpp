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
 * Description: instantiation of array_type class
 *
 * $Log: array_type.cpp,v $
 * Revision 1.2  2005/03/17 22:25:17  quicky2000
 * Update to add cvs log flag
 *
 *
 *****************************************************************************/
#include "array_type.h"

void displayArrayTypeId(t_ArrayTypeId p_ArrayTypeId)
{
	switch(p_ArrayTypeId)
	{
		case Array_Type_Constrained:printf("Array_Type_Constrained");break;
		case Array_Type_Unconstrained:printf("Array_Type_Unconstrained");break;
		case Array_Type_Undefined:printf("Array_Type_Undefined");break;
		default:
		printf("INTERNAL ERROR : %s %i : array type id %i is not manage\n",__FILE__,__LINE__,p_ArrayTypeId);
		break;
	}
}

char array_type::getAliased(void)
{
	return m_Aliased;
}
	
	
void array_type::checkIntegrity(const char *p_FileName, int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	
	array::checkIntegrity(p_FileName,p_LineNumber);
	composite_type::checkIntegrity(p_FileName,p_LineNumber);
	
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
}

array_type::array_type(void):composite_type(Composite_Type_Array),array(Array_Undefined)
{
	#ifdef TRACE
	printfTraceUp("array_type",__FILE__,__LINE__);
	#endif
	m_Aliased=0;
	#ifdef TRACE
	printfTraceDown("array_type",__FILE__,__LINE__);
	#endif
}

array_type::array_type(const char *p_Name,array *p_Array,char p_Aliased,main_unit *p_MainUnit):composite_type(Composite_Type_Array,p_Name,p_MainUnit),array(p_Array)
{
	#ifdef TRACE
	printfTraceUp("array_type",__FILE__,__LINE__);
	#endif
	m_Aliased=p_Aliased;
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("array_type",__FILE__,__LINE__);
	#endif
}

array_type* new_array_type(const char *p_Name,tree *p_ArrayTree,main_unit *p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("new_array_type",__FILE__,__LINE__);
	#endif
	array_type *result=NULL;
	if(p_ArrayTree!=NULL)
	{
		int p_Aliased=0;
		array *p_Array=new_array(p_ArrayTree);
		
		if(p_ArrayTree->getSon(1)->getNodeType()==Node_Ada_Component_Subtype_Definition)
		{
			switch(p_ArrayTree->getSon(1)->getSon(0)->getNodeType())
			{
				case Node_Ada_C_Empty:break;
				case Node_Ada_Aliased:p_Aliased=1;break;
				default:
				errorNotAllowed(__FILE__,__LINE__,p_ArrayTree->getSon(1)->getSon(0),"aliased_opt");
				my_exit(-1);
			}
		}
		else
		{
			errorNotAllowed(__FILE__,__LINE__,p_ArrayTree->getSon(1),"component_subtype_def");
			my_exit(-1);
		}
		result=new array_type(p_Name,p_Array,p_Aliased,p_MainUnit);
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_ArrayTree");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("new_array_type",__FILE__,__LINE__);
	#endif
	return result;
	
}
