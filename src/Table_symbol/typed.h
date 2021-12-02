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
 * Description: declaration of typed class
 *
 * $Log: typed.h,v $
 * Revision 1.2  2005/03/27 01:02:12  quicky2000
 * Update to replace the memeber type name by:
 * _ a reference ont ree which represents the type
 * _ a reference on the type
 * _ boolean to indicate if the reference on type was computed from the representation of type
 *
 * Revision 1.1  2005/03/09 20:15:27  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ update include paths due to the new sources organization
 *
 * Revision 1.1.1.1  2005/03/01 22:20:52  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef TYPED_H
#define TYPED_H

#include <stdlib.h>

#include "../Tools/error.h"
#include "../Tools/trace.h"

class type;
class main_unit;

class typed
{
	protected :
	tree *m_TypeTree;
	type *m_Type;
	char m_BoolSearched;
	char m_BoolFound;

	public:
	char* getTypeName(void);
	tree* getTypeTree(void);
	type* getType(void);
	
	char isBoolFound(void);
	char isBoolSearched(void);

	typed* setTypeFound(type *p_Type);
	typed* setTypeNotFound(void);


	void checkIntegrity(char *p_FileName,int p_LineNumber);
	
	typed(void);
	typed(tree *p_Tree);
	
};
#endif
