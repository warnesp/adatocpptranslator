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
 * Description: declaration of table_symbol class
 *
 * $Log: table_symbol.cpp,v $
 * Revision 1.2  2005/03/19 11:19:03  quicky2000
 * Update to add cvs log flag
 *
 *
 *****************************************************************************/
#include "table_symbol.h"

table_symbol::table_symbol(void)
{
	#ifdef TRACE
		printfTraceUp("table_symbol",__FILE__,__LINE__);
	#endif
	m_Constants = NULL;
	m_FunctionSpecs = NULL;
	m_UseDependancies = NULL;
	m_WithDependancies = NULL;
	m_PackageBodys = NULL;
	m_PackageRenames = NULL;
	m_PackageSpecs = NULL;
	m_ProcedureSpecs = NULL;
	m_Types = NULL;
	m_VariableArrays = NULL;
	m_VariableObjects = NULL;
	#ifdef TRACE
		printfTraceDown("table_symbol",__FILE__,__LINE__);
	#endif

}


/* get procedures */
/******************/
list<constant_number*>* table_symbol::getConstants(void)
{
	return m_Constants;
}

list<function_spec*>* table_symbol::getFunctionSpecs(void)
{
	return m_FunctionSpecs;
}

list<named*>* table_symbol::getUseDependancies(void)
{
	return m_UseDependancies;
}

list<named*>* table_symbol::getWithDependancies(void)
{
	return m_WithDependancies;
}

list<package_body*>* table_symbol::getPackageBodys(void)
{
	return m_PackageBodys;
}

list<package_rename*>* table_symbol::getPackageRenames(void)
{
	return m_PackageRenames;
}

list<package_spec*>* table_symbol::getPackageSpecs(void)
{
	return m_PackageSpecs;
}

list<procedure_spec*>* table_symbol::getProcedureSpecs(void)
{
	return m_ProcedureSpecs;
}

list<type*>* table_symbol::getTypes(void)
{
	return m_Types;
}

list<variable_array*>* table_symbol::getVariableArrays(void)
{
	return m_VariableArrays;
}

list<variable_object*>* table_symbol::getVariableObjects(void)
{
	return m_VariableObjects;
}

/* Add procedures */
/******************/
void table_symbol::add(constant_number *p_Constant)
{
	#ifdef TRACE
	printfTraceUp("add",__FILE__,__LINE__);
	#endif
	m_Constants=::add(p_Constant,m_Constants);
	#ifdef TRACE
	printfTraceDown("add",__FILE__,__LINE__);
	#endif
}

void table_symbol::add(function_spec *p_FunctionSpec)
{
	#ifdef TRACE
	printfTraceUp("add",__FILE__,__LINE__);
	#endif
	m_FunctionSpecs=::add(p_FunctionSpec,m_FunctionSpecs);
	#ifdef TRACE
	printfTraceDown("add",__FILE__,__LINE__);
	#endif
}

void table_symbol::addUseDependancie(named *p_UseDependancie)
{
	#ifdef TRACE
	printfTraceUp("add",__FILE__,__LINE__);
	#endif
	m_UseDependancies=::add(p_UseDependancie,m_UseDependancies);
	#ifdef TRACE
	printfTraceDown("add",__FILE__,__LINE__);
	#endif
}

void table_symbol::addWithDependancie(named *p_WithDependancie)
{
	#ifdef TRACE
	printfTraceUp("add",__FILE__,__LINE__);
	#endif
	m_WithDependancies=::add(p_WithDependancie,m_WithDependancies);
	#ifdef TRACE
	printfTraceDown("add",__FILE__,__LINE__);
	#endif
}

void table_symbol::add(package_body *p_PackageBody)
{
	#ifdef TRACE
	printfTraceUp("add",__FILE__,__LINE__);
	#endif
	m_PackageBodys=::add(p_PackageBody,m_PackageBodys);
	#ifdef TRACE
	printfTraceDown("add",__FILE__,__LINE__);
	#endif
}

void table_symbol::add(package_rename *p_PackageRename)
{
	#ifdef TRACE
	printfTraceUp("add",__FILE__,__LINE__);
	#endif
	m_PackageRenames=::add(p_PackageRename,m_PackageRenames);
	#ifdef TRACE
	printfTraceDown("add",__FILE__,__LINE__);
	#endif
}

void table_symbol::add(package_spec *p_PackageSpec)
{
	#ifdef TRACE
	printfTraceUp("add",__FILE__,__LINE__);
	#endif
	m_PackageSpecs=::add(p_PackageSpec,m_PackageSpecs);
	#ifdef TRACE
	printfTraceDown("add",__FILE__,__LINE__);
	#endif
}

void table_symbol::add(procedure_spec *p_ProcedureSpec)
{
	#ifdef TRACE
	printfTraceUp("add",__FILE__,__LINE__);
	#endif
	m_ProcedureSpecs=::add(p_ProcedureSpec,m_ProcedureSpecs);
	#ifdef TRACE
	printfTraceDown("add",__FILE__,__LINE__);
	#endif
}

void table_symbol::add(type *p_Type)
{
	#ifdef TRACE
	printfTraceUp("add",__FILE__,__LINE__);
	#endif
	m_Types=::add(p_Type,m_Types);
	#ifdef TRACE
	printfTraceDown("add",__FILE__,__LINE__);
	#endif
}

void table_symbol::add(variable_array *p_VariableArray)
{
	#ifdef TRACE
	printfTraceUp("add",__FILE__,__LINE__);
	#endif
	m_VariableArrays=::add(p_VariableArray,m_VariableArrays);
	#ifdef TRACE
	printfTraceDown("add",__FILE__,__LINE__);
	#endif
}

void table_symbol::add(variable_object *p_VariableObject)
{
	#ifdef TRACE
	printfTraceUp("add",__FILE__,__LINE__);
	#endif
	m_VariableObjects=::add(p_VariableObject,m_VariableObjects);
	#ifdef TRACE
	printfTraceDown("add",__FILE__,__LINE__);
	#endif
}
