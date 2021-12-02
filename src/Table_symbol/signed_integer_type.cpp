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
 * Description: instantiation of signed_integer_type class
 *
 * $Log: signed_integer_type.cpp,v $
 * Revision 1.2  2005/03/18 19:29:21  quicky2000
 * Update due to the add of a range member in class signed_integer_type
 *
 * Revision 1.1  2005/03/13 16:50:26  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 *
 * Revision 1.1.1.1  2005/03/01 22:20:44  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "signed_integer_type.h"
#include "base_range.h"

void signed_integer_type::checkIntegrity(char *p_FileName, int p_LineNumber)
{	
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	int l_Error=0;
	
	if(m_Range==NULL)
	{
		errorIsNull(__FILE__,__LINE__,"m_Range");
		l_Error=1;
	}
	else
	{
		m_Range->checkIntegrity(p_FileName,p_LineNumber);
	}

	integer_type::checkIntegrity(p_FileName,p_LineNumber);
	
	if(l_Error!=0)
	{
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
}

signed_integer_type::signed_integer_type(void):integer_type(Integer_Type_Signed)
{
	#ifdef TRACE
	printfTraceUp("signed_integer_type",__FILE__,__LINE__);
	#endif
	m_Range=new base_range();
	#ifdef TRACE
	printfTraceDown("signed_integer_type",__FILE__,__LINE__);
	#endif
}

signed_integer_type::signed_integer_type(char *p_Name,tree *p_LowerBound, tree *p_UpperBound, main_unit *p_MainUnit):integer_type(Integer_Type_Signed,p_Name,p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("signed_integer_type",__FILE__,__LINE__);
	#endif
	m_Range=new base_range(p_LowerBound,p_UpperBound);
	#ifdef TRACE
	printfTraceDown("signed_integer_type",__FILE__,__LINE__);
	#endif
}
	
