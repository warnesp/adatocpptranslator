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
 * Description: declaration of procedure_protoype class
 *
 * $Log: procedure_prototype.h,v $
 * Revision 1.1  2005/03/19 09:22:28  quicky2000
 * initial import due to the new representation of subprogram
 *
 *
 *****************************************************************************/
#ifndef PROCEDURE_PROTOTYPE_H
#define PROCEDURE_PROTOTYPE_H

#include "../Tools/error.h"
#include "../Tools/trace.h"

#include "../Tools/list_tools.h"

class procedure_prototype
{
	private:
	list<parameter*> *m_Parameters;
	char m_BoolEmpty;
	
	public:
	list<parameter*>* getParameters(void);
	parameter* getParameter(char *p_Name);
	
	void checkIntegrity(const char *p_FileName, int p_LineNumber);
	
	procedure_prototype(void);
	procedure_prototype(tree *p_FormalPartTree,main_unit *p_MainUnit);	
};
#endif
