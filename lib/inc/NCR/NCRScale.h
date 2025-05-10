/*************************************************************************
 *
 *  NCRScale.h: Scale header file for the NCR Applications.
 * 
 * $Workfile: NCRScale.h $
 *
 * $Revision: 16 $
 *
 * $Archive: /OPOS/Rel.2_0/Include/NCR/NCRScale.h $
 *
 * $Date: 9/21/00 12:32p $
 *
 *************************************************************************
 *
 * Copyright (c) NCR Corporation 1997.  All rights reserved.
 *
 *************************************************************************
 *
 * $History: NCRScale.h $ 	
 * 
 * *****************  Version 16  *****************
 * User: Nj151001     Date: 9/21/00    Time: 12:32p
 * Updated in $/OPOS/Rel.2_0/Include/NCR
 * Added message to indicate .bas dependency
 * 
 * *****************  Version 9  *****************
 * User: Reedm        Date: 2/12/98    Time: 4:23p
 * Updated in $/OPOS/Rel.1_2/Include/NCR
 * TAR 72258 added NCR_ESCAL and NCR_ESCAN extended errors.
 * 
 * *****************  Version 7  *****************
 * User: Reedm        Date: 10/14/97   Time: 4:22p
 * Updated in $/OPOS/Rel.1_1/Include/NCR
 * TAR67385 fix - File patch 1.1.1.1 - Changed Read Weight to use Scale
 * WEIGH command instead of MONITOR command.  Defined the result codes and
 * result code extended for Read Weight.  DIRECT I/O SCALE LIVE WEIGHT
 * continues to use MONITOR command.  Added DIRECT I/O SCALE READ WEIGHT
 * DELAY to set the delay from a Scale STATUS of Stable NonZero Weight
 * Available to the DLL issuing the WEIGH command.  The default delay is
 * 500ms.
 * 
 ************************************************************************/

//!!!!!!!!!!!!!!!!!!!!!!!!!!! ndj 9/19/00 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// NOTE: Any modifications made to this include file most also be made in
//       NCRscale.bas !!  Do not check in your modified version of this file
//	 unless you are checking in NCRscale.bas as well.

/////////////////////////////////////////////////////////////////////
// "ResultCodeExtended" Property Constants for Scale
/////////////////////////////////////////////////////////////////////

const long NCR_ESCAL_UNSTABLE           = 2 + OPOSERREXT; // ReadWeight NO stable weight available
const long NCR_ESCAL_UNDERZERO          = 3 + OPOSERREXT; // ReadWeight Weight under zero
const long NCR_ESCAL_ZEROWEIGHT         = 4 + OPOSERREXT; // ReadWeight Stable Weight of zero
const long NCR_ESCAL_WEIGHTUNCHANGED    = 5 + OPOSERREXT; // ReadWeight status Weight unchanged
const long NCR_ESCAL_NOTREADY           = 6 + OPOSERREXT; // ReadWeight status Not Ready TAR 72258


/////////////////////////////////////////////////////////////////////
// "DirectIO" Method Constants for Scale (NCR 7870 and 7880)
/////////////////////////////////////////////////////////////////////

const long NCRDIO_SCAL_STATUS           = 601;
const long NCRDIO_SCAL_READROM          = 602;
const long NCRDIO_SCAL_ROM_VERSION      = 603;
const long NCRDIO_SCAL_LIVE_WEIGHT      = 604;
const long NCRDIO_SCAL_DIRECT           = 605;
const long NCRDIO_SCAL_WEIGHT_DELAY     = 606;  //07Oct97 TAR67385 Delay from Stable Weight
                                                //Available to sending WEIGH command.
//Start RPSUPOS-1629
const long NCRDIO_SCAL_ZERO           = 607;
//End RPSUPOS-1629
