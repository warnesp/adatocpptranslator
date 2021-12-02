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
 * Description: instantiation of parameter class
 *
 * $Log: parameter.cpp,v $
 * Revision 1.3  2005/03/27 01:04:11  quicky2000
 * Update due to the replacement of type representation by a tree instead of string
 *
 * Revision 1.2  2005/03/18 19:16:08  quicky2000
 * Update due to protected members which become private
 *
 * Revision 1.1  2005/03/13 16:47:56  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 * _ to modify the constructor
 *
 * Revision 1.1.1.1  2005/03/01 22:20:42  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "parameter.h"

void displayParameterMode(t_ParameterMode p_ParameterMode)
{
	#ifdef TRACE
	printfTraceUp("displayParameterMode",__FILE__,__LINE__);
	#endif
	switch(p_ParameterMode)
	{
		case Parameter_In:printf("Parameter_In");break;
		case Parameter_In_Out:printf("Parameter_In_Out");break;
		case Parameter_Out:printf("Parameter_Out");break;
		case Parameter_Undefined:printf("Parameter_Undefined");	break;
		default:printf("ERROR : %s %i : parameter mode %i is not manage\n",__FILE__,__LINE__,p_ParameterMode);
				my_exit(-1);
		break;
	}
	#ifdef TRACE
	printfTraceDown("displayParameterMode",__FILE__,__LINE__);
	#endif
	
}

t_ParameterMode parameter::getParameterMode(void)
{
	this->checkIntegrity(__FILE__,__LINE__);
	return m_ParameterMode;
}

void parameter::display(void)
{
	#ifdef TRACE
	printfTraceUp("display",__FILE__,__LINE__);
	#endif
	this->checkIntegrity(__FILE__,__LINE__);
	printf("parameter \"%s\" of type \"%s\" with mode ",getName(),getString(m_TypeTree));
	displayParameterMode(m_ParameterMode);
	printf("\n");
	#ifdef TRACE
	printfTraceDown("display",__FILE__,__LINE__);
	#endif
	
}

void parameter::checkIntegrity(char *p_FileName,int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	
	int error=0;

	if(m_ParameterMode==Parameter_Undefined)
	{
		printf("ERROR : %s %i : \"m_ParameterMode\" member value is \"Parameter_Undefined\"\n",p_FileName,p_LineNumber);
		error=1;
	}

	variable_object::checkIntegrity(p_FileName,p_LineNumber);
	
	if(error!=0)
	{
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
	
	
}
	
parameter::parameter(void):variable_object()
{
	#ifdef TRACE
	printfTraceUp("parameter",__FILE__,__LINE__);
	#endif
	
	m_ParameterMode=Parameter_Undefined;
	
	#ifdef TRACE
	printfTraceDown("parameter",__FILE__,__LINE__);
	#endif
	
}

parameter::parameter(char *p_Name,subtyped *p_Subtyped,t_ParameterMode p_ParameterMode,main_unit *p_MainUnit):variable_object(p_Name,0,0,p_Subtyped,p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("parameter",__FILE__,__LINE__);
	#endif
	
	m_ParameterMode=p_ParameterMode;
	this->checkIntegrity(__FILE__,__LINE__);
	
	#ifdef TRACE
	printfTraceDown("parameter",__FILE__,__LINE__);
	#endif
	
}

parameter::parameter(char *p_Name,subtyped *p_Subtyped,t_ParameterMode p_ParameterMode,tree *p_InitTree,main_unit *p_MainUnit):variable_object(p_Name,0,0,p_Subtyped,p_InitTree,p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("parameter",__FILE__,__LINE__);
	#endif
	
	m_ParameterMode=p_ParameterMode;
	this->checkIntegrity(__FILE__,__LINE__);
	
	#ifdef TRACE
	printfTraceDown("parameter",__FILE__,__LINE__);
	#endif
	
}

parameter* new_parameter(char *p_Name,tree *p_TypeTree,tree *p_ParameterModeTree,tree *p_InitTree, main_unit *p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("new_parameter",__FILE__,__LINE__);
	#endif
	parameter *result=NULL;
	
	if(p_ParameterModeTree!=NULL && p_InitTree!=NULL && p_MainUnit!=NULL)
	{
		t_ParameterMode p_Mode=Parameter_Undefined;
		switch(p_ParameterModeTree->getNodeType())
		{
			case Node_Ada_C_Empty:
			case Node_Ada_Mode_In: p_Mode=Parameter_In;break;
			case Node_Ada_Mode_In_Out: p_Mode=Parameter_In_Out;break;
			case Node_Ada_Mode_Out: p_Mode=Parameter_Out;break;
			default :
			errorNotAllowed(__FILE__,__LINE__,p_ParameterModeTree,"mode");
			my_exit(-1);
			break;
			
		}
		
		switch(p_InitTree->getNodeType())
		{
			case Node_Ada_Initialisation_Option: result=new parameter(p_Name,new subtyped(p_TypeTree,0),p_Mode,p_InitTree->getSon(0),p_MainUnit);break;
			case Node_Ada_C_Empty: result=new parameter(p_Name,new subtyped(p_TypeTree,0),p_Mode,p_MainUnit);break;
			default : 
			errorNotAllowed(__FILE__,__LINE__,p_InitTree,"init_opt");
			break;
			
		}
		
		
	}
	else
	{
		if(p_ParameterModeTree==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_ParameterModeTree");
		}
		if(p_InitTree==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_InitTree");
		}
		if(p_MainUnit==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_InitTree");
		}
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("new_parameter",__FILE__,__LINE__);
	#endif
	
	return result;
}
	
