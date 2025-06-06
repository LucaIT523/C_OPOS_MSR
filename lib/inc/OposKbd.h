/////////////////////////////////////////////////////////////////////
//
// OposKbd.h
//
//   POS Keyboard header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 96-04-22 OPOS Release 1.1                                     CRM
// 97-06-04 OPOS Release 1.2                                     CRM
//   Add "EventTypes" and "POSKeyEventType" values.
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSKBD_H)
#define      OPOSKBD_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// "EventTypes" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG KBD_ET_DOWN          =   1;
const LONG KBD_ET_DOWN_UP       =   2;


/////////////////////////////////////////////////////////////////////
// "POSKeyEventType" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG KBD_KET_KEYDOWN      =   1;
const LONG KBD_KET_KEYUP        =   2;


#endif                  // !defined(OPOSKBD_H)
