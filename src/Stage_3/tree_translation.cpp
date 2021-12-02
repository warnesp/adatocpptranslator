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
 * $Log: tree_translation.cpp,v $
 * Revision 1.4  2005/03/26 23:40:01  quicky2000
 * Update to improve management of comments in case where ada tree is not converted
 *
 * Revision 1.3  2005/03/19 13:18:16  quicky2000
 * Update to:
 * _ better manage comment blocks by avoiding to have enclosed comments
 * _ better manage constrained and unconstrained array types
 * _ manage ada based types
 *
 * Revision 1.2  2005/03/16 21:00:54  quicky2000
 * Update to remove a useless printf
 *
 * Revision 1.1  2005/03/08 00:01:35  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ modify the include paths due to new organisation of source files
 * _ maintain the code
 * _ add the function translationIndexedComp
 *
 * Revision 1.2  2005/03/03 23:02:28  quicky2000
 * Update to add translation of missing nodes
 *
 * Revision 1.1.1.1  2005/03/01 22:20:51  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "tree_translation.h"

#include "../Table_symbol/package.h"

#include "../Tools/value.h"

//#define TRACE_TREE_TRANSLATION

extern main_unit *g_CurrentMainUnit;

// Variable which indicate if current code is in a comment block:
//		0 : not in comment block
//		1 : in comment block
char g_InComment=0;

#define CREATE_COMMENT_BLOCK(param) if(!g_InComment)\
									{\
										g_InComment=1;\
										tree *l_Param=param;\
										l_Result=new tree(Node_C_Comment_Block,l_Param,l_Param->getNumLine());\
										g_InComment=0;\
									}\
									else\
									{\
										l_Result=param;\
									}

/* ========================================================================== */
/* PROTOTYPE DES SOUS PROGRAMMES INTERNES	                              */
/* ========================================================================== */

/*****************************************************************************
 * Function name : translationUnconstraintObjectArray 
 *
 * Input :	p_FpLog reference on a FILE
 * 		p_Name reference on a string
 * Output : package_spec* - reference on a package_spec
 * Modified variable : none
 * Description : Function which return a reference on the package spec
 * 	designed by parameter P_Name
 *****************************************************************************/
tree* translationUnconstraintObjectArray( FILE *p_FpLog, tree *p_Tree);


tree* translation(FILE *p_FpLog, tree *p_Tree)
{
	tree *l_Result = NULL;

	if( p_Tree!=NULL)
	{
		main_unit *l_MainUnitSave=g_CurrentMainUnit;
		
		t_NodeType nodeType=p_Tree->getNodeType();
		
		#ifdef TRACE_TREE_TRANSLATION
		displayNodeType( p_Tree->getNodeType() );
		printf(" : %i\n", p_Tree->getNumLine() );
		#endif
		switch( nodeType)
		{
			case Node_Ada_Abort_Stmt:
			CREATE_COMMENT_BLOCK(new tree( Node_Ada_Abort_Stmt, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() ))
			break;
			
			case Node_Ada_Abs:
			l_Result = new tree( Node_Ada_Indexed_Comp, new tree( Node_Ada_C_Ident, p_Tree->getNumLine(), "abs"), translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Abstract_Subprog_Decl:
			CREATE_COMMENT_BLOCK(new tree( Node_Ada_Abstract_Subprog_Decl, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() ))
			break;

			case Node_Ada_Abstract_Tagged:
			l_Result = new tree( Node_C_Comment_Bracket, p_Tree, p_Tree->getNumLine() );
			break;

			case Node_Ada_Accept_Hdr:
			l_Result = new tree( Node_Ada_Accept_Hdr, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Accept_Stmt:
			switch( p_Tree->getNbSon() )
			{
				case 1:CREATE_COMMENT_BLOCK(new tree( Node_Ada_Accept_Stmt, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() ))
				break;
				case 3:CREATE_COMMENT_BLOCK(new tree( Node_Ada_Accept_Stmt, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), translation( p_FpLog, p_Tree->getSon(2) ), p_Tree->getNumLine() ))
				break;
				default:
				errorNbSon(__FILE__,__LINE__, p_Tree);
				my_exit(-1);
				break;
			}
			break;
			
			case Node_Ada_Access:
			l_Result = new tree( Node_C_Comment_Bracket, p_Tree, p_Tree->getNumLine() );
			break;

			case Node_Ada_Address_Spec:
			l_Result = new tree( Node_C_Comment_Bracket, p_Tree, p_Tree->getNumLine() );
			break;

			case Node_Ada_Affect:
			l_Result = new tree( Node_C_Affect, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Aggregate:
			/* NOT MANAGE case WITH value_s */
			l_Result= new tree( Node_Ada_Aggregate, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Aggregate_Null_Record:
				switch(p_Tree->getNbSon())
				{
					case 0:
						l_Result = new tree( Node_C_Comment_Bracket, p_Tree, p_Tree->getNumLine() );
					break;
					case 1:
						l_Result = new tree( Node_C_Comment_Bracket, new tree( Node_Ada_Aggregate_Null_Record, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() ), p_Tree->getNumLine() );
					break;
					default:
						errorNbSon(__FILE__,__LINE__,p_Tree);
						my_exit(-1);
				}
			break;

			case Node_Ada_Aliased:
			errorLogManage( p_FpLog, p_Tree->getNumLine(), "aliased option");
			l_Result = new tree( Node_Ada_C_Empty, p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Aliased_Constant:
			errorLogManage( p_FpLog, p_Tree->getNumLine(), "aliased option");
			l_Result = new tree( Node_C_Constant, p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Align_Opt:
				l_Result = new tree( Node_C_Comment_Bracket, new tree( Node_Ada_Align_Opt, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() ),p_Tree, p_Tree->getNumLine());
			break;
			
			case Node_Ada_Allocator:
				l_Result = new tree( Node_C_Comment_Bracket, new tree( Node_Ada_Allocator, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() ),p_Tree, p_Tree->getNumLine());
			break;
			
			case Node_Ada_Alternative:
			{
				switch( p_Tree->getSon(0)->getNodeType() )
				{
					case Node_Ada_List_Choice:
					{
						tree *case1=NULL;
						tree *case2=NULL;
						switch( p_Tree->getNbSon() )
						{
							case 1:
							case1=new tree( Node_Ada_Alternative, p_Tree->getSon(0)->getSon(0), p_Tree->getNumLine() );
							case2=new tree( Node_Ada_Alternative, p_Tree->getSon(0)->getSon(1), p_Tree->getNumLine() );
							break;
							case 2:
							case1=new tree( Node_Ada_Alternative, p_Tree->getSon(0)->getSon(0), p_Tree->getNumLine() );
							case2=new tree( Node_Ada_Alternative, p_Tree->getSon(0)->getSon(1), p_Tree->getSon(1), p_Tree->getNumLine() );
							break;
							default:
							errorNbSon(__FILE__,__LINE__, p_Tree);
							my_exit(-1);
							break;
						}
						l_Result = new tree( Node_Ada_List_Alternative, translation( p_FpLog,case1), translation( p_FpLog,case2), p_Tree->getNumLine() );
					}
					break;
					case Node_Ada_Others:
					{
						switch( p_Tree->getNbSon() )
						{
							case 1:
							l_Result = new tree( Node_C_Default_Case, p_Tree->getNumLine() );
							break;
							case 2:
							l_Result = new tree( Node_C_Default_Case, translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
							break;
							default:
							errorNbSon(__FILE__,__LINE__, p_Tree);
							break;
						}
					}
					break;
					default:
					switch( p_Tree->getNbSon() )
					{
						case 1:
						l_Result = new tree( Node_C_Case, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() );
						break;
						case 2:
						l_Result = new tree( Node_C_Case, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
						break;
						default:
						errorNbSon(__FILE__,__LINE__, p_Tree);
						my_exit(-1);
						break;
					}
					break;
				}
			}
			break;
			
			case Node_Ada_And:
			l_Result = new tree( Node_C_And, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_C_And_Com:
			l_Result = new tree( Node_Ada_C_And_Com, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_And_Then:
			l_Result = new tree( Node_C_And, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Async_Select:
			CREATE_COMMENT_BLOCK(new tree( Node_Ada_Async_Select, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() ))
			break;
			
			case Node_Ada_Attrib_Def:
			CREATE_COMMENT_BLOCK(new tree( Node_Ada_Attrib_Def, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() ))
			break;
			
			case Node_Ada_Attribute:
			l_Result = new tree( Node_C_Comment_Bracket, new tree( Node_Ada_Attribute, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getSon(1), p_Tree->getNumLine() ) , p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Basic_Loop:
			l_Result = new tree( Node_C_Basic_Loop, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Block:
			l_Result = new tree( Node_C_Block, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), translation( p_FpLog, p_Tree->getSon(2) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Block_Body:
			l_Result = translation( p_FpLog, p_Tree->getSon(0) );
			break;
			
			case Node_Ada_Block_Decl:
			l_Result = translation( p_FpLog, p_Tree->getSon(0) );
			break;
			
			case Node_Ada_Body_Stub_Package:
			CREATE_COMMENT_BLOCK(new tree( Node_Ada_Body_Stub_Package, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() ))
			break;
			
			case Node_Ada_Body_Stub_Prot:
			CREATE_COMMENT_BLOCK(new tree( Node_Ada_Body_Stub_Prot, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() ))
			break;
			
			case Node_Ada_Body_Stub_SubProg:
			CREATE_COMMENT_BLOCK(new tree( Node_Ada_Body_Stub_SubProg, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() ))
			break;
			
			case Node_Ada_Body_Stub_Task:
			CREATE_COMMENT_BLOCK(new tree( Node_Ada_Body_Stub_Task, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() ))
			break;

			case Node_Ada_Case:
			l_Result = new tree( Node_C_Switch, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), translation( p_FpLog, p_Tree->getSon(2) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Code_Stmt:
			CREATE_COMMENT_BLOCK(new tree( Node_Ada_Code_Stmt, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() ))
			break;
			
			case Node_Ada_Clause_Use_Option:
			//CREATE_COMMENT_BLOCK(new tree( Node_Ada_Clause_Use_Option, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() ))
			l_Result= new tree( Node_Ada_Clause_Use_Option, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Clause_Width:
			if( p_Tree->getSon(0)->getNodeType() == Node_Ada_List_C_Name )
			{
				tree *l_ClauseWith1=new tree( Node_Ada_Clause_Width, p_Tree->getSon(0)->getSon(0), p_Tree->getNumLine() );
				tree *l_ClauseWith2=new tree( Node_Ada_Clause_Width, p_Tree->getSon(0)->getSon(1), p_Tree->getNumLine() );
				l_Result = new tree( Node_Ada_Context_Specification, translation( p_FpLog, l_ClauseWith1), translation( p_FpLog, l_ClauseWith2), p_Tree->getNumLine() );
			}
			else
			{
				file *l_File = NULL;
				int l_Error = 0;
				list<package_spec*> *l_PackageSpecList = getByName( getString( p_Tree->getSon(0) ), g_TableSymbol->getPackageSpecs() );
				if( l_PackageSpecList == NULL)
				{
					fprintf( p_FpLog, "line %i ( in ada file ) : package \"%s\" not found\n", p_Tree->getNumLine(), getString( p_Tree->getSon(0) ) );
					l_Error = 1;
				}
				else
				{
					if( l_PackageSpecList->getNbItem() != 1)
					{
						fprintf( p_FpLog, "line %i ( in ada file ) : search of package \"%s\" give several answers\n", p_Tree->getNumLine(), getString( p_Tree->getSon(0) ) );
						l_Error = 1;
					}
					else
					{
						char *l_FileName = myStrcat(3,deleteExtension( l_PackageSpecList->getItem()->getFile()->getName() ), ".", g_Config->getHeaderExtension() );
						l_Result = new tree( Node_C_Include_Local, new tree( Node_Ada_C_Ident, p_Tree->getNumLine(), l_FileName), p_Tree->getNumLine() );
					}
				}
				
				if( l_Error!=0)
				{
					l_Result = new tree( Node_C_Comment_Line, new tree( Node_C_Include_Local, p_Tree->getSon(0), p_Tree->getNumLine() ), p_Tree->getNumLine() );
				}
			}
			break;
			
			case Node_Ada_Component_Association:
			l_Result = new tree( Node_C_Component_Association, p_Tree->getSon(0), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );break;
			
			case Node_Ada_Component_Decl:
			{
				if( p_Tree->getSon(0)->getNodeType() != Node_Ada_List_Identifier)
				{
					l_Result = new tree( Node_C_Component_Decl, translation( p_FpLog, p_Tree->getSon(1) ), translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(2) ), p_Tree->getNumLine() );
				}
				else
				{
					tree *p_Component1=translation( p_FpLog, new tree( Node_Ada_Component_Decl, p_Tree->getSon(0)->getSon(0), p_Tree->getSon(1), p_Tree->getSon(2), p_Tree->getNumLine() ) );
					tree *p_Component2=translation( p_FpLog, new tree( Node_Ada_Component_Decl, p_Tree->getSon(0)->getSon(1), p_Tree->getSon(1), p_Tree->getSon(2), p_Tree->getNumLine() ) );
					l_Result = new tree( Node_Ada_List_Component_Decl, p_Component1, new tree( Node_Ada_C_Empty, p_Tree->getNumLine() ), p_Component2, p_Tree->getNumLine() );
				}
			}
			break;
			
			case Node_Ada_Component_List:
			{
				switch( p_Tree->getNbSon() )
				{
					case 1:
					l_Result = new tree( Node_C_Comment, p_Tree->getNumLine(), " null;");
					break;
					case 2:
					l_Result = new tree( Node_Ada_Component_List, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
					break;
					default:
					errorNbSon(__FILE__,__LINE__, p_Tree);
					my_exit(-1);
				}
			}
			break;
			
			case Node_Ada_Component_Subtype_Definition:
			if( p_Tree->getSon(0)->getNodeType() != Node_Ada_C_Empty)
			{
				errorLogManage( p_FpLog, p_Tree->getNumLine(), "aliased option");
			}
			l_Result = translation( p_FpLog, p_Tree->getSon(1) );
			break;
			
			case Node_Ada_Compound_Name:
			l_Result = new tree( Node_Ada_Compound_Name, p_Tree->getSon(0), p_Tree->getSon(1), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Comp_Loc_s:
				l_Result = new tree( Node_C_Comment_Bracket, p_Tree, p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Condition_Clause:
			l_Result = new tree( Node_C_Condition_Clause, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Cond_Entry_Call:
			CREATE_COMMENT_BLOCK(new tree( Node_Ada_Cond_Entry_Call, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), translation( p_FpLog, p_Tree->getSon(2) ), p_Tree->getNumLine() ))
			break;
			
			case Node_Ada_Constant:
			l_Result = new tree( Node_C_Constant, p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Context_Specification:
			{
				tree *p_Son0=translation( p_FpLog, p_Tree->getSon(0) );
				tree *p_Son1=translation( p_FpLog, p_Tree->getSon(1) );
				
				switch( p_Tree->getNbSon() )
				{
					case 2:
					l_Result = new tree( Node_Ada_Context_Specification, p_Son0, p_Son1, p_Tree->getNumLine() );
					break;
					case 3:
					{
						tree *p_Son2=translation( p_FpLog, p_Tree->getSon(2) );
						l_Result = new tree( Node_Ada_Context_Specification, p_Son0, p_Son1, p_Son2, p_Tree->getNumLine() );
					}
					break;
					default:
					errorNbSon(__FILE__,__LINE__, p_Tree);
					my_exit(-1);
					break;
				}
			}
			break;
			
			case Node_Ada_C_Based_Number:
			{
				treeBased *l_Tree=static_cast<treeBased*>(p_Tree);
				//CREATE_COMMENT_BLOCK(p_Tree)
				switch(l_Tree->getBase())
				{
					// octal numbers
					case 8:
					{
						char *l_String=NULL;
						
						if(((float)((int)p_Tree->getFloat())) == p_Tree->getFloat())
						{
							l_String=myStrcat(2,"0",l_Tree->getString());
						}
						else
						{
							l_String=(char*)malloc(100*sizeof(char));
							sprintf(l_String,"%f",p_Tree->getFloat());
						}
						l_Result=new tree(Node_Ada_C_Ident,p_Tree->getNumLine(),l_String);
					}
					break;
					// hexadecimal numbers
					case 16:
					{
						char *l_String=NULL;
						
						if(((float)((int)p_Tree->getFloat())) == p_Tree->getFloat())
						{
							l_String=myStrcat(2,"0x",l_Tree->getString());
						}
						else
						{
							l_String=(char*)malloc(100*sizeof(char));
							sprintf(l_String,"%f",p_Tree->getFloat());
						}
						l_Result=new tree(Node_Ada_C_Ident,p_Tree->getNumLine(),l_String);
					}
					break;
					// other numbers
					default:
					{
						char *l_String=(char*)malloc(100*sizeof(char));
						if(((float)((int)p_Tree->getFloat())) == p_Tree->getFloat())
						{
							sprintf(l_String,"%i",123);
						}
						else
						{
							sprintf(l_String,"%f",p_Tree->getFloat());
						}
						
						l_Result = new tree( Node_Ada_C_Ident, p_Tree->getNumLine(), l_String);
					}
					break;
				}
			}
			break;
			
			case Node_Ada_C_Compilation_Unit:
			{
				tree *p_Translated0=translation( p_FpLog, p_Tree->getSon(0) );;
				tree *p_Translated1=translation( p_FpLog, p_Tree->getSon(1) );;
				tree *p_Translated2=translation( p_FpLog, p_Tree->getSon(2) );;
				switch( p_Tree->getNbSon() )
				{
					case 3:
					l_Result = new tree( Node_Ada_C_Compilation_Unit, p_Translated0, p_Translated1, p_Translated2, p_Tree->getNumLine() );
					break;
					case 4:
					{
						tree *p_Translated3=translation( p_FpLog, p_Tree->getSon(3) );
						l_Result = new tree( Node_Ada_C_Compilation_Unit, p_Translated0, p_Translated1, p_Translated2, p_Translated3, p_Tree->getNumLine() );
					}
					break;
					default:
					errorNbSon(__FILE__,__LINE__, p_Tree);
					my_exit(-1);
					break;
				}
			}
			break;
			
			case Node_Ada_C_Div:
			l_Result = new tree( Node_Ada_C_Div, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_C_Empty:
			l_Result = new tree( Node_Ada_C_Empty, p_Tree->getNumLine() );
			break;
			
			case Node_Ada_C_Float:
			l_Result = new treeFloat( p_Tree->getNumLine(), p_Tree->getString() );
			break;
			
			case Node_Ada_C_Formal_Part:
			l_Result = new tree( Node_Ada_C_Formal_Part, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_C_Ident:
			l_Result = new tree( Node_Ada_C_Ident, p_Tree->getNumLine(), p_Tree->getString() );
			break;
			
			case Node_Ada_C_Integer:
			l_Result = new treeInteger( p_Tree->getNumLine(), p_Tree->getString() );
			break;
			
			case Node_Ada_C_Less:
			l_Result = new tree( Node_Ada_C_Less, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_C_Less_Equal:
			l_Result = new tree( Node_Ada_C_Less_Equal, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_C_List_Compilation_Unit:
			l_Result = new tree( Node_Ada_C_List_Compilation_Unit, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_C_List_Decl_Item_Or_Body:
			l_Result = new tree( Node_Ada_C_List_Decl_Item_Or_Body, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_C_List_Statement:
			{
				tree *l_Son0=translation( p_FpLog, p_Tree->getSon(0) );
				tree *l_Son1=translation( p_FpLog, p_Tree->getSon(1) );
				l_Result= new tree( Node_Ada_C_List_Statement, l_Son0, l_Son1, p_Tree->getNumLine() );
			}
			break;
			
			case Node_Ada_C_Minor:
			l_Result = new tree( Node_Ada_C_Minor, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_C_Mult:
			l_Result = new tree( Node_Ada_C_Mult, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_C_Parenthesized_Primary:
			l_Result = new tree( Node_Ada_C_Parenthesized_Primary, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_C_Plus:
			l_Result = new tree( Node_Ada_C_Plus, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_C_Program:
			g_CurrentMainUnit = ( main_unit* )p_Tree->getTableSymbolMember();
			l_Result = new tree( Node_Ada_C_Program, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_C_Quote_Char:
			l_Result = p_Tree;
			break;
				
			case Node_Ada_C_String:
			l_Result = p_Tree;
			break;
			
			case Node_Ada_C_Sup:
			l_Result = new tree( Node_Ada_C_Sup, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_C_Sup_Equal:
			l_Result = new tree( Node_Ada_C_Sup_Equal, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_C_Unary_Minor:
			l_Result = new tree( Node_Ada_C_Unary_Minor, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_C_Unary_Plus:
			l_Result = new tree( Node_Ada_C_Unary_Plus, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Decimal_Digits_Constraint:
				l_Result = new tree(Node_C_Comment_Bracket, p_Tree, p_Tree->getNumLine() );
			break;

			case Node_Ada_Delay_Or_Entry_Alt:
			l_Result = new tree( Node_Ada_Delay_Or_Entry_Alt, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Delay_Stmt:
			CREATE_COMMENT_BLOCK( new tree( Node_Ada_Delay_Stmt, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() ))
			break;
			
			case Node_Ada_Delay_Stmt_Until:
			CREATE_COMMENT_BLOCK( new tree( Node_Ada_Delay_Stmt_Until, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() ))
			break;
			
			case Node_Ada_Delta:
				l_Result = new tree( Node_C_Comment_Bracket, p_Tree, p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Delta_Box:
				l_Result = new tree( Node_C_Comment_Bracket, p_Tree, p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Delta_Box_Digits_Box:
				l_Result = new tree( Node_C_Comment_Bracket, p_Tree, p_Tree->getNumLine() );
			break;

			case Node_Ada_Digits:
				l_Result = new tree( Node_C_Comment_Bracket, p_Tree, p_Tree->getNumLine() );
			break;

			case Node_Ada_Digits_Box_Lex:
				l_Result = new tree( Node_C_Comment_Bracket, p_Tree, p_Tree->getNumLine() );
			break;

			case Node_Ada_Discrete_Range:
			l_Result = new tree( Node_C_Comment_Bracket, new tree( Node_Ada_Discrete_Range, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Discrete_With_Range:
			l_Result = new tree( Node_C_Comment_Bracket, new tree( Node_Ada_Discrete_With_Range, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Discrim_Part:
				l_Result = new tree( Node_C_Comment_Bracket, p_Tree, p_Tree->getNumLine() );
			break;

			case Node_Ada_Discrim_Part_Opt:
				l_Result = new tree( Node_C_Comment_Bracket, p_Tree, p_Tree->getNumLine() );
			break;

			case Node_Ada_Discrim_Spec:
				l_Result = new tree( Node_C_Comment_Bracket, p_Tree, p_Tree->getNumLine() );
			break;

			case Node_Ada_Else:
			l_Result = new tree( Node_C_Else, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Entry_Body:
				switch( p_Tree->getNbSon())
				{
					case 4:
						CREATE_COMMENT_BLOCK( new tree( Node_Ada_Entry_Body, translation( p_FpLog, p_Tree->getSon(0)), translation( p_FpLog, p_Tree->getSon(1)), translation( p_FpLog, p_Tree->getSon(2)), translation( p_FpLog, p_Tree->getSon(3)) , p_Tree->getNumLine() ))
					break;
					case 6:
						CREATE_COMMENT_BLOCK( new tree( Node_Ada_Entry_Body, translation( p_FpLog, p_Tree->getSon(0)), translation( p_FpLog, p_Tree->getSon(1)), translation( p_FpLog, p_Tree->getSon(2)), translation( p_FpLog, p_Tree->getSon(3)), translation( p_FpLog, p_Tree->getSon(4)), translation( p_FpLog, p_Tree->getSon(5)), p_Tree->getNumLine() ))
					break;
					default:
					errorNbSon(__FILE__,__LINE__,p_Tree);
					my_exit(-1);
					break;
				}
			break;
			
			case Node_Ada_Entry_Body_Part:
			switch( p_Tree->getNbSon())
				{
					case 0:
						l_Result = p_Tree;
					break;
					case 3:
						CREATE_COMMENT_BLOCK( new tree( Node_Ada_Entry_Body_Part, translation( p_FpLog, p_Tree->getSon(0)), translation( p_FpLog, p_Tree->getSon(1)), translation( p_FpLog, p_Tree->getSon(2)), p_Tree->getNumLine() ))
					break;
					default:
					errorNbSon(__FILE__,__LINE__,p_Tree);
					my_exit(-1);
					break;
				}
			break;
			
			case Node_Ada_Entry_Decl:
				switch(p_Tree->getNbSon())
				{
					case 2:
						l_Result = new tree( Node_C_Comment_Bracket, new tree( Node_Ada_Entry_Decl, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() ), p_Tree->getNumLine() );
					break;
					case 3:
						l_Result = new tree( Node_C_Comment_Bracket, new tree( Node_Ada_Entry_Decl, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ),  translation( p_FpLog, p_Tree->getSon(2) ), p_Tree->getNumLine() ), p_Tree->getNumLine() );
					break;
					default:
						errorNbSon(__FILE__,__LINE__,p_Tree);
					my_exit(-1);
				}
			break;
			
			case Node_Ada_Entry_Decl_s:
				l_Result = new tree( Node_Ada_Entry_Decl_s, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), translation( p_FpLog, p_Tree->getSon(2) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Entry_Name:
			l_Result = new tree( Node_Ada_Entry_Name, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Equal:
			l_Result = new tree( Node_C_Equal, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Except_Choice_s:
				l_Result = new tree( Node_C_Or, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Exception_Handler:
				switch(p_Tree->getNbSon())
				{
					case 2:
						l_Result = new tree( Node_C_Exception_Handler, translation( p_FpLog, p_Tree->getSon(0) ),  translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
					break;
					case 3:
						CREATE_COMMENT_BLOCK(p_Tree)
					break;
					default:
						errorNbSon(__FILE__,__LINE__,p_Tree);
						my_exit(-1);
					break;
				}
			break;

			case Node_Ada_Except_Handler_Part:
				switch(p_Tree->getNbSon())
				{
					case 1:
						l_Result = translation( p_FpLog, p_Tree->getSon(0) );
					break;
					case 2:
						l_Result = new tree( Node_Ada_C_List_Statement, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
					break;
					default:
						errorNbSon(__FILE__,__LINE__,p_Tree);
						my_exit(-1);
					break;
				}
			break;

			case Node_Ada_Exception_Decl:
			CREATE_COMMENT_BLOCK(p_Tree)
			break;

			case Node_Ada_Exclusive_Or:
			l_Result = new tree( Node_C_Exclusive_Or, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Exit:
			/* NOT MANAGE */
			l_Result = new tree( Node_C_Break, p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Generic:
			l_Result = p_Tree;
			break;

			case Node_Ada_Generic_Decl:
			//CREATE_COMMENT_BLOCK( new tree( Node_Ada_Generic_Decl, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() ), p_Tree->getNumLine() );
				CREATE_COMMENT_BLOCK(p_Tree)
			break;
			
			case Node_Ada_Generic_Derived_Type:
					l_Result = new tree( Node_C_Comment_Bracket, p_Tree, p_Tree->getNumLine() );
			break;

			case Node_Ada_Generic_Derived_Type_Abstract_Private:
					l_Result = new tree( Node_C_Comment_Bracket, p_Tree, p_Tree->getNumLine() );
			break;

			case Node_Ada_Generic_Derived_Type_Private:
				l_Result = new tree( Node_C_Comment_Bracket, p_Tree, p_Tree->getNumLine() );
			break;

			case Node_Ada_Generic_Discrim_Part_Opt:
				l_Result = new tree( Node_C_Comment_Bracket, p_Tree, p_Tree->getNumLine() );
			break;

			case Node_Ada_Generic_Formal:
				l_Result = new tree( Node_C_Comment_Bracket, p_Tree, p_Tree->getNumLine() );
			break;

			case Node_Ada_Generic_Formal_Part:
				l_Result = new tree( Node_C_Comment_Bracket, p_Tree, p_Tree->getNumLine() );
			break;

			case Node_Ada_Generic_Formal_Package:
				l_Result = new tree( Node_C_Comment_Bracket, p_Tree, p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Generic_Formal_Package_Box:
				l_Result = new tree( Node_C_Comment_Bracket, p_Tree, p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Generic_Formal_Procedure:
				l_Result = new tree( Node_C_Comment_Bracket, p_Tree, p_Tree->getNumLine() );
			break;
	
			case Node_Ada_Generic_Inst:
				l_Result = p_Tree;
			break;
	
			case Node_Ada_Generic_Subp_Inst:
				l_Result = p_Tree;
			break;
			
			case Node_Ada_Generic_Type_Def:
				l_Result = p_Tree;
			break;
			
			case Node_Ada_Generic_Type_Def_Box:
				l_Result = p_Tree;
			break;
	
			case Node_Ada_Generic_Package_Inst:
			CREATE_COMMENT_BLOCK(p_Tree)
			break;
			
			case Node_Ada_Generic_Subprog_Inst:
			CREATE_COMMENT_BLOCK(p_Tree)
			break;
			
			case Node_Ada_Goto:
			l_Result = new tree( Node_Ada_Goto, p_Tree->getSon(0), p_Tree->getNumLine() );
			break;

			case Node_Ada_Guarded_Select_Alt:
			CREATE_COMMENT_BLOCK( new tree(Node_Ada_Guarded_Select_Alt, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() ))
			break;
			
			case Node_Ada_Handler_Statement:
			/* NOT MANAGE son 2 */
			if(p_Tree->getSon(1)->getNodeType()==Node_Ada_C_Empty)
			{
				l_Result = translation( p_FpLog, p_Tree->getSon(0) );
			}
			else
			{
				l_Result = new tree( Node_C_Handler_Statement, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine());
			}

			break;
			
			case Node_Ada_If:
			{
				switch( p_Tree->getSon(0)->getNodeType() )
				{
					case Node_Ada_Condition_Clause:
					l_Result = new tree( Node_C_If, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
					break;
					case Node_Ada_List_Condition_Clause:
					{
						switch( p_Tree->getSon(1)->getNodeType() )
						{
							case Node_Ada_C_Empty:
							l_Result = new tree( Node_C_If, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
							break;
							case Node_Ada_Else:
							l_Result = new tree( Node_C_If, translationListConditionClause( p_FpLog, p_Tree->getSon(0), p_Tree->getSon(1) ), new tree( Node_Ada_C_Empty, p_Tree->getNumLine() ), p_Tree->getNumLine() );
							break;
							default:
							errorNotAllowed(__FILE__,__LINE__, p_Tree->getSon(1), "else_opt");
							my_exit(-1);
							break;
					
						}
					}
					
					break;
					default:
					errorNotAllowed(__FILE__,__LINE__, p_Tree->getSon(0), "cond_clause_s");
					my_exit(-1);
					break;
				}
			}
			break;
			
			case Node_Ada_In:
			if( p_Tree->getSon(1)->getNodeType() == Node_Ada_Range_Inter )
			{
				l_Result = new tree( Node_C_And, new tree( Node_Ada_C_Less_Equal, translation( p_FpLog, p_Tree->getSon(1)->getSon(0) ), p_Tree->getSon(0) , p_Tree->getNumLine() ), new tree( Node_Ada_C_Less_Equal, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getSon(1)->getSon(1), p_Tree->getNumLine() ), p_Tree->getNumLine() );
			}
			else
			{
				l_Result = new tree( Node_C_Comment_Bracket, new tree( Node_Ada_In, translation( p_FpLog, p_Tree->getSon(0) ),  translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() ), p_Tree, p_Tree->getNumLine() );
			}
			break;
			
			case Node_Ada_Index:
			l_Result = new tree( Node_C_Comment_Bracket, p_Tree, p_Tree->getNumLine() );
			break;

			case Node_Ada_Indexed_Comp:
			{
				
				if(isAnArray( p_FpLog, p_Tree, g_CurrentMainUnit) == NULL)
				{
					if( isFunction(p_FpLog, p_Tree, g_CurrentMainUnit) != NULL)
					{
					}
					l_Result = new tree( Node_Ada_Indexed_Comp, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
				}
				else
				{
					
					l_Result = new tree( Node_C_Array_Comp, translation( p_FpLog, p_Tree->getSon(0) ), translationIndexedComp( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
				}
					
			}
			break;
			
			case Node_Ada_Initialisation_Option:
			l_Result = new tree( Node_C_Initialisation_Option, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Iteration:
			{
				switch( p_Tree->getNbSon() )
				{
					// Loop "while"
					case 1:
					l_Result = new tree( Node_C_While, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() );
					break;
					// Loop for
					case 3:
					{
						// get iteration variable
						tree *l_Iterator = translation( p_FpLog, p_Tree->getSon(0)->getSon(0));
						tree *l_Inf = NULL;
						tree *l_Sup = NULL;
						tree *l_Step = NULL;
						tree *l_StopCondition = NULL;

						// Determination of inf and sup limit of range
						switch( p_Tree->getSon(2)->getNodeType() )
						{
							case Node_Ada_Discrete_Range:
							case Node_Ada_Range:
								l_Inf = new tree( Node_C_Comment_Bracket, p_Tree->getSon(2), p_Tree->getNumLine() );
								l_Sup = new tree( Node_C_Comment_Bracket, p_Tree->getSon(2), p_Tree->getNumLine() );
							break;
							case Node_Ada_Range_Inter:
								l_Inf = translation( p_FpLog, p_Tree->getSon(2)->getSon(0) );
								l_Sup = translation( p_FpLog, p_Tree->getSon(2)->getSon(1) );
							break;
							default:errorNotAllowed( __FILE__, __LINE__, p_Tree->getSon(2), "discrete_range"); 
								my_exit(-1);
							break;
						}

						// Determination of step
						switch( p_Tree->getSon(1)->getNodeType() )
						{
							case Node_Ada_Reverse:
							{
								tree *l_Swap = l_Sup;
								l_Sup = l_Inf;
								l_Inf = l_Swap;
								l_Step = new tree( Node_C_Post_Less, l_Iterator, p_Tree->getNumLine() );
								l_StopCondition = new tree( Node_Ada_C_Sup_Equal, l_Iterator, l_Sup, p_Tree->getNumLine() );
							}
							break;
							case Node_Ada_C_Empty:
								l_Step = new tree( Node_C_Post_Plus, l_Iterator, p_Tree->getNumLine() );
								l_StopCondition = new tree( Node_Ada_C_Less_Equal, l_Iterator, l_Sup, p_Tree->getNumLine() );
							break;
							default:errorNotAllowed( __FILE__, __LINE__, p_Tree->getSon(1), "reverse_opt");
									my_exit(-1);
						}

								
						l_Result = new tree( Node_C_Iteration, new tree( Node_C_Iterative_Part, l_Iterator, l_Inf, p_Tree->getNumLine()), l_StopCondition, l_Step, p_Tree->getNumLine() );
					}
					break;
					default:
					errorNbSon(__FILE__,__LINE__, p_Tree);
					my_exit(-1);
					break;
				}
			}
			break;
			
			case Node_Ada_Iterative_Part:
			l_Result = p_Tree;
			break;
			
			case Node_Ada_Label:
				l_Result = new tree(Node_C_Comment_Line, p_Tree, p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Label_Loop:
			l_Result = new tree( Node_Ada_Label_Loop, p_Tree->getSon(0), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_List_Alternative:
			l_Result = new tree( Node_Ada_List_Alternative, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_List_Component_Decl:
			{
				tree *p_ComponentDecl1=translation( p_FpLog, p_Tree->getSon(0) );
				tree *p_Pragmas=translation( p_FpLog, p_Tree->getSon(1) );
				tree *p_ComponentDecl2=translation( p_FpLog, p_Tree->getSon(2) );
				l_Result = new tree( Node_Ada_List_Component_Decl, p_ComponentDecl1, p_Pragmas, p_ComponentDecl2, p_Tree->getNumLine() );
			}
			break;
			
			case Node_Ada_List_Condition_Clause:
			l_Result = new tree( Node_C_List_Condition_Clause, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_List_Discrete_Range:
			l_Result = new tree( Node_C_List_Discrete_Range, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_List_Discrim_Spec:
				l_Result = p_Tree ;
			break;
				
			case Node_Ada_List_Enumeration_Identifier:
				l_Result = p_Tree ;
			break;

			case Node_Ada_List_Identifier:
				l_Result = p_Tree;
			break;
			
			case Node_Ada_List_Index:
				l_Result = new tree( Node_Ada_List_Index, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_List_Item_Decl:
			{
				tree *p_ItemDecl1 = translation( p_FpLog, p_Tree->getSon(0) );
				tree *p_ItemDecl2 = translation( p_FpLog, p_Tree->getSon(1) );
				l_Result = new tree( Node_Ada_List_Item_Decl, p_ItemDecl1, p_ItemDecl2, p_Tree->getNumLine() );
			}
			break;
			
			case Node_Ada_List_Name:
				l_Result = new tree( Node_Ada_List_Name, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_List_Parameter:
				l_Result = new tree( Node_C_List_Parameter, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_List_Pragma:
				CREATE_COMMENT_BLOCK(p_Tree)
			break;
			
			case Node_Ada_List_Pragma_Arg:
				l_Result = p_Tree;
			break;
			
			case Node_Ada_List_Value:
				l_Result = new tree( Node_Ada_List_Value, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_List_Value2:
				l_Result = new tree( Node_Ada_List_Value2, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_List_Variant:
				l_Result = p_Tree;
			break;

			case Node_Ada_Loop:
				// Son 4 is not managed
				l_Result = new tree( Node_C_Loop, p_Tree->getSon(0), translation( p_FpLog, p_Tree->getSon(1) ), translation( p_FpLog, p_Tree->getSon(2) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Mark_Point:
			{
				
				if(getPackageSpec( p_FpLog, getString( p_Tree->getSon(0) ), g_CurrentMainUnit)==NULL)
				{
					l_Result= new tree( Node_Ada_Mark_Point, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getSon(1), p_Tree->getNumLine() );
				}
				else
				{
					l_Result = new tree( Node_C_Mark, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getSon(1), p_Tree->getNumLine() );
				}
			}
			break;
			
			case Node_Ada_Mark_Quote:
			l_Result = p_Tree;
			break;

			case Node_Ada_Mod:
			l_Result = new tree( Node_C_Mod, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Mode_Access:
				l_Result = new tree( Node_C_Comment_Bracket, p_Tree, p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Mod_Box:
				l_Result = new tree( Node_C_Comment_Bracket, p_Tree, p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Mode_In:
			l_Result = new tree( Node_Ada_C_Empty, p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Mode_In_Out:
			l_Result= new tree( Node_C_Star, p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Mode_Out:
			l_Result= new tree( Node_C_Star, p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Non_Equal:
			l_Result = new tree( Node_C_Non_Equal, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Not:
			l_Result = new tree( Node_C_Not, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Not_In:
			if( p_Tree->getSon(1)->getNodeType() == Node_Ada_Range_Inter )
			{
				l_Result = new tree( Node_C_Or, new tree( Node_Ada_C_Less, p_Tree->getSon(0) , translation( p_FpLog, p_Tree->getSon(1)->getSon(0) ), p_Tree->getNumLine() ), new tree( Node_Ada_C_Less, p_Tree->getSon(1)->getSon(1), translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() ), p_Tree->getNumLine() );
			}
			else
			{
				l_Result = new tree( Node_C_Comment_Bracket, new tree( Node_Ada_Not_In, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() ), p_Tree, p_Tree->getNumLine() );
			}
			
			
			break;
			
			case Node_Ada_Null:
			l_Result = new tree( Node_Ada_Null, p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Null_Statement:
			l_Result = new tree( Node_Ada_C_Empty, p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Number_Decl:
			CREATE_COMMENT_BLOCK(p_Tree)
			calculate(p_FpLog,new value(p_Tree->getSon(1)),g_CurrentMainUnit);

			break;
			
			case Node_Ada_Object_Decl:
			{
				if( p_Tree->getSon(0)->getNodeType()==Node_Ada_List_Identifier && p_Tree->getSon(3)->getNodeType() != Node_Ada_C_Empty)
				{
					tree *object1= new tree( Node_Ada_Object_Decl, p_Tree->getSon(0)->getSon(0), p_Tree->getSon(1), p_Tree->getSon(2), p_Tree->getSon(3), p_Tree->getNumLine() );
					tree *object2= new tree( Node_Ada_Object_Decl, p_Tree->getSon(0)->getSon(1), p_Tree->getSon(1), p_Tree->getSon(2), p_Tree->getSon(3), p_Tree->getNumLine() );
					l_Result = new tree( Node_Ada_C_List_Decl_Item_Or_Body, translation( p_FpLog,object1), translation( p_FpLog,object2), p_Tree->getNumLine() );
				}
				else
				{
					switch( p_Tree->getSon(2)->getNodeType() )
					{
						case Node_Ada_Subtype_Indication:
						{
							int l_Normal=1;
							
							if(p_Tree->getSon(2)->getSon(0)->getNodeType()==Node_Ada_Indexed_Comp)
							{
								if(isTypeAnArray(p_FpLog,p_Tree->getSon(2)->getSon(0)->getSon(0),g_CurrentMainUnit)!=NULL)
									{
										l_Normal=0;
										l_Result=translation(p_FpLog,new tree(Node_Ada_Object_Decl,p_Tree->getSon(0),p_Tree->getSon(1),new tree(Node_Ada_Constraint_Array_Type,p_Tree->getSon(2)->getSon(0)->getSon(1),p_Tree->getSon(2)->getSon(0)->getSon(0),p_Tree->getNumLine()),p_Tree->getSon(3),p_Tree->getNumLine()));
									}
							}
							
							if(l_Normal!=0)
							{
								l_Result = new tree( Node_C_Object_Decl, translation( p_FpLog, p_Tree->getSon(1) ), translation( p_FpLog, p_Tree->getSon(2) ), p_Tree->getSon(0), translation( p_FpLog, p_Tree->getSon(3) ), p_Tree->getNumLine() );
							}
						}
						break;
						case Node_Ada_Unconstraint_Array_Type:
						l_Result = new tree( Node_C_Object_Decl, translation( p_FpLog, p_Tree->getSon(1) ), translation( p_FpLog, p_Tree->getSon(2)->getSon(1) ), new tree( Node_C_Array_Comp, p_Tree->getSon(0), translationUnconstraintObjectArray( p_FpLog, p_Tree->getSon(2)->getSon(0) ), p_Tree->getNumLine() ), translation( p_FpLog, p_Tree->getSon(3) ), p_Tree->getNumLine() );
						break;
						case Node_Ada_Constraint_Array_Type:
						l_Result = new tree( Node_C_Object_Decl, translation( p_FpLog, p_Tree->getSon(1) ), translation( p_FpLog, p_Tree->getSon(2)->getSon(1) ), new tree( Node_C_Array_Comp, p_Tree->getSon(0), translation( p_FpLog, p_Tree->getSon(2)->getSon(0) ), p_Tree->getNumLine() ), translation( p_FpLog, p_Tree->getSon(3) ), p_Tree->getNumLine() );
						break;
						default:
						errorNotAllowed(__FILE__,__LINE__, p_Tree->getSon(2), "object_subtype_def");
						my_exit(-1);
						break;
					}
					
				}
				
			}
			break;
			
			case Node_Ada_Or:
			l_Result = new tree( Node_C_Or, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Or_Else:
			l_Result = new tree( Node_C_Or, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Or_Select:
			l_Result = new tree( Node_C_Or, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Others:
				l_Result = new tree( Node_C_Comment_Bracket, p_Tree, p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Pragma_Arg:
				l_Result = new tree( Node_C_Comment_Bracket, p_Tree, p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Package_Body:
			{
				g_CurrentMainUnit = ( main_unit* )p_Tree->getTableSymbolMember();
				tree *l_UseTree=translation( p_FpLog, new tree( Node_Ada_Clause_Width, p_Tree->getSon(0), p_Tree->getNumLine() ) );
				tree *l_NamespaceTree = new tree( Node_C_Namespace_Def, p_Tree->getSon(0), translation( p_FpLog, p_Tree->getSon(1) ), translation( p_FpLog, p_Tree->getSon(2) ), p_Tree->getNumLine() );
				l_Result = new tree( Node_Ada_List_Item_Decl, l_UseTree, l_NamespaceTree, p_Tree->getNumLine() );
			}
			break;
			
			case Node_Ada_Package_Decl:
			l_Result = translation( p_FpLog, p_Tree->getSon(0) );
			break;
			
			case Node_Ada_Package_Spec:
				g_CurrentMainUnit = ( main_unit* )p_Tree->getTableSymbolMember();
				l_Result = new tree( Node_C_Namespace_Def, p_Tree->getSon(0), translation( p_FpLog, p_Tree->getSon(1) ), translation( p_FpLog, p_Tree->getSon(2) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Parameter:
			{
				if( p_Tree->getSon(0)->getNodeType() != Node_Ada_C_Ident)
				{
					tree *p_Parameter1=new tree( Node_Ada_Parameter, p_Tree->getSon(0)->getSon(0), p_Tree->getSon(1), p_Tree->getSon(2), p_Tree->getSon(3), p_Tree->getNumLine() );
					tree *p_Parameter2=new tree( Node_Ada_Parameter, p_Tree->getSon(0)->getSon(1), p_Tree->getSon(1), p_Tree->getSon(2), p_Tree->getSon(3), p_Tree->getNumLine() );;
					l_Result = new tree( Node_C_List_Parameter, translation( p_FpLog, p_Parameter1), translation( p_FpLog, p_Parameter2), p_Tree->getNumLine() );
				}
				else
				{
					l_Result = new tree( Node_C_Parameter, translation( p_FpLog, p_Tree->getSon(2) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getSon(0), p_Tree->getSon(3), p_Tree->getNumLine() );
				}
			}
			break;
			
			case Node_Ada_Power:
			l_Result = new tree( Node_C_Power, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Pragma:
			{
				switch( p_Tree->getNbSon() )
				{
					case 1:
					CREATE_COMMENT_BLOCK( new tree( Node_Ada_Pragma, p_Tree->getSon(0), p_Tree->getNumLine() ))
					break;
					case 2:
					CREATE_COMMENT_BLOCK( new tree( Node_Ada_Pragma, p_Tree->getSon(0), p_Tree->getSon(1), p_Tree->getNumLine() ))
					break;
					default:
					errorNbSon(__FILE__,__LINE__, p_Tree);
					my_exit(-1);
					break;
				}
			}
			break;
			
			case Node_Ada_Private:
				l_Result = new tree( Node_C_Comment_Line, p_Tree, p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Private_Part:
				l_Result = new tree( Node_C_Private_Part, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Private_Type:
				l_Result = new tree( Node_C_Comment_Bracket, p_Tree, p_Tree->getNumLine() );
			break;
			
			
			case Node_Ada_Procedure_Call:
				// In case where son 0 of procedure call is an indexed comp it must be stand an indexed comp because it can't be an array
				if( p_Tree->getSon(0)->getNodeType() != Node_Ada_Indexed_Comp )
				{
					l_Result = new tree( Node_Ada_Procedure_Call, new tree( Node_Ada_Indexed_Comp,translation( p_FpLog, p_Tree->getSon(0) ),new tree(Node_Ada_C_Empty,p_Tree->getNumLine()),p_Tree->getNumLine()), p_Tree->getNumLine() );
				}
				else
				{
					l_Result = new tree( Node_Ada_Procedure_Call,new tree( Node_Ada_Indexed_Comp, translation( p_FpLog, p_Tree->getSon(0)->getSon(0) ), translation( p_FpLog, p_Tree->getSon(0)->getSon(1) ), p_Tree->getSon(0)->getNumLine() ), p_Tree->getNumLine() );
				}
			break;
			
			case Node_Ada_Prot_Body:
			CREATE_COMMENT_BLOCK( new tree( Node_Ada_Prot_Body, translation(p_FpLog, p_Tree->getSon(0) ),  translation(p_FpLog, p_Tree->getSon(1) ),  translation(p_FpLog, p_Tree->getSon(2) ), p_Tree->getNumLine() ))
			break;

			case Node_Ada_Prot_Decl:
			CREATE_COMMENT_BLOCK( new tree( Node_Ada_Prot_Decl, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() ))
			break;

			case Node_Ada_Prot_Def:
				l_Result = p_Tree ;
			break;

			case Node_Ada_Prot_Elem_Decl_s:
				l_Result = p_Tree ;
			break;

			case Node_Ada_Prot_Op_Body:
			l_Result= new tree( Node_Ada_Prot_Op_Body, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Prot_Op_Body_s:
			l_Result= new tree( Node_Ada_Prot_Op_Body_s, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), translation( p_FpLog, p_Tree->getSon(2) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Prot_Op_Decl:
				l_Result = p_Tree;
			break;

			case Node_Ada_Prot_Op_Decl_s:
				l_Result = new tree( Node_Ada_Prot_Op_Decl_s, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;

			case Node_Ada_Prot_Private_Opt:
				l_Result = new tree( Node_C_Comment_Bracket, p_Tree, p_Tree->getNumLine() );
			break;

			case Node_Ada_Prot_Spec:
			l_Result = p_Tree;
			break;

			case Node_Ada_Protected_Opt:
				l_Result = new tree( Node_C_Comment_Bracket, p_Tree, p_Tree->getNumLine() );
			break;

			case Node_Ada_Qualified:
			l_Result = new tree( Node_C_Comment_Bracket, new tree( Node_Ada_Qualified, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Raise_Stmt:
			CREATE_COMMENT_BLOCK(p_Tree)
			break;
			
			case Node_Ada_Range:
				switch(p_Tree->getNbSon())
				{
						case 1: l_Result = new tree( Node_C_Comment_Bracket, new tree( Node_Ada_Range, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() ), p_Tree->getNumLine() );
						break;
						case 2: l_Result = new tree( Node_C_Comment_Bracket, new tree( Node_Ada_Range, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() ), p_Tree->getNumLine() );
						break;
						default:errorNbSon( __FILE__, __LINE__, p_Tree );
						my_exit(-1);
				}
				
			break;
			
			case Node_Ada_Range_Box:
				l_Result = p_Tree;
			break;
			
			case Node_Ada_Range_Constraint:
			l_Result = p_Tree;
			break;

			case Node_Ada_Range_Inter:
			l_Result = new tree( Node_C_Comment_Bracket, new tree( Node_Ada_Range_Inter, translation( p_FpLog, p_Tree->getSon(0) ),  translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() ), p_Tree, p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Record_Type_Spec:
			CREATE_COMMENT_BLOCK(p_Tree)
			break;
			
			case Node_Ada_Rem:
			CREATE_COMMENT_BLOCK( new tree( Node_Ada_Rem, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() ))
			break;
			
			case Node_Ada_Rename_Decl:
			CREATE_COMMENT_BLOCK(p_Tree)
			break;
			
			case Node_Ada_Rename_Unit:
			CREATE_COMMENT_BLOCK(p_Tree)
			break;
			
			case Node_Ada_Rename_Unit_Package:
			l_Result = new tree( Node_C_Define, p_Tree->getSon(0), p_Tree->getSon(1)->getSon(0), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Renames:
				l_Result = p_Tree ;
			break;

			case Node_Ada_Rep_Spec_s:
				l_Result = new tree( Node_Ada_Rep_Spec_s,translation( p_FpLog, p_Tree->getSon(0) ),translation( p_FpLog, p_Tree->getSon(1) ),translation( p_FpLog, p_Tree->getSon(2) ),p_Tree->getNumLine() );
			break;

			case Node_Ada_Requeue_Stmt:
			CREATE_COMMENT_BLOCK(p_Tree)
			break;
			
			case Node_Ada_Requeue_Stmt_With:
			CREATE_COMMENT_BLOCK(p_Tree)
			break;
			
			case Node_Ada_Return:
			{
				switch( p_Tree->getNbSon() )
				{
					case 0:
					l_Result = new tree( Node_Ada_Return, p_Tree->getNumLine() );
					break;
					case 1:
					l_Result = new tree( Node_Ada_Return, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() );
					break;
					default:
					errorNbSon(__FILE__,__LINE__, p_Tree);
					my_exit(-1);
					break;
				}
			}
			break;
			
			case Node_Ada_Reverse:
			l_Result = p_Tree;
			break;
			
			case Node_Ada_Select_Alt:
				switch(p_Tree->getNbSon())
				{
					case 0:
						l_Result = new tree( Node_C_Comment_Bracket, p_Tree , p_Tree->getNumLine());
					break;
					case 2:
						l_Result = new tree( Node_C_Comment_Bracket, new tree( Node_Ada_Select_Alt, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() ), p_Tree->getNumLine());
					break;
					default:
					errorNbSon(__FILE__,__LINE__,p_Tree);
					my_exit(-1);
				}
			break;
			
			case Node_Ada_Selected_Comp:
			{
				if( p_Tree->getSon(0)->getNodeType()==Node_Ada_Indexed_Comp )
				{
					l_Result = new tree( Node_Ada_Selected_Comp, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
				}
				else
				{
					if(getPackageSpec( p_FpLog, getString( p_Tree->getSon(0) ), g_CurrentMainUnit)==NULL)
					{
						l_Result= new tree( Node_Ada_Mark_Point, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getSon(1), p_Tree->getNumLine() );
					}
					else
					{
						l_Result = new tree( Node_C_Mark, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getSon(1), p_Tree->getNumLine() );
					}
				}
				
			}
			break;
			
			case Node_Ada_Selected_Comp_All:
			CREATE_COMMENT_BLOCK( new tree( Node_Ada_Selected_Comp_All, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() ))
			break;
			
			case Node_Ada_Select_Wait:
			CREATE_COMMENT_BLOCK( new tree( Node_Ada_Select_Wait, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), translation( p_FpLog, p_Tree->getSon(2) ), p_Tree->getNumLine() ))
			break;
			
			case Node_Ada_Statement:
			l_Result = new tree( Node_C_Labelled_Stmt, p_Tree->getSon(0), p_Tree->getSon(1), p_Tree->getNumLine() );
			break;

			case Node_Ada_Subp_Default:
				l_Result = new tree( Node_C_Comment, p_Tree, p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Subprog_Body:
			g_CurrentMainUnit = ( main_unit* )p_Tree->getTableSymbolMember();
			l_Result = new tree( Node_C_Subprog_Body, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), translation( p_FpLog, p_Tree->getSon(2) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Subprog_Decl:
			l_Result = new tree( Node_Ada_Subprog_Decl, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Subprog_Spec:
			{
				//g_CurrentMainUnit = ( main_unit* )p_Tree->getTableSymbolMember();
				switch( p_Tree->getNbSon() )
				{
					case 1:/* NOT MANAGE */
					l_Result = new tree( Node_Ada_C_Empty, p_Tree->getNumLine() );
					break;
					case 2:
					l_Result = new tree( Node_C_Subprog_Spec, p_Tree->getSon(0), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
					break;
					case 3:
					l_Result = new tree( Node_C_Subprog_Spec, translation( p_FpLog, p_Tree->getSon(2) ), p_Tree->getSon(0), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
					break;
					default:
					errorNbSon(__FILE__,__LINE__, p_Tree);
					my_exit(-1);
					break;
				}
			}
			break;
			
			case Node_Ada_Subtype_Decl:
			l_Result = new tree( Node_C_Derived_Type_Decl, translation( p_FpLog, p_Tree->getSon(1) ), translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Subtype_Indication:
			if( p_Tree->getNbSon()==2)
			{
				errorLogManage( p_FpLog, p_Tree->getNumLine(), "constraint");
			}
			//p_Tree->displayTree();
			
			l_Result = new tree( Node_Ada_Subtype_Indication, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Subunit:
			l_Result = translation( p_FpLog, p_Tree->getSon(1) );
			break;
			
			case Node_Ada_Tagged:
				l_Result = new tree( Node_C_Comment_Bracket, p_Tree, p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Task_Body:
			CREATE_COMMENT_BLOCK( new tree( Node_Ada_Task_Body, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), translation( p_FpLog, p_Tree->getSon(2) ), translation( p_FpLog, p_Tree->getSon(3) ), p_Tree->getNumLine() ))
			break;

			case Node_Ada_Task_Decl:
			CREATE_COMMENT_BLOCK(p_Tree)
			break;

			case Node_Ada_Task_Def:
				l_Result = p_Tree ;
			break;
			
			case Node_Ada_Task_Private_Opt:
				l_Result = p_Tree ;
			break;
			
			case Node_Ada_Task_Spec:
				l_Result = p_Tree ;
			break;
			
			case Node_Ada_Timed_Entry_Call:
			CREATE_COMMENT_BLOCK(new tree(Node_Ada_Timed_Entry_Call,translation( p_FpLog, p_Tree->getSon(0) ),translation( p_FpLog, p_Tree->getSon(1) ),translation( p_FpLog, p_Tree->getSon(2) ),translation( p_FpLog, p_Tree->getSon(3) ),p_Tree->getNumLine()))
			break;
			
			case Node_Ada_Type_Decl:
			l_Result = translationTypeDecl( p_FpLog, p_Tree);
			break;
			
			case Node_Ada_Use_Clause:
			//CREATE_COMMENT_BLOCK(new tree( Node_Ada_Use_Clause, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() ))
			
			if( p_Tree->getSon(0)->getNodeType() == Node_Ada_List_Name )
			{
				tree *l_ClauseUse1=new tree( Node_Ada_Use_Clause, p_Tree->getSon(0)->getSon(0), p_Tree->getNumLine() );
				tree *l_ClauseUse2=new tree( Node_Ada_Use_Clause, p_Tree->getSon(0)->getSon(1), p_Tree->getNumLine() );
				l_Result = new tree( Node_Ada_Context_Specification, translation( p_FpLog, l_ClauseUse1), translation( p_FpLog, l_ClauseUse2), p_Tree->getNumLine() );
			}
			else
			{
				file *l_File = NULL;
				int l_Error = 0;
				list<package_spec*> *l_PackageSpecList = getByName( getString( p_Tree->getSon(0) ), g_TableSymbol->getPackageSpecs() );
				if( l_PackageSpecList == NULL)
				{
					fprintf( p_FpLog, "line %i ( in ada file ) : package \"%s\" not found\n", p_Tree->getNumLine(), getString( p_Tree->getSon(0) ) );
					l_Error = 1;
				}
				else
				{
					if( l_PackageSpecList->getNbItem() != 1)
					{
						fprintf( p_FpLog, "line %i ( in ada file ) : search of package \"%s\" give several answers\n", p_Tree->getNumLine(), getString( p_Tree->getSon(0) ) );
						l_Error = 1;
					}
					else
					{
						l_Result = new tree( Node_C_Using_Namespace,p_Tree->getSon(0), p_Tree->getNumLine() );
					}
				}
				
				if( l_Error!=0)
				{
					l_Result = new tree( Node_C_Comment_Line, new tree( Node_C_Using_Namespace, p_Tree->getSon(0), p_Tree->getNumLine() ), p_Tree->getNumLine() );
				}
			}
			break;
			
			case Node_Ada_Use_Clause_Type:
			CREATE_COMMENT_BLOCK(new tree( Node_Ada_Use_Clause_Type, translation( p_FpLog, p_Tree->getSon(0) ), p_Tree->getNumLine() ))
			break;

			case Node_Ada_Value2:
			l_Result = new tree( Node_Ada_List_Value2, translation( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
			break;
			
			case Node_Ada_Variant_Part:
			errorLogManage( p_FpLog, p_Tree->getNumLine(), "variant part");
			CREATE_COMMENT_BLOCK(p_Tree)
			break;
			
			case Node_Ada_Variant_Part_Optional:
			errorLogManage( p_FpLog, p_Tree->getNumLine(), "variant part");
			CREATE_COMMENT_BLOCK(p_Tree)
			break;
			
			case Node_Ada_When:
				CREATE_COMMENT_BLOCK(p_Tree)
			break;

			default:
			{
				printf("ERROR : %s %i : \"",__FILE__,__LINE__);
				displayNodeType( p_Tree->getNodeType() );
				printf("\" at line %i of \"%s\" is not managed\n", p_Tree->getNumLine(), g_CurrentFile->getName() );
				my_exit(-1);
			}
			break;
			
		}
		
		comment *l_Comment = NULL;
		if( (l_Result != p_Tree) && (( l_Comment = p_Tree->getComment() ) != NULL))
		{
			l_Result->addComment( l_Comment);
		}
	
		g_CurrentMainUnit=l_MainUnitSave;
	}
	else
	{
		errorIsNull(__FILE__,__LINE__, "p_Tree");
		my_exit(-1);
	}
	
	return l_Result;
}

tree* translationRecordTypeDecl(FILE *p_FpLog, tree *p_NameTree, tree *p_DiscrimTree, tree *p_RecordTypeTree)
{
	#ifdef TRACE
	printfTraceUp("translationRecordTypeDecl",__FILE__,__LINE__);
	#endif
	tree *l_Result = NULL;
	if( p_NameTree!=NULL && p_DiscrimTree!=NULL && p_RecordTypeTree!=NULL)
	{
		/* management of record options */
		if( p_RecordTypeTree->getSon(0)->getNodeType() != Node_Ada_C_Empty)
		{
			errorLogManage( p_FpLog, p_RecordTypeTree->getNumLine(), "tagged option");
		}
		
		if( p_RecordTypeTree->getSon(1)->getNodeType() != Node_Ada_C_Empty)
		{
			errorLogManage( p_FpLog, p_RecordTypeTree->getNumLine(), "tagged option");
		}
		
		/* translation of record def */
		tree *p_RecordDefTree = NULL;
		
		
		switch( p_RecordTypeTree->getSon(2)->getNodeType() )
		{
			case Node_Ada_Null_Record:
			p_RecordDefTree = new tree( Node_C_Comment, p_NameTree->getNumLine(), "null record;");
			break;
			case Node_Ada_Record_Definition:
			p_RecordDefTree=translation( p_FpLog, p_RecordTypeTree->getSon(2)->getSon(1) );
			break;
			default:
			errorNotAllowed(__FILE__,__LINE__, p_RecordDefTree, "record_def");
			my_exit(-1);
			break;
		}
		l_Result = new tree( Node_C_Structured_Type_Decl, new tree( Node_Ada_C_Ident, p_NameTree->getNumLine(),myStrcat(2, "t_", p_NameTree->getString() ) ), p_RecordDefTree, p_NameTree, p_NameTree->getNumLine() );
	}
	else
	{
		int error = 0;
		if( p_NameTree==NULL)
		{
			errorIsNull(__FILE__,__LINE__, "p_NameTree");
			error = 1;
		}
		
		if( p_DiscrimTree==NULL)
		{
			errorIsNull(__FILE__,__LINE__, "p_DiscrimTree");
			error = 1;
		}
		
		if( p_RecordTypeTree==NULL)
		{
			errorIsNull(__FILE__,__LINE__, "p_RecordTypeTree");
			error = 1;
		}
		
		if(error!=0)
		{
			my_exit(-1);
		}
	}
	#ifdef TRACE
	printfTraceDown("translationRecordTypeDecl",__FILE__,__LINE__);
	#endif
	return l_Result;

}

tree* translationTypeDecl(FILE *p_FpLog, tree *p_Tree)
{
	#ifdef TRACE
	printfTraceUp("translationTypeDecl",__FILE__,__LINE__);
	#endif
	tree *l_Result = NULL;
	
	if( p_Tree!=NULL)
	{
		switch( p_Tree->getNbSon() )
		{
			case 1:
			CREATE_COMMENT_BLOCK(p_Tree)
			break;
			case 3:
			{
				tree *p_TypeDefTree=p_Tree->getSon(2);
				switch( p_TypeDefTree->getNodeType() )
				{
					/*******************/
					/* Enumerated type */
					/*******************/
					case Node_Ada_Enumeration_Type:
					l_Result = new tree( Node_C_Enumeration_Type_Decl, p_TypeDefTree->getSon(0), p_Tree->getSon(0), p_Tree->getNumLine() );
					break;
					
					/**************/
					/* Real types */
					/**************/
					case Node_Ada_Fixed_Type:
					errorLogManage( p_FpLog, p_Tree->getNumLine(), "delta and (or) digits constraint");
					l_Result = new tree( Node_C_Derived_Type_Decl, new tree( Node_C_Float, p_Tree->getNumLine() ), p_Tree->getSon(0), p_Tree->getNumLine() );
					break;
					case Node_Ada_Float_Type:
					errorLogManage( p_FpLog, p_Tree->getNumLine(), "digits constraint");
					l_Result = new tree( Node_C_Derived_Type_Decl, new tree( Node_C_Float, p_Tree->getNumLine() ), p_Tree->getSon(0), p_Tree->getNumLine() );
					break;
					
					/*****************/
					/* Integer types */
					/*****************/
					case Node_Ada_Integer_Type:
					errorLogManage( p_FpLog, p_Tree->getNumLine(), "range constraint");
					l_Result = new tree( Node_C_Derived_Type_Decl, new tree( Node_C_Int, p_Tree->getNumLine() ), p_Tree->getSon(0), p_Tree->getNumLine() );
					break;
					case Node_Ada_Mod_Integer_Type:
					errorLogManage( p_FpLog, p_Tree->getNumLine(), "mod constraint");
					l_Result = new tree( Node_C_Derived_Type_Decl, new tree( Node_C_Int, p_Tree->getNumLine() ), p_Tree->getSon(0), p_Tree->getNumLine() );
					break;
					
					/*****************/
					/* Derived types */
					/*****************/
					case Node_Ada_Derived_Type:
					l_Result = new tree( Node_C_Derived_Type_Decl, translation( p_FpLog, p_TypeDefTree->getSon(0) ), p_Tree->getSon(0), p_Tree->getNumLine() );
					break;
					
					case Node_Ada_Derived_Type_With_Private:
					errorLogManage( p_FpLog, p_Tree->getNumLine(), "with private constraint");
					l_Result = new tree( Node_C_Derived_Type_Decl, translation( p_FpLog, p_TypeDefTree->getSon(0) ), p_Tree->getSon(0), p_Tree->getNumLine() );
					break;
					
					case Node_Ada_Derived_Type_With_Record:
					errorLogManage( p_FpLog, p_Tree->getNumLine(), "with record");
					l_Result = new tree( Node_C_Derived_Type_Decl, translation( p_FpLog, p_TypeDefTree->getSon(0) ), p_Tree->getSon(0), p_Tree->getNumLine() );
					break;
					
					case Node_Ada_Abstract_Derived_Type_With_Private:
					errorLogManage( p_FpLog, p_Tree->getNumLine(), "with abstract private constraint");
					l_Result = new tree( Node_C_Derived_Type_Decl, translation( p_FpLog, p_TypeDefTree->getSon(0) ), p_Tree->getSon(0), p_Tree->getNumLine() );
					break;
					
					case Node_Ada_Abstract_Derived_Type_With_Record:
					errorLogManage( p_FpLog, p_Tree->getNumLine(), "with abstract record");
					l_Result = new tree( Node_C_Derived_Type_Decl, translation( p_FpLog, p_TypeDefTree->getSon(0) ), p_Tree->getSon(0), p_Tree->getNumLine() );
					break;
					
					/****************/
					/* Access types */
					/****************/
					case Node_Ada_Access_All_Type:
					case Node_Ada_Access_Constant_Type:
					l_Result = new tree( Node_C_Access_Type_Decl, p_TypeDefTree->getSon(0), p_Tree->getSon(0), p_Tree->getNumLine() );
					break;
					case Node_Ada_Access_Type:
					{
						switch( p_TypeDefTree->getNbSon() )
						{
							case 1:
							l_Result = new tree( Node_C_Access_Type_Decl, translation( p_FpLog, p_TypeDefTree->getSon(0) ), p_Tree->getSon(0), p_Tree->getNumLine() );
							break;
							case 2:
								if(p_TypeDefTree->getSon(0)->getNodeType()==Node_Ada_Protected_Opt)
								{
									errorLogManage( p_FpLog, p_Tree->getNumLine(), "protected option for procedure");
								}
								l_Result=new tree(Node_C_Access_Subprog_Type_Decl,p_TypeDefTree->getSon(0),new tree(Node_Ada_C_Ident,p_Tree->getNumLine(),"void"),p_Tree->getSon(0),translation(p_FpLog,p_TypeDefTree->getSon(1)),p_Tree->getNumLine());
							break;
							case 3:
								if(p_TypeDefTree->getSon(0)->getNodeType()==Node_Ada_Protected_Opt)
								{
									errorLogManage( p_FpLog, p_Tree->getNumLine(), "protected option for function");
								}
								l_Result=new tree(Node_C_Access_Subprog_Type_Decl,p_TypeDefTree->getSon(0),p_TypeDefTree->getSon(2),p_Tree->getSon(0),translation(p_FpLog,p_TypeDefTree->getSon(1)),p_Tree->getNumLine());
							break;
							errorNbSon(__FILE__,__LINE__, p_TypeDefTree);
							my_exit(-1);
						}
					}
					break;
					
					/****************/
					/* Record Types */
					/****************/
					case Node_Ada_Record_Type:
					l_Result = translationRecordTypeDecl( p_FpLog, p_Tree->getSon(0), p_Tree->getSon(1), p_Tree->getSon(2) );
					break;
					
					/****************/
					/* Array type */
					/**************/
					case Node_Ada_Unconstraint_Array_Type:
					l_Result=new tree(Node_C_Unconstraint_Array_Type,translation( p_FpLog, p_TypeDefTree->getSon(1) ), p_Tree->getSon(0), new tree(Node_C_Comment_Line, p_TypeDefTree->getSon(0),p_TypeDefTree->getSon(0)->getNumLine()), p_Tree->getNumLine() );
					break;
					
					case Node_Ada_Constraint_Array_Type:
					l_Result = new tree( Node_C_Array_Type, translation( p_FpLog, p_TypeDefTree->getSon(1) ), p_Tree->getSon(0), translation( p_FpLog, p_TypeDefTree->getSon(0) ), p_Tree->getNumLine() );
					break;
					
					default:
					CREATE_COMMENT_BLOCK(p_Tree)
					break;
					
					
				}
			}
			break;
			default:
			errorNbSon(__FILE__,__LINE__, p_Tree);
			break;	
		}
		
	}
	else
	{
		errorIsNull(__FILE__,__LINE__, "p_Tree");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("translationTypeDecl",__FILE__,__LINE__);
	#endif
	
	return l_Result;
}

tree* translationListConditionClause(FILE *p_FpLog, tree *p_ListConditionClauseTree, tree *p_ElseOptTree)
{
	#ifdef TRACE
	printfTraceUp("translationListConditionClause",__FILE__,__LINE__);
	#endif
	tree *l_Result = NULL;
	
	if( p_ListConditionClauseTree!=NULL && p_ElseOptTree!=NULL)
	{
		switch( p_ListConditionClauseTree->getNodeType() )
		{
			case Node_Ada_List_Condition_Clause:
			l_Result = new tree( Node_C_List_Condition_Clause, translation( p_FpLog, p_ListConditionClauseTree->getSon(0) ), translationListConditionClause( p_FpLog, p_ListConditionClauseTree->getSon(1), p_ElseOptTree), p_ListConditionClauseTree->getNumLine() );
			break;
			case Node_Ada_Condition_Clause:
			l_Result = new tree( Node_C_Condition_Clause, translation( p_FpLog, p_ListConditionClauseTree->getSon(0) ), translation( p_FpLog, p_ListConditionClauseTree->getSon(1) ), translation( p_FpLog, p_ElseOptTree), p_ListConditionClauseTree->getNumLine() );
			break;
			default:
			errorNotAllowed(__FILE__,__LINE__, p_ListConditionClauseTree, "cond_clause_s");
			my_exit(-1);
			break;
		}
	}
	else
	{
		int l_Error = 0;
		if( p_ListConditionClauseTree==NULL)
		{
			errorIsNull(__FILE__,__LINE__, "p_ListConditionClauseTree");
			l_Error = 1;
		}
		if( p_ElseOptTree==NULL)
		{
			errorIsNull(__FILE__,__LINE__, "p_ElseOptTree");
			l_Error = 1;
		}
		if( l_Error!=0)
		{
			my_exit(-1);
		}
	}
	#ifdef TRACE
	printfTraceDown("translationListConditionClause",__FILE__,__LINE__);
	#endif
	return l_Result;
}

tree* translationIndexedComp(FILE *p_FpLog, tree *p_Tree)
{
	#ifdef TRACE
	printfTraceUp("translationIndexedComp",__FILE__,__LINE__);
	#endif
	tree *l_Result = NULL;
	if( p_Tree->getNodeType()==Node_Ada_List_Value)
	{
		l_Result = new tree( Node_C_List_Discrete_Range, translationIndexedComp( p_FpLog, p_Tree->getSon(0) ), translation( p_FpLog, p_Tree->getSon(1) ), p_Tree->getNumLine() );
	}
	else
	{
		l_Result = translation( p_FpLog, p_Tree);
	}
	#ifdef TRACE
	printfTraceDown("translationIndexedComp",__FILE__,__LINE__);
	#endif
	return l_Result;
}

/*****************************************************************************
 * Function name : translationUnconstraintObjectArray 
 *
 * Input :	p_FpLog reference on a FILE
 * 		p_Name reference on a string
 * Output : package_spec* - reference on a package_spec
 * Modified variable : none
 * Description : Function which return a reference on the package spec
 * 	designed by parameter P_Name
 *****************************************************************************/
tree* translationUnconstraintObjectArray( FILE *p_FpLog, tree *p_Tree)
{
	#ifdef TRACE
	printfTraceDown("translationIndexedComp",__FILE__,__LINE__);
	#endif
	tree *l_Result=NULL;

	/* Check of input parameters */
	if(p_Tree!=NULL)
	{
		switch(p_Tree->getNodeType())
		{
			case Node_Ada_List_Index:
				l_Result=new tree(Node_C_List_Discrete_Range,translationUnconstraintObjectArray(p_FpLog,p_Tree->getSon(0)),translationUnconstraintObjectArray(p_FpLog,p_Tree->getSon(1)),p_Tree->getNumLine());
			break;
			case Node_Ada_Index:
				l_Result=new tree(Node_Ada_C_Empty,p_Tree->getNumLine());
			break;
			
			/* Default case */
			default:
			errorNotAllowed(__FILE__,__LINE__,p_Tree,"index_s");
			my_exit(-1);
		}
	}
	else
	{
		// Determine which parameter failed
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("translationIndexedComp",__FILE__,__LINE__);
	#endif
	return l_Result;
}
