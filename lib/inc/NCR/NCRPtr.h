/*************************************************************************
 *
 * NCRPtr.h
 *
 *   Declares NCR-specific extensions to OPOSPtr.h.
 *
 *   Copyright (c) 1996 NCR.  All rights reserved.
 *
 * Author: C. Monroe 
 *
 *
 * $Workfile:: NCRPtr.h                                                  $
 *
 * $Revision:: 18                                                        $
 *
 * $Archive:: /OPOS/Rel.2_6/Include/NCR/NCRPtr.h                         $
 *
 * $Date:: 2/05/12 9:29p                                                 $
 *
 *************************************************************************
 * 
 * Copyright (c) NCR Corporation 1998.  All rights reserved.
 *
 *************************************************************************
 *
 * $History:: NCRPtr.h                                                   $
 * 
 * *****************  Version 18  *****************
 * User: Barlom       Date: 2/05/12    Time: 9:29p
 * Updated in $/OPOS/Rel.2_6/Include/NCR
 * New defines for QR barcode support TAR # 474308
 * 
 * *****************  Version 17  *****************
 * User: Barlom       Date: 9/08/11    Time: 9:04p
 * Updated in $/OPOS/Rel.2_6/Include/NCR
 * Changed value for PRTSTAT_HEAD_DOT_FAIL so it is not a FAULT.
 * TAR # 469456
 * 
 * *****************  Version 16  *****************
 * User: Barlom       Date: 8/27/11    Time: 9:33p
 * Updated in $/OPOS/Rel.2_6/Include/NCR
 * Initial check-in of changes to support new printers 7197-5xxx,
 * 7167-5xxx, and 7649-F301.
 * TAR # 468660
 * 
 * *****************  Version 15  *****************
 * User: Barlom       Date: 2/04/10    Time: 11:38a
 * Updated in $/OPOS/Rel.2_5/Include/NCR
 * TAR # 423498 - Added new error state PTRSTAT_WRONG_PAPER
 * 
 * *****************  Version 14  *****************
 * User: Barlom       Date: 6/15/09    Time: 4:51p
 * Updated in $/OPOS/Rel.2_5/Include/NCR
 * Added inline functions for numeric and string Pidx validation that had
 * been removed from standard code.
 * TAR # 407531
 * 
 * *****************  Version 13  *****************
 * User: Barlom       Date: 4/28/08    Time: 9:46a
 * Updated in $/OPOS/Rel.2_5/Include/NCR
 * Added constants to use for reducing number of ERROR to NORMAL event
 * logs. New constants are used to try and make certain printer has really
 * recovered.
 * TAR # 375910
 * 
 * *****************  Version 12  *****************
 * User: Barlom       Date: 9/27/07    Time: 5:27p
 * Updated in $/OPOS/Rel.2_5/Include/NCR
 * Added definitions for 2ST Paper Detect Direct I/O Command and Event.
 * TAR # 359896
 * 
 * *****************  Version 10  *****************
 * User: Barlom       Date: 4/27/06    Time: 6:16p
 * Updated in $/OPOS/Rel.2_5/Include/NCR
 * Initial check-in of changes to support 7168 2ST printer.
 * Added new NCR proprietary error NCR_EPTR_2ST_MODE
 * 
 * *****************  Version 9  *****************
 * User: Barlom       Date: 10/02/04   Time: 12:36a
 * Updated in $/OPOS/Rel.2_4/include/ncr
 * Added constant for NCR_CHK_DOC_HEIGHT_AUTOSIZE.
 * RFC TAR # 281958
 * 
 * *****************  Version 8  *****************
 * User: Barlom       Date: 9/12/03    Time: 11:45p
 * Updated in $/OPOS/Rel.2_4/Include/NCR
 * Initial Check-In of changes for implementation of new Check Scanner
 * device class.
 * 
 * *****************  Version 5  *****************
 * User: Barlom       Date: 5/02/02    Time: 10:33p
 * Updated in $/OPOS/Rel.2_2/include/ncr
 * Added registry DirectIO parameters PTR_PARAM_SlipStopEOF and
 * PTR_PARAM_PrintIntegrityMode.  TAR # 203390
 * 
 * *****************  Version 4  *****************
 * User: Barlom       Date: 2/26/02    Time: 2:48p
 * Updated in $/OPOS/Rel.2_2/Include/NCR
 * Added new parameter PTR_PARAM_IgnorePIPError for
 * NCRDIO_PTR_SET_REG_PARAM.  This is for Workaround to SCOT PIP Issue
 * which is associated with TAR # 195052.
 * 
 * *****************  Version 3  *****************
 * User: Barlom       Date: 1/15/02    Time: 6:49p
 * Updated in $/OPOS/Rel.2_2/include/ncr
 * Added NCRDIO_PTR_SET_COLOR_PAPER and PTR_PARAM_ColorPaper to Direct I/O
 * Method to allow user to change Registry Setting and Color Paper usage
 * on the fly for 7167 and 7197 printers.
 * 
 * *****************  Version 2  *****************
 * User: Barlom       Date: 1/15/02    Time: 11:44a
 * Updated in $/OPOS/Rel.2_2/include/ncr
 * Added definitions for Direct I/O calls to allow changing K590
 * m_bUseSoftOptions, m_nRecRetainLength, m_nMinRecLength, and to allow
 * modification of Registry entries for these and other K590 Registry
 * Keys.  RFC TAR # 192050
 * 
 * *****************  Version 38  *****************
 * User: Dm150011     Date: 7/09/01    Time: 12:31p
 * Updated in $/OPOS/Rel.2_1/Include/NCR
 * Added NCR_EMICR_COVER_OPEN
 * 
 * *****************  Version 37  *****************
 * User: Barlom       Date: 5/16/01    Time: 9:38p
 * Updated in $/OPOS/Rel.2_1/include/ncr
 * Added new Direct I/O commands of NCRDIO_PTR_SET_PAPER_LOW and
 * NCRDIO_PTR_SET_BLACK_MARK to allow dynamic setting of these printer
 * options by the application.  Also added new registry overrides to the
 * NCRDIO_PTR_SET_REG_PARAM.  These overrides are for registry keys of
 * EjectOnEnable, EjectAdjustmentTime, and KnifeCutAdjustmentTime.  See
 * TARs # 171573, 127785, and 172118 for some additional details.
 * 
 * *****************  Version 35  *****************
 * User: Wm151001     Date: 9/27/00    Time: 2:52p
 * Updated in $/OPOS/Rel.2_0/Include/NCR
 * Add  const long  NCRDIO_PTR_SET_USERCHAR = 118
 * 
 * *****************  Version 32  *****************
 * User: Barlom       Date: 7/15/00    Time: 9:31p
 * Updated in $/OPOS/Rel.1_8/include/ncr
 * Final changes for initial release of K585 printer.
 * 
 * *****************  Version 31  *****************
 * User: Barlom       Date: 6/09/00    Time: 12:08a
 * Updated in $/OPOS/Rel.1_8/include/ncr
 * Added the following constants to support new event logging to support
 * the SNMP Agent.  Definitions are bracketed by comments containing TAR #
 * 143376
 * PTRSTAT_NEED_EVENT_PPS,PTRSTAT_NEED_EVENT_CDC,PTRSTAT_NEED_EVENT_RPOK,P
 * TRSTAT_NEED_EVENT_ARC,PTRSTAT_NEED_CLEAR_ARC
 * 
 * *****************  Version 30  *****************
 * User: Barlom       Date: 5/03/00    Time: 6:20p
 * Updated in $/OPOS/Rel.1_8/include/ncr
 * Added parameters of PTR_PARAM_PreEjectDelay and
 * PTR_PARAM_PostEjectDelay to the NCRDIO_PTR_SET_REG_PARAM
 * Direct I/O function to allow the application to override the
 * PreEjectDelay and PostEjectDelay registry settings.  Change for RFC TAR
 * # 140000.
 * 
 * *****************  Version 28  *****************
 * User: Dw160003     Date: 11/09/99   Time: 11:27a
 * Updated in $/OPOS/Rel.1_7/Include/NCR
 * added VSS headers
 * 
 * *****************  Version 1  *****************
 * User: Monroec       Date: 8/28/96    Time: 10:01a
 * Created in $/OPOS/Rel.1_4/Include/NCR
 * 
 * *****************  Version 2  *****************
 * User: Monroec       Date: 2/12/97    Time: 10:01a
 * Updated for NCR OPOS Release 1.1
 * 
 *
 ************************************************************************/

#ifndef _NCRPTR_H_
#define _NCRPTR_H_


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// ResultCodeExtended values:
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
//
// NCR-specific statuses are returned in the "ResultCodeExtended" property.
//   (Per the OPOS spec, a vendor may do this when "ResultCode" is not OPOS_E_EXTENDED.)
//
//***************************************************************************
//
// If "ResultCodeExtended" bitwise ANDed (&) with PTRSTAT_FLAG is non-zero
//   (that is, the bit PTRSTAT_FLAG is on), then "ResultCodeExtended" contains
//   a series of bits that represent the current printer status.
// The printer status also may be queried at any time by using the DirectIO
//   command "GetPrinterStatus".
// The following device status constants define those bits:
//
//             *** Printer Status ***

const int PTRSTAT_FLAG          = 0x80000000; // (Always on.)

const int PTRSTAT_ALL           = 0x3FFFFFFF; // All statuses.
const int PTRSTAT_STATE         = 0x00000003; // All state flags.
const int PTRSTAT_PRINTER       = 0x0FFFFFF0; // All printer statuses.
const int PTRSTAT_PRINTER_FAULT = 0x0FF00000; // All printer faults/failures.
const int PTRSTAT_DRAWER        = 0x30000000; // All drawer statuses.

// Printer states.
const int PTRSTAT_OFF_STATE     = 0x00000001; // Printer is off.
const int PTRSTAT_ERROR_STATE   = 0x00000002; // Printer is in error: Not accepting requests.
const int PTRSTAT_HEAD_DOT_FAIL = 0x00000004; // TAR # 468660 -- Failure of Dot Head Element -- TAR # 469456 -- Made into a Warning

// OPOS printer sensor values.
const int PTRSTAT_COVER_OPEN    = 0x00000010; // Cover or door open.
const int PTRSTAT_JRN_EMPTY     = 0x00000040; // Journal out.
const int PTRSTAT_JRN_NEAREND   = 0x00000080; // Journal low.
const int PTRSTAT_REC_EMPTY     = 0x00000100; // Receipt out.
const int PTRSTAT_REC_NEAREND   = 0x00000200; // Receipt low.
const int PTRSTAT_SLP_EMPTY     = 0x00000400; // Slip leading edge sensor: no paper.
const int PTRSTAT_SLP_NEAREND   = 0x00000800; // Slip trailing edge sensor: no paper.

// Printer slip sensor values: May not match OPOS values due to differences in
//   what the printer reports.
const int PTRSTAT_SLP_TOF       = 0x00001000; // Slip top of form sensor on.
const int PTRSTAT_SLP_BOF       = 0x00002000; // Slip bottom of form sensor on.

// Printer states only available when real-time commands are supported.
const int PTRSTAT_SLP_SELECTED  = 0x00010000; // Slip selected.
const int PTRSTAT_SLP_WAITING   = 0x00020000; // Printer waiting for insertion.

// Printer failure conditions. Support varies by printer.
const int PTRSTAT_AUTORECOVER_FAULT           // Auto-recoverable fault, such as
                                = 0x00100000; //   temperature fault.
const int PTRSTAT_MOTOR_FAULT   = 0x00200000; // Motor fault.
const int PTRSTAT_KNIFE_FAULT   = 0x00400000; // Knife fault.
const int PTRSTAT_FAULT         = 0x00800000; // General fault.
const int PTRSTAT_FAILURE       = 0x01000000; // Unrecoverable error.
const int PTRSTAT_WRONG_PAPER	= 0x02000000; // TAR # 423498 -- Status for Wrong Paper in Label Printer


// Drawer states.
const int PTRSTAT_DWR1_OPEN     = 0x10000000; // Drawer 1 open.
const int PTRSTAT_DWR2_OPEN     = 0x20000000; // Drawer 2 open.


const int PTRSTAT_DWR_SHIFT     = 27;         // Bit shift count to get drawer statuses to
                                              //   low bits: Bit 1 for drawer 1; 2 for 2.

// Self-Service Printer specific device status values
const int PTRSTAT_PPS_EMPTY     = 0x00000001; // Receipt Presenter Paper Sensor
const int PTRSTAT_PO_ROTATED    = 0x00000002; // Receipt Presenter Mechanism Orientation
const int PTRSTAT_CPC_EMPTY     = 0x00000004; // Kiosk Paper Chute
const int PTRSTAT_PTR_RESET     = 0x00000008; // Reset Button Pressed
const int PTRSTAT_PRESENTER_ERR = 0x00000010; // Receipt Presenter Error
const int PTRSTAT_PAPER_JAM     = 0x00000020; // Paper failed to feed properly Jam assumed
const int PTRSTAT_CDS_OPEN		= 0x00000040; // Kiosk Cabinet Door Open
const int PTRSTAT_BMD_FAILURE   = 0x00000080; // Black mark detect failure
const int PTRSTAT_HEAD_FAILURE  = 0x00000100; // Thermal Print Head Mechanism Failure

const int PTRSTAT_REC_DROPPED   = 0x10000000; // Receipt was dropped on K585 printer

const int PTRSTAT_KNIFE_CUT     = 0x80000000; // A Knife Cut has been issued.

// Start changes for TAR # 143376
// Added below to support SNMP Agent changes.  These flags are maintained in
// the m_nEventFlags member variable and are used to determine if we need to
// send an event indicating a recovery from an error.
const int PTRSTAT_NEED_EVENT_PPS= 0x00000001; // Need to issue event presenter is clear
const int PTRSTAT_NEED_EVENT_CDC= 0x00000002; // Need to issue event clamshell door closed
const int PTRSTAT_NEED_EVENT_RPOK=0x00000004; // Need to issue event receipt paper OK
const int PTRSTAT_NEED_EVENT_ARC= 0x00000008; // Need to issue event thermal head auto recover state
const int PTRSTAT_NEED_CLEAR_ARC= 0x00000010; // Need to issue clear log for thermal event
// Added for TAR # 375910
const int PTRSTAT_NEED_ERRTO_NORM=0x00000020; // Need to fire an Error to Normal Event
// End changes for TAR # 143376

// Start changes for TAR # 375910
// These values are used internally with m_nRecover_Event to make certain we don't 
// first an Error to Normal event too soon.
const int FSM_OK_TO_RECOVER = 0;
const int FSM_WAIT_FOR_PAPER_AT_PRESENTER = 2;  
// End changes for TAR # 375910

// TAR # 468660 -- Barcode values for NCR OPOS 2.x using same values as OPOS 1.12, but
//           we are only officially 1.7 compliant, so define our own lablels
//    - One dimensional symbologies (added in 1.12)
const LONG NCR_PTR_BCS_GS1DATABAR    =131;  // GS1 DataBar Omnidirectional
const LONG NCR_PTR_BCS_GS1DATABAR_E  =132;  // GS1 DataBar Expanded
const LONG NCR_PTR_BCS_GS1DATABAR_S  =133;  // GS1 DataBar Stacked Omnidirectional
const LONG NCR_PTR_BCS_GS1DATABAR_E_S=134;  // GS1 DataBar Expanded Stacked

// 7197R2 -- Additional GS1 not in UnifiedPOS 1.12, but supported by printer
const LONG NCR_PTR_BCS_GS1DATABAR_TRUNC		= 520; // GS1 DataBar Truncated
const LONG NCR_PTR_BCS_GS1DATABAR_LIMITED	= 521; // GS1 DataBar Limited
const LONG NCR_PTR_BCS_GS1DATABAR_STACK		= 522; // GS1 DataBar Stacked ( not Omnidirectional )


// TAR # 474308 -- QR Barcode values for NCR OPOS 2.x using the same values as OPOS 1.12, but
//             we are only officially 1.7 compliant, so defin our own labels
const LONG NCR_PTR_BCS_QRCODE		=204; // QR Barcode
const LONG NCR_PTR_BCS_UQRCODE		=205; // Micro QR Barcode



//***************************************************************************
//
// If "ResultCodeExtended" bitwise ANDed (&) with PTRSTAT_FLAG is zero
//   (that is, the bit PTRSTAT_FLAG is off), then "ResultCodeExtended" contains
//   an NCR-specific error status to clarify the error.

const LONG NCR_EPTR = 10000;

//---------------------------------------------------------------------------
//--- Statuses for any device ---
//---------------------------------------------------------------------------

// - Software failure detected.
const LONG NCR_EPTR_SWFAIL              =   1 + NCR_EPTR;

// - Set DeviceEnabled errors:
//      Could not get access to the COM port.
//      Either it is not a valid port, or some other application has it opened.
const LONG NCR_EPTR_DE_PORTOPEN         =   2 + NCR_EPTR;

//---------------------------------------------------------------------------
//--- POSPrinter Statuses ---
//---------------------------------------------------------------------------

// - General errors:
//      Bad station: Illegal value or doesn't exist.
const LONG NCR_EPTR_STATION             = 101 + NCR_EPTR;
//      Station does not have capability for requested action.
const LONG NCR_EPTR_NOCAP               = 102 + NCR_EPTR;
//      Station is in rotated mode: Action not allowed.
const LONG NCR_EPTR_ROTATEMODE          = 103 + NCR_EPTR;
//      Station does not support selected BarCode rotation
const LONG NCR_EPTR_BAD_ROTATESPECIAL	= 104 + NCR_EPTR;


// - CutPaper errors:
//      Percentage parameter invalid.
const LONG NCR_EPTR_CP_PERCENTAGE       = 111 + NCR_EPTR;

// - Bar code errors:
//      Bad symbology: Not supported by printer.
const LONG NCR_EPTR_BC_SYMBOLOGY        = 121 + NCR_EPTR;
//      Bad height: Height <= zero.
//        (If bigger than supported by printer, is set to printer's maximum.)
const LONG NCR_EPTR_BC_HEIGHT           = 122 + NCR_EPTR;
//      Bad alignment: Illegal value.
const LONG NCR_EPTR_BC_ALIGNMENT        = 123 + NCR_EPTR;
//      Bad textposition: Illegal value.
const LONG NCR_EPTR_BC_TEXTPOSITION     = 124 + NCR_EPTR;

// - Bitmap errors (PrintBitmap and SetBitmap):
const LONG NCR_EPTR_BM_BITMAPNUMBER     = 131 + NCR_EPTR; // SetBitmap only.
//      Bad width: Zero or too wide.
const LONG NCR_EPTR_BM_WIDTH            = 132 + NCR_EPTR; // Set & Print.
//      Bad alignment: Bad constant, or positive value+bitmap width too wide.
const LONG NCR_EPTR_BM_ALIGNMENT        = 133 + NCR_EPTR; // Set & Print.
//      Bad bitmap mode: Cannot use current bitmap type to print bitmap.
//        (See "Bitmap Printing Types" below for more information.)
const LONG NCR_EPTR_BM_BITMAPTYPE       = 134 + NCR_EPTR; // Set & Print.

// - Rotation errors:
//      "Normal" rotation specified while not in rotated print mode.
const LONG NCR_EPTR_RP_NOTROTATEMODE    = 141 + NCR_EPTR;
//      Bad rotation: Illegal constant.
const LONG NCR_EPTR_RP_ROTATION         = 142 + NCR_EPTR;

// - Transaction errors:
//      Start transaction requested while already in a transaction.
const LONG NCR_EPTR_TP_TRANSMODE        = 151 + NCR_EPTR;
//      End transaction requested while not in a transaction.
const LONG NCR_EPTR_TP_NOTTRANSMODE     = 152 + NCR_EPTR;
//      Bad control: Illegal value.
const LONG NCR_EPTR_TP_CONTROL          = 153 + NCR_EPTR;


// - Self Service Printer Errors:
//		Receipt Presenter not ready to start next transaction.
const LONG NCR_EPTR_RPM_NOT_READY		= 154 + NCR_EPTR;
//		Cabinet door on Kiosk open unable to print.
const LONG NCR_EPTR_CDS_DOOR_OPEN		= 155 + NCR_EPTR;
// Below added for TAR # 116827
//		Presenter Mechanism Error
const LONG NCR_EPTR_RPM_MECH_ERROR		= 156 + NCR_EPTR;
//		Presenter Paper Jam
const LONG NCR_EPTR_RPM_PAPER_JAM		= 157 + NCR_EPTR;
//		Presenter Black Mark Failure
const LONG NCR_EPTR_RPM_BLACK_MARK		= 158 + NCR_EPTR;
//		Print Head Failure
const LONG NCR_EPTR_PRINT_HEAD_FAILURE  = 159 + NCR_EPTR;


// - 2 Sided Thermal Errors
//      Operation only allowed in Transaction Mode if in a 2ST Mode
const LONG NCR_EPTR_2ST_MODE			= 170 + NCR_EPTR;


// - QR Barcode Error Values -- TAR # 474308
const LONG NCR_EPTR_QR_ERRLVL_NOTVALID		= 180 + NCR_EPTR;
const LONG NCR_EPTR_QR_INVALID_BARCODE_DATA	= 181 + NCR_EPTR;
const LONG NCR_EPTR_QR_TOO_MANY_CHARACTERS	= 182 + NCR_EPTR;


//---------------------------------------------------------------------------
//--- Micr Statuses ---
//---------------------------------------------------------------------------

// - Read Micr data errors:
//      Line error during read: Parity, overrun, framing.
const LONG NCR_EMICR_LINE_ERROR          = 201 + NCR_EPTR; 
//      Check not present.
const LONG NCR_EMICR_NOCHECK             = 202 + NCR_EPTR;
//      Check contains no Micr data.
const LONG NCR_EMICR_NO_DATA             = 203 + NCR_EPTR;
//      Received data but some characters were not read successfully.
const LONG NCR_EMICR_BAD_DATA            = 204 + NCR_EPTR; 
//      Check jammed during read.
const LONG NCR_EMICR_CHECKJAM            = 205 + NCR_EPTR;
//		MICR Cover Open
const LONG NCR_EMICR_COVER_OPEN			 = 206 + NCR_EPTR;


//---------------------------------------------------------------------------
//--- Check Scanner Statuses ---
//---------------------------------------------------------------------------

// - Scan Check data errors:
//	Line error during read: Parity, overrun, framing.
const LONG NCR_ECHK_LINE_ERROR			 = 301 + NCR_EPTR;
// - Check Scanner Cover Open
const LONG NCR_ECHK_COVER_OPEN			 = 302 + NCR_EPTR;


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// NCR value-add extensions via DirectIO.
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------
//--- POSPrinter DirectIO ---
//---------------------------------------------------------------------------

//** SetBitmapType **  Set the bitmap type for bitmap printing.
//                     (See details below in "Bitmap Printing Types".)
//    Data:       In > New bitmap type value.
//                Out> Previous bitmap type value.
//    String:     (Not used.)
//    ResultCode: OPOS_SUCCESS   = Set successfully.
//                OPOS_E_ILLEGAL = Bad bitmap type.
const LONG NCRDIO_PTR_SET_BITMAP_TYPE = 101;

// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

//** SetBarcodeWidth **  Set the minimum width of barcode bars.
//    Data:       In > New minimum bar width in dots.
//                Out> Previous width.
//    String:     (Not used.)
//    ResultCode: OPOS_SUCCESS   = Set successfully.
//                OPOS_E_ILLEGAL = Bad width.
const LONG NCRDIO_PTR_SET_BARCODE_WIDTH = 102;

// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

//** SoundAudibleTone **  Generate an audible tone from the printer.
//    Data:       In > Repeat count (range 1 - 20).
//    String:     (Not used.)
//    ResultCode: OPOS_SUCCESS   = Successful.
//                OPOS_E_ILLEGAL = Printer cannot generate sounds.
//                -other-        = Error occurred, such as printer not claimed
//                                   or enabled, or printer off.
const LONG NCRDIO_PTR_SOUND_AUDIBLE_TONE = 103;

// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

//** SetMinLineCharsMode **  Set the mode for the printer station so that it
//                           supports at least this number of characters.
//                           When XxxLineChars is set, the mode will be set
//                           to the minimum of the XxxLineChars value and this
//                           value.
//    Data:       In > High Word (b.31-16) = Station (PTR_S_...).
//                     Low  Word (b.15-00) = Minimum line character value.
//                       Set to zero for default handling.
//                Out> Previous value (if printer claimed & enabled and station
//                       is valid).
//    String:     (Not used.)
//    ResultCode: OPOS_SUCCESS   = Successful.
//                OPOS_E_ILLEGAL = Printer station cannot support this value.
//                -other-        = Error occurred, such as printer not claimed
//                                   or enabled, or bad station.
const LONG NCRDIO_PTR_SET_MIN_LINE_CHARS_MODE = 104;

// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

//** GetPrinterStatus **  Get the printer status.
//    Data:       Out> Current printer status.
//    String:     (Not used.)
//    ResultCode: OPOS_SUCCESS   = Successful.
//                -other-        = Printer not claimed or enabled.
const LONG NCRDIO_PTR_GET_PRINTER_STATUS = 105;

// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

//** RawOutput **  Pass application data directly to the printer with
//                       no parsing or modification.
//    Data:       In > Station for output.
//    String:     In > Data to send to printer.
//    ResultCode: OPOS_SUCCESS   = Set successfully.
//                Other values   = See ResultCode property.
const LONG NCRDIO_PTR_RAW_OUTPUT = 106;

// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

//** SlipFlip **  Initiate a Slip Flipping Sequence on the Printer.
//                    This tell the printer to active the flip mechanism.   
//    Data:       In > Not Used
//    String:     In > Not Used
//    ResultCode: OPOS_SUCCESS   = Slip Flip Sequence was successful.
//                Other values   = See ResultCode property.
const LONG NCRDIO_PTR_SLIP_FLIP = 107;

//#if defined( JAPAN )	// 12/98 - This directive can be deleted.
// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

//** SetUserDefinedKanjiChar **  Set the User-Defined Kanji character.
//    Data:       In > High Word (b.31-16) = Station (PTR_S_...).
//                     Low  Word (b.15-00) = character codes.
//                         FFxx -> character codes for the defined characters
//                                   for the first byte.
//                         xxFF -> character codes for the defined characters
//                                   for the second byte.
//    String:     In > Data to send to printer.
//    ResultCode: OPOS_SUCCESS   = Successful.
//                OPOS_E_ILLEGAL = Printer does not support.
//                -other-        = Error occurred, such as printer not claimed
//                                   or enabled, or printer off.
const LONG NCRDIO_PTR_SET_UD_KANJI_CHAR = 108;
//#endif				// 12/98 - This directive can be deleted.

// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

//** SensorStatus **  Check one of the proprietary sensors for its current value
//
//    Data:       In > Parameter to select sensor to report.
//                Out> Value indicating the current state of the sensor.
//    String:     In > (Not used.)
//    ResultCode: OPOS_SUCCESS   = Returned current value for sensor in Data.
//                OPOS_E_ILLEGAL = Specified Sensor not support by printer.
const LONG NCRDIO_PTR_SENSOR_STATUS = 109;
//
//  Parameter constants are:
//
//  -- CabinetDoorSwitch --
//
const LONG PTR_Cabinet_Door_Switch                = 0x00100000;
//   -- Parameter return values indicating current status --
const LONG PTR_CDS_Door_Open					  = 0x00100001;
const LONG PTR_CDS_Door_Closed					  = 0x00100002;
//
//  -- PresenterPaperSensor --
//
const LONG PTR_Presenter_Paper_Sensor             = 0x00200000;
//   -- Parameter return values indicating current status --
const LONG PTR_PPS_Paper_Present				  = 0x00200001;
const LONG PTR_PPS_No_Paper 					  = 0x00200002;
//
//  -- CabinetPaperChute --
//
const LONG PTR_Cabinet_Paper_Chute                = 0x00400000;
//   -- Parameter return values indicating current status --
const LONG PTR_CPC_Paper_Present				  = 0x00400001;
const LONG PTR_CPC_No_Paper 					  = 0x00400002;
//
//  -- PresenterOrientation --
//
const LONG PTR_Presenter_Orientation			  = 0x00800000;
//
//   -- Parameter return values indicating current status --
const LONG PTR_PO_Rotated_90					  = 0x00800001;
const LONG PTR_PO_Normal						  = 0x00800002;

// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

// Start A225 Change 5-21-1999

//** AutoEjectTimeout **  Set the Auto Eject Time-Out value in the 7401-K580.
//                   This time-out is the delay between the time a receipt is
//					 presented, and it is auto ejected onto the floor.   
//    Data:       In > Time-Out period
//				  OPOS_FOREVER - Infinite no time-out
//				  One of 20, 40, 60, or 80 seconds in decimal.
//    String:     In > Not Used
//    ResultCode: OPOS_SUCCESS   = Time-out value set to specified value.
//                OPOS_E_ILLEGAL = An invalid time-out period value was passed.
const LONG NCRDIO_PTR_AUTOEJECT_TIMEOUT = 110;

// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

//** EjectReceipt **  Initiate a Receipt Eject Sequence from a 7401-K580
//                    printer.  Ejects Receipt from the presenter mechanism.   
//    Data:       In > Not Used
//    String:     In > Not Used
//    ResultCode: OPOS_SUCCESS   = Eject successfully transmitted to printer.
//                Other values   = See ResultCode property.
const LONG NCRDIO_PTR_EJECT_RECEIPT = 111;

// End A225 Changes 5-21-1999

// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

// Add 7196-4205/3205 - Start

//** 7196SetStamp  Set stamp data for 7196-4205/3205.
//    Data:       (Not used.)
//    String:     In > Path of a bitmap file which represents stamp
//    ResultCode: OPOS_SUCCESS   = Set successfully.
//                OPOS_E_ILLEGAL = Bad path or not a 416 x 160 mono color BMP file.
//                OPOS_E_FAILURE = not a 416 x 160 mono color BMP file
const LONG NCRDIO_PTR_7196_SET_STAMP = 112;

// Add 7196-4205/3205 - End

//RPSUPOS-1087 Start
// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

//** RawOutIn **  Pass application data directly to the printer with
//                       no parsing or modification.
//    Data:       In/Out > In:Expected bytes for output, Out:Lentgh of the Response in bytes
//    String:     In/out > Data to send to printer, Out:Data to received from printer
//    ResultCode: OPOS_SUCCESS   = Set successfully.
//                Other values   = See ResultCode property.
const LONG NCRDIO_PTR_RAW_OUTIN = 114;
//End RPSUPOS-1087
// Start Wal-Mart change 08-03-1999 TAR # 116776
// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

//** GetKioskStatus **  Get the Kiosk specific status bits.
//    Data:       Out> Current kiosk status bits.
//    String:     (Not used.)
//    ResultCode: OPOS_SUCCESS   = Successful.
//                -other-        = Printer not claimed or enabled.
const LONG NCRDIO_PTR_GET_KIOSK_STATUS = 116;

//EuroSymbol
const LONG  NCRDIO_PTR_SET_USERD_CHAR  = 118; 

// End Wal-Mart change 08-03-1999


//** 2STPaperType **  Return current 2ST paper type if known
//
//    Data:       In > pointer to LONG for return value
//                Out> LONG pointed to indicates paper type
//						PTR_2ST_PAPER_UNKNOWN -- Paper Type is not yet determined
//						PTR_2ST_PAPER_SINGLE -- Single Sided paper roll installed
//						PTR_2ST_DOUBLE -- Double Sided paper roll installed
//    String:     In > (Not used.)
//    ResultCode: OPOS_SUCCESS   = Returned current paper type or unknown
//                OPOS_E_ILLEGAL = The printer does not support 2ST Paper Type or
//									the functionality is not enabled.
const LONG NCRDIO_PTR_2ST_PAPER_TYPE = 122;
//
//  Parameter constants are:
//
//  -- values indicating paper type --
//
const LONG PTR_2ST_PAPER_UNKNOWN                  = 0x00000000;
const LONG PTR_2ST_PAPER_SINGLE					  = 0x00000001;
const LONG PTR_2ST_PAPER_DOUBLE					  = 0x00000002;


//** SetPaperLow **   Send Paper Low Sensor Configuration Command to K590 printer.   
//    Data:       In > Paper Low Sensor Usage
//                     0 - Paper Low Detection Set for 50ft
//					   1 - Paper Low Detection Set for 10ft
//					   2 - Paper Low Disabled
//    String:     In > Not Used
//    ResultCode: OPOS_SUCCESS   = Paper Low Option Successfully sent to printer.
//                OPOS_E_ILLEGAL = Command not valid for current printer, or
//                                 parameter value out of range.
//                Other values   = See ResultCode property.
const LONG  NCRDIO_PTR_SET_PAPER_LOW   = 126;

//** SetBlackMark **   Send Black Mark Configuration Command to K590 printer.   
//    Data:       In > Black Mark Option Usage
//                     0 - Document Mode (Ignore Black Mark)
//					   1 - Normal Mode (Cut at first black mark beyond printing)
//					   2 - Advance Mode (Cut at 2nd black mark beyond printing)
//    String:     In > Not Used
//    ResultCode: OPOS_SUCCESS   = Black Mark Option Successfully sent to printer.
//                OPOS_E_ILLEGAL = Command not valid for current printer, or
//                                 parameter value out of range.
//                Other values   = See ResultCode property.
const LONG  NCRDIO_PTR_SET_BLACK_MARK  = 127;

// Start added commands for TAR # 192050
//** SetMinimumReceiptLength **   Send command to set minimum receipt length to K590.   
//    Data:       In > Minimum Receipt Length Option
//                     1 - 90mm 
//					   2 - 111mm
//					   3 - 150mm
//					   4 - 225mm
//					   5 - 300mm
//					   6 - 375mm
//					   7 - 450mm
//					   8 - 525mm
//					   9 - 600mm
//    String:     In > Not Used
//    ResultCode: OPOS_SUCCESS   = New Minimum Receipt Length sent to the printer
//									if the m_bUseSoftOptions flag is TRUE.
//                OPOS_E_ILLEGAL = Command not valid for current printer, or
//                                 parameter value out of range.
//                Other values   = See ResultCode property.
const LONG	NCRDIO_PTR_SET_MINIMUM_REC_LEN = 130;

//** SetReceiptRetainLength **   Send command to set receipt retain length to K590 printer.   
//    Data:       In > Receipt Retain Length Option
//                     1 - 25mm
//					   2 - 50mm
//					   3 - 75mm
//    String:     In > Not Used
//    ResultCode: OPOS_SUCCESS   = New Receipt Retain Length sent to the printer
//									if the m_bUseSoftOptions flag is TRUE.
//                OPOS_E_ILLEGAL = Command not valid for current printer, or
//                                 parameter value out of range.
//                Other values   = See ResultCode property.
const LONG	NCRDIO_PTR_SET_REC_RETAIN_LEN = 131;

//** SetColorPaper **   Send command to set the type of Color Thermal paper in the printer.   
//    Data:       In > Color Paper Type
//                     1 - Monochrome
//					   2 - Two Color
//    String:     In > Not Used
//    ResultCode: OPOS_SUCCESS   = New Color Paper type sent to the printer
//                OPOS_E_ILLEGAL = Command not valid for current printer, or
//                                 parameter value out of range.
//                Other values   = See ResultCode property.
const LONG	NCRDIO_PTR_SET_COLOR_PAPER = 132;

// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

//** SetRegParam **  Set or change a parameter that may be initialized by
//                   the system registry.
//    Data:       In > ParameterConstant + New value.
//                Out> Previous value.
//    String:     (Not used.)
//    ResultCode: OPOS_SUCCESS   = Set successfully.
//                OPOS_E_ILLEGAL = Bad parameter constant or value.
const LONG NCRDIO_PTR_SET_REG_PARAM = 151;

//  Parameter constants are:

//  --AsyncBlockSize--
//      Async requests per block: 1 or more (Default = 10)
//        Up to this number of async requests are printed before a status request
//        is sent to the printer.  If an error occurs, then a retry will reprint
//        all requests in the current block.
//        * Set to a low number to reduce the lines reprinted on an error retry.
//        * Set to a higher number for better performance (especially with
//           thermal printers). This removes the extra time required for each
//           status request.
const LONG PTR_PARAM_AsyncBlockSize             = 0x11000000;

//  --AsyncBlockStatusTimeout--
//      Max time after async request before end-of-block: 50 - 10000 ms
//      (Default = 200 ms)
//        When the last enqueued async request is sent to the printer and a status
//        request has not been enqueued (because the AsyncBlockSize limit has not
//        been reached), then wait AsyncBlockStatusTimeout ms before sending a
//        status request.
//        * Set to a low number when you want an OutputComplete response as soon
//           as possible. Since a smaller number causes the status to be requested
//           soon after the last request in a series of requests from the app, then
//           the completion or error event will be delivered a little sooner.
//        * Set to a higher number when the app is slower in delivering a series
//           of requests. When too low, extra status requests will be made between
//           print requests, adding some time.
//        -> The best setting for this parameter may require some testing.
const LONG PTR_PARAM_AsyncBlockStatusTimeout    = 0x12000000;

//  --AutoLineFeed--
//      Print at end of each request: 1 = True or 0 = False (Default = False)
//        If some printable characters have not been printed because the request
//        does not end with a CarriageReturn or LineFeed, then the default and
//        OPOS-compliant behavior is to remember these characters and append
//        characters from later requests to form print lines.
//        Usually, however, an application will want each print request to cause
//        a line to be printed.
//        * Set to False for the default handling.
//        * Set to True to cause a LineFeed to be automatically appended at the
//           end of a request if some printable characters are still present.
const LONG PTR_PARAM_AutoLineFeed               = 0x13000000;

//  --SlipToTopOfForm--
//      [Parameter specific to 7156. (The 7152 always automatically is True.)]
//      At Printer "EndInsertion", reposition the form so that the first print
//      line is about 5mm from the top of the form.
//        * Set to True to perform the repositioning.
//            If the form is inserted from the side above the slip stop, then
//            the form will reverse feed, wait 400ms, and forward feed to its
//            original position.
//        * Set to False to bypass positioning.
//            If the form is inserted to the slip stop, then the first print line
//              is about 16mm from the top of the form.
const LONG PTR_PARAM_SlipToTopOfForm            = 0x14000000;

//  --SlipInSettleTime--
//      BeginInsertion time in ms that slip-in status must be stable: 0 - 10000
//      (Default = 500 ms)
//        During BeginInsertion, if the slip is not initially present but is
//        inserted during the timeout period, then the slip in sensor must
//        remain on for this period of time before a successful status is returned.
//        * Set higher if operators have difficulty properly positioning the slip
//           before the rolls close.
//        * Set lower if operators position the slip correctly and wait too long
//           before the slip rolls close.
const LONG PTR_PARAM_SlipInSettleTime           = 0x15000000;

//  --SlipOutSettleTime--
//      BeginRemoval time in ms that slip-out status must be stable: 0 - 10000
//      (Default = 500 ms)
//        During BeginRemoval, if the slip is not initially removed but is
//        removed during the timeout period, then the slip in sensor must
//        remain off for this period of time before a successful status is returned.
//        For printers where the normal condition of the slip rolls is "open",
//        then this parameter is not important.
//        * Set higher if operators have difficulty properly removing the slip
//           before the rolls close. 
//        * Set lower if operators remove the slip correctly and wait too long
//           before the slip rolls close.
const LONG PTR_PARAM_SlipOutSettleTime          = 0x16000000;

//  --SlipStatusPollTime--
//      Slip status poll rate in ms: 50 - 10000 (Default = 150 ms)
//        During BeginInsertion or BeginRemoval, status polling is increased to
//        this rate to monitor the sensors.
//        * Set higher to monitor the sensors more quickly.
//        * Set lower to reduce CPU overhead.
const LONG PTR_PARAM_SlipStatusPollTime         = 0x17000000;

//  --StatusPollTime--
//      Status poll rate in ms: 200 - 10000 (Default = 1000 ms)
//        During normal conditions, the printer and drawer status is polled at
//        this rate to monitor the sensors.
//        * Set higher to monitor the sensors more quickly.
//        * Set lower to reduce CPU overhead.
const LONG PTR_PARAM_StatusPollTime             = 0x18000000;

//  --EjectSlipFeedForward--
//      Initial forward feed when ejecting a slip.  Zero to disable eject feed.
//        (Default = EjectSlipFeedReverse 25 for 7156; else 0)
const LONG PTR_PARAM_EjectSlipFeedForward       = 0x19000000;
//  --EjectSlipFeedReverse--
//      Initial reverse feed when ejecting a slip.  Zero to disable eject feed.
//        (Default = EjectSlipFeedReverse 25 for 7156; else 0)
const LONG PTR_PARAM_EjectSlipFeedReverse       = 0x19800000;


//  --PrintStatusWaitTime--
//      Amount of time to wait for a buffered status response from the printer
//      before giving up, and reporting an error.
//        (Default = 30000 ms with range from 5000 ms to 30000 ms)
const LONG PTR_PARAM_PrintStatusWaitTime        = 0x1A000000;

// Add 7196-4205/3205 - Start

//  --SidewaysWidth--
//       7196 specific parameter : sideways width in milli meter
//         (Default 0;   0 or 60, 70, 80, 90, 100, 110, ..., 180)
const LONG PTR_PARAM_SidewaysWidth              = 0x1B000000;
// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

// Add 7196-4205/3205 - End

// SCOT RFC TAR # 140000 - Start

//  --PreEjectDelay--
//      K580 specific parameter : Delay before performing force eject to 
//         ensure that the receipt has completed presenting, in milliseconds.
//         (Default = 2000, Valid Range 0 - 15000)
const LONG PTR_PARAM_PreEjectDelay              = 0x1C000000;

//  --PostEjectDelay--
//      K580 specific parameter : Delay after force eject to make certain the
//         presenter has returned to print mode, in milliseconds.
//         (Default = 5000, Valid Range 3000 - 8000)
const LONG PTR_PARAM_PostEjectDelay             = 0x1D000000;

// SCOT RFC - End

// Addtional Registry Entries that have accumulated over the last couple
// of years.  Many are related to TARs # 171573, 127785, and 172118
// *************************** Start 05/16/2001 ************************

//  --EjectOnEnable--
//      K580 & K590: Instructs the SO to send an AX E (0x1F, 0x45)
//         Eject Ticket command upon DeviceEnable to make certain any
//         tickets left in the presenter will be ejected and not be
//         reported as paper in the presenter.
//         (Values: T or F for True or False Default: F)
const LONG PTR_PARAM_EjectOnEnable				= 0x1E000000;

//  --EjectAdjustmentTime--
//      K580 & K590: Additional time-out value added to print request when
//         a request contains multiple tickets within a single print 
//         request.  Time is in milliseconds.
//         (Default = 10000, Valid Range 0 - 30000)
const LONG PTR_PARAM_EjectAdjustmentTime		= 0x1F000000;

//  --KnifeCutAdjustmentTime--
//      K580 & K590: Additional time-out value added to print request when
//         a request contains multiple tickets within a single print 
//         request.  This time take into account time to perform a knife cut.
//         Time is in milliseconds.
//         (Default = 6000, Valid Range 0 - 30000)
const LONG PTR_PARAM_KnifeCutAdjustmentTime		= 0x20000000;

// *************************** End - 05/16/2001 ************************

// ************************ Start RFC TAR # 192050 *********************
//   Added the following options to allow modification of registry 
//   through Direct I/O.  Options for UseSoftOptions, MinRecLength, and
//   RecRetainLength are for RFC 192050.  The PaperLowOption and 
//   BlackMarkOption are from previous changes which were not added to
//   this Direct I/O.

//	--PaperLowOption--
//		K590: Paper Low Options sets how printer is suppose to treat the
//			sensor.  (Default = 0, Valid Range 0 - 2)
//			0=Report low at 50ft, 1=Report low at 20ft, 2=Disable paper low
const LONG PTR_PARAM_PaperLowOption				= 0x21000000;

//	--BlackMarkOption--
//		K590: Determine how paper Black Mark is to be used.
//			(Default = 0, Valid Range 0 - 2)
//			0=Document Mode (disabled), 1=Normal Mode (1 mark), 
//			2=Advance Mode (2 marks)
const LONG PTR_PARAM_BlackMarkOption			= 0x22000000;

//	--UseSoftOptions--
//		K590: Determine of Firmware options that can be set by software
//			should be used.  These are for options that were added to the
//			printer firmware after GCA.  This is for compatibiliy.
//			(Default = F, Valid Range T or F )
const LONG PTR_PARAM_UseSoftOptions				= 0x23000000;

//	--RecRetainLength--
//		K590: Set the amount of Receipt Paper that is suppose to be retained
//			in the presenter.  ( Default = 2, Valid Range 1 - 3 )
//			1=25mm, 2=50mm, 3=75mm
const LONG PTR_PARAM_RecRetainLength			= 0x24000000;

//	--MinRecLength--
//		K590: Set the Minimum amount of Receipt paper that must be ejected 
//			during presentation regardless of amount of printing.
//			( Default 2, Valid Range 1 - 9 )
//			1=90mm, 2=111mm, 3=150mm, 4=225mm, 5=300mm, 6=375mm, 7=450mm
//			8=525mm, 9=600mm
const LONG PTR_PARAM_MinRecLength				= 0x25000000;
// ************************* End RFC TAR # 192050 **********************

//	--ColorPaper--
//		7167 & 7197: Selects the type of paper that is being used in 
//			the printer, and number of colors supported. Currently only
//			1=MonoChrome, and 2=2 Color are supported.
//			(Default 1, Valid Range 1 - 2)
const LONG PTR_PARAM_ColorPaper					= 0x26000000;
// ************************* End RFC TAR # 192050 **********************
// TAR SCOT PIP ISSUE - Start
//  --IgnorePIPError--
//      K580 & K590: Set to TRUE if we want to ignore any paper-in-presenter
//      errors, and let the printer Firmware handle them.
//		(Default = F, Valid Range T or F )
const LONG PTR_PARAM_IgnorePIPError				= 0x27000000;
// TAR SCOT PIP ISSUE - End
// RFC TAR # 203390 - Start
//  --SlipStopEOF--
//      7167: Set to TRUE if we want to make sure printer printer firmware stops
//      feeding the paper at End-Of-Form so it can be reversed out.  If False it
//      might feed beyond the feed rolls.
//      (Default = T, Valid Range T or F )
const LONG PTR_PARAM_SlipStopEOF				= 0x28000000;
//  --PrintIntegrityMode--
//      7167 and 7197: Determines print speed by determining the integrity mode of
//      the printer.  If TRUE every line is checked to make certain no lines are lost
//      on an error condition.  If FALSE let it fly to get the 50 LPS rating on 
//      print speed.
//      (Default = F, Valid Range T or F )
const LONG PTR_PARAM_PrintIntegrityMode			= 0x29000000;
// RFC TAR # 203390 - End

// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

//** SetDatacapParam **  Change a data capture parameter from its default or
//                       system registry-specified value. 
//    Data:       In > ParameterConstant + New value.
//                Out> Previous value.
//    String:     In > (Not used.)
//    ResultCode: OPOS_SUCCESS   = Set successfully.
//                OPOS_E_ILLEGAL = Bad value.
const LONG NCRDIO_PTR_SET_DATACAP_PARAM = 152;

//  Parameter constants are:

//  --DcapControl--
//      Hex destination(s):
//       * Set value to zero to stop all data capture.
//       * Else set value to sum or one or more: DcapApp Debugger DcapFile
//         (1) To use a lower priority thread:      1       2        4
//              (Better for performance.)
//         (2) To output immediately:              10      20       40
//              (Sometimes useful to debug lockup problems.)
const LONG PTR_PARAM_DcapControl                = 0x21000000;

//  --DcapMask--
//      Hex mask of events to capture. See DataCap.h for complete list of events.
//        General breakdown of hex digits is...
//          000xxxxF -> Capture all API information.
//          000xxxFx -> Capture all event information.
//          000xxFxx -> Capture all internal operations.
//          000xFxxx -> Capture polls.
//          000Fxxxx -> Capture all raw I/O information.
const LONG PTR_PARAM_DcapMask                   = 0x22000000;



//** QRModel **   Override the registry setting for QRModel with parameter   
//    Data:       In > Model Number
//                     PTR_PARAM_QR_MODEL_1 
//					   PTR_PARAM_QR_MODEL_2
//
//    String:     In > Not Used
//    ResultCode: OPOS_SUCCESS   = Successfully set the active QRModel value.
//                OPOS_E_ILLEGAL = Command not valid for current printer, or
//                                 parameter value out of range.
//                Other values   = See ResultCode property.
const LONG  NCRDIO_PTR_QR_MODEL   = 140;

const LONG	PTR_PARAM_QR_MODEL_1  = 1;
const LONG	PTR_PARAM_QR_MODEL_2  = 2;



//** QRErrLevel **   Override the registry setting for QR barcode error correction level with parameter   
//    Data:       In > Model Number
//                     PTR_PARAM_QR_ERR_LVL_L	1 
//					   PTR_PARAM_QR_ERR_LVL_M	2
//					   PTR_PARAM_QR_ERR_LVL_Q	3
//					   PTR_PARAM_QR_ERR_LVL_H	4
//
//    String:     In > Not Used
//    ResultCode: OPOS_SUCCESS   = Successfully set the active QR barcode error correction level.
//                OPOS_E_ILLEGAL = Command not valid for current printer, or
//                                 parameter value out of range.
//                Other values   = See ResultCode property.
const LONG  NCRDIO_PTR_QR_ERROR_LEVEL  = 141;

const LONG	PTR_PARAM_QR_ERR_LVL_L  = 1;
const LONG	PTR_PARAM_QR_ERR_LVL_M  = 2;
const LONG	PTR_PARAM_QR_ERR_LVL_Q	= 3;
const LONG	PTR_PARAM_QR_ERR_LVL_H	= 4;



//** QRSize **   Override the registry setting for QRSize with parameter   
//    Data:       In > Model Number
//                     PTR_PARAM_QR_SIZE_DEFAULT  0 ( Indicates to attempt to calculate size form height parameter ) 
//					   1 - 16 = Specifies a specific size to use
//
//    String:     In > Not Used
//    ResultCode: OPOS_SUCCESS   = Successfully set the active QRModel value.
//                OPOS_E_ILLEGAL = Command not valid for current printer, or
//                                 parameter value out of range.
//                Other values   = See ResultCode property.
const LONG  NCRDIO_PTR_QR_SIZE   = 142;

const LONG	PTR_PARAM_QR_SIZE_DEFAULT  = 0;
const LONG	PTR_PARAM_QR_SIZE_MIN = 1;
const LONG	PTR_PARAM_QR_SIZE_MAX = 16;



// RPSUPOS-844 --- DirectIO to Enable/Disable the Thai font diacritical character space compensation
//
// ** Enable/Disable Service Object inserting spaces to compensate for diacritical characters no longer taking up space
//
//    Data:       In > Enable/Disable
//                     PTR_PARAM_SP_COMP_DISABLE - 0
//					   PTR_PARAM_SP_COMP_ENABLE - 1
//
//    String:     In > Not Used
//    ResultCode: OPOS_SUCCESS   = Successfully set the active QRModel value.
//                OPOS_E_ILLEGAL = Command not valid for current printer, or
//                                 parameter value out of range.
//                Other values   = See ResultCode property.
const LONG NCRDIO_PTR_THAI_SP_COMP = 145;

const LONG PTR_PARAM_SP_COMP_DISABLE = 0;
const LONG PTR_PARAM_SP_COMP_ENABLE = 1;



//---------------------------------------------------------------------------
//--- Micr DirectIO ---
//---------------------------------------------------------------------------

//** ClearExceptions **  Clear all exception strings.
//    Data:       (Not used.)
//    String:     (Not used.)
//    ResultCode: OPOS_SUCCESS.
const LONG NCRDIO_MICR_CLEAR_EXCEPTIONS = 201;

// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

//** AddException **  Add an exception string to the end of the list of strings.
//                    (See details below in "MICR Data Handling".)
//    Data:       Out> If improper format, set to the approximate character number
//                  where bad format was found.
//    String:     In > Exception string.
//    Remarks:    When Micr data is parsed, the exception strings will be examined
//                  starting with the first one added. If the raw data does not
//                  match the string, then the next exception string is examined.
//                  If no exception strings match, then the default strings are used.
//    ResultCode: OPOS_SUCCESS   = String is ok; exception added.
//                OPOS_E_ILLEGAL = String has improper format.
const LONG NCRDIO_MICR_ADD_EXCEPTION = 202;

// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

//** RemoveNonDigits **  Selects optional space and dash removal from account
//                       and/or transit numbers. The default value is ""; this
//                       default may be changed using the system registry.
//    Data:       (Not used.)
//    String:     In > RemoveNonDigits string.
//                  Set to "A" for Account; "T" for Transit; "AT" for both;
//                  "" for neither",
//    ResultCode: OPOS_SUCCESS.
const LONG NCRDIO_MICR_SET_REMOVE_NON_DIGITS = 203;


//---------------------------------------------------------------------------
//--- Cash Drawer DirectIO ---
//---------------------------------------------------------------------------

//** SetWaitForDrawerCloseFile **
//                Set the wave file used by the WaitForDrawerClose API.
//                  The default value is ""; this default may be changed using
//                  the system registry.
//                The "file" may also be a defined system event, such as
//                  "SystemAsterisk".
//    Data:       In > (Not used.)
//    String:     In > File name (or empty string).
//    Remarks:    During WaitForDrawerClose processing, a "beep" is to be sounded
//                  after an initial delay. If a wave file is specified, however,
//                  the beep is replaced by playing the file.
//    ResultCode: OPOS_SUCCESS.
const LONG NCRDIO_CASH_SET_WAITFORDRAWERCLOSE_FILE = 202;


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// PrintBitmap extension for parameter "Width"
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
//
//   - If the OPOS constant PTR_BM_ASIS is specified, then the bitmap is printed
//       using the number of printer _dots_ given in the bitmap.  The bitmap may
//       still be transformed for the lower resolutions (as in "single density").
//   - If the NCR constant NCR_PTR_BM_ASIS is specified, then the bitmap is printed
//       using the number of printer _bits_ given in the bitmap.  The bitmap bits
//       are sent as printer bit image bits one-for-one, and the size of the result
//       will vary from one resolution to another.

const LONG NCR_PTR_BM_ASIS = -21;


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// Bitmap Printing Types.
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
//
//   Specifies the quality and method of bitmap printing.
//
//   - If a specific type is specified, then it will be used.
//      - If PTR_BM_ASIS or NCR_PTR_BM_ASIS: If not too big, then print.
//          Else an error is returned.
//      - Else: If the specified width is less or equal to the maximum
//          allowed by this type with the current metrics (including
//          linechars), then transform the bitamp to the specified width
//          and print.
//          Else an error is returned.
//
//   - Default will change based on the LetterQuality flag for the station.
//      - If True: Uses the high quality download type if available, else HQ direct.
//        If False: Uses the low quality download type if available, else LQ direct.
//      - If PTR_BM_ASIS or NCR_PTR_BM_ASIS: If not too big, then print.
//          Else try the "next type". If no next, an error is returned.
//            Ordering of next:
//              LQ download -> LQ direct -> HQ download -> HQ direct.
//      - Else: If the specified width is less or equal to the maximum
//          allowed by this type with the current metrics (including
//          linechars), then transform the bitamp to the specified width
//          and print.
//          Else try the "next type". If no next, an error is returned.
//            Ordering of next:
//              LQ download -> LQ direct
//              HQ download -> HQ direct.

const char BitmapType_Default   = 0;

// Direct printing types: Does not download into printer first.
//   Usually causes overall higher throughput, but perceived throughput
//   may be lower, plus print quality may suffer due to banding at the
//   end of each line.
//  -> Supported by: Journal Receipt Slip
//       7156          N/A     Yes    Yes
//       7193          N/A     Yes    N/A
//       7166          N/A     Yes    Yes
//       7152          No      Yes    Yes
//       7140          No      No     No
//       7141          N/A     Yes    Yes
//       7162          No      Yes    Yes
//       1001          N/A     Yes    No
//       2001          No      Yes    N/A
//        520          N/A     N/A    Yes
//       7196-3205     N/A     Yes    N/A
//       7196-4205     No      Yes    N/A
//       7196-5005     N/A     Yes    N/A
//       7196-8005     N/A     Yes    N/A
const char BitmapType_HighQ     = 0x11; // HQ.
const char BitmapType_LowQ      = 0x12; // LQ.

// Download printing types.
//  -> Supported by: Journal Receipt Slip
//       7156          N/A     Yes    No 
//       7193          N/A     Yes    N/A
//       7166          N/A     Yes    No 
//       7152          No      Yes    Yes
//       7140          No      No     No
//       7141          N/A     Yes    Yes
//       7162          No      Yes    Yes
//       1001          N/A     No     No
//       2001          No      Yes    N/A
//        520          N/A     N/A    No
//       7196-3205     N/A     Yes    N/A
//       7196-4205     No      Yes    N/A
//       7196-5005     N/A     Yes    N/A
//       7196-8005     N/A     Yes    N/A
const char BitmapType_HighQ_DL  = 0x21; // HQ.
const char BitmapType_LowQ_DL   = 0x22; // LQ.


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// MICR Data Handling.
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
//
// MICR data consists of digits, spaces, plus four special MICR symbols:
//   Transit, On-Us, Amount, Dash.
//
// In the following discussion, and in the DirectIO command NCRDIO_MICR_ADD_EXCEPTION,
// these characters are used to describe MICR format data:
//     t o a - space   MICR substitution symbols for Transit, On-Us,
//                       Amount, Dash, and Space.
//     X               Digit, space, or dash.
//     E               EPC: Digit.
//     T               Transit number: Digit or dash.
//                       (For US checks, only digits are allowed.)
//     A               Account number: Digit, space, or dash.
//                       (Account number begins and ends with a digit.)
//     S               Serial/sequence number: Digit.
//     $               Amount: Digit.
//     B               Series of blanks (spaces) and/or dashes.
//                       Optional unless a repeat count is given.
//     *               Trailer: Series of any digits, dashes, and spaces followed
//                       by an optional amount field.
//                       (= "X[0+]a$[10]aB" if amount present and "X[0+]" if not).
//
//   An optional repeat count may follow any character except *:
//     [count]         Specifies exactly "count" characters.
//     [min-max]       Specifies between "min" and "max" characters.
//     [min+]          Specifies at least "min" characters.
//
//   The general MICR data format is:
//    oX[1+]o EtT[9]t X[1+]oX[0+] a$[10]a
//
//   The fields are:
//    oX[1+]o     Auxiliary on-us (optional).
//                  Bounded on left and right with On-Us characters.
//                  Often used for serial number, in which case 'X' are digits.
//    E           EPC character (optional).
//                  Immediately precedes leftmost Transit character.
//    tT[9]t      Transit number (required).
//                  Bounded on left and right with Transit characters.
//    X[1+]oX[0+] On-us (optional).
//                  (More than one On-Us symbol could be included, although I
//                  haven't seen this.)
//    a$[10]a     Amount (optional).
//                  Bounded on left and right with Amount characters.
//
//===========================================================================
//
// The transit number and amount can always be found and properly parsed.
// The placement of the serial and account numbers, however, varies between
//   banks.  In addition, the Auxiliary On-Us and the On-Us fields may contain
//   other bank-specific data.
//
// To handle the majority of cases, the following default handling of serial
// and account numbers is performed:
//
// Case (1): Serial number in Auxiliary On-Us field.
//           Account number in On-Us field from first digit to the On-Us symbol,
//             not including spaces and dashes before the On-Us.
//   "BoS[1+]oBEtT[9]tBA[1+]Bo*"
//     -> Serial number is the number S[1+]
//     -> Account number is the number A[1+].
//   Example:
//      "o9876o t123456789t 12-345-6789 o 6666 a0000054321a"
//        Transit: "123456789"      Amount: "0000054321"
//        Account: "12-345-6789"    Serial: "9876"
//        EPC:     ""
//        ** If the RemoveNonDigits string contains an 'A', then
//           Account is "123456789".
//
// Case (2): Account number in On-Us field. This field starts with an optional
//             On-Us symbol, then the account number is taken from first digit to the 
//             required trailing On-Us symbol, not including spaces and dashes 
//             before the trailing On-Us.
//           Serial number in On-Us field after the On-Us symbol.
//             Must be three or more digits.
//   "BEtT[9]tBo[0-1]A[1+]BoBS[3+]*",
//     -> Account number is the number A[1+], if present.
//     -> Serial number is the number S[3+]
//   Example:
//      "5t123456789t o12 345-67 o 6666"
//        Transit: "123456789"      Amount: ""
//        Account: "12 345-67"      Serial: "6666"
//        EPC:     "5"
//        ** If the RemoveNonDigits string contains an 'A', then
//           Account is "1234567".
//
// Case (3): Serial number in On-Us field from first digit to next non-digit;
//             must be between three and five digits.
//           Account number in On-Us field from first digit after the serial
//             number to the On-Us symbol, not including spaces and dashes
//             before the On-Us.
//   "BEtT[9]tBS[3-5]B[1+]A[1+]Bo*"
//     -> Serial number is the number S[3-5]
//     -> Account number is the number A[1+].
//   Example:
//      "t12345-789t 555 12 345-67 o 66"
//        Transit: "12345-789"      Amount: ""
//        Account: "12 345-67"      Serial: "555"
//        EPC:     ""
//        ** If the RemoveNonDigits string contains a 'T', then
//           Transit is "12345789".
//        ** If the RemoveNonDigits string contains an 'A', then
//           Account is "1234567".
//   Example:
//      "t123456789t 555 12 345-67 o 66 a0000054321a"
//        Transit: "123456789"      Amount: "0000054321"
//        Account: "12 345-67"      Serial: "555"
//        EPC:     ""
//        ** If the RemoveNonDigits string contains an 'A', then
//           Account is "1234567".
//
// Case (4): Account number in On-Us field from first digit to the On-Us symbol,
//             not including spaces and dashes before the On-Us.
//   "BEtT[9]tBA[1+]Bo*"
//     -> No serial number.
//     -> Account number is the number A[1+].
//   Example:
//      "t123456789t 55 12 345-67 o 66"
//        Transit: "123456789"      Amount: ""
//        Account: "55 12 345-67"   Serial: ""
//        EPC:     ""
//        ** If the RemoveNonDigits string contains an 'A', then
//           Account is "551234567".
//
// Case (5): Serial number in On-Us field from first digit to the On-Us symbol,
//             must be three or more digits.
//           Account number in second On-Us field from the first digit after the
//             On-Us symbol that ended the serial number to the On-Us symbol, 
//             not including spaces and dashes before the On-Us.
//   "BtT[9]tBS[3+]BoBA[1+]o*",
//     -> Serial number is the number S[3+]
//     -> Account number is the number A[1+].
//   Example:
//      "t12345-789t 555 o 12 345-67 o 66"
//        Transit: "12345-789"      Amount: ""
//        Account: "12 345-67"      Serial: "555"
//        EPC:     ""
//        ** If the RemoveNonDigits string contains a 'T', then
//           Transit is "12345789".
//        ** If the RemoveNonDigits string contains an 'A', then
//           Account is "1234567".
//===========================================================================
//
// If the default handling is not correct for some banks, then exception
// strings can be added for these cases.  The exception strings should be
// formatted as in these examples.
//
// Example exception string "t061000052tBA[10-12]o*":
//     This string requires that the EPC and Serial Number be absent.
//   If Micr Data is: "t061000052t 123 456 789o"
//        Transit: "061000052"      Amount: ""
//        Account: "123 456 789"    Serial: ""
//        EPC:     ""
//        ** If the RemoveNonDigits string contains an 'A', then
//           Account is "123456789".
//        (Without the exception, then default case (3) would have returned "123"
//         as the serial number and "456 789" (** or 456789) as the account number.)
//   If Micr Data is: "t061000052t 123456789012o3333a0000054321a"
//        Transit: "061000052"      Amount: "0000054321"
//        Account: "123456789012"   Serial: ""
//        EPC:     ""
//        (Note that the "3333" between the On-Us and Amount symbols is ignored.
//         Without the exception, then default case (2) would have returned "3333"
//         as the serial number.)
//
// Example exception string "t052000113tBS[3]BA[7-10]o*":
//     This string requires that the EPC be absent.
//   If Micr Data is: "t052000113t 123 456 789o"
//        Transit: "052000113"      Amount: ""
//        Account: "456 789"        Serial: "123"
//        EPC:     ""
//        ** If the RemoveNonDigits string contains an 'A', then
//           Account is "456789".
//
// Example exception string "tTTT00011TtBS[2]A[10]S[3]o*":
//     This string requires that the EPC be absent.
//   If Micr Data is: "t99-000119t 123 456 7890987o a9876543210a"
//        Transit: "99-000119"      Amount: "9876543210"
//        Account: "3 456 7890"     Serial: "12987"
//        EPC:     ""
//        ** If the RemoveNonDigits string contains a 'T', then
//           Transit is "99000119".
//        ** If the RemoveNonDigits string contains an 'A', then
//           Account is "34567890".


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// DocumentHeight extension for Check Scanner Height to perform AutoSize on 
//   the Height of a document.
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
//
const LONG NCR_CHK_DOC_HEIGHT_AUTOSIZE = -1; // Added for RFC TAR # 281958


//---------------------------------------------------------------------------
//--- Check Scanner DirectIO ---
//---------------------------------------------------------------------------

//** SetThresholdLevel **  Set the contrast level that pics up image
//                     
//    Data:       In > Single byte value from -128..0..127
//    String:     (Not used.)
//    ResultCode: OPOS_SUCCESS   = Set successfully.
//                OPOS_E_ILLEGAL = Invalid Parameter
//                Other values   = See ResultCode property.
const LONG NCRDIO_CHKSCAN_SET_THRESHOLD_LEVEL = 301;


//** ReadThresholdLevel **  Reads from the printer contrast level
//                     
//    Data:       Out > Single byte value from -128..0..127
//    String:     (Not used.)
//    ResultCode: OPOS_SUCCESS   = Set successfully.
//                Other values   = See ResultCode property.
const LONG NCRDIO_CHKSCAN_READ_THRESHOLD_LEVEL = 302;


//---------------------------------------------------------------------------
//--- Common Device DirectIO ---
//---------------------------------------------------------------------------

//** GetCCLData **  Obtain device information such as Class-Model & Serial #
//                     
//    Data:       Out > Number of items contained in the string
//    String:     Out > String of items separated by LF
//    ResultCode: OPOS_SUCCESS   = Set successfully.
//                Other values   = See ResultCode property.
const LONG NCRDIO_DEVICE_GET_CCL_DATA = 401;


//---------------------------------------------------------------------------
//--- POSPrinter DirectIO Events ---
//---------------------------------------------------------------------------
//
// -- Proprietary Sensor Change Event --
//
const LONG NCR_PTR_DIOE_SENSOR_UPDATE				= 0x00000001;

//
// -- Two Sided Paper Type Event --
//
const LONG NCR_PTR_DIOE_2ST_PAPER_SENSOR			= 0x00000010;



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


#endif

//..end..