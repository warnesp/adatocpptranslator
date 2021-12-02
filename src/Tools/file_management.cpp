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
 * $Log: file_management.cpp,v $
 * Revision 1.1  2005/03/08 00:21:14  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ improve error messages
 *
 * Revision 1.1.1.1  2005/03/01 22:20:37  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "file_management.h"

/*****************************************************************************
 * Procedure name : selectInput
 *
 * Input : fin (reference on a file )
 * Output : .
 * Modified variable : yyin ( declared in flex and bison file )
 * Description : Procedure which put in global yyin variable the reference contain
 * in variable fin
 *****************************************************************************/
void selectInput (FILE* p_File)
{
  extern FILE* yyin;
  yyin = p_File;
}

FILE* fileOpen(char *p_Name, char *p_OpenMode)
{
	return fileOpen(p_Name,"./",p_OpenMode);
}

FILE* fileOpen(char *p_Name,char *p_Path, char *p_OpenMode)
{
	FILE *fp=NULL;
	
	char *name=myStrcat(2,p_Path,p_Name);
	
	if((fp=fopen(name,p_OpenMode))==NULL)
	{
		printf("ERROR : unable to open file : \"%s\"\n",name);
		exit(-1);
	}
	
	return fp;
}

FILE* outputFileOpen(char *p_OutputPath,char *p_Name,char *p_Extension)
{
	FILE *fp=NULL;
	
	/* Copy of file name */
	char *name=deleteExtension(p_Name);
	
	if((fp=fopen(myStrcat(5,p_OutputPath,"/",name,".",p_Extension),"w"))==NULL)
	{
		printf("ERROR : unable to open file : \"%s\"\n",name);
		exit(-1);
	}
	
	return fp;
}
