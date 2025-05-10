#ifndef OPOSCARDREADER_H
#define OPOSCARDREADER_H

#include <fstream>
#include <string>
#include <objbase.h>

// Opos.h uses LONG and doesnt't define it?
#define LONG long

const LONG TIMEOUT = 1000;

// Their header files don't define the interface, so I tried defining it myself
// I'm quite certain this is wrong, but didn't know how to do it
// (I set a random uuid, idk where I should get it from)
class __declspec(uuid("00000000-894b-0000-c000-ad4831868740")) IOPOSMSR {
public:
    virtual LONG Open(BSTR DeviceName);
    virtual LONG Close();
    virtual LONG Claim(LONG timeout);
    virtual LONG Release();

    virtual void SetDeviceEnabled(bool);
    virtual void SetDataEventEnabled(bool);
    virtual LONG GetDataCount();
    virtual BSTR GetRawData();
};


class OposCardReader {
public:
    OposCardReader();
    ~OposCardReader();

    void open();
    void close();

    BSTR read();
private:
    bool open_;
    IOPOSMSR* device;
};


const bool hasEnv(const char* tag) noexcept;

void logMessage(std::string message);

#endif /* OPOSCARDREADER_H */


