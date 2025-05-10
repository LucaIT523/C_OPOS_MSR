/*************************************************************************
 *
 * NCRkbdhook.h
 *
 *
 * Author:  
 *
 *
 * $Workfile:: ncrkbdhook.h                                              $
 *
 * $Revision:: 4                                                         $
 *
 * $Archive:: /OPOS/Rel.2_4/Include/NCR/ncrkbdhook.h                     $
 *
 * $Date:: 3/09/04 8:31p                                                 $
 *
 *************************************************************************
 * 
 * Copyright (c) NCR Corporation 1998.  All rights reserved.
 *
 *************************************************************************
 *
 * $History:: ncrkbdhook.h                                               $
 * 
 * *****************  Version 4  *****************
 * User: Mo139997     Date: 3/09/04    Time: 8:31p
 * Updated in $/OPOS/Rel.2_4/Include/NCR
 * TAR# 262726, Key Repeat Issue of POSKeyboard SO for 5953 USB Dynakey.
 * 
 * *****************  Version 9  *****************
 * User: Nj151001     Date: 9/21/00    Time: 12:32p
 * Updated in $/OPOS/Rel.2_0/Include/NCR
 * Added message to indicate .bas dependency
 * 
 * *****************  Version 6  *****************
 * User: Dw160003     Date: 11/05/99   Time: 3:02p
 * Updated in $/OPOS/Rel.1_7/Include/NCR
 * added VSS headers
 * 
 * *****************  Version 1  *****************
 * User:           Date:            Time: 
 * Created in $/OPOS/Rel.1_1/Include/NCR
 * 
 *
 ************************************************************************/


//!!!!!!!!!!!!!!!!!!!!!!!!!!! ndj 9/19/00 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// NOTE: Any modifications made to this include file most also be made in
//       ncrkbdhook.bas !!  Do not check in your modified version of this file
//	 unless you are checking in ncrkbdhook.bas as well.

/////////////////////////////////////////////////////////////////////////////
// constants definition
/////////////////////////////////////////////////////////////////////////////

#ifndef KBDHOOKAPI
#define	KBDHOOKAPI	__declspec(dllimport)
#endif

/////////////////////////////////////////////////////////////////////////////
// Beginning of C Language definition
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////////////////////
// function interface definition
/////////////////////////////////////////////////////////////////////////////

// hook mode

#define	HOOK_LEVEL_NONE			1				// no hook mode
#define	HOOK_LEVEL_PARTIAL		2				// partial hook mode
#define	HOOK_LEVEL_ALL			3				// all keys hook mode

/* TAR# 262726, Key Repeat Issue of POS Keyboard SO for 5953 USB Dynakey */
/* add disable repeat feature, ported from NCRAutoRepeatKbd.dll, 03/03/04 */
#define  BUFFER_SIZE		256
#define  DEFAULT_CHORD_SIZE	3
#define  MIN_CHORD_SIZE		1
#define  MAX_CHORD_SIZE		16
#define  MAX_DISABLED_SCAN_CODES	128
/* TAR# 262726, change end */

// POS key structure

typedef struct _POSKEY							// POSKEY definition
{
	USHORT	usScanCode;								// system scan code
	USHORT	usKeyCode;								// logical key code
} POSKEY, *PPOSKEY;

// parser macros for a value of lParam

#define	KEY_REPEAT_COUNT(l)		(LOWORD(l) & 0x00FF)		// repeat counts
#define	KEY_SCAN_CODE(l)		(HIWORD(l) & 0x00FF)		// scan code
#define	IS_EXTENDED_KEY(l)		(HIWORD(l) & KF_EXTENDED)	// is extended key ?
#define	IS_BREAK_KEY(l)			(HIWORD(l) & KF_UP)			// is break key ?

// some scan codes

#define	SC_EXTENDED_KEY			0xE000			// extended key code 0xE0xx



/////////////////////////////////////////////////////////////////////////////
// exposed APIs definition
/////////////////////////////////////////////////////////////////////////////

KBDHOOKAPI BOOL WINAPI KbdHookInstall(HWND hwndPost, UINT uMsgNotify, BOOL fGlobal);
KBDHOOKAPI BOOL WINAPI KbdHookUninstall(VOID);
KBDHOOKAPI BOOL WINAPI KbdHookEnable(USHORT usLevel, PPOSKEY pKeys);
KBDHOOKAPI VOID WINAPI KbdHookConnectThread(DWORD dwThread);
/* TAR# 262726, Key Repeat Issue of POS Keyboard SO for 5953 USB Dynakey */
/* add disable repeat feature, ported from NCRAutoRepeatKbd.dll, 03/03/04 */
KBDHOOKAPI BOOL WINAPI KbdHookSetRepeat(BOOL bDisable, WORD nNumDisabled, WORD *panDisabled, WORD nChordSize);
/* TAR# 262726, change end */

/////////////////////////////////////////////////////////////////////////////
// End of C Language Definition
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

/////////////////////////////////////////////////////////////////////////////
