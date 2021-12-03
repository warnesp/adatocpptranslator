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
 * Description: declaration of configuration class
 *
 * $Log: configuration.h,v $
 * Revision 1.5  2005/03/26 23:12:37  quicky2000
 * Update of version number
 *
 * Revision 1.4  2005/03/19 13:45:08  quicky2000
 * Update of release version number
 *
 * Revision 1.3  2005/03/19 10:45:59  quicky2000
 * Update to change the version number
 *
 * Revision 1.2  2005/03/17 18:17:26  quicky2000
 * Update to change the version number and define some parameters with preprocessor constant
 *
 * Revision 1.1  2005/03/08 00:11:14  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ modify the include paths due to the reorganization of source files
 *
 * Revision 1.4  2005/03/03 22:15:18  quicky2000
 * Update Release version number
 *
 * Revision 1.3  2005/03/02 23:54:43  quicky2000
 * Update to restablish cvs log history
 *
 * Revision 1.2  2005/03/01 23:20:35  quicky2000
 * Update of Release version
 *
 * Revision 1.1.1.1  2005/03/01 22:20:35  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "error.h"
#include <time.h>

#define RELEASE_NAME	"BASED VERSION"
#define RELEASE_NUMBER	"1.0.2 Beta"

#define BODY_EXTENSION	"cpp"
#define HEADER_EXTENSION	"h"
#define LOG_EXTENSION	"log"

#define INPUT_DIR	"input"
#define OUTPUT_DIR	"output"

#define VERBOSE		1

class configuration
{
	private:
	/* Software informations */
	const char *m_ReleaseName;
	const char *m_Release;
	const char *m_Date;
	
	/* Extensions */
	const char *m_BodyExtension;
	const char *m_HeaderExtension;
	const char *m_LogExtension;
	
	/* Directories */
	const char *m_InputDir;
	const char *m_OutputDir;
	
	/* Verbose mode */
	char m_Verbose;
	
	public:
	configuration(void);
	
	const char * getBodyExtension(void);
	const char * getHeaderExtension(void);
	const char * getLogExtension(void);
	
	const char * getInputDir(void);
	const char * getOutputDir(void);
	
	char getVerbose(void);
	
	void display(void);
	void write(FILE *p_Fp,const char *p_SourceName);
};
#endif
