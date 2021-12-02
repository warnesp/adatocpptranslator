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
 * Description: instantiation of tree string representation
 *
 * $Log: tree_string_representation.cpp,v $
 * Revision 1.2  2005/03/26 18:00:34  quicky2000
 * Update to manage Node_Ada_Selected_Comp_All
 *
 * Revision 1.1  2005/03/08 00:45:09  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ update to maintain code
 *
 * Revision 1.1.1.1  2005/03/01 22:20:50  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/

#include "tree_string_representation.h"

const char* getString(tree *p_Tree)
{
	const char *result=NULL;
	
	if(p_Tree!=NULL)
	{
		switch(p_Tree->getNodeType())
		{
			case Node_Ada_C_String:
			case Node_Ada_C_Ident:
			result=p_Tree->getString();
			break;
			
			case Node_Ada_Selected_Comp:
			case Node_Ada_Mark_Point:
			case Node_Ada_Compound_Name:
			{
				const char *s1=NULL,*s2=NULL;
				s1=getString(p_Tree->getSon(0));
				s2=getString(p_Tree->getSon(1));
				result=myStrcat(3,s1,".",s2);
			}
			break;
			
			case Node_Ada_Selected_Comp_All:
			case Node_Ada_Indexed_Comp:
			result=getString(p_Tree->getSon(0));
			break;
			
            //case Node_Ada_Attribute:
            //result = "Foo";
            //break;

			default:
			printf("ERROR : %s %i : node type \"",__FILE__,__LINE__);
			displayNodeType(p_Tree->getNodeType());
			printf("\" is not manage\n");
			my_exit(-1);
		 
		}
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	
	return result;
}
