//////////////////////////////////////////////////////////////////////////////
//
// This is the NCR OPOS Message File for use with StoreMinder Event Agent.
// 
//
// PLEASE ... update this file based on guidelines in the OPOS Event Agent
// Implementation Specification 497-0002626.
//
//
// $Workfile:: NCROPOSMsg.mc                                             $
//
// $Revision:: 18                                                        $
//
// $Archive:: /OPOS/Rel.2_6/StoreMinder/Message Files/NCROPOSMsg.mc      $
//
// $Date:: 8/24/11 4:03p                                                 $
//
//////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) NCR Corporation 1997, 1998.  All rights reserved.
//
//////////////////////////////////////////////////////////////////////////////
// The StoreMinder CNCREventLog class uses the Severity field to 
// pass the severity of the message being logged from the message 
// file to ReportEvent.
//
// The CONVERT_SEVERITY macro is used for this purpose:

 #define CONVERT_SM_SEVERITY(X)                                                 \
		(((X >> 30) == SEVERITY_SM_SUCCESS)    ? evlTypeAuditSuccess:           \
		(((X >> 30) == SEVERITY_SM_INFORMATION)? evlTypeInformation:            \
		(((X >> 30) == SEVERITY_SM_WARNING)    ? evlTypeWarning:                \
		(((X >> 30) == SEVERITY_SM_ERROR)      ? evlTypeError : evlTypeInformation))))

// The StoreMinder CNCREventLog class uses the facility field to 
// pass the category of the message being logged from the message 
// file to ReportEvent.  
//
// The CONVERT_SM_CATEGORY macro is used for this purpose:

 #define CONVERT_SM_CATEGORY(X)   ((X >> 16) & 0xFFF)
	
// SM_CATEGORY_COUNT should be the total number of categories:

 #define SM_CATEGORY_COUNT 18


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
//
// OPOS Controls (Control Object and Service Object) Message Id Ranges 
//
//     Common Events:          10000 - 10099
//
//   OPOS Spec 1.3:
//     Bump Bar:               10100 - 10149
//     Cash Changer:           10150 - 10199
//     Cash Drawer:            10200 - 10249
//     Coin Dispenser:         10250 - 10299
//     Hard Totals:            10300 - 10349
//     Keylock:                10350 - 10399
//     LineDisplay:            10400 - 10449
//     MICR:                   10450 - 10499
//     MSR:                    10500 - 10549
//     POS Keyboard:           10550 - 10599
//     POS Printer:            10600 - 10649
//     Remote Order Display:   10650 - 10699
//     Scale:                  10700 - 10749
//     Scanner:                10750 - 10799
//     Signature Capture:      10800 - 10849
//     Tone Indicator:         10850 - 10899
//
//   Non-OPOS "NCR OPOS" Controls
//     IVICMForm Control:      10900 - 10949
//     Wedge Driver:           10950 - 10999
//     Wedge KBD Filter:       11000 - 11049
//
//   OPOS Spec 1.4:
//   OPOS Spec 1.5:
//     
//  The Following is a sample message:
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
// The StoreMinder Source is going to be the same as the Service
// Object ProgID. This will aid in Service Object recognition.
// If the Source name is longer than 20 characters it will get 
// truncated when transfered to the Store Minder server when the
// communications is via winsock (Store Minder 1.1). If the communcations 
// is DCOM the Source name is transferred intact (Store Minder 2.0).
//
// Currently the maximum character count for all of the insertion
// strings concatenated together is 125.  If the insertion strings
// are longer, the event message will not be formatted correctly.
//

// ----------------------------------------------------------------------------
// Common OPOS Event Log Messages
// Source: PROGID for any of the NCR OPOS Service Objects 
// MessageId Range Common Events: 10000 - 10099
// ----------------------------------------------------------------------------

//
// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - Name of the method: GetPropertyNumber,
//	              SetPropertyNumber, GetPropertyString
//	              SetPropertyString
// Parameter 4 - Name of the OPOS Device Class: CashDrawer,
//               CoinDispenser, HardTotals, Keylock, LineDisplay,
//               MICR, MSR, POSPrinter, Scale, Scanner, SignatureCapture  
//					
// Data: Contains the illegal Property index value (LONG).
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
// MessageId: OPOS_PROPERTY_INDEX_ILLEGAL
//
// MessageText:
//
//  Bad property index.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  "%3" method received an unsupported property index. This Service Object may 
//  be of an older OPOS Specification version than the %4 Control Object, or the 
//  Control Object is using an invalid property index.  See Data for the 
//  illegal Property index value.%n
//  %nAction - Verify that the Control Object and Service Object have 
//  compatible OPOS versions. 
//  Contact your Control Object vender for more information.%n
//
#define OPOS_PROPERTY_INDEX_ILLEGAL      ((DWORD)0xC0072710L)


// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - Name of the OPOS Device Class: CashDrawer,
//               CoinDispenser, HardTotals, Keylock, LineDisplay,
//               MICR, MSR, POSPrinter, Scale, Scanner, SignatureCapture  
//					
// Data: None
//
//
// MessageId: OPOS_SO_ALREADY_OPEN
//
// MessageText:
//
//  Service Object is already Open.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  "OpenService" method has already been called by this instance of the %3 
//  Control Object.
//  %n%nAn application can only Open the OPOS Control once before doing 
//  a corresponding Close.  The Control Object or the application has a programming 
//  error.%n
//  %nAction - Verify that the Application is calling Open only once before a Close. 
//  If the Application terminated abnormally, a reboot may be necessary.  If the
//  Control Object has a programming error, contact the Control Object vender 
//  for more information.%n
//
#define OPOS_SO_ALREADY_OPEN             ((DWORD)0xC0072711L)


// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - Name of the OPOS Device Class: CashDrawer,
//               CoinDispenser, HardTotals, Keylock, LineDisplay,
//               MICR, MSR, POSPrinter, Scale, Scanner, or SignatureCapture 
// Parameter 4 - Name of the event method: SODirectIO, SOStatusUpdate, SOError
//               SOOutputComplete, or SOData
//					
// Data: None

//
// MessageId: OPOS_BAD_EVENT_INTERFACE
//
// MessageText:
//
//  Unable to initialize event interface to Control Object.%n
//  %nMeaning - %1, 
//  Profile: %2, 
//  could not initialize the event (dispatch) interface that is exposed by the 
//  %3 Control Object. The GetIDsOfNames() failed when querying for the 
//  "%4" method.  
//  %n%nEither the Control Object is not exposing the expected event methods, or the 
//  Service Object is querying for the wrong method name.%n
//  %nAction - Fix the Control Object to expose the event methods in the event 
//  dispatch interface.  Contact the Control Object vender for more information.  
//  Fix the Service Object to query for the correct event method names.  
//  Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_BAD_EVENT_INTERFACE         ((DWORD)0xC0072712L)


// Parameter 1 - Service Object or Control Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - Profile Registry Key.
//					
// Data: None

//
// MessageId: OPOS_OPEN_REGISTRY
//
// MessageText:
//
//  Unable to open a Registry Key.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  Could not open the Registry Key 
//  HKEY_LOCAL_MACHINE\%3, 
//  %n%nThe RegOpenKeyEx() API failed. The user on this system may not have the 
//  correct permissions, or there is a Microsoft internal processing error.%n
//  %nAction - Verify that registry Key exists in the system registry and that 
//  the user has the correct permissions to access the registry.
//  Contact your NCR OPOS service representative for more information.
//
#define OPOS_OPEN_REGISTRY               ((DWORD)0xC0052713L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - The configuration parameter registry value. See NCROPOS.HLP
//               for the most up-to-date configuration parameters for each
//               service object.
// Parameter 4 - The invalid configuration parameter registry value data.  See
//               NCROPOS.HLP for the most up-to-date configuration parameter
//               options, ranges, and defaults for each service object.
//					
// Data: None

//
// MessageId: OPOS_CONFIG_PARAMETER_INVALID
//
// MessageText:
//
//  Invalid configuration parameter in the registry.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  Could not initialize because the "%3" registry parameter has invalid 
//  data: "%4".%n
//  %nAction - Use RSM to correctly configure 
//  the Profile in error. Use the NCROPOS.HLP to verify that registry parameters 
//  are correct for the Service Object's Programmatic Id (event source) that is 
//  in error.  If the Profile "Uses" another Profile, in the case of Multi-Class 
//  Service Objects, make sure that the parent Profile, the one being Used, is 
//  correctly configured.  
//  Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_CONFIG_PARAMETER_INVALID    ((DWORD)0xC0032714L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - The configuration parameter registry value. See NCROPOS.HLP
//               for the most up-to-date configuration parameters for each
//               service object.
//					
// Data: None

//
// MessageId: OPOS_CONFIG_PARAMETER_MISSING
//
// MessageText:
//
//  Missing configuration parameter in the registry.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  Could not initialize because the "%3" registry parameter could not be found.%n
//  %nAction - Use RSM to correctly configure 
//  the Profile in error. Use the NCROPOS.HLP to verify that registry parameters 
//  are correct for the Service Object's Programmatic Id (event source) that is 
//  in error.  If the Profile "Uses" another Profile, in the case of Multi-Class 
//  Service Objects, make sure that the parent Profile, the one being Used, is 
//  correctly configured.  
//  Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_CONFIG_PARAMETER_MISSING    ((DWORD)0xC0032715L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - The name of the internal memory resource that could not be created.
//               
//               
//					
// Data: None

//
// MessageId: OPOS_ALLOCATE_MEMORY_FAILURE
//
// MessageText:
//
//  Unable to allocate memory resource.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  Could not allocate the "%3".
//  %n%n  Could be running low on memory or handles.%n
//  %nAction - Use a system resource tool, such as the NT Performance Monitor, 
//  to determine the amount of system and process memory usage.  There could 
//  be a process in the system that has a memory leak, or a process terminated 
//  abnormally causing threads not to clean up correctly. 
//  Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_ALLOCATE_MEMORY_FAILURE     ((DWORD)0xC00C2716L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - The name of the internal IPC resource that could not be created.
//               
//               
//					
// Data: None

//
// MessageId: OPOS_ALLOCATE_IPC_FAILURE
//
// MessageText:
//
//  Unable to create IPC resource.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  Could not create the "%3" IPC resource.
//  %n%nCould be running low on memory or 
//  handles. Could have been caused by an abnormal or incorrect application 
//  termination.%n
//  %nAction - Use a system resource tool, such as the NT Performance Monitor, 
//  to determine the amount of system and process memory usage.  There could 
//  be a process in the system that has a memory leak, or a process terminated 
//  abnormally causing things not to clean up normally. 
//
#define OPOS_ALLOCATE_IPC_FAILURE        ((DWORD)0xC00D2717L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: GetLastError() result after the CreateFile() attempt failed.
//       If not possible to retrieve the value is 0.

//
// MessageId: OPOS_NO_PORT_DRIVER
//
// MessageText:
//
//  The NCRKMPDR.SYS could not be opened.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  %nCould not open the NCR Kernel Mode Port Driver.  When this Service Object
//  is running on an Microsoft NT operating system, the NCRKMPDR.SYS driver 
//  must be installed correctly. If the driver is installed correctly, 
//  the NCRKMPDR.SYS driver could have an internal problem initializing.  
//  See Data for the GetLastError() status results.%n
//  %nAction - Verify that the NCRKMPDR.SYS driver is installed.  Since, it is 
//  loaded during NT System Startup, a reboot is necessary after the driver is 
//  first installed.  The file should be located in the \<winnt>\system32\drivers 
//  directory.  The registry should have the following information: 
//  [HKEY_LOCAL_MACHINE\System\CurrentControlSet\Services\NCRKMPDR]
//  "ErrorControl"=dword:00000001
//  "Start"=dword:00000001
//  "Type"=dword:00000001
//  If it is believed to be loaded correctly, a NET STOP NCRKMPDR and corresponding
//  NET START NCRKMPDR should succeed at the command prompt.
//  Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_NO_PORT_DRIVER              ((DWORD)0xC0072718L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - Name of the System API that failed if known,
//               SetFilePointer and WriteFile (for NTDriver Access).
//               
//               
//					
// Data: GetLastError() result API call failed.

//
// MessageId: OPOS_SYSTEM_CALL_FAILURE
//
// MessageText:
//
//  A System level API failed.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  The attempt to call the System API "%3" failed.
//  %n%nSee Data for the 
//  GetLastError() status results.%n
//  %nAction - Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_SYSTEM_CALL_FAILURE         ((DWORD)0xC0052719L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - Name of the System API that failed if known,
//               GetFileSize, SetFilePointer, SetEndOfFile, ReadFile
//               WriteFile.
//               
//               
//					
// Data: GetLastError() result API call failed.

//
// MessageId: OPOS_FILE_IO_FAILURE
//
// MessageText:
//
//  A File Input/Output system level API failed.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  The attempt to call the File I/O System API "%3" failed.
//  %n%nIf the device
//  is using a hard disk or some other storage device, the disk could be full,
//  or the hardware could be failing.  See Data for the 
//  GetLastError() status results.%n
//  %nAction - Try running a Check Disk utility for your operating system
//  to check for errors.
//  Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_FILE_IO_FAILURE             ((DWORD)0xC00B271AL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - The Port that failed.  Example: "\\\\.\\COM1" or "COM1"
//               
//               
//					
// Data: GetLastError() result API call failed.

//
// MessageId: OPOS_OPEN_PORT_FAILURE
//
// MessageText:
//
//  Could not open the COM Port.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  The attempt to open %3 Port failed.
//  %n%nThe Win32 API call CreateFile() failed.  
//  The port may not be configured correctly.  The port may be in use by another 
//  device.  See Data for the GetLastError() status results.%n
//  %nAction - Verify that the Port is correctly configured and there are no 
//  Port conflicts by using RSM.  If a conflict is detected, 
//  use the Operating System's Control Panel to correctly configure the 
//  desired Port.  Use RSM to configure the Profile in error 
//  to another Port if available.  
//  Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_OPEN_PORT_FAILURE           ((DWORD)0xC005271BL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - OPOS Error, either OPOS_E_ILLEGAL or OPOS_E_TIMEOUT
//               
//               
//					
// Data: Timeout value

//
// MessageId: OPOS_CLAIM_FAILURE
//
// MessageText:
//
//  OPOS "Claim" method failed.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  The attempt to "Claim" failed with the error %3.
//  %n%nIf OPOS_E_ILLEGAL, 
//  this device cannot be claimed for exclusive access, or an invalid 
//  Timeout parameter was specified. If OPOS_E_TIMEOUT, another application 
//  has exclusive access to the device, and did not relinquish control 
//  before Timeout milliseconds expired.  See Data for
//  Timeout value.  For some devices, incorrect port settings can also 
//  cause this error.%n
//  %nAction - Verify that this device can be claimed for exclusive access. 
//  Shutdown other applications that may have the device claimed and try 
//  the method again.  Verify that all of the configuration parameters
//  are correct.%n
//
#define OPOS_CLAIM_FAILURE               ((DWORD)0xC001271CL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None.

//
// MessageId: OPOS_NOTCLAIMED
//
// MessageText:
//
//  The Control is not claimed.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nThis OPOS Control must be claimed before attempting to call any
//  methods or set any properties.%n
//  %nAction - Modify the application to call the "Claim" first.%n
//
#define OPOS_NOTCLAIMED                  ((DWORD)0xC007271DL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None.

//
// MessageId: OPOS_DEVICE_ENABLE_FAILURE
//
// MessageText:
//
//  Device Enable failed.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nThe attempt to set the property DeviceEnable = TRUE failed.%n
//  %nAction - Verify that all configuration parameters are correct.  
//  For more information, review the next event(s) logged for this source.
//  Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_DEVICE_ENABLE_FAILURE       ((DWORD)0x4001271EL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None.

//
// MessageId: OPOS_DEVICE_ENABLE_SUCCESS
//
// MessageText:
//
//  Device Enable successful.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nThe attempt to set the property DeviceEnable = TRUE succeeded.  
//  The device is now fully functional.%n
//  %nAction - No action.%n
//
#define OPOS_DEVICE_ENABLE_SUCCESS       ((DWORD)0x4001271FL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: GetLastError() result API call failed.

//
// MessageId: OPOS_CANNOT_LOAD_WKFM_DLL
//
// MessageText:
//
//  LoadLibrary() failed to load the "NCRWedgeKBDFilter.dll".%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nThe system call to load the library failed.  See Data for the GetLastError() 
//  status results.%n
//  %nAction - Verify that the dll exists in the system directory or
//  in a directory available through the PATH.%n
//
#define OPOS_CANNOT_LOAD_WKFM_DLL        ((DWORD)0xC0012720L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None.

//
// MessageId: OPOS_WKFM_HOOK_NOT_INSTALLED
//
// MessageText:
//
//  Could not hook the keyboard data stream.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nThe NCRWedgeKBDFilter.dll could not hook into the OS keyboard data stream.
//  In order to filter the wedge specific device data, the NCRWedgeKBDFilter.dll
//  installs a system level keyboard hook.  The Wedge Service Objects then
//  interface into this Filter DLL to receive wedge data (Scanner, MSR, and 
//  Keylock).  The failure can occur because of a programming error, 
//  the global hook is being set with NULL hInstance or a 
//  thread-specific hook is being set for a thread that is
//  not in the setting application, a hook that can only be a system hook is being 
//  installed to a specific thread, the thread ID is invalid, there is already a 
//  hook set for a journal hook type (only one can be installed at a time), a 
//  screen saver is running while trying to set a journal hook type, security
//  does not allow this hook to be set or the system is out of memory.%n
//  %nAction - Contact your NCR OPOS representative for more information.%n
//
#define OPOS_WKFM_HOOK_NOT_INSTALLED     ((DWORD)0xC0072723L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None.

//
// MessageId: OPOS_WKFM_OVERFLOW
//
// MessageText:
//
//  Buffer overflow.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nThe NCRWedgeKBDFilter.dll reported that its internal buffer was not large
//  enough to hold the data from the wedge device. More data came from wedge
//  than was expected.  The internal buffer can overflow if the end
//  sentinels are lost due to a problem in the operating system
//  or programming error in the NCRWedgeKBDFilter.dll.%n
//  %nAction - Contact your NCR OPOS representative for more information.%n
//
#define OPOS_WKFM_OVERFLOW               ((DWORD)0xC0072724L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - "MSR", "Keyboard", or "Scanner" Interface
//               
//               
//					
// Data: None.

//
// MessageId: OPOS_WKFM_ALREADY_ENABLED
//
// MessageText:
//
//  Interface already enabled.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2 Interface %3
//  %n%nThe NCRWedgeKBDFilter.dll has already enabled the interface.
//  This problem can occur if an application terminates without releasing
//  all references on the Control Object, the application terminates
//  abnormally causing the Service Object not to execute its 
//  destructor.  Application is not following the OPOS specification
//  correctly.%n
//  %nAction - Contact your NCR OPOS representative for more information.
//  Contact your Application provider for more information.%n
//
#define OPOS_WKFM_ALREADY_ENABLED        ((DWORD)0xC0072725L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None.

//
// MessageId: OPOS_WKFM_BUFF_TOO_SMALL
//
// MessageText:
//
//  Buffer is too small to hold the data.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nThe NCRWedgeKBDFilter.dll has reported that the Service Object's data 
//  buffer is not large enough to hold all the MSR data.  Internal programming
//  error.%n
//  %nAction - Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_WKFM_BUFF_TOO_SMALL         ((DWORD)0xC0072726L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: NCRWedgeKBDFilter.dll return code value.

//
// MessageId: OPOS_WKFM_SEND_FAILED
//
// MessageText:
//
//  Unable to send data to wedge device.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nThe NCRWedgeKBDFilter.dll was unable to send data to the wedge device.
//  Internal programming error.%n
//  %nAction - Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_WKFM_SEND_FAILED            ((DWORD)0xC0072727L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None.

//
// MessageId: OPOS_WKFM_NOBUFFERS
//
// MessageText:
//
//  NCRWedgeKBDFilter.dll reported internal data buffer is full.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nNCRWedgeKBDFilter.dll is holding 6 messages and another message arrived.
//  There is not enough room in WKFM MSR data buffer to hold the incoming
//  message. Internal programming error.%n
//  %nAction - Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_WKFM_NOBUFFERS              ((DWORD)0xC0072728L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: NCRWedgeKBDFilter.dll return code value.

//
// MessageId: OPOS_WKFM_ERROR_UNKNOWN
//
// MessageText:
//
//  Unknown error.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nThe NCRWedgeKBDFilter.dll has returned an error status that the Service 
//  Object does not recognize.  The DLL could be of a newer version that the
//  Service Object. See Data for the unknown error status.%n
//  %nAction - Make sure that the Major.Minor release of the dll match the 
//  release of the Service Object by use the File Explorer to review the 
//  Version Properties. 
//  Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_WKFM_ERROR_UNKNOWN          ((DWORD)0xC0072729L)

// Parameter 1 - Control Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - Name of the OPOS Device Class: CashDrawer,
//               CoinDispenser, HardTotals, Keylock, LineDisplay,
//               MICR, MSR, POSPrinter, Scale, Scanner, SignatureCapture  
//					
// Data: None
//
//
// MessageId: OPOS_CO_ALREADY_OPEN
//
// MessageText:
//
//  Control Object is already Open.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  "Open" method has already been called by the application for this instance of 
//  the %3 Control Object.
//  %n%nAn application can only Open the OPOS Control once 
//  before doing a corresponding Close.  The the application has a programming 
//  error.%n
//  %nAction - Verify that the Application is calling Open only once before a Close. 
//  If the Application terminated abnormally, a reboot may be necessary.%n
//
#define OPOS_CO_ALREADY_OPEN             ((DWORD)0xC007272AL)

// Parameter 1 - Control Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - Profile Registry Key.
//					
// Data: None
//
//
// MessageId: OPOS_NO_VALID_SO
//
// MessageText:
//
//  No Service Object defined for Profile.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  "Open" method failed because the Service Object's Programmatic ID is
//  not configured as the default value for the Profile at Registry Key
//  HKEY_LOCAL_MACHINE\%3.
//  %n%nAction - Use RSM to delete the Profile and create a new profile for the 
//  desired Service Object.  Or, modify the registry key to contain a valid 
//  Programmatic ID for the Profile in error by using the Registry Editor.%n
//
#define OPOS_NO_VALID_SO                 ((DWORD)0xC003272BL)

// Parameter 1 - Control Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - Service Object Programmatic ID
//					
// Data: None.
//
//
// MessageId: OPOS_SO_LOAD_FAILED
//
// MessageText:
//
//  Unable to Load the Service Object.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  The CreateDispatch() failed to load the "%3" Service Object.  
//  %n%nThis could be caused by an automation error because the Service Object 
//  is not correctly registered.%n
//  %nAction - Use RegSvr32 to correctly register the desired Service Object.%n
//
#define OPOS_SO_LOAD_FAILED              ((DWORD)0xC003272CL)

// Parameter 1 - Control Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - Service Object's Programmatic ID
// Parameter 4 - OPOS Specification Release Version supported by 
//				  the Service Object
// Parameter 5 - Dispatch Method Name
//					
// Data: None.
//
//
// MessageId: OPOS_SO_DISPATCH_LOOKUP_FAILED
//
// MessageText:
//
//  Failed lookup of Dispatch Method name.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  The "%3" Service Object indicates that it supports the 
//  OPOS %4 Specification release but does not support the required 
//  Dispatch Method "%5".
//  %n%nAction -  Fix the Service Object to comply with the OPOS Specification
//  that is supported. Contact your OPOS Service Object vender for more 
//  information.%n
//
#define OPOS_SO_DISPATCH_LOOKUP_FAILED   ((DWORD)0xC007272DL)

// Parameter 1 - Control Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - Service Object's Programmatic ID
// Parameter 4 - Service Object Version
// Parameter 5 - Control Object Version
//					
// Data: None.
//
//
// MessageId: OPOS_SO_VERSION_NOT_SUPPORTED
//
// MessageText:
//
//  Service Object version is not supported.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  The "%3" Service Object indicates that it supports the 
//  OPOS %4 Specification release but this Control Object only supports
//  OPOS %5 and earlier.
//  %n%nAction -  Fix the Service Object to comply with the OPOS Specification
//  that is supported by this Control Object or replace this Control Object
//  so that it supports the version of the Service Object. 
//  Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_SO_VERSION_NOT_SUPPORTED    ((DWORD)0xC007272EL)

// Parameter 1 - Control Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - Service Object's Programmatic ID
//					
// Data: None.
//
//
// MessageId: OPOS_SO_OPEN_FAILED
//
// MessageText:
//
//  Service Object failed to open.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  The attempt to open the "%3" Service Object by calling the 
//  "OpenService" method failed.
//  %n%nAction -  Review other errors logged with the Service Object as 
//  the Source for more information.
//  Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_SO_OPEN_FAILED              ((DWORD)0x4001272FL)

// Parameter 1 - Control Object Description.
// Parameter 2 - Profile Name.
//					
// Data: GetLastError() result after the CreateEx() attempt failed.
//
//
// MessageId: OPOS_CO_NO_EVT_WINDOW
//
// MessageText:
//
//  Failed open of event window.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nThe attempt to open the "FireEventWindow" failed.  This is the way the 
//  Control Object ensures compliance with the Apartment Threading Model before
//  firing an event into the application. Could be running low on memory or handles.  
//  See Data for the GetLastError() status results.%n
//  %nAction -  Use a system resource tool, such as the NT Performance Monitor, 
//  to determine the amount of system and process memory usage.  There could 
//  be a process in the system that has a memory leak, or a process terminated 
//  abnormally causing threads not to clean up correctly. 
//  Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_CO_NO_EVT_WINDOW            ((DWORD)0xC0012730L)

// Parameter 1 - Control Object Description.
// Parameter 2 - Profile Name.
//					
// Data: None.
//
//
// MessageId: OPOS_CO_NOPROFILE
//
// MessageText:
//
//  Profile (DeviceName input parameter) is an empty string.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nThe DeviceName parameter for the Open() method was an empty string.%n
//  %nAction -  Modify the application to correctly initialize this input
//  parameter before calling the Control Object's Open() method.%n
//
#define OPOS_CO_NOPROFILE                ((DWORD)0xC0012731L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - Device Description that supports the CCL Data
// Parameter 4 - Class and Model of the device
// Parameter 5 - Serial Number of the device
// Parameter 6 - ROM #1 Description
// Parameter 7 - ROM #1 Part Number
// Parameter 8 - ROM #1 Version
// Parameter 9 - ROM #2 Description
// Parameter 10 - ROM #2 Part Number
// Parameter 11 - ROM #2 Version
//               
//               
//					
// Data: None.

//
// MessageId: OPOS_DEVICE_ENABLE_SUCCESSEX
//
// MessageText:
//
//  Device Enable successful with CCL data.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  The attempt to set the property DeviceEnable = TRUE succeeded.  
//  The device is now fully functional.%n
//  %nDevice Description: %3
//  %nClass-Model: %4
//  %nSerial Number: %5
//  %nROM1 Description: %6
//  %nROM1 Part Number: %7
//  %nROM1 Version: %8
//  %nROM2 Description: %9
//  %nROM2 Part Number: %10
//  %nROM2 Version: %11
//  %nROM3 Description: %12
//  %nROM3 Part Number: %13
//  %nROM3 Version: %14%n
//  %nAction - No action.%n
//
#define OPOS_DEVICE_ENABLE_SUCCESSEX     ((DWORD)0x40012732L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None.

//
// MessageId: OPOS_DEVICE_DISABLE_SUCCESS
//
// MessageText:
//
//  Device Disable successful.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nThe attempt to set the property DeviceEnable = FALSE succeeded.  
//  The device is now not functional.%n
//  %nAction - No action.%n
//
#define OPOS_DEVICE_DISABLE_SUCCESS      ((DWORD)0x40012733L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None.

//
// MessageId: OPOS_DEVICE_DISABLE_FAILURE
//
// MessageText:
//
//  Device Disable failed.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nThe attempt to set the property DeviceEnable = FALSE failed.%n
//  %nAction - Verify that all configuration parameters are correct.  
//  For more information, review the next event(s) logged for this source.
//  Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_DEVICE_DISABLE_FAILURE      ((DWORD)0x40012734L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - Name of the System API that failed if known,
//               SetFilePointer and WriteFile (for NTDriver Access).
//               
//               
//					
// Data: GetLastError() result API call failed.

//
// MessageId: OPOS_INTERNAL_CALL_FAILURE
//
// MessageText:
//
//  An Internal Function Failed.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  The attempt to call the internal function "%3" failed.
//  %n%nAction - Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_INTERNAL_CALL_FAILURE       ((DWORD)0xC0072735L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//					
// Data: none

//
// MessageId: OPOS_NO_DEVICE_ATTACHED_TO_PORT
//
// MessageText:
//
//  No Hardware Device Located.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nThe device was not found.  Cannot communicate to device.%n
//  %nAction - Verify all configuration parameters are correct. Verify the device is
//  properly connected to configured port. Verify the device is powered up ready for
//  normal operation. %n
//
#define OPOS_NO_DEVICE_ATTACHED_TO_PORT  ((DWORD)0xC0102736L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//					
// Data: none

//
// MessageId: OPOS_FILE_OPEN_ERROR
//
// MessageText:
//
//  Failed to open file.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  The file "%3" could not be opened. See Data for the GetLastError() status results.
//  %n%nSee Data for the GetLastError() status results.%n
//  %nAction - Verify the file exists, and security permissions are correct.
//  View the GetLastError() information for additional details. Contact your
//  NCR OPOS service representative for more information.%n
//
#define OPOS_FILE_OPEN_ERROR             ((DWORD)0xC00B2737L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - What was not downloaded ("Firmware", "Application", "Operating System", etc)
//
// Data: None.
//
//
// MessageId: OPOS_FAILED_DNLD_TO_DEVICE
//
// MessageText:
//
//  Failed to download to the device.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  Failed to download %3 to the device.
//  %n%nAction - Ensure the device is powered up and operational. Ensure the device is
//  properly configured. Consult data capture. Contact your NCR OPOS service
//  representative for more information.%n
//
#define OPOS_FAILED_DNLD_TO_DEVICE       ((DWORD)0xC00F2738L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - DLL name             
//               
//					
//
// MessageId: OPOS_GENERIC_CANNOT_LOAD_DLL
//
// MessageText:
//
//  Failed to load and initialize a Dynamic Link Library (DLL).%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  Failed to successfully load and initialize the DLL "%3".
//  %n%nAction - Verify that the dll exists in the system directory or
//  in a directory available through the PATH.%n
//
#define OPOS_GENERIC_CANNOT_LOAD_DLL     ((DWORD)0xC0012739L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - Device Class or Type. For example, "Keylock", "MSR", "Tone". 
// Parameter 4 - Device/Product description. For USB, this would be the USB Device's Product String, 
//                  obtained via NCRHIDLib::LibGetProductString()
//               
//					
//
// MessageId: OPOS_PLUGNPLAY_DEVICE_UNLOADED
//
// MessageText:
//
//  Plug and Play device has unloaded.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  The Plug and Play %3 device "%4" has been unloaded from the system.
//  %n%nAction - Ensure the device is attached. If applicable, ensure the device is powered up.%n
//
#define OPOS_PLUGNPLAY_DEVICE_UNLOADED   ((DWORD)0x4001273AL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - Device Class or Type. For example, "Keylock", "MSR", "Tone". 
// Parameter 4 - Device/Product description. For USB, this would be the USB Device's Product String, 
//                  obtained via NCRHIDLib::LibGetProductString()
//               
//					
//
// MessageId: OPOS_PLUGNPLAY_DEVICE_RELOADED
//
// MessageText:
//
//  Plug and Play device has been reloaded.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  The Plug and Play %3 device "%4" has been reloaded into the system.
//  %n%nAction - None. The device should be operational. If it is not operational, try closing
//  the device and reopening it, or stop and restart the affected application(s).%n
//
#define OPOS_PLUGNPLAY_DEVICE_RELOADED   ((DWORD)0x4001273BL)

// ---------------------------------------------------------------------------------
// Bump Bar Device Class
// Source: 
// MessageId Range Bump Bar: 10100 - 10149
// ---------------------------------------------------------------------------------
//
// Currently there are no Bump Bar Service Objects supported by NCR Atlanta
//
// ---------------------------------------------------------------------------------
// Cash Changer Device Class
// Source: 
// MessageId Range Cash Changer: 10150 - 10199
// ---------------------------------------------------------------------------------
//
// Currently there are no Cash Changer Service Objects supported by NCR Atlanta
//
// ---------------------------------------------------------------------------------
// Cash Drawer Device Class
// Source: "NCRCashDrawer" (PROGID for the NCRCashDrawer.dll Service Object)
// MessageId Range Cash Drawer: 10200 - 10249
// ---------------------------------------------------------------------------------
// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - Name of the requested Device in conflict: 
//               Cash Bases DRUR01 Cash Drawer, or Cash Bases MPU Cash Drawer
// Parameter 4 - Type of Port that was in conflict. Example: COM1, or COM2
// Parameter 5 - Name of the instantiated Device that requested Device is in conflict
//               with: DRUR01, MPU, NCR7453
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_CD_COM_PORT_CONFLICT
//
// MessageText:
//
//  Device COM Port conflict found.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  Could not initialize the %3 device because the %4 Port was in use 
//  by the %5 device.
//  %n%nAction - Reconfigure the Profile using RSM to use a different COM Port.%n
//
#define OPOS_CD_COM_PORT_CONFLICT        ((DWORD)0xC00327D8L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - Name of the requested Device in conflict: NCR 7453 Cash Drawer,
//               Cash Bases DRUR01 Cash Drawer, or Cash Bases MPU Cash Drawer
// Parameter 4 - Number of Maximum Device instances allowed.
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_CD_MAX_LIMIT
//
// MessageText:
//
//  Cannot exceed maximum number of internal Device object instances.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  Could not initialize the %3 Device because an amount of %4 
//  Cash Drawer internal Devices objects have already been created.  
//  %n%nThis amount can be a combination of Serial Devices using different COM Ports 
//  and an I/O Device.%n
//  %nAction - Don't Open more than the maximum number of supported Cash Drawer
//  instances within a single application.
//  For example, if a new MPU Cash Drawer (a Serial Device) instance is created 
//  using COM1 and a MPU Cash Drawer instance has already been created using 
//  COM1, the new instance will use the Device object already created.  Otherwise 
//  if each MPU Cash Drawer instance is using a different COM Port, a new 
//  internal Device object is created.  A new internal Device object is also 
//  created for each Cash Drawer that uses an I/O Port.%n
//
#define OPOS_CD_MAX_LIMIT                ((DWORD)0xC00327D9L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - Name of the requested Device in conflict: NCR 7453 Cash Drawer,
// Parameter 4 - Type of Port that was in conflict. Example: I/O 101
// Parameter 5 - Name of the instanciated Device that requested Device is in conflict
//               with: NCR7453
// Parameter 6 - Type of Port previously initialized. Example: I/O 121
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_CD_IO_PORT_CONFLICT
//
// MessageText:
//
//  Device IO Port conflict found.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  Could not initialize the %3 device using %4 Port because a 
//  previous %5 device was initialized using %6 Port.
//  %n%nWhen two Profiles of this 
//  same Cash Drawer Model are configured, they must use the same I/O Port.%n
//  %nAction - Reconfigure the Profile using RSM to use 
//  the same I/O Port as other Profiles of this same Cash Drawer Model for this 
//  Service Object.%n
//
#define OPOS_CD_IO_PORT_CONFLICT         ((DWORD)0xC00327DAL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_CD_DRAWER_OPEN_FAILED
//
// MessageText:
//
//  The "OpenDrawer" method failed.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nAn attempt to open the cash drawer was not successful.  The Service Object
//  issued an open drawer hardware command to the device, but the hardware drawer 
//  status did not indicate that the drawer had opened.%n
//  %nAction - Check that the drawer is plugged in securely to the terminal.  
//  Do the command again and listen closely to hear for a drawer release.  
//  Make sure there is nothing blocking the drawer.  If the cash drawer 
//  is externally powered, make sure that it is plugged in.
//  The connection, cable, or cash drawer hardware could be bad.
//  Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_CD_DRAWER_OPEN_FAILED       ((DWORD)0xC00F27DBL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - Drawer number, currently only 1 or 2.
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_CD_IN_USE
//
// MessageText:
//
//  Application has already done an "Open" method for this Cash 
//  Drawer configuration.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  Application has already called the "Open" method for a Profile configured
//  with Drawer %3.
//  %n%nThe application has probably instantiated two Cash Drawer 
//  Controls and either tried to "Open" them both with the same Profile or 
//  the two Profiles are configured to the same Drawer number and use ("Uses" 
//  parameter) the Cash Drawer from the same POS Printer Profile.%n
//  %nAction - Use RSM to reconfigure the Profile in error to use 
//  a different Drawer number or "Uses" a different POS Printer Profile, or recreate 
//  the CashDrawer Profile for a different Service Object, or modify 
//  the Application to only use one Cash Drawer Control.%n
//
#define OPOS_CD_IN_USE                   ((DWORD)0xC00327DCL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - Drawer number, currently only 1 or 2.
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_CD_UNKNOWN_STATE
//
// MessageText:
//
//  Could not determine a valid Cash Drawer State.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nAn open or closed drawer state could not be determined from this cash drawer
//  hardware.  The hardware may not be functioning correctly or the cash drawer
//  is not connected to the Port that this Profile is configured for.  
//  The OpenNormal parameter may be incorrectly configured.%n
//  %nAction - Use RSM to verify that the Profile is configured for the 
//  correct Port.  The OpenNormal parameter should be set based on the type of Cash
//  Bases Cash Drawer that is being used.  Verify that the Cash Drawer is connected 
//  and is powered.
//  Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_CD_UNKNOWN_STATE            ((DWORD)0xC00F27DDL)

// ---------------------------------------------------------------------------------
// Coin Dispenser Device Class
// Source: "NCRCoinDispenser" (PROGID for the NCRCoinDispenser.dll Service Object)
// MessageId Range Coin Dispenser: 10250 - 10299
// ---------------------------------------------------------------------------------

// Currently there are no StoreMinder Event Logs for the Coin 
// Dispenser (developed in Japan)
// ---------------------------------------------------------------------------------
// Hard Totals Device Class
// Source: "NCRHardTotals" (PROGID for the NCRHardTotal.dll Service Object)
// MessageId Range Hard Totals: 10300 - 10349
// ---------------------------------------------------------------------------------
// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_HT_UNKNOWN_TERMINAL_TYPE
//
// MessageText:
//
//  Unknown terminal type.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nSince this terminal type is unknown, this hardware does not allow 
//  maintaining Hard Totals in CMOS.  You must maintain Hard Totals on disk.%n
//  %nAction - Use RSM to reconfigure the Hard Totals Profile in 
//  error to use a disk file rather that CMOS.%n
//
#define OPOS_HT_UNKNOWN_TERMINAL_TYPE    ((DWORD)0xC003283CL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: The invalid base I/O address.
//
//
// MessageId: OPOS_HT_BAD_CMOS_BASEADDRESS
//
// MessageText:
//
//  Invalid base I/O address.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nInvalid base I/O address was returned when trying to determine the 
//  terminal type.%n
//  %nAction - The terminal motherboard may need to be replaced.
//  Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_HT_BAD_CMOS_BASEADDRESS     ((DWORD)0xC00F283DL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None.
//
//
// MessageId: OPOS_HT_NO_CMOS_FOUND
//
// MessageText:
//
//  Retail CMOS is not present on this system.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nThis terminal is not configured with retail CMOS.  It could be that this 
//  terminal is not configured CMOS, this is an older NCR terminal and the 
//  hardware has not been updated, or a newer NCR terminal which has a different
//  kind of CMOS than expected.%n
//  %nAction - Use RSM to reconfigure the Hard Totals Profile in 
//  error to use a disk file rather that CMOS.%n
//
#define OPOS_HT_NO_CMOS_FOUND            ((DWORD)0xC00F283EL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - CMOS or hard disk.
//               
//               
//					
// Data: None.
//
//
// MessageId: OPOS_HT_BAD_SUMCHECK
//
// MessageText:
//
//  Sumcheck validation failed.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  The validation process failed due to a bad sumcheck value.  The hard totals 
//  file data has been corrupted.  This can be caused by degrading %3 hardware.
//  %n%nAction - Use the Hard Totals "RecalculateValidationData" method to clear 
//  this error and allow access to the file.  Data in the file has been corrupted, 
//  and the data should be cleared or restored, if possible.  If the hardware
//  is hard disk, use a disk utility to check for disk errors.%n
//  Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_HT_BAD_SUMCHECK             ((DWORD)0xC00F283FL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - Name of file that could not be created.
//               
//               
//					
// Data: GetLastError() result API call failed.
//
//
// MessageId: OPOS_HT_CANNOT_CREATE_FILE
//
// MessageText:
//
//  Could not create or open a hard totals file on the hard disk.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  Could not create or open hard totals file: %3.
//  %n%nSee Data for the 
//  GetLastError() status results.
//  %nAction - Be sure that the file name and directory are valid.  Use a disk
//  utility to check for disk errors with the hard disk.%n
//
#define OPOS_HT_CANNOT_CREATE_FILE       ((DWORD)0xC00B2840L)

// ---------------------------------------------------------------------------------
// Keylock Device Class
// Source: "NCRWedge.Keylock" (PROGID for the NCRWedgeKey.dll Service Object)
// MessageId Range Keylock: 10350 - 10399
// ---------------------------------------------------------------------------------
// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: GetLastError() result API call failed.

//
// MessageId: OPOS_KL_NO_ENTRY_POINT
//
// MessageText:
//
//  GetProcAddress() failed to get the entry point addresses.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nThe system call to query the NCRWedgeKBDFilter.dll entry points (WedgeKLOCKCapture,
//  WedgeKLOCKRead, WedgeKLOCKError, WedgeReadPartNumber, WedgeKeyBoardPartNumber, 
//  WedgeKeyBoardPNRequest) failed.  See Data for the GetLastError() 
//  status results.%n
//  %nAction - Verify that the dll exists in the system directory or
//  in a directory available through the PATH.  Verify that the dll contains these
//  entry points but using a DUMPBIN.EXE utility to view the exports.  Make
//  sure that the Major.Minor release of the dll match the release of the
//  Service Object by use the File Explorer to review the Version Properties.%n
//
#define OPOS_KL_NO_ENTRY_POINT           ((DWORD)0xC001286EL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - Number of Maximum Device instances allowed.
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_KL_MAX_LIMIT
//
// MessageText:
//
//  Cannot exceed maximum number of Keylock instances.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  Could not initialize the Keylock Service Object because an amount of %3 
//  Keylock Devices have already been created.
//  %n%nAction - Don't Open more than the maximum number of supported Keylock
//  instances. %n
//
#define OPOS_KL_MAX_LIMIT                ((DWORD)0xC003286FL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: NCRWedgeKBDFilter.dll return code value.

//
// MessageId: OPOS_KL_WKFM_INVALID_DATA
//
// MessageText:
//
//  Invalid Data.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nThe NCRWedgeKBDFilter.dll WedgeKLOCKRead() function returned invalid Keylock
//  data. See Data for Keylock Data returned.%n
//  %nAction - Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_KL_WKFM_INVALID_DATA        ((DWORD)0xC00F2870L)

// ---------------------------------------------------------------------------------
// Line Display Device Class
// Source: "NCRLineDisplay" (PROGID for the NCRLineDisp.dll Service Object)
// Source: "NCR5991.LineDisplay" (PROGID for the NCR5991.dll Service Object)
// MessageId Range LineDisplay: 10400 - 10449
// ---------------------------------------------------------------------------------
// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - COM Port that this profile is configured for.
//               
//               
//					
// Data: None.
//
//
// MessageId: OPOS_LD_5972_FAILURE
//
// MessageText:
//
//  Could not read the Line Display ID from the Hardware.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  %3 Port
//  %n%nThe Line Display ID could not be obtained for Models "5972" or "5972VFD".  
//  The hardware could not be found on the Port because either there is no
//  Line Display of this model connected to this COM Port, or some
//  other hardware device is connected to the COM Port.%n
//  %nAction - Use RSM to reconfigure the Profile such that the 
//  Line Display model matches that of the hardware.  Verify that the Line Display is
//  connected to the correct COM Port.  Reseat the cabling.  Verify that the 
//  Line Display is plugged in, and the part number is displayed on power up.
//  Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_LD_5972_FAILURE             ((DWORD)0xC00F28A0L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - COM Port that this profile is configured for.
//               
// NOTE: If CTS and DSR are both now ON, then the device is considered online ...
// so even if the FALCON hardware is not actually connected, this Event
// may never get logged.
//               
//					
// Data: None.
//
//
// MessageId: OPOS_LD_FALCON_FAILURE
//
// MessageText:
//
//  Line Display hardware is not Online.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2 Port: %3
//  %n%nThe Line Display, Model "FALCON", is not online.  The hardware could 
//  not be found on Port because either there is no Line Display of this 
//  model connected to this COM Port, or some other hardware device is 
//  connected to the COM Port.%n
//  %nAction - Use RSM to reconfigure the Profile such that the 
//  Line Display model matches that of the hardware.  Verify that the Line Display is
//  connected to the correct COM Port.  Reseat the cabling.  Verify that the 
//  Line Display is plugged in, and the part number is displayed on power up.
//  Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_LD_FALCON_FAILURE           ((DWORD)0xC00F28A1L)

// ---------------------------------------------------------------------------------
// MICR Device Class
// Source: "NCRPrinter.MICR" (PROGID for the NCRPrinter.dll Service Object)
// MessageId Range MICR: 10450 - 10499
// ---------------------------------------------------------------------------------
// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_MC_IN_USE
//
// MessageText:
//
//  Application has already done the "Open" method for this MICR configuration.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nApplication has already called the "Open" method for a Profile configured
//  with this MICR Service Object. The application has probably instantiated two 
//  MICR Controls and either tried to "Open" them both with the same Profile or 
//  the two Profiles are configured to use ("Uses" parameter) the MICR from the 
//  same POS Printer Profile.%n
//  %nAction - Use RSM to reconfigure the Profile in error so
//  that it "Uses" a different POS Printer Profile, recreate the MICR Profile  
//  for a different Service Object, or modify the Application to only use 
//  one MICR Control.%n
//
#define OPOS_MC_IN_USE                   ((DWORD)0xC00328D2L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_MC_VALIDATE_FAILED
//
// MessageText:
//
//  MICR data validation failed.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nThe MICR read has failed.%n
//  %nAction - Retry the MICR read.  If the read continues to fail,
//  contact your NCR OPOS service representative for more information.
//
#define OPOS_MC_VALIDATE_FAILED          ((DWORD)0x800F28D3L)    // change Severity level from error to warning mb185113 7-30-09

// ---------------------------------------------------------------------------------
// MSR Device Class
// Source: "NCRWedge.MSR" (PROGID for the NCRWedgeMSR.dll Service Object)
// Source: "NCR5991.MSR" (PROGID for the NCR5991.dll Service Object)
// Source: "NCR5945.MSR" (PROGID for the NCR5945.dll Service Object)
// MessageId Range MSR: 10500 - 10549
// ---------------------------------------------------------------------------------
// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: GetLastError() result API call failed.

//
// MessageId: OPOS_MR_NO_ENTRY_POINT
//
// MessageText:
//
//  GetProcAddress() failed to get the entry point addresses.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nThe system call to query the NCRWedgeKBDFilter.dll entry points (WedgeMSRCapture, 
//  WedgeMSRRead, WedgeMSRError, WedgeReadPartNumber) failed.  See Data for the GetLastError() 
//  status results.%n
//  %nAction - Verify that the dll exists in the system directory or
//  in a directory available through the PATH.  Verify that the dll contains these
//  entry points but using a DUMPBIN.EXE utility to view the exports.  Make
//  sure that the Major.Minor release of the dll match the release of the
//  Service Object by use the File Explorer to review the Version Properties.%n
//
#define OPOS_MR_NO_ENTRY_POINT           ((DWORD)0xC0012904L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: NCRWedgeKBDFilter.dll return code value.

//
// MessageId: OPOS_MR_WKFM_INVALID_DATA
//
// MessageText:
//
//  Invalid Data.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nThe NCRWedgeKBDFilter.dll WedgeMSRRead() function returned invalid MSR data.
//  See Data for MSR Data returned.%n
//  %nAction - Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_MR_WKFM_INVALID_DATA        ((DWORD)0xC00F2905L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - track number
//               
//					
// Data: none

//
// MessageId: OPOS_MR_BAD_TRACK_IN_START
//
// MessageText:
//
//  Start Sentinel Error.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  Data of the track #%3 was not obtained due to start sentinel error.
//  %n%nAction - Try reading the card again.  If the problem persists, contact
//  your NCR OPOS service representative.%n
//
#define OPOS_MR_BAD_TRACK_IN_START       ((DWORD)0x80112906L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - track number
//               
//					
// Data: none

//
// MessageId: OPOS_MR_BAD_TRACK_IN_END
//
// MessageText:
//
//  End Sentinel Error.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  Data of the track #%3 was not obtained due to end sentinel error.
//  %n%nAction - Try reading the card again.  If the problem persists, contact
//  your NCR OPOS service representative.%n
//
#define OPOS_MR_BAD_TRACK_IN_END         ((DWORD)0x80112907L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - track number
//               
//					
// Data: none

//
// MessageId: OPOS_MR_BAD_TRACK_IN_PARITY
//
// MessageText:
//
//  Parity Error.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  Data of the track #%3 was not obtained due to parity error.
//  %n%nAction - Check the magnetic stripes of the card and try reading
//  the card again.  If the problem persists with other cards, contact
//  your NCR OPOS service representative.%n
//
#define OPOS_MR_BAD_TRACK_IN_PARITY      ((DWORD)0x80102908L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - track number
//               
//					
// Data: none

//
// MessageId: OPOS_MR_BAD_TRACK_IN_LRC
//
// MessageText:
//
//  LRC Error.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  Data of the track #%3 was not obtained due to LRC error.
//  %n%nAction - Check the magnetic stripes of the card and try reading
//  the card again.  If the problem persists with other cards, contact
//  your NCR OPOS service representative.%n
//
#define OPOS_MR_BAD_TRACK_IN_LRC         ((DWORD)0x80102909L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - track number
//               
//					
// Data: none

//
// MessageId: OPOS_MR_BAD_TRACK_IN_FAILURE
//
// MessageText:
//
//  Internal Parsing Error.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  Data of the track #%3 was not obtained due to internal parsing error.
//  %n%nAction - Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_MR_BAD_TRACK_IN_FAILURE     ((DWORD)0xC012290AL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// 
//               
//					
// Data: none

//
// MessageId: OPOS_MR_NO_TRACK_DATA
//
// MessageText:
//
//  No Track Data Available.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nNo track data of the card was available due to reading failure.%n
//  %nAction - Try reading the card again.  If the problem persists, contact
//  your NCR OPOS service representative.%n
//
#define OPOS_MR_NO_TRACK_DATA            ((DWORD)0x8011290BL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// 
//               
//					
// Data: none

//
// MessageId: OPOS_MR_PARTIAL_TRACK_DATA
//
// MessageText:
//
//  Some Track Data Unavailable.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nSome track data of the card was not available due to reading failure,
//  but good track data was returned.%n
//  %nAction - Try reading the card again.  If the problem persists, contact
//  your NCR OPOS service representative.%n
//
#define OPOS_MR_PARTIAL_TRACK_DATA       ((DWORD)0x4011290CL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - Set up information (IRQ and Memory Address)
//               
//					
// Data: none

//
// MessageId: OPOS_MR_NO_DEVICE_ATTACHED
//
// MessageText:
//
//  No MSR Device Recognized.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  MSR device is not recognized in the setting %3,
//  and the device is not ready to run.%n
//  %nAction - Verify that the MSR base address is correctly set
//  in the BIOS menu (Advanced - I/O Device Configuration - MSR Address).
//  And then, verify that values in the system registry
//  [HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\%2\Parameters]
//  are correctly defined according to the value in the BIOS.  
//  %n%nThe values of the system registry should be:
//    [Address]  0xD0000 if the D000-D1FF is set in the BIOS,
//               0xCA000 if the CA00-CBFF is set in the BIOS,
//               0xC8000 if the C800-C9FF is set in the BIOS.
//    [IRQ]      0x0F%n
//
#define OPOS_MR_NO_DEVICE_ATTACHED       ((DWORD)0xC003290DL)

// ---------------------------------------------------------------------------------
// POS Keyboard Device Class
// Source: 
// MessageId Range POS Keyboard: 10550 - 10599
// ---------------------------------------------------------------------------------

// Currently there are no POS Keyboard Service Objects supported by NCR Atlanta
// ---------------------------------------------------------------------------------
// POS Printer Device Class
// Source: "NCRPrinter.POSPrinter" (PROGID for the NCRPrinter.dll Service Object)
// MessageId Range: POS Printer: 10600 - 10649
// ---------------------------------------------------------------------------------
// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_PP_IN_USE
//
// MessageText:
//
//  Application has already done the "Open" method for this POS Printer 
//  configuration.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nApplication has already called the "Open" method for a Profile configured
//  with this POS Printer Service Object. The application has probably 
//  instantiated two POS Printer Controls and either tried to "Open" them 
//  both with the same Profile or the two Profiles are configured with the 
//  same COM Port.%n
//  %nAction - Use RSM to reconfigure the Profile in error so
//  that it is configured with a different COM Port, or modify the Application 
//  to only use one POS Printer Control.%n
//
#define OPOS_PP_IN_USE                   ((DWORD)0xC0032968L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_PP_PS_CLAIM_FAILED
//
// MessageText:
//
//  Failed to claim power sharing mutex resource.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nOn a Falcon 7445 terminal, the integrated Printers (Model 1001 and 2001) 
//  must share power with the external slip Printer (Model 500).  
//  On other NCR terminals the Printer Control must share
//  power with the Serial/7453 Cash Drawer Control or another Printer Control.  
//  The software IPC Resource that prevents two Controls from accessing power 
//  at the same time is not functioning correctly.  This could be due to a 
//  software defect or operating system malfunction.  When the resource
//  cannot be claimed the Printer will not perform the requested Printer function.%n
//  %nAction - Power down the terminal.  Though this is a software error, 
//  it could cause a brown out in the workstation.
//  Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_PP_PS_CLAIM_FAILED          ((DWORD)0xC00D2969L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_PP_PS_RELEASE_FAILED
//
// MessageText:
//
//  Failed to release power sharing mutex resource.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nOn a Falcon 7445 terminal, the integrated Printers (Model 1001 and 2001) 
//  must share power with the external slip Printer (Model 500).  
//  On other NCR terminals the Printer Control must share
//  power with the Serial/7453 Cash Drawer Control or another Printer Control.  
//  The software IPC Resource that prevents two Controls from accessing power 
//  at the same, time is not functioning correctly.  This could be due to a 
//  software defect or operating system malfunction. When the resource
//  cannot be released, other Controls that use this IPC resource will not perform 
//  as expected.%n
//  %nAction - Power down the terminal.  Though this is a software error,
//  it could cause a brown out in the workstation.
//  Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_PP_PS_RELEASE_FAILED        ((DWORD)0xC00D296AL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - The Port that failed.  Example: "COM1"
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_PP_BAD_STATUS
//
// MessageText:
//
//  Bad, invalid, or no Printer status received.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2 Port %3
//  %n%nThe bad Printer status indicates that either the printer connected to 
//  the Port does not match the Model that this profile is configured for,
//  there is no Printer connected to this COM Port, or some other hardware 
//  device such as a scanner or modem is connected to the COM Port.%n
//  %nAction - Use RSM to reconfigure the Profile such that the 
//  Printer model matches that of the hardware.  Verify that the Printer is
//  connected to the correct COM Port.  Reseat the cabling.  Verify that the 
//  printer is turned on.%n
//
#define OPOS_PP_BAD_STATUS               ((DWORD)0xC00F296BL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: Printer Status Bytes
//
//
// MessageId: OPOS_PP_DEFAULT
//
// MessageText:
//
//  Printer Error.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nAn unrecognized printer error was encountered.  Could be an 
//  internal programming error.
//  See Data for the Printer Status Bytes returned from the Printer.%n
//  %nAction - Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_PP_DEFAULT                  ((DWORD)0xC00F296CL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: Printer Status Bytes
//
//
// MessageId: OPOS_PP_NONRECOVERABLE
//
// MessageText:
//
//  Printer non-recoverable error occurred.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nA severe Printer error has occcurred.  This could be due to a circuit 
//  board failure or some other hardware malfunction. 
//  See Data for the Printer Status Bytes returned from the Printer.%n
//  %nAction - The Printer needs hardware maintenance.  Replace the Printer.
//  Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_PP_NONRECOVERABLE           ((DWORD)0xC00F296DL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: Printer Status Bytes
//
//
// MessageId: OPOS_PP_MOTOR
//
// MessageText:
//
//  Printer motor error occurred.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nSee Data for the Printer Status Bytes returned from the Printer.%n
//  %nAction - This is normally caused by a slip paper or print head jam.
//  Clear any paper from the slip station and retry the operation. If 
//  the problem persists after several attempts to clear there maybe a 
//  mechanical problem which will require the printer to be replaced.
//  If the problem persists contact your NCR service representative.%n
//
#define OPOS_PP_MOTOR                    ((DWORD)0xC00F296EL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: Printer Status Bytes
//
//
// MessageId: OPOS_PP_KNIFE
//
// MessageText:
//
//  Printer knife error occurred.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nSee Data for the Printer Status Bytes returned from the Printer.%n
//  %nAction - Replace the printer knife.
//  Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_PP_KNIFE                    ((DWORD)0xC00F296FL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: Printer Status Bytes
//
//
// MessageId: OPOS_PP_RECOVERABLE
//
// MessageText:
//
//  Printer recoverable error occurred.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nThe Printer has detected that the print head has overheated.  The temperature
//  within the Printer has caused it to temporarily stop printing in order to cool
//  itself down.  If this error happens too frequently, it could mean that the
//  print head has an overheating problem and is operating in a degraded mode.
//  See Data for the Printer Status Bytes returned from the Printer.%n
//  %nAction - Monitor this error for reoccurrence.  If it happens frequently, 
//  contact your NCR OPOS service representative for more information.%n
//
#define OPOS_PP_RECOVERABLE              ((DWORD)0xC00F2970L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_PP_PAPER_OUT
//
// MessageText:
//
//  Printer paper out error occurred.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nHas detected that the printer is out of either receipt
//  or journal paper depending on the model.
//  See Data for the Printer Status Bytes returned from the Printer.%n
//  %nAction - Replace the paper roll.%n
//
#define OPOS_PP_PAPER_OUT                ((DWORD)0x400F2971L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_PP_COVER_OPEN
//
// MessageText:
//
//  Printer cover open error occurred.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nhas detected that the cover of the Printer is open and cannot complete
//  the Printer request.%n
//  %nAction - Close the Printer cover and try the Printer request again.%n
//
#define OPOS_PP_COVER_OPEN               ((DWORD)0x400F2972L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_PP_ERROR_TO_NORMAL
//
// MessageText:
//
//  Printer state changed from Error to Normal.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nA previous error has now been resolved.%n
//  %nAction - No Action.%n
//
#define OPOS_PP_ERROR_TO_NORMAL          ((DWORD)0x400F2973L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_PP_OFF_TO_ON
//
// MessageText:
//
//  Printer state change from OFF to ON.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nThe printer has either just come on or has been cleared of an error which
//  made it appear off.%n
//  %nAction - No Action.%n
//
#define OPOS_PP_OFF_TO_ON                ((DWORD)0x400F2974L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_PP_ON_TO_OFF
//
// MessageText:
//
//  Printer state change from ON to OFF.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nThe printer is either turned off, or is not responding to status request polls
//  therefore it appears off.  For some Printer models the software is unable to determine
//  if the Printer if actually off or in an error state.  For the integrated 
//  Falcon printers (Model 1001 or 2001), they are always powered on when the terminal
//  is on, so they are in a non-responsive error mode.%n
//  %nAction - For the integrated Falcon printers, check that the blue lever inside the 
//  printer is not switched off.%n
//
#define OPOS_PP_ON_TO_OFF                ((DWORD)0x400F2975L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_PP_CABINET_DOOR_OPEN
//
// MessageText:
//
//  Outer cabinet door of printer mechanism is open.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nHas detected that the cabinet door of the Printer is open and cannot complete
//  the Printer request.%n
//  %nAction - Close the Printer cabinet door and try the Printer request again.%n
//
#define OPOS_PP_CABINET_DOOR_OPEN        ((DWORD)0x400F2976L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_PP_PRESENTER_PAPER_PRESENT
//
// MessageText:
//
//  Receipt Presenter Mechanism has paper in it from the previous transaction.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nhas detected that the Receipt Presenter Mechanism of the Printer still has
//  paper in it from the previous transaction and cannot complete the Printer 
//  request.%n
//  %nAction - Remove the paper from the Receipt Presenter and try the Printer 
//  request again.%n
//
#define OPOS_PP_PRESENTER_PAPER_PRESENT  ((DWORD)0x400F2977L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_PP_PRESENTER_PAPER_JAM
//
// MessageText:
//
//  Receipt Presenter mechanism has encountered a paper jam during printing.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nhas detected that there has been a paper jam somewhere in the receipt
//  mechanism paper path. Unit will not be operational until cleared.%n
//  %nAction - Remove and reload the paper from the printer to correct
//  the jam. Reset the printer in order to return it to operational 
//  status.%n
//
#define OPOS_PP_PRESENTER_PAPER_JAM      ((DWORD)0xC00F2978L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_PP_PRESENTER_MECHANISM_FAILURE
//
// MessageText:
//
//  Receipt Presenter mechanism has failed to rotate to proper position.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nhas detected that the Receipt Presenter Mechanism has failed to rotate to
//  either the presentation position or the normal print position.%n
//  %nAction - Remove and reload the paper from the printer to correct
//  the jam. Reset the printer in order to return it to operational 
//  status.%n
//
#define OPOS_PP_PRESENTER_MECHANISM_FAILURE ((DWORD)0xC00F2979L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_PP_PRESENTER_BLACKMARK_FAILURE
//
// MessageText:
//
//  Black Mark receipt cutting is being used, but no black mark detected.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nhas not been able to detect the Black Mark for paper cut positioning.
//  This could be either Black Mark should not be used, wrong type of
//  paper, or a hardware failure.%n
//  %nAction - Remove and reload the paper from the printer to correct
//  the jam. Reset the printer in order to return it to operational 
//  status.  Verify that paper is proper type to use.%n
//
#define OPOS_PP_PRESENTER_BLACKMARK_FAILURE ((DWORD)0xC00F297AL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_PP_THERMAL_PRINTHEAD_FAILURE
//
// MessageText:
//
//  Firmware has detected a failure of the Thermal Print Head Mechanism.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nInternal firmware monitoring routines have determined that there has
//  been a failure of the Thermal Print Head Mechanism.  The mechanism or
//  the entire printer need to be replaced.%n
//  %nAction - Call Service Personel to replace the Thermal Print Head or
//  replace the printer.%n
//
#define OPOS_PP_THERMAL_PRINTHEAD_FAILURE ((DWORD)0xC00F297BL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_PP_RECEIPT_PAPER_LOW
//
// MessageText:
//
//  The Receipt station is running low on paper and will need replaced soon.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nThe Receipt Paper Low sensor in the printer has detected that the paper
//  is nearing the end of the roll.  The actual number of transactions or
//  lines that can be printed before paper is completely out depends on the
//  printer, sensor adjustment, and transactions sizes.%n
//  %nAction - Make sure a replacement roll of paper is available at the site
//  where the printer is installed.  Depending on store procedures, you may
//  want to replace the paper now, or wait until an out-of-paper alert is
//  received.%n
//
#define OPOS_PP_RECEIPT_PAPER_LOW        ((DWORD)0x800F297CL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_PP_RECOVERED_TEMPERATURE
//
// MessageText:
//
//  The printer has recovered from a recoverable thermal overheat.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nThe printer had temporarily ceased functionality due to an overheated
//  print head.  The print head has cooled down sufficiently enough for
//  printing to resume.%n
//  %nAction - No action.%n
//
#define OPOS_PP_RECOVERED_TEMPERATURE    ((DWORD)0x400F297DL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_PP_PAPER_OK
//
// MessageText:
//
//  The paper roll in the printer now has sufficient paper for operation.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nThe printer had been in either a paper low or a paper out state.  The 
//  paper roll has been replaced and there is now enough paper for an 
//  extended period of normal printing.%n
//  %nAction - No action.%n
//
#define OPOS_PP_PAPER_OK                 ((DWORD)0x400F297EL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_PP_COVER_OK
//
// MessageText:
//
//  The clamshell or cassette cover has been closed.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nEither the paper roll clamshell door or the ribbon cassette door had
//  been open, but is now closed and the printer is ready for normal
//  operation.%n
//  %nAction - No action.%n
//
#define OPOS_PP_COVER_OK                 ((DWORD)0x400F297FL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_PP_CABINET_DOOR_CLOSED
//
// MessageText:
//
//  The printer mechanism door on the kiosk has been closed.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nThe door on the kiosk printer which covers the print mechanism and
//  paper roll had been open, but has now been closed.%n
//  %nAction - No action.%n
//
#define OPOS_PP_CABINET_DOOR_CLOSED      ((DWORD)0x400F2980L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_PP_PRESENTER_CLEAR
//
// MessageText:
//
//  The receipt ticket presenter mechanism is now clear of abnormal paper.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nA paper in presenter error had been logged because of an unexpected 
//  condition of paper in the presenter during an attempt to print.  The 
//  condition has been cleared, and the printer is now ready again to 
//  print.%n
//  %nAction - No action.%n
//
#define OPOS_PP_PRESENTER_CLEAR          ((DWORD)0x400F2981L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_PP_SW_TIMEOUT
//
// MessageText:
//
//  The Printer Service Object timed out waiting for a response from the printer.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nThis problem is most likely cause by an application coding issue.  The Printer
//  Service Object has a defined amount of time it waits for a status response. If
//  the application places too many print operations within a single request, the
//  time for completion may exceed.%n
//  %nAction - Report the problem to your application provider.%n
//
#define OPOS_PP_SW_TIMEOUT               ((DWORD)0xC00F2986L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_PP_HW_TIMEOUT
//
// MessageText:
//
//  The Service Object timed out attempting to transmit data to the printer.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nWhen attempting to transmit data to the printer a time-out was encountered.
//  This is most likey caused by the printer becoming physically disconnected
//  from the terminal, or disconnected from power.%n
//  %nAction - Check all cables to the printer to make sure it is connected
//  properly, and turned on.%n
//
#define OPOS_PP_HW_TIMEOUT               ((DWORD)0xC00F2987L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_PP_WRONG_PAPER
//
// MessageText:
//
//  Paper roll inserted into printer does not match printer paper type configuration.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nPrinter is configured for either Thermal or Label paper instead of 
//  automatic detection, and the type of paper roll loaded does not match
//  the configuration.%n
//  %nAction - Load a paper roll that matches the configuration, or change the
//  configuration to match the paper being used, or to automatic detection.%n
//
#define OPOS_PP_WRONG_PAPER              ((DWORD)0x800F2988L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_PP_THERMAL_ELEMENT_FAILURE
//
// MessageText:
//
//  Firmware has detected one or more thermal dot elements has failed.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nPrinter has detected that one or more elements in the print heat that
//  generates the dots for chracters is not functioning.%n
//  %nAction - Visually inspect the output of the printer. If the elements
//  that are not functioning are resulting in unreadable receipts replace
//  the printer.%n
//
#define OPOS_PP_THERMAL_ELEMENT_FAILURE  ((DWORD)0x800F2989L)

// ---------------------------------------------------------------------------------
// Scanner Device Class
// Source:
// MessageId Range Remote Order Display:   10650 - 10699
// ---------------------------------------------------------------------------------
//
// Currently there are no Remote Order Display Service Objects supported by NCR Atlanta
// ---------------------------------------------------------------------------------
// Scale Device Class
// Source: "NCR78xx.Scale" (PROGID for the NCR78xx.dll Service Object)
// MessageId Range Scale: 10700 - 10749
// ---------------------------------------------------------------------------------
// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: Application Thread ID (long)
//
//
// MessageId: OPOS_SL_IN_USE
//
// MessageText:
//
//  Application has already done the "Open" method for this Scale configuration.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nApplication has already called the "Open" method for a Profile configured
//  with this Scale Service Object. The application has probably instantiated two 
//  Scale Controls and either tried to "Open" them both with the same Profile or 
//  the two Profiles are configured to use ("Uses" parameter) the Scale from the 
//  same Scanner Profile.  See Data for the Application's Thread ID.%n
//  %nAction - Use RSM to reconfigure the Profile in error so
//  that it "Uses" a different Scanner Profile, recreate the Scale Profile  
//  for a different Service Object, or modify the Application to only use 
//  one Scale Control.%n
//
#define OPOS_SL_IN_USE                   ((DWORD)0xC00329CCL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_SL_MODEL_NOT_SUPPORTED
//
// MessageText:
//
//  The Scanner model does not support a Scale.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nThe Scanner hardware that this Scale Profile "Uses", does not support a Scale.%n
//  %nAction - Use RSM to reconfigure the Profile in error so
//  it uses a different Scanner Profile, or reconfigure the Scanner Profile
//  for a model that supports a scale (i.e. 7870, 7875, or 7880).%n
//
#define OPOS_SL_MODEL_NOT_SUPPORTED      ((DWORD)0xC00329CDL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - The Port that failed.  Example: "COM1"
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_SL_BAD_STATUS
//
// MessageText:
//
//  Bad, invalid, or no Scale status received.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2 Port: %3
//  %n%nThe bad Scale status indicates that either the Scale connected to
//  the Port does not match the Model that this Profile is configured for,
//  there is no Scale connected to this COM Port, or some other hardware
//  device such as a printer or modem is connected to the COM Port.%n
//  %nAction - Use RSM to reconfigure the Profile such that the
//  Scanner/Scale model matches that of the hardware.  See the Model defined
//  in the Scanner that this Scale Profile "Uses". Scanner Models that support
//  Scales include: 7870, 7875, and 7880. Verify that the
//  Scanner/Scale is connected to the correct COM Port.  Reseat the cabling.
//  Verify that the scanner/scale is turned, on plugged in.%n
//
#define OPOS_SL_BAD_STATUS               ((DWORD)0xC00F29CEL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - Suffix value.
//               
//               
//					
// Data: Scale data received.

//
// MessageId: OPOS_SL_BAD_SUFFIX
//
// MessageText:
//
//  Bad Scale Data, no suffix found.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  Error was detected while parsing the Scale data.  The Service Object is
//  configured such that a "%3" suffix is expected to prepend the Scale data and
//  the suffix could not be found.
//  %n%nThe Scanner/Scale hardware has not been configured
//  to prepend a suffix or the Service Object has been incorrectly configured
//  to expect a suffix.  The Scale data has been corrupted.
//  See Data for the Scale data received.%n
//  %nAction - Use RSM to correctly configure the Scanner profile 
//  that this Scale profile "Uses".  Program the Scanner/Scale hardware to have the 
//  correct suffix.
//  Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_SL_BAD_SUFFIX               ((DWORD)0xC00F29CFL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - Prefix value.
//               
//               
//					
// Data: Scale data received.

//
// MessageId: OPOS_SL_BAD_PREFIX
//
// MessageText:
//
//  Bad Scale Data, no prefix found.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  Error was detected while parsing the Scale data.  The Service Object is
//  configured such that a "%3" prefix is expected to prepend the Scale data and
//  the prefix could not be found.
//  %n%nThe Scanner/Scale hardware has not been configured
//  to prepend a prefix or the Service Object has been incorrectly configured
//  to expect a prefix.  The Scale data has been corrupted.
//  See Data for the Scale data received.%n
//  %nAction - Use RSM to correctly configure the Scanner profile 
//  that this Scale profile "Uses".  Program the Scanner/Scale hardware to have the 
//  correct prefix.
//  Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_SL_BAD_PREFIX               ((DWORD)0xC00F29D0L)

// ---------------------------------------------------------------------------------
// Scanner Device Class
// Source: "NCR78xx.Scanner" (PROGID for the NCR78xx.dll Service Object)
// Source: "NCRWedge.Scanner" (PROGID for the NCRWedgeScan.dll Service Object)
// MessageId Range Scanner: 10750 - 10799
// ---------------------------------------------------------------------------------
// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: Application Thread ID (long)
//
//
// MessageId: OPOS_SN_IN_USE
//
// MessageText:
//
//  Application has already called the "Open" method for a Profile configured
//  with this Scanner Service Object. The application has probably 
//  instantiated two Scanner Controls and either tried to "Open" them 
//  both with the same Profile or the two Profiles are configured with the 
//  same COM Port.  See Data for the Application's Thread ID.%n
//  %nAction - Use RSM to reconfigure the Profile in error so
//  that it is configured with a different COM Port, or modify the Application 
//  to only use one Scanner Control.%n
//
#define OPOS_SN_IN_USE                   ((DWORD)0xC00329FEL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - The Port that failed.  Example: "COM1"
//               
//               
//					
// Data: None
//
//
// MessageId: OPOS_SN_BAD_STATUS
//
// MessageText:
//
//  Bad, invalid, or no Scanner status received.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2 Port %3
//  %n%nThe bad Scanner status indicates that either the Scanner connected to
//  the Port does not match the Model that this profile is configured for,
//  there is no Scanner connected to this COM Port, or some other hardware
//  device such as a printer or modem is connected to the COM Port.  The
//  serial configuration items such as Baud, Parity, and StopBit may not match
//  what the Scanner hardware is configured for.%n
//  %nAction - Use RSM to reconfigure the Profile such that the
//  Scanner model matches that of the hardware.  Verify that the Scanner is
//  connected to the correct COM Port.  Reseat the cabling.  Verify that the
//  Scanner is turned, on plugged in.  Verify that the Scanner is in the
//  correct serial mode by using the Scanner Programming Tags (ST-2121-74)
//  to program the Scanner's RS232 hardware settings.%n
//
#define OPOS_SN_BAD_STATUS               ((DWORD)0xC00F29FFL)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: GetLastError() result API call failed.

//
// MessageId: OPOS_SN_NO_ENTRY_POINT
//
// MessageText:
//
//  GetProcAddress() failed to get the entry point addresses.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nThe system call to query the NCRWedgeKBDFilter.dll entry points (WedgeSCANCapture, WedgeSCANRead,
//  WedgeSCANError, WedgeWriteData, WedgeReadPartNumber) failed.  See Data for the GetLastError() 
//  status results.%n
//  %nAction - Verify that the dll exists in the system directory or
//  in a directory available through the PATH.  Verify that the dll contains these
//  entry points but using a DUMPBIN.EXE utility to view the exports.  Make
//  sure that the Major.Minor release of the dll match the release of the
//  Service Object by use the File Explorer to review the Version Properties.%n
//
#define OPOS_SN_NO_ENTRY_POINT           ((DWORD)0xC0012A00L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None.

//
// MessageId: OPOS_SN_OVERFLOW
//
// MessageText:
//
//  Buffer overflow.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nInternal buffer overflow. More data came from Wedge Filter Dll than
//  the Service Object could handle.  Internal programming error.%n
//  %nAction - Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_SN_OVERFLOW                 ((DWORD)0xC0072A01L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - Suffix value.
//               
//               
//					
// Data: None.

//
// MessageId: OPOS_SN_BAD_SUFFIX
//
// MessageText:
//
//  Bad Scanner Data, no suffix found.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  Error was detected while parsing the Scanner data.  The Service Object is
//  configured such that a "%3" suffix is expected to prepend the Scanner data and
//  the suffix could not be found.
//  %n%nThe Scanner hardware has not been configured
//  to prepend a suffix or the Service Object has been incorrectly configured
//  to expect a suffix.  The Scanner data has been corrupted.
//  See Data for the Scanner data received.%n
//  %nAction - Use RSM to correctly configure the scanner profile 
//  in error.  Program the Scanner hardware to have the correct suffix.  
//  Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_SN_BAD_SUFFIX               ((DWORD)0xC00F2A02L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - Prefix value.
//               
//               
//					
// Data: None.

//
// MessageId: OPOS_SN_BAD_PREFIX
//
// MessageText:
//
//  Bad Scanner Data, no prefix found.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  Error was detected while parsing the Scanner data.  The Service Object is
//  configured such that a "%3" prefix is expected to append the Scanner data and
//  the prefix could not be found.
//  %n%nThe Scanner hardware has not been configured
//  to append a prefix or the Service Object has been incorrectly configured
//  to expect a prefix.  The Scanner data has been corrupted.
//  See Data for the Scanner data received.%n
//  %nAction - Use RSM to correctly configure the scanner profile 
//  in error.  Program the Scanner hardware to have the correct prefix.  
//  Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_SN_BAD_PREFIX               ((DWORD)0xC00F2A03L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None.

//
// MessageId: OPOS_SN_BAD_TAG
//
// MessageText:
//
//  Bad Scanner Data.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nError was detected while parcing the Scanner/Scale data.  The Service Object 
//  is expecting Scanner data for a Scanner/Scale model.  The Scanner data should 
//  be lead with "0x30 0x38".  The profile could be configured with an incorrect 
//  model or the Scanner data has been corrupted.
//  See Data for the Scanner data received.%n
//  %nAction - Use RSM to correctly configure the scanner profile 
//  in error. Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_SN_BAD_TAG                  ((DWORD)0xC00F2A04L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None.

//
// MessageId: OPOS_SN_MOTOR_FAILURE
//
// MessageText:
//
//  Scanner Motor Failed.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nA scanner motor failure has occurred.  The scanner requires service.%n
//  %nAction - Have the motor unit replaced. Contact your NCR OPOS service 
//  representative for more information.%n
//
#define OPOS_SN_MOTOR_FAILURE            ((DWORD)0xC00F2A05L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None.

//
// MessageId: OPOS_SN_LASER_FAILURE
//
// MessageText:
//
//  Scanner Laser Failed.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nA scanner laser failure has occurred.  The scanner requires service.%n
//  %nAction - Have the laser unit replaced. Contact your NCR OPOS service 
//  representative for more information.%n
//
#define OPOS_SN_LASER_FAILURE            ((DWORD)0xC00F2A06L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//               
//					
// Data: None.

//
// MessageId: OPOS_SN_WOBULATOR_FAILURE
//
// MessageText:
//
//  Scanner Wobulator Failed.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nA scanner wobulator failure has occurred.  The scanner requires service.%n
//  %nAction - Have the wobulator unit replaced. Contact your NCR OPOS service 
//  representative for more information.%n
//
#define OPOS_SN_WOBULATOR_FAILURE        ((DWORD)0xC00F2A07L)

// Start RPSUPOS-1817 Jan 2017
// Add message ID for Scanner SubDevice issue
//
// MessageId: OPOS_SN_SUBDEVICE_FAILURE
//
// MessageText:
//
//  Scanner SubDevice Failed.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nA scanner subdevice (internal or external device connected to the scanner) failure has occurred.  The scanner requires service.%n
//  %nAction - Have the subdevice re-connected or replaced. Contact your NCR OPOS service 
//  representative for more information.%n
//
#define OPOS_SN_SUBDEVICE_FAILURE        ((DWORD)0x800F2A08L)

// End RPSUPOS-1817
// ---------------------------------------------------------------------------------
// Signature Capture Device Class
// Source: "NCR5991.SigCap" (PROGID for the NCR5991.dll Service Object)
// MessageId Range Signature Capture: 10800 - 10849
// ---------------------------------------------------------------------------------
// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - COM Port Value, COM1-COM20
//               
//					
// Data: Command Sent and Status Byte returned, if there is one.  Refer
// to the "NCR 5991 Signature Capture Peripheral Interface Document" 
// (250-0006654) for more detailed information.
//
//       Commands Possible -   0x02 Transmit Compressed Signature Data
//                             0x03 Transmit NCR or IBM Printable Signature Data
//                             0x04 Transmit Generic Printable Signature
//                             0x05 Transmit Next Block of Data
//                             0x0B Configure Device
//                             0x31 Clear Screen
//                             0x33 Set Text Font (Customer Display)
//                             0x34 Display Text String at Row, COlumn
//                             0x41 Enable MSR
//                             0x42 Poll for MSR Data
//                             0x71 Perform Communications Turnaround
//
//       Statuses Possible -   0x45 Text String Truncated
//                             0x70 No OS loaded
//                             0x80 More Data Available
//                             0x90 No Application Loaded
//                             0xC7 MSR Data Unreadable
//                             0xE0 MSR Busy, Already Enabled
//                             0xE6 Invalid DATA field
//                             0xE7 Invalid Hardware Configuration
//                             0xEC Invalid Parameter
//                             0xEF Power Failure Occurred
//                             0xF0 No Data Available
//                             0xF1 Invalid VLI
//                             0xF2 Communications Time-Out
//                             0xF5 Communications Adapter Failure
//                             0xF8 Internal System Failure
//                             0xFA Invalid Mode for Command
//                             0xFB Receive Buffer Full
//                             0xFD Invalid Command
//                             0xFF Invalid BCC
//
//
// MessageId: OPOS_SC_BAD_STATUS
//
// MessageText:
//
//  Bad, invalid, or no 5991 Signature Capture status received.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nThe bad 5991 status indicates that either there
//  is no 5991 device connected to this Port, some other hardware
//  device such as a scanner or modem is connected to the COM Port,
//  or the 5991 hardware is failing. See Data for the
//  Signature Capture Command sent (byte 1) and Status Byte
//  (byte 2) returned.%n
//  %nAction - Verify that the 5991 device is connected to the
//  correct COM Port as indicated with RSM.  Reconfigure
//  if necessary.  Reseat the cabling.  Verify that the Signature Capture
//  is turned on. Analyze the Data for more information.  Contact your NCR
//  OPOS service representative for more information.%n
//
#define OPOS_SC_BAD_STATUS               ((DWORD)0xC00F2A30L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//					
// Data: None.
//
//
// MessageId: OPOS_SC_BAD_TURNAROUND_DATA
//
// MessageText:
//
//  CheckHealth Internal turnaround (Loop) test failed.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nEither the data returned during the loop test was not the correct
//  length, or the data string was not the same data string that was
//  sent to the Signature Capture hardware.%n
//  %nAction - Verify that the Signature Capture is connected to the 
//  correct COM Port as indicated with RSM.  Reconfigure
//  if necessary.  Reseat the cable.  Verify that the Signature Capture
//  is turned on. The hardware may need to be replaced. Contact your NCR 
//  OPOS service representative for more information.%n
//
#define OPOS_SC_BAD_TURNAROUND_DATA      ((DWORD)0xC00F2A31L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//					
// Data: None.
//
//
// MessageId: OPOS_SC_BCC_INVALID
//
// MessageText:
//
//  BCC invalid while reading signature data.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nThe invalid Block Check Character indicates that the message
//  has been corrupted during transmission from the 5991 Device
//  and the host.%n
//  %nAction - The hardware or cable may need to be replaced. 
//  Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_SC_BCC_INVALID              ((DWORD)0xC00F2A32L)

// ---------------------------------------------------------------------------------
// Tone Indicator Device Class
// Source: 
// MessageId Range Tone Indicator: 10850 - 10899
// ---------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------
// IVICMForm Device Class
// Source: 
// MessageId Range Tone Indicator: 10900 - 10949
// ---------------------------------------------------------------------------------
// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//               
//					
// Data: None.
//
//
// MessageId: OPOS_IVICMFORM_FAIL_EXTRACT_HC_FILE
//
// MessageText:
//
//  Failed to extract CheckHealth Dialog resource from file.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2
//  %n%nThe interactive checkhealth failed in its attempt to extract the
//  CheckHealth Dialog resource from the Service Object file. See Data
//  for the GetLastError() status results.%n
//  %nAction - Contact your NCR OPOS service representative for more information.%n
//
#define OPOS_IVICMFORM_FAIL_EXTRACT_HC_FILE ((DWORD)0xC00C2A94L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - form file (.out) being stored
//					
// Data: None.
//
//
// MessageId: OPOS_IVICMFORM_FAIL_STORE_FORM_FILE
//
// MessageText:
//
//  Failed to store form file on device.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  Failed to store form file "%3" on device.
//  %n%nA failure occurred during
//  transmission of the file to the hardware device.%n
//  %nAction - Ensure the device is operational. The retry the StoreFormOnDevice()
//  or Interactive CheckHealth attempt. Contact your NCR OPOS service
//  representative for more information.%n
//
#define OPOS_IVICMFORM_FAIL_STORE_FORM_FILE ((DWORD)0xC00B2A95L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - form file (.icf) being stored
//					
// Data: None.
//
//
// MessageId: OPOS_IVICMFORM_STORE_KEYPAD_KEYBOARD_FORM
//
// MessageText:
//
//  Failed to store form on device.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  Cannot store the form file "%3" on the device because it specifies a Keypad or 
//  Keyboard.
//  %n%nSuch forms may be displayed on the device, but may not be stored on
//  the device.%n
//  %nAction - Remove the Keypad and/or Keyboard from the form, or change the 
//  application to not store this form on the device.%n
//
#define OPOS_IVICMFORM_STORE_KEYPAD_KEYBOARD_FORM ((DWORD)0xC0112A96L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
//	Parameter 3 - bitmap file cannot load
// Parameter 4 - form file (.icf) being processed
//
// Data: None.
//
//
// MessageId: OPOS_IVICMFORM_LOAD_BITMAP
//
// MessageText:
//
//  Failed to load bitmap resource file.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  Could not load the Bitmap file "%3" which is specified within the form
//  file "%4".
//  %n%nAction - Ensure the bitmap file exists. Ensure the bitmap file exists
//  in the location specified within the form file. If the filename specified
//  for the bitmap file is not fully qualified (drive:\fullpath\filename), ensure
//  the bitmap file is located in specified relative location from the form
//  file's location. Ensure proper security permissions exist for the bitmap file and directory.%n
//
#define OPOS_IVICMFORM_LOAD_BITMAP       ((DWORD)0xC0112A97L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - form file (.icf) being stored
//					
// Data: None.
//
//
// MessageId: OPOS_IVICMFORM_INVALID_FORM_NUMBER1
//
// MessageText:
//
//  Invalid form number for this form file.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  Invalid form number specified for the form file "%3".
//  %n%nA form file that contains
//  a survey box and/or bitmap cannot have a form number less than or equal to zero.%n
//  %nAction - Specify a valid form number.%n
//
#define OPOS_IVICMFORM_INVALID_FORM_NUMBER1 ((DWORD)0xC0112A98L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - form file (.icf) being processed
//					
// Data: None.
//
//
// MessageId: OPOS_IVICMFORM_INVALID_FORM_FILE1
//
// MessageText:
//
//  Invalid form file. No content.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  Invalid form file "%3".
//  %n%nNo content found. Content consists of bitmaps, buttons,
//  survey boxes, script boxes, signature boxes, and text.%n
//  %nAction - Specify a valid form file.%n
//
#define OPOS_IVICMFORM_INVALID_FORM_FILE1 ((DWORD)0xC0112A99L)

// Parameter 1 - Service Object Description.
// Parameter 2 - Profile Name.
// Parameter 3 - form file (.out) being stored
//					
// Data: None.
//
//
// MessageId: OPOS_IVICMFORM_FAIL_DISPLAY_FORM_FILE
//
// MessageText:
//
//  Failed to display form file on device.%n
//  %nMeaning -%n
//  %1, Profile: %2, FSMID: %2%n 
//  Failed to display form %3 on device.
//  %n%nA failure occurred during
//  transmission of the file to hardware device.%n
//  %nAction - Ensure the device is operational. The retry the StoreFormOnDevice
//  or Interactive CheckHealth attempt. Contact your NCR OPOS service representative
//  for more information.%n
//
#define OPOS_IVICMFORM_FAIL_DISPLAY_FORM_FILE ((DWORD)0xC00B2A9AL)

// ---------------------------------------------------------------------------------
// NCR Wedge Driver Class
// Source: 
// MessageId Range Wedge Driver: 10950 - 10999
// ---------------------------------------------------------------------------------
// Parameter 1 - None.
// Parameter 2 - None.
//               
//					
// Data: None.
//
//
// MessageId: NCRWEDGE_MSG_DRIVER_LOADED
//
// MessageText:
//
//  NCR Wedge driver (NCRWedge.sys) was loaded successfully.
//
#define NCRWEDGE_MSG_DRIVER_LOADED       ((DWORD)0x40012AC6L)

// Parameter 1 - None.
// Parameter 2 - None.
//               
//					
// Data: LED flag
//
//
// MessageId: NCRWEDGE_MSG_SUSPEND_SET_INDICATOR
//
// MessageText:
//
//  Set Indicator command to the keyboard was suspended.
//
#define NCRWEDGE_MSG_SUSPEND_SET_INDICATOR ((DWORD)0x400F2AC7L)

// Parameter 1 - None.
// Parameter 2 - None.
//               
//					
// Data: Wedge Device ID
//
//
// MessageId: NCRWEDGE_MSG_GENERATE_NUMLOCK
//
// MessageText:
//
//  NumLock scan code was automatically generated for consistency.
//
#define NCRWEDGE_MSG_GENERATE_NUMLOCK    ((DWORD)0x400F2AC8L)

// Parameter 1 - None.
// Parameter 2 - None.
//               
//					
// Data: Wedge Device ID
//
//
// MessageId: NCRWEDGE_MSG_REMOVE_NUMLOCK
//
// MessageText:
//
//  NumLock scan code was delivered but automatically removed.
//
#define NCRWEDGE_MSG_REMOVE_NUMLOCK      ((DWORD)0x400F2AC9L)

// Parameter 1 - None.
// Parameter 2 - None.
//               
//					
// Data: Wedge Device ID
//
//
// MessageId: NCRWEDGE_MSG_DETECT_NUMLOCK
//
// MessageText:
//
//  NumLock scan code was detected in wedge data stream.
//
#define NCRWEDGE_MSG_DETECT_NUMLOCK      ((DWORD)0x800F2ACAL)

// Parameter 1 - None.
// Parameter 2 - None.
//               
//					
// Data: Make Code of unknown wedge sentinel ID
//
//
// MessageId: NCRWEDGE_MSG_UNKNOWN_WEDGE_ID
//
// MessageText:
//
//  Unknown wedge sentinel ID was received.
//
#define NCRWEDGE_MSG_UNKNOWN_WEDGE_ID    ((DWORD)0x800F2ACBL)

// Parameter 1 - None.
// Parameter 2 - None.
//               
//					
// Data: Wedge Device ID and Data Counts
//
//
// MessageId: NCRWEDGE_MSG_WEDGE_TIMEOUT
//
// MessageText:
//
//  Portion of the wedge data was discarded due to timeout.
//
#define NCRWEDGE_MSG_WEDGE_TIMEOUT       ((DWORD)0xC00F2ACCL)

// ---------------------------------------------------------------------------------
// NCR Wedge Keyboard Filter Class
// Source: 
// MessageId Range Wedge KBD Filter: 11000 - 11049
// ---------------------------------------------------------------------------------
// Parameter 1 - None.
// Parameter 2 - None.
//               
//					
// Data: None.
//
//
// MessageId: EVENT_MSG_FILTER_LOADED
//
// MessageText:
//
//  NCR Wedge Keyboard Filter (NCRWedgeKBDFilter.dll) was loaded successfully.
//
#define EVENT_MSG_FILTER_LOADED          ((DWORD)0x40012AF8L)

// Parameter 1 - Virtual Key Code
// Parameter 2 - None.
//               
//					
// Data: None.
//
//
// MessageId: EVENT_MSG_KEY_BEING_PRESSED
//
// MessageText:
//
//  The virtual key (%1) is in a state where it is being pressed. Attempt to reset the state.
//
#define EVENT_MSG_KEY_BEING_PRESSED      ((DWORD)0x800F2AF9L)

// Parameter 1 - Virtual Key Code
// Parameter 2 - None.
//               
//					
// Data: None.
//
//
// MessageId: EVENT_MSG_TOGGLE_STATE_MISMATCH
//
// MessageText:
//
//  Toggle state of the virtual key (%1) is out of order.  Attempt to put it back to original state.
//
#define EVENT_MSG_TOGGLE_STATE_MISMATCH  ((DWORD)0x800F2AFAL)

// Parameter 1 - None.
// Parameter 2 - None.
//               
//					
// Data: Wedge Data
//
//
// MessageId: EVENT_MSG_INVALID_WEDGE_DATA
//
// MessageText:
//
//  Invalid scan code in the wedge data stream was found. It will be ignored.
//
#define EVENT_MSG_INVALID_WEDGE_DATA     ((DWORD)0x800F2AFBL)

// Parameter 1 - None.
// Parameter 2 - None.
//               
//					
// Data: None.
//
//
// MessageId: EVENT_MSG_CRITICAL_ERROR
//
// MessageText:
//
//  Critical error.
//
#define EVENT_MSG_CRITICAL_ERROR         ((DWORD)0xC00F2AFCL)

// Parameter 1 - None.
// Parameter 2 - None.
//               
//					
// Data: Wedge Data.
//
//
// MessageId: EVENT_MSG_CANNOT_PARSE_DATA
//
// MessageText:
//
//  The wedge data cannot be parsed due to invalid scan code.
//
#define EVENT_MSG_CANNOT_PARSE_DATA      ((DWORD)0xC00F2AFDL)

// ---------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------
// ----------------------- END OF NCROPOSMSG.MC ------------------------------------
// ---------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------