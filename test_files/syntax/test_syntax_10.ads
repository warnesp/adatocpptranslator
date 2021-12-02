-- $Log: test_syntax_10.ads,v $
-- Revision 1.2  2005/03/16 18:21:33  quicky2000
-- Update to add the cvs log flag
--

-- rule unit
-- test_of
-- subunit

	-- rule subunit
	-- test_of
	-- SEPARATE_Lex '(' compound_name ')' subunit_body
	
		-- rule subunit_body
		-- test_of
		-- subprog_body
		
		-- rule subunit_body
		-- test_of
		-- pkg_body
		
		-- rule subunit_body
		-- test_of
		-- task_body
		
			-- rule task_body
			-- test_of
			-- TASK_Lex BODY_Lex simple_name IS_Lex decl_part block_body END_Lex id_opt ';'
			separate (compound.name)
			task body name is
			i:integer;
			begin
			i:=i+1;
			end name;
		
		
		-- rule subunit_body
		-- test_of
		-- prot_body
		
			-- rule prot_body
			-- test_of
			-- PROTECTED_Lex BODY_Lex simple_name IS_Lex prot_op_body_s END_Lex id_opt ';'
			
				-- rule prot_op_body_s
				-- test_of
				-- pragma_s
				separate (compound.name)
				protected body name is
				pragma prgm;
				end name;
				
				separate (compound.name)
				protected body name is
				pragma prgm;
				end;
				
			
				-- rule prot_op_body_s
				-- test_of
				-- prot_op_body_s prot_op_body pragma_s
				
					-- rule prot_op_body
					-- test_of
					-- entry_body
					
						-- rule entry_body
						-- test_of
						-- ENTRY_Lex IDF_Lex formal_part_opt WHEN_Lex condition entry_body_part
						
							-- rule entry_body_part
							-- test_of
							-- ';'
							separate (compound.name)
							protected body name is
							pragma prgm;
							entry idf (x,y:integer:=0) when 10;
							end;
					
							-- rule entry_body_part
							-- test_of
							-- IS_Lex decl_part block_body END_Lex id_opt ';'
							separate (compound.name)
							protected body name is
							pragma prgm;
							entry idf (x,y:integer:=0) when 10 is
							j:integer;
							begin
							j:=j+1;
							end;
							end;
					
						
						
						-- rule entry_body
						-- test_of
						-- ENTRY_Lex IDF_Lex '(' iter_part discrete_range ')' formal_part_opt WHEN_Lex condition entry_body_part
						separate (compound.name)
							protected body name is
							pragma prgm;
							entry idf (for idf in 1..2)(x,y:integer:=0) when 10;
							end;
							
						

					
					
					-- rule prot_op_body
					-- test_of
					-- subprog_body
					separate (compound.name)
					protected body name is
					procedure name(x,y:integer;z:real:=0.0)is
					i:integer;
					begin
					i:=i+1;
					end;
					end;
						
					-- rule prot_op_body
					-- test_of
					-- subprog_spec ';'
					separate (compound.name)
					protected body name is
					procedure name(x,y:integer;z:real:=0.0);
					end;
					
				
				
		
		
		
	
	
	
	

