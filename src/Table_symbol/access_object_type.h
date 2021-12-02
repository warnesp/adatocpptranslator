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
 * Description: declaration of access_object_type class
 *
 * $Log: access_object_type.h,v $
 * Revision 1.3  2005/03/26 23:54:10  quicky2000
 * Update to replace the parameter which represent type by a tree instead of a string to manage type represents by complex nodes like selected comp...
 *
 * Revision 1.2  2005/03/17 19:09:23  quicky2000
 * Update to make protected members be private
 *
 * Revision 1.1  2005/03/08 00:50:26  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ update modify include paths due to the new source organization
 *
 * Revision 1.1.1.1  2005/03/01 22:20:31  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef ACCESS_OBJECT_TYPE_H
#define ACCESS_OBJECT_TYPE_H

#include "../Tools/error.h"
#include "../Tools/trace.h"
#include "../Tools/tree_string_representation.h"

#include "../Tools/tree.h"

#include "access_type.h"
#include "typed.h"

typedef enum
{
	Access_Object_Type_All,
	Access_Object_Type_Constant,
	Access_Object_Type_Normal,
	Access_Object_Type_Undefined
}t_AccessObjectTypeId;

void displayAccessObjectTypeId(t_AccessObjectTypeId p_AccessObjectTypeId);
	
class access_object_type: public access_type, public typed
{
	private:
	t_AccessObjectTypeId m_AccessObjectTypeId;
	
	public:
	t_AccessObjectTypeId getAccessObjectTypeId(void);
	void checkIntegrity(const char *p_FileName,int p_LineNumber);
	
	access_object_type(void);
	access_object_type(t_AccessObjectTypeId p_AccessObjectTypeId,const char *p_Name,tree *p_TypeTree,main_unit *p_MainUnit);
};

access_object_type* new_access_object_type(const char *p_Name,tree *p_AccessTree,main_unit *p_MainUnit);
#endif
