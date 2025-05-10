/*************************************************************************
 *
 * NCRKMPDR.H
 *
 *  This is the application header file for the NCR Kernel Mode Port Driver.
 *
 * Author: Wayne Standard 
 * LANGUAGE:          Microsoft VC++ 4.0
 * OPERATING SYSTEM:  Windows NT 3.5
 * TARGET SYSTEM:     PC
 * ENVIRONMENT:       Kernel mode Driver
 *
 * CREATED:           March 1996
 * AUTHOR:            Wayne Standard, RP&S Atlanta
 *
 *
 * $Workfile:: NCRkmpdr.h                                                $
 *
 * $Revision:: 9                                                         $
 *
 * $Archive:: /OPOS/Rel.2_0/Include/NCR/NCRkmpdr.h                       $
 *
 * $Date:: 9/21/00 12:32p                                                $
 *
 *************************************************************************
 * 
 * Copyright (c) NCR Corporation 1998.  All rights reserved.
 *
 *************************************************************************
 *
 * $History:: NCRkmpdr.h                                                 $
 * 
 * *****************  Version 9  *****************
 * User: Nj151001     Date: 9/21/00    Time: 12:32p
 * Updated in $/OPOS/Rel.2_0/Include/NCR
 * Added message to indicate .bas dependency
 * 
 * *****************  Version 6  *****************
 * User: Dw160003     Date: 11/09/99   Time: 10:24a
 * Updated in $/OPOS/Rel.1_7/Include/NCR
 * added VSS headers
 * 
 * *****************  Version 1  *****************
 * User: Standw       Date: 3/04/96    Time: 10:01a
 * Created in $/OPOS/Rel.1_1/Include/NCR
 * 
 *
 ************************************************************************/


//!!!!!!!!!!!!!!!!!!!!!!!!!!! ndj 9/19/00 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// NOTE: Any modifications made to this include file most also be made in
//       NCRkmpdr.bas !!  Do not check in your modified version of this file
//	 unless you are checking in NCRkmpdr.bas as well.

// Operation codes used in the high DWORD of the read/write offset.
#define  WEDGE_IO          0xD0     // Perform WEDGE I/O
#define  CMOS_CONFIG       0x30     // Get CMOS configuration byte
#define  CMOS_IO           0x31     // Perform CMOS I/O

