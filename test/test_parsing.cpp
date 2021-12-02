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
 * Description: test of lexical and syntaxic analysis
 *
 * $Log: test_parsing.cpp,v $
 * Revision 1.1.1.1  2005/03/01 22:20:53  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "test_parsing.h"

int main(int argc, char** argv)
{
	if(argc!=2)
	{
		printf("ERROR : %s %i : this program must have one argument\n",__FILE__,__LINE__);
		exit(-1);
	}
	
	char *name=argv[1];
	FILE * fpIn=fileOpen(name,"rt");
	selectInput(fpIn);
	
	printf("parse of file %s\n",name);
			
	//Call of bison function which analyse the file
	yyparse();
	
	fclose(fpIn);
	
	if(g_BoolSyntaxError!=0)
	{
		exit(-1);
	}
	/******************************
	 *  Redistribution of comments
	 ******************************/
	myYyval->redistributeComments();
	
	/********************
	 *  Display of tree
	 ********************/
	myYyval->displayTree();
	
}
