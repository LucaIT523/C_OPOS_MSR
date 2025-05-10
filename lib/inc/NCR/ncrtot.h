/*************************************************************************
 *
 * NCRTOT.H
 *
 *   NCR Specific Hard Totals header file for OPOS Applications
 *
 *   Copyright (c) 1996 NCR.  All rights reserved.
 *
 * Author: WTS 
 *
 *
 * $Workfile:: ncrtot.h                                                     $
 *
 * $Revision:: 13                                                        $
 *
 * $Archive:: /OPOS/Rel.2_0/Include/NCR/ncrtot.h                            $
 *
 * $Date:: 9/21/00 12:32p                                                $
 *
 *************************************************************************
 * 
 * Copyright (c) NCR Corporation 1998.  All rights reserved.
 *
 *************************************************************************
 *
 * $History:: ncrtot.h                                                      $
 * 
 * *****************  Version 13  *****************
 * User: Nj151001     Date: 9/21/00    Time: 12:32p
 * Updated in $/OPOS/Rel.2_0/Include/NCR
 * Added message to indicate .bas dependency
 * 
 * *****************  Version 10  *****************
 * User: Dw160003     Date: 11/09/99   Time: 1:51p
 * Updated in $/OPOS/Rel.1_7/Include/NCR
 * added VSS headers
 * 
 * *****************  Version 1  *****************
 * User: WTS       Date: 3/14/96    Time: 10:01a
 * Created in $/OPOS/Rel.1_4/Include/NCR
 * 
 * *****************  Version 2  *****************
 * User: WTS       Date: 1/24/97    Time: 10:01a
 * OPOS Release 1.1 : Modified data capture masks
 * 
 *
 ************************************************************************/


//!!!!!!!!!!!!!!!!!!!!!!!!!!! ndj 9/19/00 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// NOTE: Any modifications made to this include file most also be made in
//       NCRtot.bas !!  Do not check in your modified version of this file
//	 unless you are checking in NCRtot.bas as well.

#if !defined(NCRTOT_H)
#define      NCRTOT_H


#include "opostot.h"


/////////////////////////////////////////////////////////////////////
// Data capture masks for Hard Totals
/////////////////////////////////////////////////////////////////////
const	DWORD	DCM_INFO  = 1;		// Enable informational data capture
const	DWORD	DCM_ERROR = 2;		// Data capture all errors
const	DWORD	DCM_TRACE = 4;		// Data capture trace information
const   DWORD   DCM_IO    = 0x10;   // Capture data read and written to files


/////////////////////////////////////////////////////////////////////
// "ResultCodeExtended" Property Constants for Hard Totals
/////////////////////////////////////////////////////////////////////

const LONG NCR_ETOT_FILEDELETED = 3 + OPOSERREXT;   // File deleted by another app
const LONG NCR_ETOT_NOHANDLES   = 4 + OPOSERREXT;   // No more handles available

#endif                  // !defined(NCRTOT_H)

