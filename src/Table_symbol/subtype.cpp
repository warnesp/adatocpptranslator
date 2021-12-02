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
 * Description: instantiation of subtype class
 *
 * $Log: subtype.cpp,v $
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
#include "subtype.h"

void subtype::checkIntegrity(char *p_FileName, int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	int error=0;
	
	type::checkIntegrity(p_FileName,p_LineNumber);
	subtyped::checkIntegrity(p_FileName,p_LineNumber);
	
	if(error!=0)
	{
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
}

subtype::subtype(void):type(Type_Subtype),subtyped()
{
	#ifdef TRACE
	printfTraceUp("subtype",__FILE__,__LINE__);
	#endif
	#ifdef TRACE
	printfTraceDown("subtype",__FILE__,__LINE__);
	#endif
	
}

subtype::subtype(char *p_Name,subtyped *p_Subtyped,main_unit *p_MainUnit):type(Type_Subtype,p_Name,p_MainUnit),subtyped(p_Subtyped)
{
	#ifdef TRACE
	printfTraceUp("subtype",__FILE__,__LINE__);
	#endif
	#ifdef TRACE
	printfTraceDown("subtype",__FILE__,__LINE__);
	#endif
}

subtype *new_subtype(char *p_Name,tree *p_SubtypeTree,main_unit *p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("subtype",__FILE__,__LINE__);
	#endif
	subtype *result=NULL;
	if(p_SubtypeTree!=NULL)
	{
		subtyped *p_Subtyped=new_subtyped(p_SubtypeTree);
		result=new subtype(p_Name,p_Subtyped,p_MainUnit);
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_SubtypeTree");
		my_exit(-1);
	}
	
	#ifdef TRACE
	printfTraceDown("subtype",__FILE__,__LINE__);
	#endif
	
	return result;
}
