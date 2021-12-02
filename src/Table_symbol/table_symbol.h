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
 * $Log: table_symbol.h,v $
 * Revision 1.2  2005/03/19 09:52:30  quicky2000
 * Update to add the cvs log flag
 *
 *
 *****************************************************************************/
#ifndef TABLE_SYMBOL_H
	#define TABLE_SYMBOL_H

	#include "../Tools/error.h"
	#include "../Tools/trace.h"
	#include "../Tools/list.h"
		
	class table_symbol
	{
		public:
			table_symbol(void);

		void add(constant_number *p_Constant);
		void add(function_spec *p_FunctionSpec);
		void addUseDependancie(named *p_UseDependancie);
		void addWithDependancie(named *p_WithDependancie);
		void add(package_body *p_PackageBody);
		void add(package_rename *p_PackageRename);
		void add(package_spec *p_PackageSpec);
		void add(procedure_spec *p_ProcedureSpec);
		void add(type *p_Type);
		void add(variable_array *p_VariableArray);
		void add(variable_object *p_VariableObject);

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
	
			private:
			list<constant_number*> *m_Constants;
			list<function_spec*> *m_FunctionSpecs;
			list<named*> *m_UseDependancies;
			list<named*> *m_WithDependancies;
			list<package_body*> *m_PackageBodys;
			list<package_rename*> *m_PackageRenames;
			list<package_spec*> *m_PackageSpecs;
			list<procedure_spec*> *m_ProcedureSpecs;
			list<type*> *m_Types;
			list<variable_array*> *m_VariableArrays;
			list<variable_object*> *m_VariableObjects;

	};
#endif
