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
 * Description: declaration of array class
 *
 * $Log: array.h,v $
 * Revision 1.2  2005/03/17 22:22:38  quicky2000
 * Update to make protected member become private
 *
 * Revision 1.1  2005/03/08 00:50:26  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ update modify include paths due to the new source organization
 *
 * Revision 1.1.1.1  2005/03/01 22:20:32  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef ARRAY_H
#define ARRAY_H

#include "../Tools/error.h"
#include "../Tools/trace.h"

#include "../Tools/list.h"
#include "subtyped.h"
#include "../Tools/tree.h"

typedef enum
{
	Array_Constrained,
	Array_Unconstrained,
	Array_Undefined
}t_ArrayId;

void displayArrayId(t_ArrayId p_ArrayId);

class array:public subtyped
{
	private:
	t_ArrayId m_ArrayId;
	list<tree*> *m_Dims;
	int m_NbDim;
	
	public:
	void checkIntegrity(char *p_FileName,int p_LineNumber);
	t_ArrayId getArrayId(void);
	list<tree*>* getDims(void);
	int getNbDim(void);
	
	array(void);
	array(t_ArrayId p_ArrayId);
	array(array *p_Array);
	array(t_ArrayId p_ArrayId,list<tree*> *p_Dims, int p_NbDim,subtyped *p_Subtyped);
};

array* new_array(tree *p_Tree);
#endif
