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
 * Description: instantiation of file class
 *
 * $Log: file.cpp,v $
 * Revision 1.2  2005/03/18 18:33:13  quicky2000
 * Update for code maintenance
 *
 * Revision 1.1  2005/03/13 16:36:27  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 *
 * Revision 1.3  2005/03/02 23:52:28  quicky2000
 * Update to restablish cvs log history
 *
 * Revision 1.2  2005/03/01 23:20:37  quicky2000
 * Update to initalize the variable member m_BoolHeader of class file
 *
 * Revision 1.1  2005/03/01 22:20:37  quicky2000
 * Initial revision
 *
 *
 *****************************************************************************/
#include "file.h"

void file::display(void)
{
	this->checkIntegrity(__FILE__,__LINE__);
	printf("file : %s\n",this->getName());
}

void file::checkIntegrity(const char *p_FileName,int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	
	int error=0;
	main_unit::checkIntegrity(p_FileName,p_LineNumber);
	
	if(m_Path==NULL)
	{
		errorIsNull(p_FileName,p_LineNumber,"m_Path");
		error=1;
	}
	if(m_Tree==NULL)
	{
		errorIsNull(p_FileName,p_LineNumber,"m_Tree");
		error=1;
	}
	
	if(error!=0)
	{
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
	
}

char* file::getPath(void)
{
	return m_Path;
}

tree* file::getTree(void)
{
	return m_Tree;
}

char file::getBoolHeader(void)
{
	return m_BoolHeader;
}

void file::setTree(tree *p_Tree)
{
	m_Tree=p_Tree;
	this->checkIntegrity(__FILE__,__LINE__);
}

void file::setBoolHeader(char p_BoolHeader)
{
	m_BoolHeader=p_BoolHeader;
}

file::file():main_unit()
{
	#ifdef TRACE
	printfTraceUp("file",__FILE__,__LINE__);
	#endif
	m_Path=NULL;
	m_Tree=NULL;
	m_BoolHeader=0;
	#ifdef TRACE
	printfTraceDown("file",__FILE__,__LINE__);
	#endif
	
}

file::file(const char *p_Name,char *p_Path):main_unit(Main_Unit_File,p_Name,NULL)
{
	#ifdef TRACE
	printfTraceUp("file",__FILE__,__LINE__);
	#endif
	int error=0;
	if(p_Name==NULL)
	{
		errorIsNull(__FILE__,__LINE__,"p_Name");
		error=1;
	}
	if(p_Path==NULL)
	{
		errorIsNull(__FILE__,__LINE__,"p_Path");
		error=1;
	}
	if(error!=0)
	{
		my_exit(-1);
	}
	m_Path=p_Path;
	m_Tree=NULL;
	m_BoolHeader=0;
	#ifdef TRACE
	printfTraceDown("file",__FILE__,__LINE__);
	#endif
	
}

file* new_file(char *p_Name)
{
	#ifdef TRACE
	printfTraceUp("new_file",__FILE__,__LINE__);
	#endif
	file *result=NULL;
	
	if(p_Name!=NULL)
	{
		char *fileName=NULL;
		char *path=NULL;
		
		char *name=(char *)malloc(sizeof(char)*(strlen(p_Name)+1));
		if(name==NULL)
		{
			printf("INTERNAL ERROR : %s %i : memory allocation has failed\n",__FILE__,__LINE__);
			my_exit(-1);
		}
		char *ref=strrchr(p_Name,'\\');
		if(strrchr(p_Name,'/')>ref)
		{
			ref=strrchr(p_Name,'/');
		}
		
		if(ref==NULL)
		{
			fileName=(char *)malloc(sizeof(char)*(strlen(p_Name)+1));
			if(fileName==NULL)
			{
				printf("INTERNAL ERROR : %s %i : memory allocation has failed\n",__FILE__,__LINE__);
				my_exit(-1);
			}
			strcpy(fileName,p_Name);
			
			path=(char *)malloc(sizeof(char)*(strlen("./")+1));
			if(path==NULL)
			{
				printf("INTERNAL ERROR : %s %i : memory allocation has failed\n",__FILE__,__LINE__);
				my_exit(-1);
			}
			strcpy(path,"./");
		}
		else
		{
			fileName=(char *)malloc(sizeof(char)*(strlen(ref+sizeof(char))+1));
			if(fileName==NULL)
			{
				printf("INTERNAL ERROR : %s %i : memory allocation has failed\n",__FILE__,__LINE__);
				my_exit(-1);
			}
			strcpy(fileName,ref+sizeof(char));
			
			*(ref+sizeof(char))='\0';
			path=(char *)malloc(sizeof(char)*(strlen(p_Name)+1));
			if(path==NULL)
			{
				printf("INTERNAL ERROR : %s %i : memory allocation has failed\n",__FILE__,__LINE__);
				my_exit(-1);
			}
			strcpy(path,p_Name);
			
		}
		
		result=new file(fileName,path);
		
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Name");
		my_exit(-1);
	}
	
	#ifdef TRACE
	printfTraceDown("new_file",__FILE__,__LINE__);
	#endif
	return result;
}
