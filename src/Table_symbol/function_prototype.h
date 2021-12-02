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
 * Description: declaration of function_prototype class
 *
 * $Log: function_prototype.h,v $
 * Revision 1.2  2005/03/27 01:04:38  quicky2000
 * Update due to the replacement of return type representation by a tree instead of string
 *
 * Revision 1.1  2005/03/19 08:31:20  quicky2000
 * Add due to the new representation of subprograms in table of symbol
 *
 *
 *****************************************************************************/
#ifndef FUNCTION_PROTOTYPE_H
#define FUNCTION_PROTOTYPE_H

#include "../Tools/error.h"
#include "../Tools/trace.h"

#include "procedure_prototype.h"
#include "typed.h"

class main_unit;

class function_prototype:public typed, public procedure_prototype
{
	private:
	
	public:
	void checkIntegrity(const char *p_FileName, int p_LineNumber);
	
	function_prototype(void);
	function_prototype(tree *p_ReturnTree);
	function_prototype(tree *p_FormalPartTree,tree *p_ReturnTree,main_unit *p_MainUnit);	
};
#endif
