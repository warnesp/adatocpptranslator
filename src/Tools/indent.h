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
 * Description: indent tools declaration
 *
 * $Log: indent.h,v $
 * Revision 1.2  2005/03/17 18:23:01  quicky2000
 * Update to comment useless code
 *
 * Revision 1.1  2005/03/08 00:23:48  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ add functions to manage indentation
 *
 * Revision 1.1.1.1  2005/03/01 22:20:38  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef INDENT_H
#define INDENT_H

#include <stdio.h>

void indentUp(void);
void indentDown(void);
//void privateIndentUp(void);
//void privateIndentDown(void);
void fprintfIndent(FILE *fp);
//void privateFprintfIndent(FILE *fp);
#endif
