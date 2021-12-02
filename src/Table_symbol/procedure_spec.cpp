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
 * Description: declaration of procedure_spec class
 * Description: instantiation of procedure_spec class
 *
 * $Log: procedure_spec.cpp,v $
 * Revision 1.2  2005/03/18 19:21:25  quicky2000
 * Update due to new representation of function and procedure in table of symbol
 *
 * Revision 1.1  2005/03/13 16:44:25  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 *
 * Revision 1.1.1.1  2005/03/01 22:20:42  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "../Tools/error.h"
#include "../Tools/trace.h"

#include "procedure_spec.h"

#include "procedure_prototype.h"

void procedure_spec::checkIntegrity(char *p_FileName, int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	if(m_Prototype==NULL)
	{
		errorIsNull(__FILE__,__LINE__,"m_Prototype");
		my_exit(1);
	}
	unit::checkIntegrity(p_FileName,p_LineNumber);
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
}

	
procedure_spec::procedure_spec(void):unit()
{
	#ifdef TRACE
	printfTraceUp("procedure_spec",__FILE__,__LINE__);
	#endif
	m_Prototype=NULL;
	#ifdef TRACE
	printfTraceDown("procedure_spec",__FILE__,__LINE__);
	#endif
}

procedure_spec::procedure_spec(char *p_Name,tree *p_FormalPart,main_unit *p_MainUnit):unit(p_Name,p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("procedure_spec",__FILE__,__LINE__);
	#endif
	m_Prototype=new procedure_prototype(p_FormalPart,p_MainUnit);
	checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("procedure_spec",__FILE__,__LINE__);
	#endif
}

