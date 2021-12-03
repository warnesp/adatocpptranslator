-- $Log: main.adb,v $
-- Revision 1.2  2005/03/26 17:43:59  quicky2000
-- Update to add a case instruction
--
-- Revision 1.1  2005/03/04 18:46:39  quicky2000
-- Initial import
--
with Ada.text_io;
use Ada.text_io;
with Ada.Integer_Text_IO;
use Ada.Integer_Text_IO;
with Statements;
use Statements;

procedure main is
begin
	I:=I+1;
	if I=1
	then Put_line("equal");
	else Put_line("not equal");
	end if;

	if I=1
	then Put_line("i=1");
	elsif I=2
	then put_line("i=2");
	elsif I=3
	then put_line("i=3");
	else Put_Line("i=4");
	end if;

	I:=0;
	while i<10
	loop
		Put(I);
		New_Line(1);
		I:=I+1;
	end loop;
	
	Put(I);
	New_Line(2);
		
	I:=0;
	for I in 1..5
	loop
		Put(I);
		New_Line(1);
	end loop;

	Put(I);
	New_Line(2);
	
	I:=12;

	for I in reverse 1..5
	loop
		Put(I);
		New_Line(1);
	end loop;

	Put(I);
	New_Line(2);
	
	for I in l_Range
	loop
		Put(I);
		New_Line(1);
	end loop;

	Put(I);
	New_Line(1);
	
	case I is
		when 0=>Put_line("I=0");
		when 1=>Put_Line("I=1");
		when 2|4|8=>Put_line("I mod 2 = 0");
		when others=>Put_Line("others");
	end case;

end main;