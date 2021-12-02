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
 * Description: instantiation of generic_package class
 *
 * $Log: generic_package_inst.h,v $
 * Revision 1.1  2005/03/08 20:14:48  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ update the include paths due to the new organization of sources
 *
 * Revision 1.1.1.1  2005/03/01 22:20:38  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef GENERIC_PACKAGE_INST_H
#define GENERIC_PACKAGE_INST_H

#include "../Tools/error.h"
#include "../Tools/trace.h"

#include "package.h"
#include "../Tools/tree.h"

class generic_package_inst : public package
{
	private:
	char *m_GenericPackageName;
	
	public:
	char* getGenericPackageName(void);
	
	void display(void);
	void checkIntegrity(char *p_FileName,int p_LineNumber);
	
	generic_package_inst(void);
	generic_package_inst(char *p_Name,char *p_GenericPackageName,main_unit *p_MainUnit);
	
};

generic_package_inst* new_generic_package_inst(char *p_Name,tree *p_GenericPackageName,main_unit *p_MainUnit);
#endif
