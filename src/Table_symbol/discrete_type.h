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
 * Description: declaration of discrete_type class
 *
 * $Log: discrete_type.h,v $
 * Revision 1.2  2005/03/18 19:37:30  quicky2000
 * Update to make protected members become private
 *
 * Revision 1.1  2005/03/08 00:56:20  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ update modify include paths due to the new source organization
 *
 * Revision 1.1.1.1  2005/03/01 22:20:36  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef DISCRETE_TYPE_H
#define DISCRETE_TYPE_H

#include "../Tools/trace.h"

#include "scalar_type.h"

typedef enum
{
	Discrete_Type_Enumerated,
	Discrete_Type_Integer,
	Discrete_Type_Undefined
}t_DiscreteTypeId;

void displayDiscreteTypeId(t_DiscreteTypeId p_DiscreteTypeId);

class discrete_type: public scalar_type
{
	private:
	t_DiscreteTypeId m_DiscreteTypeId;
	
	public:
	t_DiscreteTypeId getDiscreteTypeId(void);
	void checkIntegrity(char *p_FileName, int p_LineNumber);
	
	discrete_type(void);
	discrete_type(t_DiscreteTypeId p_DiscreteTypeId);
	discrete_type(t_DiscreteTypeId p_DiscreteTypeId,char *p_Name,main_unit *p_MainUnit);
};

#endif
