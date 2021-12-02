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
 * Description: declaration of renamed class
 *
 * $Log: renamed.cpp,v $
 * Revision 1.1  2005/03/13 16:44:25  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 *
 * Revision 1.1.1.1  2005/03/01 22:20:43  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "renamed.h"

char* renamed::getOriginalName(void)
{
	return m_OriginalName;
}

void renamed::checkIntegrity(char *p_FileName, int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	int error=0;

	if(m_OriginalName==NULL)
	{
		errorIsNull(p_FileName,p_LineNumber,"m_OriginalName");
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

renamed::renamed(void)
{
	#ifdef TRACE
	printfTraceUp("renamed",__FILE__,__LINE__);
	#endif
	m_OriginalName=NULL;
	#ifdef TRACE
	printfTraceDown("renamed",__FILE__,__LINE__);
	#endif
}

renamed::renamed(char *p_OriginalName)
{
	#ifdef TRACE
	printfTraceUp("renamed",__FILE__,__LINE__);
	#endif
	m_OriginalName=p_OriginalName;
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("renamed",__FILE__,__LINE__);
	#endif
}
