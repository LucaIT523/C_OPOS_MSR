/////////////////////////////////////////////////////////////////////
//
// OposTot.h
//
//   Hard Totals header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 95-12-08 OPOS Release 1.0                                     CRM
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSTOT_H)
#define      OPOSTOT_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// "ResultCodeExtended" Property Constants for Hard Totals
/////////////////////////////////////////////////////////////////////

const LONG OPOS_ETOT_NOROOM     = 1 + OPOSERREXT; // Create, Write
const LONG OPOS_ETOT_VALIDATION = 2 + OPOSERREXT; // Read, Write


#endif                  // !defined(OPOSTOT_H)
