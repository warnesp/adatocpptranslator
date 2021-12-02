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
 * Description: instantiation of constant_number class
 *
 * $Log: constant_number.cpp,v $
 * Revision 1.2  2005/03/19 14:27:23  quicky2000
 * Update to make the class "constant_number" derive from class "initialised"
 *
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
#include "constant_number.h"

void constant_number::display(FILE *p_Fp)
{
	this->checkIntegrity(__FILE__,__LINE__);	 
}

void constant_number::checkIntegrity(char *p_FileName,int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	int error=0;
	
	unit::checkIntegrity(__FILE__,__LINE__);
	initialised::checkIntegrity(__FILE__,__LINE__);
	
	if(error!=0)
	{
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
	
}

constant_number::constant_number():unit(),initialised()
{
	#ifdef TRACE
	printfTraceUp("constant_number",__FILE__,__LINE__);
	#endif
	#ifdef TRACE
	printfTraceDown("constant_number",__FILE__,__LINE__);
	#endif
}
constant_number::constant_number(char *p_Name,tree * p_InitTree,main_unit *p_MainUnit):unit(p_Name,p_MainUnit),initialised(p_InitTree)
{
	#ifdef TRACE
	printfTraceUp("constant_number",__FILE__,__LINE__);
	#endif
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("constant_number",__FILE__,__LINE__);
	#endif
}
