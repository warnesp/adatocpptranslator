-- Description : test case to test the use of namespace
--
-- $Log: main.adb,v $
-- Revision 1.1  2005/03/19 12:24:50  quicky2000
-- initial import
--

with Ada.text_io;
use Ada.text_io;
with Ada.Integer_Text_IO;
use Ada.Integer_Text_IO;
with namespace1;
with namespace2;
with namespace3;use namespace3;
procedure test_namespace is
begin
	Put_line("X=");
	Put(namespace1.X);
	new_line(1);

	Put_line("X=");
	Put(namespace2.X);
	new_line(1);

	Put_line("X=");
	Put(X);
	new_line(1);
	
end test_namespace;
