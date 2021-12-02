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
 * Description: declaration of list tools
 *
 * $Log: list_tools.cpp,v $
 * Revision 1.3  2005/03/19 13:34:26  quicky2000
 * Update to add list of constant_number class objects
 *
 * Revision 1.2  2005/03/17 18:31:25  quicky2000
 * Update to move include directives from header files
 *
 * Revision 1.1  2005/03/08 00:32:22  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ maitainance of code
 *
 * Revision 1.1.1.1  2005/03/01 22:20:40  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/

#include "list_tools.h"

#include "../Table_symbol/component.h"
#include "../Table_symbol/constant_number.h"
#include "../Table_symbol/file.h"
#include "../Table_symbol/function_spec.h"
#include "../Table_symbol/package.h"
#include "../Table_symbol/package_rename.h"
#include "../Table_symbol/parameter.h"
#include "../Table_symbol/type.h"
#include "../Table_symbol/variable_array.h"
#include "../Table_symbol/variable_object.h"

template list<component*>* getByName(const char *p_Name,list<component*>* p_List);
template list<constant_number*>* getByName(const char *p_Name,list<constant_number*>* p_List);
template list<function_spec*>* getByName(const char *p_Name,list<function_spec*>* p_List);
template list<package_rename*>* getByName(const char *p_Name,list<package_rename*>* p_List);
template list<package_spec*>* getByName(const char *p_Name,list<package_spec*>* p_List);
template list<parameter*>* getByName(const char *p_Name,list<parameter*>* p_List);
template list<type*>* getByName(const char *p_Name,list<type*>* p_List);
template list<variable_array*>* getByName(const char *p_Name,list<variable_array*>* p_List);
template list<variable_object*>* getByName(const char *p_Name,list<variable_object*>* p_List);

template<class T> list<T>* getByName(const char *p_Name,list<T>* p_List)
{
	#ifdef TRACE
	printfTraceUp("getByName",__FILE__,__LINE__);
	#endif
	
	list<T> *l_Result=NULL;
	
	if(p_Name!=NULL)
	{
		list<T> *l_Current=p_List;
		
		while(l_Current!=NULL)
		{
			if(!strcasecmp(p_Name,l_Current->getItem()->getName()))
			{
				l_Result=add(l_Current->getItem(),l_Result);
			}
			l_Current=l_Current->getNext();
		}
		
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Name");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("getByName",__FILE__,__LINE__);
	#endif
	return l_Result;
}

