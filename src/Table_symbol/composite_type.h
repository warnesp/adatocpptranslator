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
 * Description: declaration of composite_type class
 *
 * $Log: composite_type.h,v $
 * Revision 1.2  2005/03/18 19:37:30  quicky2000
 * Update to make protected members become private
 *
 * Revision 1.1  2005/03/08 00:53:12  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ update modify include paths due to the new source organization
 *
 * Revision 1.1.1.1  2005/03/01 22:20:35  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef COMPOSITE_TYPE_H
#define COMPOSITE_TYPE_H

#include "../Tools/trace.h"

#include "type.h"

typedef enum
{
	Composite_Type_Array,
	Composite_Type_Record,
	Composite_Type_Undefined
}t_CompositeTypeId;

void displayCompositeTypeId(t_CompositeTypeId p_CompositeTypeId);

class composite_type:public type
{
	private:
	t_CompositeTypeId m_CompositeTypeId;
	
	public:
	t_CompositeTypeId getCompositeTypeId(void);
	
	void checkIntegrity(char *p_FleName,int p_LineNumber);
	
	composite_type(void);
	composite_type(t_CompositeTypeId p_CompositeTypeId);
	composite_type(t_CompositeTypeId p_CompositeTypeId,char *p_Name,main_unit *p_MainUnit);
};
	
#endif
