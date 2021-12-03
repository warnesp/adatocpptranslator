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
 * Description: declaration of function_rename class
 *
 * $Log: function_rename.h,v $
 * Revision 1.4  2005/03/27 01:04:38  quicky2000
 * Update due to the replacement of return type representation by a tree instead of string
 *
 * Revision 1.3  2005/03/19 11:26:03  quicky2000
 * Update for code maintenance
 *
 * Revision 1.2  2005/03/19 08:35:04  quicky2000
 * Update due:
 * _ to the new representation of function in table of symbol
 * _ to make protected members become private
 *
 * Revision 1.1  2005/03/08 01:02:18  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ update modify include paths due to the new source organization
 *
 * Revision 1.1.1.1  2005/03/01 22:20:38  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef FUNCTION_RENAME_H
#define FUNCTION_RENAME_H

#include <stdio.h>

#include "../Tools/error.h"
#include "../Tools/trace.h"

#include "renamed.h"
#include "function_spec.h"

#include "../Tools/list.h"
class function_rename:public function_spec,public renamed
{
	private:
	char m_BoolGeneric;
	
	public:
	char getBoolGeneric(void);
	
	void checkIntegrity(const char *p_FileName,int p_LineNumber);
	
	function_rename(const char *p_Name,tree *p_FormalPartTree,tree *p_ReturnTypeTree,const char *p_OriginalName,char p_BoolGeneric,main_unit *p_MainUnit);
};
#endif
