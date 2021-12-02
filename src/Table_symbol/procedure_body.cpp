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
 * Description: instantiation of procedure_body class
 *
 * $Log: procedure_body.cpp,v $
 * Revision 1.2  2005/03/18 19:21:24  quicky2000
 * Update due to new representation of function and procedure in table of symbol
 *
 * Revision 1.1  2005/03/13 16:47:17  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 * _ to add a function to search a variable in parameter list
 *
 * Revision 1.1.1.1  2005/03/01 22:20:42  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "../Tools/error.h"
#include "../Tools/trace.h"

#include "procedure_body.h"
#include "procedure_prototype.h"

void procedure_body::checkIntegrity(const char *p_FileName, int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	if(m_Prototype==NULL)
	{
		errorIsNull(__FILE__,__LINE__,"m_Prototype");
		my_exit(1);
	}
	main_unit::checkIntegrity(p_FileName,p_LineNumber);
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
}

list<parameter*>* procedure_body::getParameters(void)
{
	return m_Prototype->getParameters();
}
	
	procedure_body::procedure_body(void):main_unit()
	{
		#ifdef TRACE
		printfTraceUp("procedure_body",__FILE__,__LINE__);
		#endif
		m_Prototype=NULL;
		#ifdef TRACE
		printfTraceDown("procedure_body",__FILE__,__LINE__);
		#endif
	}

	procedure_body::procedure_body(const char *p_Name,tree *p_FormalPartTree,main_unit *p_MainUnit):main_unit(Main_Unit_Procedure_Body,p_Name,p_MainUnit)
	{
		#ifdef TRACE
		printfTraceUp("procedure_body",__FILE__,__LINE__);
		#endif
		m_Prototype=new procedure_prototype(p_FormalPartTree,p_MainUnit);
		checkIntegrity(__FILE__,__LINE__);
		#ifdef TRACE
		printfTraceDown("procedure_body",__FILE__,__LINE__);
		#endif
	}

