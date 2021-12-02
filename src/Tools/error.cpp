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
 * Description: instantiation of error management tools
 *
 * $Log: error.cpp,v $
 * Revision 1.4  2005/03/26 23:15:09  quicky2000
 * Modification of error message
 *
 * Revision 1.3  2005/03/19 13:30:54  quicky2000
 * Update to remove a type fault
 *
 * Revision 1.2  2005/03/17 18:13:02  quicky2000
 * Update to modify the prototype of errorGeneric
 *
 * Revision 1.1  2005/03/08 00:17:50  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ implement new functions to better manage errors
 *
 * Revision 1.1.1.1  2005/03/01 22:20:36  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "error.h"

void errorIsNull(const char *p_FileName,int p_LineNumber, const char *p_Name)
{
	printf("INTERNAL ERROR : %s %i : \"%s\" is NULL\n",p_FileName,p_LineNumber,p_Name);
}

void errorLogManage(FILE *p_Fp,int p_NumLine, const char *p_Comment)
{
	fprintf(p_Fp,"line %i ( in ada file ) : %s is not managed\n",p_NumLine,p_Comment);
}

void errorNbSon(const char *p_FileName,int p_LineNumber,tree *p_Tree)
{
	printf("INTERNAL ERROR : %s %i : nb son \"%i\" is not allowed by grammar for node \"",p_FileName,p_LineNumber,p_Tree->getNbSon());
	displayNodeType(p_Tree->getNodeType());
	printf("\" at ligne %i\n", p_Tree->getNumLine());
}

void errorNotAllowed(const char *p_FileName,int p_LineNumber,tree *p_Tree, const char *p_RuleName)
{
	printf("INTERNAL ERROR : %s %i : node type \"",p_FileName,p_LineNumber);
	displayNodeType(p_Tree->getNodeType());
	printf("\" line %i is not allowed by ada grammar in rule \"%s\"\n",p_Tree->getNumLine(),p_RuleName);
}

void errorGeneric(const char *p_FileName,int p_LineNumber, const char *p_ErrorMessage)
{
		printf("INTERNAL ERROR : %s %i : %s\n",p_FileName,p_LineNumber,p_ErrorMessage);
}

void my_exit(int p_NumError)
{
	printf("Please report this bug to adatoccpptranslator@free.fr\n");
	exit(p_NumError);
}
