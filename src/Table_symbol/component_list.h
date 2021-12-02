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
 * Description: declaration of component_list class
 *
 * $Log: component_list.h,v $
 * Revision 1.2  2005/03/18 19:37:30  quicky2000
 * Update to make protected members become private
 *
 * Revision 1.1  2005/03/08 00:53:11  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ update modify include paths due to the new source organization
 *
 * Revision 1.1.1.1  2005/03/01 22:20:35  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef COMPONENT_LIST_H
#define COMPONENT_LIST_H

#include "../Tools/error.h"
#include "../Tools/trace.h"

#include "component.h"
#include "../Tools/list.h"

class variant;

class component_list
{
	private:
	char m_BoolComponentsNull;
	list<component*> *m_Components;
	char m_BoolVariantNull;
	const char *m_DiscrimName;
	list<variant*> *m_VariantPart;
	
	public:
	char getBoolComponentsNull(void);
	list<component*>* getComponents(void);
	char getBoolVariantNull(void);
	const char* getDiscrimName(void);
	list<variant*>* getVariantPart(void);
	
	void checkIntegrity(const char *p_FileName, int p_LineNumber);
	
	component_list(void);
	component_list(list<component*> *p_Components);
	component_list(const char *p_DiscrimName,list<variant*> *p_VariantPart);
	component_list(list<component*> *p_Components,const char *p_DiscrimName,list<variant*> *p_VariantPart);
	
};

component_list* new_component_list(tree *p_Tree);
#endif
