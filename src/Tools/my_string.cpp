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
 * $Log: my_string.cpp,v $
 * Revision 1.2  2005/03/19 13:36:29  quicky2000
 * Update to add implementations of functions:
 * _ myStrcpy
 * _ removeChar
 *
 * Revision 1.1  2005/03/08 00:35:22  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ maintainance of code
 *
 * Revision 1.1.1.1  2005/03/01 22:20:41  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "my_string.h"

char* deleteExtension(char *p_Name)
{
	/* Copy of file name */
	char *l_Name=(char *)malloc((1+strlen(p_Name))*sizeof(char));
	
	if(l_Name==NULL)
	{
		printf("ERROR : %s %i : memory allocation has failed\n",__FILE__,__LINE__);
		my_exit(-1);
	}
	strcpy(l_Name,p_Name);
	
	if(strrchr(l_Name,'.')!=NULL)
	{
		*strrchr(l_Name,'.')='\0';
	}
	return l_Name;
}

char* myStrcat(int p_Number,char *p_S1,...)
{
	char *result=NULL;
	int length=strlen(p_S1);
	va_list ap;
	va_start(ap,p_S1);
	for(int i=1;i<p_Number;i++)
	{
		length+=strlen(va_arg(ap,char*));
	}
	
	result=(char*)malloc((length+1)*sizeof(char));
	if(result==NULL)
	{
		printf("ERROR : %s %i : memory allocation has failed\n");
		my_exit(-1);
	}
	va_start(ap,p_S1);
	strcpy(result,p_S1);
	for(int i=1;i<p_Number;i++)
	{
		strcat(result,va_arg(ap,char*));
	}
	
	va_end(ap);
	return result;
}

char* myStrcpy(char *p_String)
{
	char *l_Result=NULL;
	
	if(p_String!=NULL)
	{
		l_Result = (char*)malloc((strlen(p_String)+1)*sizeof(char));
		strcpy(l_Result,p_String);
	}
	else
	{
		printf("INTERNAL ERROR : %s %i : \"p_String\" is NULL\n");
		my_exit(-1);
	}

	return l_Result;
}


char *myUpperCase(char *p_Name)
{
	char *l_NewName=NULL;
	
	if(p_Name!=NULL)
	{
		l_NewName=(char *)malloc(sizeof(char)*(1+strlen(p_Name)));
		if(l_NewName==NULL)
		{
			printf("ERROR : %s %i : memory allocation failed\n",__FILE__,__LINE__);
			my_exit(-1);
		}
		for(int l_I=0;l_I<=strlen(p_Name);l_I++)
		{
			l_NewName[l_I]=toupper(p_Name[l_I]);
		}
	}
	else
	{
		printf("ERROR : %s %i : \"p_Name\" is NULL\n",__FILE__,__LINE__);
		my_exit(-1);
	}
	
	return l_NewName;
}

char* removeChar(char *l_String,char l_Char)
{
	char *l_Result=NULL;
	int l_NbChar=0;
	int l_Index=0;
	
	while( l_String[l_Index] != '\0' )
	{
		if(l_String[l_Index] != l_Char)
		{
			l_Result=(char*)realloc(l_Result,(l_NbChar+1)*sizeof(char));
			l_Result[l_NbChar]=l_String[l_Index];
			l_NbChar++;
		}
		l_Index++;
	}
	
	l_Result=(char*)realloc(l_Result,(l_NbChar+1)*sizeof(char));
	l_Result[l_NbChar]='\0';
	
	return l_Result;
}
