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
 * Description: declaration of scalar_type class
 *
 * $Log: scalar_type.h,v $
 * Revision 1.2  2005/03/19 09:47:09  quicky2000
 * Update to make protected members become private
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
#ifndef SCALAR_TYPE_H
#define SCALAR_TYPE_H

#include "../Tools/trace.h"

#include "elementary_type.h"

typedef enum
{
	Scalar_Type_Discrete,
	Scalar_Type_Real,
	Scalar_Type_Undefined
}t_ScalarTypeId;

void displayScalarTypeId(t_ScalarTypeId p_ScalarTypeId);

class scalar_type: public elementary_type
{
	private:
	t_ScalarTypeId m_ScalarTypeId;
	
	public:
	t_ScalarTypeId getScalarTypeId(void);
	void checkIntegrity(const char *p_FileName, int p_LineNumber);
	
	scalar_type(void);
	scalar_type(t_ScalarTypeId p_ScalarTypeId);
	scalar_type(t_ScalarTypeId p_ScalarTypeId,const char *p_Name,main_unit *p_MainUnit);
};

#endif
