
// OposCardTestDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "OposCardTest.h"
#include "OposCardTestDlg.h"
#include "afxdialogex.h"

#import "C:\\Program Files\\NCR\\OPOS\\OPOSMSR.ocx" rename_namespace("OPOSMSR")

#pragma comment(lib, "Ole32.lib")  // Link with OLE32 library

IOPOSMSR* m_device;


const LONG TIMEOUT = 1000;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;
#define		MY_DEBUG_LOG

std::string MyGetCurrentTime() {
	time_t now = time(0);
	tm* localtm = localtime(&now);
	char timeStr[100];
	strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", localtm);
	return std::string(timeStr);
}

void MyWriteLog(const char* format, ...)
{
#ifdef MY_DEBUG_LOG
	FILE* w_pFile = NULL;

	w_pFile = fopen("myOPOSLog.txt", "ab");

	if (w_pFile) {
		char LogData[1024] = "";
		char buffer[1024] = "";
		va_list args;
		va_start(args, format);
		vsnprintf(buffer, sizeof(buffer), format, args);
		va_end(args);

		std::string w_sTime = MyGetCurrentTime();
		sprintf(LogData, "%s - %s\n", w_sTime.c_str(), buffer);

		fwrite(LogData, strlen(LogData), 1, w_pFile);
	}

	fclose(w_pFile);

#endif
	return;
}
// Function to convert CLSID to std::string
std::string CLSIDToString(const CLSID& clsid) {
	// Convert CLSID to string (LPOLESTR)
	LPOLESTR clsidString = nullptr;
	HRESULT hr = StringFromCLSID(clsid, &clsidString);

	if (FAILED(hr)) {
	}

	// Convert LPOLESTR (wide string) to std::string
	std::wstring ws(clsidString);
	std::string result(ws.begin(), ws.end());

	// Free the allocated string
	CoTaskMemFree(clsidString);

	return result;
}


// CAboutDlg dialog used for App About
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// COposCardTestDlg dialog



COposCardTestDlg::COposCardTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OPOSCARDTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bInit = FALSE;
	m_bOpen = FALSE;
	m_device = NULL;
}

void COposCardTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(COposCardTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &COposCardTestDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON_GET_DATA, &COposCardTestDlg::OnBnClickedButtonGetData)
	ON_BN_CLICKED(IDC_BUTTON_OPEN, &COposCardTestDlg::OnBnClickedButtonOpen)
	ON_BN_CLICKED(IDC_BUTTON_INIT, &COposCardTestDlg::OnBnClickedButtonInit)
END_MESSAGE_MAP()


// COposCardTestDlg message handlers

BOOL COposCardTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon


	MyWriteLog("Program Starting .... ");


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void COposCardTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void COposCardTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR COposCardTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void COposCardTestDlg::OnBnClickedCancel()
{
	m_bInit = FALSE;
	m_bOpen = FALSE;


	m_device->Release();
	m_device->Close();

	// Cleanup COM before exiting
	CoUninitialize();

	MyWriteLog("Program End .... ");
	EndDialog(IDCANCEL);
}


void COposCardTestDlg::OnBnClickedButtonGetData()
{






}


void COposCardTestDlg::OnBnClickedButtonOpen()
{
	HRESULT			w_hr;

	if (m_bInit == FALSE) {
		MessageBoxA(NULL, "Please click Init button", "Test", MB_OK | MB_TOPMOST);
		goto L_EXIT;
	}

	try {
		if ((w_hr = m_device->Open(L"OPOSMSR")) != OPOS_SUCCESS) {
			MyWriteLog("Faild ...  OnBnClickedButtonOpen() m_device->Open");
			goto L_EXIT;
		}

		if ((w_hr = m_device->Claim(TIMEOUT)) != OPOS_SUCCESS) {
			MyWriteLog("Faild ...  OnBnClickedButtonOpen() m_device->Claim");
			goto L_EXIT;
		}

		m_device->SetDeviceEnabled(true);
		m_device->SetDataEventEnabled(true);

	}
	catch (_com_error& e) {
		MyWriteLog("Faild ...  OnBnClickedButtonOpen() try catch");
	}

	//. OK
	MessageBoxA(NULL, "OK ... Open", "Test", MB_OK | MB_TOPMOST);
	m_bOpen = TRUE;
	MyWriteLog("OK ...  OnBnClickedButtonOpen()");


L_EXIT:
	return;
}


void COposCardTestDlg::OnBnClickedButtonInit()
{
	CLSID				clsid;
	IOPOSMSR*			msrCtrl = nullptr;
	IID					w_iid;

	HRESULT hr = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
	if (FAILED(hr)) {
		MyWriteLog("Faild ...  OnBnClickedButtonInit() CoInitialize");
		goto L_EXIT;
	}

	// Creating instance
	hr = CLSIDFromProgID(L"OPOS.MSR", &clsid);
	if (FAILED(hr)) {
		MyWriteLog("Faild ...  OnBnClickedButtonInit() CLSIDFromProgID OPOS.MSR");
		CoUninitialize();
		goto L_EXIT;
	}
	else {
		string	w_sCLSID = CLSIDToString(clsid);
		MyWriteLog(w_sCLSID.c_str());
	}

	// IID for the desired interface
	w_iid = __uuidof(IOPOSMSR);
	// Create the COM instance
	hr = CoCreateInstance(clsid, nullptr, CLSCTX_INPROC_SERVER, w_iid, (void**)&msrCtrl);
	if (msrCtrl == nullptr) {
		MyWriteLog("Faild ...  OnBnClickedButtonInit() CoCreateInstance msrCtrl == nullptr");
		CoUninitialize();
		goto L_EXIT;
	}

	//. OK
	m_device = msrCtrl;
	MessageBoxA(NULL, "OK ... Init", "Test", MB_OK | MB_TOPMOST);
	m_bInit = TRUE;
	MyWriteLog("OK ...  OnBnClickedButtonInit()");

L_EXIT:
	return;
}
