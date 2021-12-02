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
 * Description: instantiation of main_unit class
 *
 * $Log: main_unit.cpp,v $
 * Revision 1.3  2005/03/19 14:46:59  quicky2000
 * Update to add getConstantNumber method. This method allow to search a constant_number in a main unit
 *
 * Revision 1.2  2005/03/18 19:12:44  quicky2000
 * Update due to the replacement of list unit members by a member whose type is table of symbol
 *
 * Revision 1.1  2005/03/13 16:40:30  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 * _ to add a function to search a vfunctions specifications in main unit
 *
 * Revision 1.1.1.1  2005/03/01 22:20:40  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "main_unit.h"

#include "../Tools/list_tools.h"

void displayMainUnitType(t_MainUnitType p_MainUnitType)
{
	switch(p_MainUnitType)
	{
		case Main_Unit_File:
		printf("Main_Unit_File");
		break;
		
		case Main_Unit_Generic_Package:
		printf("Main_Unit_Generic_Package");
		break;
	
		case Main_Unit_Generic_Subprog_Body:
		printf("Main_Unit_Generic_Subprog_Body");
		break;
	
		case Main_Unit_Package:
		printf("Main_Unit_Package");
		break;
	
		case Main_Unit_Procedure_Body:
		printf("Main_Unit_Procedure_Body");
		break;
		
		case Main_Unit_Prot:
		printf("Main_Unit_Prot");
		break;
		
		case Main_Unit_Function_Body:
		printf("Main_Unit_Function_Body");
		break;
		
		case Main_Unit_Task:
		printf("Main_Unit_Task");
		break;
		
		case Main_Unit_Table_Symbol:
		printf("Main_Unit_Table_Symbol");
		break;
		
		case Main_Unit_Undefined:
		printf("Main_Unit_Undefined");
		break;
	
		default:
		printf("INTERNAL ERROR : %s %i : main unit type %i is not manage\n",__FILE__,__LINE__,p_MainUnitType);
		my_exit(-1);
		break;
	}
	
	
}

/* get members */
/***************/
t_MainUnitType main_unit::getMainUnitType(void)
{
	return m_MainUnitType;
}

list<constant_number*>* main_unit::getConstants(void)
{
	return m_TableSymbol->getConstants();
}

list<function_spec*>* main_unit::getFunctionSpecs(void)
{
	return m_TableSymbol->getFunctionSpecs();
}

list<named*>* main_unit::getUseDependancies(void)
{
	return m_TableSymbol->getUseDependancies();
}

list<named*>* main_unit::getWithDependancies(void)
{
	return m_TableSymbol->getWithDependancies();
}

list<package_body*>* main_unit::getPackageBodys(void)
{
	return m_TableSymbol->getPackageBodys();
}

list<package_rename*>* main_unit::getPackageRenames(void)
{
	return m_TableSymbol->getPackageRenames();
}

list<package_spec*>* main_unit::getPackageSpecs(void)
{
	return m_TableSymbol->getPackageSpecs();
}

list<procedure_spec*>* main_unit::getProcedureSpecs(void)
{
	return m_TableSymbol->getProcedureSpecs();
}

list<type*>* main_unit::getTypes(void)
{
	return m_TableSymbol->getTypes();
}

list<variable_array*>* main_unit::getVariableArrays(void)
{
	return m_TableSymbol->getVariableArrays();
}

list<variable_object*>* main_unit::getVariableObjects(void)
{
	return m_TableSymbol->getVariableObjects();
}

/* Advanced get */
/****************/
constant_number* main_unit::getConstantNumber(char *p_Name)
{
	#ifdef TRACE
	printfTraceUp("getConstantNumber",__FILE__,__LINE__);
	#endif
	constant_number *l_Result=NULL;
	if(p_Name!=NULL)
	{
		list<constant_number*> *l_List=NULL;
		l_List=getByName(p_Name,m_TableSymbol->getConstants());

		if(l_List==NULL && m_MainUnitType!=Main_Unit_File)
		{
			l_Result=getMainUnit()->getConstantNumber(p_Name);
		}
		if(l_List!=NULL)
		{
			if(l_List->getNbItem()==1)
			{
				l_Result=(constant_number*)l_List->getItem();
			}
			else
			{
				printf("INTERNAL ERROR : %s %i: ambiguity during searh of constant number \"%s\"\n",__FILE__,__LINE__,p_Name);
				my_exit(-1);
			}
		}
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Name");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("getConstantNumber",__FILE__,__LINE__);
	#endif
	return l_Result;
}

file* main_unit::getFile(void)
{
	#ifdef TRACE
	printfTraceUp("getFile",__FILE__,__LINE__);
	#endif
	file *result=NULL;
	if(m_MainUnitType!=Main_Unit_File)
	{
		result=getMainUnit()->getFile();
	}
	else
	{
		result=(file*)this;
	}
	
	#ifdef TRACE
	printfTraceDown("getFile",__FILE__,__LINE__);
	#endif
	return result;
}

function_spec* main_unit::getFunctionSpec(char *p_Name)
{
	#ifdef TRACE
	printfTraceUp("getFunctionSpec",__FILE__,__LINE__);
	#endif
	function_spec *l_Result=NULL;
	if(p_Name!=NULL)
	{
		list<function_spec*> *l_List=NULL;
		l_List=getByName(getName(),m_TableSymbol->getFunctionSpecs());

		if(l_List==NULL && m_MainUnitType!=Main_Unit_File)
		{
			l_Result=getMainUnit()->getFunctionSpec(p_Name);
		}
		if(l_List!=NULL)
		{
			if(l_List->getNbItem()==1)
			{
				l_Result=(function_spec*)l_List->getItem();
			}
			else
			{
				//printf("INTERNAL ERROR : %s %i: ambiguity during solve of function \"%s\"\n",__FILE__,__LINE__,p_Name);
				//my_exit(-1);
			}
		}
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Name");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("getFunctionSpec",__FILE__,__LINE__);
	#endif
	return l_Result;
	
}

list<named*>* main_unit::getGlobalWithDependancies(void)
{
	#ifdef TRACE
	printfTraceUp("getGlobalWithDependancies",__FILE__,__LINE__);
	#endif
	list<named*> *l_Result=NULL;
	l_Result=cat(l_Result,m_TableSymbol->getWithDependancies());
	if(getMainUnit()->getMainUnitType()!=Main_Unit_File)
	{
		l_Result=cat(l_Result,getMainUnit()->getGlobalWithDependancies());
	}
	
	#ifdef TRACE
	printfTraceDown("getGlobalWithDependancies",__FILE__,__LINE__);
	#endif
	return l_Result;
}

package* main_unit::getPackage(void)
{
	#ifdef TRACE
	printfTraceUp("getPackage",__FILE__,__LINE__);
	#endif
	package *l_Result=NULL;
	if(m_MainUnitType!=Main_Unit_File)
	{
		if(m_MainUnitType==Main_Unit_Package)
		{
			l_Result=(package*)this;
		}
		else
		{
			l_Result=getMainUnit()->getPackage();
		}
	}
	
	#ifdef TRACE
	printfTraceDown("getPackage",__FILE__,__LINE__);
	#endif
	return l_Result;
}

package_rename* main_unit::getPackageRename(char *p_Name)
{
	#ifdef TRACE
	printfTraceUp("getPackageRename",__FILE__,__LINE__);
	#endif
	
	package_rename *l_Result=NULL;
	if(p_Name!=NULL)
	{
		list<package_rename*> *l_List=NULL;
		l_List=getByName(p_Name,m_TableSymbol->getPackageRenames());

		if(l_List==NULL && m_MainUnitType!=Main_Unit_File)
		{
			l_Result=getMainUnit()->getPackageRename(p_Name);
		}
		if(l_List!=NULL)
		{
			if(l_List->getNbItem()==1)
			{
				l_Result=(package_rename*)l_List->getItem();
			}
			else
			{
				printf("INTERNAL ERROR : %s %i: ambiguity during solve of package \"%s\" rename\n",__FILE__,__LINE__,p_Name);
				my_exit(-1);
			}
		}
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Name");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("getPackageRename",__FILE__,__LINE__);
	#endif
	
	return l_Result;
}

type* main_unit::getType(char *p_Name)
{
	#ifdef TRACE
	printfTraceUp("getType",__FILE__,__LINE__);
	#endif
	type *l_Result=NULL;
	if(p_Name!=NULL)
	{
		list<type*> *l_List=NULL;
		l_List=getByName(p_Name,m_TableSymbol->getTypes());

		if(l_List==NULL && m_MainUnitType!=Main_Unit_File)
		{
			l_Result=getMainUnit()->getType(p_Name);
		}
		if(l_List!=NULL)
		{
			if(l_List->getNbItem()==1)
			{
				l_Result=(type*)l_List->getItem();
			}
			else
			{
				printf("INTERNAL ERROR : %s %i: ambiguity during solve of type \"%s\"\n",__FILE__,__LINE__,p_Name);
				my_exit(-1);
			}
		}
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Name");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("getType",__FILE__,__LINE__);
	#endif
	return l_Result;
	
}

variable* main_unit::getVariable(char *p_Name)
{
	#ifdef TRACE
	printfTraceUp("getVariable",__FILE__,__LINE__);
	#endif
	
	variable *l_Result=NULL;
	if(p_Name!=NULL)
	{
		list<variable*> *l_List=NULL;
		list<variable*> *l_ListVariableObject=NULL;
		list<variable*> *l_ListVariableArray=NULL;
		
		l_ListVariableObject=(list<variable*>*)getByName(p_Name,m_TableSymbol->getVariableObjects());
		l_ListVariableArray=(list<variable*>*)getByName(p_Name,m_TableSymbol->getVariableArrays());
		l_List=cat(l_ListVariableObject,l_ListVariableArray);
		
		if(l_List==NULL && m_MainUnitType!=Main_Unit_File)
		{
			l_Result=getMainUnit()->getVariable(p_Name);
		}
		if(l_List!=NULL)
		{
			if(l_List->getNbItem()==1)
			{
				l_Result=(variable*)l_List->getItem();
				//printf("variable %s\n",l_Result->getName());
			}
			else
			{
				printf("INTERNAL ERROR : %s %i: ambiguity during solve of variable \"%s\"\n",__FILE__,__LINE__,p_Name);
				my_exit(-1);
			}
		}
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Name");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("getVariable",__FILE__,__LINE__);
	#endif
	return l_Result;
	
}

void main_unit::add(constant_number *p_Constant)
{
	#ifdef TRACE
	printfTraceUp("add",__FILE__,__LINE__);
	#endif
	m_TableSymbol->add(p_Constant);
	#ifdef TRACE
	printfTraceDown("add",__FILE__,__LINE__);
	#endif
}

void main_unit::add(function_spec *p_FunctionSpec)
{
	#ifdef TRACE
	printfTraceUp("add",__FILE__,__LINE__);
	#endif
	m_TableSymbol->add(p_FunctionSpec);
	#ifdef TRACE
	printfTraceDown("add",__FILE__,__LINE__);
	#endif
}

void main_unit::addUseDependancie(named *p_UseDependancie)
{
	#ifdef TRACE
	printfTraceUp("add",__FILE__,__LINE__);
	#endif
	m_TableSymbol->addUseDependancie(p_UseDependancie);
	#ifdef TRACE
	printfTraceDown("add",__FILE__,__LINE__);
	#endif
}

void main_unit::addWithDependancie(named *p_WithDependancie)
{
	#ifdef TRACE
	printfTraceUp("add",__FILE__,__LINE__);
	#endif
	m_TableSymbol->addWithDependancie(p_WithDependancie);
	#ifdef TRACE
	printfTraceDown("add",__FILE__,__LINE__);
	#endif
}

void main_unit::add(package_body *p_PackageBody)
{
	#ifdef TRACE
	printfTraceUp("add",__FILE__,__LINE__);
	#endif
	m_TableSymbol->add(p_PackageBody);
	#ifdef TRACE
	printfTraceDown("add",__FILE__,__LINE__);
	#endif
}

void main_unit::add(package_rename *p_PackageRename)
{
	#ifdef TRACE
	printfTraceUp("add",__FILE__,__LINE__);
	#endif
	m_TableSymbol->add(p_PackageRename);
	#ifdef TRACE
	printfTraceDown("add",__FILE__,__LINE__);
	#endif
}

void main_unit::add(package_spec *p_PackageSpec)
{
	#ifdef TRACE
	printfTraceUp("add",__FILE__,__LINE__);
	#endif
	m_TableSymbol->add(p_PackageSpec);
	#ifdef TRACE
	printfTraceDown("add",__FILE__,__LINE__);
	#endif
}

void main_unit::add(procedure_spec *p_ProcedureSpec)
{
	#ifdef TRACE
	printfTraceUp("add",__FILE__,__LINE__);
	#endif
	m_TableSymbol->add(p_ProcedureSpec);
	#ifdef TRACE
	printfTraceDown("add",__FILE__,__LINE__);
	#endif
}

void main_unit::add(type *p_Type)
{
	#ifdef TRACE
	printfTraceUp("add",__FILE__,__LINE__);
	#endif
	m_TableSymbol->add(p_Type);
	#ifdef TRACE
	printfTraceDown("add",__FILE__,__LINE__);
	#endif
}

void main_unit::add(variable_array *p_VariableArray)
{
	#ifdef TRACE
	printfTraceUp("add",__FILE__,__LINE__);
	#endif
	m_TableSymbol->add(p_VariableArray);
	#ifdef TRACE
	printfTraceDown("add",__FILE__,__LINE__);
	#endif
}

void main_unit::add(variable_object *p_VariableObject)
{
	#ifdef TRACE
	printfTraceUp("add",__FILE__,__LINE__);
	#endif
	m_TableSymbol->add(p_VariableObject);
	#ifdef TRACE
	printfTraceDown("add",__FILE__,__LINE__);
	#endif
}

void main_unit::checkIntegrity(char *p_FileName,int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	
	int error=0;
	
	if(m_MainUnitType==Main_Unit_Undefined)
	{
		printf("INTERNAL ERROR : %s %i : \"m_MainUnitType\" value is \"",p_FileName,p_LineNumber);
		displayMainUnitType(m_MainUnitType);
		printf("\"\n");
		error=1;
	}
	if((m_MainUnitType!=Main_Unit_File && m_MainUnitType!=Main_Unit_Table_Symbol)&& getMainUnit()==NULL)
	{
		errorIsNull(p_FileName,p_LineNumber,"m_MainUnit");
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

main_unit::main_unit(void):unit()
{
	#ifdef TRACE
	printfTraceUp("main_unit",__FILE__,__LINE__);
	#endif
	m_MainUnitType = Main_Unit_Undefined;
	m_TableSymbol = new table_symbol();
	#ifdef TRACE
	printfTraceDown("main_unit",__FILE__,__LINE__);
	#endif
	
}
	
main_unit::main_unit(t_MainUnitType p_MainUnitType,char *p_Name,main_unit *p_MainUnit):unit(p_Name,p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("main_unit",__FILE__,__LINE__);
	#endif
	m_MainUnitType=p_MainUnitType;
	m_TableSymbol = new table_symbol();
	this->checkIntegrity(__FILE__,__LINE__);
	#ifdef TRACE
	printfTraceDown("main_unit",__FILE__,__LINE__);
	#endif
	
}
