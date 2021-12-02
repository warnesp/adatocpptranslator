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
 * Description: declaration of parameter class
 *
 * $Log: parameter.h,v $
 * Revision 1.3  2005/03/27 01:04:11  quicky2000
 * Update due to the replacement of type representation by a tree instead of string
 *
 * Revision 1.2  2005/03/19 08:46:57  quicky2000
 * Update to make protected members become private
 *
 * Revision 1.1  2005/03/08 20:18:25  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ update the include paths due to the new organization of sources
 *
 * Revision 1.1.1.1  2005/03/01 22:20:42  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef PARAMETER_H
#define PARAMETER_H

#include "../Tools/error.h"
#include "../Tools/trace.h"

#include "../Tools/tree.h"

#include "variable_object.h"

typedef enum
{
	Parameter_In,
	Parameter_In_Out,
	Parameter_Out,
	Parameter_Undefined
}t_ParameterMode;

void displayParameterMode(t_ParameterMode p_ParameterMode);

class parameter : public variable_object
{
	private:
	t_ParameterMode m_ParameterMode;
	
	public:
	t_ParameterMode getParameterMode(void);
	
	void display(void);
	void checkIntegrity(const char *p_FileName,int p_LineNumber);
	
	parameter(void);
	parameter(const char *p_Name,subtyped *p_Subtyped,t_ParameterMode p_ParameterMode,main_unit *p_MainUnit);
	parameter(const char *p_Name,subtyped *p_Subtyped,t_ParameterMode p_ParameterMode,tree *p_InitTree,main_unit *p_MainUnit);

};

parameter* new_parameter(const char *p_Name,tree *p_TypeTree,tree *p_ParameterModeTree,tree *p_InitTree, main_unit *p_MainUnit);
#endif
