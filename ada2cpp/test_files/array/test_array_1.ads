-- $Log: test_array_1.ads,v $
-- Revision 1.5  2005/03/19 12:12:36  quicky2000
-- Update to:
-- _ declare unconstrained array type
-- _ variable whose type is previous delcared unconstrained array type
-- _ unconstrained array variables
--
-- Revision 1.4  2005/03/15 22:36:56  quicky2000
-- Update to add cvs log flag
--
with test_array_2;

package test_array_1 is
	-- Variable one dimensionnal array
	V_local_1: array(0..10) of Integer;
	-- Variable two dimensionnal array
	V_Local_2: array(0..10,0..10) of Integer;

	-- type one dimensionnal array
	type T_Local_1 is array(0..10) of integer;
	-- type one dimensionnal array
	type T_Local_2 is array(0..10,0..10) of integer;
 	
	-- Variable whose type is one dimensionnal array
	V_Local_3:aliased T_local_1;
	-- Variable whose type is two dimensionnal array
	V_Local_4:T_local_2;

	-- Type one dimensionnal array of one dimensionnal array
	type T_Local_3 is array(0..10)of t_Local_1;

	-- Variable whose type is one dimensionnal array of one dimensionnal array
	V_Local_5: T_local_3;

	-- type access on array type
	type T_Access_Array is access all t_local_1;
	V_Local_6:T_Access_Array;
	
	-- type derived of array type
	type T_Derived_Array is new t_local_1;
	V_Local_7:T_Derived_Array;
	
	-- subtype of array type
	subtype T_Subtype_Array is t_local_1;
	V_Local_8:T_Subtype_Array;
	
	type t_local_8 is record
		m1:t_local_1;
		m2:t_local_2;
		m3:t_local_3;
		m6:T_Access_Array;
		m7:T_Derived_Array;
		m8:T_Subtype_Array;
	end record;

	V_local_9:t_local_8;

	-- unconstrained array type
	type T_Local_unconstrained is array(integer range <>,integer range <>)of integer;
	type T_Local_unconstrained_2 is array(integer range <>)of integer;

	V_Local_10:t_Local_unconstrained(1..10,1..10);
	V_Local_11:t_Local_unconstrained_2(1..10);

	procedure main;

	procedure test(parameter: out T_local_2);
	function test2(parameter: in T_local_2)return Integer;

end test_array_1;


