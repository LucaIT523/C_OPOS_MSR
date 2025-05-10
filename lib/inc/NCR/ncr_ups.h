/*************************************************************************
 *
 * NCR_UPS.H
 *
 * Header file for use by applications interested in NCR
 * UPS notification messages.  The strings in this file should be
 * passed to the RegisterWindowsMessage API in order to obtain the
 * message number of the AC off and on messages, respectively.
 *
 * Copyright (c) 1996 NCR.  All rights reserved.
 *
 * Modification history
 *
 * Author:  
 *
 *
 * $Workfile:: ncr_ups.h                                                 $
 *
 * $Revision:: 7                                                         $
 *
 * $Archive:: /OPOS/Rel.1_7/Include/NCR/ncr_ups.h                        $
 *
 * $Date:: 11/05/99 2:50p                                                $
 *
 *************************************************************************
 * 
 * Copyright (c) NCR Corporation 1998.  All rights reserved.
 *
 *************************************************************************
 *
 * $History:: ncr_ups.h                                                  $
 * 
 * *****************  Version 7  *****************
 * User: Dw160003     Date: 11/05/99   Time: 2:50p
 * Updated in $/OPOS/Rel.1_7/Include/NCR
 * added VSS headers
 * 
 * *****************  Version 1  *****************
 * User:        Date: //96    Time: 10:01a
 * Created in $/OPOS/Rel.1_4/Include/NCR
 * 
 *
 ************************************************************************/




// The AC off message is sent to all top level windows when AC power is lost
// for longer than the ride-through time specified in the registry.
#define NCR_AC_OFF_STRING	"NCR AC Off Msg"

// This AC on message is sent to all top level windows if AC power is restored
// after the AC off message is sent but before the shutdown time expires.
#define NCR_AC_ON_STRING	"NCR AC Restored Msg"
