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
 * Description: declaration of signed_integer_type class
 *
 * $Log: signed_integer_type.h,v $
 * Revision 1.2  2005/03/19 09:49:30  quicky2000
 * Update to remove the inheritance from base_range class due to add of a base_range member to integer_type
 *
 * Revision 1.1  2005/03/09 20:07:39  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ update include paths due to the new sources organization
 *
 * Revision 1.1.1.1  2005/03/01 22:20:44  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef SIGNED_INTEGER_TYPE_H
#define SIGNED_INTEGER_TYPE_H

#include "../Tools/trace.h"

#include "integer_type.h"
class base_range;

class signed_integer_type: public integer_type
{
	private:
	base_range *m_Range;
	
	public:
	void checkIntegrity(char *p_FileName, int p_LineNumber);
	
	signed_integer_type(void);
	signed_integer_type(char *p_Name,tree *p_LowerBound, tree *p_UpperBound, main_unit *p_MainUnit);
	
};
#endif
