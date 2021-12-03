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
 * Description: declaration of elementary_type class
 *
 * $Log: elementary_type.h,v $
 * Revision 1.2  2005/03/18 19:41:29  quicky2000
 * Update to make protected members become private
 *
 * Revision 1.1  2005/03/08 00:58:07  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ update modify include paths due to the new source organization
 *
 * Revision 1.1.1.1  2005/03/01 22:20:36  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef ELEMENTARY_TYPE_H
#define ELEMENTARY_TYPE_H

#include "../Tools/trace.h"

#include "type.h"

typedef enum
{
	Elementary_Type_Access,
	Elementary_Type_Scalar,
	Elementary_Type_Undefined
}t_ElementaryTypeId;

void displayElementaryTypeId(t_ElementaryTypeId p_ElementaryTypeId);

/**
 * Classe représentant les types élémentaires
 * @author THEVENON Julien
 * @version 1-0-1 Beta
 * @since 18 juillet 2003
 */
class elementary_type: public type
{
	private:

    /**
     * Type permettant de savoir de quel elementary type il s'agit
     */
	t_ElementaryTypeId m_ElementaryTypeId;
	
	public:
	t_ElementaryTypeId getElementaryTypeId(void);

	void checkIntegrity(const char *p_FileName, int p_LineNumber);
	
	elementary_type(void);
	elementary_type(t_ElementaryTypeId p_ElementaryTypeId);

    /**
     * Constructeur vide
     * @param p_Name - nom de l'lementary_type*/
	elementary_type(t_ElementaryTypeId p_ElementaryTypeId,const char *p_Name,main_unit *p_MainUnit);
};
#endif
