/////////////////////////////////////////////////////////////////////
//
// OposScan.h
//
//   Scanner header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 95-12-08 OPOS Release 1.0                                     CRM
// 97-06-04 OPOS Release 1.2                                     CRM
//   Add "ScanDataType" values.
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSSCAN_H)
#define      OPOSSCAN_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// "ScanDataType" Property Constants
/////////////////////////////////////////////////////////////////////

// One dimensional symbologies
const LONG SCAN_SDT_UPCA        = 101;  // Digits
const LONG SCAN_SDT_UPCE        = 102;  // Digits
const LONG SCAN_SDT_JAN8        = 103;  // = EAN 8
const LONG SCAN_SDT_EAN8        = 103;  // = JAN 8 (added in 1.2)
const LONG SCAN_SDT_JAN13       = 104;  // = EAN 13
const LONG SCAN_SDT_EAN13       = 104;  // = JAN 13 (added in 1.2)
const LONG SCAN_SDT_TF          = 105;  // (Discrete 2 of 5) Digits
const LONG SCAN_SDT_ITF         = 106;  // (Interleaved 2 of 5) Digits
const LONG SCAN_SDT_Codabar     = 107;  // Digits, -, $, :, /, ., +;
                                        //   4 start/stop characters
                                        //   (a, b, c, d)
const LONG SCAN_SDT_Code39      = 108;  // Alpha, Digits, Space, -, .,
                                        //   $, /, +, %; start/stop (*)
                                        // Also has Full ASCII feature
const LONG SCAN_SDT_Code93      = 109;  // Same characters as Code 39
const LONG SCAN_SDT_Code128     = 110;  // 128 data characters

const LONG SCAN_SDT_UPCA_S      = 111;  // UPC-A with supplemental
                                        //   barcode
const LONG SCAN_SDT_UPCE_S      = 112;  // UPC-E with supplemental
                                        //   barcode
const LONG SCAN_SDT_UPCD1       = 113;  // UPC-D1
const LONG SCAN_SDT_UPCD2       = 114;  // UPC-D2
const LONG SCAN_SDT_UPCD3       = 115;  // UPC-D3
const LONG SCAN_SDT_UPCD4       = 116;  // UPC-D4
const LONG SCAN_SDT_UPCD5       = 117;  // UPC-D5
const LONG SCAN_SDT_EAN8_S      = 118;  // EAN 8 with supplemental
                                        //   barcode
const LONG SCAN_SDT_EAN13_S     = 119;  // EAN 13 with supplemental
                                        //   barcode
const LONG SCAN_SDT_EAN128      = 120;  // EAN 128
const LONG SCAN_SDT_OCRA        = 121;  // OCR "A"
const LONG SCAN_SDT_OCRB        = 122;  // OCR "B"

//  - One dimensional symbologies (added in 1.8)
const LONG SCAN_SDT_RSS14       = 131;  // Reduced Space Symbology - 14 digit GTIN
const LONG SCAN_SDT_RSS_EXPANDED= 132;  // RSS - 14 digit GTIN plus additional fields

// - One dimensional symbologies (added in 1.12)
const LONG SCAN_SDT_GS1DATABAR  = 131;  // GS1 DataBar Omnidirectional (normal or stacked)
const LONG SCAN_SDT_GS1DATABAR_E= 132;  // GS1 DataBar Expanded (normal or stacked)

// Two dimensional symbologies
const LONG SCAN_SDT_PDF417      = 201;
const LONG SCAN_SDT_MAXICODE    = 202;

// - Two dimensional symbologies (added in 1.11)
const LONG SCAN_SDT_DATAMATRIX  = 203;  // Data Matrix
const LONG SCAN_SDT_QRCODE      = 204;  // QR Code
const LONG SCAN_SDT_UQRCODE     = 205;  // Micro QR Code
const LONG SCAN_SDT_AZTEC       = 206;  // Aztec
const LONG SCAN_SDT_UPDF417     = 207;  // Micro PDF 417


// Special cases
const LONG SCAN_SDT_OTHER       = 501;  // Start of Scanner-Specific bar
                                        //   code symbologies
const LONG SCAN_SDT_UNKNOWN     =   0;  // Cannot determine the barcode
                                        //   symbology.


#endif                  // !defined(OPOSSCAN_H)
