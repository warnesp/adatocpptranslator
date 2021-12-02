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
 * Description: instantiation of access_procedure_type class
 *
 * $Log: access_procedure_type.cpp,v $
 * Revision 1.2  2005/03/17 20:32:57  quicky2000
 * Update for code maintenance
 *
 *
 *****************************************************************************/
#include "access_procedure_type.h"

void access_procedure_type::checkIntegrity(char *p_FileName, int p_LineNumber)
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

access_procedure_type::access_procedure_type(void):access_subprog_type(Access_Subprog_Type_Procedure)
{
	#ifdef TRACE
		printfTraceUp("access_procedure_type",__FILE__,__LINE__);
	#endif
	#ifdef TRACE
		printfTraceDown("access_procedure_type",__FILE__,__LINE__);
	#endif
	
}

access_procedure_type::access_procedure_type(char *p_Name,tree *p_ProtectedTree,tree *p_ParametersTree, main_unit *p_MainUnit):access_subprog_type(Access_Subprog_Type_Procedure,p_ProtectedTree,p_Name,p_ParametersTree,p_MainUnit)
{
	#ifdef TRACE
		printfTraceUp("access_procedure_type",__FILE__,__LINE__);
	#endif
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
		printfTraceDown("access_procedure_type",__FILE__,__LINE__);
	#endif
	
}

/*access_procedure_type* new_access_procedure_type(char *p_Name,tree *p_ProtectedTree, tree *p_ParametersTree,main_unit *p_MainUnit)
{
	#ifdef TRACE
		printfTraceUp("new_access_procedure_type",__FILE__,__LINE__);
	#endif
	access_procedure_type *result=NULL;
	if(p_ParametersTree!=NULL && p_ProtectedTree!=NULL)
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
		result=new access_procedure_type(p_Name,p_Protected,p_Parameters,p_MainUnit);
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
		if(error!=0)
		{
			my_exit(-1);
		}
	}
	#ifdef TRACE
		printfTraceDown("new_access_procedure_type",__FILE__,__LINE__);
	#endif
}*/
