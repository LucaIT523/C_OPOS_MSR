/////////////////////////////////////////////////////////////////////
//
// OposMisc.h
//
//   Miscellaneous Lights Interface header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 00-03-31 OPOS Release 1.2                                     TPB
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSMISC_H)
#define      OPOSMISC_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// Indicator Constants
/////////////////////////////////////////////////////////////////////
// Media Entry Indicator 1 (MCRW Card Entry)
const LONG NCR_MISC_I_MEDIAINDICATOR1       = 1;

// Media Entry Indicator 2 (Depository/Cash Acceptor Entry)	
const LONG NCR_MISC_I_MEDIAINDICATOR2       = 2;	

// Media Entry Indicator 3 (Passbook/Coupon Entry)
const LONG NCR_MISC_I_MEDIAINDICATOR3       = 3;	

// Lane Light
const LONG NCR_MISC_I_INSERVICE             = 4;	
const LONG NCR_MISC_I_REMOTERELAY           = 4;	// Alias

//Remote Status Indicator 1 (green)
const LONG NCR_MISC_I_REMOTESTATUS1         = 5;

//Remote Status Indicator 2 (yellow)
const LONG NCR_MISC_I_REMOTESTATUS2         = 6;

//Remote Status Indicator 3 (red)
const LONG NCR_MISC_I_REMOTESTATUS3         = 7;

// Media Entry Indicator 4 (Coin Acceptor)
const LONG NCR_MISC_I_MEDIAINDICATOR4       = 8;

// Media Entry Indicator 5 (SCOT 2.0 Spare)
const LONG NCR_MISC_I_MEDIAINDICATOR5       = 9;

// Self Checkout Mode Light
const LONG NCR_MISC_I_SELFCHECKOUT_MODE     = 10;


/////////////////////////////////////////////////////////////////////
// Indicator State Constants
/////////////////////////////////////////////////////////////////////
// Indicator is OFF
const LONG NCR_MISC_ISTATE_OFF          	= 0;	

// Indicator is ON
const LONG NCR_MISC_ISTATE_ON           	= 1;	

// Indicator is blinking at 0.25 Hz.
const LONG NCR_MISC_ISTATE_QUARTER_HZ      	= 2;	

// Indicator is blinking at 0.5  Hz.
const LONG NCR_MISC_ISTATE_HALF_HZ         	= 3;	

// Indicator is blinking at 1.0  Hz.
const LONG NCR_MISC_ISTATE_ONE_HZ          	= 4;	

// Indicator is blinking at 2.0  Hz.
const LONG NCR_MISC_ISTATE_TWO_HZ          	= 5;	

// Indicator is blinking at 4.0  Hz.
const LONG NCR_MISC_ISTATE_FOUR_HZ          = 6;	


#endif                  // !defined(OPOSMISC_H)
