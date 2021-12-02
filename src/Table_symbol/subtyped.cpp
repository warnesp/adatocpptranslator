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
 * Description: instantiation of subtyped class
 *
 * $Log: subtyped.cpp,v $
 * Revision 1.2  2005/03/27 01:04:11  quicky2000
 * Update due to the replacement of type representation by a tree instead of string
 *
 * Revision 1.1  2005/03/13 16:50:27  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 *
 * Revision 1.1.1.1  2005/03/01 22:20:44  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "subtyped.h"

char subtyped::getBoolConstraint(void)
{
	return m_BoolConstraint;
}

tree* subtyped::getConstraint(void)
{
	this->checkIntegrity(__FILE__,__LINE__);
	return m_Constraint;
}

void subtyped::checkIntegrity(char *p_FileName, int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	int error=0;
	
	if(m_Constraint==NULL && m_BoolConstraint!=0)
	{
		printf("ERROR : %s %i :member \"m_Constraint\" is NULL and \"m_BoolConstraint\" is not NULL\n",p_FileName,p_LineNumber);
		error=1;
	}
	
	if(m_Constraint!=NULL && m_BoolConstraint==0)
	{
		printf("ERROR : %s %i :member \"m_Constraint\" is not NULL and \"m_BoolConstraint\" is NULL\n",p_FileName,p_LineNumber);
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

subtyped::subtyped(void):typed()
{
	#ifdef TRACE
	printfTraceUp("subtyped",__FILE__,__LINE__);
	#endif
	m_BoolConstraint=0;
	m_Constraint=NULL;
	#ifdef TRACE
	printfTraceDown("subtyped",__FILE__,__LINE__);
	#endif
}

subtyped::subtyped(subtyped *p_Subtyped):typed(p_Subtyped->getTypeTree())
{
	#ifdef TRACE
	printfTraceUp("subtyped",__FILE__,__LINE__);
	#endif
	m_BoolConstraint=p_Subtyped->getBoolConstraint();
	m_Constraint=p_Subtyped->getConstraint();
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("subtyped",__FILE__,__LINE__);
	#endif
}
subtyped::subtyped(tree *p_NameTree,char p_BoolConstraint, tree *p_Constraint):typed(p_NameTree)
{
	#ifdef TRACE
	printfTraceUp("subtyped",__FILE__,__LINE__);
	#endif
	m_BoolConstraint=p_BoolConstraint;
	m_Constraint=p_Constraint;
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("subtyped",__FILE__,__LINE__);
	#endif
}

subtyped* new_subtyped(tree *p_Tree)
{
	#ifdef TRACE
	printfTraceUp("new_subtyped",__FILE__,__LINE__);
	#endif
	subtyped *result=NULL;
	
	if(p_Tree!=NULL)
	{
		if(p_Tree->getNbSon()==2)
		{
			switch(p_Tree->getSon(1)->getNodeType())
			{
				case Node_Ada_C_Empty:
				result=new subtyped(p_Tree->getSon(0),0,NULL);
				break;
				default:
				result=new subtyped(p_Tree->getSon(0),1,p_Tree->getSon(1));
				break;
			}
			
		}
		else
		{
			result=new subtyped(p_Tree->getSon(0),0,NULL);
		}
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	
	#ifdef TRACE
	printfTraceDown("new_subtyped",__FILE__,__LINE__);
	#endif
	return result;
}
