/*************************************************************************
 *
 *  NCRTone.h: Tone Indicator header file for the NCR Applications.
 * 
 * $Workfile: NCRTone.h $
 *
 * $Revision: 8 $
 *
 * $Archive: /OPOS/Rel.2_0/Include/NCR/NCRTone.h $
 *
 * $Date: 9/21/00 12:32p $
 *
 *************************************************************************
 *
 * Copyright (c) NCR Corporation 1998.  All rights reserved.
 *
 *************************************************************************
 *
 * $History: NCRTone.h $   
 * 
 * *****************  Version 8  *****************
 * User: Nj151001     Date: 9/21/00    Time: 12:32p
 * Updated in $/OPOS/Rel.2_0/Include/NCR
 * Added message to indicate .bas dependency
 * 
 * *****************  Version 5  *****************
 * User: Reedm        Date: 11/30/99   Time: 12:16p
 * Updated in $/OPOS/Rel.1_7/Include/NCR
 * TAR 120539 added DIRECT IO const for error tone and keyclick
 * 
 * *****************  Version 1  *****************
 * User: Spohnb       Date: 6/25/98    Time: 11:54a
 * Created in $/OPOS/Rel.1_4/Include/NCR
 * Initial version.
 * 
 * 
 ************************************************************************/

//!!!!!!!!!!!!!!!!!!!!!!!!!!! ndj 9/19/00 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// NOTE: Any modifications made to this include file most also be made in
//       NCRtone.bas !!  Do not check in your modified version of this file
//	 unless you are checking in NCRtone.bas as well.

/////////////////////////////////////////////////////////////////////
// "ResultCodeExtended" Property Constants for Tone Indicator
/////////////////////////////////////////////////////////////////////

const long NCR_ETONE_NOT_ON_WEDGE = 701 + OPOSERREXT; // Not available for Wedge tone device
const long NCR_ETONE_UNSUPPORTED  = 702 + OPOSERREXT; // Feature not currently supported


/////////////////////////////////////////////////////////////////////
// "DIRECT IO" Constants for Tone Indicator
/////////////////////////////////////////////////////////////////////
const long NCRDIO_SET_ERROR_TONE = 701; // Wedge error tone   
const long NCRDIO_SET_KEYCLICK_TONE = 702; // Wedge keycklick tone   
