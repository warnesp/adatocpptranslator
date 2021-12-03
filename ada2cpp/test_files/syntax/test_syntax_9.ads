-- $Log: test_syntax_9.ads,v $
-- Revision 1.2  2005/03/16 18:21:33  quicky2000
-- Update to add the cvs log flag
--

-- rule unit
-- test_of
-- pkg_body

	-- rule pkg_body
	-- test_of
	-- PACKAGE_Lex BODY_Lex compound_name IS_Lex decl_part body_opt END_Lex c_id_opt ';'
	package body name is
	end;
	
	package body name is
	end name;
	
	package body name is
		-- rule decl_part
		-- test_of
		-- decl_item_or_body_s1
		
			-- rule decl_item_or_body_s1
			-- test_of
			-- decl_item_or_body
			
				-- rule decl_item_or_body
				-- test_of
				-- body
				
					-- rule body
					-- test_of
					-- subprog_body
					
						-- rule subprog_body
						-- test_of
						-- subprog_spec IS_Lex decl_part block_body END_Lex id_opt ';'
						procedure compound.name(x,y:mark;z,t:in out mark.mark:=0)is
						I:integer:=0;
						begin
						I:=I+1;
						end;
						
						procedure compound.name(x,y:mark;z,t:in out mark.mark:=0)is
						I:integer:=0;
						begin
						I:=I+1;
						end name;
						
				

				-- rule decl_item_or_body
				-- test_of
				-- decl_item
				
					-- rule decl_item
					-- test_of
					-- decl
					idf,idf2: exception;
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
				
			
		
		

		-- rule body_opt
		-- test_of
		-- block_body
		
			-- rule block_body
			-- test_of
			-- BEGIN_Lex handled_stmt_s
			begin
			
				-- rule handled_stmt_s
				-- test_of
				-- statement_s except_handler_part_opt
				
				-- rule statement_s
				-- test_of
				-- statement
				I:=0; 
			
	end name;
	
	package body name is
	begin
	I:=0;
	
	-- rule except_handler_part_opt
	-- test_of
	-- except_handler_part
	
		-- rule except_handler_part_opt
		-- test_of
		-- except_handler_part
		
			-- rule except_handler_part
			-- test_of
			-- EXCEPTION_Lex exception_handler
			
				-- rule exception_handler
				-- test_of
				-- WHEN_Lex except_choice_s FLECHE_Lex statement_s
				
					-- rule except_choice_s
					-- test_of
					-- except_choice
					
						-- rule except_choice
						-- test_of
						-- name
						exception when name => I:=0;
						
	end name;
						
	package body name is
	begin
	I:=0;					
						-- rule except_choice
						-- test_of
						-- others
						exception when others => I:=0;
	end name;
						
					
	package body name is
	begin
	I:=0;			
				-- rule except_choice_s
				-- test_of
				-- except_choice_s '|' except_choice
				
				-- rule exception_handler
				-- test_of
				-- WHEN_Lex IDF_Lex ':' except_choice_s FLECHE_Lex statement_s
				exception when idf: name | name2 => I:=0;
	end name;
				
	package body name is
	begin
	I:=0;			
			-- rule except_handler_part
			-- test_of
			-- except_handler_part exception_handler
			exception when idf: name | name2 => I:=0;
			when others => I:=0;
	end;
	
	package body name is
	I:integer;
	begin
	-- rule handled_stmt_s
	-- test_of
	-- statement_s except_handler_part_opt

		-- rule statement_s
		-- test_of
		-- statement
		
			-- rule statement
			-- test_of
			-- unlabeled
			
				-- rule unlabeled
				-- test_of
				-- simple_stmt
				
					-- rule simple_stmt
					-- test_of
					-- null_stmt
					null;
					
					-- rule simple_stmt
					-- test_of
					-- assign_stmt
					
						-- rule assign_stmt
						-- test_of
						-- name AFFECT_Lex expression ';'
						name:=1+1;
						
					
					-- rule simple_stmt
					-- test_of
					-- exit_stmt
					
						-- rule exit_stmt
						-- test_of
						-- EXIT_Lex name_opt when_opt ';'
						exit;
						exit name;
						
							-- rule when_opt
							-- test_of
							-- WHEN_Lex condition
							
								-- rule condition
								-- test_of
								-- expression
								exit when 1;
								exit name when 1;
								 
						
						
					
					
					
					-- rule simple_stmt
					-- test_of
					-- return_stmt
					
						-- rule simple_stmt
						-- test_of
						-- RETURN_Lex ';'
						return;
						
						-- rule simple_stmt
						-- test_of
						-- RETURN_Lex expression ';'
						return 10;
						
						
					
					
					
					-- rule simple_stmt
					-- test_of
					-- goto_stmt
					
						-- rule goto_stmt
						-- test_of
						-- GOTO_Lex name ';'
						goto name;
						

					-- rule simple_stmt
					-- test_of
					-- procedure_call
					
						-- rule procedure_call
						-- test_of
						-- name ';'
						name;
					
					
					-- rule simple_stmt
					-- test_of
					-- delay_stmt
						
						-- rule delay_stmt
						-- test_of
						-- DELAY_Lex expression ';'
						delay 10;
						
						-- rule delay_stmt
						-- test_of
						-- DELAY_Lex UNTIL_Lex expression ';'
						delay until 4/5;
					
					
					-- rule simple_stmt
					-- test_of
					-- abort_stmt
					
						-- rule abort_stmt
						-- test_of
						-- ABORT_Lex name_s ';'
						abort name;
						abort name,name2;
						
					
					-- rule simple_stmt
					-- test_of
					-- raise_stmt
					
						-- rule raise_stmt
						-- test_of
						-- RAISE_Lex name_opt ';'
						raise;
						raise name;
					
					
					
					-- rule simple_stmt
					-- test_of
					-- code_stmt
					
						-- rule code_stmt
						-- test_of
						-- qualified ';'
						name'(1+2);
					
					
					
					-- rule simple_stmt
					-- test_of
					-- requeue_stmt
					
						-- rule requeue_stmt
						-- test_of
						-- REQUEUE_Lex name ';'
						requeue name;
						
						-- rule requeue_stmt
						-- test_of
						-- REQUEUE_Lex name WITH_Lex ABORT_Lex ';'
						requeue name with abort;
					
				
				-- rule unlabeled
				-- test_of
				-- compound_stmt
				
					-- rule compound_stmt
					-- test_of
					-- if_stmt
					
						-- rule if_stmt
						-- test_of
						-- IF_Lex cond_clause_s else_opt END_Lex IF_Lex ';'
						
							-- rule cond_clause_s
							-- test_of
							-- cond_clause
							
								-- rule cond_clause
								-- test_of
								-- condition THEN_Lex statement_s
								if 10>2 then
								i:=0;
								end if;
							
							

							-- rule cond_clause_s
							-- test_of
							-- cond_clause_s ELSIF_Lex cond_clause
							if 10>2 then
							i:=0;
							elsif 10<20 then
							i:=-1;
							end if;
							
							-- rule else_opt
							-- test_of
							-- ELSE_Lex statement_s
							if 10>2 then
							i:=0;
							elsif 10<20 then
							i:=-1;
							else
							i:=2;
							end if;
							
					-- rule compound_stmt
					-- test_of
					-- case_stmt
					
						-- rule case_stmt
						-- test_of
						-- CASE_Lex expression IS_Lex pragma_s alternative_s END_Lex CASE_Lex ';'
						
						-- rule alternative_s
						-- test_of
						-- 
						case 10>2 is
						end case;
					
						case 10>2 is
						pragma prgm;
						end case;
						
						-- rule alternative_s
						-- test_of
						-- alternative_s alternative
						
							-- rule alternative
							-- test_of
							-- WHEN_Lex choice_s FLECHE_Lex statement_s
							case 10>2 is
							pragma prgm;
							when name|name2 => i:=0;
							end case;
						
							

						
					
					
					
					-- rule compound_stmt
					-- test_of
					-- loop_stmt
					
						-- rule loop_stmt
						-- test_of
						-- label_opt iteration basic_loop id_opt ';'
						
							-- rule iteration
							-- test_of
							--
							
								-- rule basic_loop
								-- test_of
								-- LOOP_Lex statement_s END_Lex LOOP_Lex
								loop
								i:=i+1;
								end loop;
							
							-- rule iteration
							-- test_of
							-- WHILE_Lex condition
							
							while i<10
							loop
							i:=i+1;
							end loop;
							
							-- rule iteration
							-- test_of
							-- iter_part reverse_opt discrete_range
							
								-- rule iter_part
								-- test_of
								-- FOR_Lex IDF_Lex IN_Lex
								for idf in 1..2
								loop 
								j:=j+1;
								end loop;
								
								-- rule reverse_opt
								-- test_of
								-- REVERSE_lex
								for idf in reverse 1..2
								loop 
								j:=j+1;
								end loop;
								
							
							-- rule label_opt
							-- test_of
							-- IDF_Lex ':'
							label:
							for idf in reverse 1..2
							loop 
							j:=j+1;
							end loop label;
						
						
						

					
					
					-- rule compound_stmt
					-- test_of
					-- block
					
						-- rule block
						-- test_of
						-- label_opt block_decl block_body END_Lex id_opt ';'
						--label:
						begin
						i:=0;
						end;
						
						label:
						begin
						i:=0;
						end;
						
						label:
						begin
						i:=0;
						end label;
						
						label:
						declare
						i:integer;
						begin
						i:=0;
						end label;
						
					
					
					-- rule compound_stmt
					-- test_of
					-- accept_stmt
					
						-- rule accept_stmt
						-- test_of
						-- accept_hdr ';'
						
							-- rule accept_hdr
							-- test_of
							-- ACCEPT_Lex entry_name formal_part_opt
							
								-- rule entry_name
								-- test_of
								-- simple_name
								accept simple_name;
								
								-- rule entry_name
								-- test_of
								-- entry_name '(' expression ')'
								accept simple_name(10);
								accept simple_name(10)(20);
								
								-- rule formal_part_opt
								-- test_of
								-- formal_part
								accept simple_name(10)(20)(x,y:integer:=0);
								
						-- rule accept_stmt
						-- test_of
						-- accept_hdr DO_Lex handled_stmt_s END_Lex id_opt ';'
						accept simple_name(10)(20)(x,y:integer:=0)
						do
						i:=0;
						end;
								
					-- rule compound_stmt
					-- test_of
					-- select_stmt
					
						-- rule select_stmt
						-- test_of
						-- select_wait
						
							-- rule select_wait
							-- test_of
							-- SELECT_Lex guarded_select_alt or_select else_opt END_Lex SELECT_Lex ';'
							
								-- rule guarded_select_alt
								-- test_of
								-- select_alt
								
									-- rule select_alt
									-- test_of
									-- accept_stmt stmts_opt
									select
									accept simple_name(10);
									end select;
									
									select
									accept simple_name(10);
									i:=0;
									end select;

									-- rule select_alt
									-- test_of
									-- delay_stmt stmts_opt
									select
									delay 10;
									end select;
									
									select
									delay 10;
									i:=0;
									end select;


									-- rule select_alt
									-- test_of
									-- TERMINATE_Lex ';'
									select
									terminate;
									end select;
									
								
								
								-- rule guarded_select_alt
								-- test_of
								-- WHEN_Lex condition FLECHE_Lex select_alt
								select
								when 10 => delay 10;
									   i:=0;
								end select;
								
							-- rule or_select
							-- test_of
							-- or_select OR_Lex guarded_select_alt
							select
							when 10 => delay 10;
								   i:=0;
							or
							when 1 => delay 10;
								   i:=0;
							
							
							end select;
								
							-- rule else_opt
							-- test_of
							-- ELSE_Lex statement_s
							select
							when 10 => delay 10;
								   i:=0;
							or
							when 1 => delay 10;
								   i:=0;
							else
							i:=-1;
							
							end select;	
							


						-- rule select_stmt
						-- test_of
						-- async_select
						
							-- rule async_select
							-- test_of
							-- SELECT_Lex delay_or_entry_alt THEN_Lex ABORT_Lex statement_s	END_Lex SELECT_Lex ';'
							
								-- rule delay_or_entry_alt
								-- test_of
								-- delay_stmt stmts_opt
								select delay 10;
								then abort i:=0;
								end select;
								
								-- rule delay_or_entry_alt
								-- test_of
								-- entry_call stmts_opt
								
									-- rule entry_call
									-- test_of
									-- procedure_call
									select name;
									then abort i:=i+1;
									end select;
								
							

						

						-- rule select_stmt
						-- test_of
						-- timed_entry_call
						
							-- rule timed_entry_call
							-- test_of
							-- SELECT_Lex entry_call stmts_opt OR_Lex delay_stmt stmts_opt END_Lex SELECT_Lex ';'
							select
							name;
							or delay 10;
							end select;
							
							select
							name;
							i:=0;
							or delay 10;
							end select;
							
							select
							name;
							or delay 10;
							i:=0;
							end select;
							
							select
							name;
							i:=0;
							or delay 10;
							i:=0;
							end select;
							
						
						

						-- rule select_stmt
						-- test_of
						-- cond_entry_call
						
							-- rule cond_entry_call
							-- test_of
							-- SELECT_Lex entry_call stmts_opt ELSE_Lex statement_s END_Lex SELECT_Lex ';'
							select
							name;
							else
							i:=0;
							end select;
							
							select
							name;
							i:=1;
							else
							i:=0;
							end select;
							
					
				
				
				
				-- rule unlabeled
				-- test_of
				-- pragma
				pragma prgm;
				
			
			
			
			-- rule statement
			-- test_of
			-- label statement
			<<label>>
			abort name;
	end name;		
	
		
		
	
		
	
	
	
