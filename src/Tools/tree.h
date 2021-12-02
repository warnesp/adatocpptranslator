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
 * Description: declaration of tree types
 *
 * $Log: tree.h,v $
 * Revision 1.3  2005/03/19 13:54:08  quicky2000
 * Update to add:
 * _ node types Node_C_Access_Subprog_Type_Decl, Node_C_Unconstraint_Array_Type, Node_C_Using_Namespace
 * _ getBase method to treeBased class
 *
 * Revision 1.2  2005/03/17 18:56:28  quicky2000
 * Update to:
 * _ make protected members be private
 * _ change accessor to m_TableSymbol member
 * _ add new accessor to string float and integer representation of tree
 *
 * Revision 1.1  2005/03/08 00:41:19  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ update to add new C nodes
 *
 * Revision 1.2  2005/03/03 23:05:06  quicky2000
 * Update to add node Node_C_Labelled_Stmt
 *
 * Revision 1.1.1.1  2005/03/01 22:20:50  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trace.h"

class unit;

// Enumeration type which represents the type of nodes
typedef enum
{
	Node_Ada_Abort_Stmt,
	Node_Ada_Abs,
	Node_Ada_Abstract_Derived_Type_With_Private,
	Node_Ada_Abstract_Derived_Type_With_Record,
	Node_Ada_Abstract_Subprog_Decl,
	Node_Ada_Abstract_Tagged,
	Node_Ada_Accept_Hdr,
	Node_Ada_Accept_Stmt,
	Node_Ada_Access,
	Node_Ada_Access_All_Type,
	Node_Ada_Access_Constant_Type,
	Node_Ada_Access_Type,
	Node_Ada_Address_Spec,
	Node_Ada_Affect,
	Node_Ada_Aggregate,
	Node_Ada_Aggregate_Null_Record,
	Node_Ada_Aliased,
	Node_Ada_Aliased_Constant,
	Node_Ada_Align_Opt,
	Node_Ada_Allocator,
	Node_Ada_Alternative,
	Node_Ada_And,
	Node_Ada_And_Then,
	Node_Ada_Async_Select,
	Node_Ada_Attrib_Def,
	Node_Ada_Attribute,
	Node_Ada_Basic_Loop,
	Node_Ada_Block,
	Node_Ada_Block_Body,
	Node_Ada_Block_Decl,
	Node_Ada_Body_Stub_Package,
	Node_Ada_Body_Stub_Prot,
	Node_Ada_Body_Stub_SubProg,
	Node_Ada_Body_Stub_Task,
	Node_Ada_C_And_Com,
	Node_Ada_C_Based_Number,
	Node_Ada_C_Comment,
	Node_Ada_C_Compilation_Unit,
	Node_Ada_C_Div,
	Node_Ada_C_Empty,
	Node_Ada_C_Float,
	Node_Ada_C_Formal_Part,
	Node_Ada_C_Ident,
	Node_Ada_C_Integer,
	Node_Ada_C_Less,
	Node_Ada_C_Less_Equal,
	Node_Ada_C_List_Compilation_Unit,
	Node_Ada_C_List_Decl_Item_Or_Body,
	Node_Ada_C_List_Statement,
	Node_Ada_C_Minor,
	Node_Ada_C_Mult,
	Node_Ada_C_Parenthesized_Primary,
	Node_Ada_C_Plus,
	Node_Ada_C_Program,
	Node_Ada_C_Quote_Char,
	Node_Ada_C_String,
	Node_Ada_C_Sup,
	Node_Ada_C_Sup_Equal,
	Node_Ada_C_Unary_Minor,
	Node_Ada_C_Unary_Plus,
	Node_Ada_C_Undefined,
	Node_Ada_Case,
	Node_Ada_Clause_Use_Option,
	Node_Ada_Clause_Width,
	Node_Ada_Code_Stmt,
	Node_Ada_Comp_Loc_s,
	Node_Ada_Component_Association,
	Node_Ada_Component_Decl,
	Node_Ada_Component_List,
	Node_Ada_Component_Subtype_Definition,
	Node_Ada_Compound_Name,
	Node_Ada_Cond_Entry_Call,
	Node_Ada_Condition_Clause,
	Node_Ada_Constant,
	Node_Ada_Constraint_Array_Type,
	Node_Ada_Context_Specification,
	Node_Ada_Decimal_Digits_Constraint,
	Node_Ada_Delay_Or_Entry_Alt,
	Node_Ada_Delay_Stmt,
	Node_Ada_Delay_Stmt_Until,
	Node_Ada_Delta,
	Node_Ada_Delta_Box,
	Node_Ada_Delta_Box_Digits_Box,
	Node_Ada_Derived_Type,
	Node_Ada_Derived_Type_With_Private,
	Node_Ada_Derived_Type_With_Record,
	Node_Ada_Digits,
	Node_Ada_Digits_Box_Lex,
	Node_Ada_Discrete_Range,
	Node_Ada_Discrete_With_Range,
	Node_Ada_Discrim_Part,
	Node_Ada_Discrim_Part_Opt,
	Node_Ada_Discrim_Spec,
	Node_Ada_Else,
	Node_Ada_Entry_Body,
	Node_Ada_Entry_Body_Part,
	Node_Ada_Entry_Decl,
	Node_Ada_Entry_Decl_s,
	Node_Ada_Entry_Name,
	Node_Ada_Enumeration_Type,
	Node_Ada_Equal,
	Node_Ada_Exception_Decl,
	Node_Ada_Exception_Handler,
	Node_Ada_Except_Choice_s,
	Node_Ada_Except_Handler_Part,
	Node_Ada_Exclusive_Or,
	Node_Ada_Exit,
	Node_Ada_Fixed_Type,
	Node_Ada_Float_Type,
	Node_Ada_Generic,
	Node_Ada_Generic_Decl,
	Node_Ada_Generic_Derived_Type,
	Node_Ada_Generic_Derived_Type_Abstract_Private,
	Node_Ada_Generic_Derived_Type_Private,
	Node_Ada_Generic_Discrim_Part_Opt,
	Node_Ada_Generic_Formal,
	Node_Ada_Generic_Formal_Package,
	Node_Ada_Generic_Formal_Package_Box,
	Node_Ada_Generic_Formal_Part,
	Node_Ada_Generic_Formal_Procedure,
	Node_Ada_Generic_Inst,
	Node_Ada_Generic_Package_Inst,
	Node_Ada_Generic_Subprog_Inst,
	Node_Ada_Generic_Subp_Inst,
	Node_Ada_Generic_Type_Def,
	Node_Ada_Generic_Type_Def_Box,
	Node_Ada_Goto,
	Node_Ada_Guarded_Select_Alt,
	Node_Ada_Handler_Statement,
	Node_Ada_If,
	Node_Ada_In,
	Node_Ada_Index,
	Node_Ada_Indexed_Comp,
	Node_Ada_Initialisation_Option,
	Node_Ada_Integer_Type,
	Node_Ada_Iteration,
	Node_Ada_Iterative_Part,
	Node_Ada_Label,
	Node_Ada_Label_Loop,
	Node_Ada_Limited,
	Node_Ada_List_Alternative,
	Node_Ada_List_Choice,
	Node_Ada_List_Component_Decl,
	Node_Ada_List_Condition_Clause,
	Node_Ada_List_C_Name,
	Node_Ada_List_Discrete_Range,
	Node_Ada_List_Discrim_Spec,
	Node_Ada_List_Enumeration_Identifier,
	Node_Ada_List_Identifier,
	Node_Ada_List_Index,
	Node_Ada_List_Item_Decl,
	Node_Ada_List_Name,
	Node_Ada_List_Parameter,
	Node_Ada_List_Pragma,
	Node_Ada_List_Pragma_Arg,
	Node_Ada_List_Value,
	Node_Ada_List_Value2,
	Node_Ada_List_Variant,
	Node_Ada_Loop,
	Node_Ada_Mark_Quote,
	Node_Ada_Mark_Point,
	Node_Ada_Mod,
	Node_Ada_Mode_Access,
	Node_Ada_Mod_Box,
	Node_Ada_Mode_In,
	Node_Ada_Mode_In_Out,
	Node_Ada_Mode_Out,
	Node_Ada_Mod_Integer_Type,
	Node_Ada_Non_Equal,
	Node_Ada_Not,
	Node_Ada_Not_In,
	Node_Ada_Null,
	Node_Ada_Null_Record,
	Node_Ada_Null_Statement,
	Node_Ada_Number_Decl,
	Node_Ada_Object_Decl,
	Node_Ada_Or,
	Node_Ada_Or_Else,
	Node_Ada_Or_Select,
	Node_Ada_Others,
	Node_Ada_Package_Body,
	Node_Ada_Package_Decl,
	Node_Ada_Package_Spec,
	Node_Ada_Parameter,
	Node_Ada_Power,
	Node_Ada_Pragma,
	Node_Ada_Pragma_Arg,
	Node_Ada_Private,
	Node_Ada_Private_Part,
	Node_Ada_Private_Type,
	Node_Ada_Procedure_Call,
	Node_Ada_Protected_Opt,
	Node_Ada_Prot_Body,
	Node_Ada_Prot_Decl,
	Node_Ada_Prot_Def,
	Node_Ada_Prot_Elem_Decl_s,
	Node_Ada_Prot_Op_Body,
	Node_Ada_Prot_Op_Body_s,
	Node_Ada_Prot_Op_Decl,
	Node_Ada_Prot_Op_Decl_s,
	Node_Ada_Prot_Private_Opt,
	Node_Ada_Prot_Spec,
	Node_Ada_Qualified,
	Node_Ada_Range,
	Node_Ada_Range_Box,
	Node_Ada_Range_Constraint,
	Node_Ada_Range_Inter,
	Node_Ada_Raise_Stmt,
	Node_Ada_Record_Definition,
	Node_Ada_Record_Type,
	Node_Ada_Record_Type_Spec,
	Node_Ada_Rem,
	Node_Ada_Rename_Decl,
	Node_Ada_Rename_Unit,
	Node_Ada_Rename_Unit_Package,
	Node_Ada_Renames,
	Node_Ada_Rep_Spec_s,
	Node_Ada_Requeue_Stmt,
	Node_Ada_Requeue_Stmt_With,
	Node_Ada_Return,
	Node_Ada_Reverse,
	Node_Ada_Selected_Comp,
	Node_Ada_Selected_Comp_All,
	Node_Ada_Select_Alt,
	Node_Ada_Select_Wait,
	Node_Ada_Statement,
	Node_Ada_Subp_Default,
	Node_Ada_Subprog_Body,
	Node_Ada_Subprog_Decl,
	Node_Ada_Subprog_Spec,
	Node_Ada_Subtype_Decl,
	Node_Ada_Subtype_Indication,
	Node_Ada_Subunit,
	Node_Ada_Tagged,
	Node_Ada_Task_Body,
	Node_Ada_Task_Decl,
	Node_Ada_Task_Def,
	Node_Ada_Task_Private_Opt,
	Node_Ada_Task_Spec,
	Node_Ada_Timed_Entry_Call,
	Node_Ada_Type_Decl,
	Node_Ada_Unconstraint_Array_Type,
	Node_Ada_Use_Clause,
	Node_Ada_Use_Clause_Type,
	Node_Ada_Value2,
	Node_Ada_Variant,
	Node_Ada_Variant_Part,
	Node_Ada_Variant_Part_Optional,
	Node_Ada_When,
	Node_C_Access_Type_Decl,
	Node_C_Access_Subprog_Type_Decl,
	Node_C_Affect,
	Node_C_And,
	Node_C_Array_Comp,
	Node_C_Array_Type,
	Node_C_Basic_Loop,
	Node_C_Block,
	Node_C_Break,
	Node_C_Case,
	Node_C_Comment,
	Node_C_Comment_Block,
	Node_C_Comment_Bracket,
	Node_C_Comment_Line,
	Node_C_Component_Association,
	Node_C_Component_Decl,
	Node_C_Condition_Clause,
	Node_C_Constant,
	Node_C_Default_Case,
	Node_C_Define,
	Node_C_Derived_Type_Decl,
	Node_C_Else,
	Node_C_Enumeration_Type_Decl,
	Node_C_Equal,
	Node_C_Exception_Handler,
	Node_C_Exclusive_Or,
	Node_C_Float,
	Node_C_Handler_Statement,
	Node_C_If,
	Node_C_Include_Local,
	Node_C_Initialisation_Option,
	Node_C_Int,
	Node_C_Iteration,
	Node_C_Iterative_Part,
	Node_C_Labelled_Stmt,
	Node_C_List_Condition_Clause,
	Node_C_List_Discrete_Range,
	Node_C_List_Parameter,
	Node_C_Loop,
	Node_C_Mark,
	Node_C_Mod,
	Node_C_Namespace_Def,
	Node_C_Non_Equal,
	Node_C_Not,
	Node_C_Object_Decl,
	Node_C_Or,
	Node_C_Parameter,
	Node_C_Post_Less,
	Node_C_Post_Plus,
	Node_C_Power,
	Node_C_Private_Part,
	Node_C_Spaced,
	Node_C_Star,
	Node_C_Structured_Type_Decl,
	Node_C_Subprog_Body,
	Node_C_Subprog_Spec,
	Node_C_Switch,
	Node_C_Unconstraint_Array_Type,
	Node_C_Using_Namespace,
	Node_C_While
	
}t_NodeType;



/*****************************************************************************
 * Function name : displayNodeType
 *
 * Input : p_NodeType : t_NodeType type of node
 * Output : none
 * Modified variable : none
 * Description : function which display the string corresponding to the node
 * type contain in "p_NodeType" parameter
 *****************************************************************************/
void displayNodeType(t_NodeType p_NodeType);


/*****************************************************************************
 * Class name : comment
 * Description : class which is the representation of a comment list
 *****************************************************************************/
class comment
{
	private:
	// Line number where comment takes place
	int m_NumLine;
	
	// text of comment
	const char *m_CommentText;
	
	// reference on next comment
	class comment *m_Next;
	
	public:
	// display
	void display(void);
	
	// Access method to member fields
	int getNumLine(void);
	const char *getCommentText(void);
	comment* getNext(void);
	
	// method which return the reference on the last comment
	comment* getLastComment(void);
	
	// method to add a new comment
	void addComment(comment *p_Comment);
	
	void setNextToNull(void);
	
	// check integrity
	void checkIntegrity(const char *p_FileName, int p_NumLine);
	
	//constructor
	comment(int p_NumLine,const char *p_CommentText);
	
	
};

/*****************************************************************************
 * Class name : tree
 * Description : class which is the representation of abstract tree
 *****************************************************************************/
class tree
{
	private:
	
	// Node type
	t_NodeType m_NodeType;
	
	// Nb son of node
	int m_NbSon;
	
	//line number of node
	int m_NumLine;
	
	//sons of node
	class tree **m_Sons;
	
	//string representation
	const char* m_String;
	
	//integer representation                                    
  	int m_Integer;
	
	// real representation                                      
  	double m_Float;
	
	// comment
	comment *m_Comment;
	
	// member of symbol table
	unit *m_TableSymbolMember;
	
	public:
	// Access methods to member fields
	t_NodeType getNodeType(void);
	int getNbSon(void);
	int getNumLine(void);
	tree* getSon(int p_NumSon);
	const char* getString(void);
	int getInteger(void);
	double getFloat(void);
	comment* getComment(void);
	unit* getTableSymbolMember(void);
	
	//method to find a node with its type
	tree* findNode(t_NodeType p_NodeType);
	
	// method to extract comments froms a tree
	comment* extractComments(void);
	
	
	// method to set autorized member fields
	void setInteger(int p_Integer);
	void setFloat(float p_Float);
	void setSon(int p_NumSon,tree *p_Tree);
	void setString(const char *p_String);
	void setTableSymbolMember(unit *p_TableSymbolMember);
	
	
	// method to add comment to a Node
	void addComment(comment *p_Comment);
	
	// method to puts correctly placed comments on tree
	comment* setComments(comment *p_Comments);
	
	// method to redistribute comments on tree
	void redistributeComments(void);
	
	// Check integrity
	void checkIntegrity(const char *p_FileName,int p_LineNumber);
	
	//Display
	void display(void);
	void displayTree(int p_Level=0);
	
	// Constructors
	tree(int p_NumLine);
	tree(t_NodeType p_NodeType,int p_NumLine);
	tree(t_NodeType p_NodeType, tree *p_Son1, int p_NumLine);
	tree(t_NodeType p_NodeType, tree *p_Son1, tree *p_Son2, int p_NumLine);
	tree(t_NodeType p_NodeType, tree *p_Son1, tree *p_Son2, tree *p_Son3, int p_NumLine);
	tree(t_NodeType p_NodeType, tree *p_Son1, tree *p_Son2, tree *p_Son3, tree *p_Son4, int p_NumLine);
	tree(t_NodeType p_NodeType, tree *p_Son1, tree *p_Son2, tree *p_Son3, tree *p_Son4, tree *p_Son5, int p_NumLine);
	tree(t_NodeType p_NodeType, tree *p_Son1, tree *p_Son2, tree *p_Son3, tree *p_Son4, tree *p_Son5, tree *p_Son6, int p_NumLine);
	
	// Special constructors
	tree(t_NodeType p_NodeType, int p_NumLine, const char * p_Ident);
};

/*****************************************************************************
 * Class name : treeInteger
 * Description : class which is the representation of a node containing an
 * integer
 *****************************************************************************/
class treeInteger: public tree
{
	public:
	treeInteger(int p_NumLine, const char * p_String);
};

/*****************************************************************************
 * Class name : treeFloat
 * Description : class which is the representation of a node containing a
 * float
 *****************************************************************************/
class treeFloat: public tree
{
	public:
	treeFloat(int p_NumLine, const char * p_String);
};

/*****************************************************************************
 * Class name : treeBased
 * Description : class which is the representation of a node containing a
 * basedNumber
 *****************************************************************************/
class treeBased: public tree
{
	private:
	int m_Base;
	
	public:
	treeBased(int p_NumLine, const char * p_String);

	int getBase(void);
};


#endif
