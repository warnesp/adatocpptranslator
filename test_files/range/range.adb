-- $Log: range.adb,v $
-- Revision 1.2  2005/03/04 18:43:40  quicky2000
-- Initial import
--
-- Revision 1.1.2.1  2005/03/04 18:35:23  quicky2000
-- Initial import
--
with Ada.text_io;
use Ada.Text_Io;

package body my_range is
	
	procedure main is
		l_range:range1;
 	    A:integer:=3;
	begin
		A:=A+1;
		if A in 1..2
		then put_line("in");
		else Put_line("out");
		end if;
		
		if A not in 1..12
		then put_line("out");
		else Put_line("in");
		end if;

	end Main;
end my_range;
