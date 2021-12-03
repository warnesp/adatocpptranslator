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
 * Description: declaration of main_unit class
 *
 * $Log: main_unit.h,v $
 * Revision 1.4  2005/03/19 15:24:03  quicky2000
 * Update to add getConstantNumber method declaration
 *
 * Revision 1.3  2005/03/19 11:28:58  quicky2000
 * Update for code maintenance
 *
 * Revision 1.2  2005/03/19 08:42:04  quicky2000
 * Update to replace members list of main units by a table of symbol member
 *
 * Revision 1.1  2005/03/08 19:26:37  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ update the include paths due to the new organization of source files
 *
 * Revision 1.1.1.1  2005/03/01 22:20:40  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef MAIN_UNIT_H
#define MAIN_UNIT_H

#include <stdio.h>
#include <stdlib.h>

#include "../Tools/error.h"
#include "../Tools/trace.h"
#include "../Tools/indent.h"

#include "../Table_symbol/table_symbol.h"
#include "unit.h"

class file;
class package;
class variable;

/* Type of main_unit */
/*********************/
typedef enum
{
	Main_Unit_File,
	Main_Unit_Function_Body,
	Main_Unit_Generic_Package,
	Main_Unit_Generic_Subprog_Body,
	Main_Unit_Package,
	Main_Unit_Procedure_Body,
	Main_Unit_Prot,

	Main_Unit_Subunit,
	Main_Unit_Table_Symbol,
	Main_Unit_Task,
	Main_Unit_Undefined
} t_MainUnitType;

void displayMainUnitType(t_MainUnitType p_MainUnitType);

/* class main_unit */
/*******************/
class main_unit: public unit
{
	private:
	t_MainUnitType m_MainUnitType;
	table_symbol *m_TableSymbol;
	
	public:
	
	/* get members */
	t_MainUnitType getMainUnitType(void);
	list<constant_number*>* getConstants(void);
	list<function_spec*>* getFunctionSpecs(void);
	list<named*>* getUseDependancies(void);
	list<named*>* getWithDependancies(void);
	list<package_body*>* getPackageBodys(void);
	list<package_rename*>* getPackageRenames(void);
	list<package_spec*>* getPackageSpecs(void);
	list<procedure_spec*>* getProcedureSpecs(void);
	list<type*>* getTypes(void);
	list<variable_array*>* getVariableArrays(void);
	list<variable_object*>* getVariableObjects(void);
	
	/* Advanced get */
	constant_number* getConstantNumber(const char *p_Name);
	file* getFile(void);
	function_spec* getFunctionSpec(const char *p_Name);
	list<named*>* getGlobalWithDependancies(void);
	package* getPackage(void);
	package_rename* getPackageRename(const char *p_Name);
	type* getType(const char *p_Name);
	virtual variable* getVariable(const char *p_Name);
	
	void add(constant_number *p_Constant);
	void add(function_spec *p_Constant);
	void addUseDependancie(named *p_UseDependancie);
	void addWithDependancie(named *p_WithDependancie);
	void add(package_body *p_PackageBody);
	void add(package_rename *p_PackageRename);
	void add(package_spec *p_PackageSpec);
	void add(procedure_spec *p_ProcedureSpec);
	void add(type *p_Type);
	void add(variable_array *p_VariableArray);
	void add(variable_object *p_VariableObject);
	
	void checkIntegrity(const char *p_FileName,int p_LineNumber);
	
	main_unit(void);
	main_unit(t_MainUnitType p_MainUnitType,const char *p_Name,main_unit *p_MainUnit);
};

#endif
