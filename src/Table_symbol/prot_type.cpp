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
 * Description: instantiation of prot_type class
 *
 * $Log: prot_type.cpp,v $
 * Revision 1.1  2005/03/13 16:44:25  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 *
 * Revision 1.1.1.1  2005/03/01 22:20:42  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "prot_type.h"

void prot_type::checkIntegrity(const char *p_FileName,int p_LineNumber)
{
	
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	prot::checkIntegrity(p_FileName,p_LineNumber);
	discrimined::checkIntegrity(p_FileName,p_LineNumber);
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
	
}	

prot_type::prot_type(void):prot(),discrimined()
{
	#ifdef TRACE
	printfTraceUp("prot_type",__FILE__,__LINE__);
	#endif
	#ifdef TRACE
	printfTraceDown("prot_type",__FILE__,__LINE__);
	#endif
}

prot_type::prot_type(const char *p_Name,char p_BoolGeneric,list<discrim_spec*> *p_DiscrimSpecs,main_unit *p_CurrentMainUnit):prot(Prot_Type,p_Name,p_CurrentMainUnit),discrimined(p_BoolGeneric,p_DiscrimSpecs)
{
	#ifdef TRACE
	printfTraceUp("prot_type",__FILE__,__LINE__);
	#endif
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("prot_type",__FILE__,__LINE__);
	#endif
	
}
	
prot_type *new_prot_type(const char *p_Name,tree *p_DiscrimSpecsTree,main_unit *p_CurrentMainUnit)
{
	prot_type *result=NULL;
	#ifdef TRACE
	printfTraceUp("new_prot_type",__FILE__,__LINE__);
	#endif
	
	if(p_DiscrimSpecsTree!=NULL)
	{
		switch(p_DiscrimSpecsTree->getNodeType())
		{
			case Node_Ada_C_Empty:
			result=new prot_type(p_Name,0,NULL,p_CurrentMainUnit);
			break;
			case Node_Ada_Discrim_Part_Opt:
			result=new prot_type(p_Name,1,NULL,p_CurrentMainUnit);
			break;
			case Node_Ada_Discrim_Part:
			{
				list<discrim_spec*> *p_DiscrimSpecs=NULL;
				p_DiscrimSpecs=getListDiscrimSpec(p_DiscrimSpecsTree->getSon(0),p_DiscrimSpecs);
				result=new prot_type(p_Name,0,p_DiscrimSpecs,p_CurrentMainUnit);
			}
			break;
			
			default :
			errorNotAllowed(__FILE__,__LINE__,p_DiscrimSpecsTree,"discrim_part_opt");
			my_exit(-1);
			break;
		}
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_DiscrimSpecsTree");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("new_prot_type",__FILE__,__LINE__);
	#endif
	
	return result;
}
