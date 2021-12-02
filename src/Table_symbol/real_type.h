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
 * Description: declaration of real_type class
 *
 * $Log: real_type.h,v $
 * Revision 1.2  2005/03/19 09:43:42  quicky2000
 * Update to make protected members become private
 * _ to add a range member to real_type class
 *
 * Revision 1.1  2005/03/09 20:07:39  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ update include paths due to the new sources organization
 *
 * Revision 1.1.1.1  2005/03/01 22:20:43  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef REAL_TYPE_H
#define REAL_TYPE_H

#include "../Tools/trace.h"

#include "scalar_type.h"
class base_range;

typedef enum
{
	Real_Type_Floating,
	Real_Type_Fixed,
	Real_Type_Undefined
}t_RealTypeId;

void displayRealTypeId(t_RealTypeId p_RealTypeId);

class real_type: public scalar_type
{
	private:
	t_RealTypeId m_RealTypeId;
	base_range *m_Range;
	char m_BoolRange;
	
	public:
	t_RealTypeId getRealTypeId(void);
	void checkIntegrity(char *p_FileName, int p_LineNumber);
	
	char getBoolRange(void);
		
	real_type(void);
	real_type(t_RealTypeId p_RealTypeId);
	real_type(t_RealTypeId p_RealTypeId,char *p_Name,tree *p_LowerBound,tree *p_UpperBound,main_unit *p_MainUnit);
	real_type(t_RealTypeId p_RealTypeId,char *p_Name,main_unit *p_MainUnit);
};

#endif
