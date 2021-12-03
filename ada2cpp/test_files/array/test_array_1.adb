-- $Log: test_array_1.adb,v $
-- Revision 1.4  2005/03/19 12:11:01  quicky2000
-- Update to use unconstrained array type variables declared in package specs
--
-- Revision 1.3  2005/03/15 22:34:26  quicky2000
-- Update to add a function which use a local parameter whose type is an array type
--
-- Revision 1.2  2005/03/04 18:57:43  quicky2000
-- Update to add new cases:
-- use of arrays stored in a structured type, these arrays are variables declared as arrays, arrays with two dimensions, arrays of arrays
--
package body test_array_1 is
	procedure main is
	begin	
		-- operations on "local variables "
		V_local_1(0):=16#A_2#E2;
		V_local_2(0,0):=0;
		V_local_3(0):=0;
		V_local_4(0,0):=0;
		V_local_5(0)(0):=0;
		V_Local_6:=V_Local_3'access;
		V_local_6(0):=0;
		
		V_Local_7(0):=0;
		V_Local_8(0):=0;
		V_Local_8(0):=1+2*(test_array_1.V_Local_7(0));

		v_local_9.m1(0):=0;
		v_local_9.m2(0,0):=0;
		v_local_9.m3(0)(0):=0;
		v_local_9.m6:=V_Local_3'access;
		v_local_9.m6(0):=0;
		test_array_1.v_local_9.m6(0):=0;
		v_local_9.m7(0):=0;
		v_local_9.m8(0):=0;

		V_Local_10(3,5):=13;
		V_Local_11(2):=-3;

		-- operations on remote variables
		test_array_2.V_remote_1(0):=0;
		test_array_2.V_remote_2(0,0):=0;
		test_array_2.V_remote_3(0):=0;
		test_array_2.V_remote_4(0,0):=0;
		test_array_2.V_remote_5(-4):=7;
		test_array_2.V_remote_6(-2,5):=7;
		test_array_2.V_remote_7(1):=0;
		test_array_2.V_remote_8(1,2):=7;

	end main;

	procedure test(parameter: out T_local_2)is
	begin
		parameter(0,2):=12;
	end test;

	function test2(parameter: in T_local_2)return Integer is
	begin
		return parameter(0,2);
	end test2;

end test_array_1;
