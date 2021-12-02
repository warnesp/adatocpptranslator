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
 * Description: declaration of package class
 *
 * $Log: package.h,v $
 * Revision 1.2  2005/03/19 08:46:57  quicky2000
 * Update to make protected members become private
 *
 * Revision 1.1  2005/03/08 20:18:25  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ update the include paths due to the new organization of sources
 *
 * Revision 1.1.1.1  2005/03/01 22:20:41  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef PACKAGE_H
#define PACKAGE_H

#include "../Tools/trace.h"

#include "main_unit.h"
#include "unit.h"

typedef enum
{
	Generic_Package_Inst,
	Package_Undefined,
	Body,
	Spec,
	Subunit
}t_Package_Type;

void displayPackageType(t_Package_Type p_PackageType);

class package: public main_unit
{
	private:
	t_Package_Type m_PackageType;
	
	public:
	t_Package_Type getPackageType(void);
	
	void checkIntegrity(const char *p_FileName,int p_LineNumber);
	
	void display(void);
	
	package(void);
	package(t_Package_Type p_PackageType, const char *p_Name,main_unit *p_MainUnit);
};

class package_spec:public package
{
	public:
	package_spec(void);
	package_spec(const char *p_Name,main_unit *p_MainUnit);
	
};
class package_body:public package
{
	public:
	package_body(void);
	package_body(const char *p_Name,main_unit *p_MainUnit);
	
};
#endif
