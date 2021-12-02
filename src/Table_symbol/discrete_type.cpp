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
 * Description: instantiation of discrete_type class
 *
 * $Log: discrete_type.cpp,v $
 * Revision 1.1  2005/03/13 14:36:02  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 *
 * Revision 1.1.1.1  2005/03/01 22:20:36  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "discrete_type.h"

void displayDiscreteTypeId(t_DiscreteTypeId p_DiscreteTypeId)
{
	switch(p_DiscreteTypeId)
	{
		case Discrete_Type_Enumerated:printf("Discrete_Type_Enumerated");break;
		case Discrete_Type_Integer:printf("Discrete_Type_Integer");break;
		case Discrete_Type_Undefined:printf("Discrete_Type_Undefined");break;
		default:
		printf("INTERNAL ERROR : %s %i : discrete type id %i is not manage\n",__FILE__,__LINE__,p_DiscreteTypeId);
		my_exit(-1);
		break;
	}
}

void discrete_type::checkIntegrity(char *p_FileName, int p_LineNumber)
{	
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	int error=0;
	
	if(m_DiscreteTypeId==Discrete_Type_Undefined)
	{
		printf("INTERNAL ERROR : %s %i : member \"m_DiscreteTypeId\" is \"",p_FileName,p_LineNumber);
		displayDiscreteTypeId(m_DiscreteTypeId);
		printf("\"\n");
		error=1;
	}
	
	scalar_type::checkIntegrity(p_FileName,p_LineNumber);
	if(error!=0)
	{
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
}

t_DiscreteTypeId discrete_type::getDiscreteTypeId(void)
{
	return m_DiscreteTypeId;
}
	
discrete_type::discrete_type(void):scalar_type(Scalar_Type_Discrete)
{
	#ifdef TRACE
	printfTraceUp("discrete_type",__FILE__,__LINE__);
	#endif
	m_DiscreteTypeId=Discrete_Type_Undefined;
	#ifdef TRACE
	printfTraceDown("discrete_type",__FILE__,__LINE__);
	#endif
	
}

discrete_type::discrete_type(t_DiscreteTypeId p_DiscreteTypeId):scalar_type(Scalar_Type_Discrete)
{
	#ifdef TRACE
	printfTraceUp("discrete_type",__FILE__,__LINE__);
	#endif
	m_DiscreteTypeId=p_DiscreteTypeId;
	#ifdef TRACE
	printfTraceDown("discrete_type",__FILE__,__LINE__);
	#endif
}


discrete_type::discrete_type(t_DiscreteTypeId p_DiscreteTypeId,char *p_Name,main_unit *p_MainUnit):scalar_type(Scalar_Type_Discrete,p_Name,p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("discrete_type",__FILE__,__LINE__);
	#endif
	m_DiscreteTypeId=p_DiscreteTypeId;
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("discrete_type",__FILE__,__LINE__);
	#endif
	
}
