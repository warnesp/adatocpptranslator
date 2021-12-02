-- $Log: test_syntax_11.ads,v $
-- Revision 1.2  2005/03/16 18:23:20  quicky2000
-- Update to add the cvs log flag
--

-- rule unit
-- test_of
-- generic_decl
generic x,y:in mark;
package compound.name is
end compound.name;

-- rule unit
-- test_of
-- rename_unit
package compound.name renames name2;

