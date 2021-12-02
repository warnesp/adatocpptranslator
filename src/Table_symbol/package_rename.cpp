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
 * Description: instantiation of package_rename class
 *
 * $Log: package_rename.cpp,v $
 * Revision 1.1  2005/03/13 16:44:25  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 *
 * Revision 1.1.1.1  2005/03/01 22:20:41  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "package_rename.h"

char package_rename::getBoolGeneric(void)
{
	return m_BoolGeneric;
}
	
void package_rename::checkIntegrity(char *p_FileName,int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	renamed::checkIntegrity(__FILE__,__LINE__);
	named::checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
	
}

package_rename::package_rename(char *p_PackageName,char *p_OriginalName,char p_BoolGeneric,main_unit *p_MainUnit):unit(p_PackageName,p_MainUnit),renamed(p_OriginalName)
{
	#ifdef TRACE
	printfTraceUp("package_rename",__FILE__,__LINE__);
	#endif
	m_BoolGeneric=p_BoolGeneric;
	#ifdef TRACE
	printfTraceDown("package_rename",__FILE__,__LINE__);
	#endif
	
}
