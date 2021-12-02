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
 * Description: declaration of class list
 *
 * $Log: list.h,v $
 * Revision 1.3  2005/03/26 23:19:34  quicky2000
 * Update to replace a string parameter of functions getListDiscrimSpec and getListParameter by a tree parameter
 *
 * Revision 1.2  2005/03/17 18:29:32  quicky2000
 * Update to move include directives in body files
 *
 * Revision 1.1  2005/03/08 00:26:56  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ modify include files due to the new orgnaisation of source files
 *
 * Revision 1.1.1.1  2005/03/01 22:20:40  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef LIST_H
#define LIST_H

#include "../Tools/trace.h"

#include "tree_string_representation.h"

class component;
class constant_number;
class discrim_spec;
class file;
class function_spec;
class generic_package_inst;
class main_unit;
class named;
class package_body;
class package_rename;
class package_spec;
class parameter;
class procedure_spec;
class tree;
class type;
class variable;
class variable_array;
class variable_object;
class variant;

/* class list : list of items of class T
/***********************************************/
template <class T> class list
{
	private:
	//item in current list
	T m_Item;
	//reference on next item
	list *m_Next;
	
	public:
	
	 /*****************************************************************************
	 * Function name : list 
	 *
	 * Input : reference on object of class T
	 * Output : none
	 * Modified variable : none
	 * Description : constructor of liste
	 * it creates a list containing the item given in parameter
	 * member m_next is initalized whith NULL value
	 *****************************************************************************/
	 list(T);
	
	int getNbItem(void);
	
	/*****************************************************************************
	 * Function name : ajouter 
	 *
	 * Input : object of class T
	 * Output : none
	 * Modified variable : this
	 * Description : function which add the item contained in "item" parameter
	 * at the end of list if the item is not already in the list
	 *****************************************************************************/
	void add(T p_Item);
	void add(list<T> *p_List);
	
	/*****************************************************************************
	 * Function name : getItem 
	 *
	 * Input : none
	 * Output : an item of class T
	 * Modified variable : none
	 * Description : function which returns the first item of the list referenced
	 * by "this" pointer
	 *****************************************************************************/
	T getItem(void);
	
	/*****************************************************************************
	 * Function name : getNext 
	 *
	 * Input : none
	 * Output : reference on an object of class liste
	 * Modified variable : none
	 * Description : function which returns a reference on the rest of the list
	 *****************************************************************************/
	list* getNext(void);
	
	/*****************************************************************************
	* Function name : afficher 
	*
	* Input : none
	* Output : none
	* Modified variable : none
	* Description : function which display the list of item referenced by "this"
	* pointer
	*****************************************************************************/
	void display(FILE *p_Fp);
	
};

template<class T> list<T>* add(T p_Item,list<T>* p_List);
template<class T> list<T>* cat(list<T>* p_List1,list<T>* p_List2);

list<tree*>* getListChoice(tree *p_Tree,list<tree*> *p_Trees);

list<component*>* getListComponent(tree *p_Tree,list<component*>* p_Components);
list<component*>* getListComponent(tree *p_Tree,tree *p_ComponentSubtypeDefTree, tree *p_InitTree,list<component*>* p_Components);

list<discrim_spec*>* getListDiscrimSpec(tree *p_Tree,list<discrim_spec*> *p_DiscrimSpecs);
list<discrim_spec*>* getListDiscrimSpec(tree *p_Tree,list<discrim_spec*> *p_DiscrimSpecs,tree *p_AccessTree,tree *p_TypeTree,tree *p_InitTree);

list<named*>* getListEnumerationLitteral(tree *p_Tree,list<named*> *p_EnumerationLitterals);

list<parameter*>* getListParameter(tree *p_Tree,list<parameter*> *p_Parameters,main_unit *p_MainUnit);
list<parameter*>* getListParameter(tree *p_Tree,list<parameter*> *p_Parameters,tree *p_ParameterModeTree,tree *p_TypeTree,tree *p_InitTree,main_unit *p_MainUnit);

list<tree*>* getListTree(tree *p_Tree,list<tree*> *p_Trees);

list<variant*>* getListVariant(tree *p_Tree,list<variant*>* p_Variants);
#endif
