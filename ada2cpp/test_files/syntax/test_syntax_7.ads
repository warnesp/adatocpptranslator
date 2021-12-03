-- $Log: test_syntax_7.ads,v $
-- Revision 1.2  2005/03/16 18:23:21  quicky2000
-- Update to add the cvs log flag
--

-- rule compilation
-- test of
-- compilation comp_unit
pragma moi;

	-- rule comp_unit
	-- test of
	-- context_spec private_opt unit pragma_s
		
		-- rule context_spec
		-- test of
		-- context_spec with_clause use_clause_opt
	
			-- rule with_clause
			-- test of
			-- WITH_Lex c_name_list ';'
			
				-- rule c_name_list
				-- test of
				-- compound_name

					-- rule compound_name
					-- test of
					-- simple_name
					with compound_name;

					-- rule compound_name
					-- test of
					-- compound_name '.' simple_name
					with compound_name.simple_name;

				-- rule c_name_list
				-- test of
				-- c_name_list ',' compound_name
				with compound_name.simple_name,name;
				
				-- rule use_clause_opt
				-- test of
				-- compound_name use_clause_opt use_clause
				
					-- rule use_clause
					-- test of
					-- USE_Lex name_s ';'
						
						-- rule name_s
						-- test of
						-- name ';'
						use name;
						
						-- rule name_s
						-- test of
						-- name_s ',' name
						use name,name2;
					
					-- rule use_clause
					-- test of
					-- USE_Lex TYPE_Lex name_s ';'
					use type name;
				


		-- rule context_spec
		-- test of
		-- context_spec pragma
		with compound_name.simple_name,name;
		pragma name;
		
	-- rule comp_unit
	-- test of
	-- private_opt unit pragma_s
	

package moi is
end moi;


-- rule private_opt
-- test of
-- PRIVATE_Lex
private
package moi is
end moi;

pragma moi;

