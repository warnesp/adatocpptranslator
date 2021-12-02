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
 * Description: instantiation of generic_package class
 *
 * $Log: generic_package_inst.cpp,v $
 * Revision 1.2  2005/03/18 19:10:40  quicky2000
 * Update due to protected memberswhich become private
 *
 * Revision 1.1  2005/03/13 16:36:27  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 *
 * Revision 1.1.1.1  2005/03/01 22:20:38  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "generic_package_inst.h"

char* generic_package_inst::getGenericPackageName(void)
{
	return m_GenericPackageName;
}

void generic_package_inst::display(void)
{
	this->checkIntegrity(__FILE__,__LINE__);
	printf("package \"%s\" instantiation of \"%s\" generic package is defined in main unit \"%s\"\n",getName(),m_GenericPackageName,getMainUnit()->getName());
}


void generic_package_inst::checkIntegrity(char *p_FileName,int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	int error=0;
	if(m_GenericPackageName==NULL)
	{
		errorIsNull(p_FileName,p_LineNumber,"m_GenericPackageName");
		error=1;
	}
	
	package::checkIntegrity(p_FileName,p_LineNumber);
	if(error!=0)
	{
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
	
}

generic_package_inst::generic_package_inst(void)
{
	#ifdef TRACE
	printfTraceUp("generic_package_inst",__FILE__,__LINE__);
	#endif
	m_GenericPackageName=NULL;
	#ifdef TRACE
	printfTraceDown("generic_package_inst",__FILE__,__LINE__);
	#endif
	
}

generic_package_inst::generic_package_inst(char *p_Name,char *p_GenericPackageName,main_unit *p_MainUnit):package(Generic_Package_Inst,p_Name,p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("generic_package_inst",__FILE__,__LINE__);
	#endif
	m_GenericPackageName=p_GenericPackageName;
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("generic_package_inst",__FILE__,__LINE__);
	#endif
}

generic_package_inst* new_generic_package_inst(char *p_Name,tree *p_GenericPackageName,main_unit *p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("new_generic_package_inst",__FILE__,__LINE__);
	#endif
	generic_package_inst *result=NULL;
	
	int error=0;
	
	if(p_GenericPackageName==NULL)
	{
		errorIsNull(__FILE__,__LINE__,"p_GenericPackageName");
		error=1;
	}
	
	if(error!=0)
	{
		my_exit(-1);
	}
	
	switch(p_GenericPackageName->getNodeType())
	{
		case Node_Ada_C_Ident:
		result=new generic_package_inst(p_Name,p_GenericPackageName->getString(),p_MainUnit);
		break;
		
		case Node_Ada_Selected_Comp:
		case Node_Ada_Indexed_Comp:
		result=new_generic_package_inst(p_Name,p_GenericPackageName->getSon(0),p_MainUnit);
		break;
		
		default:
		printf("INTERNAL ERROR : %s %i : node type ",__FILE__,__LINE__);
		displayNodeType(p_GenericPackageName->getNodeType());
		printf(" is not manage\n");
		p_GenericPackageName->displayTree();
		my_exit(-1); 
		break;
	}
	
	#ifdef TRACE
	printfTraceDown("new_generic_package_inst",__FILE__,__LINE__);
	#endif
	
	return result;
}
	
