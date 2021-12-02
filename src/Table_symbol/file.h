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
 * Description: declaration of file type
 *
 * $Log: file.h,v $
 * Revision 1.1  2005/03/08 01:01:15  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ update modify include paths due to the new source organization
 *
 * Revision 1.1.1.1  2005/03/01 22:20:37  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef FILE_H
#define FILE_H

#include "../Tools/error.h"
#include "../Tools/trace.h"

#include "main_unit.h"
#include "../Tools/tree.h"
#include "unit.h"

class file : public main_unit
{
	private:
	char *m_Path;
	tree *m_Tree;
	char m_BoolHeader;
	
	public:
	
	void display(void);
	void checkIntegrity(const char *p_FileName,int p_LineNumber);
	
	char* getPath(void);
	tree* getTree(void);
	char getBoolHeader(void);
	
	void setTree(tree *p_Tree);
	void setBoolHeader(char p_BoolHeader);
	
	file();
	file(const char *p_Name,char *p_Path);
	
};

file* new_file(char *p_Name);

#endif
