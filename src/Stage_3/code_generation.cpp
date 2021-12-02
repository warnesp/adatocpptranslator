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
 * Description: generation of output code
 *
 * $Log: code_generation.cpp,v $
 * Revision 1.2  2005/03/19 13:21:57  quicky2000
 * Update to generate code for:
 * _ unconstrained array types
 * _ using namespace instructions
 * _ subprogram pointers
 *
 * Revision 1.1  2005/03/07 23:45:58  quicky2000
 * Update for code maintenance
 *
 * Revision 1.2  2005/03/03 22:12:24  quicky2000
 * Update to hat a forgotten node : Node_C_Labelled_Stmt
 *
 * Revision 1.1.1.1  2005/03/01 22:20:34  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "code_generation.h"

void generateCode(FILE *p_Fp,char p_BoolHeader,const char *p_SourceName,char *p_NewName,tree *p_Tree)
{
	#ifdef TRACE
	printfTraceUp("generateCode",__FILE__,__LINE__);
	#endif
	if( p_Fp!=NULL)
	{
		g_Config->write( p_Fp, p_SourceName);
		
		if( p_BoolHeader!=0)
		{
			char *l_Constant=myUpperCase( p_NewName);
			fprintf( p_Fp , "#ifndef %s\n",l_Constant);
			indentUp();
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "#define %s\n\n",l_Constant);
			generateCode( p_Fp, p_Tree);
			indentDown();
			fprintf( p_Fp , "\n#endif\n");
		}
		else
		{
			generateCode( p_Fp, p_Tree);
		}
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Fp");
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("generateCode",__FILE__,__LINE__);
	#endif
	
}

void generateCode(FILE *p_Fp,tree *p_Tree)
{
	if( p_Tree!=NULL && p_Fp!=NULL)
	{
		#ifdef TRACE_CODE_GENERATION
		printf("generation of code of node \"");
		displayNodeType( p_Tree->getNodeType());
		printf("\"\n");
		#endif
		
		if( p_Tree->getComment()!=NULL)
		{
			comment *r_Comment=p_Tree->getComment();
			while(r_Comment!=NULL)
			{
				if(r_Comment->getCommentText()!=NULL)
				{
					fprintfIndent( p_Fp );
					fprintf( p_Fp , "// %s\n",(r_Comment->getCommentText()+2));
				}
				r_Comment=r_Comment->getNext();
			}
		}
		
		switch( p_Tree->getNodeType())
		{
			case Node_Ada_Abort_Stmt:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "abort ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Abs:
			fprintf( p_Fp , "abs ");
			generateCode( p_Fp, p_Tree->getSon(0));
			break;
			
			case Node_Ada_Abstract_Derived_Type_With_Private:
			fprintf( p_Fp , "abstract new ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " with private");
			break;
			
			case Node_Ada_Abstract_Derived_Type_With_Record:
			fprintf( p_Fp , "abstract new ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " with\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(1));
			indentDown();
			break;
			
			case Node_Ada_Abstract_Subprog_Decl:
			fprintfIndent( p_Fp );
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " is abstract;\n");
			break;
			
			case Node_Ada_Abstract_Tagged:
			fprintf( p_Fp , "abstract tagged");
			break;
			
			case Node_Ada_Accept_Hdr:
			fprintf( p_Fp , "accept ");
			generateCode( p_Fp, p_Tree->getSon(0));
			if( p_Tree->getSon(1)->getNodeType()!=Node_Ada_C_Empty)
			{
				fprintf( p_Fp , " ");
			}
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Accept_Stmt:
			fprintfIndent( p_Fp );
			switch( p_Tree->getNbSon())
			{
				case 1:
				generateCode( p_Fp, p_Tree->getSon(0));
				break;
				case 3:
				generateCode( p_Fp, p_Tree->getSon(0));
				fprintf( p_Fp , "\n");
				fprintfIndent( p_Fp );
				fprintf( p_Fp , "do\n");
				indentUp();
				generateCode( p_Fp, p_Tree->getSon(1));
				indentDown();
				fprintfIndent( p_Fp );
				fprintf( p_Fp , "end");
				if( p_Tree->getSon(2)->getNodeType()!=Node_Ada_C_Empty)
				{
					fprintf( p_Fp , " ");
				}
				generateCode( p_Fp, p_Tree->getSon(2));
				break;
				default: 
				errorNbSon(__FILE__,__LINE__, p_Tree);
				my_exit(-1);
				break;
			}
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Access:
			fprintf( p_Fp , "access");
			break;
			
			case Node_Ada_Access_All_Type:
			fprintf( p_Fp , "access all ");
			generateCode( p_Fp, p_Tree->getSon(0));
			break;
			
			case Node_Ada_Access_Constant_Type:
			fprintf( p_Fp , "access constant ");
			generateCode( p_Fp, p_Tree->getSon(0));
			break;
			
			case Node_Ada_Access_Type:
			fprintf( p_Fp , "access ");
			generateCode( p_Fp, p_Tree->getSon(0));
			switch( p_Tree->getNbSon())
			{
				case 1:
				break;
				case 2:
				if( p_Tree->getSon(0)->getNodeType()!=Node_Ada_C_Empty)
				{
					fprintf( p_Fp , " ");
				}
				fprintf( p_Fp , "procedure");
				if( p_Tree->getSon(1)->getNodeType()!=Node_Ada_C_Empty)
				{
					fprintf( p_Fp , " ");
				}
				generateCode( p_Fp, p_Tree->getSon(1));
				break;
				case 3:
				fprintf( p_Fp , " function");
				if( p_Tree->getSon(1)->getNodeType()!=Node_Ada_C_Empty)
				{
					fprintf( p_Fp , " ");
				}
				generateCode( p_Fp, p_Tree->getSon(1));
				fprintf( p_Fp , " return ");
				generateCode( p_Fp, p_Tree->getSon(2));
				break;
				default: 
				errorNbSon(__FILE__,__LINE__, p_Tree);
				my_exit(-1);
				break;
			}
			break;
			
			case Node_Ada_Address_Spec:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "for ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " use at ");
			generateCode( p_Fp, p_Tree->getSon(1));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Affect:
			fprintfIndent( p_Fp );
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " := ");
			generateCode( p_Fp, p_Tree->getSon(1));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Aggregate:
			fprintf( p_Fp , "(");
			generateCode( p_Fp, p_Tree->getSon(0));
			switch( p_Tree->getNbSon())
			{
				case 1:
				break;
				case 2:
				fprintf( p_Fp , " with ");
				generateCode( p_Fp, p_Tree->getSon(1));
				break;
				default:
				errorNbSon(__FILE__,__LINE__, p_Tree);
				my_exit(-1);
				break;
			}
			fprintf( p_Fp , ")");
			break;
			
			case Node_Ada_Aggregate_Null_Record:
			fprintf( p_Fp , "(");
			switch( p_Tree->getNbSon())
			{
				case 0:
				break;
				case 1:
				generateCode( p_Fp, p_Tree->getSon(0));
				fprintf( p_Fp , " with ");
				break;
				default:
				errorNbSon(__FILE__,__LINE__, p_Tree);
				my_exit(-1);
				break;
			}
			fprintf( p_Fp , "null record)");
			break;
			
			case Node_Ada_Aliased:
			fprintf( p_Fp , "aliased");
			break;
			
			case Node_Ada_Aliased_Constant:
			fprintf( p_Fp , "aliased constant");
			break;
			
			case Node_Ada_Align_Opt:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "at mod ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Allocator:
			fprintf( p_Fp , "new ");
			generateCode( p_Fp, p_Tree->getSon(0));
			break;
			
			case Node_Ada_Alternative:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "when ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " =>\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(1));
			indentDown();
			break;
			
			case Node_Ada_And:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " and ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_C_And_Com:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " & ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_And_Then:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " and then ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Async_Select:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "select\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(0));
			indentDown();
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "then abort\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(1));
			indentDown();
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "end select;\n");
			break;
			
			case Node_Ada_Attrib_Def:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "for ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " use ");
			generateCode( p_Fp, p_Tree->getSon(1));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Attribute:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , "'");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Basic_Loop:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "loop\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(0));
			indentDown();
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "end loop");
			break;
			
			case Node_Ada_Block_Body:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "begin\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(0));
			indentDown();
			break;
			
			case Node_Ada_Block:
			fprintfIndent( p_Fp );
			generateCode( p_Fp, p_Tree->getSon(0));
			if( p_Tree->getSon(0)->getNodeType()!=Node_Ada_C_Empty)
			{
				fprintf( p_Fp , "\n");
			}
			generateCode( p_Fp, p_Tree->getSon(1));
			generateCode( p_Fp, p_Tree->getSon(2));
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "end");
			if( p_Tree->getSon(3)->getNodeType()!=Node_Ada_C_Empty)
			{
				fprintf( p_Fp , " ");
				generateCode( p_Fp, p_Tree->getSon(3));
			}
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Block_Decl:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "declare\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(0));
			indentDown();
			break;
			
			case Node_Ada_Body_Stub_Package:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "package body ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " is separate;\n");
			break;
			
			case Node_Ada_Body_Stub_Prot:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "protected body ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " is separate;\n");
			break;
			
			case Node_Ada_Body_Stub_SubProg:
			fprintfIndent( p_Fp );
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " is separate;\n");
			break;
			
			case Node_Ada_Body_Stub_Task:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "task body ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " is separate;\n");
			break;
			
			case Node_Ada_Case:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "case ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " is\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(1));
			generateCode( p_Fp, p_Tree->getSon(2));
			indentDown();
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "end case;\n");
			break;
			
			case Node_Ada_Clause_Width:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "with ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Code_Stmt:
			fprintfIndent( p_Fp );
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Comp_Loc_s:
			generateCode( p_Fp, p_Tree->getSon(0));
			if( p_Tree->getSon(0)->getNodeType()!=Node_Ada_C_Empty)
			{
				fprintf( p_Fp , "\n");
			}
			fprintfIndent( p_Fp );
			generateCode( p_Fp, p_Tree->getSon(1));
			fprintf( p_Fp , " at ");
			generateCode( p_Fp, p_Tree->getSon(2));
			fprintf( p_Fp , " range ");
			generateCode( p_Fp, p_Tree->getSon(3));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Component_Association:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " => ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Component_Decl:
			fprintfIndent( p_Fp );
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ": ");
			generateCode( p_Fp, p_Tree->getSon(1));
			generateCode( p_Fp, p_Tree->getSon(2));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Component_List:
			switch( p_Tree->getNbSon())
			{
				case 1:
				fprintfIndent( p_Fp );
				fprintf( p_Fp , "null;\n");
				generateCode( p_Fp, p_Tree->getSon(0));
				break;
				case 2:
				generateCode( p_Fp, p_Tree->getSon(0));
				generateCode( p_Fp, p_Tree->getSon(1));
				break;
				default:
				errorNbSon(__FILE__,__LINE__, p_Tree);
				my_exit(-1);
				break;
			}
			break;
			
			case Node_Ada_Component_Subtype_Definition:
			generateCode( p_Fp, p_Tree->getSon(0));
			if( p_Tree->getSon(0)->getNodeType()!=Node_Ada_C_Empty)
			{
				fprintf( p_Fp , " ");
			}
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Compound_Name:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ".");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Cond_Entry_Call:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "select\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(0));
			generateCode( p_Fp, p_Tree->getSon(1));
			indentDown();
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "else\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(2));
			indentDown();
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "end select;\n");
			break;
			
			case Node_Ada_Condition_Clause:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " then\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(1));
			indentDown();
			break;
			
			case Node_Ada_Constant:
			fprintf( p_Fp , "constant");
			break;
			
			case Node_Ada_Constraint_Array_Type:
			fprintf( p_Fp , "array(");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ") of ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Context_Specification:
			generateCode( p_Fp, p_Tree->getSon(0));
			generateCode( p_Fp, p_Tree->getSon(1));
			switch( p_Tree->getNbSon())
			{
				case 2:
				break;
				case 3:
				generateCode( p_Fp, p_Tree->getSon(2));
				break;
				default:
				errorNbSon(__FILE__,__LINE__, p_Tree);
				my_exit(-1);
				break;
			}
			break;
			
			case Node_Ada_C_Based_Number:
			fprintf( p_Fp , "%s", p_Tree->getString());
			break;
			
			case Node_Ada_C_Compilation_Unit:
			generateCode( p_Fp, p_Tree->getSon(0));
			generateCode( p_Fp, p_Tree->getSon(1));
			generateCode( p_Fp, p_Tree->getSon(2));
			switch( p_Tree->getNbSon())
			{
				case 3:
				break;
				generateCode( p_Fp, p_Tree->getSon(3));
				case 4:
				break;
				default:
				errorNbSon(__FILE__,__LINE__, p_Tree);
				my_exit(-1);
				break;
			}
			break;
			
			case Node_Ada_C_Div:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " / ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_C_Empty:
			break;
			
			case Node_Ada_C_Float:
			fprintf( p_Fp , "%s", p_Tree->getString());
			break;
			
			case Node_Ada_C_Formal_Part:
			fprintf( p_Fp , "(");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ")");
			break;
			
			case Node_Ada_C_Ident:
			fprintf( p_Fp , "%s", p_Tree->getString());
			break;
			
			case Node_Ada_C_Integer:
			fprintf( p_Fp , "%s", p_Tree->getString());
			break;
			
			case Node_Ada_C_Less:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " < ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_C_Less_Equal:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " <= ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_C_List_Compilation_Unit:
			generateCode( p_Fp, p_Tree->getSon(0));
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_C_List_Decl_Item_Or_Body:
			generateCode( p_Fp, p_Tree->getSon(0));
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_C_List_Statement:
			generateCode( p_Fp, p_Tree->getSon(0));
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_C_Minor:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " - ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_C_Mult:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " * ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_C_Parenthesized_Primary:
			fprintf( p_Fp , "(");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ")");
			break;
			
			case Node_Ada_C_Plus:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " + ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_C_Program:
			generateCode( p_Fp, p_Tree->getSon(0));
			break;
			
			case Node_Ada_C_Quote_Char:
			fprintf( p_Fp , "%s", p_Tree->getString());
			break;
			
			case Node_Ada_C_String:
			fprintf( p_Fp , "%s", p_Tree->getString());
			break;
			
			case Node_Ada_C_Sup:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " > ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_C_Sup_Equal:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " >= ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_C_Unary_Minor:
			fprintf( p_Fp , "- ");
			generateCode( p_Fp, p_Tree->getSon(0));
			break;
			
			case Node_Ada_C_Unary_Plus:
			fprintf( p_Fp , "+ ");
			generateCode( p_Fp, p_Tree->getSon(0));
			break;
			
			case Node_Ada_Decimal_Digits_Constraint:
			fprintf( p_Fp , "digits ");
			generateCode( p_Fp, p_Tree->getSon(0));
			if( p_Tree->getSon(1)->getNodeType()!=Node_Ada_C_Empty)
			{
				fprintf( p_Fp , " ");
			}
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Delay_Or_Entry_Alt:
			generateCode( p_Fp, p_Tree->getSon(0));
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Delay_Stmt:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "delay ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Delay_Stmt_Until:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "delay until ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Delta:
			fprintf( p_Fp , "delta");
			break;
			
			case Node_Ada_Delta_Box:
			fprintf( p_Fp , "delta <>");
			break;
			
			case Node_Ada_Delta_Box_Digits_Box:
			fprintf( p_Fp , "delta <> digits <>");
			break;
			
			case Node_Ada_Derived_Type:
			fprintf( p_Fp , "new ");
			generateCode( p_Fp, p_Tree->getSon(0));
			break;
			
			case Node_Ada_Derived_Type_With_Private:
			fprintf( p_Fp , "new ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " with private");
			break;
			
			case Node_Ada_Derived_Type_With_Record:
			fprintf( p_Fp , "new ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " with\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(1));
			indentDown();
			break;
			
			case Node_Ada_Digits:
			fprintf( p_Fp , "digits");
			break;
			
			case Node_Ada_Digits_Box_Lex:
			fprintf( p_Fp , "digits <>");
			break;
			
			case Node_Ada_Discrete_Range:
			generateCode( p_Fp, p_Tree->getSon(0));
			if( p_Tree->getSon(1)->getNodeType()!=Node_Ada_C_Empty)
			{
				fprintf( p_Fp , " ");
			}
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Discrete_With_Range:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Discrim_Part:
			fprintf( p_Fp , "(");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ")");
			break;
			
			case Node_Ada_Discrim_Part_Opt:
			fprintf( p_Fp , "( <> )");
			break;
			
			case Node_Ada_Discrim_Spec:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ": ");
			generateCode( p_Fp, p_Tree->getSon(1));
			if( p_Tree->getSon(1)->getNodeType()!=Node_Ada_C_Empty)
			{
				fprintf( p_Fp , " ");
			}
			generateCode( p_Fp, p_Tree->getSon(2));
			generateCode( p_Fp, p_Tree->getSon(3));
			break;
			
			case Node_Ada_Else:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "else\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(0));
			indentDown();
			break;
			
			case Node_Ada_Equal:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " = ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Entry_Body:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "entry ");
			generateCode( p_Fp, p_Tree->getSon(0));
			
			switch( p_Tree->getNbSon())
			{
				case 4:
				if( p_Tree->getSon(1)->getNodeType()!=Node_Ada_C_Empty)
				{
					fprintf( p_Fp , " ");
				}
				generateCode( p_Fp, p_Tree->getSon(1));
				fprintf( p_Fp , " when ");
				generateCode( p_Fp, p_Tree->getSon(2));
				if( p_Tree->getSon(3)->getNbSon()!=0)
				{
					fprintf( p_Fp , " ");
				}
				generateCode( p_Fp, p_Tree->getSon(3));
				break;
				case 6:
				fprintf( p_Fp , "(");
				generateCode( p_Fp, p_Tree->getSon(1));
				fprintf( p_Fp , " ");
				generateCode( p_Fp, p_Tree->getSon(2));
				fprintf( p_Fp , ")");
				generateCode( p_Fp, p_Tree->getSon(3));
				fprintf( p_Fp , " when ");
				generateCode( p_Fp, p_Tree->getSon(4));
				if( p_Tree->getSon(5)->getNbSon()!=0)
				{
					fprintf( p_Fp , " ");
				}
				generateCode( p_Fp, p_Tree->getSon(5));
				break;
				default:
				errorNbSon(__FILE__,__LINE__, p_Tree);
				my_exit(-1);
				break;
			}
			break;
			
			case Node_Ada_Entry_Body_Part:
			switch( p_Tree->getNbSon())
			{
				case 0:
				break;
				case 3:
				fprintf( p_Fp , "is\n");
				indentUp();
				generateCode( p_Fp, p_Tree->getSon(0));
				indentDown();
				generateCode( p_Fp, p_Tree->getSon(1));
				fprintfIndent( p_Fp );
				fprintf( p_Fp , "end");
				if( p_Tree->getSon(2)->getNodeType()!=Node_Ada_C_Empty)
				{
					fprintf( p_Fp , " ");
				}
				generateCode( p_Fp, p_Tree->getSon(2));
				break;
				default:
				errorNbSon(__FILE__,__LINE__, p_Tree);
				my_exit(-1);
				break;
			}
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Entry_Decl:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "entry ");
			generateCode( p_Fp, p_Tree->getSon(0));
			switch( p_Tree->getNbSon())
			{
				case 2:
				if( p_Tree->getSon(1)->getNodeType()!=Node_Ada_C_Empty)
				{
					fprintf( p_Fp , " ");
				}
				generateCode( p_Fp, p_Tree->getSon(1));
				break;
				case 3:
				fprintf( p_Fp , "(");
				generateCode( p_Fp, p_Tree->getSon(1));
				fprintf( p_Fp , ")");
				generateCode( p_Fp, p_Tree->getSon(2));
				break;
				default:
				errorNbSon(__FILE__,__LINE__, p_Tree);
				my_exit(-1);
				break;
			}
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Entry_Decl_s:
			generateCode( p_Fp, p_Tree->getSon(0));
			generateCode( p_Fp, p_Tree->getSon(1));
			generateCode( p_Fp, p_Tree->getSon(2));
			break;
			
			case Node_Ada_Entry_Name:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , "(");
			generateCode( p_Fp, p_Tree->getSon(1));
			fprintf( p_Fp , ")");
			break;
			
			case Node_Ada_Enumeration_Type:
			fprintf( p_Fp , "(");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ")");
			break;
			
			case Node_Ada_Except_Choice_s:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " | ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Except_Handler_Part:
			switch( p_Tree->getNbSon())
			{
				case 1:
				fprintfIndent( p_Fp );
				fprintf( p_Fp , "exception\n");
				indentUp();
				generateCode( p_Fp, p_Tree->getSon(0));
				indentDown();
				break;
				case 2:
				generateCode( p_Fp, p_Tree->getSon(0));
				indentUp();
				generateCode( p_Fp, p_Tree->getSon(1));
				indentDown();
				break;
				default:
				errorNbSon(__FILE__,__LINE__, p_Tree);
				my_exit(-1);
				break;
			}
			break;
			
			case Node_Ada_Exception_Decl:
			fprintfIndent( p_Fp );
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ": exception;\n");
			break;
			
			case Node_Ada_Exception_Handler:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "when ");
			generateCode( p_Fp, p_Tree->getSon(0));
			switch( p_Tree->getNbSon())
			{
				case 2:
				fprintf( p_Fp , " =>\n");
				indentUp();
				generateCode( p_Fp, p_Tree->getSon(1));
				indentDown();
				break;
				case 3:
				fprintf( p_Fp , ": ");
				generateCode( p_Fp, p_Tree->getSon(1));
				fprintf( p_Fp , " =>\n");
				indentUp();
				generateCode( p_Fp, p_Tree->getSon(2));
				indentDown();
				break;
				default:
				errorNbSon(__FILE__,__LINE__, p_Tree);
				my_exit(-1);
				break;
			}
			break;
			
			case Node_Ada_Exclusive_Or:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " xor ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Exit:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "exit");
			if( p_Tree->getSon(0)->getNodeType()!=Node_Ada_C_Empty || p_Tree->getSon(1)->getNodeType()!=Node_Ada_C_Empty)
			{
				fprintf( p_Fp , " ");
			}
			generateCode( p_Fp, p_Tree->getSon(0));
			if( p_Tree->getSon(0)->getNodeType()!=Node_Ada_C_Empty && p_Tree->getSon(1)->getNodeType()!=Node_Ada_C_Empty)
			{
				fprintf( p_Fp , " ");
			}
			generateCode( p_Fp, p_Tree->getSon(1));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Fixed_Type:
			fprintf( p_Fp , "delta ");
			generateCode( p_Fp, p_Tree->getSon(0));
			switch( p_Tree->getNbSon())
			{
				case 2:
				fprintf( p_Fp , " ");
				generateCode( p_Fp, p_Tree->getSon(1));
				break;
				case 3:
				fprintf( p_Fp , " digits ");
				generateCode( p_Fp, p_Tree->getSon(1));
				if( p_Tree->getSon(2)->getNodeType()!=Node_Ada_C_Empty)
				{
					fprintf( p_Fp , " ");
				}
				generateCode( p_Fp, p_Tree->getSon(2));
				break;
				default:
				errorNbSon(__FILE__,__LINE__, p_Tree);
				my_exit(-1);
				break;
			}
			break;
			
			case Node_Ada_Float_Type:
			fprintf( p_Fp , "digits ");
			generateCode( p_Fp, p_Tree->getSon(0));
			if( p_Tree->getSon(1)->getNodeType()!=Node_Ada_C_Empty)
			{
				fprintf( p_Fp , " ");
			}
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Guarded_Select_Alt:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "when ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " =>\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(1));
			indentDown();
			break;
			
			case Node_Ada_Generic:
			fprintf( p_Fp , "generic");
			break;
			
			case Node_Ada_Generic_Decl:
			fprintfIndent( p_Fp );
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintfIndent( p_Fp );
			generateCode( p_Fp, p_Tree->getSon(1));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Generic_Derived_Type:
			fprintf( p_Fp , "new ");
			generateCode( p_Fp, p_Tree->getSon(0));
			break;
			
			case Node_Ada_Generic_Derived_Type_Abstract_Private:
			fprintf( p_Fp , "abstract new ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " with private");
			break;
			
			case Node_Ada_Generic_Derived_Type_Private:
			fprintf( p_Fp , "new ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " with private");
			break;
			
			case Node_Ada_Generic_Discrim_Part_Opt:
			fprintf( p_Fp , "( <> )");
			break;
			
			case Node_Ada_Generic_Formal:
			fprintfIndent( p_Fp );
			switch( p_Tree->getNbSon())
			{
				case 1:
				generateCode( p_Fp, p_Tree->getSon(0));
				fprintf( p_Fp , ";\n");
				break;
				case 3:
				fprintf( p_Fp , "type ");
				generateCode( p_Fp, p_Tree->getSon(0));
				generateCode( p_Fp, p_Tree->getSon(1));
				fprintf( p_Fp , " is");
				generateCode( p_Fp, p_Tree->getSon(2));
				fprintf( p_Fp , ";\n");
				break;
				case 4:
				fprintf( p_Fp , "with function ");
				generateCode( p_Fp, p_Tree->getSon(0));
				generateCode( p_Fp, p_Tree->getSon(1));
				fprintf( p_Fp , " return ");
				generateCode( p_Fp, p_Tree->getSon(2));
				if( p_Tree->getSon(3)->getNodeType()!=Node_Ada_C_Empty)
				{
					fprintf( p_Fp , " ");
				}
				generateCode( p_Fp, p_Tree->getSon(3));
				fprintf( p_Fp , ";\n");
				break;
				default:
				errorNbSon(__FILE__,__LINE__, p_Tree);
				my_exit(-1);
				break;
			}
			break;
			
			case Node_Ada_Generic_Formal_Package:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "with package ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " is new ");
			generateCode( p_Fp, p_Tree->getSon(1));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Generic_Formal_Package_Box:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "with package ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " is new ");
			generateCode( p_Fp, p_Tree->getSon(1));
			fprintf( p_Fp , "( <> );\n");
			break;
			
			case Node_Ada_Generic_Formal_Part:
			generateCode( p_Fp, p_Tree->getSon(0));
			if( p_Tree->getSon(0)->getNodeType()!=Node_Ada_Generic)
			{
				generateCode( p_Fp, p_Tree->getSon(1));
			}
			else
			{
				fprintf( p_Fp , "\n");
				indentUp();
				generateCode( p_Fp, p_Tree->getSon(1));
				indentDown();
			}
			break;
			
			case Node_Ada_Generic_Formal_Procedure:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "with procedure ");
			generateCode( p_Fp, p_Tree->getSon(0));
			generateCode( p_Fp, p_Tree->getSon(1));
			if( p_Tree->getSon(2)->getNodeType()!=Node_Ada_C_Empty)
			{
				fprintf( p_Fp , " ");
			}
			generateCode( p_Fp, p_Tree->getSon(2));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Generic_Inst:
			fprintf( p_Fp , "new ");
			generateCode( p_Fp, p_Tree->getSon(0));
			break;
			
			case Node_Ada_Generic_Package_Inst:
			fprintf( p_Fp , "package ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " is ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Generic_Subp_Inst:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " is ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Generic_Subprog_Inst:
			fprintfIndent( p_Fp );
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Generic_Type_Def:
			generateCode( p_Fp, p_Tree->getSon(0));
			break;
			
			case Node_Ada_Generic_Type_Def_Box:
			fprintf( p_Fp , "( <> )");
			break;
			
			case Node_Ada_Goto:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "goto ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Handler_Statement:
			generateCode( p_Fp, p_Tree->getSon(0));
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_If:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "if ");
			generateCode( p_Fp, p_Tree->getSon(0));
			generateCode( p_Fp, p_Tree->getSon(1));
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "end if;\n");
			break;
			
			case Node_Ada_In:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " in ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Index:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " range <>");
			break;
			
			case Node_Ada_Indexed_Comp:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , "(");
			generateCode( p_Fp, p_Tree->getSon(1));
			fprintf( p_Fp , ")");
			break;
			
			case Node_Ada_Initialisation_Option:
			fprintf( p_Fp , ":= ");
			generateCode( p_Fp, p_Tree->getSon(0));
			break;
			
			case Node_Ada_Integer_Type:
			generateCode( p_Fp, p_Tree->getSon(0));
			break;
			
			case Node_Ada_Iteration:
			switch( p_Tree->getNbSon())
			{
				case 1:
				fprintf( p_Fp , "while ");
				generateCode( p_Fp, p_Tree->getSon(0));
				break;
				case 3:
				generateCode( p_Fp, p_Tree->getSon(0));
				if( p_Tree->getSon(1)->getNodeType()!=Node_Ada_C_Empty)
				{
					fprintf( p_Fp , " ");
				}
				generateCode( p_Fp, p_Tree->getSon(1));
				fprintf( p_Fp , " ");
				generateCode( p_Fp, p_Tree->getSon(2));
				break;
				default:
				errorNbSon(__FILE__,__LINE__, p_Tree);
				my_exit(-1);
				break;
			}
			
			break;
			
			case Node_Ada_Iterative_Part:
			fprintf( p_Fp , "for ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " in");
			break;
			
			case Node_Ada_Label:
			fprintf( p_Fp , "<< ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " >>");
			break;
			
			case Node_Ada_Label_Loop:
			fprintfIndent( p_Fp );
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ":");
			break;
			
			case Node_Ada_Limited:
			fprintf( p_Fp , "limited");
			break;
			
			case Node_Ada_List_Alternative:
			generateCode( p_Fp, p_Tree->getSon(0));
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_List_C_Name:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ", ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_List_Choice:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " | ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_List_Component_Decl:
			generateCode( p_Fp, p_Tree->getSon(0));
			generateCode( p_Fp, p_Tree->getSon(1));
			generateCode( p_Fp, p_Tree->getSon(2));
			break;
			
			case Node_Ada_List_Condition_Clause:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "elsif ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_List_Discrete_Range:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ", ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_List_Discrim_Spec:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , "; ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_List_Enumeration_Identifier:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ", ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_List_Identifier:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ", ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_List_Index:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ", ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_List_Item_Decl:
			generateCode( p_Fp, p_Tree->getSon(0));
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_List_Name:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ", ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_List_Parameter:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , "; ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_List_Pragma:
			generateCode( p_Fp, p_Tree->getSon(0));
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_List_Pragma_Arg:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ", ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_List_Value:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ", ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_List_Value2:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ", ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_List_Variant:
			generateCode( p_Fp, p_Tree->getSon(0));
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Loop:
			generateCode( p_Fp, p_Tree->getSon(0));
			if( p_Tree->getSon(0)->getNodeType()!=Node_Ada_C_Empty)
			{
				fprintf( p_Fp , " ");
			}
			else
			{	
				fprintfIndent( p_Fp );
			}
			generateCode( p_Fp, p_Tree->getSon(1));
			fprintf( p_Fp , "\n");
			generateCode( p_Fp, p_Tree->getSon(2));
			fprintf( p_Fp , " ");
			generateCode( p_Fp, p_Tree->getSon(3));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Mark_Point:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ".");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Mark_Quote:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , "'");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Mod:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " mod ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Mod_Integer_Type:
			fprintf( p_Fp , "mod ");
			generateCode( p_Fp, p_Tree->getSon(0));
			break;
			
			case Node_Ada_Mode_Access:
			fprintf( p_Fp , "access");
			break;
			
			case Node_Ada_Mod_Box:
			fprintf( p_Fp , "mode <>");
			break;
			
			case Node_Ada_Mode_In:
			fprintf( p_Fp , "in");
			break;
			
			case Node_Ada_Mode_In_Out:
			fprintf( p_Fp , "in out");
			break;
			
			case Node_Ada_Mode_Out:
			fprintf( p_Fp , "out");
			break;
			
			case Node_Ada_Non_Equal:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " /= ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Not:
			fprintf( p_Fp , "not ");
			generateCode( p_Fp, p_Tree->getSon(0));
			break;
			
			case Node_Ada_Not_In:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " not in ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Null:
			fprintf( p_Fp , "null");
			break;
			
			case Node_Ada_Null_Record:
			fprintf( p_Fp , "null record");
			break;
			
			case Node_Ada_Null_Statement:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "null;\n");
			break;
			
			case Node_Ada_Number_Decl:
			fprintfIndent( p_Fp );
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ": constant := ");
			generateCode( p_Fp, p_Tree->getSon(1));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Object_Decl:
			fprintfIndent( p_Fp );
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ": ");
			generateCode( p_Fp, p_Tree->getSon(1));
			if( p_Tree->getSon(0)->getNodeType()!=Node_Ada_C_Empty)
			{
				fprintf( p_Fp , " ");
			}
			generateCode( p_Fp, p_Tree->getSon(2));
			generateCode( p_Fp, p_Tree->getSon(3));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Or:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " or ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Or_Else:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " or else ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Or_Select:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "or\n");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Others:
			fprintf( p_Fp , "others");
			break;
			
			case Node_Ada_Package_Body:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "package body ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " is\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(1));
			indentDown();
			generateCode( p_Fp, p_Tree->getSon(2));
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "end");
			if( p_Tree->getSon(3)->getNodeType()!=Node_Ada_C_Empty)
			{
				fprintf( p_Fp , " ");
			}
			generateCode( p_Fp, p_Tree->getSon(3));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Package_Decl:
			fprintfIndent( p_Fp );
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Package_Spec:
			fprintf( p_Fp , "package ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " is\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(1));
			indentDown();
			fprintfIndent( p_Fp );
			generateCode( p_Fp, p_Tree->getSon(2));
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "end");
			if( p_Tree->getSon(3)->getNodeType()!=Node_Ada_C_Empty)
			{
				fprintf( p_Fp , " ");
			}
			generateCode( p_Fp, p_Tree->getSon(3));
			break;
			
			case Node_Ada_Parameter:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ": ");
			generateCode( p_Fp, p_Tree->getSon(1));
			if( p_Tree->getSon(1)->getNodeType()!=Node_Ada_C_Empty)
			{
				fprintf( p_Fp , " ");
			}
			generateCode( p_Fp, p_Tree->getSon(2));
			generateCode( p_Fp, p_Tree->getSon(3));
			break;
			
			case Node_Ada_Power:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " ** ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Pragma:
			switch( p_Tree->getNbSon())
			{
				case 1:
				fprintfIndent( p_Fp );
				fprintf( p_Fp , "pragma ");
				generateCode( p_Fp, p_Tree->getSon(0));
				fprintf( p_Fp , ";\n");
				break;
				case 2:
				fprintfIndent( p_Fp );
				fprintf( p_Fp , "pragma ");
				generateCode( p_Fp, p_Tree->getSon(0));
				fprintf( p_Fp , "( ");
				generateCode( p_Fp, p_Tree->getSon(1));
				fprintf( p_Fp , ");\n");
				break;
				default:
				errorNbSon(__FILE__,__LINE__, p_Tree);
				my_exit(-1);
				break;
			}
			break;
			
			case Node_Ada_Pragma_Arg:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " => ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Procedure_Call:
			fprintfIndent( p_Fp );
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Prot_Body:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "protected body ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " is\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(1));
			indentDown();
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "end");
			if( p_Tree->getSon(2)->getNodeType()!=Node_Ada_C_Empty)
			{
				fprintf( p_Fp , " ");
			}
			generateCode( p_Fp, p_Tree->getSon(2));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Prot_Decl:
			fprintfIndent( p_Fp );
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Prot_Def:
			fprintf( p_Fp , "is\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(0));
			generateCode( p_Fp, p_Tree->getSon(1));
			indentDown();
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "end");
			if( p_Tree->getSon(2)->getNodeType()!=Node_Ada_C_Empty)
			{
				fprintf( p_Fp , " ");
			}
			generateCode( p_Fp, p_Tree->getSon(2));
			break;
			
			case Node_Ada_Prot_Elem_Decl_s:
			generateCode( p_Fp, p_Tree->getSon(0));
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Prot_Op_Body_s:
			generateCode( p_Fp, p_Tree->getSon(0));
			generateCode( p_Fp, p_Tree->getSon(1));
			generateCode( p_Fp, p_Tree->getSon(2));
			break;
			
			case Node_Ada_Prot_Op_Body:
			fprintfIndent( p_Fp );
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Prot_Op_Decl_s:
			generateCode( p_Fp, p_Tree->getSon(0));
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Prot_Op_Decl:
			fprintfIndent( p_Fp );
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Prot_Private_Opt:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "private\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(0));
			indentDown();
			break;
			
			case Node_Ada_Prot_Spec:
			fprintf( p_Fp , "protected ");
			switch( p_Tree->getNbSon())
			{
				case 2:
				generateCode( p_Fp, p_Tree->getSon(0));
				fprintf( p_Fp , " ");
				generateCode( p_Fp, p_Tree->getSon(1));
				break;
				case 3:
				fprintf( p_Fp , "type ");
				generateCode( p_Fp, p_Tree->getSon(0));
				fprintf( p_Fp , " ");
				generateCode( p_Fp, p_Tree->getSon(1));
				if( p_Tree->getSon(1)->getNodeType()!=Node_Ada_C_Empty)
				{
					fprintf( p_Fp , " ");
				}
				generateCode( p_Fp, p_Tree->getSon(2));
				break;
				default:
				errorNbSon(__FILE__,__LINE__, p_Tree);
				my_exit(-1);
				break;
			}
			break;
			
			case Node_Ada_Protected_Opt:
			fprintf( p_Fp , "protected");
			break;
			
			case Node_Ada_Private:
			fprintf( p_Fp , "private\n");
			break;
			
			case Node_Ada_Private_Part:
			fprintf( p_Fp , "private\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(0));
			indentDown();
			break;
			
			case Node_Ada_Private_Type:
			generateCode( p_Fp, p_Tree->getSon(0));
			if( p_Tree->getSon(0)->getNodeType()!=Node_Ada_C_Empty && p_Tree->getSon(1)->getNodeType()!=Node_Ada_C_Empty)
			{
				fprintf( p_Fp , " ");
			}
			generateCode( p_Fp, p_Tree->getSon(1));
			if( p_Tree->getSon(0)->getNodeType()!=Node_Ada_C_Empty || p_Tree->getSon(1)->getNodeType()!=Node_Ada_C_Empty)
			{
				fprintf( p_Fp , " ");
			}
			fprintf( p_Fp , "private");
			break;
			
			case Node_Ada_Qualified:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , "'");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Raise_Stmt:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "raise ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Range_Constraint:
			fprintf( p_Fp , "range ");
			generateCode( p_Fp, p_Tree->getSon(0));
			break;
			
			case Node_Ada_Range:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , "'Range");
			switch( p_Tree->getNbSon())
			{
				case 1:
				break;
				case 2:
				fprintf( p_Fp , "(");
				generateCode( p_Fp, p_Tree->getSon(1));
				fprintf( p_Fp , ")");
				break;
				default:
				errorNbSon(__FILE__,__LINE__, p_Tree);
				my_exit(-1);
				break;
			}
			break;
			
			case Node_Ada_Range_Box:
			fprintf( p_Fp , "range <>");
			break;
			
			case Node_Ada_Range_Inter:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " .. ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Record_Definition:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "record\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(0));
			generateCode( p_Fp, p_Tree->getSon(1));
			indentDown();
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "end record");
			break;
			
			case Node_Ada_Record_Type:
			generateCode( p_Fp, p_Tree->getSon(0));
			if( p_Tree->getSon(0)->getNodeType()!=Node_Ada_C_Empty && p_Tree->getSon(1)->getNodeType()!=Node_Ada_C_Empty)
			{
				fprintf( p_Fp , " ");
			}
			generateCode( p_Fp, p_Tree->getSon(1));
			if( p_Tree->getSon(0)->getNodeType()!=Node_Ada_C_Empty || p_Tree->getSon(1)->getNodeType()!=Node_Ada_C_Empty)
			{
				fprintf( p_Fp , " ");
			}
			generateCode( p_Fp, p_Tree->getSon(2));
			break;
			
			case Node_Ada_Record_Type_Spec:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "for ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " use record\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(1));
			generateCode( p_Fp, p_Tree->getSon(2));
			indentDown();
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "end record;\n");
			break;
			
			case Node_Ada_Rem:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " rem ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Rename_Decl:
			fprintfIndent( p_Fp );
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ": ");
			switch( p_Tree->getNbSon())
			{
				case 2:
				fprintf( p_Fp , "exception ");
				generateCode( p_Fp, p_Tree->getSon(1));
				break;
				case 4:
				generateCode( p_Fp, p_Tree->getSon(1));
				if( p_Tree->getSon(1)->getNodeType()!=Node_Ada_C_Empty)
				{
					fprintf( p_Fp , " ");
				}
				generateCode( p_Fp, p_Tree->getSon(2));
				fprintf( p_Fp , " ");
				generateCode( p_Fp, p_Tree->getSon(3));
				break;
				default:
				errorNbSon(__FILE__,__LINE__, p_Tree);
				my_exit(-1);
				break;
			}
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Rename_Unit:
			fprintfIndent( p_Fp );
			switch( p_Tree->getNbSon())
			{
				case 2:
				generateCode( p_Fp, p_Tree->getSon(0));
				fprintf( p_Fp , " ");
				generateCode( p_Fp, p_Tree->getSon(1));
				break;
				case 3:
				generateCode( p_Fp, p_Tree->getSon(0));
				fprintfIndent( p_Fp );
				generateCode( p_Fp, p_Tree->getSon(1));
				fprintf( p_Fp , " ");
				generateCode( p_Fp, p_Tree->getSon(2));
				break;
				default:
				errorNbSon(__FILE__,__LINE__, p_Tree);
				my_exit(-1);
				break;
			}
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Rename_Unit_Package:
			fprintfIndent( p_Fp );
			switch( p_Tree->getNbSon())
			{
				case 2:
				fprintf( p_Fp , "package ");
				generateCode( p_Fp, p_Tree->getSon(0));
				fprintf( p_Fp , " ");
				generateCode( p_Fp, p_Tree->getSon(1));
				break;
				case 3:
				generateCode( p_Fp, p_Tree->getSon(0));
				fprintfIndent( p_Fp );
				fprintf( p_Fp , "package ");
				generateCode( p_Fp, p_Tree->getSon(1));
				fprintf( p_Fp , " ");
				generateCode( p_Fp, p_Tree->getSon(2));
				break;
				default:
				errorNbSon(__FILE__,__LINE__, p_Tree);
				my_exit(-1);
				break;
			}
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Renames:
			fprintf( p_Fp , "renames ");
			generateCode( p_Fp, p_Tree->getSon(0));
			break;
			
			case Node_Ada_Rep_Spec_s:
			generateCode( p_Fp, p_Tree->getSon(0));
			generateCode( p_Fp, p_Tree->getSon(1));
			generateCode( p_Fp, p_Tree->getSon(2));
			break;
			
			case Node_Ada_Requeue_Stmt:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "requeue ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Requeue_Stmt_With:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "requeue ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " with abort;\n");
			break;
			
			case Node_Ada_Return:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "return");
			switch( p_Tree->getNbSon())
			{
				case 0:
				break;
				case 1:
				fprintf( p_Fp , " ");
				generateCode( p_Fp, p_Tree->getSon(0));
				break;
				default:
				errorNbSon(__FILE__,__LINE__, p_Tree);
				my_exit(-1);
				break;
			}
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Reverse:
			fprintf( p_Fp , "reverse");
			break;
			
			case Node_Ada_Select_Alt:
			switch( p_Tree->getNbSon())
			{
				case 0:
				fprintfIndent( p_Fp );
				fprintf( p_Fp , "terminate;\n");
				break;
				case 2:
				generateCode( p_Fp, p_Tree->getSon(0));
				generateCode( p_Fp, p_Tree->getSon(1));
				break;
				default:
				errorNbSon(__FILE__,__LINE__, p_Tree);
				my_exit(-1);
				break;
			}
			break;
			
			case Node_Ada_Selected_Comp:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ".");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Selected_Comp_All:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ".all");
			break;
			
			case Node_Ada_Select_Wait:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "select\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(0));
			generateCode( p_Fp, p_Tree->getSon(1));
			indentDown();
			generateCode( p_Fp, p_Tree->getSon(2));
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "end select;\n");
			break;
			
			case Node_Ada_Statement:
			fprintfIndent( p_Fp );
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , "\n");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Subp_Default:
			switch( p_Tree->getNbSon())
			{
				case 0:
				fprintf( p_Fp , "is <>");
				break;
				case 1:
				fprintf( p_Fp , "is ");
				generateCode( p_Fp, p_Tree->getSon(0));
				break;
				default:
				errorNbSon(__FILE__,__LINE__, p_Tree);
				my_exit(-1);
				break;
			}
			break;
			
			case Node_Ada_Subprog_Body:
			fprintfIndent( p_Fp );
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " is\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(1));
			generateCode( p_Fp, p_Tree->getSon(2));
			indentDown();
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "end");
			if( p_Tree->getSon(3)->getNodeType()!=Node_Ada_C_Empty)
			{
				fprintf( p_Fp , " ");
			}
			generateCode( p_Fp, p_Tree->getSon(3));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Subprog_Decl:
			fprintfIndent( p_Fp );
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Subprog_Spec:
			switch( p_Tree->getNbSon())
			{
				case 1:
				fprintf( p_Fp , "function ");
				generateCode( p_Fp, p_Tree->getSon(0));
				break;
				case 2:
				fprintf( p_Fp , "procedure ");
				generateCode( p_Fp, p_Tree->getSon(0));
				generateCode( p_Fp, p_Tree->getSon(1));
				break;
				case 3:
				fprintf( p_Fp , "function ");
				generateCode( p_Fp, p_Tree->getSon(0));
				generateCode( p_Fp, p_Tree->getSon(1));
				fprintf( p_Fp , " return ");
				generateCode( p_Fp, p_Tree->getSon(2));
				break;
				default:
				errorNbSon(__FILE__,__LINE__, p_Tree);
				my_exit(-1);
				break;
			}
			break;
			
			case Node_Ada_Subtype_Decl:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "subtype ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " is ");
			generateCode( p_Fp, p_Tree->getSon(1));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Subtype_Indication:
			generateCode( p_Fp, p_Tree->getSon(0));
			switch( p_Tree->getNbSon())
			{
				case 1:
				break;
				case 2:
				fprintf( p_Fp , " ");
				generateCode( p_Fp, p_Tree->getSon(1));
				break;
				default: 
				errorNbSon(__FILE__,__LINE__, p_Tree);
				my_exit(-1);
				break;
			}
			break;
			
			case Node_Ada_Subunit:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "separate(");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ")\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(1));
			indentDown();
			break;
			
			case Node_Ada_Tagged:
			fprintf( p_Fp , "tagged");
			break;
			
			case Node_Ada_Task_Body:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "task body ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , "is\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(1));
			indentDown();
			generateCode( p_Fp, p_Tree->getSon(2));
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "end");
			if( p_Tree->getSon(3)->getNodeType()!=Node_Ada_C_Empty)
			{
				fprintf( p_Fp , " ");
			}
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Task_Decl:
			fprintfIndent( p_Fp );
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Task_Def:
			fprintf( p_Fp , "is\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(0));
			generateCode( p_Fp, p_Tree->getSon(1));
			indentDown();
			generateCode( p_Fp, p_Tree->getSon(2));
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "end");
			if( p_Tree->getSon(3)->getNodeType()!=Node_Ada_C_Empty)
			{
					fprintf( p_Fp , " ");
			}
			generateCode( p_Fp, p_Tree->getSon(3));
			break;
			
			case Node_Ada_Task_Private_Opt:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "private\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(0));
			generateCode( p_Fp, p_Tree->getSon(1));
			indentDown();
			break;
			
			case Node_Ada_Task_Spec:
			fprintf( p_Fp , "task ");
			switch( p_Tree->getNbSon())
			{
				case 2:
				generateCode( p_Fp, p_Tree->getSon(0));
				if( p_Tree->getSon(1)->getNodeType()!=Node_Ada_C_Empty)
				{
					fprintf( p_Fp , " ");
				}
				generateCode( p_Fp, p_Tree->getSon(1));
				break;
				case 3:
				fprintf( p_Fp , "type ");
				generateCode( p_Fp, p_Tree->getSon(0));
				if( p_Tree->getSon(1)->getNodeType()!=Node_Ada_C_Empty || p_Tree->getSon(2)->getNodeType()!=Node_Ada_C_Empty)
				{
					fprintf( p_Fp , " ");
				}
				generateCode( p_Fp, p_Tree->getSon(1));
				if( p_Tree->getSon(1)->getNodeType()!=Node_Ada_C_Empty && p_Tree->getSon(2)->getNodeType()!=Node_Ada_C_Empty)
				{
					fprintf( p_Fp , " ");
				}
				generateCode( p_Fp, p_Tree->getSon(2));
				break;
				default: 
				errorNbSon(__FILE__,__LINE__, p_Tree);
				my_exit(-1);
				break;
			}
			break;
			
			case Node_Ada_Timed_Entry_Call:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "select\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(0));
			generateCode( p_Fp, p_Tree->getSon(1));
			indentDown();
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "or\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(2));
			generateCode( p_Fp, p_Tree->getSon(3));
			indentDown();
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "end select;\n");
			break;
			
			case Node_Ada_Type_Decl:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "type ");
			generateCode( p_Fp, p_Tree->getSon(0));
			switch( p_Tree->getNbSon())
			{
				case 1:
				break;
				case 3:
				if( p_Tree->getSon(1)->getNodeType()!=Node_Ada_C_Empty)
				{
					fprintf( p_Fp , " ");
				}
				generateCode( p_Fp, p_Tree->getSon(1));
				fprintf( p_Fp , " is ");
				if( p_Tree->getSon(2)->getNodeType()!=Node_Ada_Record_Type)
				{
					generateCode( p_Fp, p_Tree->getSon(2));
				}
				else
				{
					fprintf( p_Fp , "\n");
					indentUp();
					generateCode( p_Fp, p_Tree->getSon(2));
					indentDown();
					
				}
				break;
				default: 
				errorNbSon(__FILE__,__LINE__, p_Tree);
				my_exit(-1);
				break;
			}
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Unconstraint_Array_Type:
			fprintf( p_Fp , "array(");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ") of ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Use_Clause:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "use ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Clause_Use_Option:
			generateCode( p_Fp, p_Tree->getSon(0));
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Use_Clause_Type:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "use type ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_Ada_Value2:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ", ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_Ada_Variant:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "when ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " = >\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(1));
			generateCode( p_Fp, p_Tree->getSon(2));
			indentDown();
			break;
			
			case Node_Ada_Variant_Part:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "case ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " is\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(1));
			generateCode( p_Fp, p_Tree->getSon(2));
			indentDown();
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "end case;\n");
			break;
			
			case Node_Ada_Variant_Part_Optional:
			generateCode( p_Fp, p_Tree->getSon(0));
			generateCode( p_Fp, p_Tree->getSon(1));
			generateCode( p_Fp, p_Tree->getSon(2));
			break;
			
			case Node_Ada_When:
			fprintf( p_Fp , "when ");
			generateCode( p_Fp, p_Tree->getSon(0));
			break;
			
			case Node_C_Affect:
			fprintfIndent( p_Fp );
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " = ");
			generateCode( p_Fp, p_Tree->getSon(1));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_C_Access_Type_Decl:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "typedef ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , "* ");
			generateCode( p_Fp, p_Tree->getSon(1));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_C_Access_Subprog_Type_Decl:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "typedef ");
			if(p_Tree->getSon(0)->getNodeType()!=Node_Ada_C_Empty)
			{
				fprintf( p_Fp , "/* protected*/");
			}
			generateCode( p_Fp, p_Tree->getSon(1));
			fprintf( p_Fp , "(*");
			generateCode( p_Fp, p_Tree->getSon(2));
			fprintf( p_Fp , ")");
			if(p_Tree->getSon(2)->getNodeType()!=Node_Ada_C_Empty)
			{
				generateCode( p_Fp, p_Tree->getSon(3));
			}
			else
			{
				fprintf( p_Fp , "(void)");
			}
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_C_And:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " && ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_C_Array_Comp:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , "[");
			generateCode( p_Fp, p_Tree->getSon(1));
			fprintf( p_Fp , "]");
			break;
			
			case Node_C_Array_Type:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "typedef ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " ");
			generateCode( p_Fp, p_Tree->getSon(1));
			fprintf( p_Fp , "[");
			generateCode( p_Fp, p_Tree->getSon(2));
			fprintf( p_Fp , "];\n");
			break;
			
			case Node_C_Basic_Loop:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "{\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(0));
			indentDown();
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "}\n");
			break;
			
			case Node_C_Block:
			generateCode( p_Fp, p_Tree->getSon(0));
			generateCode( p_Fp, p_Tree->getSon(1));
			generateCode( p_Fp, p_Tree->getSon(2));
			break;
			
			case Node_C_Break :
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "break;\n");
			break;
			
			case Node_C_Case:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "case ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ":\n");
			switch( p_Tree->getNbSon())
			{
				case 1:
				break;
				case 2:
				generateCode( p_Fp, p_Tree->getSon(1));
				fprintfIndent( p_Fp );
				fprintf( p_Fp , "break;\n");
				break;
			}
			break;
			
			case Node_C_Comment:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "//%s\n", p_Tree->getString());
			break;
			
			case Node_C_Comment_Block:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "/*\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(0));
			indentDown();
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "*/\n");
			break;
			
			case Node_C_Comment_Bracket:
			fprintf( p_Fp , "/* ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " */");
			break;
			
			case Node_C_Comment_Line:
			fprintf( p_Fp , "// ");
			generateCode( p_Fp, p_Tree->getSon(0));
			break;
			
			case Node_C_Component_Association:
			fprintf( p_Fp , "/* ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " => */ ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_C_Component_Decl:
			fprintfIndent( p_Fp );
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " ");
			generateCode( p_Fp, p_Tree->getSon(1));
			generateCode( p_Fp, p_Tree->getSon(2));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_C_Condition_Clause:
			fprintf( p_Fp , "(");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ")\n");
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "{\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(1));
			indentDown();
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "}\n");
			switch( p_Tree->getNbSon())
			{
				case 2:
				break;
				case 3:
				generateCode( p_Fp, p_Tree->getSon(2));
				break;
				default:
				errorNbSon(__FILE__,__LINE__, p_Tree);
				my_exit(-1);
				break;
			}
			break;
			
			case Node_C_Constant:
			fprintf( p_Fp , "const");
			break;
			
			case Node_C_Default_Case:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "default :\n");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "break;\n");
			break;
			
			case Node_C_Define:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "#define ");
			generateCode( p_Fp, p_Tree->getSon(0));
			switch( p_Tree->getNbSon())
			{
				case 1:
				break;
				case 2:
				fprintf( p_Fp , " ");
				generateCode( p_Fp, p_Tree->getSon(1));
				break;
				default:
				errorNbSon(__FILE__,__LINE__, p_Tree);
				break;
			}
			fprintf( p_Fp , "\n");
			break;
			
			case Node_C_Derived_Type_Decl:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "typedef ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " ");
			generateCode( p_Fp, p_Tree->getSon(1));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_C_Else:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "else\n");
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "{\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(0));
			indentDown();
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "}\n");
			break;
			
			case Node_C_Enumeration_Type_Decl:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "typedef enum\n");
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "{\n");
			indentUp();
			fprintfIndent( p_Fp );
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , "\n");
			indentDown();
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "} ");
			generateCode( p_Fp, p_Tree->getSon(1));
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_C_Equal:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " == ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_C_Exception_Handler:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "catch( ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " )\n");
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "{\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(1));
			indentDown();
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "}\n");
			break;
			
			case Node_C_Exclusive_Or:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " ^ ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;

			case Node_C_Float:
			fprintf( p_Fp , "float");
			break;

			case Node_C_Handler_Statement:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "try\n");
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "{\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(0));
			indentDown();
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "}\n");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_C_If:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "if");
			generateCode( p_Fp, p_Tree->getSon(0));
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_C_Initialisation_Option:
			fprintf( p_Fp , "= ");
			generateCode( p_Fp, p_Tree->getSon(0));
			break;
			
			case Node_C_Int:
			fprintf( p_Fp , "int");
			break;
			
			case Node_C_Include_Local:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "#include \"");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , "\"\n");
			break;
			
			case Node_C_Iteration:
			fprintfIndent( p_Fp );
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp, " ");
			generateCode( p_Fp, p_Tree->getSon(1));
			fprintf( p_Fp, " ; ");
			generateCode( p_Fp, p_Tree->getSon(2));
			fprintf( p_Fp, ")");
			break;
			
			case Node_C_Iterative_Part:
			fprintf( p_Fp , "for( int ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " = ");
			generateCode( p_Fp, p_Tree->getSon(1));
			fprintf( p_Fp , " ;");
			break;
			
			case Node_C_Labelled_Stmt:
			fprintfIndent( p_Fp );
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ":\n");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_C_List_Condition_Clause:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , "\n");
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "else\n");
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "{\n");
			indentUp();
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "if");
			generateCode( p_Fp, p_Tree->getSon(1));
			indentDown();
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "}\n");
			break;
			
			case Node_C_List_Discrete_Range:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , "][");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_C_List_Parameter:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , ", ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_C_Loop:
			if( p_Tree->getSon(0)->getNodeType()!=Node_Ada_C_Empty)
			{
				fprintfIndent( p_Fp );
				generateCode( p_Fp, p_Tree->getSon(0));
				fprintf( p_Fp , "\n");
			}
			generateCode( p_Fp, p_Tree->getSon(1));
			fprintf( p_Fp , "\n");
			generateCode( p_Fp, p_Tree->getSon(2));
			fprintf( p_Fp , "\n");
			break;
			
			case Node_C_Mark:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , "::");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_C_Mod:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " % ");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_C_Namespace_Def:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "namespace ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , "\n");
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "{\n");
			indentUp();
			generateCode( p_Fp, p_Tree->getSon(1));
			generateCode( p_Fp, p_Tree->getSon(2));
			indentDown();
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "}\n");
			break;
			
			case Node_C_Non_Equal:
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , "!=");
			generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_C_Not:
			fprintf( p_Fp , "!");
			generateCode( p_Fp, p_Tree->getSon(0));
			break;
			
			case Node_C_Object_Decl:
			fprintfIndent( p_Fp );
			if( p_Tree->getSon(0)->getNodeType()!=Node_Ada_C_Empty)
			{
				generateCode( p_Fp, p_Tree->getSon(0));
				fprintf( p_Fp , " ");
			}
			
			generateCode( p_Fp, p_Tree->getSon(1));
			fprintf( p_Fp , " ");
			generateCode( p_Fp, p_Tree->getSon(2));
			
			if( p_Tree->getSon(3)->getNodeType()!=Node_Ada_C_Empty)
			{
				fprintf( p_Fp , " ");
				generateCode( p_Fp, p_Tree->getSon(3));
			}
			fprintf( p_Fp , ";\n");
			break;
			
			case Node_C_Or:
				generateCode( p_Fp, p_Tree->getSon(0));
				fprintf( p_Fp , " || ");
				generateCode( p_Fp, p_Tree->getSon(1));
			break;
			
			case Node_C_Parameter:
				generateCode( p_Fp, p_Tree->getSon(0));
				fprintf( p_Fp , " ");
				generateCode( p_Fp, p_Tree->getSon(1));
				generateCode( p_Fp, p_Tree->getSon(2));
				generateCode( p_Fp, p_Tree->getSon(3));
			break;
			
			case Node_C_Post_Less:
				generateCode( p_Fp, p_Tree->getSon(0) );
				fprintf( p_Fp , "--");
			break;
			
			case Node_C_Post_Plus:
				generateCode( p_Fp, p_Tree->getSon(0) );
				fprintf( p_Fp , "++");
			break;
			
			case Node_C_Power:
				fprintf( p_Fp , "pow(");
				generateCode( p_Fp, p_Tree->getSon(0));
				fprintf( p_Fp , ",");
				generateCode( p_Fp, p_Tree->getSon(1));
				fprintf( p_Fp , ")");
			break;
			
			case Node_C_Private_Part:
				fprintfIndent( p_Fp );
				fprintf( p_Fp , "// private\n");
				generateCode( p_Fp, p_Tree->getSon(0));
			break;
			
			case Node_C_Spaced:
				generateCode( p_Fp, p_Tree->getSon(0) );
				fprintf( p_Fp, " ");
				generateCode( p_Fp, p_Tree->getSon(1) );
			break;

			case Node_C_Subprog_Body:
				fprintfIndent( p_Fp );
				generateCode( p_Fp, p_Tree->getSon(0));
				fprintf( p_Fp , "\n");
				fprintfIndent( p_Fp );
				fprintf( p_Fp , "{\n");
				indentUp();
				generateCode( p_Fp, p_Tree->getSon(1));
				generateCode( p_Fp, p_Tree->getSon(2));
				indentDown();
				fprintfIndent( p_Fp );
				fprintf( p_Fp , "}\n");
			break;
			
			case Node_C_Star:
				fprintf( p_Fp , "*");
			break;
			
			case Node_C_Structured_Type_Decl:
				fprintfIndent( p_Fp );
				fprintf( p_Fp , "typedef struct ");
				generateCode( p_Fp, p_Tree->getSon(0));
				fprintf( p_Fp , "\n");
				fprintfIndent( p_Fp );
				fprintf( p_Fp , "{\n");
				indentUp();
				generateCode( p_Fp, p_Tree->getSon(1));
				indentDown();
				fprintfIndent( p_Fp );
				fprintf( p_Fp , "} ");
				generateCode( p_Fp, p_Tree->getSon(2));
				fprintf( p_Fp , ";\n");
			break;
			
			case Node_C_Subprog_Spec:
			{
				switch( p_Tree->getNbSon())
				{
					case 2:
						fprintf( p_Fp , "void ");
						generateCode( p_Fp, p_Tree->getSon(0));
						if( p_Tree->getSon(1)->getNodeType() != Node_Ada_C_Empty) 
						{
							generateCode( p_Fp, p_Tree->getSon(1) );
						}
						else
						{
							fprintf( p_Fp , "( void )");
						}
					break;
					case 3:
						generateCode( p_Fp, p_Tree->getSon(0));
						fprintf( p_Fp , " ");
						generateCode( p_Fp, p_Tree->getSon(1));
						if( p_Tree->getSon(2)->getNodeType() != Node_Ada_C_Empty) 
						{
							generateCode( p_Fp, p_Tree->getSon(2) );
						}
						else
						{
							fprintf( p_Fp , "( void )");
						}
					break;
					default:
						errorNbSon(__FILE__,__LINE__, p_Tree);
						my_exit(-1);
					break;
				}
			}
			break;
			
			case Node_C_Switch:
				fprintfIndent( p_Fp );
				fprintf( p_Fp , "switch(");
				generateCode( p_Fp, p_Tree->getSon(0));
				fprintf( p_Fp , ")\n");
				fprintfIndent( p_Fp );
				fprintf( p_Fp , "{\n");
				indentUp();
				generateCode( p_Fp, p_Tree->getSon(1));
				generateCode( p_Fp, p_Tree->getSon(2));
				indentDown();
				fprintfIndent( p_Fp );
				fprintf( p_Fp , "}\n");
			break;
			
			case Node_C_Unconstraint_Array_Type:
			fprintfIndent( p_Fp );
			fprintf( p_Fp , "typedef ");
			generateCode( p_Fp, p_Tree->getSon(0));
			fprintf( p_Fp , " ");
			generateCode( p_Fp, p_Tree->getSon(1));
			fprintf( p_Fp , ";");
			generateCode( p_Fp, p_Tree->getSon(2));
			fprintf( p_Fp , "\n");
			break;
			
			case Node_C_Using_Namespace:
				fprintfIndent( p_Fp );
				fprintf( p_Fp , "using namespace ");
				generateCode( p_Fp, p_Tree->getSon(0));
				fprintf( p_Fp , ";\n");
			break;
			
			case Node_C_While:
				fprintfIndent( p_Fp );
				fprintf( p_Fp , "while( ");
				generateCode( p_Fp, p_Tree->getSon(0));
				fprintf( p_Fp , ")");
			break;
			
			default:printf("ERROR : %s %i : ",__FILE__,__LINE__);
				displayNodeType( p_Tree->getNodeType());
				printf(" is not manage\n");
				my_exit(-1);
			break;
		}
		
	}
	else
	{
		int l_Error=0;
		
		if( p_Tree==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_Tree");
			l_Error=1;
		}	
		
		if( p_Fp==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_Fp");
			l_Error=1;
		}
		
		if(l_Error!=0)
		{
			my_exit(-1);
		}
	}
}
