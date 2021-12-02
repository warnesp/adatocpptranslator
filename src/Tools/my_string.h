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
 * Description: management of string
 *
 * $Log: my_string.h,v $
 * Revision 1.2  2005/03/19 13:47:36  quicky2000
 * Update to add declarations of myStrcpy and removeChar functions
 *
 * Revision 1.1  2005/03/08 00:34:40  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ modify the include paths due to the new organisation of source code
 *
 * Revision 1.1.1.1  2005/03/01 22:20:41  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef MY_STRING_H
#define MY_STRING_H

#include <stdlib.h>
#include <stdio.h>

#include <ctype.h>
#include <string.h>
#include <stdarg.h>

#include "error.h"

char *deleteExtension(char *p_Name);
char* myStrcat(int p_Number,char *p_S1,...);
char* myStrcpy(char *p_String);
char *myUpperCase(char *p_name);
char* removeChar(char *l_String,char l_Char);
#endif
