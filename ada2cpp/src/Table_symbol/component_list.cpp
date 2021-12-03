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
 * Description: instantiation of component_list class
 *
 * $Log: component_list.cpp,v $
 * Revision 1.1  2005/03/13 14:36:02  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 *
 * Revision 1.1.1.1  2005/03/01 22:20:35  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "component_list.h"

char component_list::getBoolComponentsNull(void)
{
	return m_BoolComponentsNull;
}

list<component*>* component_list::getComponents(void)
{
	return m_Components;
}

char component_list::getBoolVariantNull(void)
{
	return m_BoolVariantNull;
}

const char* component_list::getDiscrimName(void)
{
	return m_DiscrimName;
}

list<variant*>* component_list::getVariantPart(void)
{
	return m_VariantPart;
}

void component_list::checkIntegrity(const char *p_FileName, int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	int error=0;
	
	if(m_BoolComponentsNull==0 && m_Components!=NULL)
	{
		printf("INTERNAL ERROR : %s %i : \"m_BoolComponentsNull\" equal 0 and \"m_Components\" is not NULL\n",__FILE__,__LINE__);
		error=1;
	}
	
	if(m_BoolComponentsNull!=0 && m_Components==NULL)
	{
		printf("INTERNAL ERROR : %s %i : \"m_BoolComponentsNull\" is not NULL and \"m_Components\" is NULL\n",__FILE__,__LINE__);
		error=1;
	}
	
	if(m_BoolVariantNull==0)
	{
		if(m_VariantPart!=NULL)
		{
			printf("INTERNAL ERROR : %s %i : \"m_BoolVariantNull\" equal 0 and \"m_VariantPart\" is not NULL\n",__FILE__,__LINE__);
			error=1;
		}
		if(m_DiscrimName!=NULL)
		{
			printf("INTERNAL ERROR : %s %i : \"m_BoolVariantNull\" equal 0 and \"m_DiscrimName\" is not NULL\n",__FILE__,__LINE__);
			error=1;
		}
	}
	
	if(m_BoolVariantNull!=0)
	{
		if(m_VariantPart==NULL)
		{
			printf("INTERNAL ERROR : %s %i : \"m_BoolVariantNull\" is not NULL and \"m_VariantPart\" is NULL\n",__FILE__,__LINE__);
			error=1;
		}
		if(m_DiscrimName==NULL)
		{
			printf("INTERNAL ERROR : %s %i : \"m_BoolVariantNull\" is not NULL and \"m_DiscrimName\" is NULL\n",__FILE__,__LINE__);
			error=1;
		}
	}
	
	if(error!=0)
	{
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
}

component_list::component_list(void)
{
	#ifdef TRACE
	printfTraceUp("component_list",__FILE__,__LINE__);
	#endif
	m_BoolComponentsNull=1;
	m_Components=0;
	m_BoolVariantNull=1;
	m_DiscrimName=NULL;
	m_VariantPart=0;
	#ifdef TRACE
	printfTraceDown("component_list",__FILE__,__LINE__);
	#endif
}

component_list::component_list(list<component*> *p_Components)
{
	#ifdef TRACE
	printfTraceUp("component_list",__FILE__,__LINE__);
	#endif
	if(p_Components!=NULL)
	{
		m_Components=p_Components;
		m_BoolComponentsNull=0;
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Components");
		my_exit(-1);
	}
	
	m_DiscrimName=NULL;
	m_VariantPart=NULL;
	m_BoolVariantNull=1;
	
	#ifdef TRACE
	printfTraceDown("component_list",__FILE__,__LINE__);
	#endif
}

component_list::component_list(const char *p_DiscrimName,list<variant*> *p_VariantPart)
{
	#ifdef TRACE
	printfTraceUp("component_list",__FILE__,__LINE__);
	#endif
	m_Components=NULL;
	m_BoolComponentsNull=1;
	
	if(p_DiscrimName!=NULL && p_VariantPart!=NULL)
	{
		m_DiscrimName=p_DiscrimName;
		m_VariantPart=p_VariantPart;
		m_BoolVariantNull=0;
	}
	else
	{
		int error=0;
		
		if(p_DiscrimName==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_DiscrimName");
			error=1;
		}
		
		if(p_VariantPart==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_VariantPart");
			error=1;
		}
		
		if(error!=0)
		{
			my_exit(-1);
		}
	}
	#ifdef TRACE
	printfTraceDown("component_list",__FILE__,__LINE__);
	#endif
}

component_list::component_list(list<component*> *p_Components,const char *p_DiscrimName,list<variant*> *p_VariantPart)
{
	#ifdef TRACE
	printfTraceUp("component_list",__FILE__,__LINE__);
	#endif
	if(p_Components!=NULL && p_DiscrimName!=NULL && p_VariantPart!=NULL)
	{
		m_Components=p_Components;
		m_BoolComponentsNull=0;
		m_DiscrimName=p_DiscrimName;
		m_VariantPart=p_VariantPart;
		m_BoolVariantNull=0;
	}
	else
	{
		int error=0;
		
		if(p_Components==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_Components");
			error=1;
		}
		
		if(p_DiscrimName==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_DiscrimName");
			error=1;
		}
		
		if(p_VariantPart==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_VariantPart");
			error=1;
		}
		
		if(error!=0)
		{
			my_exit(-1);
		}
	}
	#ifdef TRACE
	printfTraceDown("component_list",__FILE__,__LINE__);
	#endif
}

component_list* new_component_list(tree *p_Tree)
{
	#ifdef TRACE
	printfTraceUp("new_component_list",__FILE__,__LINE__);
	#endif
	component_list *result=NULL;
	if(p_Tree!=NULL)
	{
		if(p_Tree->getNodeType()==Node_Ada_Component_List)
		{
			switch(p_Tree->getNbSon())
			{
				case 1:
				result=new component_list();
				break;
				case 2:
				{
					if(p_Tree->getSon(0)->getNodeType()!=Node_Ada_Variant_Part)
					{
						list<component*> *p_Components=NULL;
						p_Components=getListComponent(p_Tree->getSon(0),p_Components);
						if(p_Tree->getSon(1)->getNodeType()!=Node_Ada_Variant_Part_Optional)
						{
							result=new component_list(p_Components);
						}
						else
						{
							tree *p_VariantPart=p_Tree->getSon(1)->getSon(1);
							const char *p_DiscrimName=p_VariantPart->getSon(0)->getString();
							list<variant*> *p_Variants=NULL;
							p_Variants=getListVariant(p_VariantPart->getSon(2),p_Variants);
							result=new component_list(p_Components,p_DiscrimName,p_Variants);
						}
					}
					else
					{
						tree *p_VariantPart=p_Tree->getSon(0);
						const char *p_DiscrimName=p_VariantPart->getSon(0)->getString();
						list<variant*> *p_Variants=NULL;
						p_Variants=getListVariant(p_VariantPart->getSon(2),p_Variants);
						result=new component_list(p_DiscrimName,p_Variants);	
					}
				}
				break;
				default:
				errorNbSon(__FILE__,__LINE__,p_Tree);
				my_exit(-1);
			}
		}
		else
		{
			errorNotAllowed(__FILE__,__LINE__,p_Tree,"variant");
			my_exit(-1);
		}
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("new_component_list",__FILE__,__LINE__);
	#endif
	return result;
}
