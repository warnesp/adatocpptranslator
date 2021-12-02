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
 * Description: instantiation of discrimined class
 *
 * $Log: discrimined.cpp,v $
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
#include "discrimined.h"

char discrimined::getBoolDiscrim(void)
{
	return m_BoolDiscrim;
}

char discrimined::getBoolGeneric(void)
{
	return m_BoolGeneric;
}

	
list<discrim_spec*>* discrimined::getDiscrimSpecs(void)
{
	this->checkIntegrity(__FILE__,__LINE__);
	return m_DiscrimSpecs;
}

void discrimined::checkIntegrity(const char *p_FileName,int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	int error=0;

	if(m_BoolGeneric!=0 && m_BoolDiscrim!=0)
	{
		printf("INTERNAL ERROR : %s %i : \"m_BoolGeneric\" member value is not \"0\" and \"m_BoolDiscrim\" member value is not \"0\"\n",p_FileName,p_LineNumber);
		error=1;
	}
	
	if(m_BoolDiscrim==0 && m_DiscrimSpecs!=NULL)
	{
		printf("INTERNAL ERROR : %s %i : \"m_BoolDiscrim\" member value is \"0\" and \"m_DiscrimSpecs\" is not NULL\n",p_FileName,p_LineNumber);
		error=1;
	}

	if(m_BoolDiscrim!=0 && m_DiscrimSpecs==NULL)
	{
		printf("INTERNAL ERROR : %s %i : \"m_BoolDiscrim\" member value is not \"0\" and \"m_DiscrimSpecs\" is NULL\n",p_FileName,p_LineNumber);
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

discrimined::discrimined(void)
{
	#ifdef TRACE
	printfTraceUp("discrimined",__FILE__,__LINE__);
	#endif
	m_BoolDiscrim=0;
	m_BoolGeneric=0;
	m_DiscrimSpecs=NULL;
	#ifdef TRACE
	printfTraceDown("discrimined",__FILE__,__LINE__);
	#endif
}

discrimined::discrimined(char p_BoolGeneric,list<discrim_spec*> *p_DiscrimSpecs=NULL)
{
	#ifdef TRACE
	printfTraceUp("discrimined",__FILE__,__LINE__);
	#endif
	m_BoolGeneric=p_BoolGeneric;
	
	if(p_DiscrimSpecs==NULL)
	{
		m_BoolDiscrim=0;
	}
	else
	{
		m_BoolDiscrim=1;
	}
	m_DiscrimSpecs=p_DiscrimSpecs;

	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("discrimined",__FILE__,__LINE__);
	#endif
}
