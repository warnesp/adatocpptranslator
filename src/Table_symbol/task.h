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
 * Description: declaration of task class
 *
 * $Log: task.h,v $
 * Revision 1.2  2005/03/19 09:54:37  quicky2000
 * Update to make protected members become private
 *
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

#ifndef TASK_H
#define TASK_H

#include <stdio.h>

#include "../Tools/trace.h"

#include "main_unit.h"

typedef enum
{
	Task_Normal,
	Task_Type,
	Task_Undefined
}t_TaskType;

void displayTaskType(t_TaskType p_TaskType);

class task:public main_unit
{
	private:
	t_TaskType m_TaskType;
	
	public:
	t_TaskType getTaskType(void);
	
	void checkIntegrity(char *p_FileName,int p_Linenumber);

	task(void);
	task(t_TaskType p_TaskType,char *p_Name,main_unit *p_CurrentMainUnit);
};

#endif
