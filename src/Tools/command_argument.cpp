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
 * Description: declaration of functions which manages arguments of line command
 *
 * $Log: command_argument.cpp,v $
 * Revision 1.1  2005/03/08 00:08:05  quicky2000
 * Update to:
 * _ move the file from src directory
 *
 * Revision 1.2  2005/03/02 23:44:09  quicky2000
 * Update to manage both dos and unix format for file containing the list of files to translate
 *
 * Revision 1.1.1.1  2005/03/01 22:20:34  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "command_argument.h"

list<file*>* createListFile(char *p_Name)
{
	FILE *fp=fileOpen(p_Name,"rt");
	char name[FILE_NAME_MAX_SIZE]="\0";
	list<file*> *inputFiles=NULL;
	
	while(fgets(name,FILE_NAME_MAX_SIZE,fp)!=NULL)
	{
		while(strchr(name,'\\')!=NULL)
		{
			*strchr(name,'\\')='/';
		}

		// research of CR character to delete it
		if(strchr(name,13)!=NULL)
		{
			*strchr(name,13)='\0';
		}
		
		// research of END LINE character to delete it
		if(strchr(name,'\n')!=NULL)
		{
			*strchr(name,'\n')='\0';
		}
		printf("name read : \"%s\"\n",name);
		if(inputFiles!=NULL)
		{
			inputFiles->add(new_file(name));
		}
		else
		{
			inputFiles=new list<file*>(new_file(name));
		}
		
		
	}
	fclose(fp);
	
	return inputFiles;
	
	
}
