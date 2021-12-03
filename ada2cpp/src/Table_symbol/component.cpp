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
 * Description: instantiation of component class
 *
 * $Log: component.cpp,v $
 * Revision 1.1  2005/03/13 14:36:02  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 *
 * Revision 1.1.1.1  2005/03/01 22:20:34  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "component.h"

void component::checkIntegrity(const char *p_FileName, int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	int error=0;
	
	object::checkIntegrity(p_FileName,p_LineNumber);
	named::checkIntegrity(p_FileName,p_LineNumber);
	subtyped::checkIntegrity(p_FileName,p_LineNumber);
	
	if(error!=0)
	{
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
}

component::component(void):named(),object(),subtyped()
{
	#ifdef TRACE
	printfTraceUp("component",__FILE__,__LINE__);
	#endif
	#ifdef TRACE
	printfTraceDown("component",__FILE__,__LINE__);
	#endif
	
}

component::component(const char *p_Name,char p_Aliased,subtyped *p_Subtyped):named(p_Name),object(p_Aliased),subtyped(p_Subtyped)
{
	#ifdef TRACE
	printfTraceUp("component",__FILE__,__LINE__);
	#endif
	#ifdef TRACE
	printfTraceDown("component",__FILE__,__LINE__);
	#endif
}

component::component(const char *p_Name,char p_Aliased,subtyped *p_Subtyped,tree *p_InitTree):named(p_Name),object(p_Aliased,p_InitTree),subtyped(p_Subtyped)
{
	#ifdef TRACE
	printfTraceUp("component",__FILE__,__LINE__);
	#endif
	#ifdef TRACE
	printfTraceDown("component",__FILE__,__LINE__);
	#endif
}

component* new_component(const char *p_Name,tree *p_ComponentSubtypeDefTree, tree *p_InitTree)
{
	#ifdef TRACE
	printfTraceUp("new_component",__FILE__,__LINE__);
	#endif
	component *result=NULL;
	char p_Aliased=0;
	
	if(p_ComponentSubtypeDefTree!=NULL && p_InitTree!=NULL)
	{
		if(p_ComponentSubtypeDefTree->getNodeType()==Node_Ada_Component_Subtype_Definition)
		{
			switch(p_ComponentSubtypeDefTree->getSon(0)->getNodeType())
			{
				case Node_Ada_C_Empty:break;
				case Node_Ada_Aliased:p_Aliased=1;break;
				default:
				errorNotAllowed(__FILE__,__LINE__,p_ComponentSubtypeDefTree->getSon(0),"aliased_opt");
				my_exit(-1);
			}
		}
		else
		{
			errorNotAllowed(__FILE__,__LINE__,p_ComponentSubtypeDefTree,"component_subtype_def");
			my_exit(-1);
		}
		
		subtyped *p_Subtyped=new_subtyped(p_ComponentSubtypeDefTree->getSon(1));
		switch(p_InitTree->getNodeType())
		{
			case Node_Ada_C_Empty:result=new component(p_Name,p_Aliased,p_Subtyped);break;
			case Node_Ada_Initialisation_Option:result=new component(p_Name,p_Aliased,p_Subtyped,p_InitTree->getSon(0));break;
			default:errorNotAllowed(__FILE__,__LINE__,p_InitTree,"init_opt");
			my_exit(-1);
		}
	}
	else
	{
		int error=0;
		if(p_ComponentSubtypeDefTree==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_ComponentSubtypeDefTree");
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
	printfTraceDown("new_component",__FILE__,__LINE__);
	#endif
	
	return result;
}
