/////////////////////////////////////////////////////////////////////
//
// OposFptr.h
//
//   Fiscal Printer header file for OPOS Applications.
//
// Modification history
// ------------------------------------------------------------------
// 98-03-06 OPOS Release 1.3                                     PDU
// 01-07-15 OPOS Release 1.6                                     TNN
//   Add values for all 1.6 added properties and method
//   parameters
// 04-03-22 OPOS Release 1.8                                     CRM
//   Add more values for StatusUpdateEvent.
//
/////////////////////////////////////////////////////////////////////

#if !defined(OPOSFPTR_H)
#define      OPOSFPTR_H


#include "Opos.h"


/////////////////////////////////////////////////////////////////////
// Fiscal Printer Station Constants
/////////////////////////////////////////////////////////////////////

const LONG FPTR_S_JOURNAL                   = 1;
const LONG FPTR_S_RECEIPT                   = 2;
const LONG FPTR_S_SLIP                      = 4;

const LONG FPTR_S_JOURNAL_RECEIPT           = 3;


/////////////////////////////////////////////////////////////////////
// "ActualCurrency" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG FPTR_AC_BRC                      =  1;
const LONG FPTR_AC_BGL                      =  2;
const LONG FPTR_AC_EUR                      =  3;
const LONG FPTR_AC_GRD                      =  4;
const LONG FPTR_AC_HUF                      =  5;
const LONG FPTR_AC_ITL                      =  6;
const LONG FPTR_AC_PLZ                      =  7;
const LONG FPTR_AC_ROL                      =  8;
const LONG FPTR_AC_RUR                      =  9;
const LONG FPTR_AC_TRL                      =  10;


/////////////////////////////////////////////////////////////////////
// "ContractorId" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG FPTR_CID_FIRST                   =  1;
const LONG FPTR_CID_SECOND                  =  2;
const LONG FPTR_CID_SINGLE                  =  3;


/////////////////////////////////////////////////////////////////////
// "CountryCode" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG FPTR_CC_BRAZIL                   =  1;
const LONG FPTR_CC_GREECE                   =  2;
const LONG FPTR_CC_HUNGARY                  =  4;
const LONG FPTR_CC_ITALY                    =  8;
const LONG FPTR_CC_POLAND                   =  16;
const LONG FPTR_CC_TURKEY                   =  32;
const LONG FPTR_CC_RUSSIA                   =  64;
const LONG FPTR_CC_BULGARIA                 =  128;
const LONG FPTR_CC_ROMANIA                  =  256;


/////////////////////////////////////////////////////////////////////
// "DateType" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG FPTR_DT_CONF                     =  1;
const LONG FPTR_DT_EOD                      =  2;
const LONG FPTR_DT_RESET                    =  3;
const LONG FPTR_DT_RTC                      =  4;
const LONG FPTR_DT_VAT                      =  5;


/////////////////////////////////////////////////////////////////////
// "ErrorLevel" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG FPTR_EL_NONE                     =  1;
const LONG FPTR_EL_RECOVERABLE              =  2;
const LONG FPTR_EL_FATAL                    =  3;
const LONG FPTR_EL_BLOCKED                  =  4;


/////////////////////////////////////////////////////////////////////
// "ErrorState", "PrinterState" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG FPTR_PS_MONITOR                  =  1;
const LONG FPTR_PS_FISCAL_RECEIPT           =  2;
const LONG FPTR_PS_FISCAL_RECEIPT_TOTAL     =  3;
const LONG FPTR_PS_FISCAL_RECEIPT_ENDING    =  4;
const LONG FPTR_PS_FISCAL_DOCUMENT          =  5;
const LONG FPTR_PS_FIXED_OUTPUT             =  6;
const LONG FPTR_PS_ITEM_LIST                =  7;
const LONG FPTR_PS_LOCKED                   =  8;
const LONG FPTR_PS_NONFISCAL                =  9;
const LONG FPTR_PS_REPORT                   = 10;


/////////////////////////////////////////////////////////////////////
// "FiscalReceiptStation" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG FPTR_RS_RECEIPT                  =  1;
const LONG FPTR_RS_SLIP                     =  2;


/////////////////////////////////////////////////////////////////////
// "FiscalReceiptType" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG FPTR_RT_CASH_IN                  =  1;
const LONG FPTR_RT_CASH_OUT                 =  2;
const LONG FPTR_RT_GENERIC                  =  3;
const LONG FPTR_RT_SALES                    =  4;
const LONG FPTR_RT_SERVICE                  =  5;
const LONG FPTR_RT_SIMPLE_INVOICE           =  6;


/////////////////////////////////////////////////////////////////////
// "MessageType" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG FPTR_MT_ADVANCE                  =  1;
const LONG FPTR_MT_ADVANCE_PAID             =  2;
const LONG FPTR_MT_AMOUNT_TO_BE_PAID        =  3;
const LONG FPTR_MT_AMOUNT_TO_BE_PAID_BACK   =  4;
const LONG FPTR_MT_CARD                     =  5;
const LONG FPTR_MT_CARD_NUMBER              =  6;
const LONG FPTR_MT_CARD_TYPE                =  7;
const LONG FPTR_MT_CASH                     =  8;
const LONG FPTR_MT_CASHIER                  =  9;
const LONG FPTR_MT_CASH_REGISTER_NUMBER     =  10;
const LONG FPTR_MT_CHANGE                   =  11;
const LONG FPTR_MT_CHEQUE                   =  12;
const LONG FPTR_MT_CLIENT_NUMBER            =  13;
const LONG FPTR_MT_CLIENT_SIGNATURE         =  14;
const LONG FPTR_MT_COUNTER_STATE            =  15;
const LONG FPTR_MT_CREDIT_CARD              =  16;
const LONG FPTR_MT_CURRENCY                 =  17;
const LONG FPTR_MT_CURRENCY_VALUE           =  18;
const LONG FPTR_MT_DEPOSIT                  =  19;
const LONG FPTR_MT_DEPOSIT_RETURNED         =  20;
const LONG FPTR_MT_DOT_LINE                 =  21;
const LONG FPTR_MT_DRIVER_NUMB              =  22;
const LONG FPTR_MT_EMPTY_LINE               =  23;
const LONG FPTR_MT_FREE_TEXT                =  24;
const LONG FPTR_MT_FREE_TEXT_WITH_DAY_LIMIT =  25;
const LONG FPTR_MT_GIVEN_DISCOUNT           =  26;
const LONG FPTR_MT_LOCAL_CREDIT             =  27;
const LONG FPTR_MT_MILEAGE_KM               =  28;
const LONG FPTR_MT_NOTE                     =  29;
const LONG FPTR_MT_PAID                     =  30;
const LONG FPTR_MT_PAY_IN                   =  31;
const LONG FPTR_MT_POINT_GRANTED            =  32;
const LONG FPTR_MT_POINTS_BONUS             =  33;
const LONG FPTR_MT_POINTS_RECEIPT           =  34;
const LONG FPTR_MT_POINTS_TOTAL             =  35;
const LONG FPTR_MT_PROFITED                 =  36;
const LONG FPTR_MT_RATE                     =  37;
const LONG FPTR_MT_REGISTER_NUMB            =  38;
const LONG FPTR_MT_SHIFT_NUMBER             =  39;
const LONG FPTR_MT_STATE_OF_AN_ACCOUNT      =  40;
const LONG FPTR_MT_SUBSCRIPTION             =  41;
const LONG FPTR_MT_TABLE                    =  42;
const LONG FPTR_MT_THANK_YOU_FOR_LOYALTY    =  43;
const LONG FPTR_MT_TRANSACTION_NUMB         =  44;
const LONG FPTR_MT_VALID_TO                 =  45;
const LONG FPTR_MT_VOUCHER                  =  46;
const LONG FPTR_MT_VOUCHER_PAID             =  47;
const LONG FPTR_MT_VOUCHER_VALUE            =  48;
const LONG FPTR_MT_WITH_DISCOUNT            =  49;
const LONG FPTR_MT_WITHOUT_UPLIFT           =  50;


/////////////////////////////////////////////////////////////////////
// "SlipSelection" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG FPTR_SS_FULL_LENGTH              =  1;
const LONG FPTR_SS_VALIDATION               =  2;


/////////////////////////////////////////////////////////////////////
// "TotalizerType" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG FPTR_TT_DOCUMENT                 =  1;
const LONG FPTR_TT_DAY                      =  2;
const LONG FPTR_TT_RECEIPT                  =  3;
const LONG FPTR_TT_GRAND                    =  4;


/////////////////////////////////////////////////////////////////////
// "GetData" Method Constants
/////////////////////////////////////////////////////////////////////

const LONG FPTR_GD_CURRENT_TOTAL            =  1;
const LONG FPTR_GD_DAILY_TOTAL              =  2;
const LONG FPTR_GD_RECEIPT_NUMBER           =  3;
const LONG FPTR_GD_REFUND                   =  4;
const LONG FPTR_GD_NOT_PAID                 =  5;
const LONG FPTR_GD_MID_VOID                 =  6;
const LONG FPTR_GD_Z_REPORT                 =  7;
const LONG FPTR_GD_GRAND_TOTAL              =  8;
const LONG FPTR_GD_PRINTER_ID               =  9;
const LONG FPTR_GD_FIRMWARE                 = 10;
const LONG FPTR_GD_RESTART                  = 11;
const LONG FPTR_GD_REFUND_VOID              = 12;
const LONG FPTR_GD_NUMB_CONFIG_BLOCK        = 13;
const LONG FPTR_GD_NUMB_CURRENCY_BLOCK      = 14;
const LONG FPTR_GD_NUMB_HDR_BLOCK           = 15;
const LONG FPTR_GD_NUMB_RESET_BLOCK         = 16;
const LONG FPTR_GD_NUMB_VAT_BLOCK           = 17;
const LONG FPTR_GD_FISCAL_DOC               = 18;
const LONG FPTR_GD_FISCAL_DOC_VOID          = 19;
const LONG FPTR_GD_FISCAL_REC               = 20;
const LONG FPTR_GD_FISCAL_REC_VOID          = 21;
const LONG FPTR_GD_NONFISCAL_DOC            = 22;
const LONG FPTR_GD_NONFISCAL_DOC_VOID       = 23;
const LONG FPTR_GD_NONFISCAL_REC            = 24;
const LONG FPTR_GD_SIMP_INVOICE             = 25;
const LONG FPTR_GD_TENDER                   = 26;
const LONG FPTR_GD_LINECOUNT                = 27;
const LONG FPTR_GD_DESCRIPTION_LENGTH       = 28;

const LONG FPTR_PDL_CASH                     =  1;
const LONG FPTR_PDL_CHEQUE                   =  2;
const LONG FPTR_PDL_CHITTY                   =  3;
const LONG FPTR_PDL_COUPON                   =  4;
const LONG FPTR_PDL_CURRENCY                 =  5;
const LONG FPTR_PDL_DRIVEN_OFF               =  6;
const LONG FPTR_PDL_EFT_IMPRINTER            =  7;
const LONG FPTR_PDL_EFT_TERMINAL             =  8;
const LONG FPTR_PDL_TERMINAL_IMPRINTER       =  9;
const LONG FPTR_PDL_FREE_GIFT                = 10;
const LONG FPTR_PDL_GIRO                     = 11;
const LONG FPTR_PDL_HOME                     = 12;
const LONG FPTR_PDL_IMPRINTER_WITH_ISSUER    = 13;
const LONG FPTR_PDL_LOCAL_ACCOUNT            = 14;
const LONG FPTR_PDL_LOCAL_ACCOUNT_CARD       = 15;
const LONG FPTR_PDL_PAY_CARD                 = 16;
const LONG FPTR_PDL_PAY_CARD_MANUAL          = 17;
const LONG FPTR_PDL_PREPAY                   = 18;
const LONG FPTR_PDL_PUMP_TEST                = 19;
const LONG FPTR_PDL_SHORT_CREDIT             = 20;
const LONG FPTR_PDL_STAFF                    = 21;
const LONG FPTR_PDL_VOUCHER                  = 22;

const LONG FPTR_LC_ITEM                      =  1;
const LONG FPTR_LC_ITEM_VOID                 =  2;
const LONG FPTR_LC_DISCOUNT                  =  3;
const LONG FPTR_LC_DISCOUNT_VOID             =  4;
const LONG FPTR_LC_SURCHARGE                 =  5;
const LONG FPTR_LC_SURCHARGE_VOID            =  6;
const LONG FPTR_LC_REFUND                    =  7;
const LONG FPTR_LC_REFUND_VOID               =  8;
const LONG FPTR_LC_SUBTOTAL_DISCOUNT         =  9;
const LONG FPTR_LC_SUBTOTAL_DISCOUNT_VOID    = 10;
const LONG FPTR_LC_SUBTOTAL_SURCHARGE        = 11;
const LONG FPTR_LC_SUBTOTAL_SURCHARGE_VOID   = 12;
const LONG FPTR_LC_COMMENT                   = 13;
const LONG FPTR_LC_SUBTOTAL                  = 14;
const LONG FPTR_LC_TOTAL                     = 15;

const LONG FPTR_DL_ITEM                      =  1;
const LONG FPTR_DL_ITEM_ADJUSTMENT           =  2;
const LONG FPTR_DL_ITEM_FUEL                 =  3;
const LONG FPTR_DL_ITEM_FUEL_VOID            =  4;
const LONG FPTR_DL_NOT_PAID                  =  5;
const LONG FPTR_DL_PACKAGE_ADJUSTMENT        =  6;
const LONG FPTR_DL_REFUND                    =  7;
const LONG FPTR_DL_REFUND_VOID               =  8;
const LONG FPTR_DL_SUBTOTAL_ADJUSTMENT       =  9;
const LONG FPTR_DL_TOTAL                     = 10;
const LONG FPTR_DL_VOID                      = 11;
const LONG FPTR_DL_VOID_ITEM                 = 12;


/////////////////////////////////////////////////////////////////////
// "GetTotalizer" Method Constants
/////////////////////////////////////////////////////////////////////

const LONG FPTR_GT_GROSS                    =  1;
const LONG FPTR_GT_NET                      =  2;
const LONG FPTR_GT_DISCOUNT                 =  3;
const LONG FPTR_GT_DISCOUNT_VOID            =  4;
const LONG FPTR_GT_ITEM                     =  5;
const LONG FPTR_GT_ITEM_VOID                =  6;
const LONG FPTR_GT_NOT_PAID                 =  7;
const LONG FPTR_GT_REFUND                   =  8;
const LONG FPTR_GT_REFUND_VOID              =  9;
const LONG FPTR_GT_SUBTOTAL_DISCOUNT        =  10;
const LONG FPTR_GT_SUBTOTAL_DISCOUNT_VOID   =  11;
const LONG FPTR_GT_SUBTOTAL_SURCHARGES      =  12;
const LONG FPTR_GT_SUBTOTAL_SURCHARGES_VOID =  13;
const LONG FPTR_GT_SURCHARGE                =  14;
const LONG FPTR_GT_SURCHARGE_VOID           =  15;
const LONG FPTR_GT_VAT                      =  16;
const LONG FPTR_GT_VAT_CATEGORY             =  17;


/////////////////////////////////////////////////////////////////////
// "AdjustmentType" arguments in diverse methods
/////////////////////////////////////////////////////////////////////

const LONG FPTR_AT_AMOUNT_DISCOUNT          =  1;
const LONG FPTR_AT_AMOUNT_SURCHARGE         =  2;
const LONG FPTR_AT_PERCENTAGE_DISCOUNT      =  3;
const LONG FPTR_AT_PERCENTAGE_SURCHARGE     =  4;


/////////////////////////////////////////////////////////////////////
// "ReportType" argument in "PrintReport" method
/////////////////////////////////////////////////////////////////////

const LONG FPTR_RT_ORDINAL                  =  1;
const LONG FPTR_RT_DATE                     =  2;


/////////////////////////////////////////////////////////////////////
// "NewCurrency" argument in "SetCurrency" method
/////////////////////////////////////////////////////////////////////

const LONG FPTR_SC_EURO                     =  1;


/////////////////////////////////////////////////////////////////////
// "StatusUpdateEvent" Event: "Data" Parameter Constants
/////////////////////////////////////////////////////////////////////

const LONG FPTR_SUE_COVER_OPEN              =  11;
const LONG FPTR_SUE_COVER_OK                =  12;
const LONG FPTR_SUE_JRN_COVER_OPEN          =  60;  // (added in 1.8)
const LONG FPTR_SUE_JRN_COVER_OK            =  61;  // (added in 1.8)
const LONG FPTR_SUE_REC_COVER_OPEN          =  62;  // (added in 1.8)
const LONG FPTR_SUE_REC_COVER_OK            =  63;  // (added in 1.8)
const LONG FPTR_SUE_SLP_COVER_OPEN          =  64;  // (added in 1.8)
const LONG FPTR_SUE_SLP_COVER_OK            =  65;  // (added in 1.8)

const LONG FPTR_SUE_JRN_EMPTY               =  21;
const LONG FPTR_SUE_JRN_NEAREMPTY           =  22;
const LONG FPTR_SUE_JRN_PAPEROK             =  23;

const LONG FPTR_SUE_REC_EMPTY               =  24;
const LONG FPTR_SUE_REC_NEAREMPTY           =  25;
const LONG FPTR_SUE_REC_PAPEROK             =  26;

const LONG FPTR_SUE_SLP_EMPTY               =  27;
const LONG FPTR_SUE_SLP_NEAREMPTY           =  28;
const LONG FPTR_SUE_SLP_PAPEROK             =  29;

const LONG FPTR_SUE_IDLE                    =1001;


/////////////////////////////////////////////////////////////////////
// "ResultCodeExtended" Property Constants
/////////////////////////////////////////////////////////////////////

const LONG OPOS_EFPTR_COVER_OPEN                 = 201; // (Several)
const LONG OPOS_EFPTR_JRN_EMPTY                  = 202; // (Several)
const LONG OPOS_EFPTR_REC_EMPTY                  = 203; // (Several)
const LONG OPOS_EFPTR_SLP_EMPTY                  = 204; // (Several)
const LONG OPOS_EFPTR_SLP_FORM                   = 205; // EndRemoval
const LONG OPOS_EFPTR_MISSING_DEVICES            = 206; // (Several)
const LONG OPOS_EFPTR_WRONG_STATE                = 207; // (Several)
const LONG OPOS_EFPTR_TECHNICAL_ASSISTANCE       = 208; // (Several)
const LONG OPOS_EFPTR_CLOCK_ERROR                = 209; // (Several)
const LONG OPOS_EFPTR_FISCAL_MEMORY_FULL         = 210; // (Several)
const LONG OPOS_EFPTR_FISCAL_MEMORY_DISCONNECTED = 211; // (Several)
const LONG OPOS_EFPTR_FISCAL_TOTALS_ERROR        = 212; // (Several)
const LONG OPOS_EFPTR_BAD_ITEM_QUANTITY          = 213; // (Several)
const LONG OPOS_EFPTR_BAD_ITEM_AMOUNT            = 214; // (Several)
const LONG OPOS_EFPTR_BAD_ITEM_DESCRIPTION       = 215; // (Several)
const LONG OPOS_EFPTR_RECEIPT_TOTAL_OVERFLOW     = 216; // (Several)
const LONG OPOS_EFPTR_BAD_VAT                    = 217; // (Several)
const LONG OPOS_EFPTR_BAD_PRICE                  = 218; // (Several)
const LONG OPOS_EFPTR_BAD_DATE                   = 219; // (Several)
const LONG OPOS_EFPTR_NEGATIVE_TOTAL             = 220; // (Several)
const LONG OPOS_EFPTR_WORD_NOT_ALLOWED           = 221; // (Several)
const LONG OPOS_EFPTR_BAD_LENGTH                 = 222; // (Several)
const LONG OPOS_EFPTR_MISSING_SET_CURRENCY       = 223; // (Several)


#endif                  // !defined(OPOSFPTR_H)
