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
 * Description: declaration of procedure_spec class
 *
 * $Log: procedure_spec.h,v $
 * Revision 1.2  2005/03/19 09:31:44  quicky2000
 * Update due to the new representation of procedures
 *
 * Revision 1.1  2005/03/08 20:18:26  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ update the include paths due to the new organization of sources
 *
 * Revision 1.1.1.1  2005/03/01 22:20:42  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef PROCEDURE_SPEC_H
#define PROCEDURE_SPEC_H

#include "../Tools/error.h"
#include "../Tools/trace.h"

#include "unit.h"
class procedure_prototype;

class procedure_spec:public unit
{
	private:
	procedure_prototype *m_Prototype;

	public:
	void checkIntegrity(const char *p_FileName, int p_LineNumber);
	
	procedure_spec(void);
	procedure_spec(const char *p_Name,tree *p_FormalPartTree,main_unit *p_MainUnit);
};
#endif
