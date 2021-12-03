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
 * Description: management of files
 *
 * $Log: file_management.h,v $
 * Revision 1.1  2005/03/08 00:20:24  quicky2000
 * Update to:
 * _ move the file from src directory
 *
 * Revision 1.1.1.1  2005/03/01 22:20:37  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef FILE_MANAGEMENT_H
#define FILE_MANAGEMENT_H

#include <stdio.h>
#include <stdlib.h>

#include "my_string.h"

#define FILE_NAME_MAX_SIZE 300

void selectInput (FILE* p_File);
FILE* fileOpen(const char *p_Name, const char *p_OpenMode);
FILE* fileOpen(const char *p_Name, const char *p_Path, const char *p_OpenMode);
FILE* outputFileOpen(const char *p_OutputPath,const char *p_Name,const char *p_Extension);
#endif
