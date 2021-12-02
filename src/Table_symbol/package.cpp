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
 * Description: instantiation of package class
 *
 * $Log: package.cpp,v $
 * Revision 1.2  2005/03/18 19:16:08  quicky2000
 * Update due to protected members which become private
 *
 * Revision 1.1  2005/03/13 16:44:25  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 *
 * Revision 1.1.1.1  2005/03/01 22:20:41  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "package.h"

void displayPackageType(t_Package_Type p_PackageType)
{
	switch(p_PackageType)
	{
		case Generic_Package_Inst: printf("Generic_Package_Inst");break;
		case Package_Undefined: printf("Package_Undefined");break;
		case Body: printf("Body");break;
		case Spec: printf("Spec");break;
		case Subunit: printf("Subunit");break;
		default:printf("INTERNAL ERROR : %s %i : package type %i is not manage\n",__FILE__,__LINE__,p_PackageType);
		my_exit(-1);
		break;
	}
}



void package::checkIntegrity(char *p_FileName,int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	int error=0;
	
	if(m_PackageType==Package_Undefined)
	{
		printf("ERROR : %s %i : member m_PackageType value is \"Package_Undefined\"\n",p_FileName,p_LineNumber);
		error=1;
	}
	
	unit::checkIntegrity(p_FileName,p_LineNumber);
	if(error!=0)
	{
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
	
}	
	
void package::display(void)
{
	this->checkIntegrity(__FILE__,__LINE__);
	printf("package \"%s\" defined in main unit \"%s\"\n",getName(),getMainUnit()->getName());
}

t_Package_Type package::getPackageType(void)
{
	return m_PackageType;
}

package::package(void):main_unit()
{
	#ifdef TRACE
	printfTraceUp("package",__FILE__,__LINE__);
	#endif
	#ifdef TRACE
	printfTraceDown("package",__FILE__,__LINE__);
	#endif
	
}
	
package::package(t_Package_Type p_PackageType,char *p_Name,main_unit *p_MainUnit):main_unit(Main_Unit_Package,p_Name,p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("package",__FILE__,__LINE__);
	#endif
	m_PackageType=p_PackageType;
	#ifdef TRACE
	printfTraceDown("package",__FILE__,__LINE__);
	#endif
}



package_spec::package_spec(void):package()
{
	#ifdef TRACE
	printfTraceUp("package_spec",__FILE__,__LINE__);
	#endif
	#ifdef TRACE
	printfTraceDown("package_spec",__FILE__,__LINE__);
	#endif
}
	
package_spec::package_spec(char *p_Name,main_unit *p_MainUnit):package(Spec,p_Name,p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("package_spec",__FILE__,__LINE__);
	#endif
	#ifdef TRACE
	printfTraceDown("package_spec",__FILE__,__LINE__);
	#endif
}

package_body::package_body(void):package()
{
	#ifdef TRACE
	printfTraceUp("package_body",__FILE__,__LINE__);
	#endif
	#ifdef TRACE
	printfTraceDown("package_body",__FILE__,__LINE__);
	#endif
}
	
package_body::package_body(char *p_Name,main_unit *p_MainUnit):package(Body,p_Name,p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("package_body",__FILE__,__LINE__);
	#endif
	#ifdef TRACE
	printfTraceDown("package_body",__FILE__,__LINE__);
	#endif
}

