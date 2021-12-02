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
 * Description: instantiation of prot class
 *
 * $Log: prot.cpp,v $
 * Revision 1.1  2005/03/13 16:44:25  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 *
 * Revision 1.1.1.1  2005/03/01 22:20:42  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "prot.h"

void displayProtType(t_ProtType p_ProtType)
{
	switch(p_ProtType)
	{
		case Prot_Normal:printf("Prot_Normal");break;
		case Prot_Type:printf("Prot_Type");break;
		case Prot_Undefined:printf("Prot_Undefined");break;
		break;
		default : printf("ERROR : %s %i : prot type %i is not manage\n",__FILE__,__LINE__,p_ProtType);
		my_exit(-1);
		break;
	}
}

t_ProtType prot::getProtType(void)
{
	return  m_ProtType;
}

void prot::checkIntegrity(char *p_FileName, int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	int error=0;

	if(m_ProtType==Prot_Undefined)
	{
		printf("ERROR : %s %i : \"m_ProtType\" member value is \"Prot_Undefined\"\n",p_FileName,p_LineNumber);
		error=1;
	}

	if (error!=0)
	{
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
	
}

prot::prot(void):main_unit()
{
	#ifdef TRACE
	printfTraceUp("prot",__FILE__,__LINE__);
	#endif
	m_ProtType=Prot_Undefined;
	#ifdef TRACE
	printfTraceDown("prot",__FILE__,__LINE__);
	#endif
	
}

prot::prot(t_ProtType p_ProtType,char *p_Name,main_unit *p_CurrentMainUnit):main_unit(Main_Unit_Prot,p_Name,p_CurrentMainUnit)
{
	#ifdef TRACE
	printfTraceUp("prot",__FILE__,__LINE__);
	#endif
	m_ProtType=p_ProtType;
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("prot",__FILE__,__LINE__);
	#endif
}

