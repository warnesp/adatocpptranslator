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
 * Description: instantiation of record_type class
 *
 * $Log: record_type.cpp,v $
 * Revision 1.1  2005/03/13 16:46:40  quicky2000
 * Update :
 * _ to move the code from scr directory
 * _ for code maintenance
 * _ to add a function to list the type component members
 *
 *
 *****************************************************************************/
#include "record_type.h"

char record_type::getBoolNullRecord(void)
{
	return m_BoolNullRecord;
}

char record_type::getBoolAbstract(void)
{
	return m_BoolAbstract;
}

char record_type::getBoolLimited(void)
{
	return m_BoolLimited;
}

char record_type::getBoolTagged(void)
{
	return m_BoolTagged;
}

component_list* record_type::getComponentList(void)
{
	return m_ComponentList;
}

void record_type::checkIntegrity(char *p_FileName, int p_LineNumber)
{
	#ifdef TRACE
	printfTraceUp("checkIntegrity",__FILE__,__LINE__);
	#endif
	int error=0;
	
	composite_type::checkIntegrity(p_FileName,p_LineNumber);
	discrimined::checkIntegrity(p_FileName,p_LineNumber);
	if(m_ComponentList==NULL && m_BoolNullRecord==0)
	{
		printf("ERROR : %s %i : \"m_ComponentList\" is NULL and \"m_BoolNullRecord\" is NULL\n",p_FileName,p_LineNumber);
		error=1;
	}
	
	if(m_ComponentList!=NULL && m_BoolNullRecord!=0)
	{
		printf("ERROR : %s %i : \"m_ComponentList\" is not NULL and \"m_BoolNullRecord\" is not NULL\n",p_FileName,p_LineNumber);
		error=1;
	}
	
	if(error!=0)
	{
		my_exit(-1);
	}
	#ifdef TRACE
	printfTraceDown("checkIntegrity",__FILE__,__LINE__);
	#endif
}

record_type::record_type(void):composite_type(Composite_Type_Record),discrimined()
{
	#ifdef TRACE
	printfTraceUp("record_type",__FILE__,__LINE__);
	#endif
	m_BoolNullRecord=0;
	m_BoolAbstract=0;
	m_BoolTagged=0;
	m_BoolLimited=0;
	m_ComponentList=NULL;
	#ifdef TRACE
	printfTraceDown("record_type",__FILE__,__LINE__);
	#endif
}

record_type::record_type(char *p_Name,char p_Abstract,char p_Limited,char p_Tagged,main_unit *p_MainUnit):composite_type(Composite_Type_Record,p_Name,p_MainUnit),discrimined()
{
	#ifdef TRACE
	printfTraceUp("record_type",__FILE__,__LINE__);
	#endif
	m_BoolNullRecord=1;
	m_BoolAbstract=p_Abstract;
	m_BoolTagged=p_Tagged;
	m_BoolLimited=p_Limited;
	m_ComponentList=NULL;
	#ifdef TRACE
	printfTraceDown("record_type",__FILE__,__LINE__);
	#endif
}

record_type::record_type(char *p_Name,char p_Abstract,char p_Limited,char p_Tagged,char p_BoolGeneric,list<discrim_spec*> *p_DiscrimSpecs,main_unit *p_MainUnit):composite_type(Composite_Type_Record,p_Name,p_MainUnit),discrimined(p_BoolGeneric,p_DiscrimSpecs)
{
	#ifdef TRACE
	printfTraceUp("record_type",__FILE__,__LINE__);
	#endif
	m_BoolNullRecord=1;
	m_BoolAbstract=p_Abstract;
	m_BoolTagged=p_Tagged;
	m_BoolLimited=p_Limited;
	m_ComponentList=NULL;
	#ifdef TRACE
	printfTraceDown("record_type",__FILE__,__LINE__);
	#endif
}

record_type::record_type(char *p_Name,char p_Abstract,char p_Limited,char p_Tagged,component_list *p_ComponentList,main_unit *p_MainUnit):composite_type(Composite_Type_Record,p_Name,p_MainUnit),discrimined()
{
	#ifdef TRACE
	printfTraceUp("record_type",__FILE__,__LINE__);
	#endif
	m_BoolNullRecord=0;
	m_BoolAbstract=p_Abstract;
	m_BoolTagged=p_Tagged;
	m_BoolLimited=p_Limited;
	m_ComponentList=p_ComponentList;
	#ifdef TRACE
	printfTraceDown("record_type",__FILE__,__LINE__);
	#endif
}

record_type::record_type(char *p_Name,char p_Abstract,char p_Limited,char p_Tagged,char p_BoolGeneric,list<discrim_spec*> *p_DiscrimSpecs,component_list *p_ComponentList,main_unit *p_MainUnit):composite_type(Composite_Type_Record,p_Name,p_MainUnit),discrimined(p_BoolGeneric,p_DiscrimSpecs)
{
	#ifdef TRACE
	printfTraceUp("record_type",__FILE__,__LINE__);
	#endif
	m_BoolNullRecord=0;
	m_BoolAbstract=p_Abstract;
	m_BoolTagged=p_Tagged;
	m_BoolLimited=p_Limited;
	m_ComponentList=p_ComponentList;
	#ifdef TRACE
	printfTraceDown("record_type",__FILE__,__LINE__);
	#endif
}

record_type* new_record_type(char *p_Name,tree *p_DiscrimTree,tree *p_RecordTree,main_unit *p_MainUnit)
{
	#ifdef TRACE
	printfTraceUp("new_record_type",__FILE__,__LINE__);
	#endif
	record_type *result=NULL;
	if(p_DiscrimTree!=NULL && p_RecordTree!=NULL)
	{
		if(p_RecordTree->getNodeType()==Node_Ada_Record_Type)
		{
			char p_Tagged=0;
			char p_Abstract=0;
			char p_Limited=0;
			switch(p_RecordTree->getSon(0)->getNodeType())
			{
				case Node_Ada_C_Empty:
				break;
				case Node_Ada_Tagged:p_Tagged=1;
				break;
				case Node_Ada_Abstract_Tagged:p_Abstract=1;p_Tagged=1;
				break;
				default:errorNotAllowed(__FILE__,__LINE__,p_RecordTree->getSon(0),"tagged_opt");
				my_exit(-1);
				break;
			}
			switch(p_RecordTree->getSon(1)->getNodeType())
			{
				case Node_Ada_C_Empty:
				break;
				case Node_Ada_Limited:p_Limited=1;
				break;
				default:errorNotAllowed(__FILE__,__LINE__,p_RecordTree->getSon(1),"limited_opt");
				my_exit(-1);
				break;
			}
			
			char discrimined=0;
			char p_BoolGeneric=0;
			list<discrim_spec*> *p_DiscrimSpecs=NULL;
			
			switch(p_DiscrimTree->getNodeType())
			{
			
				case Node_Ada_C_Empty:
                        	break;
                        	case Node_Ada_Discrim_Part_Opt:
				discrimined=1;
                        	p_BoolGeneric=1;
				break;
                        	case Node_Ada_Discrim_Part:
				discrimined=1;
                        	p_DiscrimSpecs=getListDiscrimSpec(p_DiscrimTree->getSon(0),p_DiscrimSpecs);
           			break;
				default:
				errorNotAllowed(__FILE__,__LINE__,p_DiscrimTree,"discrim_part_opt");
				my_exit(-1);
				break;

			}
			
			tree *p_RecordDefTree=p_RecordTree->getSon(2);
			
			switch(p_RecordDefTree->getNbSon())
			{
				case 0:
				if(discrimined==0)
				{
					result=new record_type(p_Name,p_Abstract,p_Limited,p_Tagged,p_MainUnit);
				}
				else
				{
					result=new record_type(p_Name,p_Abstract,p_Limited,p_Tagged,p_BoolGeneric,p_DiscrimSpecs,p_MainUnit);
				}
				break;
				case 2:
				{
					component_list *p_ComponentList=new_component_list(p_RecordDefTree->getSon(1));
					if(discrimined==0)
					{
						result=new record_type(p_Name,p_Abstract,p_Limited,p_Tagged,p_ComponentList,p_MainUnit);
					}
					else
					{
						result=new record_type(p_Name,p_Abstract,p_Limited,p_Tagged,p_BoolGeneric,p_DiscrimSpecs,p_ComponentList,p_MainUnit);
					}
				}
				break;
				default:
				errorNbSon(__FILE__,__LINE__,p_RecordDefTree);
				my_exit(-1);
				break;
			}
			
		}
		else
		{
			errorNotAllowed(__FILE__,__LINE__,p_RecordTree,"record_type");
			my_exit(-1);
		}
	}
	else
	{
		int error=0;
		
		if(p_DiscrimTree==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_DiscrimTree");
			error=1;
		}
		if(p_RecordTree==NULL)
		{
			errorIsNull(__FILE__,__LINE__,"p_RecordTree");
			error=1;
		}
		if(error!=0)
		{
			my_exit(-1);
		}
	}
	#ifdef TRACE
	printfTraceDown("new_record_type",__FILE__,__LINE__);
	#endif
	
	return result;
}	
