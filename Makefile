#***************************************************************************#
#                       Ada_to_C_Cpp_Translator
#***************************************************************************#
# Adatoccpptranslator is a free software which convert Ada code to C/C++ 
# source code
# Copyright (C) 2004 Julien THEVENON
# This program is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the Free
# Software Foundation; either version 2 of the License, or (at your option) 
# any later version.
# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
# FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for 
# more details.
# You should have received a copy of the GNU General Public License along with
# this program; if not, write to the Free Software Foundation, Inc.,
# 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
# For further informations : adatoccpptranslator@free.fr
#
# $Log: Makefile,v $
# Revision 1.6  2005/03/27 01:19:15  quicky2000
# Update to add installer target which create missing directories necessary to build the translator
#
# Revision 1.5  2005/03/19 11:51:27  quicky2000
# Update to add value.o target
#
# Revision 1.4  2005/03/15 20:54:35  quicky2000
# Update to reflect the new management of ada suprograms in table of symbol
#
# Revision 1.3  2005/03/06 12:33:23  quicky2000
# Update to reflect the new organisation of sources
#
# Revision 1.2  2005/03/04 19:45:24  quicky2000
# Update due to the reorganization of source files
#
# Revision 1.1.1.1  2005/03/01 22:20:30  quicky2000
# Initial import
#

#**************************#
#* Variables declarations *#
#**************************#

#* Executables *#
# ------------- #
CPP=g++
YACC=bison
LEX=flex

#* Directories *#
# ------------- #
OBJ=obj
SRC=src
SRC_TS=src/Table_symbol
SRC_S1=src/Stage_1
SRC_S2=src/Stage_2
SRC_S3=src/Stage_3
SRC_TOOLS=src/Tools
TEST=test
BIN=bin
DOC=doc
OUT=output

all: translator

#*******************************************#
#* Targets declarations of class and tools *#
#*******************************************#

### access_function_type class
$(OBJ)/access_function_type.o: $(SRC_TS)/access_function_type.cpp $(SRC_TS)/access_function_type.h
	$(CPP) -c $(SRC_TS)/access_function_type.cpp -o $(OBJ)/access_function_type.o

### access_object_type class
$(OBJ)/access_object_type.o: $(SRC_TS)/access_object_type.cpp $(SRC_TS)/access_object_type.h
	$(CPP) -c $(SRC_TS)/access_object_type.cpp -o $(OBJ)/access_object_type.o

### access_procedure_type class
$(OBJ)/access_procedure_type.o: $(SRC_TS)/access_procedure_type.cpp $(SRC_TS)/access_procedure_type.h
	$(CPP) -c $(SRC_TS)/access_procedure_type.cpp -o $(OBJ)/access_procedure_type.o

### access_subprog_type class
$(OBJ)/access_subprog_type.o: $(SRC_TS)/access_subprog_type.cpp $(SRC_TS)/access_subprog_type.h
	$(CPP) -c $(SRC_TS)/access_subprog_type.cpp -o $(OBJ)/access_subprog_type.o

### access_type class
$(OBJ)/access_type.o: $(SRC_TS)/access_type.cpp $(SRC_TS)/access_type.h
	$(CPP) -c $(SRC_TS)/access_type.cpp -o $(OBJ)/access_type.o

### array class
$(OBJ)/array.o: $(SRC_TS)/array.cpp $(SRC_TS)/array.h
	$(CPP) -c $(SRC_TS)/array.cpp -o $(OBJ)/array.o

### array_type class
$(OBJ)/array_type.o: $(SRC_TS)/array_type.cpp $(SRC_TS)/array_type.h
	$(CPP) -c $(SRC_TS)/array_type.cpp -o $(OBJ)/array_type.o

### base_range class
$(OBJ)/base_range.o: $(SRC_TS)/base_range.cpp $(SRC_TS)/base_range.h
	$(CPP) -c $(SRC_TS)/base_range.cpp -o $(OBJ)/base_range.o

### code generation tools
$(OBJ)/code_generation.o: $(SRC_S3)/code_generation.cpp $(SRC_S3)/code_generation.h
	$(CPP) -c $(SRC_S3)/code_generation.cpp -o $(OBJ)/code_generation.o

### command argument tools
$(OBJ)/command_argument.o: $(SRC_TOOLS)/command_argument.cpp $(SRC_TOOLS)/command_argument.h
	$(CPP) -c $(SRC_TOOLS)/command_argument.cpp -o $(OBJ)/command_argument.o

### component class
$(OBJ)/component.o: $(SRC_TS)/component.cpp $(SRC_TS)/component.h
	$(CPP) -c $(SRC_TS)/component.cpp -o $(OBJ)/component.o

### component_list class
$(OBJ)/component_list.o: $(SRC_TS)/component_list.cpp $(SRC_TS)/component_list.h
	$(CPP) -c $(SRC_TS)/component_list.cpp -o $(OBJ)/component_list.o

### composite_type class
$(OBJ)/composite_type.o: $(SRC_TS)/composite_type.cpp $(SRC_TS)/composite_type.h
	$(CPP) -c $(SRC_TS)/composite_type.cpp -o $(OBJ)/composite_type.o

### configuration tools
$(OBJ)/configuration.o: $(SRC_TOOLS)/configuration.cpp $(SRC_TOOLS)/configuration.h
	$(CPP) -c $(SRC_TOOLS)/configuration.cpp -o $(OBJ)/configuration.o

### constant_number class
$(OBJ)/constant_number.o: $(SRC_TS)/constant_number.cpp $(SRC_TS)/constant_number.h
	$(CPP) -c $(SRC_TS)/constant_number.cpp -o $(OBJ)/constant_number.o

### decimal_fixed_type class
$(OBJ)/decimal_fixed_type.o: $(SRC_TS)/decimal_fixed_type.cpp $(SRC_TS)/decimal_fixed_type.h
	$(CPP) -c $(SRC_TS)/decimal_fixed_type.cpp -o $(OBJ)/decimal_fixed_type.o

### derived_type class
$(OBJ)/derived_type.o: $(SRC_TS)/derived_type.cpp $(SRC_TS)/derived_type.h
	$(CPP) -c $(SRC_TS)/derived_type.cpp -o $(OBJ)/derived_type.o

### discrete_type class
$(OBJ)/discrete_type.o: $(SRC_TS)/discrete_type.cpp $(SRC_TS)/discrete_type.h
	$(CPP) -c $(SRC_TS)/discrete_type.cpp -o $(OBJ)/discrete_type.o

### discrim_spec class
$(OBJ)/discrim_spec.o: $(SRC_TS)/discrim_spec.cpp $(SRC_TS)/discrim_spec.h
	$(CPP) -c $(SRC_TS)/discrim_spec.cpp -o $(OBJ)/discrim_spec.o

### discrimined class
$(OBJ)/discrimined.o: $(SRC_TS)/discrimined.cpp $(SRC_TS)/discrimined.h
	$(CPP) -c $(SRC_TS)/discrimined.cpp -o $(OBJ)/discrimined.o

### elementary_type class
$(OBJ)/elementary_type.o: $(SRC_TS)/elementary_type.cpp $(SRC_TS)/elementary_type.h
	$(CPP) -c $(SRC_TS)/elementary_type.cpp -o $(OBJ)/elementary_type.o

### enumerated_type class
$(OBJ)/enumerated_type.o: $(SRC_TS)/enumerated_type.cpp $(SRC_TS)/enumerated_type.h
	$(CPP) -c $(SRC_TS)/enumerated_type.cpp -o $(OBJ)/enumerated_type.o

### error management tools
$(OBJ)/error.o: $(SRC_TOOLS)/error.cpp $(SRC_TOOLS)/error.h
	$(CPP) -c $(SRC_TOOLS)/error.cpp -o $(OBJ)/error.o

### files objects tools
$(OBJ)/file.o: $(SRC_TS)/file.cpp $(SRC_TS)/file.h
	$(CPP) -c $(SRC_TS)/file.cpp -o $(OBJ)/file.o

### files management tools
$(OBJ)/file_management.o: $(SRC_TOOLS)/file_management.cpp $(SRC_TOOLS)/file_management.h
	$(CPP) -c $(SRC_TOOLS)/file_management.cpp -o $(OBJ)/file_management.o

### fixed_type class
$(OBJ)/fixed_type.o: $(SRC_TS)/fixed_type.cpp $(SRC_TS)/fixed_type.h
	$(CPP) -c $(SRC_TS)/fixed_type.cpp -o $(OBJ)/fixed_type.o

### float_type class
$(OBJ)/float_type.o: $(SRC_TS)/float_type.cpp $(SRC_TS)/float_type.h
	$(CPP) -c $(SRC_TS)/float_type.cpp -o $(OBJ)/float_type.o

### function_body class
$(OBJ)/function_body.o: $(SRC_TS)/function_body.cpp $(SRC_TS)/function_body.h
	$(CPP) -c $(SRC_TS)/function_body.cpp -o $(OBJ)/function_body.o

### function_prototype class
$(OBJ)/function_prototype.o: $(SRC_TS)/function_prototype.cpp $(SRC_TS)/function_prototype.h
	$(CPP) -c $(SRC_TS)/function_prototype.cpp -o $(OBJ)/function_prototype.o

### function_rename class
$(OBJ)/function_rename.o: $(SRC_TS)/function_rename.cpp $(SRC_TS)/function_rename.h
	$(CPP) -c $(SRC_TS)/function_rename.cpp -o $(OBJ)/function_rename.o

### function_spec class
$(OBJ)/function_spec.o: $(SRC_TS)/function_spec.cpp $(SRC_TS)/function_spec.h
	$(CPP) -c $(SRC_TS)/function_spec.cpp -o $(OBJ)/function_spec.o

### generic_package_inst class
$(OBJ)/generic_package_inst.o: $(SRC_TS)/generic_package_inst.cpp $(SRC_TS)/generic_package_inst.h
	$(CPP) -c $(SRC_TS)/generic_package_inst.cpp -o $(OBJ)/generic_package_inst.o

### indent tools
$(OBJ)/indent.o: $(SRC_TOOLS)/indent.cpp $(SRC_TOOLS)/indent.h
	$(CPP) -c $(SRC_TOOLS)/indent.cpp -o $(OBJ)/indent.o

### initialised class
$(OBJ)/initialised.o: $(SRC_TS)/initialised.cpp $(SRC_TS)/initialised.h
	$(CPP) -c $(SRC_TS)/initialised.cpp -o $(OBJ)/initialised.o

### integer_type tools
$(OBJ)/integer_type.o: $(SRC_TS)/integer_type.cpp $(SRC_TS)/integer_type.h
	$(CPP) -c $(SRC_TS)/integer_type.cpp -o $(OBJ)/integer_type.o

### list tools
$(OBJ)/list.o: $(SRC_TOOLS)/list.cpp $(SRC_TOOLS)/list.h
	$(CPP) -c $(SRC_TOOLS)/list.cpp -o $(OBJ)/list.o
	
### list tools
$(OBJ)/list_tools.o: $(SRC_TOOLS)/list_tools.cpp $(SRC_TOOLS)/list_tools.h
	$(CPP) -c $(SRC_TOOLS)/list_tools.cpp -o $(OBJ)/list_tools.o

### main_unit class
$(OBJ)/main_unit.o: $(SRC_TS)/main_unit.cpp $(SRC_TS)/main_unit.h
	$(CPP) -c $(SRC_TS)/main_unit.cpp -o $(OBJ)/main_unit.o

### modular_integer_type class
$(OBJ)/modular_integer_type.o: $(SRC_TS)/modular_integer_type.cpp $(SRC_TS)/modular_integer_type.h
	$(CPP) -c $(SRC_TS)/modular_integer_type.cpp -o $(OBJ)/modular_integer_type.o

### strign management tools
$(OBJ)/my_string.o: $(SRC_TOOLS)/my_string.cpp $(SRC_TOOLS)/my_string.h
	$(CPP) -c $(SRC_TOOLS)/my_string.cpp -o $(OBJ)/my_string.o

### named class
$(OBJ)/named.o: $(SRC_TS)/named.cpp $(SRC_TS)/named.h
	$(CPP) -c $(SRC_TS)/named.cpp -o $(OBJ)/named.o
	
### object class
$(OBJ)/object.o: $(SRC_TS)/object.cpp $(SRC_TS)/object.h
	$(CPP) -c $(SRC_TS)/object.cpp -o $(OBJ)/object.o

### ordinary_fixed_type class
$(OBJ)/ordinary_fixed_type.o: $(SRC_TS)/ordinary_fixed_type.cpp $(SRC_TS)/ordinary_fixed_type.h
	$(CPP) -c $(SRC_TS)/ordinary_fixed_type.cpp -o $(OBJ)/ordinary_fixed_type.o

### package class
$(OBJ)/package.o: $(SRC_TS)/package.cpp $(SRC_TS)/package.h
	$(CPP) -c $(SRC_TS)/package.cpp -o $(OBJ)/package.o

### package_rename class
$(OBJ)/package_rename.o: $(SRC_TS)/package_rename.cpp $(SRC_TS)/package_rename.h
	$(CPP) -c $(SRC_TS)/package_rename.cpp -o $(OBJ)/package_rename.o

### parameter class
$(OBJ)/parameter.o: $(SRC_TS)/parameter.cpp $(SRC_TS)/parameter.h
	$(CPP) -c $(SRC_TS)/parameter.cpp -o $(OBJ)/parameter.o

### procedure_body class
$(OBJ)/procedure_body.o: $(SRC_TS)/procedure_body.cpp $(SRC_TS)/procedure_body.h
	$(CPP) -c $(SRC_TS)/procedure_body.cpp -o $(OBJ)/procedure_body.o

### procedure_prototype class
$(OBJ)/procedure_prototype.o: $(SRC_TS)/procedure_prototype.cpp $(SRC_TS)/procedure_prototype.h
	$(CPP) -c $(SRC_TS)/procedure_prototype.cpp -o $(OBJ)/procedure_prototype.o

### procedure_rename class
$(OBJ)/procedure_rename.o: $(SRC_TS)/procedure_rename.cpp $(SRC_TS)/procedure_rename.h
	$(CPP) -c $(SRC_TS)/procedure_rename.cpp -o $(OBJ)/procedure_rename.o

### procedure_spec class
$(OBJ)/procedure_spec.o: $(SRC_TS)/procedure_spec.cpp $(SRC_TS)/procedure_spec.h
	$(CPP) -c $(SRC_TS)/procedure_spec.cpp -o $(OBJ)/procedure_spec.o

### prot class
$(OBJ)/prot.o: $(SRC_TS)/prot.cpp $(SRC_TS)/prot.h
	$(CPP) -c $(SRC_TS)/prot.cpp -o $(OBJ)/prot.o

### prot_type class
$(OBJ)/prot_type.o: $(SRC_TS)/prot_type.cpp $(SRC_TS)/prot_type.h
	$(CPP) -c $(SRC_TS)/prot_type.cpp -o $(OBJ)/prot_type.o

### real_type class
$(OBJ)/range.o: $(SRC_TS)/range.cpp $(SRC_TS)/range.h
	$(CPP) -c $(SRC_TS)/range.cpp -o $(OBJ)/range.o

### real_type class
$(OBJ)/real_type.o: $(SRC_TS)/real_type.cpp $(SRC_TS)/real_type.h
	$(CPP) -c $(SRC_TS)/real_type.cpp -o $(OBJ)/real_type.o

### record_type class
$(OBJ)/record_type.o: $(SRC_TS)/record_type.cpp $(SRC_TS)/record_type.h
	$(CPP) -c $(SRC_TS)/record_type.cpp -o $(OBJ)/record_type.o

### renamed class
$(OBJ)/renamed.o: $(SRC_TS)/renamed.cpp $(SRC_TS)/renamed.h
	$(CPP) -c $(SRC_TS)/renamed.cpp -o $(OBJ)/renamed.o

### scalar_type class
$(OBJ)/scalar_type.o: $(SRC_TS)/scalar_type.cpp $(SRC_TS)/scalar_type.h
	$(CPP) -c $(SRC_TS)/scalar_type.cpp -o $(OBJ)/scalar_type.o

### signed_integer_type class
$(OBJ)/signed_integer_type.o: $(SRC_TS)/signed_integer_type.cpp $(SRC_TS)/signed_integer_type.h
	$(CPP) -c $(SRC_TS)/signed_integer_type.cpp -o $(OBJ)/signed_integer_type.o

### subtype class
$(OBJ)/subtype.o: $(SRC_TS)/subtype.cpp $(SRC_TS)/subtype.h
	$(CPP) -c $(SRC_TS)/subtype.cpp -o $(OBJ)/subtype.o

### subtyped class
$(OBJ)/subtyped.o: $(SRC_TS)/subtyped.cpp $(SRC_TS)/subtyped.h
	$(CPP) -c $(SRC_TS)/subtyped.cpp -o $(OBJ)/subtyped.o

### subunit class
$(OBJ)/subunit.o: $(SRC_TS)/subunit.cpp $(SRC_TS)/subunit.h
	$(CPP) -c $(SRC_TS)/subunit.cpp -o $(OBJ)/subunit.o

### table_symbol class
$(OBJ)/table_symbol.o: $(SRC_TS)/table_symbol.cpp $(SRC_TS)/table_symbol.h
	$(CPP) -c $(SRC_TS)/table_symbol.cpp -o $(OBJ)/table_symbol.o
	
### table symbol creation tools
$(OBJ)/table_symbol_creation.o: $(SRC_S2)/table_symbol_creation.cpp $(SRC_S2)/table_symbol_creation.h
	$(CPP) -c $(SRC_S2)/table_symbol_creation.cpp -o $(OBJ)/table_symbol_creation.o
	
### table symbol exploitation tools
$(OBJ)/table_symbol_exploitation.o: $(SRC_S3)/table_symbol_exploitation.cpp $(SRC_S3)/table_symbol_exploitation.h
	$(CPP) -c $(SRC_S3)/table_symbol_exploitation.cpp -o $(OBJ)/table_symbol_exploitation.o
	
### task class
$(OBJ)/task.o: $(SRC_TS)/task.cpp $(SRC_TS)/task.h
	$(CPP) -c $(SRC_TS)/task.cpp -o $(OBJ)/task.o
	
### task_type class
$(OBJ)/task_type.o: $(SRC_TS)/task_type.cpp $(SRC_TS)/task_type.h
	$(CPP) -c $(SRC_TS)/task_type.cpp -o $(OBJ)/task_type.o
	
### trace tools
$(OBJ)/trace.o: $(SRC_TOOLS)/trace.cpp $(SRC_TOOLS)/trace.h
	$(CPP) -c $(SRC_TOOLS)/trace.cpp -o $(OBJ)/trace.o
	
### tree tools
$(OBJ)/tree.o: $(SRC_TOOLS)/tree.cpp $(SRC_TOOLS)/tree.h
	$(CPP) -c $(SRC_TOOLS)/tree.cpp -o $(OBJ)/tree.o
	
### tree_string_representation tools
$(OBJ)/tree_string_representation.o: $(SRC_TOOLS)/tree_string_representation.cpp $(SRC_TOOLS)/tree_string_representation.h
	$(CPP) -c $(SRC_TOOLS)/tree_string_representation.cpp -o $(OBJ)/tree_string_representation.o
	
### tree translation tools
$(OBJ)/tree_translation.o: $(SRC_S3)/tree_translation.cpp $(SRC_S3)/tree_translation.h
	$(CPP) -c $(SRC_S3)/tree_translation.cpp -o $(OBJ)/tree_translation.o
	
### type class
$(OBJ)/type.o: $(SRC_TS)/type.cpp $(SRC_TS)/type.h
	$(CPP) -c $(SRC_TS)/type.cpp -o $(OBJ)/type.o

### typed class
$(OBJ)/typed.o: $(SRC_TS)/typed.cpp $(SRC_TS)/typed.h
	$(CPP) -c $(SRC_TS)/typed.cpp -o $(OBJ)/typed.o

### unit class
$(OBJ)/unit.o: $(SRC_TS)/unit.cpp $(SRC_TS)/unit.h
	$(CPP) -c $(SRC_TS)/unit.cpp -o $(OBJ)/unit.o

### value class
$(OBJ)/value.o: $(SRC_TOOLS)/value.cpp $(SRC_TOOLS)/value.h
	$(CPP) -c $(SRC_TOOLS)/value.cpp -o $(OBJ)/value.o

### variable class
$(OBJ)/variable.o: $(SRC_TS)/variable.cpp $(SRC_TS)/variable.h
	$(CPP) -c $(SRC_TS)/variable.cpp -o $(OBJ)/variable.o

### variable_array class
$(OBJ)/variable_array.o: $(SRC_TS)/variable_array.cpp $(SRC_TS)/variable_array.h
	$(CPP) -c $(SRC_TS)/variable_array.cpp -o $(OBJ)/variable_array.o

### variable_object class
$(OBJ)/variable_object.o: $(SRC_TS)/variable_object.cpp $(SRC_TS)/variable_object.h
	$(CPP) -c $(SRC_TS)/variable_object.cpp -o $(OBJ)/variable_object.o

### variant class
$(OBJ)/variant.o: $(SRC_TS)/variant.cpp $(SRC_TS)/variant.h
	$(CPP) -c $(SRC_TS)/variant.cpp -o $(OBJ)/variant.o


#**********************************************************#
#* Targets declarations for lexical and syntaxic analyzer *#
#**********************************************************#

$(OBJ)/y.tab.h: $(SRC_S1)/syntax.y
	$(YACC) -d -b $(OBJ)/y $(SRC_S1)/syntax.y 

$(OBJ)/y.tab.c: $(SRC_S1)/syntax.y
	$(YACC) -d -b $(OBJ)/y $(SRC_S1)/syntax.y

$(OBJ)/lex.yy.c: $(SRC_S1)/lexico.l
	$(LEX) -i -o$(OBJ)/lex.yy.c $(SRC_S1)/lexico.l

$(OBJ)/lex.yy.o: $(OBJ)/lex.yy.c $(OBJ)/y.tab.h
	$(CPP) -c $(OBJ)/lex.yy.c -o $(OBJ)/lex.yy.o

$(OBJ)/y.tab.o: $(OBJ)/y.tab.c $(OBJ)/y.tab.h
	$(CPP) -c $(OBJ)/y.tab.c -o $(OBJ)/y.tab.o 

$(OBJ)/jt_seq.o: $(SRC_S1)/jt_seq.cpp $(OBJ)/y.tab.h
	$(CPP) -c $(SRC_S1)/jt_seq.cpp -o $(OBJ)/jt_seq.o


#*****************************************#
#* Targets declarations of test programs *#
#*****************************************#

### test of lexical and syntaxic analysis
test_parsing: $(OBJ)/error.o $(OBJ)/file_management.o $(OBJ)/jt_seq.o $(OBJ)/lex.yy.o $(OBJ)/my_string.o $(OBJ)/trace.o $(OBJ)/tree.o $(OBJ)/y.tab.o $(TEST)/test_parsing.cpp
	$(CPP) -o $(BIN)/test_parsing $(OBJ)/error.o $(OBJ)/file_management.o $(OBJ)/jt_seq.o $(OBJ)/lex.yy.o $(OBJ)/my_string.o $(OBJ)/trace.o $(OBJ)/tree.o $(OBJ)/y.tab.o $(TEST)/test_parsing.cpp

#*************************************#
#* Target declarations of translator *#
#*************************************#
### test tree translation
translator: $(OBJ)/access_function_type.o $(OBJ)/access_object_type.o $(OBJ)/access_procedure_type.o $(OBJ)/access_subprog_type.o $(OBJ)/access_type.o $(OBJ)/array.o $(OBJ)/array_type.o $(OBJ)/base_range.o $(OBJ)/code_generation.o $(OBJ)/command_argument.o $(OBJ)/component.o $(OBJ)/component_list.o $(OBJ)/composite_type.o $(OBJ)/configuration.o $(OBJ)/constant_number.o $(OBJ)/decimal_fixed_type.o $(OBJ)/derived_type.o $(OBJ)/discrete_type.o $(OBJ)/discrim_spec.o $(OBJ)/discrimined.o $(OBJ)/elementary_type.o $(OBJ)/enumerated_type.o $(OBJ)/error.o $(OBJ)/file.o $(OBJ)/float_type.o $(OBJ)/file_management.o $(OBJ)/fixed_type.o $(OBJ)/function_body.o $(OBJ)/function_prototype.o $(OBJ)/function_rename.o $(OBJ)/function_spec.o $(OBJ)/generic_package_inst.o $(OBJ)/indent.o $(OBJ)/initialised.o $(OBJ)/integer_type.o $(OBJ)/jt_seq.o $(OBJ)/lex.yy.o $(OBJ)/list.o $(OBJ)/list_tools.o $(OBJ)/main_unit.o $(OBJ)/modular_integer_type.o $(OBJ)/my_string.o $(OBJ)/named.o $(OBJ)/object.o $(OBJ)/ordinary_fixed_type.o $(OBJ)/package.o $(OBJ)/package_rename.o $(OBJ)/parameter.o $(OBJ)/procedure_body.o $(OBJ)/procedure_prototype.o $(OBJ)/procedure_rename.o $(OBJ)/procedure_spec.o $(OBJ)/prot.o $(OBJ)/prot_type.o $(OBJ)/range.o $(OBJ)/real_type.o $(OBJ)/record_type.o $(OBJ)/renamed.o $(OBJ)/scalar_type.o $(OBJ)/signed_integer_type.o  $(OBJ)/subtype.o $(OBJ)/subtyped.o $(OBJ)/subunit.o $(OBJ)/task.o $(OBJ)/task_type.o $(OBJ)/table_symbol.o $(OBJ)/table_symbol_creation.o $(OBJ)/table_symbol_exploitation.o $(OBJ)/trace.o $(OBJ)/tree.o $(OBJ)/tree_string_representation.o $(OBJ)/tree_translation.o $(OBJ)/type.o $(OBJ)/typed.o $(OBJ)/unit.o $(OBJ)/value.o $(OBJ)/variable.o $(OBJ)/variable_array.o $(OBJ)/variable_object.o $(OBJ)/variant.o $(OBJ)/y.tab.o $(TEST)/translator.cpp 
	$(CPP) -o $(BIN)/translator $(OBJ)/access_function_type.o $(OBJ)/access_object_type.o $(OBJ)/access_procedure_type.o $(OBJ)/access_subprog_type.o $(OBJ)/access_type.o $(OBJ)/array.o $(OBJ)/array_type.o $(OBJ)/base_range.o $(OBJ)/code_generation.o $(OBJ)/command_argument.o $(OBJ)/component.o $(OBJ)/component_list.o $(OBJ)/composite_type.o $(OBJ)/configuration.o $(OBJ)/constant_number.o $(OBJ)/decimal_fixed_type.o $(OBJ)/derived_type.o $(OBJ)/discrete_type.o $(OBJ)/discrim_spec.o $(OBJ)/discrimined.o $(OBJ)/elementary_type.o $(OBJ)/enumerated_type.o $(OBJ)/error.o $(OBJ)/file.o $(OBJ)/float_type.o $(OBJ)/file_management.o $(OBJ)/fixed_type.o $(OBJ)/function_body.o $(OBJ)/function_prototype.o $(OBJ)/function_rename.o $(OBJ)/function_spec.o $(OBJ)/generic_package_inst.o $(OBJ)/indent.o $(OBJ)/initialised.o $(OBJ)/integer_type.o $(OBJ)/jt_seq.o $(OBJ)/lex.yy.o $(OBJ)/list.o $(OBJ)/list_tools.o $(OBJ)/main_unit.o $(OBJ)/modular_integer_type.o $(OBJ)/my_string.o $(OBJ)/named.o $(OBJ)/object.o $(OBJ)/ordinary_fixed_type.o $(OBJ)/package.o $(OBJ)/package_rename.o $(OBJ)/parameter.o $(OBJ)/procedure_body.o $(OBJ)/procedure_prototype.o $(OBJ)/procedure_rename.o $(OBJ)/procedure_spec.o $(OBJ)/prot.o $(OBJ)/prot_type.o $(OBJ)/range.o $(OBJ)/real_type.o $(OBJ)/record_type.o $(OBJ)/renamed.o $(OBJ)/scalar_type.o $(OBJ)/signed_integer_type.o  $(OBJ)/subtype.o $(OBJ)/subtyped.o $(OBJ)/subunit.o $(OBJ)/task.o $(OBJ)/task_type.o $(OBJ)/table_symbol.o $(OBJ)/table_symbol_creation.o $(OBJ)/table_symbol_exploitation.o $(OBJ)/trace.o $(OBJ)/tree.o $(OBJ)/tree_string_representation.o $(OBJ)/tree_translation.o $(OBJ)/type.o $(OBJ)/typed.o $(OBJ)/unit.o $(OBJ)/value.o $(OBJ)/variable.o $(OBJ)/variable_array.o $(OBJ)/variable_object.o $(OBJ)/variant.o $(OBJ)/y.tab.o $(TEST)/translator.cpp 


#*********************************#
#* Target declaration of cleaner *#
#*********************************#

### cleaner Linux
clean:
	rm -f *~ *.txt *.o $(BIN)/* $(OBJ)/*.* $(SRC)/*~ $(DOC)/*~ $(OUT)/*.* $(SRC_TS)/*~ $(SRC_S1)/*~ $(SRC_S2)/*~ $(SRC_S3)/*~ $(SRC_TOOLS)/*~

### cleaner Windows
cleanw:
	del /Q *.txt *.bak $(BIN)\* $(OBJ)\*.* $(OUT)\*.* $(SRC_S1)\*.bak $(SRC_S2)\*.bak $(SRC_S3)\*.bak $(SRC_TOOLS)\*.bak $(SRC_TS)\*.bak $(TEST)\*.bak

#***********************************#
#* Target declaration of installer *#
#***********************************#
install:
	@mkdir bin
	@mkdir obj
	@mkdir input
	@mkdir output
	@echo "***********************"
	@echo "-> Install successfull"
	@echo "***********************"
