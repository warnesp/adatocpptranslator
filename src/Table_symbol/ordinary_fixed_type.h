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
 * Description: declaration of ordinary_fixed_type class
 *
 * $Log: ordinary_fixed_type.h,v $
 * Revision 1.2  2005/03/19 08:46:57  quicky2000
 * Update to make protected members become private
 *
 * Revision 1.1  2005/03/08 20:14:48  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ update the include paths due to the new organization of sources
 *
 * Revision 1.1.1.1  2005/03/01 22:20:41  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef ORDINARY_FIXED_TYPE_H
#define ORDINARY_FIXED_TYPE_H

#include "../Tools/error.h"
#include "../Tools/trace.h"

#include "fixed_type.h"

class ordinary_fixed_type: public fixed_type
{
	private:
	public:
	void checkIntegrity(char *p_FileName, int p_LineNumber);
	ordinary_fixed_type(void);
	ordinary_fixed_type(char *p_Name,tree *p_Delta,tree *p_LowerBound, tree *p_UpperBound, main_unit *p_MainUnit);

};

ordinary_fixed_type* new_ordinary_fixed_type(char *p_Name,tree *p_Delta,tree *p_Range, main_unit *p_MainUnit);
#endif
