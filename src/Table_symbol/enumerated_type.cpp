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
 * Description: instantiation of enumerated_type class
 *
 * $Log: enumerated_type.cpp,v $
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
#include "enumerated_type.h"

void enumerated_type::checkIntegrity(char *p_FileName, int p_LineNumber)
{	
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	int error=0;
	
	discrete_type::checkIntegrity(p_FileName,p_LineNumber);
	if(m_EnumerationLitterals==NULL)
	{
		errorIsNull(p_FileName,p_LineNumber,"m_EnumerationLitterals");
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

enumerated_type::enumerated_type(void):discrete_type(Discrete_Type_Enumerated)
{
	#ifdef TRACE
	printfTraceUp("enumerated_type",__FILE__,__LINE__);
	#endif
	m_EnumerationLitterals=NULL;
	#ifdef TRACE
	printfTraceDown("enumerated_type",__FILE__,__LINE__);
	#endif
	
}

enumerated_type::enumerated_type(char *p_Name,list<named*> *p_EnumerationLitterals, main_unit *p_MainUnit):discrete_type(Discrete_Type_Enumerated,p_Name,p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("enumerated_type",__FILE__,__LINE__);
	#endif
	m_EnumerationLitterals=p_EnumerationLitterals;
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("enumerated_type",__FILE__,__LINE__);
	#endif
	
}

enumerated_type* new_enumerated_type(char *p_Name,tree *p_EnumerationLitteralTree,main_unit *p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("new_enumerated_type",__FILE__,__LINE__);
	#endif
	enumerated_type *result=NULL;
	
	if(p_EnumerationLitteralTree!=NULL)
	{
		list<named*> *p_EnumerationLitterals=NULL;
		p_EnumerationLitterals=getListEnumerationLitteral(p_EnumerationLitteralTree,p_EnumerationLitterals);
		result=new enumerated_type(p_Name,p_EnumerationLitterals,p_MainUnit);
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_EnumerationLitteralTree");
		my_exit(-1);
	}
	
	
	#ifdef TRACE
	printfTraceDown("new_enumerated_type",__FILE__,__LINE__);
	#endif
	
	return result;
	
}
