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
 * Description: declaration of initialised class
 *
 * $Log: initialised.h,v $
 * Revision 1.3  2005/03/19 15:27:08  quicky2000
 * Update to replace the member containing the init oject by a value class instead of a tree class
 *
 * Revision 1.2  2005/03/19 08:39:34  quicky2000
 * Update to make protected members become private
 *
 * Revision 1.1  2005/03/08 19:26:37  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ update the include paths due to the new organization of source files
 *
 * Revision 1.1.1.1  2005/03/01 22:20:38  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef INITIALISED_H
#define INITIALISED_H

#include "../Tools/error.h"
#include "../Tools/trace.h"

#include "../Tools/tree.h"

class value;

class initialised
{
	private:
	char m_BoolInitValue;
	value *m_InitValue;
	
	public:
	char getBoolInitValue(void);
	value* getInitValue(void);
	
	void checkIntegrity(char *p_FileName,int p_LineNumber);
	
	initialised(void);
	initialised(tree *p_InitTree);
	
};
#endif
