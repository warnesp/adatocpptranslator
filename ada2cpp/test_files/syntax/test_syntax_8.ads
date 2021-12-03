-- $Log: test_syntax_8.ads,v $
-- Revision 1.2  2005/03/16 18:23:21  quicky2000
-- Update to add the cvs log flag
--

-- rule unit
-- test_of
-- pkg_decl

	-- rule pkg_decl
	-- test_of
	-- pkg_spec ';'
	
		-- rule pkg_spec
		-- test_of
		-- PACKAGE_Lex compound_name IS_Lex decl_item_s private_part END_Lex c_id_opt

			-- rule decl_item_s
			-- test_of
			-- 
			package compound.name is
			
			-- rule decl_item_s
			-- test_of
			-- decl_item_s1
			
				-- rule decl_item_s1
				-- test_of
				-- decl_item
				
					-- rule decl_item
					-- test_of
					-- decl
					
						-- rule decl
						-- test_of
						-- object_decl
						
							-- rule object_decl
							-- test_of
							-- def_id_s ':' object_qualifier_opt object_subtype_def init_opt ';'
							
								-- rule def_id_s
								-- test_of
								-- IDF_Lex
								idf:integer;
							
								-- rule def_id_s
								-- test_of
								-- def_id_s ',' IDF_Lex
								idf,idf2:integer;
							
								-- rule object_qualifier_opt
								-- test_of
								-- ALIASED_Lex
								idf,idf2:aliased integer;
								
								-- rule object_qualifier_opt
								-- test_of
								-- ALIASED_Lex
								idf,idf2:constant integer;
							
								-- rule object_qualifier_opt
								-- test_of
								-- ALIASED_Lex
								idf,idf2:aliased constant integer;
							
								-- rule object_subtype_def
								-- test_of
								-- subtype_ind
								
									-- rule subtype_ind
									-- test_of
									-- name constraint
									
										-- rule constraint
										-- test_of
										-- range_constraint
										idf,idf2:aliased constant name range 1..2;
										
										-- rule constraint
										-- test_of
										-- decimal_digits_constraint

											-- rule decimal_digits_constraint
											-- test_of
											-- DIGITS_Lex expression range_constr_opt
											idf,idf2:aliased constant name digits 4;
											idf,idf2:aliased constant name digits 4 range 0..1000;
										

								
								
								-- rule object_subtype_def
								-- test_of
								-- array_type
								
									-- rule array_type
									-- test_of
									-- unconstr_array_type
										
										-- rule unconstr_array_type
										-- test_of
										-- ARRAY_Lex '(' index_s ')' OF_Lex component_subtype_def
										
											-- rule unconstr_array_type
											-- test_of
											-- index_s
											
												-- rule index_s		-- rule component_subtype_def
												-- test_of		-- test of
												-- index		-- aliased_opt subtype_ind
												idf10: array( name range <>) of integer;
												idf11,idf12: array( name range <>) of aliased integer;
										
											
												-- rule index_s
												-- test_of
												-- index_s ',' index
												idf10: array( name range <>, name2 range <>) of integer;
												idf11,idf12: array( name range <>, name2 range <>) of aliased integer;
										
											


									-- rule array_type
									-- test_of
									-- constr_array_type
									
										-- rule constr_array_type
										-- test_of
										-- ARRAY_Lex '(' iter_discrete_range_s ')' OF_Lex component_subtype_def
										
											-- rule iter_discrete_range_s
											-- test_of
											-- discrete_range
											
												-- rule discrete_range
												-- test_of
												-- name range_constr_opt
												idf11,idf12: array(name range 1..2) of aliased integer;
												idf11,idf12: array(name) of aliased integer;
										
												-- rule discrete_range
												-- test_of
												-- range
												idf11,idf12: array(11..22) of aliased integer;
										
											
											-- rule iter_discrete_range_s
											-- test_of
											-- iter_discrete_range_s ',' discrete_range
											idf11,idf12: array(name range 1..2,name) of aliased integer;
											


							
						
						-- rule decl
						-- test_of
						-- number_decl
						
							-- rule decl
							-- test_of
							-- def_id_s ':' CONSTANT_Lex AFFECT_Lex expression ';'
							idf,idf2:constant:=10+2.3;
						
						-- rule decl
						-- test_of
						-- type_decl
						
							-- rule decl
							-- test_of
							-- TYPE_Lex IDF_Lex discrim_part_opt IS_Lex type_def ';'
							
								-- rule discrim_part_opt
								-- test_of
								-- 
								type idf is new integer;
								
								-- rule discrim_part_opt
								-- test_of
								-- discrim_part
								
									-- rule discrim_part
									-- test_of
									-- '(' discrim_spec_s ')'
								
										-- rule discrim_spec_s
										-- test_of
										-- discrim_spec
										
											-- rule discrim_spec
											-- test_of
											-- def_id_s ':' access_opt mark init_opt
											
												-- rule mark
												-- test_of
												-- mark ''' attribute_id

												-- rule mark
												-- test_of
												-- mark '.' simple_name
												type idf ( x,y: mark'attrib_id)is new integer;
												type idf ( x,y: access mark.attrib_id:=0)is new integer;




										-- rule discrim_spec_s
										-- test_of
										-- discrim_spec_s ';' discrim_spec
										type idf ( x,y: access mark.attrib_id:=0;x,y: mark'attrib_id)is new integer;
										
								-- rule discrim_part_opt
								-- test_of
								-- '(' BOX_Lex ')'
								type idf (<>) is new integer;
								
								-- rule type_def
								-- test_of
								-- enumeration_type 
								
									-- rule enumeration_type
									-- test_of
									--  enum_id_s

										-- rule enum_id_s
										-- test_of
										-- enum_id 
										type idf (<>) is (enum_id);
								
										-- rule enum_id_s
										-- test_of
										-- enum_id_s ',' enum_id 
										type idf (<>) is (enum_id,enum_id2);
								
										

								-- rule type_def
								-- test_of
								-- integer_type
								
									-- rule integer_type
									-- test_of
									-- range_spec

										-- rule range_spec
										-- test_of
										-- range_constraint
										type idf (<>) is range 1..10;
								

									-- rule integer_type
									-- test_of
									-- MOD_Lex expression
									type idf (<>) is mod 1000*10;
								
								
								-- rule type_def
								-- test_of
								-- real_type
								
									-- rule real_type
									-- test_of
									-- float_type
									
										-- rule float_type
										-- test_of
										-- DIGITS_Lex expression range_spec_opt
										type idf is digits 1+2 range 1..2;
										type idf is digits 1+2;
									
									
									-- rule real_type
									-- test_of
									-- fixed_type
									
										-- rule fixed_type
										-- test_of
										-- DELTA_Lex expression range_spec
										type idf is delta 1+2 range 1..2;
									
										-- rule fixed_type
										-- test_of
										-- DELTA_Lex expression DIGITS_Lex expression range_spec_opt
										type idf is delta 1+2 digits 3 range 1..2;
										type idf is delta 1+2 digits 3;
									
									
								
								
								
								-- rule type_def
								-- test_of
								-- array_type
								type idf is array( name range <>) of integer;
								type idf is array( name range 1..2,name range 1..2) of integer;
								
								-- rule type_def
								-- test_of
								-- record_type
								
									-- rule record_type
									-- test_of
									-- tagged_opt limited_opt record_def
									
										-- rule record_def
										-- test_of
										-- NULL_Lex RECORD_Lex
										type idf is null record;
										type idf is tagged null record;
										type idf is limited null record;
										type idf is tagged limited null record;
										
										-- rule record_def
										-- test_of
										-- RECORD_Lex pragma_s comp_list END_Lex RECORD_Lex
										type idf is record
										x,y:integer:=0;
										end record;
										
										type idf is record
										pragma moi;
										x,y:integer:=0;
										end record;
										
										type idf is record
										pragma moi;
										pragma moi2;
										x,y:integer:=0;
										end record;
										

											-- rule comp_list
											-- test_of
											-- comp_decl_s variant_part_opt
											
												-- rule comp_decl_s
												-- test_of
												-- comp_decl
												type idf is record
												x,y:integer:=0;
												end record;
												
												-- rule comp_decl_s
												-- test_of
												-- comp_decl_s pragma_s comp_decl
												type idf is record
												x,y:integer:=0;
												x2,y2:integer:=0;
												end record;
												
												type idf is record
												x,y:integer:=0;
												pragma prgm;
												pragma prgm2;
												x2,y2:integer:=0;
												end record;
												
												-- rule variant_part_opt
												-- test_of
												-- variant_part
												
													-- rule variant_part
													-- test_of
													-- CASE_Lex simple_name IS_Lex pragma_s variant_s END_Lex CASE_Lex ';'

														-- rule variant_s
														-- test_of
														-- variant
														
															-- rule variant_s
															-- test_of
															-- WHEN_Lex choice_s FLECHE_Lex pragma_s comp_list
															type idf is record
															--pragma moi;
															
															--x,y:integer:=0;
															
															case simple is
															pragma prgm;
															pragma prgm2;
															when 1 => pragma moi;
																x1,y1:integer:=1;
															
															end case;
															
															end record;
														
														
														
														-- rule variant_s
														-- test_of
														-- variant_s variant
														type idf is record
															pragma moi;
															
															x,y:integer:=0;
															
															case simple is
															pragma prgm;
															pragma prgm2;
															when 1 => pragma moi;
																x1,y1:integer:=1;
															when 2 => pragma moi;
																x2,y2:integer:=1;
															
															
															end case;
															
														end record;

												
												
												
												
												
											
											
											
											-- rule comp_list
											-- test_of
											-- variant_part pragma_s
											type idf is record
												case simple is
												pragma prgm;
												pragma prgm2;
												when 1 => pragma moi;
													x1,y1:integer:=1;
												when 2 => pragma moi;
													x2,y2:integer:=1;


												end case;
												pragma moi;


											end record;
											-- rule comp_list
											-- test_of
											-- NULL_Lex ';' pragma_s
											type idf is record
											null;
											pragma moi;


											end record;
											

										
								
								
								-- rule type_def
								-- test_of
								-- access_type

									-- rule access_type
									-- test_of
									-- ACCESS_Lex subtype_ind
									type idf is access name;
									
									-- rule access_type
									-- test_of
									-- ACCESS_Lex CONSTANT_Lex subtype_ind
									type idf is access constant name;
									
									-- rule access_type
									-- test_of
									-- ACCESS_Lex CONSTANT_Lex subtype_ind
									type idf is access all name;
									
									-- rule access_type
									-- test_of
									-- ACCESS_Lex prot_opt PROCEDURE_Lex formal_part_opt
									type idf is access procedure;
									type idf is access protected procedure;
									
										-- rule formal_part_opt
										-- test_of
										-- formal_part
										
											-- rule formal_part
											-- test_of
											-- param_s
											
												-- rule param_s
												-- test_of
												-- param
												type idf is access protected procedure(x,y:mark);
												type idf is access protected procedure(y:mark);
												type idf is access protected procedure(y:mark.mark);
												type idf is access protected procedure(y:in mark.mark);
												type idf is access protected procedure(y:out mark.mark);
												type idf is access protected procedure(y:in out mark.mark:=0);
									
												-- rule param_s
												-- test_of
												-- param_s ';' param
												type idf is access protected procedure(x,y:mark;z,t:in out mark.mark:=0);
												
									-- rule access_type
									-- test_of
									-- ACCESS_Lex prot_opt FUNCTION_Lex formal_part_opt RETURN_Lex mark
									type idf is access protected function(x,y:mark;z,t:in out mark.mark:=0) return mark.mark;
									type idf is access function(x,y:mark;z,t:in out mark.mark:=0) return mark.mark;
												
									
									
									
								-- rule type_def
								-- test_of
								-- derived_type
								
									-- rule derived_type
									-- test_of
									-- NEW_Lex subtype_ind
									type idf is new name;
									
									-- rule derived_type
									-- test_of
									-- NEW_Lex subtype_ind
									type idf is new name with private;
									
									-- rule derived_type
									-- test_of
									-- NEW_Lex subtype_ind WITH_Lex record_def
									type idf is new name with record
										x,y:integer:=0;
										end record;
										
									-- rule derived_type
									-- test_of
									-- ABSTRACT_Lex NEW_Lex subtype_ind WITH_Lex PRIVATE_Lex
									type idf is abstract new name with private;
									
									-- rule derived_type
									-- test_of
									-- ABSTRACT_Lex NEW_Lex subtype_ind WITH_Lex record_def
									type idf is abstract new name with record
										x,y:integer:=0;
										end record;
										
									

								
								
								-- rule type_def
								-- test_of
								-- private_type
								type idf is private;
								type idf is tagged private;
								type idf is limited private;
								type idf is tagged limited private;
								
			
						
						-- rule decl
						-- test_of
						-- subtype_decl
						
							-- rule subtype_decl
							-- test_of
							-- SUBTYPE_Lex IDF_Lex IS_Lex subtype_ind ';'
							subtype idf is name;

						-- rule decl
						-- test_of
						-- subprog_decl
						
							-- rule subprog_decl
							-- test_of
							-- subprog_spec ';'
							
								-- rule subprog_spec
								-- test_of
								-- PROCEDURE_Lex compound_name formal_part_opt
								procedure compound.name(x,y:mark;z,t:in out mark.mark:=0);
								procedure compound.name;

								-- rule subprog_spec
								-- test_of
								-- FUNCTION_Lex designator formal_part_opt RETURN_Lex name
								function compound.name(x,y:mark;z,t:in out mark.mark:=0)return name;
								function compound.name return name;
								function "string"(x,y:mark;z,t:in out mark.mark:=0)return name;
								function "string" return name;
								
								-- rule subprog_spec
								-- test_of
								-- FUNCTION_Lex designator
								function "string";
								function compound.name;
								

							-- rule subprog_decl
							-- test_of
							-- generic_subp_inst ';'
							
								-- rule generic_subp_inst
								-- test_of
								-- subprog_spec IS_Lex generic_inst
								function compound.name(x,y:mark;z,t:in out mark.mark:=0)return name is new name2;
								
							

							-- rule subprog_decl
							-- test_of
							-- subprog_spec IS_Lex ABSTRACT_Lex ';'
							function compound.name(x,y:mark;z,t:in out mark.mark:=0)return name is abstract;

						-- rule decl
						-- test_of
						-- pkg_decl
						
						-- rule decl
						-- test_of
						-- task_decl
						
							-- rule task_decl
							-- test_of
							-- task_spec ';'
							
								-- rule task_spec
								-- test_of
								-- TASK_Lex simple_name task_def
								task name;
								
									-- rule task_def
									-- test_of
									-- IS_Lex entry_decl_s rep_spec_s task_private_opt END_Lex id_opt
								
										-- rule entry_decl_s
										-- test_of
										-- pragma_s
										task name is 
										pragma prgm;
										pragma prgm;
										end;
										
										task name is 
										pragma prgm;
										end name;
										
										-- rule entry_decl_s
										-- test_of
										-- entry_decl_s entry_decl pragma_s
										
											-- rule entry_decl
											-- test_of
											-- ENTRY_Lex IDF_Lex formal_part_opt ';'
											task name is 
											entry idf;
											pragma prm;
											entry idf(x,y:integer:=0;z:real);
											end name;
										

											-- rule entry_decl
											-- test_of
											-- ENTRY_Lex IDF_Lex '(' discrete_range ')' formal_part_opt ';'
											task name is 
											entry idf;
											pragma prm;
											entry idf(x,y:integer:=0;z:real);
											entry idf(1..2);
											entry idf(1..2)(x,y:integer:=0;z:real);
											
											end name;
										

										-- rule rep_spec_s
										-- test_of
										-- rep_spec_s rep_spec pragma_s
										
											-- rule rep_spec
											-- test_of
											-- attrib_def
											task name is 
											entry idf;
											pragma prm;
											entry idf(x,y:integer:=0;z:real);
											entry idf(1..2);
											entry idf(1..2)(x,y:integer:=0;z:real);
											for mark.mark use 10;
											end name;
										
											-- rule rep_spec
											-- test_of
											-- record_type_spec
											
												-- rule rep_spec
												-- test_of
												-- FOR_Lex mark USE_Lex RECORD_Lex align_opt comp_loc_s END_Lex RECORD_Lex ';'
												task name is 
												entry idf;
												pragma prm;
												entry idf(x,y:integer:=0;z:real);
												entry idf(1..2);
												entry idf(1..2)(x,y:integer:=0;z:real);
												for mark.mark use 10;
												for mark.mark use record
												end record;
												
												-- rule align_opt
												-- test_of
												-- AT_Lex MOD_Lex expression ';'
												for mark.mark use record at mod 10;
												end record;
												
												-- rule comp_loc_s
												-- test_of
												-- comp_loc_s mark AT_Lex expression RANGE_Lex range ';'
												for mark.mark use record
												mark.mark at 10 range 1..2;
												end record;
												
												for mark.mark use record
												 at mod 10;
												mark.mark at 10 range 1..2;
												end record;
												
												end name;
										
									
									
														
											
											-- rule rep_spec
											-- test_of
											-- address_spec
											task name is 
											entry idf;
											for mark use at 10;
											end name;	
											
									-- rule task_private_opt
									-- test of
									-- PRIVATE_Lex entry_decl_s rep_spec_s
									
									task name is 
									private 
									entry idf;
									pragma prm;
									entry idf(x,y:integer:=0;z:real);
									entry idf(1..2);
									entry idf(1..2)(x,y:integer:=0;z:real);
									for mark.mark use 10;
									for mark.mark use record
									end record;
									end name;	
										
										
										
										

								
								-- rule task_spec
								-- test_of
								-- TASK_Lex TYPE_Lex simple_name discrim_part_opt task_def
								task type simple_name (<>) is 
								entry idf;
								pragma prm;
								entry idf(x,y:integer:=0;z:real);
								end name;

						-- rule decl
						-- test_of
						-- prot_decl
						
							-- rule prot_decl
							-- test_of
							-- prot_spec ';'
							
								-- rule prot_spec
								-- test_of
								-- PROTECTED_Lex IDF_Lex prot_def
								
									-- rule prot_def
									-- test_of
									-- IS_Lex prot_op_decl_s prot_private_opt END_Lex id_opt
									
									protected idf is
									
									-- rule prot_op_decl
									-- test of
									-- entry_decl
									entry idf(x,y:integer:=0;z:real);
									
									-- rule prot_op_decl
									-- test of
									-- subprog_spec ';'
									procedure compound.name(x,y:mark;z,t:in out mark.mark:=0);
									
									-- rule prot_op_decl
									-- test of
									-- rep_spec
									for mark.mark use 10;
											
									-- rule prot_op_decl
									-- test of
									-- pragma
									pragma prgm;
									
									end;
									
									protected idf is
									entry idf(x,y:integer:=0;z:real);
									procedure compound.name(x,y:mark;z,t:in out mark.mark:=0);
									for mark.mark use 10;
									pragma prgm;
									end idf;
									
									-- rule prot_private_opt
									-- test of
									-- PRIVATE_Lex prot_elem_decl_s 
									protected idf is
									entry idf(x,y:integer:=0;z:real);
									private 
									procedure compound.name(x,y:mark;z,t:in out mark.mark:=0);
									for mark.mark use 10;
									pragma prgm;
									end idf;
									
									
								
								
								

								-- rule prot_spec
								-- test_of
								-- PROTECTED_Lex TYPE_Lex simple_name discrim_part_opt prot_def
								protected type simple_name (<>) is
								entry idf(x,y:integer:=0;z:real);
								procedure compound.name(x,y:mark;z,t:in out mark.mark:=0);
								for mark.mark use 10;
								pragma prgm;
								end idf;

							
						
						
						
						-- rule decl
						-- test_of
						-- exception_decl
						
							-- rule exception_decl
							-- test_of
							-- def_id_s ':' EXCEPTION_Lex ';'
							idf,idf2: exception;


						
						
						-- rule decl
						-- test_of
						-- rename_decl
						
							-- rule rename_decl
							-- test_of
							-- def_id_s ':' object_qualifier_opt subtype_ind renames ';'
							x,y:aliased name renames name2;
							
							-- rule rename_decl
							-- test_of
							-- def_id_s ':' EXCEPTION_Lex renames ';'
							x,y:exception renames name2;
							
							-- rule rename_decl
							-- test_of
							-- rename_unit
							
								-- rule rename_unit
								-- test_of
								-- PACKAGE_Lex compound_name renames ';'
								package compound.name renames name2;

								-- rule rename_unit
								-- test_of
								-- subprog_spec renames ';'
								procedure compound.name(x,y:mark;z,t:in out mark.mark:=0)renames name2;

								-- rule rename_unit
								-- test_of
								-- generic_formal_part PACKAGE_Lex compound_name renames ';'
								generic x,y:in mark;
								package compound.name renames name2;
								
								-- rule rename_unit
								-- test_of
								-- generic_formal_part subprog_spec renames ';'
								generic x,y:in mark;
								procedure compound.name(x,y:mark;z,t:in out mark.mark:=0)renames name2;

							

						
						
						-- rule decl
						-- test_of
						-- generic_decl
						
							-- rule generic_decl
							-- test_of
							-- generic_formal_part subprog_spec ';'
							generic x,y:in mark;
							procedure compound.name(x,y:mark;z,t:in out mark.mark:=0);

							-- rule generic_decl
							-- test_of
							-- generic_formal_part pkg_spec ';'
							generic x,y:in mark;
							package compound.name is
							end compound.name;

						-- rule decl
						-- test_of
						-- body_stub
						
							-- rule body_stub
							-- test_of
							-- TASK_Lex BODY_Lex simple_name IS_Lex SEPARATE_Lex ';'
							task body simple_name is separate;
							
							-- rule body_stub
							-- test_of
							-- PACKAGE_Lex BODY_Lex compound_name IS_Lex SEPARATE_Lex ';'
							package body compound.name is separate;
							
							-- rule body_stub
							-- test_of
							-- subprog_spec IS_Lex SEPARATE_Lex ';'
							procedure compound.name(x,y:mark;z,t:in out mark.mark:=0) is separate;
							
							-- rule body_stub
							-- test_of
							--  PROTECTED_Lex BODY_Lex simple_name IS_Lex SEPARATE_Lex ';'
							protected body simple_name is separate;
							
							
							

							
						
						
						
					
					-- rule decl_item
					-- test_of
					-- use_clause
					use name;
					
					-- rule decl_item
					-- test_of
					-- rep_spec
					for mark use 10;
					
					-- rule decl_item
					-- test_of
					-- pragma
					pragma moi;
					
					
					

				-- rule decl_item_s1
				-- test_of
				-- decl_item_s1 decl_item
			
			end compound.name;
	

	-- rule unit
	-- test_of
	-- generic_pkg_inst ';'
	
		-- rule generic_pkg_inst
		-- test_of
		-- PACKAGE_Lex compound_name IS_Lex generic_inst
		
			-- rule generic_inst
			-- test_of
			-- NEW_Lex name
			package compound.name is new name;
		
		
		
	
	

