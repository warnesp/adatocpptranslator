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
 * Description: declaration of trace tools
 *
 * $Log: trace.h,v $
 * Revision 1.2  2005/03/17 18:36:07  quicky2000
 * Update to indent code
 *
 * Revision 1.1  2005/03/08 00:38:41  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ update the paths of include files due to the new source organization
 *
 * Revision 1.1.1.1  2005/03/01 22:20:48  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef TRACE_H
	#define TRACE_H

	#include <stdio.h>

//	#define TRACE

	void printfTraceUp(const char *p_functionName, const char *p_FileName,int p_lineNumber);
	void printfTrace(const char *p_functionName, const char *p_FileName,int p_lineNumber);
	void printfTraceDown(const char *p_functionName, const char *p_FileName,int p_lineNumber);

#endif
