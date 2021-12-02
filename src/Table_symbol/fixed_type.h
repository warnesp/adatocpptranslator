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
 * Description: declaration of fixed_type class
 *
 * $Log: fixed_type.h,v $
 * Revision 1.2  2005/03/18 19:43:02  quicky2000
 * Update due to the new representation of real_type with the add of base_range member
 *
 * Revision 1.1  2005/03/08 01:01:15  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ update modify include paths due to the new source organization
 *
 * Revision 1.1.1.1  2005/03/01 22:20:37  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef FIXED_TYPE_H
#define FIXED_TYPE_H

#include "../Tools/trace.h"

#include "real_type.h"

typedef enum
{
	Fixed_Type_Ordinary,
	Fixed_Type_Decimal,
	Fixed_Type_Undefined
}t_FixedTypeId;

void displayFixedTypeId(t_FixedTypeId p_FixedTypeId);

class fixed_type: public real_type
{
	private:
	t_FixedTypeId m_FixedTypeId;
	tree *m_Delta;
	
	public:
	t_FixedTypeId getFixedTypeId(void);
	tree* getDelta(void);
	
	void checkIntegrity(char *p_FileName, int p_LineNumber);
	
	fixed_type(void);
	fixed_type(t_FixedTypeId p_FixedTypeId);
	fixed_type(t_FixedTypeId p_FixedTypeId,char *p_Name,tree *p_Delta,main_unit *p_MainUnit);
	fixed_type(t_FixedTypeId p_FixedTypeId,char *p_Name,tree *p_Delta,tree *p_LowerBound, tree *p_UpperBound, main_unit *p_MainUnit);
	
};
#endif
