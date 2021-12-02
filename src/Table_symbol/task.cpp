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
 * Description: instantiation of task class
 *
 * $Log: task.cpp,v $
 * Revision 1.1  2005/03/13 16:50:27  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 *
 * Revision 1.1.1.1  2005/03/01 22:20:48  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/

#include "task.h"

void displayTaskType(t_TaskType p_TaskType)
{
	
	#ifdef TRACE
	printfTraceUp("displayTaskType",__FILE__,__LINE__);
	#endif
	
	switch(p_TaskType)
	{
		case Task_Normal: printf("Task_Normal");break;
		case Task_Type: printf("Task_Type");break;
		case Task_Undefined: printf("Task_Undefined");break;
		default : printf("ERROR : %s %i : task type %i is not manage\n",__FILE__,__LINE__,p_TaskType);
		break;
	}
	
	#ifdef TRACE
	printfTraceDown("displayTaskType",__FILE__,__LINE__);
	#endif
	
}

t_TaskType task::getTaskType(void)
{
	this->checkIntegrity(__FILE__,__LINE__);
	return m_TaskType;
}
	
	
void task::checkIntegrity(char *p_FileName,int p_LineNumber)
{
	int error=0;
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	
	if(m_TaskType==Task_Undefined)
	{
		printf("ERROR : %s %i : \"m_TaskType\" member has value \"Task_Udefined\"\n",p_FileName,p_LineNumber);
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

task::task(void):main_unit()
{
	#ifdef TRACE
	printfTraceUp("task",__FILE__,__LINE__);
	#endif
	m_TaskType=Task_Undefined;
	#ifdef TRACE
	printfTraceDown("task",__FILE__,__LINE__);
	#endif
	
}

task::task(t_TaskType p_TaskType,char *p_Name,main_unit *p_CurrentMainUnit):main_unit(Main_Unit_Task,p_Name,p_CurrentMainUnit)
{
	#ifdef TRACE
	printfTraceUp("task",__FILE__,__LINE__);
	#endif
	m_TaskType=p_TaskType;
	#ifdef TRACE
	printfTraceDown("task",__FILE__,__LINE__);
	#endif
	
}
