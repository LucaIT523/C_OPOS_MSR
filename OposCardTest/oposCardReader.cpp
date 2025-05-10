#include "oposCardReader.h"
#include <ctime>
#include <Opos.h>
#include <OposMsr.h>

OposCardReader::OposCardReader(): open_(false) {
    logMessage("Initializing");
    HRESULT hr = CoInitialize(nullptr);
    if (FAILED(hr)) {
        logMessage("Failed to initialize COM, HRESULT: " + hr);
        exit(456);
    }

    /// Creating instance
    CLSID clsid;
    hr = CLSIDFromProgID(L"OPOS.MSR", &clsid);
    if (FAILED(hr)) {
        logMessage("Failed to get CLSID from ProgID, HRESULT: " + hr);
        exit(457);
    }

    logMessage("Initialized. Creating instance");
    // OPOS control object
    IOPOSMSR* msrCtrl = nullptr;

    // IID for the desired interface
    IID iid = __uuidof(IOPOSMSR);

    // Create the COM instance
    hr = CoCreateInstance(clsid, nullptr, CLSCTX_INPROC_SERVER, iid, (void**)&msrCtrl);
    this->device = msrCtrl;
    logMessage("Created");
}

OposCardReader::~OposCardReader() {
    this->close();

    // Cleanup COM before exiting
    CoUninitialize();
}

void OposCardReader::open() {
    // TODO Open(), Claim(), DeviceEnabled=true
    logMessage("Opening device");
    HRESULT hr;
    if((hr = this->device->Open(L"OPOSMSR")) != OPOS_SUCCESS){
        logMessage("Failed to open " + hr);
    }
    logMessage("Claiming device");
    if((hr = this->device->Claim(TIMEOUT)) != OPOS_SUCCESS){
        logMessage("Failed to claim " + hr);
    }
    logMessage("Setting properties");
    this->device->SetDeviceEnabled(true);
    this->device->SetDataEventEnabled(true);
}

BSTR OposCardReader::read() {
    if(!this->device->GetDataCount()) return nullptr;
    return this->device->GetRawData();
}

void OposCardReader::close() {
    // TODO DeviceEnabled=false, Release(), Close()
    this->device->SetDataEventEnabled(false);
    this->device->SetDeviceEnabled(false);
    this->device->Release();
    this->device->Close();
}


const bool hasEnv(const char* tag) noexcept {
  const char* ret = std::getenv(tag);
  return ret != nullptr;
}

void logMessage(std::string message){
    static const char* filename = "./opos_msr.log";

    if (!hasEnv("DEBUG_OPOS")) return;

    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);

    std::ofstream f(filename, std::fstream::in | std::fstream::out | std::fstream::app);
    f << '\n' << '[' << now->tm_mday << '/' << now->tm_mon +1 << '/' << now->tm_year + 1900 << " - " <<
                now->tm_hour << ':' << now->tm_min << ':' << now->tm_sec << ']';
    f << message << '\n';
}

