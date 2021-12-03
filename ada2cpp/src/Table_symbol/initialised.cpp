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
 * Description: instantiation of initialised class
 *
 * $Log: initialised.cpp,v $
 * Revision 1.2  2005/03/19 14:43:47  quicky2000
 * m_BoolInitTree member is replaced by m_BoolInitValue
 * m_InitTree member is replaced by m_InitValue member whose class is "value" class
 *
 * Revision 1.1  2005/03/13 16:36:27  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 *
 * Revision 1.1.1.1  2005/03/01 22:20:38  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "initialised.h"

#include "../Tools/value.h"

char initialised::getBoolInitValue(void)
{
	this->checkIntegrity(__FILE__,__LINE__);
	return m_BoolInitValue;
}
	
value* initialised::getInitValue(void)
{
	this->checkIntegrity(__FILE__,__LINE__);
	if(m_BoolInitValue==0)
	{
		printf("INTERNAL ERROR :  %s %i : no init value\n",__FILE__,__LINE__);
		my_exit(-1);
	}
	return m_InitValue;
}

void initialised::checkIntegrity(const char *p_FileName, int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	
	int error=0;

	if(m_BoolInitValue==0 && m_InitValue!=NULL)
	{
		printf("INTERNAL ERROR : %s %i : \"m_InitTree\" member is not NULL and \"m_InitValue\" value is \"0\"\n",p_FileName,p_LineNumber);
		error=1;
	}
	if(m_BoolInitValue==1 && m_InitValue==NULL)
	{
		printf("INTERNAL ERROR : %s %i : \"m_InitTree\" member is NULL and \"m_InitValue\" value is \"1\"\n",p_FileName,p_LineNumber);
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

initialised::initialised(void)
{
	#ifdef TRACE
	printfTraceUp("initialised",__FILE__,__LINE__);
	#endif
	
	m_BoolInitValue=0;
	m_InitValue=NULL;
	
	#ifdef TRACE
	printfTraceDown("initialised",__FILE__,__LINE__);
	#endif
}

initialised::initialised(tree *p_InitTree)
{
	#ifdef TRACE
	printfTraceUp("initialised",__FILE__,__LINE__);
	#endif
	
	if(p_InitTree!=NULL)
	{
		m_BoolInitValue=1;
		m_InitValue=new value(p_InitTree);
	
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_InitTree");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("initialised",__FILE__,__LINE__);
	#endif
}
