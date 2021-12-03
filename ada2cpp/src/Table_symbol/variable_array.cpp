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
 * Description: instantiation of variable_array class
 *
 * $Log: variable_array.cpp,v $
 * Revision 1.1  2005/03/13 16:50:27  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 *
 * Revision 1.1.1.1  2005/03/01 22:20:52  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "variable_array.h"

void variable_array::checkIntegrity(const char *p_FileName,int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	int error=0;
	
	variable::checkIntegrity(p_FileName,p_LineNumber);
	array::checkIntegrity(p_FileName,p_LineNumber);
	
	if(error!=0)
	{
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
}

variable_array::variable_array(void):variable(Variable_Array),array()
{
	#ifdef TRACE
	printfTraceUp("variable_array",__FILE__,__LINE__);
	#endif
	#ifdef TRACE
	printfTraceDown("variable_array",__FILE__,__LINE__);
	#endif
}

variable_array::variable_array(const char *p_Name,char p_Constant,char p_Aliased,array *p_Array,main_unit *p_MainUnit):variable(Variable_Array,p_Name,p_Constant,p_Aliased,p_MainUnit),array(p_Array)
{
	#ifdef TRACE
	printfTraceUp("variable_array",__FILE__,__LINE__);
	#endif
	#ifdef TRACE
	printfTraceDown("variable_array",__FILE__,__LINE__);
	#endif
}

variable_array::variable_array(const char *p_Name,char p_Constant,char p_Aliased,array *p_Array,tree *p_InitTree,main_unit *p_MainUnit):variable(Variable_Array,p_Name,p_Constant,p_Aliased,p_InitTree,p_MainUnit),array(p_Array)
{
	#ifdef TRACE
	printfTraceUp("variable_array",__FILE__,__LINE__);
	#endif
	#ifdef TRACE
	printfTraceDown("variable_array",__FILE__,__LINE__);
	#endif
}

variable_array *new_variable_array(const char *p_Name,tree *p_ObjectQualifierTree, tree *p_ObjectSubtypeDefTree,tree *p_InitTree,main_unit *p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("new_variable_array",__FILE__,__LINE__);
	#endif
	variable_array *result=NULL;
	char p_Aliased=0;
	char p_Constant=0;
	
	if(p_ObjectQualifierTree!=NULL && p_ObjectSubtypeDefTree!=NULL && p_InitTree!=NULL)
	{
		switch(p_ObjectQualifierTree->getNodeType())
		{
			case Node_Ada_C_Empty:break;
			case Node_Ada_Aliased:p_Aliased=1;break;
			case Node_Ada_Constant:p_Constant=1;break;
			case Node_Ada_Aliased_Constant:p_Aliased=1;p_Constant=1;break;
			default:errorNotAllowed(__FILE__,__LINE__,p_ObjectQualifierTree,"object_qualifier_opt");
			my_exit(-1);
		}
		
		array *p_Array=new_array(p_ObjectSubtypeDefTree);
		
		switch(p_InitTree->getNodeType())
		{
			case Node_Ada_C_Empty:result=new variable_array(p_Name,p_Constant,p_Aliased,p_Array,p_MainUnit);break;
			case Node_Ada_Initialisation_Option:result=new variable_array(p_Name,p_Constant,p_Aliased,p_Array,p_InitTree->getSon(0),p_MainUnit);break;
			default:errorNotAllowed(__FILE__,__LINE__,p_InitTree,"init_opt");
			my_exit(-1);
		}
		
	}
	else
	{
		int error=0;
		if(p_ObjectQualifierTree==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_ObjectQualifierTree");
			error=1;
		}
		
		if(p_ObjectSubtypeDefTree==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_ObjectSubtypeDefTree");
			error=1;
		}
		
		if(p_InitTree==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_InitTree");
			error=1;
		}
		
		if(error!=0)
		{
			my_exit(-1);
		}
		
	}
	#ifdef TRACE
	printfTraceDown("new_variable_array",__FILE__,__LINE__);
	#endif
	return result;
}
