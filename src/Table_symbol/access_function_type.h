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
 * Description: declaration of access_function_type class
 *
 * $Log: access_function_type.h,v $
 * Revision 1.3  2005/03/26 23:50:48  quicky2000
 * Update to replace the parameter which represent return type by a tree instead of a string to manage type represents by complex nodes like selected comp...
 *
 * Revision 1.2  2005/03/17 19:11:14  quicky2000
 * Update to:
 * _ remove useless include
 * _ modify class architecture
 *
 * Revision 1.1  2005/03/08 00:50:26  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ update modify include paths due to the new source organization
 *
 * Revision 1.1.1.1  2005/03/01 22:20:31  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef ACCESS_FUNCTION_TYPE_H
#define ACCESS_FUNCTION_TYPE_H

#include "../Tools/error.h"
#include "../Tools/trace.h"

#include "access_subprog_type.h"
class function_prototype;

class access_function_type: public access_subprog_type
{
	private:
	
	public:
	void checkIntegrity(char *p_FileName, int p_LineNumber);
	
	access_function_type(void);
	access_function_type(char *p_Name,tree *p_ProtectedTree,tree *p_FormalPartTree, tree *p_ReturnTypeTree,main_unit *p_MainUnit);
};
#endif
