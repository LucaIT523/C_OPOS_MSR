//////////////////////////////////////////////////////////////////////////////
//
// This is the NCR FitClient Event Message File.  It is used to define
// events for FitClient client and server software.  Some of the client
// modules supported (FitClientAgent and SystemMonitor) are also used 
// without FitClient servers.  
//
//
//
// $Workfile:: NCRFitClientMsg.mc                                            $
//
// $Revision:: 16                                                            $
//
// $Archive:: /FitClient/Rel.3_2/StoreMinder/Message Files/NCRFitClientMsg.mc                     $
//
// $Date:: 2/12/07 1:02p                                                     $
//
//////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) NCR Corporation 1998-2007.  All rights reserved.
//
//////////////////////////////////////////////////////////////////////////////





// DO NOT MODIFY THIS SECTION - BEGIN SECTION




// The StoreMinder CNCREventLog class uses the Severity field to 
// pass the severity of the message being logged from the message 
// file to ReportEvent.
//
// The CONVERT_SEVERITY macro is used for this purpose.
//



#define CONVERT_SM_SEVERITY(X)                                             \
		(((X>>30)==SEVERITY_SM_SUCCESS)    ? evlTypeAuditSuccess:           \
		(((X>>30)==SEVERITY_SM_INFORMATION)? evlTypeInformation:            \
		(((X>>30)==SEVERITY_SM_WARNING)    ? evlTypeWarning:                \
		(((X>>30)==SEVERITY_SM_ERROR)      ? evlTypeError : evlTypeInformation))))

//
// The StoreMinder CNCREventLog class uses the facility field to 
// pass the category of the message being logged from the message 
// file to ReportEvent.  
//
// The CONVERT_SM_CATEGORY macro is used for this purpose.
//
// SM_CATEGORY_COUNT should be the total number of categories
#define SM_CATEGORY_COUNT 18
#define CONVERT_SM_CATEGORY(X)   ((X>>16) & 0xFFF)														\
		

// END SECTION
//////////////////////////////////////////////////////////////////////////////
//
// Message Parameters: See comments before each event message.
//
// Store Minder CNCREventLog class parameter values that should be 
// used:
// (a) EventClass = Basic 
// (b) EventType = CONVERT_SEVERITY(<EventId>)
// (c) EventCategory = CONVERT_SM_CATEGORY(<EventId>)
// (d) EventID = same as SymbolicName listed in this message file
//
//    Within the message text, several escape sequences are supported for
//    dynamically formatting the message.  The percent sign character (%)
//    begins all escape sequences.
//
//
//        %0 - This terminates a message text line without a trailing
//             newline.  This can be used to build up long lines or to
//             terminate the message itself without a trailing newline,
//             which is useful for prompt messages.
//
//        %n!printf format string!  - This identifies an insert.  The
//             value of n can be between 1 and 99.  The printf format
//             string must be bracketed by exclamation marks.  It is
//             optional and defaults to !s! if not specified.
//
//             The printf format string can contain the * specifier for
//             either the precision or width components, and if so, they
//             will consume inserts %n+1 and %n+2 for their values at run
//             time.  MC will print a warning message if an explicit
//             reference is made to these inserts elsewhere in the message
//             text.
//
//    Inserts must reference a parameter passed to the FormatMessage API
//    call.  It will return an error if a message refers to an insert that
//    was not passed to the FormatMessage API call.
//
//    Any other character following a percent sign, other than a digit will
//    be formatted in the output message without the percent sign.  Some
//    examples:
//
//        %% - will output a single percent sign in the formatted message text.
//
//        %n - will output a hard line break when it occurs at the end of a
//             a line.  Useful when FormatMessage is supplying normal line
//             breaks so the message fits in a certain width.
//
//        %r - will output a hard carriage return, without a trailing newline.
//
//        %b - will output a space in the formatted message text.  This
//             can be used to insure there are the appropriate number of
//             trailing spaces in a message text line.
//
//        %t - will output a tab in the formatted message text.
//
//        %. - will output a single period in the formatted message text.
//             This can be used to get a single period at the beginning of
//             a line without terminating the message text definition.
//
//        %! - will output a single exclamation point in the formatted
//             message text.  This can be used to get an exclamation point
//             immediately after an insert without it being mistaken for
//             the beginning of a printf format string.
//
//    Unicode support is not understood yet.  If the input file is ASCII
//    text, do we need an escape sequence to allow input of Unicode values?
//    Or do we just let them use DBCS in the text file, assuming they have
//    a text editor that can do this.
//
//	** SandyS - TAR # 90490 **
// Removed the POST and Diagnostics source from the Message ID ranges below and 
// moved their ranges back under the NCR CCl Client Agent  source.  
//
//  Message Id Ranges 
//
//     Common Event:                       50000 - 50049
//     Diagnostic:                         50050 - 50099
//     POST Errors:                        50100 - 50199
//     NCRSRMS or NCRFitClientAgent DLL:   50200 - 50249
//     NCRFitClientAgent DLL:              50250 - 50299
//     System Monitor:                     50300 - 50349
//     NCR BINL and DHCP Server:           50400 - 50450
//     NCRFitClientAgent.DLL:              50451 - 50500
//     NCR FitClient Loader Service:       50501 - 50550
//     NCR Utilities:                      50551 - 50600
//
//     SRMS - Server Registry Mirroring Service
//     RMS - Registry Mirroring Service
//     CCL Agent - Customer Care Link Agent
//
//     Note:  
//         NCR BINL, DHCP, and FitClient Loader Service are used only on 
//         FitClient Manager and FitClient Loader servers.  Where these 
//         modules are also used with RSM, the event messages are defined 
//         in RSMMessages.dll when used on RSM servers.
//         
//         FitClientAgent is still used in standalone mode on legacy 
//         terminals with RSM.  System Monitor is also still used with RSM.  
//         These client modules still use this FitClientMsg message file even 
//         when RSM is used.
//
//
//  The Following is a sample Message
//
//  MessageId=10000
//  SymbolicName=ERROR_ONE
//  Severity=Warning
//  Facility=InternalInterface
//  Language=English
//  Stopping OPOS Service.%0
//  .
//  Language=French
//  Commencant OPOS.%0
//  .
//
// If the Source name is longer than 20 characters it will get 
// truncated when transferred to the Store Minder server when the
// communications is via winsock (Store Minder 1.1).  If the communications 
// is DCOM the Source name is transferred intact (Store Minder 2.0).
//
// Currently the maximum character count for all of the insertion
// strings concatenated together is 125.  If the insertion strings
// are longer, the event message will not be formatted correctly.
//
// ---------------------------------------------------------------------------------
//	Common Event Log Messages
// Source:  NCR SRMS
//		     NCRFitClientAgent
//		     NCRSystemMonitor
//			 NCRDLLLoader(Application/Service)
// MessageId Range for common Events: 50000 - 50049
// ---------------------------------------------------------------------------------
//
//   Parameter 1 - Source Description.
//					
//   Data: none.
//
//
//  Values are 32 bit values layed out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +-+-+-+-+-+---------------------+-------------------------------+
//  |S|R|C|N|r|    Facility         |               Code            |
//  +-+-+-+-+-+---------------------+-------------------------------+
//
//  where
//
//      S - Severity - indicates success/fail
//
//          0 - Success
//          1 - Fail (COERROR)
//
//      R - reserved portion of the facility code, corresponds to NT's
//              second severity bit.
//
//      C - reserved portion of the facility code, corresponds to NT's
//              C field.
//
//      N - reserved portion of the facility code. Used to indicate a
//              mapped NT status value.
//
//      r - reserved portion of the facility code. Reserved for internal
//              use. Used to indicate HRESULT values that are not status
//              values, but are instead message ids for display strings.
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
// Define the facility codes
//
#define SM_CAT_THIRD_PARTY_INTERFACE     0x6
#define SM_CAT_SYSTEM_CALL               0x5
#define SM_CAT_STOP_ABORT                0x2
#define SM_CAT_STARTUP_INIT              0x1
#define SM_CAT_SECURITY                  0xA
#define SM_CAT_RESOURCE                  0xC
#define SM_CAT_PERIPHERAL_COMM           0xE
#define SM_CAT_OPERATIONAL               0x11
#define SM_CAT_LAN_WAN_COMM              0x9
#define SM_CAT_IPC                       0xD
#define SM_CAT_INTERNAL_INTERFACE        0x7
#define SM_CAT_INTERNAL_ERROR            0x12
#define SM_CAT_INPUT_PARAMETER           0x4
#define SM_CAT_HARDWARE                  0xF
#define SM_CAT_FILE_IO                   0xB
#define SM_CAT_DEVICE_PERIPHERAL         0x10
#define SM_CAT_DATA_CAPTURE              0x8
#define SM_CAT_CONFIGURATION             0x3


//
// Define the severity codes
//
#define SEVERITY_SM_WARNING              0x2
#define SEVERITY_SM_SUCCESS              0x0
#define SEVERITY_SM_INFORMATION          0x1
#define SEVERITY_SM_ERROR                0x3


//
// MessageId: NCR_SERVICE_START
//
// MessageText:
//
//  The %1 Service has started successfully.
//
#define NCR_SERVICE_START                ((DWORD)0x4001C350L)

// Parameter 1 - Source Description.
//					
// Data: none.
//
//
// MessageId: NCR_SERVICE_PAUSED
//
// MessageText:
//
//  %1 Service has been paused.
//
#define NCR_SERVICE_PAUSED               ((DWORD)0x4011C351L)

//
// Parameter 1 - Source Description.
// Parameter 2 - Name of the Service in the Services applet
//					
// Data: none.
//
//
// MessageId: NCR_SERVICE_STOPPED
//
// MessageText:
//
//  The %1 Service has stopped.
//  %n%nMeaning:
//  %nService has stopped.
//  %n%nAction:
//  %nTo re-start the service, go to the Services applet under 
//  Control Panel. Start the %2 service.
//
#define NCR_SERVICE_STOPPED              ((DWORD)0x4002C352L)

//
// Parameter 1 - Source Description.
//					
// Data: GetLastError().
//
//
// MessageId: NCR_REGISTER_SERVICE_HANDLER
//
// MessageText:
//
//  Service handle could not be registered.
//  %n%nSource: %1 
//
#define NCR_REGISTER_SERVICE_HANDLER     ((DWORD)0xC001C353L)

//
// Parameter 1 - Source Description.
//					
// Data: none.
//
//
// MessageId: NCR_BAD_SERVICE_REQUEST
//
// MessageText:
//
//  Service handler received an unknown service request.
//  %n%nSource: %1
//
#define NCR_BAD_SERVICE_REQUEST          ((DWORD)0xC011C354L)

// Parameter 1 - Source Description.
// Parameter 2 - Name of the System API that failed if known,
//               SetFilePointer and WriteFile (for NTDriver Access).
//               
//					
// Data: GetLastError() result API call failed.

//
// MessageId: NCR_SYSTEM_CALL_FAILURE
//
// MessageText:
//
//  A System level API call failed.
//  %n%nSource: %1, %2 
//
#define NCR_SYSTEM_CALL_FAILURE          ((DWORD)0xC005C355L)

// Parameter 1 - Source Description
// Parameter 2 - Description of the NT Driver trying to open.
// Parameter 3 - Driver file name.
// Parameter 4 - Registry key for the driver.
//               
//               
//					
// Data: GetLastError() result after the CreateFile() attempt failed.
//       If not possible to retrieve the value is 0.

//
// MessageId: NCR_NO_NT_DRIVER
//
// MessageText:
//
//  The NT Device Driver could not be opened.%n
//  %nMeaning - %1, 
//  could not open the %2 Driver.  The %3 driver must be installed correctly. 
//  If the driver is installed correctly, it could have an internal problem 
//  initializing.  See Data for the GetLastError() status results.%n
//  %nAction - Verify that the %3 driver is installed.  Since it is 
//  loaded during NT System Startup, a reboot is necessary after the driver is
//  first installed.  The file should be located in the \<winnt>\system32\drivers 
//  directory.  The registry should have the following information: 
//  [HKEY_LOCAL_MACHINE\System\CurrentControlSet\Services\%4]
//  "ErrorControl"=dword:00000001
//  "Start"=dword:00000001
//  "Type"=dword:00000001
//  If it is believed to be loaded correctly, a NET STOP %4 and corresponding
//  NET START %4 should succeed at the command prompt.  If this is an NCR Driver
//  consult, the FitClient Help File for information about configuring this
//  Driver.  View the 'System' Event Log to see if there are any events related to the
//  driver in question.  Contact your NCR service representative for more information.%n
//
#define NCR_NO_NT_DRIVER                 ((DWORD)0xC007C356L)

// Parameter 1: Source Description
// Parameter 2: Registry Key
//					
// Data: Win32 API error code

//
// MessageId: NCR_OPEN_REGISTRY
//
// MessageText:
//
//  Unable to open a registry key.
//  %n%nMeaning:
//  %n%1 could not open the registry key:
//  %n%nHKEY_LOCAL_MACHINE\%2
//
#define NCR_OPEN_REGISTRY                ((DWORD)0xC005C357L)

//   Data: none.
//
//
// MessageId: NCR_FITCLIENTAGENT_START
//
// MessageText:
//
//  The NCR FitClient Agent DLL has started successfully.
//
#define NCR_FITCLIENTAGENT_START         ((DWORD)0x4001C358L)

//   Data: none.
//
//
// MessageId: NCR_SYSTEMMONITOR_START
//
// MessageText:
//
//  The NCRSystemMonitor DLL has started successfully.
//
#define NCR_SYSTEMMONITOR_START          ((DWORD)0x4001C359L)

// Parameter 1 - Source Description
// Parameter 2 - Description of the driver (vxd) trying to open.
// Parameter 3 - Driver file name.
// Parameter 4 - Registry key for the driver.
//               				
// Data: GetLastError() result after the CreateFile() attempt failed.
//       If not possible to retrieve the value is 0.

//
// MessageId: NCR_NO_VXD
//
// MessageText:
//
//  The Windows 9X VXD Device Driver could not be opened.%n
//  Meaning :
//  %1 could not open the %2 device driver.
//  Check that the driver is installed correctly. If the driver is installed
//  correctly, it could have an internal problem initializing. See Data for
//  the Win32 API error code.%n
//  Action :
//  Verify that the driver is installed. Since it is loaded during startup,
//  a reboot is necessary after the driver is first installed. The file %3
//  should be located in the \<windows>\system directory. The registry should
//  have the following information:%n
//  [HKEY_LOCAL_MACHINE\System\CurrentControlSet\Services\VxD\%4]
//  "DisplayName"="%2"
//  "StaticVxD"="%3"%n
//  If this is an NCR Driver, consult the FitClient help file for information
//  about configuring this driver. Contact your NCR service representative
//  for more information.
//
#define NCR_NO_VXD                       ((DWORD)0xC007C35AL)

// Parameter 1 - Source Description
// Parameter 2 - Description of the driver trying to open
// Parameter 3 - Driver file name
// Parameter 4 - Registry key for the driver
// Parameter 5 - Driver Prefix
//               				
// Data: GetLastError() result after the CreateFile() attempt failed.
//       If not possible to retrieve the value is 0.

//
// MessageId: NCR_NO_CE_DRIVER
//
// MessageText:
//
//  The Windows CE Device Driver could not be opened.%n
//  Meaning :
//  %1 could not open the %2 device driver.
//  Check that the driver is installed correctly. If the driver is installed
//  correctly, it could have an internal problem initializing. See Data for
//  the Win32 API error code.%n
//  Action :
//  Verify that the driver is installed. If the driver is not installed, the
//  image must be rebuilt to include the driver. The file %3
//  should be located in the \<windows> directory. The registry should
//  have the following information:%n
//  [HKEY_LOCAL_MACHINE\Software\Drivers\BuiltIn\%4]
//  "Order"=dword:00000001
//  "Prefix"="%5"
//  "Dll"="%3"
//  Contact your NCR service representative for more information.
//
#define NCR_NO_CE_DRIVER                 ((DWORD)0xC007C35BL)

// Parameter 1 - Source Description
// Parameter 2 - Registry Key
// Parameter 3 - Registry Value
//               				
// Data: Win32 API error code

//
// MessageId: NCR_REGISTRY_READ_VALUE
//
// MessageText:
//
//  Unable to open read a registry value.
//  %n%nMeaning:
//  %n%1 could not read the registry value:
//  %n%nHKEY_LOCAL_MACHINE\%2\%3
//
#define NCR_REGISTRY_READ_VALUE          ((DWORD)0xC005C35CL)

// Parameter 1 - Source Description
// Parameter 2 - Registry Key
// Parameter 3 - Registry Value
// Parameter 4 - Registry Value Data
//               				
// Data: Win32 API error code

//
// MessageId: NCR_REGISTRY_WRITE_VALUE
//
// MessageText:
//
//  Unable to write a registry value.
//  %n%nMeaning:
//  %n%1 could not write the registry value:
//  %nHKEY_LOCAL_MACHINE\%2\%3
//  %nData: %4
//
#define NCR_REGISTRY_WRITE_VALUE         ((DWORD)0xC005C35DL)

// Parameter 1: Source Description.
// Parameter 2: Name of the internal API that failed if known,
//
// Data: Error code

//
// MessageId: NCR_INTERNAL_INTERFACE_CALL_FAILURE
//
// MessageText:
//
//  An internal interface API call failed!
//  %n%nSource: %1, %2
//
#define NCR_INTERNAL_INTERFACE_CALL_FAILURE ((DWORD)0xC007C35EL)

// Parameter 1: Source Description.
// Parameter 2: Name of the internal API that failed if known,
//
// Data: Error code

//
// MessageId: NCR_NO_STORE_MINDER_SUPPORT
//
// MessageText:
//
//  Unable to access Store Minder API.
//  %n%nSource: %1 
//
#define NCR_NO_STORE_MINDER_SUPPORT      ((DWORD)0x8001C35FL)

// ---------------------------------------------------------------------------------
//	Diagnostic Event Log Messages
// Source:  
// MessageId Range Diagnostic Events: 50050 - 50099
// ---------------------------------------------------------------------------------
//

// Parameter 1 - Source Description.
//					
// Data: none.

//
// MessageId: NCR_SERIAL_PORT_DIAGNOSTIC_CONTROL_NOT_ENABLED
//
// MessageText:
//
//  Serial Port Diagnostic control not available.%n
//  Source - %1
//
#define NCR_SERIAL_PORT_DIAGNOSTIC_CONTROL_NOT_ENABLED ((DWORD)0x8007C382L)

//
// Parameter 1 - Source Description.
//					
// Data: none.
//
//
// MessageId: NCR_SERIAL_PORT_TEST_FAILED
//
// MessageText:
//
//  Serial Port Failed Turn Around Test.%n
//  %nSource - %1
//
#define NCR_SERIAL_PORT_TEST_FAILED      ((DWORD)0xC007C383L)

//
// Parameter 1 - Source Description.
//					
// Data: none.
//
//
// MessageId: NCR_AUDIO_DIAGNOSTIC_CONTROL_NOT_ENABLED
//
// MessageText:
//
//  Audio Diagnostic control not available.%n
//  %nSource - %1
//
#define NCR_AUDIO_DIAGNOSTIC_CONTROL_NOT_ENABLED ((DWORD)0x8007C384L)

//
// Parameter 1 - Source Description.
//					
// Data: none.
//
//
// MessageId: NCR_AUDIO_TEST_FAILED
//
// MessageText:
//
//  User failed to hear audio playback.%n
//  %nSource - %1
//
#define NCR_AUDIO_TEST_FAILED            ((DWORD)0xC007C385L)

// ---------------------------------------------------------------------------------
//	POST Errors Event Log Messages
// Source:                         
// MessageId Range Diagnostic Events: 50100 - 50199
// ---------------------------------------------------------------------------------
//
//
//
//
// Parameter 1 - Source Description.
//					
// Data: Byte 1 is Error Class and Byte 2 Error Code returned from the BIOS.
//	
// Error Class (hex): Will contain one of the following,
//
// 01h - System
// 02h - Extended
// 03h - EISA
// 04h - PNP ISA
// 05h - PCI
// 06h - MCD
// 07h - USB
//
//	Error Code (hex): Will contain one of the following,
//
// 00h - Disk
// 01h - Keyboard
// 02h - Video
// 03h - Memory  
// 04h - POST/timeout
// 05h - CMOS
// 06h - Timer
//
//
///////////////////////////////////////////////////////////////////////////////////
//
// Added by SandyS 
// TAR # 84196
//
// The following is the 7454 FitClient POST Error Table
//
// Error Number		Error Message
//-------------		-------------
//	0200				Failure Fixed Disk
//	0201				MotherBoard Configurable Device Warning
// 0202				MotherBoard Configurable Device Error
// 0210				Stuck Key
// 0211				Keyboard Error
// 0212				Keyboard Controller Failed
// 0213				Keyboard Locked - Unlock Key Switch
//	0220				Monitor Type Does Not Match CMOS - Run Setup
// 0230				System RAM Failed at OFFSET:
// 0231				Shadow RAM Failed at OFFSET:
// 0232				Extended RAM Failed at OFFSET:
// 0233				Memory Type Mixing Detected     
// 0234				Single-Bit ECC Error Occurred
// 0235				Mutliple-Bit ECC Error Occurred
// 0250				System Battery is Dead - Replace and Run Setup
// 0251				System CMOS Checksum Bad - Default Configuration Used
// 0260				System Timer Error
// 0270				Real Time Clock Error
// 0271				Check Date and Time Settings
// 0280				Previous Boot Incomplete - Default Configuration Used
// 0281				Memory Size Found by POST Differed from EISA CMOS
// 02B0				Diskette Drive A Error
// 02B1				Diskette Drive B Error
// 02B2				Incorrect Drive A Type - Run Setup
// 02B3				Incorrect Drive B Type - Run Setup
// 02D0				System Cache Error - Cache Disabled
// 02F0				CPU ID:
// 02F4				EISA CMOS Not Writable
// 02F5				DMA Test Failed
// 02F6				Software NMI Failed
// 02F7				Fail-Safe Timer NMI Failed
// 02F8				CPU OverTemperature Error
// 02F9				System OverTemperature Error
// 02FA				Cannot Read CPU Temperature
// 02FB				Cannot Read System Temperature
// 02FC				SMB Connect Failed
// 02FD				SMB Clock Chip Init Failed
// 02FE				Batter Not Installed
// 0400				PnP ESCD Checksum Error
// 0401				PnP ESCD Read Error
// 0402				PnP ESCD Write Error
// 0403				PnP Device Node Allocation Error
// 0404				PnP Device Allocation Error
// 0405				PnP Option ROM Allocation Error
// 0406				PnP Interrupt Allocation Error
//	0504				PCI Device Allocation Error
//	0505				PCI Option ROM Allocation Error
//	0506				PCI Interrupt Allocation Error
//
///////////////////////////////////////////////////////////////////////////////////
//
//
// MessageId: NCR_POST_FAILURE
//
// MessageText:
//
//  POST has issued a general diagnostic failure.%n
//  %nSource - %1
//
#define NCR_POST_FAILURE                 ((DWORD)0xC007C3B4L)

//
// Parameter 1 - Source Description.
//					
// Data: none.
//
//
// MessageId: NCR_POST_RAM_ADDRESS_LINE_FAILURE
//
// MessageText:
//
//  POST Failure Code 0x2C - RAM failure on address line.%n
//  %nSource - %1
//
#define NCR_POST_RAM_ADDRESS_LINE_FAILURE ((DWORD)0xC007C3B5L)

//
// Parameter 1 - Source Description.
//					
// Data: none.
//
//
// MessageId: NCR_POST_RAM_LO_DATA_BYTE_FAILURE
//
// MessageText:
//
//  POST Failure Code 0x2E - RAM failure on low data byte.%n
//  %nSource - %1
//
#define NCR_POST_RAM_LO_DATA_BYTE_FAILURE ((DWORD)0xC007C3B6L)

//
// Parameter 1 - Source Description.
//					
// Data: none.
//
//
// MessageId: NCR_POST_RAM_HI_DATA_BYTE_FAILURE
//
// MessageText:
//
//  POST Failure Code 0x30 - RAM failure on hi data byte.%n
//  %nSource - %1
//
#define NCR_POST_RAM_HI_DATA_BYTE_FAILURE ((DWORD)0xC007C3B7L)

//
// Parameter 1 - Source Description.
//					
// Data: none.
//
//
// MessageId: NCR_POST_CONFIGURATION_ERROR
//
// MessageText:
//
//  POST Failure Code 0x72 - Configuration Error.%n
//  %nSource - %1
//
#define NCR_POST_CONFIGURATION_ERROR     ((DWORD)0xC007C3B8L)

//
// Parameter 1 - Source Description.
//					
// Data: none.
//
//
// MessageId: NCR_POST_REINITIALIZE_ONBOARD_IO_PORTS_FAILURE
//
// MessageText:
//
//  POST Failure Code 0x86 - Re-initialize onboard I/O ports.%n
//  %nSource - %1
//
#define NCR_POST_REINITIALIZE_ONBOARD_IO_PORTS_FAILURE ((DWORD)0xC007C3B9L)

//
// Parameter 1 - Source Description.
//					
// Data: none.
//
//
// MessageId: NCR_POST_INITIALIZE_HARD_DISK_CONTROLLER_FAILURE
//
// MessageText:
//
//  POST Failure Code 0x90 - Initialize hard disk controller failure.%n
//  %nSource - %1
//
#define NCR_POST_INITIALIZE_HARD_DISK_CONTROLLER_FAILURE ((DWORD)0xC007C3BAL)

// ---------------------------------------------------------------------------------
//	SRMS/CRMS Event Log Messages
// Source:  NCRSRMS.EXE
//          NCRFitClientAgent.DLL
//			 NCRDLLLoader(App).EXE
// MessageId Range Diagnostic Events: 50200 - 50249
// ---------------------------------------------------------------------------------
//
//
//
//
//		Parameter 1:	Source Description
//		Parameter 2:	Thread Name
//		Data:			Win 32 API error code
//
//
// MessageId: NCR_RMS_BASETHREAD_CREATION_FAILURE
//
// MessageText:
//
//  The creation of a main service thread failed!%n
//  Failed to create the '%2' thread at service startup.%n
//
#define NCR_RMS_BASETHREAD_CREATION_FAILURE ((DWORD)0xC001C418L)

//	  Parameter 1 - Source Description
//	  Parameter 2 - Event/Mutex Name
//
//	  Data: Win32 errorcode.
//
//
// MessageId: NCR_RMS_SYNCHOBJECT_CREATION_FAILURE
//
// MessageText:
//
//  The creation of a synchronization object failed!%n
//  %nSource - %1,
//  Event/Mutex Name - %2
//
#define NCR_RMS_SYNCHOBJECT_CREATION_FAILURE ((DWORD)0xC001C419L)

//	  Parameter 1 - Source Description
//	  Parameter 2 - Event/Mutex Name
//
//	  Data: Win32 errorcode.
//
//
// MessageId: NCR_RMS_CRITICAL_SYNCHOBJECT_FAILURE
//
// MessageText:
//
//  The use of a critical synchronization object failed!%n
//  %nSource - %1,
//  Event/Mutex Name - %2
//
#define NCR_RMS_CRITICAL_SYNCHOBJECT_FAILURE ((DWORD)0xC005C41AL)

//	  Parameter 1 - Source Description
//	  Parameter 2 - Module Name
//	  Parameter 3 - Registry Path
//	  Parameter 4 - Registry Value Name
//
//	  Data: Win32 errorcode.
//
//
// MessageId: NCR_RMS_CRITICAL_REGISTRY_FAILURE
//
// MessageText:
//
//  A critical registry access failed!
//  %n%nMeaning:
//  %n%1 failed in the %2 module due to a registry access failure.
//  %n%nRegistry Path - HKEY_LOCAL_MACHINE\%3
//  %nRegistry Value Name - %4
//
#define NCR_RMS_CRITICAL_REGISTRY_FAILURE ((DWORD)0xC005C41BL)

//   Parameter 1 - Source Description
//	  Parameter 2 - Method Name
//					
//   Data: CTransport errorcode.
//
//
// MessageId: NCR_RMS_CTRANSPORT_INIT_FAILURE
//
// MessageText:
//
//  The initialization of the CTransport class failed!
//  %n%nSource: %1, %2
//
#define NCR_RMS_CTRANSPORT_INIT_FAILURE  ((DWORD)0xC001C41CL)

//	  Parameter 1 - Source Description
//	  Parameter 2 - Thread Type
//
//	  Data: Win32 errorcode
//
//
// MessageId: NCR_RMS_WORKERTHREAD_CREATION_FAILURE
//
// MessageText:
//
//  The creation of a worker thread failed!%n
//  %nSource - %1, %2
//
#define NCR_RMS_WORKERTHREAD_CREATION_FAILURE ((DWORD)0xC005C41DL)

//	  Parameter 1 - Source Description
//   Parameter 2 - Method Name
//					
//   Data: CTransport errorcode.
//
//
// MessageId: NCR_RMS_CTRANSPORT_GENERAL_FAILURE
//
// MessageText:
//
//  A general registry transport class function failed!
//  %n%nSource: %1, %2
//
#define NCR_RMS_CTRANSPORT_GENERAL_FAILURE ((DWORD)0x8005C41EL)

//	  Parameter 1 - Source Description
//					
//   Data: Win32 errorcode.
//
//
// MessageId: NCR_RMS_NONCRITICAL_SYNCHRONIZATION_FAILURE
//
// MessageText:
//
//  A non-critical Synchronization access/command failed!%n
//  %nSource - %1
//
#define NCR_RMS_NONCRITICAL_SYNCHRONIZATION_FAILURE ((DWORD)0x8005C41FL)

// Parameter 1: Source Description
// Parameter 2: Registry Key
// Parameter 3: API
// Parameter 4: Method
//
// Data: Win 32 API error code
//
//
// MessageId: NCR_RMS_NONCRITICAL_REGISTRY_FAILURE
//
// MessageText:
//
//  A non-critical registry access failed!
//  %n%nMeaning:
//  %n%1, function %4, failed to execute the Win32 Registry API %3.
//  %n%nRegistry Key: HKEY_LOCAL_MACHINE\%2
//
#define NCR_RMS_NONCRITICAL_REGISTRY_FAILURE ((DWORD)0x8005C420L)

// Parameter 1: Source Description
// Parameter 2: Registry Key
// Parameter 3: Registry Value
//	Parameter 4: Default value
//					
// Data: none
//
//
// MessageId: NCR_RMS_USING_DEFAULT_VALUE
//
// MessageText:
//
//  Using default start-up parameter!
//  %n%nMeaning:
//  Unable to read the registry value 
//  %n%nHKEY_LOCAL_MACHINE\%2\%3
//  %n%nat service start. The default value of %4 will be used.
//  %n%nAction :
//  %nNone required.
//
#define NCR_RMS_USING_DEFAULT_VALUE      ((DWORD)0x4001C421L)

//   Parameter 1 - Source Description
//					
//   Data: SerReg errorcode.
//
//
// MessageId: NCR_RMS_SERIAL_INIT_FAILURE
//
// MessageText:
//
//  Serial Registry Data class Initialization failure!%n
//  %nSource - %1
//
#define NCR_RMS_SERIAL_INIT_FAILURE      ((DWORD)0xC001C422L)

//   Parameter 1 - Source Description
//	  Parameter 2 - Method Name
//					
//   Data: SerReg errorcode.
//
//
// MessageId: NCR_RMS_SERIAL_GENERAL_FAILURE
//
// MessageText:
//
//  Critical Serial Registry Data class method failed!%n
//  %nMeaning - %1, %2
//
#define NCR_RMS_SERIAL_GENERAL_FAILURE   ((DWORD)0xC001C423L)

// ---------------------------------------------------------------------------------
//	CCL Event Log Messages
// Source:  NCRFitClientAgent DLL
// MessageId Range Diagnostic Events: 50250 - 50299
// ---------------------------------------------------------------------------------
//
//   Parameter 1 - Source Description.
//   Parameter 2 - Manufacturer name from DMI System Information
//   Parameter 3 - Class/Model from DMI System Information
//   Parameter 4 - Serial Number from DMI System Information
//   Parameter 5 - BIOS Version from DMI System Information
//   Parameter 6 - BIOS Release Date from DMI System Information
//					
//   Data: none.
//
//
// MessageId: NCR_CCL_CMS_DATA
//
// MessageText:
//
//  Workstation Class, Model, Serial Number, and BIOS version data.%n
//  %nMeaning - %1,
//  the workstation's data was read from the DMI System Information structure.  This data
//  is stored in the DMI BIOS.%n
//  %nManufacturer: %2
//  %nClass-Model: %3
//  %nSerial Number: %4
//  %nBIOS Version: %5
//  %nBIOS Date: %6%n
//  %nAction - Update any CCL repository with this workstation's Class, Model
//  and Serial Number data.%n
//
#define NCR_CCL_CMS_DATA                 ((DWORD)0x4011C44AL)

//   Parameter 1 - Source Description.
//   Parameter 2 - Old Serial Number found in registry
//   Parameter 3 - New Serial Nubmer from DMI System Information
//					
//   Data: none.
//
//
// MessageId: NCR_CCL_SN_CHANGED
//
// MessageText:
//
//  Serial Number for workstation has changed.%n
//  %nSource - %1,
//  %nOldSerialNumber: %2
//  %nNewSerialNumber: %3%n
//
#define NCR_CCL_SN_CHANGED               ((DWORD)0x8011C44BL)

//   Parameter 1 - Source Description.
//					
//   Data: none.
//
//
// MessageId: NCR_CCL_SN_INVALID
//
// MessageText:
//
//  Serial Number for workstation is invalid.%n
//  %nSource - %1
//
#define NCR_CCL_SN_INVALID               ((DWORD)0xC003C44CL)

//   Parameter 1 - Source Description.
//   Parameter 2 - Old Class/Model found in registry
//   Parameter 3 - New Class/Model from DMI System Information
//					
//   Data: none.
//
//
// MessageId: NCR_CCL_CM_CHANGED
//
// MessageText:
//
//  Class/Model for workstation has changed.%n
//  %nSource - %1,
//  %nOldClassModel: %2
//  %nNewClassModel: %3%n
//
#define NCR_CCL_CM_CHANGED               ((DWORD)0x8011C44DL)

//   Parameter 1 - Source Description.
//   Parameter 2 - Old BIOS Version found in registry
//   Parameter 3 - New BIOS Version from DMI System Information
//					
//   Data: none.
//
//
// MessageId: NCR_CCL_VER_CHANGED
//
// MessageText:
//
//  BIOS Version for workstation has changed.%n
//  %nSource - %1,
//  %nOldBIOSVersion: %2
//  %nNewBIOSVersion: %3%n
//
#define NCR_CCL_VER_CHANGED              ((DWORD)0x8011C44EL)

//   Parameter 1 - Source Description.
//					
//   Data: none.
//
//
//
// MessageId: NCR_CCL_CMOS_ACCESS
//
// MessageText:
//
//  The CCL agent (NCRFitClientAgent DLL) cannot access CMOS.%n
//  %nMeaning - %1,
//
#define NCR_CCL_CMOS_ACCESS              ((DWORD)0xC007C44FL)

//   Parameter 1 - Source Description.
//   Parameter 2 - Filename.
//   Parameter 3 - File version.
//					
//   Data: none.
//
//
//
//
// MessageId: NCR_CCL_FILE_VERSION_HAS_CHANGED
//
// MessageText:
//
//  The CCL agent (NCRFitClientAgent DLL) has detected that a file version has changed.%n
//  %nMeaning - %1,
//  The CCL agent (NCRFitClientAgent DLL) has detected that file %2 has a new version %3.%n
//  %nAction - None.%n
//
#define NCR_CCL_FILE_VERSION_HAS_CHANGED ((DWORD)0x8007C450L)

//   Parameter 1 - Source Description.
//   Parameter 2 - Name of missing file.
//					
//   Data: none.
//
//					
//
// MessageId: NCR_CCL_FILE_NOT_FOUND
//
// MessageText:
//
//  The CCL agent (NCRFitClientAgent DLL) cannot find file.%n
//  %nMeaning - %1,
//  The CCL agent (NCRFitClientAgent DLL) cannot find file(s) '%2'. The version will be left
//  blank.%n
//  %nAction - None.%n
//
#define NCR_CCL_FILE_NOT_FOUND           ((DWORD)0x8007C451L)

//   Parameter 1 - Source Description.
//   Parameter 2 - File Name
//					
//   Data: none.
//
//
//
// MessageId: NCR_CCL_FILE_NO_VERSION_INFO
//
// MessageText:
//
//  Cannot find file version information.%n
//  %nMeaning - %1,
//  The file %2 does not contain file version information.  The version information
//  in the registry will be blank.%n
//  %nAction - None.%n
//
#define NCR_CCL_FILE_NO_VERSION_INFO     ((DWORD)0x8007C452L)

//   Parameter 1 - Source Description.
//   Parameter 2 - Registry Key that is being updated.
//   Parameter 3 - Registry Value under the Registry Key being updated.
//					
//   Data: GetLastError() result.
//
//
// MessageId: NCR_CCL_CANNOT_WRITE_MAC_ADDRESS
//
// MessageText:
//
//  Unable to update the MAC Address in the system registry.%n
//  %nMeaning - %1,
//  the RegWriteValue API failed while trying to update the system registry 
//  key "%2" value "%3", with the Network Adapters MAC Address.%n
//
#define NCR_CCL_CANNOT_WRITE_MAC_ADDRESS ((DWORD)0xC00BC453L)

//   Parameter 1 - Source Description.
//   Parameter 2 - NT Network Adapter Driver name.
//					
//   Data: Number of bytes returned.
//
//
// MessageId: NCR_CCL_INVALID_BUFFER_SIZE
//
// MessageText:
//
//  Incorrect data returned from NT Network Adapter Driver.%n
//  %nSource - %1, %2
//
#define NCR_CCL_INVALID_BUFFER_SIZE      ((DWORD)0xC010C454L)

//   Parameter 1 - Source Description.
//   Parameter 2 - Task Description.
//					
//   Data: none.
//
//
// MessageId: NCR_CCL_TASK_INCOMPLETE
//
// MessageText:
//
//  Service was terminated before completing all tasks.%n
//  %nMeaning - %1,
//  the %2 task could not be completed, because the service was stopped or shutdown.%n
//  %nAction - Restart the service.%n
//
#define NCR_CCL_TASK_INCOMPLETE          ((DWORD)0xC011C455L)

//   Parameter 1 - Source Description.
//   Parameter 2 - Name of DMI text file.
//					
//   Data: none.
//
//
// MessageId: NCR_CCL_READDMI_FAILURE
//
// MessageText:
//
//  Unable to read the DMI data while retrieving Class/Model/SerialNumber.%n
//  %nSource - %1, %2
//  
//
#define NCR_CCL_READDMI_FAILURE          ((DWORD)0xC011C456L)

//   Parameter 1 - Source Description.
//   Parameter 2 - Name of DMI text file.
//					
//   Data: none.
//
//
// MessageId: NCR_CCL_DMI_EMPTY
//
// MessageText:
//
//  DMI Information has not been populated..%n
//
#define NCR_CCL_DMI_EMPTY                ((DWORD)0x8011C457L)

// ---------------------------------------------------------------------------------
//	System Monitor Event Log Messages
// Source:  NCRSystemMonitor
// MessageId Range System Monitor Events: 50300 - 50349
// ---------------------------------------------------------------------------------
// Parameter 1 - Description.
// Parameter 2 - Source temperature sensor, LM78, LM75, or LM87.
//				  
//					
//					
// Data: None

//
// MessageId: NCRMSG_EVENT_TEMP_SAFE
//
// MessageText:
//
//  Transition of one of the temperature sensors back into a SAFE state.%n
//  %nMeaning - %1, 
//  source of the temperature sensor is the %2.%n
//
#define NCRMSG_EVENT_TEMP_SAFE           ((DWORD)0x400FC47CL)

// Parameter 1 - Description.
// Parameter 2 - Source temperature sensor, LM78, LM75, or LM87.
//					
//					
// Data: None

//
// MessageId: NCRMSG_EVENT_TEMP_WARNING
//
// MessageText:
//
//  Transition of one of the temperature sensors to WARNING state.%n
//  %nMeaning - %1, 
//  source of the temperature sensor is the %2.%n
//  %nAction - Contact your NCR representative for more information.%n
//
#define NCRMSG_EVENT_TEMP_WARNING        ((DWORD)0xC00FC47DL)

// Parameter 1 - Description.
// Parameter 2 - Source temperature sensor, LM78, LM75, or LM87.
//					
//					
// Data: None

//
// MessageId: NCRMSG_EVENT_TEMP_CRITICAL
//
// MessageText:
//
//  Transition of one of the temperature sensors to a CRITICAL state.%n
//  %nMeaning - %1, 
//  source of the temperature sensor is the %2. The system will automatically 
//  be shutdown and will be restarted once the system returns to a SAFE
//  operating temperature range.%n
//  %nAction - Contact your NCR representative for more information.%n
//
#define NCRMSG_EVENT_TEMP_CRITICAL       ((DWORD)0xC00FC47EL)

// Parameter 1 - Description.
//					
//					
// Data: None

//
// MessageId: NCRMSG_EVENT_LINK_UP
//
// MessageText:
//
//  The LAN Link is back up after a link down.%n
//  %nMeaning - %1, 
//  No action necessary.%n
//
#define NCRMSG_EVENT_LINK_UP             ((DWORD)0x400FC47FL)

// Parameter 1 - Description.
//					
//					
// Data: None

//
// MessageId: NCRMSG_EVENT_LINK_DOWN
//
// MessageText:
//
//  The LAN Link went down.%n
//  %nSource - %1
//
#define NCRMSG_EVENT_LINK_DOWN           ((DWORD)0x800FC480L)

// Parameter 1 - Description.
// Parameter 2 - Source power supply.
//					
//					
// Data: 
//     Word 1 - Voltage read
//     Word 2 - Voltage limit exceeded

//
// MessageId: NCRMSG_EVENT_VOLTAGE
//
// MessageText:
//
//  The voltage supply is out of range.%n
//  %nMeaning - %1, 
//  the voltage supply %2 is out of range (either too low or too high).%n
//
#define NCRMSG_EVENT_VOLTAGE             ((DWORD)0xC00FC481L)

// Parameter 1 - Description.
//					
//					
// Data: None

//
// MessageId: NCRMSG_EVENT_ABNORMAL_SHUTDOWN
//
// MessageText:
//
//  The system was not shutdown.%n
//  %nSource - %1
//
#define NCRMSG_EVENT_ABNORMAL_SHUTDOWN   ((DWORD)0xC00FC482L)

// Parameter 1 - Description.
//					
//					
// Data: None

//
// MessageId: NCRMSG_EVENT_SHUTDOWN_THERMAL
//
// MessageText:
//
//  The system was reset after a CRITICAL temperature event was ignored.%n
//  %nSource - %1
//
#define NCRMSG_EVENT_SHUTDOWN_THERMAL    ((DWORD)0xC00FC483L)

// Parameter 1 - Description.
//					
//					
// Data: None

//
// MessageId: NCRMSG_EVENT_SHUTDOWN_FORCED
//
// MessageText:
//
//  The system was shutdown via NCRSYSM_IOCTL_FORCE_RESET.%n
//  %nSource - %1
//
#define NCRMSG_EVENT_SHUTDOWN_FORCED     ((DWORD)0xC00FC484L)

// Parameter 1 - Description.
//					
//					
// Data: None

//
// MessageId: NCRMSG_EVENT_LOST
//
// MessageText:
//
//  A system management event was lost.%n
//  %nSource - %1
//
#define NCRMSG_EVENT_LOST                ((DWORD)0xC00FC485L)

// Parameter 1 - Description.
//               
//					
// Data: GetLastError() result after the CreateFile() attempt failed.
//       If not possible to retrieve the value is 0.

//
// MessageId: NCRMSG_EVENT_UNKNOWN
//
// MessageText:
//
//  Unknown event.%n
//  %nSource - %1
//
#define NCRMSG_EVENT_UNKNOWN             ((DWORD)0xC007C486L)

// Parameter 1 - Description.
// Parameter 2 - Name of the method: GetPropertyNumber,
//	              SetPropertyNumber
//					
//					
// Data: Contains the illegal Property index value (LONG).
//
//
// MessageId: NCRMSG_PROPERTY_INDEX_ILLEGAL
//
// MessageText:
//
//  Bad property index.%n
//  %nSource - %1, %2 
//
#define NCRMSG_PROPERTY_INDEX_ILLEGAL    ((DWORD)0xC007C487L)

// Parameter 1 - Description.
// Parameter 2 - The configuration parameter registry value. 
// Parameter 3 - The invalid configuration parameter registry value data.
//					
// Data: None

//
// MessageId: NCRMSG_CONFIG_PARAMETER_INVALID
//
// MessageText:
//
//  Invalid configuration parameter in the registry.%n
//  %nMeaning - %1, 
//  could not initialize because the "%2" registry parameter has invalid 
//  data: "%3".%n
//  %nAction - Contact your NCR representative for more information.%n
//
#define NCRMSG_CONFIG_PARAMETER_INVALID  ((DWORD)0xC003C489L)

// Parameter 1 - Description.
//					
//					
// Data: GetLastError() result API call failed.

//
// MessageId: NCRMSG_CANNOT_LOAD_SM_DLL
//
// MessageText:
//
//  LoadLibrary() failed to load the "NCRSystemMonitor.dll".%n
//  %nSource - %1
//
#define NCRMSG_CANNOT_LOAD_SM_DLL        ((DWORD)0xC001C48CL)

// Parameter 1 - Description.
//					
//					
// Data: GetLastError() result API call failed.

//
// MessageId: NCRMSG_BAD_SM_DLL
//
// MessageText:
//
//  Invalid "NCRSystemMonitor.dll".%n
//  %nSource - %1
//
#define NCRMSG_BAD_SM_DLL                ((DWORD)0xC001C48DL)

// Parameter 1 - Description.
//					
//					
// Data: GetLastError() result after the CreateFile() attempt failed.
//       If not possible to retrieve the value is 0.

//
// MessageId: NCRMSG_NO_SM_SERVICE
//
// MessageText:
//
//  The NCRSystemMonitor interface could not be opened.%n
//  %nSource - %1
//
#define NCRMSG_NO_SM_SERVICE             ((DWORD)0xC007C48EL)

// Parameter 1 - Description.
//               
//					
// Data: None.

//
// MessageId: NCRMSG_UA_ALREADY_RUNNING
//
// MessageText:
//
//  The application is already running.%n
//  %nMeaning - %1, 
//  the User Alert application is already running.%n
//  %nAction - Contact your NCR representative for more information%n.
//
#define NCRMSG_UA_ALREADY_RUNNING        ((DWORD)0xC001C48FL)

// Parameter 1 - Description.
// Parameter 2 - Parameters.
//					
//					
// Data: None

//
// MessageId: NCRMSG_UA_NO_LAUNCH
//
// MessageText:
//
//  Unable to launch a browser.%n
//  %nSource - %1
//
#define NCRMSG_UA_NO_LAUNCH              ((DWORD)0xC005C490L)

// Parameter 1 - Description.
// Parameter 2 - Name of the System API that failed if known,
// Parameter 3 - Registry Parameter.
//					
//					
// Data: None

//
// MessageId: NCRMSG_UA_AUTOEXEC_ERROR
//
// MessageText:
//
//  Unable to execute the function in relation to the registry change.%n
//  %nMeaning - %1, 
//  could not execute the function in relation to the registry change, 
//  the %2 API failed with invalid data "%3".%n
//  %nAction - Verify that registry parameters are correct.%n
//
#define NCRMSG_UA_AUTOEXEC_ERROR         ((DWORD)0xC012C491L)

// Parameter 1 - Description.
//					
//					
// Data: 
//     Word 1 - Fan RPM read (0 if below minimum that can be read)
//     Word 2 - Fan range exceeded

//
// MessageId: NCRMSG_EVENT_FAN_FAILURE
//
// MessageText:
//
//  A fan failure has occurred.%n
//  %nSource - %1
//
#define NCRMSG_EVENT_FAN_FAILURE         ((DWORD)0xC00FC492L)

// Parameters, Data: None

//
// MessageId: NCRMSG_UA_VOLUME_HANDLER_NOT_SUPPORTED
//
// MessageText:
//
//  Audio drivers not supported under Windows 95.%n
//  %nMeaning - The API required to control volume does not exist on Windows 95.%n
//
#define NCRMSG_UA_VOLUME_HANDLER_NOT_SUPPORTED ((DWORD)0x4011C493L)

// Parameter 1 - Description.
//					
//					
// Data: None

//
// MessageId: NCRMSG_EVENT_UNKNOWN_BOARDID
//
// MessageText:
//
//  System board ID is unknown.%n
//  %nMeaning - %1, 
//  The ID of the terminal system board is unknown.%n
//
#define NCRMSG_EVENT_UNKNOWN_BOARDID     ((DWORD)0xC00FC494L)

// Parameter 1 - Description.
//					
//					
// Data: None

//
// MessageId: NCRSYSM_BOARD_ID_CORRECT
//
// MessageText:
//
//  %1 Summa/SummaPOS Board ID fix applied. Correct Board ID written to EEPROM.
//
#define NCRSYSM_BOARD_ID_CORRECT         ((DWORD)0x4003C495L)

// ---------------------------------------------------------------------------------
//	NCR BINL and DHCP Event Log Messages
// Source:  
// MessageId Range System Monitor Events: 50400 - 50450
// ---------------------------------------------------------------------------------
//
// Parameter 1 - Description.
//				  
//					
//					
// Data: None

//
// MessageId: NCR_BINL_SERVICE_FAILURE
//
// MessageText:
//
//  The NCR BINL Server has encountered an error.%n
//  %nSource - %1
//
#define NCR_BINL_SERVICE_FAILURE         ((DWORD)0xC011C4E0L)

// Parameter 1 - Description.
//				  
//					
//					
// Data: None

//
// MessageId: NCR_BOOTFILE_LENGTH_ERROR
//
// MessageText:
//
//  The NCR BINL Server has encountered an error trying to send the bootfile name to the client.%n
//  %nSource - %1
//
#define NCR_BOOTFILE_LENGTH_ERROR        ((DWORD)0xC011C4E1L)

// Parameter 1 - Description.
//				  
//					
//					
// Data: None

//
// MessageId: NCR_IPADDRESS_OUT_OF_RANGE
//
// MessageText:
//
//  The NCR DHCP Server has encountered an error trying to assign an IP Address to the client.%n
//  %nSource - %1
//
#define NCR_IPADDRESS_OUT_OF_RANGE       ((DWORD)0xC011C4E2L)

// Parameter 1 - Source Description.
//					
// Data: None

//
// MessageId: NCR_DHCP_INVALID_IP_RANGE
//
// MessageText:
//
//  The IP address range configured for the NCR DHCP Server is invalid.%n
//  %nSource - %1 
//
#define NCR_DHCP_INVALID_IP_RANGE        ((DWORD)0xC011C4E3L)

// Parameter 1 - Source Description.
//					
// Data: None

//
// MessageId: NCR_DHCP_DISABLED
//
// MessageText:
//
//  The NCR DHCP Server is disabled.%n
//  %nSource - %1 
//
#define NCR_DHCP_DISABLED                ((DWORD)0xC011C4E4L)

// Parameter 1 - Source Description.
// Parameter 2 - Function
//					
// Data: Error Code

//
// MessageId: NCR_DHCP_SOCKET_ERR
//
// MessageText:
//
//  A socket error occurred with NCR DHCP Server.%n
//  %nMeaning - Winsock %2 call by %1 failed.  
//
#define NCR_DHCP_SOCKET_ERR              ((DWORD)0xC011C4E5L)

// Parameter 1 - Source Description.
//					
// Data: Error Code

//
// MessageId: NCR_DHCP_BCAST_WARN
//
// MessageText:
//
//  An error occurred when NCR DHCP Server attempted to enable the Broadcast option.%n
//  %nSource - %1
//
#define NCR_DHCP_BCAST_WARN              ((DWORD)0x8011C4E6L)

// Parameter 1 - Source Description.
// Parameter 2 - IP Address.
// Parameter 3 - MAC Address.
//					
// Data: None

//
// MessageId: NCR_DHCP_IP_DECLINED
//
// MessageText:
//
//  A DHCP client declined an IP Address offered.%n
//  %nSource - %1, Address %2, Client %3.
//
#define NCR_DHCP_IP_DECLINED             ((DWORD)0x8011C4E7L)

// Parameter 1 - Source Description.
// Parameter 2 - Function
//					
// Data: Error Code

//
// MessageId: NCR_DHCP_NO_DUP_CHECK
//
// MessageText:
//
//  NCR DHCP Server is configured to check for other DHCP Servers on the network, but it
//  was unable to perform this check.%n
//  %nMeaning - %1 may be configured to start only if it is the only DHCP Server on the
//  network.  %1, %2 
//
#define NCR_DHCP_NO_DUP_CHECK            ((DWORD)0x8011C4E8L)

// Parameter 1 - Source Description.
//					
// Data: None

//
// MessageId: NCR_DHCP_DUP_SERVER
//
// MessageText:
//
//  NCR DHCP Server will not start because another DHCP Server was found.%n
//  %nMeaning - %1
//
#define NCR_DHCP_DUP_SERVER              ((DWORD)0xC011C4E9L)

// Parameter 1 - Source Description.
//					
// Data: None

//
// MessageId: NCR_DHCP_NO_SUBNET_MASK
//
// MessageText:
//
//  The NCR DHCP Server could not obtain a valid subnet mask for the server.%n
//  %nSource - %1 
//
#define NCR_DHCP_NO_SUBNET_MASK          ((DWORD)0x8011C4EAL)

//   Parameter 1 - Source Description.
//					
//   Data: none.
//
//
// MessageId: NCR_DHCP_APPL_START
//
// MessageText:
//
//  The NCR DHCP Server application has started successfully.
//
#define NCR_DHCP_APPL_START              ((DWORD)0x4001C4EBL)

//
// Parameter 1 - Source Description.
//					
// Data: none.
//
//
// MessageId: NCR_DHCP_APPL_STOP
//
// MessageText:
//
//  The NCR DHCP Server application has stopped.
//
#define NCR_DHCP_APPL_STOP               ((DWORD)0x4002C4ECL)

// ---------------------------------------------------------------------------------
// NCR FitClient Agent Additional Event Log Messages
// Source:  NCR FitClient Agent
// MessageId Range: 50451 - 50500
// ---------------------------------------------------------------------------------
//

// Parameter 1: Source
//	
// Data: none

//
// MessageId: NCR_FCA_UNKNOWN_OPERATING_SYSTEM
//
// MessageText:
//
//  %1 could not resolve the current operating system platform.
//  %n%nMeaning:
//  %nYou may be attempting to run on an unsupported platform. 
//  %n%nAction:
//  %nContact your NCR representative for more information
//
#define NCR_FCA_UNKNOWN_OPERATING_SYSTEM ((DWORD)0xC005C513L)

// Parameter 1: Source
//	Parameter 2: Thread Name
//
// Data: none

//
// MessageId: NCR_FCA_BASETHREAD_DISABLED
//
// MessageText:
//
//  The %2 thread encountered errors and has been disabled. See
//  data for error code.
//  %n%nMeaning:
//  %nPart of the functionality of the %1 is no longer operationable.
//  %n%nAction:
//  %nContact your NCR representative for more information.
//
#define NCR_FCA_BASETHREAD_DISABLED      ((DWORD)0xC002C514L)

// Parameter 1: Source
//	Parameter 2: Thread Name
//
// Data: none

//
// MessageId: NCR_FCA_RESTORE_REGISTRY
//
// MessageText:
//
//  The RegRestoreFile Win32 API call failed! Registry information contained
//  in the file "%2" could not be imported. See data for Win32 error code.
//  %n%nMeaning:
//  %nRegistry data has not been restored from local storage. 
//  %n%nAction:
//  %nContact your NCR representative for more information
//
#define NCR_FCA_RESTORE_REGISTRY         ((DWORD)0xC005C515L)

// Parameter 1: Source
//	Parameter 2: Thread Name
//
// Data: none

//
// MessageId: NCR_FCA_SAVE_REGISTRY
//
// MessageText:
//
//  The RegCopyFile Win32 API call failed! Registry information could not be
//  exported to the file "%2". See data for Win32 error code.
//  %n%nMeaning:
//  %nRegistry data has not been persisted to local storage. 
//  %n%nAction:
//  %nContact your NCR representative for more information
//
#define NCR_FCA_SAVE_REGISTRY            ((DWORD)0xC005C516L)

// Parameter 1: Source
// Parameter 2: Hive
//	Parameter 3: Key
//
// Data: none

//
// MessageId: NCR_FCA_MONITORED_KEY_NOT_FOUND
//
// MessageText:
//
//  Requested key to be monitored does not exist.
//  %n%nMeaning:
//  %nThe following key does not exist and as such cannot be monitored
//  for changes.
//  %n%n%2\%3
//
#define NCR_FCA_MONITORED_KEY_NOT_FOUND  ((DWORD)0x8001C517L)

// No Parameters
//
// Data: none

//
// MessageId: NCR_FCA_FITCLIENTMANAGER_NOT_DISCOVERED
//
// MessageText:
//
//  Attempt to autodiscover the FitClient Manager Server failed.
//
#define NCR_FCA_FITCLIENTMANAGER_NOT_DISCOVERED ((DWORD)0x8001C518L)

// ---------------------------------------------------------------------------------
// NCR FitClient Loader Service Event Log Messages
// Source:  NCR FitClient Loader
// MessageId Range: 50501 - 50550
// ---------------------------------------------------------------------------------
//

// Parameter 1 - Source Description

//
// MessageId: NCR_FCL_SERVICE_INITIALIZATION_FAILED
//
// MessageText:
//
//  Initialization of the %1 service failed.
//
#define NCR_FCL_SERVICE_INITIALIZATION_FAILED ((DWORD)0xC001C545L)

// Parameter 1 - Source Description
// Parameter 2 - Exception

//
// MessageId: NCR_FCL_FATAL_EXCEPTION
//
// MessageText:
//
//  The %1 service threw a fatal exception (%2).
//
#define NCR_FCL_FATAL_EXCEPTION          ((DWORD)0xC001C546L)

// Parameter 1 - Source Description
// Parameter 2 - Description
// Parameter 3 - Meaning

//
// MessageId: NCR_FCL_SERVICE_INFORMATION
//
// MessageText:
//
//  %1 Service:
//  %n%n%2
//  %n%nMeaning:
//  %n%n%3
//  %n%nAction:
//  %n%nConsult the FitClient User Manual if you need more information or
//  contact your NCR service representative.
//
#define NCR_FCL_SERVICE_INFORMATION      ((DWORD)0x4011C547L)

// ---------------------------------------------------------------------------------
// NCR Utilities Event Log Messages
// Source:  NCRUtilities
// MessageId Range: 50551 - 50600
// ---------------------------------------------------------------------------------
//

// Parameter 1 - Source Description

//
// MessageId: NCR_UTIL_START
//
// MessageText:
//
//  The %1 utility was started with command options %2.
//
#define NCR_UTIL_START                   ((DWORD)0x4001C577L)

// Parameter 1 - Source Description
// Parameter 2 - file name

//
// MessageId: NCR_UTIL_OPEN_FILE
//
// MessageText:
//
//  Utility %1 attempted to open file %2.
//  %n%nSource: %1, File %2
//
#define NCR_UTIL_OPEN_FILE               ((DWORD)0xC00BC578L)

// Parameter 1 - Source Description
// Parameter 2 - Error Description

//
// MessageId: NCR_UTIL_CMDLINE_BAD
//
// MessageText:
//
//  The command line used with utility %1 is invalid.
//  %n%nMeaning:
//  %n%n%2 
//  %n%nAction:
//  %n%nUse the /? option to view the available options. 
//
#define NCR_UTIL_CMDLINE_BAD             ((DWORD)0xC004C579L)

// Parameter 1 - Source Description

//
// MessageId: NCR_UTIL_REBOOT_FAIL
//
// MessageText:
//
//  Utility %1 attempted to force a system reboot and failed.
//  %n%nMeaning:
//  %n%n The system call to reboot the system failed.
//  %n%nAction: Manually reboot.
//  %n%n 
//
#define NCR_UTIL_REBOOT_FAIL             ((DWORD)0xC012C57AL)

// Parameter 1 - Source Description
// Parameter 2 - Error Description

//
// MessageId: NCR_UTIL_BAD_PARAMETER
//
// MessageText:
//
//  Utility %1 cannot continue due to an invalid parameter.
//  %n%nMeaning:
//  %n%n%2
//  %n%nAction:
//  %n%nVerify registry parameters used by the utility are correct. 
//
#define NCR_UTIL_BAD_PARAMETER           ((DWORD)0xC004C57BL)

// Parameter 1 - Source Description

//
// MessageId: NCR_UTIL_MISC
//
// MessageText:
//
//  Utility %1 error.
//  %n%nMeaning:
//  %n%n%2
//  %n%nAction:
//  %n%n If a BIOS version error occurs and you are sure this will not cause a problem, remove the command line option to do the check (/B). If a CMOS cumcheck error occurs and the file being used is the old style dump, use the /O option, otherwise do not use the file. Use the /D:[File] option to determine if the file is new (info will be displayed on sumcheck supported file). For all other errors Verify all required software is installed on the terminal. 
//
#define NCR_UTIL_MISC                    ((DWORD)0xC011C57CL)

// Parameter 1 - Source Description
// Parameter 2 - file name

//
// MessageId: NCR_UTIL_READ_FILE
//
// MessageText:
//
//  Utility %1 attempted to read file %2.
//  %n%nMeaning:
//  %n%n File %2 was not found, The %1 utility aborted.
//
#define NCR_UTIL_READ_FILE               ((DWORD)0xC00BC57DL)

// Parameter 1 - Source Description
// Parameter 2 - file name

//
// MessageId: NCR_UTIL_WRITE_FILE
//
// MessageText:
//
//  Utility %1 attempted to write file %2.
//  %n%nMeaning:
//  %n%n File %2 was not found, The %1 utility aborted.
//
#define NCR_UTIL_WRITE_FILE              ((DWORD)0xC00BC57EL)

