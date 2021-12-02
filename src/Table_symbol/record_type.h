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
 * Description: declaration of record_type class
 *
 * $Log: record_type.h,v $
 * Revision 1.2  2005/03/19 09:42:26  quicky2000
 * Update to make protected members become private
 *
 * Revision 1.1  2005/03/09 20:07:39  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ update include paths due to the new sources organization
 *
 * Revision 1.1.1.1  2005/03/01 22:20:43  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef RECORD_TYPE_H
#define RECORD_TYPE_H

#include "../Tools/error.h"
#include "../Tools/trace.h"

#include "composite_type.h"
#include "discrimined.h"
#include "component_list.h"

class record_type: public composite_type,public discrimined
{
	private:
	char m_BoolNullRecord;
	char m_BoolAbstract;
	char m_BoolTagged;
	char m_BoolLimited;
	component_list *m_ComponentList;
	
	public:
	char getBoolNullRecord(void);
	char getBoolAbstract(void);
	char getBoolLimited(void);
	char getBoolTagged(void);
	component_list* getComponentList(void);
	
	void checkIntegrity(char *p_FileName, int p_LineNumber);
	
	record_type(void);
	record_type(char *p_Name,char p_Abstract,char p_Limited,char p_Tagged,main_unit *p_MainUnit);
	record_type(char *p_Name,char p_Abstract,char p_Limited,char p_Tagged,char p_BoolGeneric,list<discrim_spec*> *p_DiscrimSpecs,main_unit *p_MainUnit);
	record_type(char *p_Name,char p_Abstract,char p_Limited,char p_Tagged,component_list *p_ComponentList,main_unit *p_MainUnit);
	record_type(char *p_Name,char p_Abstract,char p_Limited,char p_Tagged,char p_BoolGeneric,list<discrim_spec*> *p_DiscrimSpecs,component_list *p_ComponentList,main_unit *p_MainUnit);
	
};

record_type* new_record_type(char *p_Name,tree *p_DiscrimTree,tree *p_RecordTree,main_unit *p_MainUnit);
#endif
