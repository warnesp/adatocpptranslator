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
 * Description: declaration of error management tools
 *
 * $Log: error.h,v $
 * Revision 1.2  2005/03/17 18:13:02  quicky2000
 * Update to modify the prototype of errorGeneric
 *
 * Revision 1.1  2005/03/08 00:16:16  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ add prototype of new functions to better manage errors
 * _ modify the paths of include files due to the new organization of sources
 *
 * Revision 1.1.1.1  2005/03/01 22:20:36  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef ERROR_H
#define ERROR_H

#include <stdlib.h>

#include "tree.h"

void errorIsNull(const char *p_FileName,int p_LineNumber, const char *p_Name);
void errorLogManage(FILE *p_Fp,int p_NumLine,const char *p_Comment);
void errorNotAllowed(const char *p_FileName,int p_LineNumber,tree *p_Tree, const char *p_RuleName);
void errorNbSon(const char *p_FileName,int p_LineNumber,tree *p_Tree);
void errorGeneric(const char *p_FileName,int p_LineNumber,const char *p_ErrorMessage);
void my_exit(int p_NumError);

#endif
