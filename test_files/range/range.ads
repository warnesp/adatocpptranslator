-- $Log: range.ads,v $
-- Revision 1.2  2005/03/04 18:43:40  quicky2000
-- Initial import
--
-- Revision 1.1.2.1  2005/03/04 18:35:23  quicky2000
-- Initial import
--
package my_range is
	type range1 is range 1..10;

	procedure main;
end my_range;

with my_range;
use my_range;
procedure test_my_range is
begin
	main;
end test_my_range;
