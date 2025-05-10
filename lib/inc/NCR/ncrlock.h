/*************************************************************************
 *
 * NCRLOCK.H
 *
 * Keylock header file for OPOS Applications.
 *
 * Author:  
 *
 *
 * $Workfile:: ncrlock.h                                                 $
 *
 * $Revision:: 6                                                         $
 *
 * $Archive:: /OPOS/Rel.2_6/Include/NCR/ncrlock.h                        $
 *
 * $Date:: 11/20/09 4:24p                                                 $
 *
 *************************************************************************
 * 
 * Copyright (c) NCR Corporation 1998.  All rights reserved.
 *
 *************************************************************************
 *
 * $History:: ncrlock.h                                                  $
 * 
 * *****************  Version 6  *****************
 * User: Barlom       Date: 11/20/09   Time: 4:24p
 * Updated in $/OPOS/Rel.2_6/Include/NCR
 * Initial chnages to support compiling under VS 2008 .NET
 * 
 * *****************  Version 16  *****************
 * User: Nj151001     Date: 9/21/00    Time: 12:32p
 * Updated in $/OPOS/Rel.2_0/Include/NCR
 * Added message to indicate .bas dependency
 * 
 * *****************  Version 14  *****************
 * User: Duffem       Date: 3/01/00    Time: 10:22a
 * Updated in $/OPOS/Rel.1_8/Include/NCR
 * 
 * *****************  Version 12  *****************
 * User: Dw160003     Date: 11/09/99   Time: 10:28a
 * Updated in $/OPOS/Rel.1_7/Include/NCR
 * added VSS headers
 * 
 * *****************  Version 1  *****************
 * User:        Date: 12/08/95    Time: 10:01a
 * Created in $/OPOS/Rel.1_1/Include/NCR
 * 
 *
 ************************************************************************/


//!!!!!!!!!!!!!!!!!!!!!!!!!!! ndj 9/19/00 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// NOTE: Any modifications made to this include file most also be made in
//       ncrlock.bas !!  Do not check in your modified version of this file
//	 unless you are checking in ncrlock.bas as well.

#if !defined(NCRLOCK_H)
#define      NCRLOCK_H


/////////////////////////////////////////////////////////////////////
// NCR-specific Wedge Keylock "KeyPosition" Property Constants,
// "WaitForKeylockChange" Method: "KeyPosition" Parameter, and
// "StatusUpdateEvent" Event: "Data" Parameter
/////////////////////////////////////////////////////////////////////

const LONG LOCK_KP_EXCP         = 4;
const LONG LOCK_KP_FIELD		= 5;
const LONG LOCK_KP_SUPERVISOR1	= 6;
const LONG LOCK_KP_SUPERVISOR2	= 7;

// added for SCOT Supervisor Switch - H/W can be in unknown state.
// Control has registry entry to communicate or not communicate the
// unknown position upwards.
const LONG LOCK_KP_UNKNOWN      = 101;

/////////////////////////////////////////////////////////////////////
// DirectIO method - Keyboard type is returned in *pData may have one of the
// following values:
//
// 0 - Touch or Non wedge keyboard
// 2 - Dynakey
// 5 - BigTicket keyboard
// 7 - POS keyboard
// 8 - Micromotion keyboard
// 
// Calling DirectIO(NCRDIO_KEYBOARD_TYPE, LONG* pData, BSTR* pString);
//
//
/////////////////////////////////////////////////////////////////////

const int NCRDIO_KEYBOARD_TYPE      = 0x01; // command to send

 


#endif                  // !defined(NCRLOCK_H)
