#include "oposCardReader.h"
#include <ctime>
#include <iostream>
#include <fstream>
#include <windows.h> // For GetTickCount
#include <comutil.h>
#include <tlhelp32.h>
#include <process.h> 

//. 
struct MyInfoStruct
{
	int			m_nTickCount;
	int			m_nPaamOpt; //. 
	int			m_nResultCode;

	char		m_sMsg[256 + 2];
	char		m_sTrackData_1[256 + 2];
	char		m_sTrackData_2[256 + 2];
	char		m_sTrackData_3[256 + 2];
};
// Helper function to get the directory of the executable
std::string GetExecutablePath()
{
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	std::string::size_type pos = std::string(buffer).find_last_of("\\/");
	return std::string(buffer).substr(0, pos);
}
bool FileExists(LPCSTR filePath) {
	DWORD fileAttributes = GetFileAttributesA(filePath);
	if (fileAttributes == INVALID_FILE_ATTRIBUTES) {
		return false; // File does not exist or an error occurred
	}
	return true; // File exists
}
MyInfoStruct	GetDataFromFile(std::string& p_sFilePath)
{
	MyInfoStruct readData;
	memset(&readData, 0x00, sizeof(MyInfoStruct));
	readData.m_nResultCode = -99;

	if (FileExists(p_sFilePath.c_str()) == false) {
		return readData;
	}

	std::ifstream inFile(p_sFilePath, std::ios::binary);
	if (inFile.is_open())
	{
		inFile.read(reinterpret_cast<char*>(&readData), sizeof(readData));
		inFile.close();
	}

	std::string		w_sTemp = readData.m_sMsg;
	w_sTemp = w_sTemp.substr(2);
	strcpy_s(readData.m_sMsg, w_sTemp.c_str());

	w_sTemp = readData.m_sTrackData_1;
	w_sTemp = w_sTemp.substr(2);
	strcpy_s(readData.m_sTrackData_1, w_sTemp.c_str());

	w_sTemp = readData.m_sTrackData_2;
	w_sTemp = w_sTemp.substr(2);
	strcpy_s(readData.m_sTrackData_2, w_sTemp.c_str());

	w_sTemp = readData.m_sTrackData_3;
	w_sTemp = w_sTemp.substr(2);
	strcpy_s(readData.m_sTrackData_3, w_sTemp.c_str());

	return readData;
}
BSTR ConvertCharToBSTR(const char* charStr)
{
	// Find the length of the char* string
	int strLength = MultiByteToWideChar(CP_ACP, 0, charStr, -1, NULL, 0);

	// Allocate memory for the wide string
	wchar_t* wideStr = new wchar_t[strLength];

	// Convert the char* string to wchar_t* (wide char string)
	MultiByteToWideChar(CP_ACP, 0, charStr, -1, wideStr, strLength);

	// Allocate a BSTR and assign the wide string to it
	BSTR bstrStr = SysAllocString(wideStr);

	// Free the wide char string after BSTR allocation
	delete[] wideStr;

	return bstrStr;
}

BSTR ConvertWCharToBSTR(const wchar_t* wideStr)
{
	// Allocate a BSTR and copy the wide string into it
	BSTR bstrStr = SysAllocString(wideStr);

	// Return the BSTR
	return bstrStr;
}


bool IsProcessRunning(const std::string& processName, DWORD& p_dwProcessID)
{
	// Create a snapshot of all processes in the system
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnapshot == INVALID_HANDLE_VALUE)
		return false;

	PROCESSENTRY32 processEntry;
	processEntry.dwSize = sizeof(PROCESSENTRY32);

	// Retrieve information about the first process
	if (!Process32First(hSnapshot, &processEntry))
	{
		CloseHandle(hSnapshot);
		return false;
	}

	// Loop through all processes in the snapshot
	do
	{
		// Compare the process name
		if (std::string(processEntry.szExeFile) == processName)
		{
			p_dwProcessID = processEntry.th32ProcessID;
			CloseHandle(hSnapshot);
			return true; // Found the process
		}
	} while (Process32Next(hSnapshot, &processEntry));

	CloseHandle(hSnapshot);
	return false; // Process not found
}
int _execute(const char* p_szEXE, const char* p_pszCommandParam, int	p_bWait /*= 1*/)
{
	SHELLEXECUTEINFOA ShExecInfo;
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = "open";
	ShExecInfo.lpFile = p_szEXE;
	ShExecInfo.lpParameters = p_pszCommandParam; //  L"/C apktool.bat -f d D:\\work\\_FCM\\test_org.apk -o D:\\work\\_FCM\\aaa";
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_HIDE; // SW_NORMAL

	if (ShellExecuteEx(&ShExecInfo)) {
		// Wait for the process to exit
		if (p_bWait == 1) {
			WaitForSingleObject(ShExecInfo.hProcess, INFINITE);
		}
		else {
			Sleep(1000);
		}
		DWORD dwCode = 0;
		GetExitCodeProcess(ShExecInfo.hProcess, &dwCode);
		return 0;
	}
	return 1;
}
bool KillProcessById(DWORD processId)
{
	HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, processId);
	if (hProcess == NULL)
	{
		return false;
	}
	if (!TerminateProcess(hProcess, 1))
	{
		CloseHandle(hProcess);
		return false;
	}
	CloseHandle(hProcess);
	return true;
}

OposCardReader::OposCardReader() 
{
	m_bOpen = false;
	m_nStartTick = 0;
}

OposCardReader::~OposCardReader() 
{
	close();
}

int OposCardReader::open()
{
	char			w_szParam[MAX_PATH] = "";
	MyInfoStruct	w_stData;
	int				w_nRtn = -99;
	DWORD			w_dwProcessID = 0;


	logMessage("OposCardReader::open()");
	//. delete 'oposmsr_ocx_data.bin' file
	std::string w_filePath = GetExecutablePath() + "\\oposmsr_ocx_data.bin";
	DeleteFileA(w_filePath.c_str());

	std::string w_EngOcxPath = GetExecutablePath() + "\\xoposmsr_eng.exe";
	std::string w_EngOcxName = "xoposmsr_eng.exe";
	//. check that engine is running 

	if (IsProcessRunning(w_EngOcxName, w_dwProcessID) == true) {
		logMessage("OposCardReader::open() IsProcessRunning(w_EngOcxName) == true");

		KillProcessById(w_dwProcessID);
		sprintf_s(w_szParam, "/C taskkill /IM %s /F", w_EngOcxName.c_str());
		_execute("cmd.exe", w_szParam, 0);
		Sleep(1000);

		logMessage("OposCardReader::open() KillProcessById End");
	}

	//. 
	logMessage("OposCardReader::open() IsProcessRunning(w_EngOcxName) == false");
	sprintf_s(w_szParam, "/C %s", w_EngOcxPath.c_str());
	_execute("cmd.exe", w_szParam, 0);

	Sleep(2000);

	logMessage("OposCardReader::open() _execute end");

	if (IsProcessRunning(w_EngOcxName, w_dwProcessID) == true) {
		logMessage("OposCardReader::open() _execute end IsProcessRunning(w_EngOcxName) == true");
		if (FileExists(w_filePath.c_str()) == true) {
			w_stData = GetDataFromFile(w_filePath);
			if (w_stData.m_nPaamOpt == 1 && w_stData.m_nResultCode != 0) {
				w_nRtn = w_stData.m_nResultCode;
				goto L_EXIT;
			}
		}
	}
	else {
		//. Faild
		logMessage("OposCardReader::open() Faild");
		if (FileExists(w_filePath.c_str()) == true) {
			w_stData = GetDataFromFile(w_filePath);
			if (w_stData.m_nPaamOpt == 1 && w_stData.m_nResultCode != 0) {
				w_nRtn = w_stData.m_nResultCode;
			}
		}
		goto L_EXIT;
	}

	//.ok
	logMessage("OposCardReader::open() OK");
	m_bOpen = true;
	m_nStartTick = (int)GetTickCount();
	w_nRtn = 0;

L_EXIT:
	return w_nRtn;
}

BSTR OposCardReader::read()
{
	return readTrack_1();
}

BSTR OposCardReader::readTrack_1()
{
	BSTR			w_sRtn = NULL;
	std::string		w_filePath = GetExecutablePath() + "\\oposmsr_ocx_data.bin";
	MyInfoStruct	w_stData;
	bool			w_bOK = false;

	//
	if (m_bOpen == false) {
		goto L_EXIT;
	}
	if (m_nStartTick == 0) {
		goto L_EXIT;
	}
	for (int i = 0; i < 2; i++) {
		w_stData = GetDataFromFile(w_filePath);
		if (w_stData.m_nPaamOpt == 2 && w_stData.m_nResultCode == 0) {
			w_bOK = true;
			break;
		}
		Sleep(250);
	}
	logMessage("OposCardReader::readTrack_1() engine");

	if (w_bOK == true) {
		logMessage("OposCardReader::readTrack_1() w_bOK == true");
		if (/*w_stData.m_nTickCount > m_nStartTick &&*/ strlen(w_stData.m_sTrackData_1) > 0) {
			w_sRtn = ConvertCharToBSTR(w_stData.m_sTrackData_1);
		}
	}

L_EXIT:
	logMessage("OposCardReader::readTrack_1() End");
	return w_sRtn;
}

BSTR OposCardReader::readTrack_2()
{
	BSTR			w_sRtn = NULL;
	std::string		w_filePath = GetExecutablePath() + "\\oposmsr_ocx_data.bin";
	MyInfoStruct	w_stData;
	bool			w_bOK = false;

	//
	if (m_bOpen == false) {
		goto L_EXIT;
	}
	if (m_nStartTick == 0) {
		goto L_EXIT;
	}
	for (int i = 0; i < 2; i++) {
		w_stData = GetDataFromFile(w_filePath);
		if (w_stData.m_nPaamOpt == 2 && w_stData.m_nResultCode == 0) {
			w_bOK = true;
			break;
		}
		Sleep(250);
	}
	logMessage("OposCardReader::readTrack_2() engine");

	if (w_bOK == true) {
		logMessage("OposCardReader::readTrack_2() w_bOK == true");
		if (/*w_stData.m_nTickCount > m_nStartTick &&*/ strlen(w_stData.m_sTrackData_2) > 0){
			w_sRtn = ConvertCharToBSTR(w_stData.m_sTrackData_2);
		}
	}

L_EXIT:
	logMessage("OposCardReader::readTrack_2() End");
	return w_sRtn;
}

BSTR OposCardReader::readTrack_3()
{
	BSTR			w_sRtn = NULL;
	std::string		w_filePath = GetExecutablePath() + "\\oposmsr_ocx_data.bin";
	MyInfoStruct	w_stData;
	bool			w_bOK = false;

	//
	if (m_bOpen == false) {
		goto L_EXIT;
	}
	if (m_nStartTick == 0) {
		goto L_EXIT;
	}
	for (int i = 0; i < 2; i++) {
		w_stData = GetDataFromFile(w_filePath);
		if (w_stData.m_nPaamOpt == 2 && w_stData.m_nResultCode == 0) {
			w_bOK = true;
			break;
		}
		Sleep(250);
	}
	logMessage("OposCardReader::readTrack_3() engine");

	if (w_bOK == true) {
		logMessage("OposCardReader::readTrack_3() w_bOK == true");
		if (/*w_stData.m_nTickCount > m_nStartTick &&*/ strlen(w_stData.m_sTrackData_3) > 0) {
			w_sRtn = ConvertCharToBSTR(w_stData.m_sTrackData_3);
		}
	}

L_EXIT:
	logMessage("OposCardReader::readTrack_3() End");
	return w_sRtn;
}

void OposCardReader::close() 
{
	DWORD			w_dwProcessID = 0;
	char			w_szParam[MAX_PATH] = "";

	std::string w_EngOcxName = "xoposmsr_eng.exe";

	if (IsProcessRunning(w_EngOcxName, w_dwProcessID) == true) {

		KillProcessById(w_dwProcessID);
		sprintf_s(w_szParam, "/C taskkill /IM %s /F", w_EngOcxName.c_str());
		_execute("cmd.exe", w_szParam, 0);
		Sleep(1000);
	}
	return;
}


//const bool hasEnv(const char* tag) noexcept {
//	const char* ret = std::getenv(tag);
//	return ret != nullptr;
//}

void logMessage(std::string message) {
	static const char* filename = "./opos_msr.log";

	std::time_t t = std::time(0);   // get time now
	std::tm* now = std::localtime(&t);

	std::ofstream f(filename, std::fstream::in | std::fstream::out | std::fstream::app);
	f << '\n' << '[' << now->tm_mday << '/' << now->tm_mon + 1 << '/' << now->tm_year + 1900 << " - " <<
		now->tm_hour << ':' << now->tm_min << ':' << now->tm_sec << ']';
	f << message << '\n';
}