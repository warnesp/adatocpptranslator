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
 * Description: declaration of task_type class
 *
 * $Log: task_type.h,v $
 * Revision 1.1  2005/03/09 20:15:27  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ update include paths due to the new sources organization
 *
 * Revision 1.1.1.1  2005/03/01 22:20:48  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef TASK_TYPE_H
#define TASK_TYPE_H

#include "../Tools/error.h"
#include "../Tools/trace.h"

#include "discrimined.h"
#include "../Tools/list.h"
#include "task.h"

class task_type:public task,public discrimined
{
	protected :
		
	public:
	void checkIntegrity(const char *p_FileName,int p_LineNumber);
	
	task_type(void);
	task_type(const char *p_Name,char p_BoolGeneric,list<discrim_spec*> *p_DiscrimSpecs,main_unit *p_CurrentMainUnit);
	
	
};

task_type *new_task_type(const char *p_Name,tree *p_DiscrimSpecsTree,main_unit *p_CurrentMainUnit);
#endif
