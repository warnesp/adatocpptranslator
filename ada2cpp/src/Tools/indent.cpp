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
 * Description: indent tools
 *
 * $Log: indent.cpp,v $
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
#include "indent.h"

char indentString[]="  ";
int indentLevel=0;
int g_PrivateIndentLevel=0;

void indentUp(void)
{
	indentLevel++;
}

void indentDown(void)
{
	indentLevel--;
}

void privateIndentUp(void)
{
	g_PrivateIndentLevel++;
}

void privateIndentDown(void)
{
	g_PrivateIndentLevel--;
}

void fprintfIndent(FILE *fp)
{
	int l_Index=0;
	for(int l_Index=0;l_Index<indentLevel;l_Index++)
	{
		fprintf(fp,"%s",indentString);
	}
}

void privateFprintfIndent(FILE *fp)
{
	int l_Index=0;
	for(int l_Index=0;l_Index<g_PrivateIndentLevel;l_Index++)
	{
		fprintf(fp,"%s",indentString);
	}
}


