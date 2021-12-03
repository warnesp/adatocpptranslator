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
 * Description: instantiation of tree types
 *
 * $Log: tree.cpp,v $
 * Revision 1.3  2005/03/19 13:42:26  quicky2000
 * Update to:
 * _ modify tree_based constructor: the decimal value is calculated and stored in a member
 * _ add missing Node_C_Access_Subprog_Type_Decl, Node_C_Unconstraint_Array_Type, Node_C_Using_Namespace in displayNodeType function
 * _ add getBase method to treeBased class
 *
 * Revision 1.2  2005/03/17 18:54:05  quicky2000
 * Update to:
 * _ make protected members be private
 * _ change accessor to m_TableSymbol member
 * _ add new accessor to string float and integer representation of tree
 *
 * Revision 1.1  2005/03/08 00:42:43  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ update to add new C nodes
 *
 * Revision 1.2  2005/03/03 23:05:06  quicky2000
 * Update to add node Node_C_Labelled_Stmt
 *
 * Revision 1.1.1.1  2005/03/01 22:20:49  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/

#include "tree.h"
#include "math.h"
#include "my_string.h"

/*****************************************************************************
 * Function name : displayNodeType
 *
 * Input : p_NodeType : t_NodeType type of node
 * Output : none
 * Modified variable : none
 * Description : function which display the string corresponding to the node
 * type contain in "p_NodeType" parameter
 *****************************************************************************/
void displayNodeType(t_NodeType p_NodeType)
{
	switch(p_NodeType)
	{
		case Node_Ada_Abort_Stmt:printf("Node_Ada_Abort_Stmt");break;
		case Node_Ada_Abs:printf("Node_Ada_Abs");break;
		case Node_Ada_Abstract_Derived_Type_With_Private:printf("Node_Ada_Abstract_Derived_Type_With_Private");break;
		case Node_Ada_Abstract_Derived_Type_With_Record:printf("Node_Ada_Abstract_Derived_Type_With_Record");break;
		case Node_Ada_Abstract_Subprog_Decl:printf("Node_Ada_Abstract_Subprog_Decl");break;
		case Node_Ada_Abstract_Tagged:printf("Node_Ada_Abstract_Tagged");break;
		case Node_Ada_Accept_Hdr:printf("Node_Ada_Accept_Hdr");break;
		case Node_Ada_Accept_Stmt:printf("Node_Ada_Accept_Stmt");break;
		case Node_Ada_Access:printf("Node_Ada_Access");break;
		case Node_Ada_Access_All_Type:printf("Node_Ada_Access_All_Type");break;
		case Node_Ada_Access_Constant_Type:printf("Node_Ada_Access_Constant_Type");break;
		case Node_Ada_Access_Type:printf("Node_Ada_Access_Type");break;
		case Node_Ada_Address_Spec:printf("Node_Ada_Address_Spec");break;
		case Node_Ada_Affect:printf("Node_Ada_Affect");break;
		case Node_Ada_Aggregate:printf("Node_Ada_Aggregate");break;
		case Node_Ada_Aggregate_Null_Record:printf("Node_Ada_Aggregate_Null_Record");break;
		case Node_Ada_Aliased:printf("Node_Ada_Aliased");break;
		case Node_Ada_Aliased_Constant:printf("Node_Ada_Aliased_Constant");break;
		case Node_Ada_Align_Opt:printf("Node_Ada_Align_Opt");break;
		case Node_Ada_Allocator:printf("Node_Ada_Allocator");break;
		case Node_Ada_Alternative:printf("Node_Ada_Alternative");break;
		case Node_Ada_And:printf("Node_Ada_And");break;
		case Node_Ada_And_Then:printf("Node_Ada_And_Then");break;
		case Node_Ada_Async_Select:printf("Node_Ada_Async_Select");break;
		case Node_Ada_Attrib_Def:printf("Node_Ada_Attrib_Def");break;
		case Node_Ada_Attribute:printf("Node_Ada_Attribute");break;
		case Node_Ada_Basic_Loop:printf("Node_Ada_Basic_Loop");break;
		case Node_Ada_Block:printf("Node_Ada_Block");break;
		case Node_Ada_Block_Body:printf("Node_Ada_Block_Body");break;
		case Node_Ada_Block_Decl:printf("Node_Ada_Block_Decl");break;
		case Node_Ada_Body_Stub_Package:printf("Node_Ada_Body_Stub_Package");break;
		case Node_Ada_Body_Stub_Prot:printf("Node_Ada_Body_Stub_Prot");break;
		case Node_Ada_Body_Stub_SubProg:printf("Node_Ada_Body_Stub_SubProg");break;
		case Node_Ada_Body_Stub_Task:printf("Node_Ada_Body_Stub_Task");break;
		case Node_Ada_C_And_Com:printf("Node_Ada_C_And_Com");break;
		case Node_Ada_C_Based_Number:printf("Node_Ada_C_Based_Number");break;
		case Node_Ada_C_Div:printf("Node_Ada_C_Div");break;
		case Node_Ada_C_Comment:printf("Node_Ada_C_Comment");break;
		case Node_Ada_C_Compilation_Unit:printf("Node_Ada_C_Compilation_Unit");break;
		case Node_Ada_C_Empty:printf("Node_Ada_C_Empty");break;
		case Node_Ada_C_Float:printf("Node_Ada_C_Float");break;
		case Node_Ada_C_Formal_Part:printf("Node_Ada_C_Formal_Part");break;
		case Node_Ada_C_Ident:printf("Node_Ada_C_Ident");break;
		case Node_Ada_C_Integer:printf("Node_Ada_C_Integer");break;
		case Node_Ada_C_Less:printf("Node_Ada_C_Less");break;
		case Node_Ada_C_Less_Equal:printf("Node_Ada_C_Less_Equal");break;
		case Node_Ada_C_List_Compilation_Unit:printf("Node_Ada_C_List_Compilation_Unit");break;
		case Node_Ada_C_List_Decl_Item_Or_Body:printf("Node_Ada_C_List_Decl_Item_Or_Body");break;
		case Node_Ada_C_List_Statement:printf("Node_Ada_C_List_Statement");break;
		case Node_Ada_C_Minor:printf("Node_Ada_C_Minor");break;
		case Node_Ada_C_Mult:printf("Node_Ada_C_Mult");break;
		case Node_Ada_C_Parenthesized_Primary:printf("Node_Ada_C_Parenthesized_Primary");break;
		case Node_Ada_C_Plus:printf("Node_Ada_C_Plus");break;
		case Node_Ada_C_Program:printf("Node_Ada_C_Program");break;
		case Node_Ada_C_Quote_Char:printf("Node_Ada_C_Quote_Char");break;
		case Node_Ada_C_String:printf("Node_Ada_C_String");break;
		case Node_Ada_C_Sup:printf("Node_Ada_C_Sup");break;
		case Node_Ada_C_Sup_Equal:printf("Node_Ada_C_Sup_Equal");break;
		case Node_Ada_C_Unary_Minor:printf("Node_Ada_C_Unary_Minor");break;
		case Node_Ada_C_Unary_Plus:printf("Node_Ada_C_Unary_Plus");break;
		case Node_Ada_C_Undefined:printf("Node_Ada_C_Undefined");break;
		case Node_Ada_Case:printf("Node_Ada_Case");break;
		case Node_Ada_Clause_Use_Option:printf("Node_Ada_Clause_Use_Option");break;
		case Node_Ada_Clause_Width:printf("Node_Ada_Clause_Width");break;
		case Node_Ada_Code_Stmt:printf("Node_Ada_Code_Stmt");break;
		case Node_Ada_Comp_Loc_s:printf("Node_Ada_Comp_Loc_s");break;
		case Node_Ada_Component_Association:printf("Node_Ada_Component_Association");break;
		case Node_Ada_Component_Decl:printf("Node_Ada_Component_Decl");break;
		case Node_Ada_Component_List:printf("Node_Ada_Component_List");break;
		case Node_Ada_Component_Subtype_Definition:printf("Node_Ada_Component_Subtype_Definition");break;
		case Node_Ada_Compound_Name:printf("Node_Ada_Compound_Name");break;
		case Node_Ada_Cond_Entry_Call:printf("Node_Ada_Cond_Entry_Call");break;
		case Node_Ada_Condition_Clause:printf("Node_Ada_Condition_Clause");break;
		case Node_Ada_Constant:printf("Node_Ada_Constant");break;
		case Node_Ada_Constraint_Array_Type:printf("Node_Ada_Constraint_Array_Type");break;
		case Node_Ada_Context_Specification:printf("Node_Ada_Context_Specification");break;
		case Node_Ada_Decimal_Digits_Constraint:printf("Node_Ada_Decimal_Digits_Constraint");break;
		case Node_Ada_Delay_Or_Entry_Alt:printf("Node_Ada_Delay_Or_Entry_Alt");break;
		case Node_Ada_Delay_Stmt:printf("Node_Ada_Delay_Stmt");break;
		case Node_Ada_Delay_Stmt_Until:printf("Node_Ada_Delay_Stmt_Until");break;
		case Node_Ada_Delta:printf("Node_Ada_Delta");break;
		case Node_Ada_Delta_Box:printf("Node_Ada_Delta_Box");break;
		case Node_Ada_Delta_Box_Digits_Box:printf("Node_Ada_Delta_Box_Digits_Box");break;
		case Node_Ada_Derived_Type:printf("Node_Ada_Derived_Type");break;
		case Node_Ada_Derived_Type_With_Private:printf("Node_Ada_Derived_Type_With_Private");break;
		case Node_Ada_Derived_Type_With_Record:printf("Node_Ada_Derived_Type_With_Record");break;
		case Node_Ada_Digits:printf("Node_Ada_Digits");break;
		case Node_Ada_Digits_Box_Lex:printf("Node_Ada_Digits_Box_Lex");break;
		case Node_Ada_Discrete_Range:printf("Node_Ada_Discrete_Range");break;
		case Node_Ada_Discrete_With_Range:printf("Node_Ada_Discrete_With_Range");break;
		case Node_Ada_Discrim_Part:printf("Node_Ada_Discrim_Part");break;
		case Node_Ada_Discrim_Part_Opt:printf("Node_Ada_Discrim_Part_Opt");break;
		case Node_Ada_Discrim_Spec:printf("Node_Ada_Discrim_Spec");break;
		case Node_Ada_Else:printf("Node_Ada_Else");break;
		case Node_Ada_Entry_Body:printf("Node_Ada_Entry_Body");break;
		case Node_Ada_Entry_Body_Part:printf("Node_Ada_Entry_Body_Part");break;
		case Node_Ada_Entry_Decl:printf("Node_Ada_Entry_Decl");break;
		case Node_Ada_Entry_Decl_s:printf("Node_Ada_Entry_Decl_s");break;
		case Node_Ada_Entry_Name:printf("Node_Ada_Entry_Name");break;
		case Node_Ada_Enumeration_Type:printf("Node_Ada_Enumeration_Type");break;
		case Node_Ada_Equal:printf("Node_Ada_Equal");break;
		case Node_Ada_Exception_Decl:printf("Node_Ada_Exception_Decl");break;
		case Node_Ada_Exception_Handler:printf("Node_Ada_Exception_Handler");break;
		case Node_Ada_Except_Choice_s:printf("Node_Ada_Except_Choice_s");break;
		case Node_Ada_Except_Handler_Part:printf("Node_Ada_Except_Handler_Part");break;
		case Node_Ada_Exclusive_Or:printf("Node_Ada_Exclusive_Or");break;
		case Node_Ada_Exit:printf("Node_Ada_Exit");break;
		case Node_Ada_Fixed_Type:printf("Node_Ada_Fixed_Type");break;
		case Node_Ada_Float_Type:printf("Node_Ada_Float_Type");break;
		case Node_Ada_Generic:printf("Node_Ada_Generic");break;
		case Node_Ada_Generic_Decl:printf("Node_Ada_Generic_Decl");break;
		case Node_Ada_Generic_Derived_Type:printf("Node_Ada_Generic_Derived_Type");break;
		case Node_Ada_Generic_Derived_Type_Abstract_Private:printf("Node_Ada_Generic_Derived_Type_Abstract_Private");break;
		case Node_Ada_Generic_Derived_Type_Private:printf("Node_Ada_Generic_Derived_Type_Private");break;
		case Node_Ada_Generic_Discrim_Part_Opt:printf("Node_Ada_Generic_Discrim_Part_Opt");break;
		case Node_Ada_Generic_Formal:printf("Node_Ada_Generic_Formal");break;
		case Node_Ada_Generic_Formal_Package:printf("Node_Ada_Generic_Formal_Package");break;
		case Node_Ada_Generic_Formal_Package_Box:printf("Node_Ada_Generic_Formal_Package_Box");break;
		case Node_Ada_Generic_Formal_Part:printf("Node_Ada_Generic_Formal_Part");break;
		case Node_Ada_Generic_Formal_Procedure:printf("Node_Ada_Generic_Formal_Procedure");break;
		case Node_Ada_Generic_Inst:printf("Node_Ada_Generic_Inst");break;
		case Node_Ada_Generic_Package_Inst:printf("Node_Ada_Generic_Package_Inst");break;
		case Node_Ada_Generic_Subprog_Inst:printf("Node_Ada_Generic_Subprog_Inst");break;
		case Node_Ada_Generic_Subp_Inst:printf("Node_Ada_Generic_Subp_Inst");break;
		case Node_Ada_Generic_Type_Def:printf("Node_Ada_Generic_Type_Def");break;
		case Node_Ada_Generic_Type_Def_Box:printf("Node_Ada_Generic_Type_Def_Box");break;
		case Node_Ada_Goto:printf("Node_Ada_Goto");break;
		case Node_Ada_Guarded_Select_Alt:printf("Node_Ada_Guarded_Select_Alt");break;
		case Node_Ada_Handler_Statement:printf("Node_Ada_Handler_Statement");break;
		case Node_Ada_If:printf("Node_Ada_If");break;
		case Node_Ada_In:printf("Node_Ada_In");break;
		case Node_Ada_Index:printf("Node_Ada_Index");break;
		case Node_Ada_Indexed_Comp:printf("Node_Ada_Indexed_Comp");break;
		case Node_Ada_Initialisation_Option:printf("Node_Ada_Initialisation_Option");break;
		case Node_Ada_Integer_Type:printf("Node_Ada_Integer_Type");break;
		case Node_Ada_Iteration:printf("Node_Ada_Iteration");break;
		case Node_Ada_Iterative_Part:printf("Node_Ada_Iterative_Part");break;
		case Node_Ada_Label:printf("Node_Ada_Label");break;
		case Node_Ada_Label_Loop:printf("Node_Ada_Label_Loop");break;
		case Node_Ada_Limited:printf("Node_Ada_Limited");break;
		case Node_Ada_List_Alternative:printf("Node_Ada_List_Alternative");break;
		case Node_Ada_List_Choice:printf("Node_Ada_List_Choice");break;
		case Node_Ada_List_Component_Decl:printf("Node_Ada_List_Component_Decl");break;
		case Node_Ada_List_Condition_Clause:printf("Node_Ada_List_Condition_Clause");break;
		case Node_Ada_List_C_Name:printf("Node_Ada_List_C_Name");break;
		case Node_Ada_List_Discrete_Range:printf("Node_Ada_List_Discrete_Range");break;
		case Node_Ada_List_Discrim_Spec:printf("Node_Ada_List_Discrim_Spec");break;
		case Node_Ada_List_Enumeration_Identifier:printf("Node_Ada_List_Enumeration_Identifier");break;
		case Node_Ada_List_Identifier:printf("Node_Ada_List_Identifier");break;
		case Node_Ada_List_Index:printf("Node_Ada_List_Index");break;
		case Node_Ada_List_Item_Decl:printf("Node_Ada_List_Item_Decl");break;
		case Node_Ada_List_Name:printf("Node_Ada_List_Name");break;
		case Node_Ada_List_Parameter:printf("Node_Ada_List_Parameter");break;
		case Node_Ada_List_Pragma:printf("Node_Ada_List_Pragma");break;
		case Node_Ada_List_Pragma_Arg:printf("Node_Ada_List_Pragma_Arg");break;
		case Node_Ada_List_Value:printf("Node_Ada_List_Value");break;
		case Node_Ada_List_Value2:printf("Node_Ada_List_Value2");break;
		case Node_Ada_List_Variant:printf("Node_Ada_List_Variant");break;
		case Node_Ada_Loop:printf("Node_Ada_Loop");break;
		case Node_Ada_Mark_Quote:printf("Node_Ada_Mark_Quote");break;
		case Node_Ada_Mark_Point:printf("Node_Ada_Mark_Point");break;
		case Node_Ada_Mod:printf("Node_Ada_Mod");break;
		case Node_Ada_Mode_Access:printf("Node_Ada_Mode_Access");break;
		case Node_Ada_Mod_Box:printf("Node_Ada_Mod_Box");break;
		case Node_Ada_Mode_In:printf("Node_Ada_Mode_In");break;
		case Node_Ada_Mode_In_Out:printf("Node_Ada_Mode_In_Out");break;
		case Node_Ada_Mode_Out:printf("Node_Ada_Mode_Out");break;
		case Node_Ada_Mod_Integer_Type:printf("Node_Ada_Mod_Integer_Type");break;
		case Node_Ada_Non_Equal:printf("Node_Ada_Non_Equal");break;
		case Node_Ada_Not:printf("Node_Ada_Not");break;
		case Node_Ada_Not_In:printf("Node_Ada_Not_In");break;
		case Node_Ada_Null:printf("Node_Ada_Null");break;
		case Node_Ada_Null_Record:printf("Node_Ada_Null_Record");break;
		case Node_Ada_Null_Statement:printf("Node_Ada_Null_Statement");break;
		case Node_Ada_Number_Decl:printf("Node_Ada_Number_Decl");break;
		case Node_Ada_Object_Decl:printf("Node_Ada_Object_Decl");break;
		case Node_Ada_Or:printf("Node_Ada_Or");break;
		case Node_Ada_Or_Else:printf("Node_Ada_Or_Else");break;
		case Node_Ada_Or_Select:printf("Node_Ada_Or_Select");break;
		case Node_Ada_Others:printf("Node_Ada_Others");break;
		case Node_Ada_Package_Body:printf("Node_Ada_Package_Body");break;
		case Node_Ada_Package_Decl:printf("Node_Ada_Package_Decl");break;
		case Node_Ada_Package_Spec:printf("Node_Ada_Package_Spec");break;
		case Node_Ada_Parameter:printf("Node_Ada_Parameter");break;
		case Node_Ada_Power:printf("Node_Ada_Power");break;
		case Node_Ada_Pragma:printf("Node_Ada_Pragma");break;
		case Node_Ada_Pragma_Arg:printf("Node_Ada_Pragma_Arg");break;
		case Node_Ada_Private:printf("Node_Ada_Private");break;
		case Node_Ada_Private_Part:printf("Node_Ada_Private_Part");break;
		case Node_Ada_Private_Type:printf("Node_Ada_Private_Type");break;
		case Node_Ada_Procedure_Call:printf("Node_Ada_Procedure_Call");break;
		case Node_Ada_Protected_Opt:printf("Node_Ada_Protected_Opt");break;
		case Node_Ada_Prot_Body:printf("Node_Ada_Prot_Body");break;
		case Node_Ada_Prot_Decl:printf("Node_Ada_Prot_Decl");break;
		case Node_Ada_Prot_Def:printf("Node_Ada_Prot_Def");break;
		case Node_Ada_Prot_Elem_Decl_s:printf("Node_Ada_Prot_Elem_Decl_s");break;
		case Node_Ada_Prot_Op_Body:printf("Node_Ada_Prot_Op_Body");break;
		case Node_Ada_Prot_Op_Body_s:printf("Node_Ada_Prot_Op_Body_s");break;
		case Node_Ada_Prot_Op_Decl:printf("Node_Ada_Prot_Op_Decl");break;
		case Node_Ada_Prot_Op_Decl_s:printf("Node_Ada_Prot_Op_Decl_s");break;
		case Node_Ada_Prot_Private_Opt:printf("Node_Ada_Prot_Private_Opt");break;
		case Node_Ada_Prot_Spec:printf("Node_Ada_Prot_Spec");break;
		case Node_Ada_Qualified:printf("Node_Ada_Qualified");break;
		case Node_Ada_Range:printf("Node_Ada_Range");break;
		case Node_Ada_Range_Box:printf("Node_Ada_Range_Box");break;
		case Node_Ada_Range_Constraint:printf("Node_Ada_Range_Constraint");break;
		case Node_Ada_Range_Inter:printf("Node_Ada_Range_Inter");break;
		case Node_Ada_Raise_Stmt:printf("Node_Ada_Raise_Stmt");break;
		case Node_Ada_Record_Definition:printf("Node_Ada_Record_Definition");break;
		case Node_Ada_Record_Type:printf("Node_Ada_Record_Type");break;
		case Node_Ada_Record_Type_Spec:printf("Node_Ada_Record_Type_Spec");break;
		case Node_Ada_Rem:printf("Node_Ada_Rem");break;
		case Node_Ada_Rename_Decl:printf("Node_Ada_Rename_Decl");break;
		case Node_Ada_Rename_Unit:printf("Node_Ada_Rename_Unit");break;
		case Node_Ada_Rename_Unit_Package:printf("Node_Ada_Rename_Unit_Package");break;
		case Node_Ada_Renames:printf("Node_Ada_Renames");break;
		case Node_Ada_Rep_Spec_s:printf("Node_Ada_Rep_Spec_s");break;
		case Node_Ada_Requeue_Stmt:printf("Node_Ada_Requeue_Stmt");break;
		case Node_Ada_Requeue_Stmt_With:printf("Node_Ada_Requeue_Stmt_With");break;
		case Node_Ada_Return:printf("Node_Ada_Return");break;
		case Node_Ada_Reverse:printf("Node_Ada_Reverse");break;
		case Node_Ada_Selected_Comp:printf("Node_Ada_Selected_Comp");break;
		case Node_Ada_Selected_Comp_All:printf("Node_Ada_Selected_Comp_All");break;
		case Node_Ada_Select_Alt:printf("Node_Ada_Select_Alt");break;
		case Node_Ada_Select_Wait:printf("Node_Ada_Select_Wait");break;
		case Node_Ada_Statement:printf("Node_Ada_Statement");break;
		case Node_Ada_Subp_Default:printf("Node_Ada_Subp_Default");break;
		case Node_Ada_Subprog_Body:printf("Node_Ada_Subprog_Body");break;
		case Node_Ada_Subprog_Decl:printf("Node_Ada_Subprog_Decl");break;
		case Node_Ada_Subprog_Spec:printf("Node_Ada_Subprog_Spec");break;
		case Node_Ada_Subtype_Decl:printf("Node_Ada_Subtype_Decl");break;
		case Node_Ada_Subtype_Indication:printf("Node_Ada_Subtype_Indication");break;
		case Node_Ada_Subunit:printf("Node_Ada_Subunit");break;
		case Node_Ada_Tagged:printf("Node_Ada_Tagged");break;
		case Node_Ada_Task_Body:printf("Node_Ada_Task_Body");break;
		case Node_Ada_Task_Decl:printf("Node_Ada_Task_Decl");break;
		case Node_Ada_Task_Def:printf("Node_Ada_Task_Def");break;
		case Node_Ada_Task_Private_Opt:printf("Node_Ada_Task_Private_Opt");break;
		case Node_Ada_Task_Spec:printf("Node_Ada_Task_Spec");break;
		case Node_Ada_Timed_Entry_Call:printf("Node_Ada_Timed_Entry_Call");break;
		case Node_Ada_Type_Decl:printf("Node_Ada_Type_Decl");break;
		case Node_Ada_Unconstraint_Array_Type:printf("Node_Ada_Unconstraint_Array_Type");break;
		case Node_Ada_Use_Clause:printf("Node_Ada_Use_Clause");break;
		case Node_Ada_Use_Clause_Type:printf("Node_Ada_Use_Clause_Type");break;
		case Node_Ada_Value2:printf("Node_Ada_Value2");break;
		case Node_Ada_Variant:printf("Node_Ada_Variant");break;
		case Node_Ada_Variant_Part:printf("Node_Ada_Variant_Part");break;
		case Node_Ada_Variant_Part_Optional:printf("Node_Ada_Variant_Part_Optional");break;
		case Node_Ada_When:printf("Node_Ada_When");break;
		case Node_C_Access_Type_Decl:printf("Node_C_Access_Type_Decl");break;
		case Node_C_Access_Subprog_Type_Decl:printf("Node_C_Access_Subprog_Type_Decl");break;
		case Node_C_Affect:printf("Node_C_Affect");break;
		case Node_C_And:printf("Node_C_And");break;
		case Node_C_Array_Comp:printf("Node_C_Array_Comp");break;
		case Node_C_Array_Type:printf("Node_C_Array_Type");break;
		case Node_C_Basic_Loop:printf("Node_C_Basic_Loop");break;
		case Node_C_Block:printf("Node_C_Block");break;
		case Node_C_Break:printf("Node_C_Break");break;
		case Node_C_Case:printf("Node_C_Case");break;
		case Node_C_Comment:printf("Node_C_Comment");break;
		case Node_C_Comment_Block:printf("Node_C_Comment_Block");break;
		case Node_C_Comment_Bracket:printf("Node_C_Comment_Bracket");break;
		case Node_C_Comment_Line:printf("Node_C_Comment_Line");break;
		case Node_C_Component_Association:printf("Node_C_Component_Association");break;
		case Node_C_Component_Decl:printf("Node_C_Component_Decl");break;
		case Node_C_Condition_Clause:printf("Node_C_Condition_Clause");break;
		case Node_C_Constant:printf("Node_C_Constant");break;
		case Node_C_Default_Case:printf("Node_C_Default_Case");break;
		case Node_C_Define:printf("Node_C_Define");break;
		case Node_C_Derived_Type_Decl:printf("Node_C_Derived_Type_Decl");break;
		case Node_C_Else:printf("Node_C_Else");break;
		case Node_C_Enumeration_Type_Decl:printf("Node_C_Enumeration_Type_Decl");break;
		case Node_C_Equal:printf("Node_C_Equal");break;
		case Node_C_Exclusive_Or:printf("Node_C_Exclusive_Or");break;
		case Node_C_Float:printf("Node_C_Float");break;
		case Node_C_Handler_Statement:printf("Node_C_Handler_Statement");break;
		case Node_C_If:printf("Node_C_If");break;
		case Node_C_Include_Local:printf("Node_C_Include_Local");break;
		case Node_C_Initialisation_Option:printf("Node_C_Initialisation_Option");break;
		case Node_C_Int:printf("Node_C_Int");break;
		case Node_C_Iteration:printf("Node_C_Iteration");break;
		case Node_C_Iterative_Part:printf("Node_C_Iterative_Part");break;
		case Node_C_Labelled_Stmt:printf("Node_C_Labelled_Stmt");break;
		case Node_C_List_Condition_Clause:printf("Node_C_List_Condition_Clause");break;
		case Node_C_List_Discrete_Range:printf("Node_C_List_Discrete_Range");break;
		case Node_C_List_Parameter:printf("Node_C_List_Parameter");break;
		case Node_C_Loop:printf("Node_C_Loop");break;
		case Node_C_Mark:printf("Node_C_Mark");break;
		case Node_C_Mod:printf("Node_C_Mod");break;
		case Node_C_Namespace_Def:printf("Node_C_Namespace_Def");break;
		case Node_C_Non_Equal:printf("Node_C_Non_Equal");break;
		case Node_C_Not:printf("Node_C_Not");break;
		case Node_C_Object_Decl:printf("Node_C_Object_Decl");break;
		case Node_C_Or:printf("Node_C_Or");break;
		case Node_C_Parameter:printf("Node_C_Parameter");break;
		case Node_C_Post_Less:printf("Node_C_Post_Less");break;
		case Node_C_Post_Plus:printf("Node_C_Post_Plus");break;
		case Node_C_Power:printf("Node_C_Power");break;
		case Node_C_Private_Part:printf("Node_C_Private_Part");break;
		case Node_C_Spaced:printf("Node_C_Spaced");break;
		case Node_C_Star:printf("Node_C_Star");break;
		case Node_C_Structured_Type_Decl:printf("Node_C_Structured_Type_Decl");break;
		case Node_C_Subprog_Body:printf("Node_C_Subprog_Body");break;
		case Node_C_Subprog_Spec:printf("Node_C_Subprog_Spec");break;
		case Node_C_Switch:printf("Node_C_Switch");break;
		case Node_C_Unconstraint_Array_Type:printf("Node_C_Unconstraint_Array_Type");break;
		case Node_C_Using_Namespace:printf("Node_C_Using_Namespace");break;
		case Node_C_While:printf("Node_C_While");break;
		default : printf("ERROR : %s %i : Node type %i is not manage\n",__FILE__,__LINE__,p_NodeType);
	}
}

/*****************************************************************************
 * Class name : comment
 * Description : class which is the representation of a comment list
 *****************************************************************************/
//Display
void comment::display(void)
{
	this->checkIntegrity(__FILE__,__LINE__);
	printf("%i   %s\n",m_NumLine,m_CommentText);
	if(m_Next!=NULL)
	{
		m_Next->display();
	}
}

// Access method to member fields
int comment::getNumLine(void)
{
	return m_NumLine;
}

const char* comment::getCommentText(void)
{
	return m_CommentText;
}


comment* comment::getNext(void)
{
	return m_Next;
}

// method which return the reference on the last comment
comment* comment::getLastComment(void)
{
	comment *result=this;
	
	if(m_Next!=NULL)
	{
		result=m_Next;
		while(result->m_Next!=NULL)
		{
			result=result->m_Next;
		}
	}
	return result;
}	
	
// method to add a new comment
void comment::addComment(comment *p_Comment)
{
	if(m_Next!=NULL)
	{
		m_Next->addComment(p_Comment);
	}
	else
	{
		m_Next=p_Comment;
	}
}

void comment::setNextToNull(void)
{
	m_Next=NULL;
}
// check integrity
void comment::checkIntegrity(const char *p_FileName, int p_NumLine)
{
	int error=0;
	if(m_NumLine<0)
	{
		printf("ERROR : %s %i : NumLine = %i\n",p_FileName,p_NumLine,m_NumLine);
		error=1;
	}
	if(m_CommentText==NULL)
	{
		printf("ERROR : %s %i : \"m_CommentText\" is NULL\n",__FILE__,__LINE__);
		error=1;
	}
	
	if(error!=0)
	{
		exit(-1);
	}
	
	
}

//constructor
comment::comment(int p_NumLine,const char *p_CommentText)
{
	
	m_NumLine=p_NumLine;
	m_CommentText=p_CommentText;
	m_Next=NULL;
	this->checkIntegrity(__FILE__,__LINE__);
	
}

/*****************************************************************************
 * Class name : tree
 * Description : class which is the representation of abstract tree
 *****************************************************************************/
// Access method to member fields
t_NodeType tree::getNodeType(void)
{
	return m_NodeType;
}

int tree::getNbSon(void)
{
	return m_NbSon;
}

int tree::getNumLine(void)
{
	return m_NumLine;
}

tree* tree::getSon(int p_NumSon)
{
	int error=0;
	if(p_NumSon>=m_NbSon)
	{
		printf("ERROR  %s %i : asked son number is higher than son number : %i >= %i for ",__FILE__,__LINE__,p_NumSon,m_NbSon);
		displayNodeType(m_NodeType);
		printf("\n   %s\n", getString());
		error=1;
	}
	if(m_Sons==NULL)
	{
		printf("ERROR : %s %i : \"m_Sons\" is NULL    Line %i\n",__FILE__,__LINE__, m_NumLine);
		error=1;
	}
	else if (error == 0)
	{
		if(m_Sons[p_NumSon]==NULL)
		{
			printf("ERROR  %s %i : m_Sons[%i] is NULL\n",__FILE__,__LINE__,p_NumSon);
			error=1;
		}
	}
	if(error!=0)
	{
		exit(-1);
	}
	return m_Sons[p_NumSon];
}

unit* tree::getTableSymbolMember(void)
{
	if(m_TableSymbolMember==0)
	{
		printf("ERROR : %s %i : \"m_TableSymbolMember\" is NULL\n",__FILE__,__LINE__);
		exit(-1);
	}
	return m_TableSymbolMember;
}

const char* tree::getString(void)
{
	return m_String;
}

int tree::getInteger(void)
{
	return m_Integer;
}

double tree::getFloat(void)
{
	return m_Float;
}

comment* tree::getComment(void)
{
	return m_Comment;
}

//method to find a node with its type
tree* tree::findNode(t_NodeType p_NodeType)
{
	#ifdef TRACE
	printfTraceUp("findNode",__FILE__,__LINE__);
	#endif
	tree *result=NULL;
	if(m_NodeType==p_NodeType)
	{
		result=this;
	}
	
	int index=0;
	while(index<m_NbSon && result==NULL)
	{
		result=m_Sons[index]->findNode(p_NodeType);
		index++;
	}
	
	#ifdef TRACE
	printfTraceDown("findNode",__FILE__,__LINE__);
	#endif
	return result;
	
}

// method to extract comments froms a tree
comment* tree::extractComments(void)
{
	this->checkIntegrity(__FILE__,__LINE__);
	
	// recuperation of node comments
	comment *result=m_Comment;
	
	//deletion of node comments
	m_Comment=NULL;
	
	//current is initalized with the beginning of comment list
	comment *current=result;
	
	//sons are analysis
	for(int i=0;i<m_NbSon;i++)
	{
		//comments are added at the end of the list
		if(result!=NULL)
		{
			current=result->getLastComment();
			current->addComment(m_Sons[i]->extractComments());
		}
		else
		{
			result=m_Sons[i]->extractComments();
		}
		
	}

	return result;
}
	
// method to set autohrized member fields
void tree::setInteger(int p_Integer)
{
	m_Integer=p_Integer;
}

void tree::setFloat(float p_Float)
{
	m_Float=p_Float;
}

void tree::setString(const char *p_String)
{
	m_String=p_String;
}
	
void tree::setSon(int p_NumSon,tree *p_Tree)
{
	int error=0;
	
	if(p_NumSon>=m_NbSon)
	{
		printf("ERROR  %s %i : asked son number is higher than son number : %i >= %i\n",__FILE__,__LINE__,p_NumSon,m_NbSon);
		error=1;
	}
	if(m_Sons==NULL)
	{
		printf("ERROR : %s %i : \"m_Sons\" is NULL\n",__FILE__,__LINE__);
		error=1;
	}
	else if(error == 0)
	{
		if(m_Sons[p_NumSon]==NULL)
		{
			printf("ERROR  %s %i : m_Sons[%i] is NULL\n",__FILE__,__LINE__,p_NumSon);
			error=1;
		}
	}
	if(error!=0)
	{
		exit(-1);
	}
	
	m_Sons[p_NumSon]=p_Tree;
}

void tree::setTableSymbolMember(unit *p_TableSymbolMember)
{
	if(p_TableSymbolMember==0)
	{
		printf("ERROR : %s %i : \"p_TableSymbolMember\" is NULL\n",__FILE__,__LINE__);
		exit(-1);
	}
	m_TableSymbolMember=p_TableSymbolMember;
}

// method to add comment to a Node
void tree::addComment(comment *p_Comment)
{
	if(m_Comment!=NULL)
	{
		m_Comment->addComment(p_Comment);
	}
	else
	{
		m_Comment=p_Comment;
	}
}

// method to puts correctly placed comments on tree
comment* tree::setComments(comment *p_Comments)
{
	this->checkIntegrity(__FILE__,__LINE__);
	
	comment *newComment=p_Comments;
	
	// test if comment can be attcached to this node
	if(p_Comments->getNumLine()<=m_NumLine)
	{
		comment *current=p_Comments;
		int continu=1;
		
		while(continu)
		{
			if(current->getNext()!=NULL)
			{
				if(current->getNext()->getNumLine()<=m_NumLine)
				{
					current=current->getNext();	
				}
				else
				{
					newComment=current->getNext();
					current->setNextToNull();
					continu=0;
				}
			}
			else
			{
				continu=0;
				newComment=NULL;
					
			}
		}
		m_Comment=p_Comments;
	}
	
	
		for(int i=0;i<m_NbSon;i++)
		{
			if(newComment!=NULL)
			{
				newComment=m_Sons[i]->setComments(newComment);
			}
		}
	return newComment;
	
	
}

// method to redistribute comments on tree
void tree::redistributeComments(void)
{
	#ifdef TRACE
	printfTraceUp("redistributeComments",__FILE__,__LINE__);
	#endif
	
	comment *c=this->extractComments();
	if(c!=NULL)
	{
		this->setComments(c);
	}
	
	#ifdef TRACE
	printfTraceDown("redistributeComments",__FILE__,__LINE__);
	#endif
	
	
}
		
// Check integrity
void tree::checkIntegrity(const char *p_FileName,int p_LineNumber)
{
	int error=0;
	if(m_NumLine<0)
	{
		printf("ERROR : %s %i : line number is %i \n",p_FileName,p_LineNumber,m_NumLine);
		error=1;
	}
	
	if(m_NbSon==0 && m_Sons!=NULL)
	{
		printf("ERROR : %s %i : m_NbSon = 0 and m_Sons != NULL\n",p_FileName,p_LineNumber,m_NumLine);
		error=1;
	}
	
	if(m_NbSon!=0 && m_Sons==NULL)
	{
		printf("ERROR : %s %i : m_NbSon != 0 and m_Sons == NULL\n",p_FileName,p_LineNumber,m_NumLine);
		error=1;
	}
	
	
	if(m_Sons!=NULL)
	{
		for(int i=0;i<m_NbSon;i++)
		{
			if(m_Sons[i]==NULL)
			{
				printf("ERROR : %s %i : son number %i is NULL\n",p_FileName,p_LineNumber,i);
				error=1;
			}
		}
	}
	if(error!=0)
	{
		exit(-1);
	}
}
	 
//Display
void tree::display(void)
{
	printf("NodeType : ");
	displayNodeType(m_NodeType);
	printf("\nNb son : %i\nNum Line : %i\n",m_NbSon,m_NumLine);
	if(m_String!=NULL)
	{
		printf("String : %s\n",m_String);
	}
	printf("Integer : %i\n",m_Integer);
	printf("Real : %f\n",m_Float);
	
	
}

void tree::displayTree(int p_Level)
{
	this->checkIntegrity(__FILE__,__LINE__);
	
	if(m_Comment!=NULL)
	{
		m_Comment->display();
	}
	
	for(int i=0;i<p_Level;i++)
	{
		printf(". ");
	}
	displayNodeType(m_NodeType);
	
	if(/*m_NodeType==Node_Ada_C_Ident && */m_String!=NULL)
	{
		printf(" %s",m_String);
	}
	
	if(m_NumLine!=0)
	{
		printf("   -- ligne %i",m_NumLine);
	}
	printf("\n");
	
	for(int i=0;i<m_NbSon;i++)
	{
		m_Sons[i]->displayTree(p_Level+1);
	}
	
}

// Constructors
tree::tree(int p_NumLine)
{
	m_NodeType=Node_Ada_C_Undefined;
	m_NbSon=0;
	m_NumLine=p_NumLine;
	m_Sons=NULL;
	m_String=NULL;
	m_Integer=0;
	m_Float=0.0; 
	m_Comment=NULL;
	m_TableSymbolMember=0;
}

tree::tree(t_NodeType p_NodeType,int p_NumLine)
{
	m_NodeType=p_NodeType;
	m_NbSon=0;
	m_NumLine=p_NumLine;
	m_Sons=NULL;
	m_String=NULL;
	m_Integer=0;
	m_Float=0.0; 
	m_Comment=NULL;
	m_TableSymbolMember=0;
}

tree::tree(t_NodeType p_NodeType, tree *p_Son1, int p_NumLine)
{
	m_NodeType=p_NodeType;
	m_NbSon=1;
	m_NumLine=p_NumLine;
	
	m_Sons=(tree**)malloc(1*sizeof(tree *));
	if(m_Sons==NULL)
	{
		printf("ERROR : %s %i : Memory allocation has failed\n",__FILE__,__LINE__);
		exit(-1);
	}
	m_Sons[0]=p_Son1;
	this->checkIntegrity(__FILE__,__LINE__);
	
	m_String=NULL;
	m_Integer=0;
	m_Float=0.0;
	m_Comment=NULL;
	m_TableSymbolMember=0;
}

tree::tree(t_NodeType p_NodeType, tree *p_Son1, tree *p_Son2, int p_NumLine)
{
	m_NodeType=p_NodeType;
	m_NbSon=2;
	m_NumLine=p_NumLine;
	
	m_Sons=(tree**)malloc(2*sizeof(tree *));
	if(m_Sons==NULL)
	{
		printf("ERROR : %s %i : Memory allocation has failed\n",__FILE__,__LINE__);
		exit(-1);
	}
	m_Sons[0]=p_Son1;
	m_Sons[1]=p_Son2;
	this->checkIntegrity(__FILE__,__LINE__);
	
	
	m_String=NULL;
	m_Integer=0;
	m_Float=0.0;
	m_Comment=NULL;
	m_TableSymbolMember=0;
}

tree::tree(t_NodeType p_NodeType, tree *p_Son1, tree *p_Son2, tree *p_Son3, int p_NumLine)
{
	m_NodeType=p_NodeType;
	m_NbSon=3;
	m_NumLine=p_NumLine;
	
	m_Sons=(tree**)malloc(3*sizeof(tree *));
	if(m_Sons==NULL)
	{
		printf("ERROR : %s %i : Memory allocation has failed\n",__FILE__,__LINE__);
		exit(-1);
	}
	m_Sons[0]=p_Son1;
	m_Sons[1]=p_Son2;
	m_Sons[2]=p_Son3;
	this->checkIntegrity(__FILE__,__LINE__);
	
	
	m_String=NULL;
	m_Integer=0;
	m_Float=0.0;
	m_Comment=NULL;
	m_TableSymbolMember=0;
}

tree::tree(t_NodeType p_NodeType, tree *p_Son1, tree *p_Son2, tree *p_Son3, tree *p_Son4, int p_NumLine)
{
	m_NodeType=p_NodeType;
	m_NbSon=4;
	m_NumLine=p_NumLine;
	
	m_Sons=(tree**)malloc(4*sizeof(tree *));
	if(m_Sons==NULL)
	{
		printf("ERROR : %s %i : Memory allocation has failed\n",__FILE__,__LINE__);
		exit(-1);
	}
	m_Sons[0]=p_Son1;
	m_Sons[1]=p_Son2;
	m_Sons[2]=p_Son3;
	m_Sons[3]=p_Son4;
	this->checkIntegrity(__FILE__,__LINE__);
	
	
	m_String=NULL;
	m_Integer=0;
	m_Float=0.0;
	m_Comment=NULL;
	m_TableSymbolMember=0;
}

tree::tree(t_NodeType p_NodeType, tree *p_Son1, tree *p_Son2, tree *p_Son3, tree *p_Son4, tree *p_Son5, int p_NumLine)
{
	m_NodeType=p_NodeType;
	m_NbSon=5;
	m_NumLine=p_NumLine;
	
	m_Sons=(tree**)malloc(5*sizeof(tree *));
	if(m_Sons==NULL)
	{
		printf("ERROR : %s %i : Memory allocation has failed\n",__FILE__,__LINE__);
		exit(-1);
	}
	m_Sons[0]=p_Son1;
	m_Sons[1]=p_Son2;
	m_Sons[2]=p_Son3;
	m_Sons[3]=p_Son4;
	m_Sons[4]=p_Son5;
	this->checkIntegrity(__FILE__,__LINE__);
	
	
	m_String=NULL;
	m_Integer=0;
	m_Float=0.0;
	m_Comment=NULL;
	m_TableSymbolMember=0;
}

tree::tree(t_NodeType p_NodeType, tree *p_Son1, tree *p_Son2, tree *p_Son3, tree *p_Son4, tree *p_Son5, tree *p_Son6, int p_NumLine)
{
	m_NodeType=p_NodeType;
	m_NbSon=6;
	m_NumLine=p_NumLine;
	
	m_Sons=(tree**)malloc(6*sizeof(tree *));
	if(m_Sons==NULL)
	{
		printf("ERROR : %s %i : Memory allocation has failed\n",__FILE__,__LINE__);
		exit(-1);
	}
	m_Sons[0]=p_Son1;
	m_Sons[1]=p_Son2;
	m_Sons[2]=p_Son3;
	m_Sons[3]=p_Son4;
	m_Sons[4]=p_Son5;
	m_Sons[5]=p_Son6;
	this->checkIntegrity(__FILE__,__LINE__);
	
	
	m_String=NULL;
	m_Integer=0;
	m_Float=0.0;
	m_Comment=NULL;
	m_TableSymbolMember=0;
}

// Special constructors
tree::tree(t_NodeType p_NodeType, int p_NumLine, const char *p_String)
{
	if(p_String==NULL)
	{
		printf("ERROR : %s %i : \"p_String\" is NULL\n",__FILE__,__LINE__);
		exit(-1);
	}
	
	m_NodeType=p_NodeType;
	m_NbSon=0;
	m_NumLine=p_NumLine;
	m_Sons=NULL;
	m_String=p_String;
	m_Integer=0;
	m_Float=0.0;
	m_Comment=NULL;
	m_TableSymbolMember=0;
}


/****************************************
 * class treeInteger
 ****************************************/
treeInteger::treeInteger(int p_NumLine, const char * p_String):tree(Node_Ada_C_Integer,p_NumLine,p_String)
{
	if(p_String==NULL)
	{
		printf("ERROR : %s %i : \"p_String\" is NULL\n",__FILE__,__LINE__);
		exit(-1);
	}
	
	setInteger(atoi(p_String));
}
		
/****************************************
 * class treeFloat
 ****************************************/
treeFloat::treeFloat(int p_NumLine, const char * p_String):tree(Node_Ada_C_Float,p_NumLine,p_String)
{
	if(p_String==NULL)
	{
		printf("ERROR : %s %i : \"p_String\" is NULL\n",__FILE__,__LINE__);
		exit(-1);
	}
	
	setFloat(atof((char *)strdup(p_String)));
	setString((char *)strdup(p_String));
}

/****************************************
 * class treeBased
 ****************************************/
treeBased::treeBased(int p_NumLine, const char * p_String):tree(Node_Ada_C_Based_Number,p_NumLine,p_String)
{
	if(p_String==NULL)
	{
		printf("ERROR : %s %i : \"p_String\" is NULL\n",__FILE__,__LINE__);
		exit(-1);
	}
	
	/*char *p_diese=strchr(p_String,'#');
	m_Base=atoi((char *)strdup(p_String));
	setFloat((double)strtol(p_diese+1,NULL,m_Base));
	setString((char *)strdup(p_String));//reel;
	printf("%s %i : based tree : base = %i\t value = %f\tbased value = %s %s\n",__FILE__,__LINE__,m_Base,getFloat(),getString(),p_diese+1);*/

	int l_Exponent=0;
	double m_IntegerPart=0;
	double m_FloatPart=0;
	
	// Cop of p_String parameter to work on local copy
	char *l_String = removeChar(p_String,'_');

	// extraction of base
	m_Base=atoi(l_String);

	// Search of first #
	char *l_Diese=strchr(l_String,'#');
	// Search of second #
	char *l_Diese2=strchr(l_Diese+1,'#');
	
	// Extraction of based value placed between '#' characters
	char *l_BasedValue=(char*)malloc((l_Diese2-l_Diese)*sizeof(char));
	for(int l_Index=0;*(l_Diese+l_Index+1)!='#';l_Index++)
	{
		l_BasedValue[l_Index]=*(l_Diese+l_Index+1);
	}
	l_BasedValue[l_Diese2-l_Diese-1]='\0';


	// check if p_diese reference the end of the string to determine the exponent
	if(*(l_Diese2+1)!='\0')
	{
		l_Exponent=atoi(l_Diese2+2);

	}
	
	if(l_Exponent!=0)
	{
		char *l_PosPoint=strchr(l_BasedValue,'.');
		if(l_PosPoint!=NULL)
		{
			int l_IndexPoint=l_PosPoint-l_BasedValue;
			
			// computation of number of digits after the '.' character
			int l_NbDigit=strlen(l_BasedValue)-l_IndexPoint-1;
				
			for(int l_Index=l_IndexPoint;l_Index<strlen(l_BasedValue);l_Index++)
			{
				l_BasedValue[l_Index]=l_BasedValue[l_Index+1];
			}
			l_BasedValue[strlen(l_BasedValue)]='0';
			l_Exponent-=l_NbDigit+1;
		}

		// There is no more decimal point
		if(l_Exponent>0)
		{
			// exponent is positive and not NULL
			// -> add of m_Exponent '0' at the end of l_BasedValue string
			// *********************************************************/

			// length of new string is stocked
			int l_Size=strlen(l_BasedValue)+1+l_Exponent;
			
			// memory allocation for new string
			l_BasedValue=(char*)realloc(l_BasedValue,l_Size*sizeof(char));
			
			// Add of '0' characters
			for(int l_Index=0;l_Index<l_Exponent;l_Index++)
			{
				l_BasedValue[l_Size-2-l_Index]='0';
			}
			
			// Add of '\0' character at the end of l_BasedValue string
			l_BasedValue[l_Size-1]='\0';
		}
		if(l_Exponent<0)
		{
			// exponent is negative and not NULL
			int l_Strlen=strlen(l_BasedValue);
			
			int l_Diff=l_Strlen+l_Exponent;
			
			// there is an integer part
			if(l_Diff>0)
			{
				l_Diff=0;
			}

				// add of a point at l_Strlen+m_Exponent
				l_BasedValue=(char*)realloc(l_BasedValue,(l_Strlen+2+l_Diff)*sizeof(char));
				for(int l_Index=0;l_Index<=-l_Exponent+l_Diff;l_Index++)
				{
					l_BasedValue[l_Strlen-l_Index+1-l_Diff]=l_BasedValue[l_Strlen-l_Index];
				}
				for(int l_Index=0;l_Index<-l_Diff;l_Index++)
				{
					l_BasedValue[l_Index+1]='0';
				}

				l_BasedValue[l_Strlen+l_Exponent-l_Diff]='.';
			
		}
		l_Exponent=0;
	}

	// extraction of integer based value
	m_IntegerPart=(double)strtol(l_BasedValue,NULL,m_Base);
	
	char *l_PosPoint=strchr(l_BasedValue,'.');
		
	// number of digit in floating part of based value
	int l_Size=0;

	// search of '.' character
	if( l_PosPoint != NULL)
	{
		// extraction of float based value
		m_FloatPart=(double)strtol(l_PosPoint+1,NULL,m_Base);
		l_Size = strlen(l_BasedValue)-(l_PosPoint-l_BasedValue)-1;
		m_FloatPart/=pow(m_Base,l_Size);
	}

	if(*(l_Diese+1)=='-')
	{
		setFloat(m_IntegerPart-m_FloatPart);
	}
	else
	{
		setFloat(m_IntegerPart+m_FloatPart);
	}
	
	// Copy of string in member string value
	setString(l_BasedValue);//reel;
	
	/*printf("%s %i : based tree : base = %i\n",__FILE__,__LINE__,m_Base);
	printf("%s %i : based tree : integer value = %f\n",__FILE__,__LINE__,m_IntegerPart);
	printf("%s %i : based tree : float value = %f\n",__FILE__,__LINE__,m_FloatPart);
	printf("%s %i : based tree : value = %f\n",__FILE__,__LINE__,getFloat());
	printf("%s %i : based tree : string = %s\n\n",__FILE__,__LINE__,getString());*/
}		

int treeBased::getBase(void)
{
	return m_Base;
}
