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
 * $Log: table_symbol_creation.cpp,v $
 * Revision 1.5  2005/03/26 23:32:42  quicky2000
 * Update of call to constructors of class function_spec, function_rename, function_body access_function_type due to the modifications of their prototypes
 *
 * Revision 1.4  2005/03/19 12:52:07  quicky2000
 * Update to restablish cvs log messages
 *
 * Revision 1.3  2005/03/19 10:55:22  quicky2000
 * Update for code maintenance
 *
 * Revision 1.2  2005/03/16 18:49:32  quicky2000
 * Update to:
 * _ replace line_number by g_LineNumber to respect coding rules
 * _ create a function to unify the display message for declarations
 *
 * Revision 1.1  2005/03/07 23:41:18  quicky2000
 * Update for code maintenance
 *
 * Revision 1.2  2005/03/03 23:15:03  quicky2000
 * Update to better manage Node_Ada_Generic and to manage Node_Ada_Access_All_Type and Node_Ada_Access_Constant_Type
 *
 * Revision 1.1.1.1  2005/03/01 22:20:47  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/

/* ========================================================================== */
/* DIRECTIVES D'INCLUSION (include)                                           */
/* ========================================================================== */
#include "table_symbol_creation.h"
#include "../Tools/configuration.h"

/* ========================================================================== */
/* DEFINITION DES DONNEES GLOBALES EXPORTEES				      */
/* ========================================================================== */
/* $ ------------------------------------------------------------------------ */
/* $ DONNEE GLOBALE        : g_TableSymbol                                    */
/* $ TYPE                  : main_unit	                                      */
/* $ DESCRIPTION           : global table_symbol of translated files          */
/* $ ------------------------------------------------------------------------ */
main_unit *g_TableSymbol=new main_unit(Main_Unit_Table_Symbol,"table symbol",NULL);

/* $ ------------------------------------------------------------------------ */
/* $ DONNEE GLOBALE        : g_CurrentMainUnit                                */
/* $ TYPE                  : main_unit	                                      */
/* $ DESCRIPTION           : reference on currentMainunit	              */
/* $ ------------------------------------------------------------------------ */
main_unit *g_CurrentMainUnit=NULL;

extern configuration *g_Config;

void printfDeclarationOf(const char *p_Declarated,const char *p_Name,const char *p_FileName,int p_NumLigne)
{
	if(g_Config->getVerbose()>0)
	{
		
		printf("declaration of %s \"%s\" in file \"%s\" line %i\n",p_Declarated,p_Name,p_FileName,p_NumLigne);
	}
}

void tableSymboleCreation(tree *p_Tree)
{
	if(p_Tree!=NULL)
	{
	
	
		main_unit *mainUnitSave=g_CurrentMainUnit;
		
		switch(p_Tree->getNodeType())
		{
			
			/****************
			 * list of unit *
			 ****************/
			
			//
			case Node_Ada_C_Program:
			g_CurrentMainUnit=g_CurrentFile;
			p_Tree->setTableSymbolMember(g_CurrentMainUnit);
			tableSymboleCreation(p_Tree->getSon(0));
			break;
			
			//pkg_decl
			case Node_Ada_Package_Decl:
			packageDeclarationManagement(p_Tree->getSon(0));
			break;
			
			//pkg_body
			case Node_Ada_Package_Body:
			packageBodyDeclaration(p_Tree);
			break;
			
			
			//subunit
			case Node_Ada_Subunit:
			packageSubunitDeclaration(p_Tree);
			break;
			
			//subprog_body
			case Node_Ada_Subprog_Body:
			subprogBodyDeclaration(p_Tree);
			break;
			
			
			//task decl
			case Node_Ada_Task_Decl:
			taskDeclaration(p_Tree->getSon(0));
			break;

			case Node_Ada_Task_Body:
			taskBodyDeclaration(p_Tree);
			break;

			//protected decl
			case Node_Ada_Prot_Decl:
			protDeclaration(p_Tree->getSon(0));
			break;
			case Node_Ada_Prot_Body:
			protBodyDeclaration(p_Tree);
			break;

			
			//rename_unit
			case Node_Ada_Rename_Unit_Package:
			renameUnitPackageDeclaration(p_Tree);
			break;
			case Node_Ada_Rename_Unit:
			renameUnitDeclaration(p_Tree);
			break;
			
			
			/*****************
			 * list of decls *
			 *****************/
			
			//generic_decl
			case Node_Ada_Generic_Decl:
			genericDeclarationManagement(p_Tree);
			break;
			
			//subprog declaration
			case Node_Ada_Subprog_Decl:
			subprogDeclaration(p_Tree->getSon(0));
			break;
			
			case Node_Ada_Generic_Subprog_Inst:
			case Node_Ada_Abstract_Subprog_Decl:
			{
			}
			break;
			
			
			//type declaration
			case Node_Ada_Type_Decl:
			{
				typeDeclaration(p_Tree);
			}
			break;
			
			//object declaration
			case Node_Ada_Object_Decl:
			{
				objectDeclaration(p_Tree->getSon(0),p_Tree->getSon(1),p_Tree->getSon(2),p_Tree->getSon(3));
			}
			break;

			//number declaration
			case Node_Ada_Number_Decl:
			numberDeclaration(p_Tree->getSon(0),p_Tree->getSon(1));
			break;

			//subtype declaration
			case Node_Ada_Subtype_Decl:
			{
				subtypeDeclaration(p_Tree);
			}
			break;

		
			//exception decl
			case Node_Ada_Exception_Decl:
			{
			}
			break;

			//rename decl
			case Node_Ada_Rename_Decl:
			{
			}
			break;

			//body stub decl
			case Node_Ada_Body_Stub_Task:
			case Node_Ada_Body_Stub_Package:
			case Node_Ada_Body_Stub_SubProg:
			case Node_Ada_Body_Stub_Prot:
			{
			}
			break;
			
			/* Use and with clauses */
			/************************/
			case Node_Ada_Clause_Width:
			clauseWithTreatement(p_Tree->getSon(0));
			break;
			case Node_Ada_Use_Clause:
			clauseUseTreatement(p_Tree->getSon(0));
			break;
			
			default:
			{
				int index=0;
				for(index=0;index<p_Tree->getNbSon();index++)
				{
					tableSymboleCreation(p_Tree->getSon(index));
				}
			}
		}
		
		g_CurrentMainUnit=mainUnitSave;
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
}

type* accessTypeDeclaration(tree *p_Tree,const char *p_Name)
{
	#ifdef TRACE
	printfTraceUp("accessTypeDeclaration",__FILE__,__LINE__);
	#endif
	type* result=NULL;
	
	if(p_Tree!=NULL)
	{
		switch(p_Tree->getNodeType())
		{
			case Node_Ada_Access_Type:
			switch(p_Tree->getNbSon())
			{
				case 1:
				{
					printfDeclarationOf("access object type",p_Name,g_CurrentFile->getName(),p_Tree->getNumLine());
					access_object_type *t=new_access_object_type(p_Name,p_Tree,g_CurrentMainUnit);
					result=t;
				}
				break;
				case 2:
				{
					printfDeclarationOf("access procedure type",p_Name,g_CurrentFile->getName(),p_Tree->getNumLine());
					access_procedure_type *t=new access_procedure_type(p_Name,p_Tree->getSon(0),p_Tree->getSon(1),g_CurrentMainUnit);
					result=t;
				}
				break;
				case 3:
				{
					printfDeclarationOf("access function type",p_Name,g_CurrentFile->getName(),p_Tree->getNumLine());
					access_function_type *t=new access_function_type(p_Name,p_Tree->getSon(0),p_Tree->getSon(1),p_Tree->getSon(2),g_CurrentMainUnit);
					result=t;
				}
				break;
				default: 
				errorNbSon(__FILE__,__LINE__,p_Tree);
				my_exit(-1);
				break;
			}
			break;
			case Node_Ada_Access_Constant_Type:
			case Node_Ada_Access_All_Type:
			{
				printfDeclarationOf("access object type",p_Name,g_CurrentFile->getName(),p_Tree->getNumLine());
				access_object_type *t=new_access_object_type(p_Name,p_Tree,g_CurrentMainUnit);
				result=t;
			}
			break;
			default :errorNotAllowed(__FILE__,__LINE__,p_Tree,"access_type");
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
	printfTraceDown("accessTypeDeclaration",__FILE__,__LINE__);
	#endif
	return result;
}

type* arrayTypeDeclaration(tree *p_Tree,const char *p_Name)
{
	#ifdef TRACE
	printfTraceUp("arrayTypeDeclaration",__FILE__,__LINE__);
	#endif
	type* result=NULL;
	
	if(p_Tree!=NULL)
	{
		switch(p_Tree->getNodeType())
		{
			case Node_Ada_Unconstraint_Array_Type:
			printfDeclarationOf("unconstrained array type",p_Name,g_CurrentFile->getName(),p_Tree->getNumLine());
			break;
			case Node_Ada_Constraint_Array_Type:
			printfDeclarationOf("constrained array type",p_Name,g_CurrentFile->getName(),p_Tree->getNumLine());
			break;
			default : errorNotAllowed(__FILE__,__LINE__,p_Tree,"array_type");
			my_exit(-1);
			break;
		}
		array_type *t=new_array_type(p_Name,p_Tree,g_CurrentMainUnit);
		result=t;
			
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("arrayTypeDeclaration",__FILE__,__LINE__);
	#endif
	return result;
}

void clauseUseTreatement(tree *p_Tree)
{
	#ifdef TRACE
	printfTraceUp("clauseUseTreatement",__FILE__,__LINE__);
	#endif
	type* result=NULL;
	
	if(p_Tree!=NULL)
	{
		switch(p_Tree->getNodeType())
		{
			case Node_Ada_List_Name:
			clauseUseTreatement(p_Tree->getSon(0));
			clauseUseTreatement(p_Tree->getSon(1));
			break;
			default :
			g_CurrentMainUnit->addUseDependancie(new named(getString(p_Tree)));
			break;
		}
			
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("clauseUseTreatement",__FILE__,__LINE__);
	#endif
}

void clauseWithTreatement(tree *p_Tree)
{
	#ifdef TRACE
	printfTraceUp("clauseWithTreatement",__FILE__,__LINE__);
	#endif
	type* result=NULL;
	
	if(p_Tree!=NULL)
	{
		switch(p_Tree->getNodeType())
		{
			case Node_Ada_List_C_Name:
			clauseWithTreatement(p_Tree->getSon(0));
			clauseWithTreatement(p_Tree->getSon(1));
			break;
			default :
			g_CurrentMainUnit->addWithDependancie(new named(getString(p_Tree)));
			break;
		}
			
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("clauseWithTreatement",__FILE__,__LINE__);
	#endif
}

type* fixedTypeDeclaration(tree *p_Tree,const char *p_Name)
{
	#ifdef TRACE
	printfTraceUp("fixedTypeDeclaration",__FILE__,__LINE__);
	#endif
	type* result=NULL;
	
	if(p_Tree!=NULL)
	{
		switch(p_Tree->getNbSon())
		{
			case 2:
			{
				printfDeclarationOf("ordinary fixed type",p_Name,g_CurrentFile->getName(),p_Tree->getNumLine());
				ordinary_fixed_type *t=new_ordinary_fixed_type(p_Name,p_Tree->getSon(0),p_Tree->getSon(1),g_CurrentMainUnit);
				result=t;
			}
			break;
			case 3:
			{
				printfDeclarationOf("decimal fixed type",p_Name,g_CurrentFile->getName(),p_Tree->getNumLine());
				decimal_fixed_type *t=new_decimal_fixed_type(p_Name,p_Tree->getSon(0),p_Tree->getSon(1),p_Tree->getSon(2),g_CurrentMainUnit);
				result=t;
			}
			break;
			default: 
			errorNbSon(__FILE__,__LINE__,p_Tree);
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
	printfTraceDown("fixedTypeDeclaration",__FILE__,__LINE__);
	#endif
	return result;
	
}

void functionSpecDeclaration(tree *p_Tree)
{
	#ifdef TRACE
	printfTraceUp("functionSpecDeclaration",__FILE__,__LINE__);
	#endif
	if(p_Tree!=NULL)
	{
		function_spec *f=NULL;
		
		printfDeclarationOf("function",getString(p_Tree->getSon(0)),g_CurrentFile->getName(),p_Tree->getNumLine());
		
		switch(p_Tree->getNbSon())
		{
			case 1:
			break;
			case 3:
			f=new function_spec(getString(p_Tree->getSon(0)),p_Tree->getSon(1),p_Tree->getSon(2),g_CurrentMainUnit);
			break;
			default: 
			errorNbSon(__FILE__,__LINE__,p_Tree);
			my_exit(-1);
			break;
		}
		
		/* Build of symbol table */
		/*************************/
		p_Tree->setTableSymbolMember(f);
		g_CurrentMainUnit->add(f);
		g_TableSymbol->add(f);
		
		
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("functionSpecDeclaration",__FILE__,__LINE__);
	#endif
	
}

void genericDeclarationManagement(tree *p_Tree)
{
	#ifdef TRACE
	printfTraceUp("genericDeclarationManagement",__FILE__,__LINE__);
	#endif
	if(p_Tree!=NULL)
	{
	
		switch(p_Tree->getSon(1)->getNodeType())
		{
			case Node_Ada_Subprog_Spec:
			genericSubprogDeclaration(p_Tree);
			break;
			
			case Node_Ada_Package_Spec:
			genericPackageDeclaration(p_Tree);
			break;
			
			default:
			errorNotAllowed(__FILE__,__LINE__,p_Tree->getSon(1),"generic_decl");
			my_exit(-1);
			
		}
		
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("genericDeclarationManagement",__FILE__,__LINE__);
	#endif
	
}

void genericPackageDeclaration(tree *p_Tree)
{
	#ifdef TRACE
	printfTraceUp("genericPackageDeclaration",__FILE__,__LINE__);
	#endif
	if(p_Tree!=NULL)
	{
		printfDeclarationOf("generic package",getString(p_Tree->getSon(1)->getSon(0)),g_CurrentFile->getName(),p_Tree->getNumLine());
		tableSymboleCreation(p_Tree->getSon(1));
		
		//tableSymboleCreation(p_Tree->getSon(1)->getSon(1));
		//tableSymboleCreation(p_Tree->getSon(1)->getSon(2));
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("genericPackageDeclaration",__FILE__,__LINE__);
	#endif
	
}

void genericSubprogDeclaration(tree *p_Tree)
{
	#ifdef TRACE
	printfTraceUp("genericSubprogDeclaration",__FILE__,__LINE__);
	#endif
	if(p_Tree!=NULL)
	{
		printfDeclarationOf("generic subprog",getString(p_Tree->getSon(1)->getSon(0)),g_CurrentFile->getName(),p_Tree->getNumLine());
		tableSymboleCreation(p_Tree->getSon(1));
		
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("genericSubprogDeclaration",__FILE__,__LINE__);
	#endif
	
}
			
void genericPackageInstantiation(tree *p_Tree)
{
	#ifdef TRACE
	printfTraceUp("genericPackageInstantiation",__FILE__,__LINE__);
	#endif
	if(p_Tree!=NULL)
	{
	
		generic_package_inst *p=new_generic_package_inst(getString(p_Tree->getSon(0)),p_Tree->getSon(1)->getSon(0),g_CurrentMainUnit);
		if(g_Config->getVerbose()>0)
		{
			printf("instantiation of package \"%s\" generic of \"%s\" in file \"%s\" line %i\n",p->getName(),p->getGenericPackageName(),g_CurrentFile->getName(),p_Tree->getNumLine());
		}
		
		/* Build of symbol table */
		/*************************/
		p_Tree->setTableSymbolMember(p);
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("genericPackageInstantiation",__FILE__,__LINE__);
	#endif
	
}

type* integerTypeDeclaration(tree *p_Tree,const char *p_Name)
{
	#ifdef TRACE
	printfTraceUp("integerTypeDeclaration",__FILE__,__LINE__);
	#endif
	type* result=0;
	
	if(p_Tree!=NULL)
	{
		switch(p_Tree->getNodeType())
		{
			case Node_Ada_Integer_Type:
			if(p_Tree->getSon(0)->getNodeType()==Node_Ada_Range_Constraint)
			{
				if(p_Tree->getSon(0)->getSon(0)->getNodeType()==Node_Ada_Range_Inter)
				{
					printfDeclarationOf("signed integer type",p_Name,g_CurrentFile->getName(),p_Tree->getNumLine());
					signed_integer_type *t=new signed_integer_type(p_Name,p_Tree->getSon(0)->getSon(0)->getSon(0),p_Tree->getSon(0)->getSon(0)->getSon(1),g_CurrentMainUnit);
					result=t;
				}
				else
				{
					errorNotAllowed(__FILE__,__LINE__,p_Tree->getSon(0)->getSon(0),"range");
					my_exit(-1);
				}
			}
			else
			{
				errorNotAllowed(__FILE__,__LINE__,p_Tree->getSon(0),"range_spec");
				my_exit(-1);
			}
			break;
			case Node_Ada_Mod_Integer_Type:
			{
				printfDeclarationOf("modular integer type",p_Name,g_CurrentFile->getName(),p_Tree->getNumLine());
				modular_integer_type *t=new modular_integer_type(p_Name,p_Tree->getSon(0),g_CurrentMainUnit);
				result=t;
			}
			break;
			default :
			errorNotAllowed(__FILE__,__LINE__,p_Tree,"type_def integer_declaration");
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
	printfTraceDown("integerTypeDeclaration",__FILE__,__LINE__);
	#endif
	return result;
}

void numberDeclaration(tree *p_Tree,tree *p_TreeInit)
{
	#ifdef TRACE
	printfTraceUp("numberDeclaration",__FILE__,__LINE__);
	#endif
	if(p_Tree!=NULL && p_TreeInit!=NULL)
	{
		switch(p_Tree->getNodeType())
		{
			case Node_Ada_List_Identifier:
			numberDeclaration(p_Tree->getSon(0),p_TreeInit);
			numberDeclaration(p_Tree->getSon(1),p_TreeInit);
			break;
			case Node_Ada_C_Ident:
			{
				printfDeclarationOf("constant number",p_Tree->getString(),g_CurrentFile->getName(),p_Tree->getNumLine());
				constant_number *cn=new constant_number(p_Tree->getString(),p_TreeInit,g_CurrentMainUnit);
				
				/* Build of symbol table */
				/*************************/
				p_Tree->setTableSymbolMember(cn);
				g_CurrentMainUnit->add(cn);
				g_TableSymbol->add(cn);
			}
			break;
		}
	}
	else
	{
		int error=0;
		if(p_Tree==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_Tree");
			error=1;
		}
		if(p_TreeInit==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_TreeInit");
			error=1;
		}
		if(error!=0)
		{
			my_exit(-1);
		}
	}
	#ifdef TRACE
	printfTraceDown("numberDeclaration",__FILE__,__LINE__);
	#endif
	
}

void objectDeclaration(tree *p_IdentifierTree,tree *p_ObjectQualifierTree, tree *p_ObjectSubtypeDef, tree *p_InitTree)
{
	#ifdef TRACE
	printfTraceUp("objectDeclaration",__FILE__,__LINE__);
	#endif
	if(p_IdentifierTree!=NULL && p_ObjectQualifierTree!=NULL && p_ObjectSubtypeDef!=NULL && p_InitTree!=NULL)
	{
		switch(p_IdentifierTree->getNodeType())
		{
			case Node_Ada_List_Identifier:
			objectDeclaration(p_IdentifierTree->getSon(0),p_ObjectQualifierTree,p_ObjectSubtypeDef,p_InitTree);
			objectDeclaration(p_IdentifierTree->getSon(1),p_ObjectQualifierTree,p_ObjectSubtypeDef,p_InitTree);
			break;
			case Node_Ada_C_Ident:
			{
				variable *result=NULL;
				switch(p_ObjectSubtypeDef->getNodeType())
				{
					case Node_Ada_Subtype_Indication:
					{
					printfDeclarationOf("variable object",p_IdentifierTree->getString(),g_CurrentFile->getName(),p_IdentifierTree->getNumLine());
					variable_object *vo=new_variable_object(p_IdentifierTree->getString(),p_ObjectQualifierTree,p_ObjectSubtypeDef,p_InitTree,g_CurrentMainUnit);
					result=vo;
					
					/* Build of symbol table */
					/*************************/
					p_IdentifierTree->setTableSymbolMember(vo);
					g_CurrentMainUnit->add(vo);
					g_TableSymbol->add(vo);
					
					}
					break;
					case Node_Ada_Constraint_Array_Type:
					case Node_Ada_Unconstraint_Array_Type:
					{
					printfDeclarationOf("variable array",p_IdentifierTree->getString(),g_CurrentFile->getName(),p_IdentifierTree->getNumLine());
					variable_array *va=new_variable_array(p_IdentifierTree->getString(),p_ObjectQualifierTree,p_ObjectSubtypeDef,p_InitTree,g_CurrentMainUnit);
					result=va;
					
					/* Build of symbol table */
					/*************************/
					p_IdentifierTree->setTableSymbolMember(va);
					g_CurrentMainUnit->add(va);
					g_TableSymbol->add(va);
					}
					break;
					default:errorNotAllowed(__FILE__,__LINE__,p_ObjectSubtypeDef,"object_subtype_def");
					my_exit(-1);
				}
				
					
				
				
			}
			break;
			default:errorNotAllowed(__FILE__,__LINE__,p_IdentifierTree,"def_id_s");
			my_exit(-1);
			break;
		}
	}
	else
	{
		int error=0;
		if(p_IdentifierTree==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_IdentifierTree");
			error=1;
		}
		
		if(p_ObjectQualifierTree==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_ObjectQualifierTree");
			error=1;
		}
		
		if(p_ObjectSubtypeDef==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_ObjectSubtypeDef");
			error=1;
		}
		
		if(p_InitTree==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_InitTree");
			error=1;
		}
		
		if(error!=0)
		{
			my_exit(-1);
		}
	}
	#ifdef TRACE
	printfTraceDown("objectDeclaration",__FILE__,__LINE__);
	#endif
	
}

void packageBodyDeclaration(tree *p_Tree)
{
	#ifdef TRACE
	printfTraceUp("packageBodyDeclaration",__FILE__,__LINE__);
	#endif
	if(p_Tree!=NULL)
	{
		printfDeclarationOf("package body",getString(p_Tree->getSon(0)),g_CurrentFile->getName(),p_Tree->getNumLine());
		package_body *p=new package_body(getString(p_Tree->getSon(0)),g_CurrentMainUnit);
		
		/* Build of symbol table */
		/*************************/
		p_Tree->setTableSymbolMember(p);
		g_CurrentMainUnit->add(p);
		g_TableSymbol->add(p);
		g_CurrentMainUnit=p;
		
		tableSymboleCreation(p_Tree->getSon(1));
		tableSymboleCreation(p_Tree->getSon(2));
		
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("packageBodyDeclaration",__FILE__,__LINE__);
	#endif
	
}

void packageDeclarationManagement(tree *p_Tree)
{
	#ifdef TRACE
	printfTraceUp("packageDeclarationManagement",__FILE__,__LINE__);
	#endif
	if(p_Tree!=NULL)
	{
	
		switch(p_Tree->getNodeType())
		{
			case Node_Ada_Package_Spec:
			packageSpecDeclaration(p_Tree);
			break;
			
			case Node_Ada_Generic_Package_Inst:
			genericPackageInstantiation(p_Tree);
			break;
			
			default:
			printf("ERROR : %s %i : node type isn't valid : ",__FILE__,__LINE__);
			displayNodeType(p_Tree->getNodeType());
			printf("\n");
			my_exit(-1);
			
		}
		
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("packageDeclarationManagement",__FILE__,__LINE__);
	#endif
	
	
}

void packageSpecDeclaration(tree *p_Tree)
{
	#ifdef TRACE
	printfTraceUp("packageSpecDeclaration",__FILE__,__LINE__);
	#endif
	if(p_Tree!=NULL)
	{
		printfDeclarationOf("package",getString(p_Tree->getSon(0)),g_CurrentFile->getName(),p_Tree->getNumLine());
		package_spec *p=new package_spec(getString(p_Tree->getSon(0)),g_CurrentMainUnit);
		
		
		/* The current file contain a package spec so it will be translated as header file */
		g_CurrentFile->setBoolHeader(1);
		
		/* Build of symbol table */
		/*************************/
		p_Tree->setTableSymbolMember(p);
		g_CurrentMainUnit->add(p);
		g_TableSymbol->add(p);
		g_CurrentMainUnit=p;
		
		
		tableSymboleCreation(p_Tree->getSon(1));
		tableSymboleCreation(p_Tree->getSon(2));
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("packageSpecDeclaration",__FILE__,__LINE__);
	#endif
	
}

void packageSubunitDeclaration(tree *p_Tree)
{
	#ifdef TRACE
	printfTraceUp("packageSubunitDeclaration",__FILE__,__LINE__);
	#endif
	if(p_Tree!=NULL)
	{
		printfDeclarationOf("subunit",getString(p_Tree->getSon(0)),g_CurrentFile->getName(),p_Tree->getNumLine());
		subunit *s=new subunit(g_CurrentFile->getName(),getString(p_Tree->getSon(0)),g_CurrentMainUnit);
		
		/* Build of symbol table */
		/*************************/
		p_Tree->setTableSymbolMember(s);
		//g_CurrentMainUnit->add(s);
		//g_TableSymbol->add(s);
		g_CurrentMainUnit=s;
		
		tableSymboleCreation(p_Tree->getSon(1));
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("packageSubunitDeclaration",__FILE__,__LINE__);
	#endif
	
}

void procedureSpecDeclaration(tree *p_Tree)
{
	#ifdef TRACE
	printfTraceUp("procedureSpecDeclaration",__FILE__,__LINE__);
	#endif
	if(p_Tree!=NULL)
	{
		printfDeclarationOf("procedure",getString(p_Tree->getSon(0)),g_CurrentFile->getName(),p_Tree->getNumLine());
		procedure_spec *p=new procedure_spec(getString(p_Tree->getSon(0)),p_Tree->getSon(1),g_CurrentMainUnit);
		
		/* Build of symbol table */
		/*************************/
		p_Tree->setTableSymbolMember(p);
		g_CurrentMainUnit->add(p);
		g_TableSymbol->add(p);
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("procedureSpecDeclaration",__FILE__,__LINE__);
	#endif
	
}


void protBodyDeclaration(tree *p_Tree)
{
	#ifdef TRACE
	printfTraceUp("protBodyDeclaration",__FILE__,__LINE__);
	#endif
	if(p_Tree!=NULL)
	{
			
		printfDeclarationOf("protected body",getString(p_Tree->getSon(0)),g_CurrentFile->getName(),p_Tree->getNumLine());

		prot *p=new prot(Prot_Normal,getString(p_Tree->getSon(0)),g_CurrentMainUnit);
		
		/* Build of symbol table */
		/*************************/
		p_Tree->setTableSymbolMember(p);
		//g_CurrentMainUnit->add(p);
		//g_TableSymbol->add(p);
		g_CurrentMainUnit=p;
		
		tableSymboleCreation(p_Tree->getSon(1));			
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("protBodyDeclaration",__FILE__,__LINE__);
	#endif
	
}
void protDeclaration(tree *p_Tree)
{
	#ifdef TRACE
	printfTraceUp("protDeclaration",__FILE__,__LINE__);
	#endif
	if(p_Tree!=NULL)
	{
		switch(p_Tree->getNodeType())
		{
		
			case Node_Ada_Prot_Spec:
			{	
				printfDeclarationOf("protected",getString(p_Tree->getSon(0)),g_CurrentFile->getName(),p_Tree->getNumLine());

				prot *p=NULL;

				switch(p_Tree->getNbSon())
				{
					case 2:p=new prot(Prot_Normal,getString(p_Tree->getSon(0)),g_CurrentMainUnit);
					
					/* Build of symbol table */
					/*************************/
					p_Tree->setTableSymbolMember(p);
					//g_CurrentMainUnit->add(p);
					//g_TableSymbol->add(p);
					g_CurrentMainUnit=p;
					
					protDeclaration(p_Tree->getSon(1));
					break;
					case 3:p=new_prot_type(getString(p_Tree->getSon(0)),p_Tree->getSon(1),g_CurrentMainUnit);
					
					/* Build of symbol table */
					/*************************/
					p_Tree->setTableSymbolMember(p);
					//g_CurrentMainUnit->add(p);
					//g_TableSymbol->add(p);
					g_CurrentMainUnit=p;
					
					protDeclaration(p_Tree->getSon(2));
					break;
					default :
					errorNbSon(__FILE__,__LINE__,p_Tree);
					my_exit(-1);
					break;
				}

			}
			break;
			case Node_Ada_C_Empty:
			break;
			case Node_Ada_Prot_Def:
			tableSymboleCreation(p_Tree->getSon(0));
			tableSymboleCreation(p_Tree->getSon(1));
			break;
			default : errorNotAllowed(__FILE__,__LINE__,p_Tree,"prot_decl, prot_def, prot_spec");
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
	printfTraceDown("protDeclaration",__FILE__,__LINE__);
	#endif
	
}

void renameUnitDeclaration(tree *p_Tree)
{
	#ifdef TRACE
	printfTraceUp("renameUnitDeclaration",__FILE__,__LINE__);
	#endif
	if(p_Tree!=NULL)
	{
		char generic=0;
		tree *subprogTree=NULL;
		tree *renamesTree=NULL;
		
		switch(p_Tree->getNbSon())
		{
			case 2:generic=0;
			subprogTree=p_Tree->getSon(0);
			renamesTree=p_Tree->getSon(1);
			printfDeclarationOf("subprog rename unit",getString(p_Tree->getSon(0)->getSon(0)),g_CurrentFile->getName(),p_Tree->getNumLine());
			break;
			case 3:generic=1;
			renamesTree=p_Tree->getSon(1);
			subprogTree=p_Tree->getSon(2);
			printfDeclarationOf("generic subprog rename",getString(p_Tree->getSon(1)->getSon(0)),g_CurrentFile->getName(),p_Tree->getNumLine());
			if(p_Tree->getSon(0)->getNodeType()!=Node_Ada_Generic && p_Tree->getSon(0)->getNodeType()!=Node_Ada_Generic_Formal_Part)
			{
				printf("ERROR : %s %i : ",__FILE__,__LINE__);
				displayNodeType(p_Tree->getSon(0)->getNodeType());
				printf(" is not a valid node type for ada reference manual\n");
				my_exit(-1);
			}
			break;
			default :
			errorNbSon(__FILE__,__LINE__,p_Tree);
			my_exit(-1);
			break;
		}
		
		switch(subprogTree->getNbSon())
		{
			case 1:
			break;
			case 2:
			{
				procedure_rename *p=new procedure_rename(getString(subprogTree->getSon(0)),subprogTree->getSon(1),getString(renamesTree->getSon(0)),generic,g_CurrentMainUnit);
				/* Build of symbol table */
				/*************************/
				p_Tree->setTableSymbolMember(p);
				g_CurrentMainUnit->add(p);
				g_TableSymbol->add(p);
			}
			break;
			case 3:
			{
				function_rename *f=new function_rename(getString(subprogTree->getSon(0)),subprogTree->getSon(1),subprogTree->getSon(2),getString(renamesTree->getSon(0)),generic,g_CurrentMainUnit);
				/* Build of symbol table */
				/*************************/
				p_Tree->setTableSymbolMember(f);
				g_CurrentMainUnit->add(f);
				g_TableSymbol->add(f);
			}
			break;
			default: 
			errorNbSon(__FILE__,__LINE__,subprogTree);
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
	printfTraceDown("renameUnitDeclaration",__FILE__,__LINE__);
	#endif
	
}

void renameUnitPackageDeclaration(tree *p_Tree)
{
	#ifdef TRACE
	printfTraceUp("renameUnitPackageDeclaration",__FILE__,__LINE__);
	#endif
	if(p_Tree!=NULL)
	{
		char generic=0;
		package_rename *p=NULL;
		
		switch(p_Tree->getNbSon())
		{
			case 2:generic=0;
			printfDeclarationOf("package rename unit",getString(p_Tree->getSon(0)),g_CurrentFile->getName(),p_Tree->getNumLine());
			p=new package_rename(getString(p_Tree->getSon(0)),getString(p_Tree->getSon(1)->getSon(0)),generic,g_CurrentMainUnit);
			break;
			case 3:generic=1;
			printfDeclarationOf("package rename unit",getString(p_Tree->getSon(1)),g_CurrentFile->getName(),p_Tree->getNumLine());
			if(p_Tree->getSon(0)->getNodeType()!=Node_Ada_Generic && p_Tree->getSon(0)->getNodeType()!=Node_Ada_Generic_Formal_Part)
			{
				printf("ERROR : %s %i : ",__FILE__,__LINE__);
				displayNodeType(p_Tree->getSon(0)->getNodeType());
				printf(" is not a valid node type for ada reference manual\n");
				my_exit(-1);
			}
			p=new package_rename(getString(p_Tree->getSon(1)),getString(p_Tree->getSon(2)->getSon(0)),generic,g_CurrentMainUnit);
			break;
			default : errorNbSon(__FILE__,__LINE__,p_Tree);
			my_exit(-1);
			break;
		}
		/* Build of symbol table */
		/*************************/
		p_Tree->setTableSymbolMember(p);
		g_CurrentMainUnit->add(p);
		g_TableSymbol->add(p);
					
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("renameUnitPackageDeclaration",__FILE__,__LINE__);
	#endif
	
}

void subprogBodyDeclaration(tree *p_Tree)
{
	#ifdef TRACE
	printfTraceUp("subprogBodyDeclaration",__FILE__,__LINE__);
	#endif
	if(p_Tree!=NULL)
	{
		tree* spec=p_Tree->getSon(0);
		
		switch(spec->getNbSon())
		{
			case 1:errorNbSon(__FILE__,__LINE__,spec);
			my_exit(-1);
			break;
			case 3:
			{
				printfDeclarationOf("function body",getString(spec->getSon(0)),g_CurrentFile->getName(),p_Tree->getNumLine());
				function_body *f=new function_body(getString(spec->getSon(0)),spec->getSon(1),spec->getSon(2),g_CurrentMainUnit);
				/* Build of symbol table */
				/*************************/
				p_Tree->setTableSymbolMember(f);
				//g_CurrentMainUnit->add(f);
				//g_TableSymbol->add(f);
				g_CurrentMainUnit=f;
					
			}
			break;
			case 2:
			{
				printfDeclarationOf("procedure body",getString(spec->getSon(0)),g_CurrentFile->getName(),p_Tree->getNumLine());
				procedure_body *p=new procedure_body(getString(spec->getSon(0)),spec->getSon(1),g_CurrentMainUnit);
				/* Build of symbol table */
				/*************************/
				p_Tree->setTableSymbolMember(p);
				//g_CurrentMainUnit->add(p);
				//g_TableSymbol->add(p);
				g_CurrentMainUnit=p;
					
			}
			break;
			default : errorNbSon(__FILE__,__LINE__,p_Tree);
			my_exit(-1);
			break;
			
		}
		
		tableSymboleCreation(p_Tree->getSon(1));
		tableSymboleCreation(p_Tree->getSon(2));
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("subprogBodyDeclaration",__FILE__,__LINE__);
	#endif
	
}

void subprogDeclaration(tree *p_Tree)
{
	#ifdef TRACE
	printfTraceUp("subprogDeclaration",__FILE__,__LINE__);
	#endif
	if(p_Tree!=NULL)
	{
		switch(p_Tree->getNbSon())
		{
			case 2:
			procedureSpecDeclaration(p_Tree);
			break;
			case 1:
			break;
			case 3:
			functionSpecDeclaration(p_Tree);
			break;
			default:
			errorNbSon(__FILE__,__LINE__,p_Tree);
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
	printfTraceDown("subprogDeclaration",__FILE__,__LINE__);
	#endif
	
}

void subtypeDeclaration(tree *p_Tree)
{
	#ifdef TRACE
	printfTraceUp("subtypeDeclaration",__FILE__,__LINE__);
	#endif
	if(p_Tree!=NULL)
	{
			
		printfDeclarationOf("subtype",p_Tree->getSon(0)->getString(),g_CurrentFile->getName(),p_Tree->getNumLine());

		subtype *s=new_subtype(p_Tree->getSon(0)->getString(),p_Tree->getSon(1),g_CurrentMainUnit);;
		/* Build of symbol table */
		/*************************/
		p_Tree->setTableSymbolMember(s);
		g_CurrentMainUnit->add(s);
		g_TableSymbol->add(s);
			
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("subtypeDeclaration",__FILE__,__LINE__);
	#endif
}

void taskBodyDeclaration(tree *p_Tree)
{
	#ifdef TRACE
	printfTraceUp("taskBodyDeclaration",__FILE__,__LINE__);
	#endif
	if(p_Tree!=NULL)
	{
			
		printfDeclarationOf("task body",getString(p_Tree->getSon(0)),g_CurrentFile->getName(),p_Tree->getNumLine());

		task *t=new task(Task_Normal,getString(p_Tree->getSon(0)),g_CurrentMainUnit);;
		/* Build of symbol table */
		/*************************/
		p_Tree->setTableSymbolMember(t);
		//g_CurrentMainUnit->add(t);
		//g_TableSymbol->add(t);
		g_CurrentMainUnit=t;
		
		tableSymboleCreation(p_Tree->getSon(1));
		tableSymboleCreation(p_Tree->getSon(2));
			
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("taskBodyDeclaration",__FILE__,__LINE__);
	#endif
	
}

void taskDeclaration(tree *p_Tree)
{
	#ifdef TRACE
	printfTraceUp("taskDeclaration",__FILE__,__LINE__);
	#endif
	if(p_Tree!=NULL)
	{
		switch(p_Tree->getNodeType())
		{
		
			case Node_Ada_Task_Spec:
			{	
				printfDeclarationOf("task",getString(p_Tree->getSon(0)),g_CurrentFile->getName(),p_Tree->getNumLine());

				task *t=NULL;

				switch(p_Tree->getNbSon())
				{
					case 2:t=new task(Task_Normal,getString(p_Tree->getSon(0)),g_CurrentMainUnit);
					/* Build of symbol table */
					/*************************/
					p_Tree->setTableSymbolMember(t);
					//g_CurrentMainUnit->add(t);
					//g_TableSymbol->add(t);
					g_CurrentMainUnit=t;
					
					taskDeclaration(p_Tree->getSon(1));
					break;
					case 3:t=new_task_type(getString(p_Tree->getSon(0)),p_Tree->getSon(1),g_CurrentMainUnit);
					/* Build of symbol table */
					/*************************/
					p_Tree->setTableSymbolMember(t);
					//g_CurrentMainUnit->add(t);
					//g_TableSymbol->add(t);
					g_CurrentMainUnit=t;
					
					taskDeclaration(p_Tree->getSon(2));
					break;
					default : errorNbSon(__FILE__,__LINE__,p_Tree);
					my_exit(-1);
					break;
				}
			}
			break;
			case Node_Ada_C_Empty:
			break;
			case Node_Ada_Task_Def:
			tableSymboleCreation(p_Tree->getSon(0));
			tableSymboleCreation(p_Tree->getSon(1));
			tableSymboleCreation(p_Tree->getSon(2));
			break;
			default : printf("ERROR : %s %i : node type ");
			displayNodeType(p_Tree->getNodeType());
			printf(" is not authorized by Ada grammar\n");
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
	printfTraceDown("taskDeclaration",__FILE__,__LINE__);
	#endif
	
}

void typeDeclaration(tree *p_Tree)
{
	#ifdef TRACE
	printfTraceUp("typeDeclaration",__FILE__,__LINE__);
	#endif
	if(p_Tree!=NULL)
	{
		if(p_Tree->getNbSon()==3)
		{
			type* t=NULL;
			switch(p_Tree->getSon(2)->getNodeType())
			{
				case Node_Ada_Enumeration_Type:
				printfDeclarationOf("enumerated type",p_Tree->getSon(0)->getString(),g_CurrentFile->getName(),p_Tree->getNumLine());
				t=new_enumerated_type(p_Tree->getSon(0)->getString(),p_Tree->getSon(2)->getSon(0),g_CurrentMainUnit);
				break;
				case Node_Ada_Integer_Type:
				case Node_Ada_Mod_Integer_Type:
				t=integerTypeDeclaration(p_Tree->getSon(2),p_Tree->getSon(0)->getString());
				break;
				case Node_Ada_Record_Type:
				printfDeclarationOf("record type",p_Tree->getSon(0)->getString(),g_CurrentFile->getName(),p_Tree->getNumLine());
				t=new_record_type(p_Tree->getSon(0)->getString(),p_Tree->getSon(1),p_Tree->getSon(2),g_CurrentMainUnit);
				break;
				
				case Node_Ada_Derived_Type_With_Private:
				case Node_Ada_Derived_Type_With_Record:
				case Node_Ada_Abstract_Derived_Type_With_Private:
				case Node_Ada_Abstract_Derived_Type_With_Record:
				case Node_Ada_Derived_Type:
				printfDeclarationOf("derived typed",p_Tree->getSon(0)->getString(),g_CurrentFile->getName(),p_Tree->getNumLine());
				t=new_derived_type(p_Tree->getSon(0)->getString(),p_Tree->getSon(2)->getSon(0),g_CurrentMainUnit);
				break;
				case Node_Ada_Unconstraint_Array_Type:
				case Node_Ada_Constraint_Array_Type:
				t=arrayTypeDeclaration(p_Tree->getSon(2),p_Tree->getSon(0)->getString());
				break;
				case Node_Ada_Float_Type:
				printfDeclarationOf("float type",p_Tree->getSon(0)->getString(),g_CurrentFile->getName(),p_Tree->getNumLine());
				t=new_float_type(p_Tree->getSon(0)->getString(),p_Tree->getSon(2)->getSon(0),p_Tree->getSon(2)->getSon(1),g_CurrentMainUnit);
				break;
				case Node_Ada_Fixed_Type:
				t=fixedTypeDeclaration(p_Tree->getSon(2),p_Tree->getSon(0)->getString());
				break;
				case Node_Ada_Private_Type:
				break;
				case Node_Ada_Access_All_Type:
				case Node_Ada_Access_Constant_Type:
				case Node_Ada_Access_Type:
				t=accessTypeDeclaration(p_Tree->getSon(2),p_Tree->getSon(0)->getString());
				break;
				default : printf("ERROR : %s %i : node type ",__FILE__,__LINE__);
				displayNodeType(p_Tree->getSon(2)->getNodeType());
				printf(" is not authorized by Ada grammar\n");
				my_exit(-1);
				break;
			}
			
			if(t!=NULL)
			{
				/* Build of symbol table */
				/*************************/
				p_Tree->setTableSymbolMember(t);
				g_CurrentMainUnit->add(t);
				g_TableSymbol->add(t);
			}
				
		}
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Tree");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("typeDeclaration",__FILE__,__LINE__);
	#endif
}
