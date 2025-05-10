/*************************************************************************
 *
 * NCRMSRNT.H
 *
 * LANGUAGE:          Microsoft C 5.0
 * OPERATING SYSTEM:  Windows NT 4.0/WIN95/WIN CE
 * TARGET SYSTEM:     Informa
 * ENVIRONMENT:       MSR Driver
 *
 * CREATED:           January 1999
 * AUTHOR:            NCR Atlanta
 *
 *----------------------------------------------------------------------------
 *
 * ABSTRACT:
 *
 *  This is the internal header file for the for the NCRMSR driver. 
 *  This header files pulled in are based on the target platform.
 *  The following Compile Defines should be used based on target 
 *      NT 4.0 Driver  -DNCR_WINNT
 *      WIN95 Driver   -DNCR_WIN95
 *      WINCE Driver   -DNCR_WINCE
 *      All Applications  -DAPPL
 *  Contents of this file should be accessed by application code.
 *
 *----------------------------------------------------------------------------
 *
 * Copyright (c) 1999 NCR Corp.  All rights reserved.
 *
 * Author: NCR Atlanta 
 *
 *
 * $Workfile:: NCRMSRNT.h                                                $
 *
 * $Revision:: 12                                                        $
 *
 * $Archive:: /OPOS/Rel.2_0/Include/NCR/NCRMSRNT.h                       $
 *
 * $Date:: 9/21/00 12:32p                                                $
 *
 *************************************************************************
 * 
 * Copyright (c) NCR Corporation 1998.  All rights reserved.
 *
 *************************************************************************
 *
 * $History:: NCRMSRNT.h                                                      $
 * 
 * *****************  Version 12  *****************
 * User: Nj151001     Date: 9/21/00    Time: 12:32p
 * Updated in $/OPOS/Rel.2_0/Include/NCR
 * Added message to indicate .bas dependency
 * 
 * *****************  Version 10  *****************
 * User: Admin        Date: 5/18/00    Time: 9:23p
 * Updated in $/OPOS/Rel.1_8/Include/NCR
 * 
 * *****************  Version 9  *****************
 * User: Mr160002     Date: 5/02/00    Time: 11:07a
 * Updated in $/OPOS/Rel.1_8/Include/NCR
 * TAR 138632 - MSR Detect Extended Error Codes
 * 
 * *****************  Version 7  *****************
 * User: Dw160003     Date: 11/09/99   Time: 10:40a
 * Updated in $/OPOS/Rel.1_7/Include/NCR
 * added VSS headers
 * 
 * *****************  Version 1  *****************
 * User:        Date:            Time: 
 * Created in $/OPOS/Rel.1_1/Include/NCR
 * 
 *
 ************************************************************************/


//!!!!!!!!!!!!!!!!!!!!!!!!!!! ndj 9/19/00 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// NOTE: Any modifications made to this include file most also be made in
//       NCRMSRNT.bas !!  Do not check in your modified version of this file
//	 unless you are checking in NCRMSRNT.bas as well.

#ifndef _NCRMSRHDR_
#define _NCRMSRHDR_

/////////////////////////////////////////////////////////////////////////////
// Include header files
/////////////////////////////////////////////////////////////////////////////

#ifndef _DEVIOCTL_
#ifndef _NTDDK_
# error Please include WINIOCTL.H or DEVIOCTL.H beforehand
#endif
#endif


#ifndef INCRMSRNT_DRVR
/////////////////////////////////////////////////////////////////////
// "ResultCodeExtended" Property Constants for MSR TAR 138632
/////////////////////////////////////////////////////////////////////
// MSR Detect Extended Codes - NCR FitClient System Monitor checks hardware and
// sets registry entry "IsPresent" to 1 if MSR Device is present and 0 if not present.
const long NCR_EMSR_MSRDETECT           = 100 + OPOSERREXT; //  MSR Detect Registry entries missing
const long NCR_EMSR_NODEVICE           = 101 + OPOSERREXT; //  Registry indicates Device is not connected
/////
#endif

/////////////////////////////////////////////////////////////////////////////
// Global Definitions
/////////////////////////////////////////////////////////////////////////////

// I/O Control function code

#define     IOCTL_NCRMSR_QUERY_CONTROLS		CTL_CODE(FILE_DEVICE_UNKNOWN,   \
													 0x800,                 \
													 METHOD_BUFFERED,       \
													 FILE_ANY_ACCESS)

#define     IOCTL_NCRMSR_SET_CONTROLS		CTL_CODE(FILE_DEVICE_UNKNOWN,   \
		                                             0x802,                 \
				                                     METHOD_BUFFERED,       \
						                             FILE_ANY_ACCESS)

#define     IOCTL_NCRMSR_QUERY_TRACKS		CTL_CODE(FILE_DEVICE_UNKNOWN,   \
		                                             0x804,                 \
				                                     METHOD_BUFFERED,       \
						                             FILE_ANY_ACCESS)

#define     IOCTL_NCRMSR_SET_TRACKS			CTL_CODE(FILE_DEVICE_UNKNOWN,   \
		                                             0x806,                 \
				                                     METHOD_BUFFERED,       \
						                             FILE_ANY_ACCESS)

#define     IOCTL_NCRMSR_QUERY_DEVICE		CTL_CODE(FILE_DEVICE_UNKNOWN,   \
		                                             0x808,                 \
				                                     METHOD_BUFFERED,       \
						                             FILE_ANY_ACCESS)

#define		IOCTL_NCRMSR_DEBUG_EVENT		CTL_CODE(FILE_DEVICE_UNKNOWN,   \
		                                             0x810,                 \
				                                     METHOD_BUFFERED,       \
						                             FILE_ANY_ACCESS)

#define		IOCTL_NCR_READ           		CTL_CODE(FILE_DEVICE_UNKNOWN,   \
		                                             0x00,                 \
				                                     METHOD_BUFFERED,       \
						                             FILE_ANY_ACCESS)

// number of leading zeros to ignore control

typedef struct _NCRMSR_CONTROLS				// number of leading zeros
{
	USHORT	usTrack1;							// for track 1
	USHORT	usTrack2;							// for track 2
	USHORT	usTrack3;							// for track 3
} NCRMSR_CONTROLS, *PNCRMSR_CONTROLS;

#define		NCRMSR_MAX_ZEROS_IGNORED		7	// maximum value

// track to be read control

typedef struct _NCRMSR_TRACKS				// tracks to be read
{
	USHORT	fsTracksToRead;						// tracks to be read
} NCRMSR_TRACKS, *PNCRMSR_TRACKS;

#define		NCRMSR_TRACK1			0x0001		// read track 1
#define		NCRMSR_TRACK2			0x0002		// read track 2
#define		NCRMSR_TRACK3			0x0004		// read track 4

// MSR device status

typedef struct _NCRMSR_DEVICE				// device status
{
	ULONG	ulMemoryAddress;					// ASIC memory address
	USHORT	usIRQ;								// IRQ number
	USHORT	fDeviceAttached;					// device attached
	USHORT	usAsicRevision;						// ASIC revision level
} NCRMSR_DEVICE, *PNCRMSR_DEVICE;

// for ReadFile() parameters

#define		NCRMSR_READ_BYTES	(96 + 40 + 104 + 3)

#endif // _NCRMSRHDR_

/////////////////////////// End Of Program //////////////////////////////////
