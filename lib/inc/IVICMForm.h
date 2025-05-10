/////////////////////////////////////////////////////////////////////
//
// IVICMForm.h
//
//   IVI Checkmate Form Control header file for OPOS Applications.
//   IVI Checkmate Form is an OPOS extension.
//
// Modification history
// ------------------------------------------------------------------
// 98-09-16 Release 1.0                                          DMJ
//
/////////////////////////////////////////////////////////////////////

#if !defined(IVICMFORM_H)
#define      IVICMFORM_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// Possible Form Data Event Statusses
//
// OnDataEvent for a form can have the following possibilities
//
//    Event.Status = 0;   // Complete event for a form without buttons
//    Event.Sataus = -1;  // Cancel event for a form without buttons
//    Event.Status = N;   // Button ID of the buttons pressed on the form
/////////////////////////////////////////////////////////////////////

const LONG IVICMFORM_FORM_COMPLETE   = 0;
const LONG IVICMFORM_FORM_CANCELED   = -1;

/////////////////////////////////////////////////////////////////////
// "CharacterSet" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG IVICMFORM_CS_ASCII        = 998;
const LONG IVICMFORM_CS_WINDOWS      = 999;


/////////////////////////////////////////////////////////////////////
// "DisplayTextAt" Method: "Attribute" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG IVICMFORM_DT_NORMAL          = 0;     // Default
const LONG IVICMFORM_DT_ITLCS           = 1;     // Italics
const LONG IVICMFORM_DT_UNDLN           = 2;     // Underline
const LONG IVICMFORM_DT_UNDLN_ITLCS     = 3;     // Underline and Itlaics
const LONG IVICMFORM_DT_RV_NORMAL       = 4;     // Reverse Video
const LONG IVICMFORM_DT_RV_ITLCS        = 5;     // Reverse Video Italics
const LONG IVICMFORM_DT_RV_UNDLN        = 6;     // Reverse Video Underline
const LONG IVICMFORM_DT_RV_UNDLN_ITLCS  = 7;     // Reverse Video Underline and Italics

#endif                  // !defined(IVICMFORM_H)
