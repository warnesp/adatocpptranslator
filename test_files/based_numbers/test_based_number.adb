-- Description : procedure which affect based values to variables
--
-- $Log: test_based_number.adb,v $
-- Revision 1.1  2005/03/19 12:19:40  quicky2000
-- initial import
--
package body based_number is

	procedure main is
	begin
		-- Base 2 
		----------
		l_VarInt := 2#01# ;
		l_VarInt := 2#10#E+0 ;

		-- not allowed b some compilers
		--del l_VarFloat := 2#11#E-0 ;
		----------------------
		l_VarInt := 2#01#E2 ;
		l_VarInt := 2#10#E+2 ;
		
		-- not allowed b some compilers
		--del l_VarInt := 2#11#E-2 ;
		----------------------	
		l_VarFloat := 2#0.1#E-3 ;
		l_VarFloat := 2#1.0#E+3 ;
		l_VarFloat := 2#1.1#E3 ;
		----------------------
		l_VarFloat := 2#0.1# ;
		l_VarFloat := 2#1.0#E+0 ;
		l_VarFloat := 2#1.1#E0 ;
		----------------------	
		l_VarFloat := 2#0.01#E-3 ;
		l_VarFloat := 2#0.10#E+3 ;
		l_VarFloat := 2#0.11#E3 ;
		----------------------	
		l_VarFloat := 2#0.01# ;
		l_VarFloat := 2#0.10#E+0 ;
		l_VarFloat := 2#0.11#E0 ;
		
		-- Base 8 
		----------
		l_VarInt := 8#21# ;
		l_VarInt := 8#21#E+0 ;
		
		-- not allowed b some compilers
		--del l_VarInt := 8#21#E-0 ;
		----------------------	
		l_VarInt := 8#21#E2 ;
		l_VarInt := 8#21#E+2 ;
		
		-- not allowed b some compilers
		--del l_VarInt := 8#21#E-2 ;
		----------------------	
		l_VarFloat := 8#2.1#E-3 ;
		l_VarFloat := 8#2.1#E+3 ;
		l_VarFloat := 8#2.1#E3 ;
		----------------------	
		l_VarFloat := 8#2.1# ;
		l_VarFloat := 8#2.1#E+0 ;
		l_VarFloat := 8#2.1#E0 ;
		----------------------	
		l_VarFloat := 8#0.21#E-3 ;
		l_VarFloat := 8#0.21#E+3 ;
		l_VarFloat := 8#0.21#E3 ;
		----------------------	
		l_VarFloat := 8#0.21# ;
		l_VarFloat := 8#0.21#E+0 ;
		l_VarFloat := 8#0.21#E0 ;
		
		-- Base 16 
		----------
		l_VarInt := 16#A1# ;
		l_VarInt := 1_6#A1#E+0 ;
		
		-- not allowed b some compilers
		--del l_VarInt := 1_6#A1#E-0 ;
		----------------------	
		l_VarInt := 16#2A#E2 ;
		l_VarInt := 1_6#2A#E+2 ;
		
		-- not allowed b some compilers
		--del l_VarInt := 1_6#2A#E-2 ;
		----------------------	
		l_VarFloat := 16#A.C#E-3 ;
		l_VarFloat := 1_6#A.C#E+3 ;
		l_VarFloat := 1_6#A.C#E3 ;
		----------------------	
		l_VarFloat := 16#2.A# ;
		l_VarFloat := 1_6#2.A#E+0 ;
		l_VarFloat := 1_6#2.A#E0 ;
		----------------------	
		l_VarFloat := 16#0.A1#E-3 ;
		l_VarFloat := 1_6#0.A1#E+3 ;
		l_VarFloat := 1_6#0.A1#E3 ;
		----------------------	
		l_VarFloat := 16#0.AC# ;
		l_VarFloat := 1_6#0.AC#E+0 ;
		l_VarFloat := 1_6#0.AC#E0 ;
	
		-- Base 7 
		----------
		l_VarInt := 7#42# ;
		l_VarInt := 7#42#E+0 ;
		
		-- not allowed b some compilers
		--del l_VarInt := 7#42#E-1 ;
		----------------------
		l_VarInt := 7#24#E2 ;
		l_VarInt := 7#24#E+2 ;
		
		
		-- not allowed b some compilers
		--del l_VarInt := 7#24#E-2 ;
		----------------------	
		l_VarFloat := 7#4.2#E-3 ;
		l_VarFloat := 7#4.2#E+3 ;
		l_VarFloat := 7#4.2#E3 ;
		----------------------
		l_VarFloat := 7#2.4# ;
		l_VarFloat := 7#2.4#E+0 ;
		l_VarFloat := 7#2.4#E0 ;
		----------------------	
		l_VarFloat := 7#0.42#E-3 ;
		l_VarFloat := 7#0.42#E+3 ;
		l_VarFloat := 7#0.42#E3 ;
		----------------------
		l_VarFloat := 7#0.24# ;
		l_VarFloat := 7#0.24#E+0 ;
		l_VarFloat := 7#0.24#E0 ;
	end main;
end based_number;