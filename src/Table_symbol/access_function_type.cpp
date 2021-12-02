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
 * Description: instantiation of access_function_type class
 *
 * $Log: access_function_type.cpp,v $
 * Revision 1.5  2005/03/26 23:50:48  quicky2000
 * Update to replace the parameter which represent return type by a tree instead of a string to manage type represents by complex nodes like selected comp...
 *
 * Revision 1.4  2005/03/19 14:01:42  quicky2000
 * Update to correct the first value passed to access_subprog_type constructor
 *
 * Revision 1.3  2005/03/17 20:30:24  quicky2000
 * Update to add cvs log flag
 *
 * Revision 1.2  2005/03/17 19:07:18  quicky2000
 * Update to modify the constructor according to the new class architecture
 *
 * Revision 1.1  2005/03/10 19:18:16  quicky2000
 * Update for code maintenance
 *
 *
 *****************************************************************************/
#include "access_function_type.h"

void access_function_type::checkIntegrity(char *p_FileName, int p_LineNumber)
{	
	#ifdef TRACE
		printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	int error=0;
	
	access_subprog_type::checkIntegrity(p_FileName,p_LineNumber);
	
	if(error!=0)
	{
		my_exit(-1);
	}
	#ifdef TRACE
		printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
}

access_function_type::access_function_type(void):access_subprog_type(Access_Subprog_Type_Function)
{
	#ifdef TRACE
		printfTraceUp("access_function_type",__FILE__,__LINE__);
	#endif
	#ifdef TRACE
		printfTraceDown("access_function_type",__FILE__,__LINE__);
	#endif
	
}

access_function_type::access_function_type(char *p_Name,tree *p_ProtectedTree,tree *p_ParametersTree,tree *p_ReturnTypeTree, main_unit *p_MainUnit):access_subprog_type(Access_Subprog_Type_Function,p_ProtectedTree,p_Name,p_ParametersTree,p_ReturnTypeTree,p_MainUnit)
{
	#ifdef TRACE
		printfTraceUp("access_function_type",__FILE__,__LINE__);
	#endif
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
		printfTraceDown("access_function_type",__FILE__,__LINE__);
	#endif
	
}

/*access_function_type* new_access_function_type(char *p_Name,tree *p_ProtectedTree,tree *p_ParametersTree,char *p_ReturnTypeName,main_unit *p_MainUnit)
{
	#ifdef TRACE
		printfTraceUp("new_access_function_type",__FILE__,__LINE__);
	#endif
	access_function_type *result=NULL;
	if(p_ParametersTree!=NULL && p_ReturnTypeName!=NULL && p_ProtectedTree!=NULL)
	{
		list<parameter*> *p_Parameters=NULL;
		char p_Protected=0;
		if(p_ProtectedTree->getNodeType()==Node_Ada_Protected_Opt)
		{
			p_Protected=1;
		}
		
		if(p_ParametersTree->getNodeType()==Node_Ada_C_Formal_Part)
		{
			p_Parameters=getListParameter(p_ParametersTree,p_Parameters,p_MainUnit);
		}
		result=new access_function_type(p_Name,p_Protected,p_Parameters,p_ReturnTypeName,p_MainUnit);
	}
	else
	{
		int error=0;
		if(p_ProtectedTree==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_ProtectedTree");
			error=1;
		}
		if(p_ParametersTree==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_ParametersTree");
			error=1;
		}
		if(p_ReturnTypeName==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_ReturnTypeName");
			error=1;
		}
		if(error!=0)
		{
			my_exit(-1);
		}
	}
	#ifdef TRACE
		printfTraceDown("new_access_function_type",__FILE__,__LINE__);
	#endif
}*/
