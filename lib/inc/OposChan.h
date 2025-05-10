/////////////////////////////////////////////////////////////////////
//
// OposChan.h
//
//   Cash Changer header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 97-06-04 OPOS Release 1.2                                     CRM
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSCHAN_H)
#define      OPOSCHAN_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// "DeviceStatus" and "FullStatus" Property Constants
// "StatusUpdateEvent" Event Constants
/////////////////////////////////////////////////////////////////////

const LONG CHAN_STATUS_OK       =  0; // DeviceStatus, FullStatus

const LONG CHAN_STATUS_EMPTY    = 11; // DeviceStatus, StatusUpdateEvent
const LONG CHAN_STATUS_NEAREMPTY= 12; // DeviceStatus, StatusUpdateEvent
const LONG CHAN_STATUS_EMPTYOK  = 13; // StatusUpdateEvent

const LONG CHAN_STATUS_FULL     = 21; // FullStatus, StatusUpdateEvent
const LONG CHAN_STATUS_NEARFULL = 22; // FullStatus, StatusUpdateEvent
const LONG CHAN_STATUS_FULLOK   = 23; // StatusUpdateEvent

const LONG CHAN_STATUS_JAM      = 31; // DeviceStatus, StatusUpdateEvent
const LONG CHAN_STATUS_JAMOK    = 32; // StatusUpdateEvent

const LONG CHAN_STATUS_ASYNC    = 91; // StatusUpdateEvent


/////////////////////////////////////////////////////////////////////
// "ResultCodeExtended" Property Constants for Cash Changer
/////////////////////////////////////////////////////////////////////

const LONG OPOS_ECHAN_OVERDISPENSE = 1 + OPOSERREXT;

#endif                  // !defined(OPOSCHAN_H)
