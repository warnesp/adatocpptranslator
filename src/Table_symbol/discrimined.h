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
 * Description: declaration of discrimined class
 *
 * $Log: discrimined.h,v $
 * Revision 1.2  2005/03/18 19:37:30  quicky2000
 * Update to make protected members become private
 *
 * Revision 1.1  2005/03/08 00:56:20  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ update modify include paths due to the new source organization
 *
 * Revision 1.1.1.1  2005/03/01 22:20:36  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef DISCRIMINED_H
#define DISCRIMINED_H

#include "../Tools/error.h"
#include "../Tools/trace.h"
#include "../Tools/list.h"

class discrimined
{
	private:
	char m_BoolDiscrim;
	char m_BoolGeneric;
	list<discrim_spec*> *m_DiscrimSpecs;
	
	public:
	char getBoolDiscrim(void);
	char getBoolGeneric(void);
	list<discrim_spec*>* getDiscrimSpecs(void);
	
	void checkIntegrity(const char *p_FileName,int p_LineNumber);
	
	discrimined(void);
	discrimined(char p_BoolGeneric,list<discrim_spec*> *p_DiscrimSpecs);
	
};
#endif
