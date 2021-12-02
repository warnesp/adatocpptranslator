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
 * Description: instantiation of base_range class
 *
 * $Log: base_range.cpp,v $
 * Revision 1.2  2005/03/17 22:41:52  quicky2000
 * Update to move a call to checkIntegrity procedure
 *
 * Revision 1.1  2005/03/13 14:35:57  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 *
 * Revision 1.1.1.1  2005/03/01 22:20:32  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "base_range.h"

void base_range::checkIntegrity(char *p_FileName,int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	int error=0;
	
	if(m_LowerBound==NULL)
	{
		errorIsNull(p_FileName,p_LineNumber,"m_LowerBound");
		error=1;
	}
	
	if(m_UpperBound==NULL)
	{
		errorIsNull(p_FileName,p_LineNumber,"m_UpperBound");
		error=1;
	}
	if(error!=0)
	{
		my_exit(-1);
	}
	range::checkIntegrity(p_FileName,p_LineNumber);
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
}

tree* base_range::getLowerBound(void)
{
	this->checkIntegrity(__FILE__,__LINE__);
	return m_LowerBound;
}

tree* base_range::getUpperBound(void)
{
	this->checkIntegrity(__FILE__,__LINE__);
	return m_UpperBound;
}

base_range::base_range(void):range(Range_Base)
{
	#ifdef TRACE
	printfTraceUp("base_range",__FILE__,__LINE__);
	#endif
	m_LowerBound=NULL;
	m_UpperBound=NULL;
	#ifdef TRACE
	printfTraceDown("base_range",__FILE__,__LINE__);
	#endif
}

base_range::base_range(tree *p_LowerBound, tree *p_UpperBound):range(Range_Base)
{
	#ifdef TRACE
	printfTraceUp("base_range",__FILE__,__LINE__);
	#endif
	m_LowerBound=p_LowerBound;
	m_UpperBound=p_UpperBound;
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("base_range",__FILE__,__LINE__);
	#endif
}
