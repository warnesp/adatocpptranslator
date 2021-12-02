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
 * Description: instantiation of derived_type class
 *
 * $Log: derived_type.cpp,v $
 * Revision 1.1  2005/03/13 14:36:02  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 *
 * Revision 1.1.1.1  2005/03/01 22:20:35  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "derived_type.h"

void derived_type::checkIntegrity(char *p_FileName, int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	
	type::checkIntegrity(p_FileName,p_LineNumber);
	subtyped::checkIntegrity(p_FileName,p_LineNumber);
	
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
}

derived_type::derived_type(void):type(Type_Derived),subtyped()
{
	#ifdef TRACE
	printfTraceUp("derived_type",__FILE__,__LINE__);
	#endif
	#ifdef TRACE
	printfTraceDown("derived_type",__FILE__,__LINE__);
	#endif
}

derived_type::derived_type(char *p_Name,subtyped *p_Subtype,main_unit *p_MainUnit):type(Type_Derived,p_Name,p_MainUnit),subtyped(p_Subtype)
{
	#ifdef TRACE
	printfTraceUp("derived_type",__FILE__,__LINE__);
	#endif
	#ifdef TRACE
	printfTraceDown("derived_type",__FILE__,__LINE__);
	#endif
}

derived_type *new_derived_type(char *p_Name,tree *p_SubtypeTree,main_unit *p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("derived_type",__FILE__,__LINE__);
	#endif
	derived_type *result=NULL;
	if(p_SubtypeTree!=NULL)
	{
		subtyped *p_Subtyped=new_subtyped(p_SubtypeTree);
		result=new derived_type(p_Name,p_Subtyped,p_MainUnit);
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_SubtypeTree");
		my_exit(-1);
	}
	
	#ifdef TRACE
	printfTraceDown("derived_type",__FILE__,__LINE__);
	#endif
	
	return result;
}
