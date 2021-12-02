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
 * Description: translation of abstract tree
 *
 * $Log: tree_translation.h,v $
 * Revision 1.3  2005/03/19 10:58:50  quicky2000
 * Update for code maintenance
 *
 * Revision 1.2  2005/03/16 20:57:46  quicky2000
 * Update to add an include
 *
 * Revision 1.1  2005/03/07 23:58:18  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ modify the include paths due to new organisation of source files
 *
 * Revision 1.1.1.1  2005/03/01 22:20:51  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef TREE_TRANSLATION_H
#define TREE_TRANSLATION_H

#include "../Tools/error.h"
#include "../Tools/trace.h"

#include "table_symbol_exploitation.h"
#include "../Table_symbol/file.h"

/*************
 * Variables *
 *************/

class main_unit;
extern main_unit *g_TableSymbol;
extern configuration *g_Config;
extern file *g_CurrentFile;

tree* translation(FILE *p_FpLog,tree *p_Tree);
tree* translationRecordTypeDecl(FILE *p_FpLog,tree *p_NameTree, tree *p_DiscrimTree, tree *p_RecordDefTree);
tree* translationTypeDecl(FILE *p_FpLog,tree *p_Tree);
tree* translationListConditionClause(FILE *p_FpLog,tree *p_ListConditionClauseTree,tree *p_ElseOptTree);
tree* translationIndexedComp(FILE *p_FpLog,tree *p_Tree);

#endif
