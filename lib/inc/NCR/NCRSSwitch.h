/////////////////////////////////////////////////////////////////////
//
// NCRSSWITCH.H
//
//   Supervisor Switch header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 97-22-04 OPOS Release 1.2                                  Ashish
// 97-19-12 Added PlatformStartWaitTime constants             Kiran (DL-NDF)
//
/////////////////////////////////////////////////////////////////////

#if !defined(NCRSSWITCH_H)
#define      NCRSSWITCH_H


#include "opos.h"
#include "oposlock.h"


const LONG NCR_ESSW		=1000;

/////////////////////////////////////////////////////////////////////
// "KeyPosition" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG SSWITCH_KP_NORM         = LOCK_KP_NORM;		// Normal Mode
const LONG SSWITCH_KP_SUPR         = LOCK_KP_SUPR;		// Supervisor Mode
const LONG SSWITCH_KP_LOCK         = LOCK_KP_LOCK;              // Locked Position
const LONG SSWITCH_KP_EXCP         = LOCK_KP_EXCP;              // Ex Position
const LONG SSWITCH_KP_UNKNOWN      = LOCK_KP_UNKNOWN;           // Unknown Position

const LONG SSWITCH_PC_NO_OF_POSITIONS   = 4;

///////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////
// PlatformStartWaitTime  Constants
////////////////////////////////////////////////////////////////////  
#define  ULY_STRT_TIME       _T("PlatformStartWaitTime") 
#define  ULY_STRT_TIMELEN    11

const LONG NCR_ESSW_ULY_NOSTART	  = NCR_ESSW + 1;





#endif                  // !defined(NCRSSWITCH_H)
