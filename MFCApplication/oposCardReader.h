#ifndef __MY_OPOSCARDREADER_H
#define __MY_OPOSCARDREADER_H

#include <fstream>
#include <string>
#include <objbase.h>


class OposCardReader {
public:
    OposCardReader();
    ~OposCardReader();

    int     open();
    void    close();
    BSTR    read();


    BSTR    readTrack_1();
    BSTR    readTrack_2();
    BSTR    readTrack_3();

private:
    bool    m_bOpen;
    int     m_nStartTick;
};

void logMessage(std::string message);


#endif /* OPOSCARDREADER_H */


