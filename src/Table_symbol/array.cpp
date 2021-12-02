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
 * Description: instantiation of array class
 *
 * $Log: array.cpp,v $
 * Revision 1.3  2005/03/27 00:05:09  quicky2000
 * Update to reflect the nmae change of the method to get the array type
 *
 * Revision 1.2  2005/03/17 22:25:17  quicky2000
 * Update to add cvs log flag
 *
 *
 *****************************************************************************/
#include "array.h"

void displayArrayId(t_ArrayId p_ArrayId)
{
	switch(p_ArrayId)
	{
		case Array_Constrained:printf("Array_Constrained");break;
		case Array_Unconstrained:printf("Array_Unconstrained");break;
		case Array_Undefined:printf("Array_Undefined");break;
		default:
		printf("INTERNAL ERROR : %s %i : array id %i is not manage\n",__FILE__,__LINE__,p_ArrayId);
		break;
	}
}

void array::checkIntegrity(const char *p_FileName, int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	int error=0;
	
	if(m_ArrayId==Array_Undefined)
	{
		printf("INTERNAL ERROR : %s %i :member \"m_ArrayId\" value is \"",p_FileName,p_LineNumber);
		displayArrayId(m_ArrayId);
		printf("\"\n");
		error=1;
	}
	
	if(m_NbDim<=0)
	{
		printf("INTERNAL ERROR : %s %i :member \"m_NbDim\" value is %i <= 0\n",p_FileName,p_LineNumber,m_NbDim);
		error=1;
	}
	
	if(m_Dims==NULL)
	{
		errorIsNull(p_FileName,p_LineNumber,"m_Dims");
		error=1;
	}
	
	subtyped::checkIntegrity(p_FileName,p_LineNumber);
	
	if(error!=0)
	{
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
}

t_ArrayId array::getArrayId(void)
{
	return m_ArrayId;
}

list<tree*>* array::getDims(void)
{
	return m_Dims;
}

int array::getNbDim(void)
{
	return m_NbDim;
}	
	
array::array(void):subtyped()
{
	#ifdef TRACE
	printfTraceUp("array",__FILE__,__LINE__);
	#endif
	m_ArrayId=Array_Undefined;
	m_NbDim=0;
	m_Dims=NULL;
	#ifdef TRACE
	printfTraceDown("array",__FILE__,__LINE__);
	#endif
}

array::array(t_ArrayId p_ArrayId):subtyped()
{
	#ifdef TRACE
	printfTraceUp("array",__FILE__,__LINE__);
	#endif
	m_ArrayId=p_ArrayId;
	m_NbDim=0;
	m_Dims=NULL;
	#ifdef TRACE
	printfTraceDown("array",__FILE__,__LINE__);
	#endif
}

array::array(array *p_Array):subtyped(p_Array->getTypeTree(),p_Array->getBoolConstraint(),p_Array->getConstraint())
{
	#ifdef TRACE
	printfTraceUp("array",__FILE__,__LINE__);
	#endif
	m_ArrayId=p_Array->getArrayId();
	m_NbDim=p_Array->getNbDim();
	m_Dims=p_Array->getDims();
	#ifdef TRACE
	printfTraceDown("array",__FILE__,__LINE__);
	#endif
}

array::array(t_ArrayId p_ArrayId,list<tree*> *p_Dims, int p_NbDim,subtyped *p_Subtyped):subtyped(p_Subtyped)
{
	#ifdef TRACE
	printfTraceUp("array",__FILE__,__LINE__);
	#endif
	m_ArrayId=p_ArrayId;
	m_Dims=p_Dims;
	m_NbDim=p_NbDim;
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("array",__FILE__,__LINE__);
	#endif
}

array* new_array(tree *p_Tree)
{
	#ifdef TRACE
	printfTraceUp("new_array",__FILE__,__LINE__);
	#endif
	array* result=NULL;
	
	if(p_Tree!=NULL)
	{
		t_ArrayId p_ArrayId;
		switch(p_Tree->getNodeType())
		{
			case Node_Ada_Constraint_Array_Type:p_ArrayId=Array_Constrained;break;
			case Node_Ada_Unconstraint_Array_Type:p_ArrayId=Array_Unconstrained;break;
			default:
			errorNotAllowed(__FILE__,__LINE__,p_Tree,"array_type");
			my_exit(-1);
		}
		list<tree*> *p_Dims=NULL;
		p_Dims=getListTree(p_Tree->getSon(0),p_Dims);
		int p_NbDim=p_Dims->getNbItem();
		subtyped *p_Subtyped=new_subtyped(p_Tree->getSon(1)->getSon(1));
		result=new array(p_ArrayId,p_Dims,p_NbDim,p_Subtyped);
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	
	#ifdef TRACE
	printfTraceDown("new_array",__FILE__,__LINE__);
	#endif
	return result;
}
