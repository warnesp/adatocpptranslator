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
 * Description: instantiation of function_rename class
 *
 * $Log: function_rename.cpp,v $
 * Revision 1.3  2005/03/27 01:04:38  quicky2000
 * Update due to the replacement of return type representation by a tree instead of string
 *
 * Revision 1.2  2005/03/18 19:06:01  quicky2000
 * Update to modify the class according to the new class architecture
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
#include "function_rename.h"
 
char function_rename::getBoolGeneric(void)
{
	return m_BoolGeneric;
}
	
void function_rename::checkIntegrity(char *p_FileName,int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	renamed::checkIntegrity(__FILE__,__LINE__);
	function_spec::checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
	
}

function_rename::function_rename(char *p_Name,tree *p_FormalPartTree,tree *p_ReturnTypeTree,char *p_OriginalName,char p_BoolGeneric,main_unit *p_MainUnit):function_spec(p_Name,p_FormalPartTree,p_ReturnTypeTree,p_MainUnit),renamed(p_OriginalName)
{
	#ifdef TRACE
	printfTraceUp("function_rename",__FILE__,__LINE__);
	#endif
	m_BoolGeneric=p_BoolGeneric;
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("function_rename",__FILE__,__LINE__);
	#endif
	
}
