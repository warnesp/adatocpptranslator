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
 * Description: instantiation of discrim_spec class
 *
 * $Log: discrim_spec.cpp,v $
 * Revision 1.2  2005/03/27 00:39:37  quicky2000
 * Update to replace the parameter representing the type by a tree isntead of a
 * string to allow the use of complex node like selected comp
 *
 * Revision 1.1  2005/03/13 14:36:02  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 *
 * Revision 1.1.1.1  2005/03/01 22:20:36  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "discrim_spec.h"

char discrim_spec::getBoolAccess(void)
{
	 return m_BoolAccess;
}


void discrim_spec::checkIntegrity(char *p_FileName,int p_LineNumber)
{
	int error=0;
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	
	named::checkIntegrity(p_FileName,p_LineNumber);
	typed::checkIntegrity(p_FileName,p_LineNumber);
	initialised::checkIntegrity(p_FileName,p_LineNumber);
	
	if(error!=0)
	{
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
	
}

discrim_spec::discrim_spec(void):named(),typed(),initialised()
{
	#ifdef TRACE
	printfTraceUp("discrim_spec",__FILE__,__LINE__);
	#endif
	m_BoolAccess=0;
	#ifdef TRACE
	printfTraceDown("discrim_spec",__FILE__,__LINE__);
	#endif
	
}
	
discrim_spec::discrim_spec(char *p_Name,tree *p_TypeTree,char p_Access):named(p_Name),typed(p_TypeTree),initialised()
{
	#ifdef TRACE
	printfTraceUp("discrim_spec",__FILE__,__LINE__);
	#endif
	m_BoolAccess=p_Access;
	
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("discrim_spec",__FILE__,__LINE__);
	#endif
	
	
}

discrim_spec::discrim_spec(char *p_Name,tree *p_TypeTree,char p_Access,tree *p_InitTree):named(p_Name),typed(p_TypeTree),initialised(p_InitTree)
{
	#ifdef TRACE
	printfTraceUp("discrim_spec",__FILE__,__LINE__);
	#endif
	m_BoolAccess=p_Access;
	
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("discrim_spec",__FILE__,__LINE__);
	#endif
	
	
}

discrim_spec* new_discrim_spec(char *p_Name,tree *p_TypeTree,tree *p_AccessTree,tree *p_InitTree)
{
	#ifdef TRACE
	printfTraceUp("new_discrim_spec",__FILE__,__LINE__);
	#endif
	discrim_spec *result=NULL;
	
	if(p_AccessTree!=NULL && p_InitTree!=NULL)
	{
		char p_Access=0;
		switch(p_AccessTree->getNodeType())
		{
			case Node_Ada_C_Empty:
			case Node_Ada_Access: p_Access=1;break;
			default : 
			errorNotAllowed(__FILE__,__LINE__,p_AccessTree,"access_opt");
			my_exit(-1);
			break;
			
		}
		
		switch(p_InitTree->getNodeType())
		{
			case Node_Ada_Initialisation_Option: result=new discrim_spec(p_Name,p_TypeTree,p_Access,p_InitTree->getSon(0));break;
			case Node_Ada_C_Empty: result=new discrim_spec(p_Name,p_TypeTree,p_Access);break;
			default : 
			errorNotAllowed(__FILE__,__LINE__,p_InitTree,"init_opt");
			my_exit(-1);
			break;
			
		}
		
		
	}
	else
	{
		int error=0;;
		if(p_AccessTree==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_AccessTree");
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
	printfTraceDown("new_discrim_spec",__FILE__,__LINE__);
	#endif
	
	return result;
}
	

