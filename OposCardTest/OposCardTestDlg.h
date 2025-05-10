
// OposCardTestDlg.h : header file
//

#pragma once

#include <objbase.h>
#include <combaseapi.h> // For StringFromCLSID
#include <tchar.h>
#include <iostream>
#include <windows.h>
#include <comdef.h>
#include "Opos.h"         // Include OPOS header files (ensure these are available)
#include "OposMSR.h"      // Header for OPOS MSR interface

//
//class __declspec(uuid("00000000-894b-0000-c000-ad4831868740")) IOPOSMSR {
//public:
//	virtual LONG Open(BSTR DeviceName);
//	virtual LONG Close();
//	virtual LONG Claim(LONG timeout);
//	virtual LONG Release();
//
//	virtual void SetDeviceEnabled(bool);
//	virtual void SetDataEventEnabled(bool);
//	virtual LONG GetDataCount();
//	virtual BSTR GetRawData();
//};

// COposCardTestDlg dialog
class COposCardTestDlg : public CDialogEx
{
// Construction
public:
	COposCardTestDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OPOSCARDTEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButtonGetData();
	afx_msg void OnBnClickedButtonOpen();
	afx_msg void OnBnClickedButtonInit();


	BOOL			m_bInit;
	BOOL			m_bOpen;


};
