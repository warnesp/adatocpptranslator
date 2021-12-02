-- $Log: test_object_decl.ads,v $
-- Revision 1.4  2005/03/19 12:28:50  quicky2000
-- Update to add deckaration of pointers on subprograms with an empty parameter list
--
-- Revision 1.3  2005/03/19 10:32:13  quicky2000
-- Update to add Ada type declaration which are pointer on function and procedure
--
-- Revision 1.2  2005/03/15 22:50:56  quicky2000
-- Update to add the cvs log flag
--
package test_object_decl is
	
-- Types declarations
v_domain:constant Integer:=2;
type t_enumere is (nom1,Nom2,Nom3);
type t_inter is range -10..10;
type t_modulo is mod v_domain;
type t_float is digits 2;
type t_fixed is delta 0.1 range -2.1..2.1;
type t_array_int is array (0..10,0..20)of Integer;

type t_record is record
	x:Integer;
	Y:integer;
	Z:integer;
end record;

type t_access_int is access Integer;
type Access_Func is access function(param1 : in Integer;
                                      Param2 : in Integer) return Integer;

type Access_Proc is access procedure(param1 : in Integer;
                                      Param2 : in Integer);

type Access_Func2 is access function return Integer;

type Access_Proc2 is access procedure;

type T_coord is new T_inter;

end Test_Object_Decl;

