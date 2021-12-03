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
 * Description: translator
 *
 * $Log: translator.cpp,v $
 * Revision 1.4  2005/03/19 12:41:06  quicky2000
 * Update to modify description comment. This file become the "main" file of translator
 *
 * Revision 1.3  2005/03/16 18:32:39  quicky2000
 * Update to reflect the change in prototype of setTableSymbolMember of class tree
 *
 * Revision 1.2  2005/03/04 19:33:38  quicky2000
 * maintenance of code : reomming of some variables to respect coding rules
 *
 * Revision 1.1.1.1  2005/03/01 22:20:54  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "translator.h"

#include <string.h>

int main(int argc, char** argv)
{
	// Display informations on Adatoccpptranslator current version
	g_Config->display();
	printf("\n");
	
	if(argc != 2)
	{
		printf("ERROR : %s %i : this program must have one argument (file containing list of files to translate)\n", __FILE__, __LINE__);
		exit(-1);
	}
    else if(strcmp(argv[1], "-h") == 0 ||
            strcmp(argv[1], "--help") == 0)
    {
        printf("Takes one argument that is a file name which contains a list of files to translate. One file per line.\n");
        exit(0);
    }
	
	const char *l_Name = argv[1];
	
	// analyse of input file
	printf("*************************\n* Analyse of input file *\n*************************\n");
	
	list<file*> *l_InputFiles = createListFile(l_Name);
	
	printf("\n*********************************\n* Parsing and analysis of files *\n*********************************\n");
	
	/***********************************
	 * _Parsing of files
	 * _Redistribution of comments
	 * _Creation of each symbol table
	 ***********************************/
	 list<file*> *l_Current = l_InputFiles;
	
	while(l_Current != NULL)
	{
		l_Name = l_Current->getItem()->getName();
		char *path = l_Current->getItem()->getPath();
		FILE * fpIn = fileOpen(l_Name, path, "rt");
		selectInput(fpIn);
		
		/*****************
		 *  Parse of file
		 *****************/
		printf("parse of file \"%s\"\n", l_Name);
			
		//Call of bison function which analyse the file
		yyparse();
		g_LineNumber = 1;
		fclose(fpIn);
		if(g_BoolSyntaxError != 0)
		{
			exit(-1);
		}
		
		/******************************
		 *  Redistribution of comments
		 ******************************/
		myYyval->redistributeComments();
		
		/******************************
		 *  generation of symbol table
		 ******************************/
		g_CurrentFile = l_Current->getItem();
	
		printf("generation of table symbol of file \"%s\"\n", l_Name);
		myYyval->setTableSymbolMember(g_CurrentFile);
		tableSymboleCreation(myYyval);
		
		g_CurrentFile->setTree(myYyval);
		
		printf("\n");
		
		l_Current = l_Current->getNext();
	}
	
	/************************
	 * Translation of files *
	 ************************/
	/* Opening of log file */
	/*FILE *l_FpDisplay = fileOpen( "table_symbol.bak","w");
	if( l_FpDisplay!=NULL)
	{
		g_TableSymbol->display(l_FpDisplay);
		fclose(l_FpDisplay);
	}*/
	
	/************************
	 * Translation of files *
	 ************************/
	l_Current = l_InputFiles;
	
	printf("************************\n* translation of files *\n************************\n");
	
	while(l_Current != NULL)
	{
		g_CurrentFile = l_Current->getItem();
	
		printf("translation of file \"%s\"\n", g_CurrentFile->getName());
		
		/* Opening of log file */
		FILE *l_FpLog = fileOpen( myStrcat(5, g_Config->getOutputDir(), "/", g_CurrentFile->getName(), ".", g_Config->getLogExtension()), "w");
		
		g_Config->write(l_FpLog, g_CurrentFile->getName());
		
		/* Translation */
		tree *l_TranslatedTree = translation(l_FpLog, g_CurrentFile->getTree());
		
		fclose(l_FpLog);
		
		/* type determination of output file */
		char l_BoolHeader = g_CurrentFile->getBoolHeader();
		const char *l_Extension = NULL;

		if(l_BoolHeader == 0)
		{
			l_Extension = g_Config->getBodyExtension();
		}
		else
		{
			l_Extension = g_Config->getHeaderExtension();
		}
		
		/* Opening of output file */
		FILE *l_FpOut = outputFileOpen(g_Config->getOutputDir(), g_CurrentFile->getName(), l_Extension);
		
		/* Generation of output file */
		generateCode(l_FpOut, l_BoolHeader, g_CurrentFile->getName(), myStrcat(3, deleteExtension(g_CurrentFile->getName()), "_", l_Extension), l_TranslatedTree);
		
		fclose(l_FpOut);
		
		l_Current = l_Current->getNext();
	}
	printf("\n");
	
	printf("-----------------------------------\n- TRANSLATION SUCCESSFULLY PASSED -\n-----------------------------------\n");
}
