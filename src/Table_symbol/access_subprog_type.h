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
 * Description: declaration of access_subprog_type class
 *
 * $Log: access_subprog_type.h,v $
 * Revision 1.3  2005/03/27 00:01:45  quicky2000
 * Update to replace the parameter which represent return type by a tree
 * instead of a string to manage type represents by complex nodes like
 * selected comp...
 *
 * Revision 1.2  2005/03/17 20:39:14  quicky2000
 * Update to:
 * _ modify the constructor
 * _ add m_Prototype member
 * _ make protected members be private
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
#ifndef ACCESS_SUBPROG_TYPE_H
#define ACCESS_SUBPROG_TYPE_H

#include "../Tools/error.h"
#include "../Tools/trace.h"

#include "access_type.h"
#include "function_prototype.h"

typedef enum
{
	Access_Subprog_Type_Function,
	Access_Subprog_Type_Procedure,
	Access_Subprog_Type_Undefined
}t_AccessSubprogTypeId;

void displayAccessSubprogTypeId(t_AccessSubprogTypeId p_AccessSubprogTypeId);

class access_subprog_type: public access_type
{
	private:
	t_AccessSubprogTypeId m_AccessSubprogTypeId;
	char m_Protected;
	procedure_prototype *m_Prototype;
	
	public:
	t_AccessSubprogTypeId getAccessSubprogTypeId(void);
	char getProtected(void);
	void checkIntegrity(const char *p_FileName, int p_LineNumber);
	
	access_subprog_type(void);
	access_subprog_type(t_AccessSubprogTypeId p_AccessSubprogTypeId);
	access_subprog_type(t_AccessSubprogTypeId p_AcccesSubprogTypeId,tree *p_ProtectedTree,const char *p_Name,tree *p_FormalPart,tree *p_ReturnTypeTree,main_unit *p_MainUnit);
	access_subprog_type(t_AccessSubprogTypeId p_AcccesSubprogTypeId,tree *p_ProtectedTree,const char *p_Name,tree *p_FormalPart,main_unit *p_MainUnit);
};
#endif
