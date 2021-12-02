-- $Log: test_array_2.ads,v $
-- Revision 1.3  2005/03/19 12:12:36  quicky2000
-- Update to:
-- _ declare unconstrained array type
-- _ variable whose type is previous delcared unconstrained array type
-- _ unconstrained array variables
--
-- Revision 1.2  2005/03/15 22:41:02  quicky2000
-- Update to add cvs log flag
--
package test_array_2 is
	-- Variable one dimensionnal array
	V_Remote_1: array(0..10) of Integer;
	-- Variable two dimensionnal array
	V_Remote_2: array(0..10,0..10) of Integer;

	-- type one dimensionnal array
	type T_Remote_1 is array(0..10) of integer;
	-- type one dimensionnal array
	type T_Remote_2 is array(0..10,0..10) of integer;
 	
	-- type one dimensionnal unconstrained array
	type T_Remote_3 is array(integer range <>) of integer;
 	
	-- type two dimensionnal unconstrained array
	type T_Remote_4 is array(integer range <>,integer range <>) of integer;
 	
	-- Variable whose type is one dimensionnal array
	V_Remote_3:T_Remote_1;
	-- Variable whose type is two dimensionnal array
	V_Remote_4:T_Remote_2;

	V_Remote_5:T_Remote_3(-10..10);
	V_Remote_6:T_Remote_4(-10..10,2..8);
	V_Remote_7:array(integer range <>)of integer:=(1=>0,2=>1,3=>2,4=>3);
	V_Remote_8:array(integer range <>,integer range <>)of integer:=(1=>(0=>0,1=>1,2=>2,3=>3),2=>(0=>0,1=>-1,2=>-2,3=>-3));

end test_array_2;
