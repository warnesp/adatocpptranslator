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
 * Description: instantiation of class list
 *
 * $Log: list.cpp,v $
 * Revision 1.4  2005/03/26 23:19:34  quicky2000
 * Update to replace a string parameter of functions getListDiscrimSpec and getListParameter by a tree parameter
 *
 * Revision 1.3  2005/03/19 10:42:48  quicky2000
 * Update for code maintenance
 *
 * Revision 1.2  2005/03/17 18:31:25  quicky2000
 * Update to move include directives from header files
 *
 * Revision 1.1  2005/03/08 00:28:45  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ maintainance of code
 *
 * Revision 1.1.1.1  2005/03/01 22:20:40  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "list.h"

#include "../Table_symbol/component.h"
#include "../Table_symbol/discrim_spec.h"
#include "../Table_symbol/parameter.h"

list<tree*>* getListChoice(tree *p_Tree,list<tree*> *p_Trees)
{
	#ifdef TRACE
	printfTraceUp("getListChoice",__FILE__,__LINE__);
	#endif
	if(p_Tree!=NULL)
	{
		switch(p_Tree->getNodeType())
		{
			case Node_Ada_List_Choice:
			if(p_Tree->getSon(0)->getNodeType()==Node_Ada_List_Choice)
			{
				p_Trees=getListChoice(p_Tree->getSon(0),p_Trees);
			}
			else
			{
				p_Trees=add(p_Tree->getSon(0),p_Trees);
			}
			p_Trees=add(p_Tree->getSon(1),p_Trees);
			break;
			default:
			p_Trees=add(p_Tree,p_Trees);
			break;
		}
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	
	#ifdef TRACE
	printfTraceDown("getListChoice",__FILE__,__LINE__);
	#endif
	
	return p_Trees;
}

list<component*>* getListComponent(tree *p_Tree,list<component*>* p_Components)
{
	#ifdef TRACE
	printfTraceUp("getListComponent",__FILE__,__LINE__);
	#endif
	if(p_Tree!=NULL)
	{
		switch(p_Tree->getNodeType())
		{
			case Node_Ada_List_Component_Decl:
			p_Components=getListComponent(p_Tree->getSon(0),p_Components);
			p_Components=getListComponent(p_Tree->getSon(2),p_Components);
			break;
			case Node_Ada_Component_Decl:
			p_Components=getListComponent(p_Tree->getSon(0),p_Tree->getSon(1),p_Tree->getSon(2),p_Components);
			break;
			default:
			errorNotAllowed(__FILE__,__LINE__,p_Tree,"comp_decl_s, comp_decl");
			my_exit(-1);
		}
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("getListComponent",__FILE__,__LINE__);
	#endif
	
	return p_Components;
}

list<component*>* getListComponent(tree *p_Tree,tree *p_ComponentSubtypeDefTree, tree *p_InitTree,list<component*>* p_Components)
{
	#ifdef TRACE
	printfTraceUp("getListComponent",__FILE__,__LINE__);
	#endif
	if(p_Tree!=NULL)
	{
		switch(p_Tree->getNodeType())
		{
			case Node_Ada_List_Identifier:
			p_Components=getListComponent(p_Tree->getSon(0),p_ComponentSubtypeDefTree,p_InitTree,p_Components);
			p_Components=getListComponent(p_Tree->getSon(1),p_ComponentSubtypeDefTree,p_InitTree,p_Components);
			break;
			case Node_Ada_C_Ident:
			p_Components=add(new_component(p_Tree->getString(),p_ComponentSubtypeDefTree,p_InitTree),p_Components);
			break;
			default:
			errorNotAllowed(__FILE__,__LINE__,p_Tree,"comp_decl_s, comp_decl");
			my_exit(-1);
		}
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("getListComponent",__FILE__,__LINE__);
	#endif
	
	return p_Components;
}

list<discrim_spec*>* getListDiscrimSpec(tree *p_Tree,list<discrim_spec*> *p_DiscrimSpecs)
{
	#ifdef TRACE
	printfTraceUp("getListDiscrimSpec",__FILE__,__LINE__);
	#endif
	if(p_Tree!=NULL)
	{
		switch(p_Tree->getNodeType())
		{
			case Node_Ada_List_Discrim_Spec:
			p_DiscrimSpecs=getListDiscrimSpec(p_Tree->getSon(0),p_DiscrimSpecs);
			p_DiscrimSpecs=getListDiscrimSpec(p_Tree->getSon(1),p_DiscrimSpecs);
			break;
			case Node_Ada_Discrim_Spec:
			p_DiscrimSpecs=getListDiscrimSpec(p_Tree->getSon(0),p_DiscrimSpecs,p_Tree->getSon(1),p_Tree->getSon(2),p_Tree->getSon(3));
			break;
			default:
			printf("ERROR : %s %i : node type ",__FILE__,__LINE__);
			displayNodeType(p_Tree->getNodeType());
			printf(" is not manage\n");
			break;
		}
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("getListDiscrimSpec",__FILE__,__LINE__);
	#endif
	
	return p_DiscrimSpecs;
}

list<discrim_spec*>* getListDiscrimSpec(tree *p_Tree,list<discrim_spec*> *p_DiscrimSpecs,tree *p_AccessTree,tree *p_TypeTree,tree *p_InitTree)
{
	#ifdef TRACE
	printfTraceUp("getListDiscrimSpec",__FILE__,__LINE__);
	#endif
	if(p_Tree!=NULL)
	{
		switch(p_Tree->getNodeType())
		{
			case Node_Ada_List_Identifier:
			p_DiscrimSpecs=getListDiscrimSpec(p_Tree->getSon(0),p_DiscrimSpecs,p_AccessTree,p_TypeTree,p_InitTree);
			p_DiscrimSpecs=getListDiscrimSpec(p_Tree->getSon(1),p_DiscrimSpecs,p_AccessTree,p_TypeTree,p_InitTree);
			break;
			case Node_Ada_C_Ident:
			p_DiscrimSpecs=add(new_discrim_spec(p_Tree->getString(),p_TypeTree,p_AccessTree,p_InitTree),p_DiscrimSpecs);
			break;
			default:
			printf("ERROR : %s %i : node type ",__FILE__,__LINE__);
			displayNodeType(p_Tree->getNodeType());
			printf(" is not manage\n");
			break;
		}
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	
	#ifdef TRACE
	printfTraceDown("getListDiscrimSpec",__FILE__,__LINE__);
	#endif
	
	return p_DiscrimSpecs;
}

list<named*>* getListEnumerationLitteral(tree *p_Tree,list<named*> *p_EnumerationLitterals)
{
	#ifdef TRACE
	printfTraceUp("getListEnumerationLitteral",__FILE__,__LINE__);
	#endif
	if(p_Tree!=NULL)
	{
		switch(p_Tree->getNodeType())
		{
			case Node_Ada_List_Enumeration_Identifier:
			p_EnumerationLitterals=getListEnumerationLitteral(p_Tree->getSon(0),p_EnumerationLitterals);
			p_EnumerationLitterals=getListEnumerationLitteral(p_Tree->getSon(1),p_EnumerationLitterals);
			break;
			case Node_Ada_C_Ident:
			case Node_Ada_C_Quote_Char:
			p_EnumerationLitterals=add(new named(p_Tree->getString()),p_EnumerationLitterals);
			break;
			default:
			printf("ERROR : %s %i : node type ",__FILE__,__LINE__);
			displayNodeType(p_Tree->getNodeType());
			printf(" is not manage\n");
			break;
			
		}
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("getListEnumerationLitteral",__FILE__,__LINE__);
	#endif
	
	return p_EnumerationLitterals;
}

list<parameter*>* getListParameter(tree *p_Tree,list<parameter*> *p_Parameters,main_unit *p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("getListParameter",__FILE__,__LINE__);
	#endif
	if(p_Tree!=NULL)
	{
		switch(p_Tree->getNodeType())
		{
			case Node_Ada_C_Formal_Part:
			p_Parameters=getListParameter(p_Tree->getSon(0),p_Parameters,p_MainUnit);
			break;
			case Node_Ada_List_Parameter:
			p_Parameters=getListParameter(p_Tree->getSon(0),p_Parameters,p_MainUnit);
			p_Parameters=getListParameter(p_Tree->getSon(1),p_Parameters,p_MainUnit);
			break;
			case Node_Ada_Parameter:
			p_Parameters=getListParameter(p_Tree->getSon(0),p_Parameters,p_Tree->getSon(1),p_Tree->getSon(2),p_Tree->getSon(3),p_MainUnit);
			break;
			default:
			printf("ERROR : %s %i : node type ",__FILE__,__LINE__);
			displayNodeType(p_Tree->getNodeType());
			printf(" is not manage\n");
			my_exit(-1);
			break;
		}
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("getListParameter",__FILE__,__LINE__);
	#endif
	
	return p_Parameters;
}

list<parameter*>* getListParameter(tree *p_Tree,list<parameter*> *p_Parameters,tree *p_ParameterModeTree,tree *p_TypeTree,tree *p_InitTree, main_unit *p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("getListParameter",__FILE__,__LINE__);
	#endif
	if(p_Tree!=NULL)
	{
		switch(p_Tree->getNodeType())
		{
			case Node_Ada_List_Identifier:
			p_Parameters=getListParameter(p_Tree->getSon(0),p_Parameters,p_ParameterModeTree,p_TypeTree,p_InitTree,p_MainUnit);
			p_Parameters=getListParameter(p_Tree->getSon(1),p_Parameters,p_ParameterModeTree,p_TypeTree,p_InitTree,p_MainUnit);
			break;
			case Node_Ada_C_Ident:
			p_Parameters=add(new_parameter(p_Tree->getString(),p_TypeTree,p_ParameterModeTree,p_InitTree,p_MainUnit),p_Parameters);
			break;
			default:
			printf("ERROR : %s %i : node type ",__FILE__,__LINE__);
			displayNodeType(p_Tree->getNodeType());
			printf(" is not manage\n");
			break;
		}
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	
	#ifdef TRACE
	printfTraceDown("getListParameter",__FILE__,__LINE__);
	#endif
	
	return p_Parameters;
}

list<tree*>* getListTree(tree *p_Tree,list<tree*> *p_Trees)
{
	#ifdef TRACE
	printfTraceUp("getListTree",__FILE__,__LINE__);
	#endif
	if(p_Tree!=NULL)
	{
		switch(p_Tree->getNodeType())
		{
			case Node_Ada_List_Discrete_Range:
			case Node_Ada_List_Index:
			p_Trees=getListTree(p_Tree->getSon(0),p_Trees);
			p_Trees=getListTree(p_Tree->getSon(1),p_Trees);
			break;
			case Node_Ada_Discrete_Range:
			case Node_Ada_Index:
			case Node_Ada_Range:
			case Node_Ada_Range_Inter:
			p_Trees=add(p_Tree,p_Trees);
			break;
			default:
			printf("ERROR : %s %i : node type ",__FILE__,__LINE__);
			displayNodeType(p_Tree->getNodeType());
			printf(" is not manage\n");
			my_exit(-1);
			break;
		}
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	
	#ifdef TRACE
	printfTraceDown("getListTree",__FILE__,__LINE__);
	#endif
	
	return p_Trees;
}

class variant;
extern variant* new_variant(tree *p_Tree);

list<variant*>* getListVariant(tree *p_Tree,list<variant*>* p_Variants)
{
	#ifdef TRACE
	printfTraceUp("getListVariant",__FILE__,__LINE__);
	#endif
	if(p_Tree!=NULL)
	{
		switch(p_Tree->getNodeType())
		{
			case Node_Ada_List_Variant:
			p_Variants=getListVariant(p_Tree->getSon(0),p_Variants);
			p_Variants=getListVariant(p_Tree->getSon(1),p_Variants);
			break;
			case Node_Ada_Variant:
			p_Variants=add(new_variant(p_Tree),p_Variants);
			break;
			default:
			errorNotAllowed(__FILE__,__LINE__,p_Tree,"variants_s, variant");
			my_exit(-1);
			break;
		}
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	
	#ifdef TRACE
	printfTraceDown("getListVariant",__FILE__,__LINE__);
	#endif
	
	return p_Variants;
}
