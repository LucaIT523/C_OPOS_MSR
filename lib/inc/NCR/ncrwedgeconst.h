/*************************************************************************
 *
 * wdgconst.h
 *
 * Type:             Header file                                              
 *                                                                          
 *  Abstract: This file contains the internal constants, structures, and       
 *         function prototypes used by the Wedge Keyboard Filter Library.         
 *
 *
 * Wedge Keyboard Filter Related Files:															  
 *                 wdgkf.c     Initialization, WEP, and Filter related code.     
 *                                                                          
 * Language:         Microsoft Visual C 4.0 or later                        
 *                                                                          
 * Operating System: Windows 95/NT
 * Target System:    PC                                                 
 *                                                                          
 * Author/Location:  Narinder Singh, E&M Atlanta                                 
 *                                                                          
 * Copyright (c) 1996 NCR Corp.                       
 *
 *
 * $Workfile:: ncrwedgeconst.h                                           $
 *
 * $Revision:: 14                                                        $
 *
 * $Archive:: /OPOS/Rel.2_0/Include/NCR/ncrwedgeconst.h                  $
 *
 * $Date:: 9/21/00 12:32p                                  $
 *
 *************************************************************************
 * 
 * Copyright (c) NCR Corporation 1998.  All rights reserved.
 *
 *************************************************************************
 *
 * $History:: ncrwedgeconst.h                                            $
 * 
 * *****************  Version 14  *****************
 * User: Nj151001     Date: 9/21/00    Time: 12:32p
 * Updated in $/OPOS/Rel.2_0/Include/NCR
 * Added message to indicate .bas dependency
 * 
 * *****************  Version 12  *****************
 * User: Farmer       Date: 12/22/99   Time: 6:32p
 * Updated in $/OPOS/Rel.1_8/include/ncr
 * Added 4 members (KeylockDataCount, KeylockDataMax, KeylockErrorCount,
 * KeylockErrorMax) to SEMAPHORE_COUNTS structure
 * 
 * *****************  Version 11  *****************
 * User: Farmer       Date: 12/22/99   Time: 5:29p
 * Updated in $/OPOS/Rel.1_8/Include/NCR
 * 
 * *****************  Version 9  *****************
 * User: Dw160003     Date: 11/09/99   Time: 2:47p
 * Updated in $/OPOS/Rel.1_7/Include/NCR
 * added VSS headers
 * 
 * *****************  Version 1  *****************
 * User: SinghN       Date:         Time: 10:01a
 * Created in $/OPOS/Rel.1_1/Include/NCR
 * 
 *
 ************************************************************************/

//!!!!!!!!!!!!!!!!!!!!!!!!!!! ndj 9/19/00 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// NOTE: Any modifications made to this include file most also be made in
//       NCRwedgeconst.bas !!  Do not check in your modified version of this file
//	 unless you are checking in NCRwedgeconst.bas as well.

/*****************************************************************************
*                                                                            *
*                                Constants                                   *
*                                                                            *
*****************************************************************************/

#define     WEDGE_SENTINEL        0x64   /* Wedge wants to send data */
#define     MSR_TRK1_START        0x5E   /* MSR track 1 data is coming next */
#define     MSR_TRK2_START        0x6A   /* MSR track 2 data is coming next */
#define     MSR_TRK3_START        0x72   /* MSR track 3 data is coming next */
#define     MSR_TRK3_START_NT     0x71   /* MSR track 3 data is coming next */
#define     SCAN_DATA_START       0x5F   /* Scanner data is coming next */
#define     KLOCK_DATA_START      0x29   /* Key postion is the next byte */
#define     WEDGE_DATA_END        0x1C   /* No more wedge data */ 
#define     PART_NUMBER_START     0x4B   /* PART number stats with 4 */


#define     MSR_TRK1_IN_PROG      0x10   /* Track 1 in progress */
#define     MSR_TRK2_IN_PROG      0x20   /* Track 2 in progress */
#define     MSR_TRK3_IN_PROG      0x30   /* Track 3 in progress */
#define     SCAN_IN_PROG          0x40   /* Scan in progress */
#define     KLOCK_IN_PROG         0x50   /* Keylock in progress */
#define     PART_IN_PROG          0x60   /* Part number in progress */
#define     KEYB_PARTNUM_IN_PROG  0x70   /* Keyboard Part number in progress */

#define     MAX_DATA_LEN          110    /* Max. track length*/

#define     MSR_MSG_BUF_SIZE      460
#define     MSR_MAX_MESSAGES      6      /* Max. # of tracks that can be stored*/
#define     MSR_SEMA_MAX          MSR_MAX_MESSAGES

#define     KLOCK_MAX_MESSAGES    8
#define     KLOCK_SEMA_MAX        KLOCK_MAX_MESSAGES

#define     SCAN_MSG_BUF_SIZE     256
#define     SCAN_MAX_MESSAGES     10
#define     SCAN_SEMA_MAX         SCAN_MAX_MESSAGES

#define     MESSAGE_TIMER         3000   /* 3 seconds */
#define     MSR_CHAR_TIMER        1000   /* 1 second */

// Hardware ports used
#define     DATA_PORT             0x60
#define     CMD_STATUS_PORT       0x64
#define     INPUT_BUFFER_FLAG     02
#define     OUTPUT_BUFFER_FLAG    01
#define     MAX_LOOP              0xFFF


// OS type
#define     OS_WINDOWS_95         1
#define     OS_WINDOWS_NT         2
#define     OS_WINDOWS_CE         3     // WTS: Windows CE Updates (2-99)

#define     KBD_STATE_LEN   256         /* Size of kbd state buffer         */


#define     PART_NUMBER_LEN      11
#define     TOTAL_PART_LEN       23
#define     KEYBOARD_PART_LEN    12

// Macros
#define    KEY_PRESSED(lParam)    (! (lParam & 0x80000000) )
#define    ALT_KEY_DOWN(lParam)      (lParam & 0x20000000)

//  Error Status
#define     GOOD_STATUS            0
#define     QUEUE_FULL             0xFF        //Max. messages are already stored
#define     NO_DATA_AVAILABLE      0xFE        //SO came to read, but no data present
#define     HOOK_NOT_INSTALLED     0xFD        //SO try to enable but no kbd hook installed 
#define     BUFFER_OVERFLOW        0xFC        //More data came from wedge than it was expected
#define     DEVICE_ALREADY_ENABLED 0xFB
#define     NO_BUFFER_TO_STORE     0xFA        // Device data is more than expected
#define     UNABLE_TO_SEND         0xF9        // problem to send output to the wedge
#define     BUFF_TOO_SMALL         0xF8        // callers buffer is not big enough to hold data
#define     NTDRIVER_NOT_INSTALLED 0xF7       // NT Kernel mode driver is not installed


/*****************************************************************************
*                                                                            *
*                                Structures                                  *
*                                                                            *
*****************************************************************************/

#pragma pack(2)                 /* Set structure alignment at "word" */

typedef struct {
    UCHAR           buf[SCAN_MSG_BUF_SIZE];  /* ring buffer for Wedge serial data */
    UCHAR           msg_length[SCAN_MAX_MESSAGES];  /* length of each serial message */
    USHORT          bytes_free;         /* num bytes free in message buf */
    USHORT          output_index;       /* next location to retrieve data from */
    USHORT          input_index;        /* next location to store data to */
    UCHAR           output_slot;        /* slot for next message to retrieve */
    UCHAR           input_slot;         /* slot to store next message */
    UCHAR           num_msgs;           /* number of messages stored */
} SCANNER_DATA;


typedef struct {
    UCHAR           buf[MSR_MSG_BUF_SIZE];  /* ring buffer for Wedge MSR data */
    UCHAR           msg_length[MSR_MAX_MESSAGES];  /* length of each message */
    USHORT          bytes_free;         /* num bytes free in message buf */
    USHORT          output_index;       /* next location to retrieve data from */
    USHORT          input_index;        /* next location to store data to */
    UCHAR           output_slot;        /* slot for next message to retrieve */
    UCHAR           input_slot;         /* slot to store next message */
    UCHAR           num_msgs;           /* number of messages stored */
}MSR_DATA;


// WTS: Windows CE Updates (2-99)
// Shared memory for holding semaphore counts is structured as follows:
#ifdef _WIN32_WCE

typedef struct {
    WORD    MsrDataCount;
    WORD    MsrDataMax;
    WORD    MsrErrorCount;
    WORD    MsrErrorMax;
    WORD    ScannerDataCount;
    WORD    ScannerDataMax;
    WORD    ScannerErrorCount;
    WORD    ScannerErrorMax;
    WORD    KbdDataCount;
    WORD    KbdDataMax;
    WORD    KbdErrorCount;
    WORD    KbdErrorMax;
	WORD	KeylockDataCount;
	WORD	KeylockDataMax;
	WORD	KeylockErrorCount;
	WORD	KeylockErrorMax;
} SEMAPHORE_COUNTS;

#endif


#pragma pack()                  /* Restore structure alignment */
