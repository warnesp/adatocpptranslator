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
 * Description: instantiation of subunit class
 *
 * $Log: subunit.cpp,v $
 * Revision 1.1  2005/03/13 16:50:27  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 *
 * Revision 1.1.1.1  2005/03/01 22:20:44  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "subunit.h"

char* subunit::getParentUnitName(void)
{
	return m_ParentUnitName;
}

void subunit::checkIntegrity(char *p_FileName, int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	int error=0;
	
	if(m_ParentUnitName==NULL)
	{
		errorIsNull(p_FileName,p_LineNumber,"m_ParentUnitName");
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

subunit::subunit(void):package()
{
	#ifdef TRACE
	printfTraceUp("subunit",__FILE__,__LINE__);
	#endif
	m_ParentUnitName=NULL;
	#ifdef TRACE
	printfTraceDown("subunit",__FILE__,__LINE__);
	#endif
}

subunit::subunit(char *p_Name,char *p_ParentUnitName,main_unit *p_MainUnit):package(Subunit,p_Name,p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("subunit",__FILE__,__LINE__);
	#endif
	m_ParentUnitName=p_ParentUnitName;
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("subunit",__FILE__,__LINE__);
	#endif
}

