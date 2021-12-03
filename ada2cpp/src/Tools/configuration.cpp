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
 * Description: instantiation of configuration class
 *
 * $Log: configuration.cpp,v $
 * Revision 1.2  2005/03/17 18:17:25  quicky2000
 * Update to change the version number and define some parameters with preprocessor constant
 *
 * Revision 1.1  2005/03/08 00:13:14  quicky2000
 * Update to:
 * _ move the file from src directory
 * _ add the function display which display informations about software
 *
 * Revision 1.1.1.1  2005/03/01 22:20:35  quicky2000
 * Initial import
 *
 *
 *****************************************************************************/
#include "configuration.h"

configuration::configuration(void)
{
	/*******************/
	/* Private members */
	/*******************/
	m_ReleaseName=RELEASE_NAME;
	m_Release=RELEASE_NUMBER;
	m_Date=__DATE__;
	
	/******************/
	/* Public members */
	/******************/
	
	/* Extensions */
	m_BodyExtension=BODY_EXTENSION;
	m_HeaderExtension=HEADER_EXTENSION;
	m_LogExtension=LOG_EXTENSION;
	
	/* Directories */
	m_InputDir=INPUT_DIR;
	m_OutputDir=OUTPUT_DIR;

	
	/* Verbose mode */
	m_Verbose=VERBOSE;
}

const char * configuration::getBodyExtension(void)
{
	return m_BodyExtension;
}

const char * configuration::getHeaderExtension(void)
{
	return m_HeaderExtension;
}

const char * configuration::getLogExtension(void)
{
	return m_LogExtension;
}

const char * configuration::getInputDir(void)
{
	return m_InputDir;
}

const char * configuration::getOutputDir(void)
{
	return m_OutputDir;
}

char configuration::getVerbose(void)
{
	return m_Verbose;
}

void configuration::display(void)
{
	printf("// AdatoCCppTranslator : \"%s\"\n",m_ReleaseName);
	printf("// Release : %s\n",m_Release);
	printf("// Emission date : %s\n",m_Date);		
}

void configuration::write(FILE *p_Fp, const char *p_SourceName)
{
	if(p_Fp!=NULL)
	{
		time_t t;
		time(&t);
		
		fprintf(p_Fp,"// AdatoCCppTranslator : \"%s\"\n",m_ReleaseName);
		fprintf(p_Fp,"// Release : %s\n",m_Release);
		fprintf(p_Fp,"// Emission date : %s\n",m_Date);
		fprintf(p_Fp,"// File created on %s",ctime(&t));
		fprintf(p_Fp,"// Source file : %s\n\n",p_SourceName);
		
	}
	else
	{
		errorIsNull(__FILE__,__LINE__,"p_Fp");
		my_exit(-1);
	}
}
