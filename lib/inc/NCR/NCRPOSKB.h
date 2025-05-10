/////////////////////////////////////////////////////////////////////
//
// NCRPOSKB.H
//
//   POS Keyboard header file for the NCR Applications.
//
//   Copyright (c) 1998 NCR.  All rights reserved.
//
// Modification history
// ------------------------------------------------------------------
// 05-20-96 NCR Release 1.0                                     HK
//
/////////////////////////////////////////////////////////////////////

//!!!!!!!!!!!!!!!!!!!!!!!!!!! ndj 9/19/00 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// NOTE: Any modifications made to this include file most also be made in
//       NCRPOSKB.bas !!  Do not check in your modified version of this file
//	 unless you are checking in NCRPOSKB.bas as well.

#include "opos.h"

/////////////////////////////////////////////////////////////////////
// "DirectIO" Command for POS Keyboard
/////////////////////////////////////////////////////////////////////
const long NCRDIO_POSKBD_SET_LEVEL	= 101;	// Set key intercept level

/////////////////////////////////////////////////////////////////////
// "ResultCodeExtended" Property Constants for POS Keyboard
/////////////////////////////////////////////////////////////////////
const long NCR_POSKBD_ERREXT_PARSE	= 101 + OPOSERREXT;	// parse error in Interception Table

/////////////////////////////////////////////////////////////////////
// "Interception" Level for POS Keyboard
/////////////////////////////////////////////////////////////////////
const long POSKBD_LEVEL_NONE	= 1;	// capture no keys
const long POSKBD_LEVEL_PARTIAL	= 2;	// Keys to be intercepted are defined in Registry
const long POSKBD_LEVEL_ALL	= 3;	// All keys are intercepted

/////////////////////////	End	/////////////////////////////