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
 * Description: instantiation of functions which manages arguments of line 
 * command
 *
 * $Log: command_argument.h,v $
 * Revision 1.1  2005/03/08 00:05:09  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ modify the include paths due to new organisation of source files
 *
 * Revision 1.1.1.1  2005/03/01 22:20:34  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef COMMAND_ARGUMENT_H
#define COMMAND_ARGUMENT_H

#include "../Tools/list.h"
#include "../Table_symbol/file.h"
#include "file_management.h"

list<file*>* createListFile(const char *p_Name);
#endif
