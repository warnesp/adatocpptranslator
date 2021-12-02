/*****************************************************************************
 *                      Ada_to_C_Cpp_Translator
 *****************************************************************************
 * Adatoccpptranslator is a free software which convert Ada code to C/C++ 
 * source code
 * Copyright (C) 2004 Julien THEVENON
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option) 
 * any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for 
 * more details.
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 * For further informations : adatoccpptranslator@free.fr
 * 
 * Description: declaration of subunit class
 *
 * $Log: subunit.h,v $
 * Revision 1.1  2005/03/09 20:07:39  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ update include paths due to the new sources organization
 *
 * Revision 1.1.1.1  2005/03/01 22:20:44  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef SUBUNIT_H
#define SUBUNIT_H

#include "../Tools/error.h"
#include "../Tools/trace.h"

#include "package.h"

class subunit : public package
{
	protected :
	char *m_ParentUnitName;
	
	public:
	char *getParentUnitName(void);
	
	void checkIntegrity(char *p_FileName, int p_LineNumber);
	
	subunit(void);
	subunit(char *p_Name,char *p_ParentUnitName,main_unit *p_MainUnit); 
};
#endif
