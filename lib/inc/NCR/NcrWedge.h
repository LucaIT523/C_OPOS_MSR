/*************************************************************************
 *
 * NcrWedge.h
 *
 * 
 * Author:  
 *
 *
 * $Workfile:: NcrWedge.h                                                $
 *
 * $Revision:: 8                                                         $
 *
 * $Archive:: /OPOS/Rel.2_0/Include/NCR/NcrWedge.h                       $
 *
 * $Date:: 9/21/00 12:32p                                                $
 *
 *************************************************************************
 * 
 * Copyright (c) NCR Corporation 1998.  All rights reserved.
 *
 *************************************************************************
 *
 * $History:: NcrWedge.h                                                 $
 * 
 * *****************  Version 8  *****************
 * User: Nj151001     Date: 9/21/00    Time: 12:32p
 * Updated in $/OPOS/Rel.2_0/Include/NCR
 * Added message to indicate .bas dependency
 * 
 * *****************  Version 5  *****************
 * User: Dw160003     Date: 11/09/99   Time: 1:55p
 * Updated in $/OPOS/Rel.1_7/Include/NCR
 * added VSS headers
 * 
 * *****************  Version 1  *****************
 * User:        Date:       Time: 10:01a
 * Created in $/OPOS/Rel.1_1/Include/NCR
 * 
 *
 ************************************************************************/


//!!!!!!!!!!!!!!!!!!!!!!!!!!! ndj 9/19/00 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// NOTE: Any modifications made to this include file most also be made in
//       NCRWedge.bas !!  Do not check in your modified version of this file
//	 unless you are checking in NCRWedge.bas as well.

#ifndef _NCRWEDGEHDR_
#define _NCRWEDGEHDR_

/////////////////////////////////////////////////////////////////////////////
// Include header files
/////////////////////////////////////////////////////////////////////////////

#ifndef _DEVIOCTL_
#ifndef _NTDDK_
# error Please include WINIOCTL.H or DEVIOCTL.H beforehand
#endif
#endif

/////////////////////////////////////////////////////////////////////////////
// Global Definitions
/////////////////////////////////////////////////////////////////////////////

// for ReadFile() parameters

typedef struct _WEDGE_DATA					// wedge data structure
{
	ULONG		ulTime;							// system time when the event occurs
	ULONG		ulBytes;						// number of bytes
	UCHAR		auchWedgeData[1];				// wedge raw data
												// 
} WEDGE_DATA, *LPWEDGE_DATA;

typedef struct _WEDGE_KEY_DATA				// wedge data structure
{
	ULONG		ulTime;							// system time when the event occurs
	USHORT		usScanCode;						// scan code
	USHORT		fBreakKey;						// break key
} WEDGE_KEY_DATA, *LPWEDGE_KEY_DATA;

#define		NCRWEDGE_READ_BYTES		(300)	// safe buffer size

// I/O Control function code

#define     IOCTL_WEDGE_SET_MODE			CTL_CODE(FILE_DEVICE_UNKNOWN,   \
													 0x800,                 \
													 METHOD_BUFFERED,       \
													 FILE_ANY_ACCESS)

#define     IOCTL_WEDGE_QUERY_MODE			CTL_CODE(FILE_DEVICE_UNKNOWN,   \
		                                             0x802,                 \
				                                     METHOD_BUFFERED,       \
						                             FILE_ANY_ACCESS)

#define     IOCTL_WEDGE_SET_SENTINELS		CTL_CODE(FILE_DEVICE_UNKNOWN,   \
		                                             0x804,                 \
				                                     METHOD_BUFFERED,       \
						                             FILE_ANY_ACCESS)

#define     IOCTL_WEDGE_QUERY_SENTINELS		CTL_CODE(FILE_DEVICE_UNKNOWN,   \
		                                             0x806,                 \
				                                     METHOD_BUFFERED,       \
						                             FILE_ANY_ACCESS)

#define     IOCTL_WEDGE_KEYBOARD_CONTROL	CTL_CODE(FILE_DEVICE_UNKNOWN,   \
		                                             0x808,                 \
				                                     METHOD_BUFFERED,       \
						                             FILE_ANY_ACCESS)

// wedge device mode control array

typedef struct _WEDGE_DEVICE_MODE			// wedge device mode
{
	ULONG		ulInterceptMode;				// interception mode
	ULONG		ulInformationCode;				// 32-bit information code
} WEDGE_DEVICE_MODE, *LPWEDGE_DEVICE_MODE;

#define		WEDGE_MODE_PASS_THROUGH		0	// pass-through mode
#define		WEDGE_MODE_INFO_CODE		1	// information code mode
#define		WEDGE_MODE_INTERCEPT		2	// interception mode

// wedge sentinels control array

typedef struct _WEDGE_SENTINELS				// wedge sentinels
{
	ULONG		ulCounts;						// number of sentinels
	UCHAR		auchSentinels[1];				// top of sentinel buffer
												//
} WEDGE_SENTINELS, *LPWEDGE_SENTINELS;

// wedge start & end sentinels control array

typedef struct _WEDGE_DEVICE_SENTINELS		// wedge sentinels
{
	ULONG		ulCounts;						// number of sentinels
	UCHAR		ucStartSentinel;				// start sentinel buffer
	UCHAR		ucEndSentinel;					// end sentinel buffer
} WEDGE_DEVICE_SENTINELS, *LPWEDGE_DEVICE_SENTINELS;

// wedge keyboard control

typedef struct _WEDGE_KEYBOARD_CONTROLS		// wedge keyboard control
{
	USHORT usUnitId;							// zero-based unit ID
	USHORT usByte;								// number of bytes
	UCHAR  auchCommand[1];						// command data
												//
} WEDGE_KEYBOARD_CONTROLS, *LPWEDGE_KEYBOARD_CONTROLS;

#endif // _NCRWEDGEHDR_

/////////////////////////// End Of Program //////////////////////////////////
