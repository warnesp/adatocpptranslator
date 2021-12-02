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
 * Description: instantiation of variant class
 *
 * $Log: variant.cpp,v $
 * Revision 1.1  2005/03/13 16:50:27  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 *
 * Revision 1.1.1.1  2005/03/01 22:20:53  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "variant.h"

list<tree*>* variant::getChoices(void)
{
	return m_Choices;
}

component_list* variant::getComponentList(void)
{
	return m_ComponentList;
}

void variant::checkIntegrity(char *p_FileName, int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	int error=0;
	
	if(m_Choices==NULL)
	{
		errorIsNull(__FILE__,__LINE__,"m_Choices");
		error=1;
	}
	
	if(m_ComponentList==NULL)
	{
		errorIsNull(__FILE__,__LINE__,"m_ComponentList");
		error=1;
	}
	
	if(error!=0)
	{
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
}

void variant::display(void)
{
}
	
variant::variant(void)
{
	#ifdef TRACE
	printfTraceUp("variant",__FILE__,__LINE__);
	#endif
	m_Choices=0;
	m_ComponentList=0;
	#ifdef TRACE
	printfTraceDown("variant",__FILE__,__LINE__);
	#endif
}

variant::variant(list<tree*>* p_Choices,component_list* p_ComponentList)
{
	#ifdef TRACE
	printfTraceUp("variant",__FILE__,__LINE__);
	#endif
	m_Choices=p_Choices;
	m_ComponentList=p_ComponentList;
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("variant",__FILE__,__LINE__);
	#endif
}

variant* new_variant(tree *p_Tree)
{
	#ifdef TRACE
	printfTraceUp("new_variant",__FILE__,__LINE__);
	#endif
	variant *result=NULL;
	if(p_Tree!=NULL)
	{
		if(p_Tree->getNodeType()==Node_Ada_Variant)
		{
			list<tree*> *p_Choices=NULL;
			p_Choices=getListChoice(p_Tree->getSon(0),p_Choices);
			component_list *p_ComponentList=NULL;
			p_ComponentList=new_component_list(p_Tree->getSon(2));
			result=new variant(p_Choices,p_ComponentList);
		}
		else
		{
			errorNotAllowed(__FILE__,__LINE__,p_Tree,"variant");
			my_exit(-1);
		}
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("new_variant",__FILE__,__LINE__);
	#endif
	return result;
}
