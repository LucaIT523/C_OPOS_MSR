/*************************************************************************
 *
 * NCRSCAN.H
 *
 *   Scanner header file for the NCR Applications.
 *
 *   Copyright (c) 1996 NCR.  All rights reserved.
 *
 * Author: NS 
 *
 *
 * $Workfile:: NCRScan.h                                                 $
 *
 * $Revision:: 6                                                         $
 *
 * $Archive:: /OPOS/Rel.2_5/Include/NCR/NCRScan.h                        $
 *
 * $Date:: 6/15/09 4:51p                                                 $
 *
 *************************************************************************
 * 
 * Copyright (c) NCR Corporation 1998.  All rights reserved.
 *
 *************************************************************************
 *
 * $History:: NCRScan.h                                                  $
 * 
 * *****************  Version 6  *****************
 * User: Barlom       Date: 6/15/09    Time: 4:51p
 * Updated in $/OPOS/Rel.2_5/Include/NCR
 * Added inline functions for numeric and string Pidx validation that had
 * been removed from standard code.
 * TAR # 407531
 * 
 * *****************  Version 4  *****************
 * User: Mr160002     Date: 7/02/04    Time: 1:04p
 * Updated in $/OPOS/Rel.2_4/Include/NCR
 * Added RC3.3 const including RFID scan data types.
 * 
 * *****************  Version 18  *****************
 * User: Nj151001     Date: 4/25/01    Time: 2:38p
 * Updated in $/OPOS/Rel.2_1/Include/NCR
 * Added new DirectIO commands to support the 7882.
 * 
 * *****************  Version 16  *****************
 * User: Nj151001     Date: 9/21/00    Time: 12:32p
 * Updated in $/OPOS/Rel.2_0/Include/NCR
 * Added message to indicate .bas dependency
 * 
 * *****************  Version 14  *****************
 * User: Mr160002     Date: 4/25/00    Time: 1:51p
 * Updated in $/OPOS/Rel.1_8/Include/NCR
 * Add extended error codes for scanner hardware failures
 * 
 * *****************  Version 12  *****************
 * User: Dw160003     Date: 11/09/99   Time: 1:30p
 * Updated in $/OPOS/Rel.1_7/Include/NCR
 * added VSS headers
 * 
 * *****************  Version 1  *****************
 * User: NS       Date: 5/08/96    Time: 10:01a
 * Created in $/OPOS/Rel.1_1/Include/NCR
 * 
 *
 ************************************************************************/

//!!!!!!!!!!!!!!!!!!!!!!!!!!! ndj 9/19/00 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// NOTE: Any modifications made to this include file most also be made in
//       NCRscan.bas !!  Do not check in your modified version of this file
//	 unless you are checking in NCRscan.bas as well.

/////////////////////////////////////////////////////////////////////
// "ResultCodeExtended" Property Constants for Scanner  TAR 72258
/////////////////////////////////////////////////////////////////////
// Reserved for SCALE:  From 0 + OPOSERREXT to 99 + OPOSERREXT.
// Reserved for SCANNER:  From 100 + OPOSERREXT to 199 + OPOSERREXT.
const long NCR_ESCAN_DATALOSS           = 100 + OPOSERREXT; //  Not used
const long NCR_ESCAN_BADTAGSUFFIX       = 101 + OPOSERREXT; //  Bad suffix byte 
const long NCR_ESCAN_BADTAGPREFIX       = 102 + OPOSERREXT; //  Bad prefix byte
const long NCR_ESCAN_BADTAG             = 103 + OPOSERREXT; //  Missing "30 38" for scanner/scale tag
const long NCR_ESCAN_SERIAL             = 104 + OPOSERREXT; //  Serial line error
const long NCR_ESCAN_WOBULATOR_FAILURE  = 105 + OPOSERREXT; 
const long NCR_ESCAN_LASER_FAILURE			= 106 + OPOSERREXT; 
const long NCR_ESCAN_MOTOR_FAILURE			= 107 + OPOSERREXT; 
const long NCR_ESCAN_MOTIONTHREAD_FAILURE = 108 + OPOSERREXT; // Motion Thread failed to start
const LONG NCR_ESCAN_BADSUFFIX       = 109 + OPOSERREXT; //  Bad suffix byte RC3.3
const LONG NCR_ESCAN_BADPREFIX       = 110 + OPOSERREXT; //  Bad prefix byte RC3.3

/////////////////////////////////////////////////////////////////////
// "DirectIO" Method Constants for Scanner (NCR 7870, 7875, 7880, and 7890)
/////////////////////////////////////////////////////////////////////

const long NCRDIO_SCAN_TONE             = 501;
const long NCRDIO_SCAN_RESET            = 502;
const long NCRDIO_SCAN_STATUS           = 503;
const long NCRDIO_SCAN_READROM          = 504;
const long NCRDIO_SCAN_ROM_VERSION      = 505;
const long NCRDIO_SCAN_PACESETTER       = 506;
const long NCRDIO_SCAN_DIRECT           = 507;
const long NCRDIO_SCAN_NOT_ON_FILE      = 508;

// ndj 3/27/01...New Direct IO commands for the 7882 scanner
const long NCRDIO_SCAN_SUSPEND          = 509;
const long NCRDIO_SCAN_START            = 510;

const long SCAN_TONE_BEEP               = 1001;
const long SCAN_TONE_ENABLE             = 1002;
const long SCAN_TONE_DISABLE            = 1003;

const long PACESETTER_READ_GOOD         = 1101;
const long PACESETTER_READ_NO_READS     = 1102;
const long PACESETTER_READ_OVERPRINT    = 1103;
const long PACESETTER_READ_UNDERPRINT   = 1104;
const long PACESETTER_READ_MISS_MARGIN  = 1105;
const long PACESETTER_RESET             = 1106;
const long PACESETTER_ENABLE_MODE_3     = 1107;
const long PACESETTER_DISABLE_MODE_3    = 1108;

// Scan Data Type RFID RC3.3
// Special cases
const LONG SCAN_SDT_RFID_UNKNOWN       = SCAN_SDT_OTHER + 100;  // Start of RFID specific barcodes
const LONG SCAN_SDT_RFID_OTHER       = SCAN_SDT_OTHER + 101;  // Start of RFID specific barcodes
const LONG SCAN_SDT_RFID       = SCAN_SDT_OTHER + 102;  // Start of RFID specific barcodes


//
// OPOS Common Validation Functions that had been removed from standard
// common files. We used them and needed to add defintions into our code.
//
// * Validation Functions *
//
// TAR # 407531
//

inline BOOL IsValidNumericPidx(LONG Pidx)
{
  return ( PIDX_Claimed <= Pidx && Pidx <= PIDX_State )
    ? TRUE : FALSE ;
}

inline BOOL IsValidNumericPidx12(LONG Pidx)
{
  return ( PIDX_Claimed <= Pidx && Pidx <= PIDX_DataCount )
    ? TRUE : FALSE ;
}

inline BOOL IsValidNumericPidx13(LONG Pidx)
{
  return ( PIDX_Claimed <= Pidx && Pidx <= PIDX_PowerState )
    ? TRUE : FALSE ;
}

inline BOOL IsValidCapPidx(LONG Pidx)
{
  return FALSE ;
}

inline BOOL IsValidCapPidx13(LONG Pidx)
{
  return ( PIDX_CapPowerReporting == Pidx )
    ? TRUE : FALSE ;
}


inline BOOL IsValidStringPidx(LONG Pidx)
{
	return ( PIDX_CheckHealthText <= Pidx &&
					 Pidx <= PIDX_ServiceObjectDescription )
			? TRUE : FALSE ;
}

// end

