-- $Log: test_syntax_5.ads,v $
-- Revision 1.2  2005/03/16 18:23:20  quicky2000
-- Update to add the cvs log flag
--

-- rule pragma
-- test of :
-- PRAGMA_Lex simple_name '(' pragma_arg_s ')' ';'

-- one argument 
pragma simple_name ( pragma_arg_s ) ;

-- more than one argument
pragma simple_name ( pragma_arg_s, pragma_arg_s2) ;

-- rule pragma_arg
-- test of :
-- expression
	-- rule expression
	-- test of : 
	-- relation
	
		-- rule relation
		-- test of : 
		-- simple_expression
		
			-- rule simple_expression
			-- test of : 
			-- '+' term
			
				-- rule term
				-- test of : 
				-- factor
				
					-- rule factor
					-- test of : 
					-- primary
					
						-- rule primary
						-- test of : 
						-- literal
						
							-- rule literal
							-- test of : 
							-- CONSTREEL_Lex
							pragma simple_name2 (+ 10.2) ;

							-- rule literal
							-- test of : 
							-- CONSTENT_Lex
							pragma simple_name (+ 10) ;
							
							-- rule literal
							-- test of : 
							-- used_char
							pragma simple_name (+ 'a') ;
							
							-- rule literal
							-- test of : 
							-- NULL_Lex
							pragma simple_name (+ null) ;
							
						-- rule primary
						-- test of : 
						-- name
						
							-- rule name
							-- test of : 
							-- indexed_comp
							
								-- rule indexed_comp
								-- test of : 
								-- name '(' value_s ')'
								
									-- rule value_s
									-- test of : 
									-- value
									
										-- rule value
										-- test of : 
										-- comp_assoc
										
											-- comp_assoc
											-- test of : 
											-- choice_s FLECHE_Lex expression
											
												
												-- comp_assoc
												-- test of : 
												-- choice
												pragma simple_name (+ name(others => 2)) ;
												
												-- choice_s
												-- test of : 
												-- choice_s '|' choice
												pragma simple_name (+ name(1 | others => 2)) ;
												

							
										-- rule value
										-- test of : 
										-- discrete_with_range
										
											-- rule discrete_with_range
											-- test of : 
											-- name range_constraint
											
												-- rule range_constraint
												-- test of : 
												-- RANGE_Lex range
												
													-- rule range
													-- test of : 
													-- simple_expression INTER_Lex simple_expression
													pragma simple_name (+ name(name range 1..2)) ;
												
													-- rule range
													-- test of : 
													-- name ''' RANGE_Lex
													pragma simple_name (+ name(name range name'range)) ;
												
													-- rule range
													-- test of : 
													-- name ''' RANGE_Lex '(' expression ')'
													pragma simple_name (+ name(name range name'range(1))) ;
												
											
											-- rule discrete_with_range
											-- test of : 
											-- name
											pragma simple_name (+ name(a_range)) ;
												
									
									-- rule value_s
									-- test of : 
									-- value_s ',' value
									pragma simple_name (+ name(a_range, a_range)) ;
											
								
							-- rule name
							-- test of : 
							-- selected_comp
							
								-- rule selected_comp
								-- test of : 
								-- name '.' simple_name
								pragma simple_name (+ name.simple_name) ;
									
								-- rule selected_comp
								-- test of : 
								-- name '.' used_char
								pragma simple_name (+ name.'a') ;
								
								-- rule selected_comp
								-- test of : 
								-- name '.' operator_symbol
								pragma simple_name (+ name."string") ;
								
								-- rule selected_comp
								-- test of : 
								-- name '.' ALL_Lex
								pragma simple_name (+ name.all) ;
								
							-- rule name
							-- test of : 
							-- attribute
							
								-- rule attribute
								-- test of : 
								-- name ''' attribute_id

									-- rule attribute_id
									-- test of : 
									-- IDF_Lex
									pragma simple_name (+ name'idf) ;
								
									-- rule attribute_id
									-- test of : 
									-- DIGITS_Lex
									pragma simple_name (+ name'digits) ;
								
									-- rule attribute_id
									-- test of : 
									-- DELTA_Lex
									pragma simple_name (+ name'delta) ;
								
									-- rule attribute_id
									-- test of : 
									-- ACCESS_Lex
									pragma simple_name (+ name'access) ;
								


							-- rule name
							-- test of : 
							-- operator_symbol
							pragma simple_name (+"string") ;
								
						
						-- rule primary
						-- test of : 
						-- allocator
						
							-- rule allocator
							-- test of : 
							-- NEW_Lex name
							pragma simple_name (+new idf) ;
							
							-- rule allocator
							-- test of : 
							-- NEW_Lex qualified
							
								-- rule qualified
								-- test of : 
								-- name ''' parenthesized_primary 
								
									-- rule parenthesized_primary
									-- test of : 
									-- aggregate
									
										-- rule aggregate
										-- test of : 
										-- '(' comp_assoc ')'
										pragma simple_name (+new name'(others => 2)) ;
						
										-- rule aggregate
										-- test of : 
										-- '(' value_s_2 ')'
										
											-- rule value_s_2
											-- test of : 
											-- value ',' value
											pragma simple_name (+new name'(others => 2,others => 2)) ;
						
											-- rule value_s_2
											-- test of : 
											-- value_s_2 ',' value
											pragma simple_name (+new name'(others => 2,others => 2,others => 2)) ;
						
											
										
										-- rule aggregate
										-- test of : 
										-- '(' expression WITH_Lex value_s ')'
										pragma simple_name (+new name'(2 with name,name)) ;
						
										-- rule aggregate
										-- test of : 
										-- '(' expression WITH_Lex NULL_Lex RECORD_Lex ')'
										pragma simple_name (+new name'(2 with null record)) ;
						
										-- rule aggregate
										-- test of : 
										-- '(' NULL_Lex RECORD_Lex ')'
										pragma simple_name (+new name'(null record)) ;
						
										
									
									-- rule parenthesized_primary
									-- test of : 
									-- '(' expression ')'
									pragma simple_name (+new name'(2)) ;
						
						
						-- rule primary
						-- test of : 
						-- qualified
						pragma simple_name (+name'(2));
						
						-- rule primary
						-- test of : 
						-- parenthesized_primary
						pragma simple_name (+(2));
						
						
					-- rule factor
					-- test of : 
					-- NOT_Lex primary
					pragma simple_name (+not 2);
						
					-- rule factor
					-- test of : 
					-- ABS_Lex primary
					pragma simple_name (+abs 2);
					
					-- rule factor
					-- test of : 
					-- primary POWER_Lex primary
					pragma simple_name (+2 ** 10);
						
				-- rule term
				-- test of : 
				-- term '*' factor
				pragma simple_name (+ 10 * 10.2) ;
		
				-- rule term
				-- test of : 
				-- term '/' factor
				pragma simple_name (+ 10 / 10.2) ;
		
				-- rule term
				-- test of : 
				-- term MOD_Lex factor
				pragma simple_name (+ 10 mod 10.2) ;
		
				-- rule term
				-- test of : 
				-- term REM_Lex factor
				pragma simple_name (+ 10 rem 10.2) ;
			
			-- rule simple_expression
			-- test of : 
			-- '-' term
			pragma simple_name (- 10.2) ;
		
			-- rule simple_expression
			-- test of : 
			-- term
			pragma simple_name ( 10.2) ;
		 
			-- rule simple_expression
			-- test of : 
			-- simple_expression '+' term
			pragma simple_name (10.2 + 10.2) ;
		
			-- rule simple_expression
			-- test of : 
			-- simple_expression '-' term
			pragma simple_name (10.2 - 10.2) ;
		
			-- rule simple_expression
			-- test of : 
			-- simple_expression '&' term
			pragma simple_name (10.2 & 10.2) ;
		
	
		-- rule relation
		-- test of : 
		-- simple_expression '=' simple_expression
		pragma simple_name (10.2 = 10.2) ;
		
		-- rule relation
		-- test of : 
		-- simple_expression DIFF_Lex simple_expression
		pragma simple_name (10.2 /= 10.2) ;
		
		-- rule relation
		-- test of : 
		-- simple_expression '<' simple_expression
		pragma simple_name (10.2 < 10.2) ;
		
		-- rule relation
		-- test of : 
		-- simple_expression INFEGAL_Lex simple_expression
		pragma simple_name (10.2 <= 10.2) ;
		
		-- rule relation
		-- test of : 
		-- simple_expression '>' simple_expression
		pragma simple_name (10.2 > 10.2) ;
		
		-- rule relation
		-- test of : 
		-- simple_expression SUPEGAL_Lex simple_expression
		pragma simple_name (10.2 >= 10.2) ;
		
		-- rule relation
		-- test of : 
		-- simple_expression IN_Lex range
		pragma simple_name (10.2 in 1..2) ;
		
		-- rule relation
		-- test of : 
		-- simple_expression NOT_Lex IN_Lex range
		pragma simple_name (10.2 not in 1..2) ;
		
		-- rule relation
		-- test of : 
		-- simple_expression IN_Lex name
		pragma simple_name (10.2 in name) ;
		
		-- rule relation
		-- test of : 
		-- simple_expression NOT_Lex IN_Lex name
		pragma simple_name (10.2 not in name) ;
		
	-- rule expression
	-- test of : 
	-- expression AND_Lex relation
	pragma simple_name (10.2 and 10.2) ;
		
	-- rule expression
	-- test of : 
	-- expression OR_Lex relation
	pragma simple_name (10.2 or 10.2) ;
	
	-- rule expression
	-- test of : 
	-- expression XOR_Lex relation
	pragma simple_name (10.2 xor 10.2) ;
	
	-- rule expression
	-- test of : 
	-- expression AND_Lex THEN_Lex relation
	pragma simple_name (10.2 and then 10.2) ;
	
	-- rule expression
	-- test of : 
	-- expression OR_Lex ELSE_Lex relation
	pragma simple_name (10.2 or else 10.2) ;
		
