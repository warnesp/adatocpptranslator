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
 * Description: declaration of subtyped class
 *
 * $Log: subtyped.h,v $
 * Revision 1.3  2005/03/27 01:04:11  quicky2000
 * Update due to the replacement of type representation by a tree instead of string
 *
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
#ifndef SUBTYPED_H
#define SUBTYPED_H

#include "../Tools/error.h"
#include "../Tools/trace.h"

#include "../Tools/tree.h"
#include "../Tools/tree_string_representation.h"
#include "typed.h"

class subtyped: public typed
{
	private:
	char m_BoolConstraint;
	tree *m_Constraint;
	
	public:
	char getBoolConstraint(void);
	tree* getConstraint(void);
	
	void checkIntegrity(const char *p_FileName, int p_Linenumber);
	
	subtyped(void);
	subtyped(subtyped *p_Subtyped);
	subtyped(tree *p_NameTree,char p_BoolConstraint,tree *p_Constraint=NULL);
};
subtyped* new_subtyped(tree *p_Tree);
#endif
