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
 * Description: declaration of prot class
 *
 * $Log: prot.h,v $
 * Revision 1.2  2005/03/19 09:20:16  quicky2000
 * Update to make protected members to become private
 *
 * Revision 1.1  2005/03/08 20:18:26  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ update the include paths due to the new organization of sources
 *
 * Revision 1.1.1.1  2005/03/01 22:20:42  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/

#ifndef PROT_H
#define PROT_H

#include "../Tools/trace.h"

#include "main_unit.h"
#include "unit.h"

typedef enum
{
	Prot_Normal,
	Prot_Type,
	Prot_Undefined
}t_ProtType;

void displayProtType(t_ProtType p_ProtType);

class prot: public main_unit
{
	private:
	t_ProtType m_ProtType;
	
	public:
	t_ProtType getProtType(void);
	
	void checkIntegrity(const char *p_FileName, int p_LineNumber);
	
	prot(void);
	prot(t_ProtType p_ProtType,const char *p_Name,main_unit *p_CurrentMainUnit);
};
#endif
