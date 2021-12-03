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
 * Description: creation of symbol table
 *
 * $Log: table_symbol_creation.h,v $
 * Revision 1.1  2005/03/07 23:40:24  quicky2000
 * Update to modify include paths due to to new source organization
 *
 * Revision 1.1.1.1  2005/03/01 22:20:47  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef TABLE_SYMBOL_CREATION_H
#define TABLE_SYMBOL_CREATION_H

/**************************
 * Include of debug tools *
 **************************/
#include "../Tools/error.h"
#include "../Tools/trace.h"

/********************
 * Include of tools *
 ********************/
#include "../Tools/list.h"
#include "../Tools/tree.h"
#include "../Tools/tree_string_representation.h"

/********************
 * include of types *
 ********************/
#include "../Table_symbol/access_function_type.h"
#include "../Table_symbol/access_object_type.h"
#include "../Table_symbol/access_procedure_type.h"
#include "../Table_symbol/array_type.h"
#include "../Table_symbol/constant_number.h"
#include "../Table_symbol/decimal_fixed_type.h"
#include "../Table_symbol/derived_type.h"
#include "../Table_symbol/enumerated_type.h"
#include "../Table_symbol/float_type.h"
#include "../Table_symbol/file.h"
#include "../Table_symbol/function_body.h"
#include "../Table_symbol/function_rename.h"
#include "../Table_symbol/generic_package_inst.h"
#include "../Table_symbol/modular_integer_type.h"
#include "../Table_symbol/ordinary_fixed_type.h"
#include "../Table_symbol/package.h"
#include "../Table_symbol/package_rename.h"
#include "../Table_symbol/procedure_body.h"
#include "../Table_symbol/procedure_rename.h"
#include "../Table_symbol/prot.h"
#include "../Table_symbol/prot_type.h"
#include "../Table_symbol/record_type.h"
#include "../Table_symbol/signed_integer_type.h"
#include "../Table_symbol/subtype.h"
#include "../Table_symbol/subunit.h"
#include "../Table_symbol/task.h"
#include "../Table_symbol/task_type.h"
#include "../Table_symbol/variable_array.h"
#include "../Table_symbol/variable_object.h"

/*************
 * Variables *
 *************/
extern file *g_CurrentFile;

/************************
 * subprog declarations *
 ************************/
void tableSymboleCreation(tree *p_Tree);

type* accessTypeDeclaration(tree *p_Tree,const char *p_Name);
type* arrayTypeDeclaration(tree *p_Tree,const char *p_Name);
void clauseUseTreatement(tree *p_Tree);
void clauseWithTreatement(tree *p_Tree);
type* fixedTypeDeclaration(tree *p_Tree,const char *p_Name);
void functionSpecDeclaration(tree *p_Tree);
void genericDeclarationManagement(tree *p_Tree);
void genericPackageDeclaration(tree *p_Tree);
void genericSubprogDeclaration(tree *p_Tree);
void genericPackageInstantiation(tree *p_Tree);
type* integerTypeDeclaration(tree *p_Tree,const char *p_Name);
void numberDeclaration(tree *p_Tree,tree *p_TreeInit);
void objectDeclaration(tree *p_IdentifierTree,tree *p_ObjectQualifierTree, tree *p_ObjectSubtypeDef, tree *p_InitTree);
void packageBodyDeclaration(tree *p_Tree);
void packageDeclarationManagement(tree *p_Tree);
void packageSpecDeclaration(tree *p_Tree);
void packageSubunitDeclaration(tree *p_Tree);
void procedureSpecDeclaration(tree *p_Tree);
void protBodyDeclaration(tree *p_Tree);
void protDeclaration(tree *p_Tree);
void renameUnitDeclaration(tree *p_Tree);
void renameUnitPackageDeclaration(tree *p_Tree);			
void subprogBodyDeclaration(tree *p_Tree);
void subprogDeclaration(tree *p_Tree);
void subtypeDeclaration(tree *p_Tree);
void taskBodyDeclaration(tree *p_Tree);
void taskDeclaration(tree *p_Tree);
void typeDeclaration(tree *p_Tree);

#endif
