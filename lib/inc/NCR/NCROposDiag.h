/*************************************************************************
 *
 * NCROPOSDIAG.H
 *
 *   Header file for AT&T GIS OPOS Diagnostics
 *
 *   Copyright (c) 1996 NCR.  All rights reserved.
 *
 * Author: JPR 
 *
 *
 * $Workfile:: NCROposDiag.h                                             $
 *
 * $Revision:: 11                                                        $
 *
 * $Archive:: /OPOS/Rel.2_0/Include/NCR/NCROposDiag.h                    $
 *
 * $Date:: 9/21/00 12:32p                                                 $
 *
 *************************************************************************
 * 
 * Copyright (c) NCR Corporation 1998.  All rights reserved.
 *
 *************************************************************************
 *
 * $History:: NCROposDiag.h                                              $
 * 
 * *****************  Version 11  *****************
 * User: Nj151001     Date: 9/21/00    Time: 12:32p
 * Updated in $/OPOS/Rel.2_0/Include/NCR
 * Added message to indicate .bas dependency
 * 
 * *****************  Version 8  *****************
 * User: Dw160003     Date: 11/09/99   Time: 10:53a
 * Updated in $/OPOS/Rel.1_7/Include/NCR
 * added VSS headers
 * 
 * *****************  Version 1  *****************
 * User: JPR       Date: 11/20/95    Time: 10:01a
 * Created in $/OPOS/Rel.1_1/Include/NCR
 * 
 * *****************  Version 2  *****************
 * User: JPR       Date: 04/09/96    Time: 10:01a
 * Added Event Type Constants and fixed a comment
 * 
 *
 ************************************************************************/


//!!!!!!!!!!!!!!!!!!!!!!!!!!! ndj 9/19/00 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// NOTE: Any modifications made to this include file most also be made in
//       NCROposDiag.bas !!  Do not check in your modified version of this file
//	 unless you are checking in NCROposDiag.bas as well.

#if !defined(DIAG_HI)
#define      DIAG_HI

/////////////////////////////////////////////////////////////////////
//
// AT&T GIS Event Agent Definitions
//
/////////////////////////////////////////////////////////////////////

//
// OLE ProgID
//
const CString AutoEventAgent = "NCRDiagnostics.EVENTLOG";

//
// Automation Method
//
const CString LogEventMethod = "LogEvent";


//
// Event Type Constants
//
const int EVENT_TYPE_INFORMATIONAL = 2;
const int EVENT_TYPE_WARNING       = 4;
const int EVENT_TYPE_ERROR         = 5;
const int EVENT_TYPE_AUDIT_SUCCESS = 1;
const int EVENT_TYPE_AUDIT_FAILURE = 3;



/////////////////////////////////////////////////////////////////////
//
// AT&T GIS Tally Agent Definitions
//
/////////////////////////////////////////////////////////////////////

//
// OLE ProgID
//
const CString AutoTallyAgent = "NCRDiagnostics.TALLIES";

//
// Automation Method
//
const CString RegisterTallyMethod = "RegisterTally";

//
// Windows Custom Message Number
//
#define	WM_OPOS_TALLY_UPDATE	(WM_USER + 101)


#endif                  // !defined(DIAG_HI)
