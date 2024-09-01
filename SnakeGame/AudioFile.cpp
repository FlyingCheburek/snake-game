#pragma comment(lib, "Winmm.lib")
#pragma warning(disable : 4996)
#include "WindowsServices.h"
#include <stdio.h>
#include <cwchar>

const wchar_t* WindowsServices::AudioFile::GetWC(const char* c){
    const size_t cSize = strlen(c) + 1;
    wchar_t* wc = new wchar_t[cSize];
    std::mbstowcs(wc, c, cSize);
    return wc;
}

WindowsServices::AudioFile::AudioFile(const std::string&& filename, const std::string&& type) : filename(filename) {
    std::string command = "open \"" + filename + "\" " + type;
    const wchar_t* _a = GetWC(command.c_str());
    mciSendString(_a, NULL, 0, NULL);
    delete _a;
}

void WindowsServices::AudioFile::play(bool wait){
    std::string b = "play " + filename;
    b += wait ? " wait" : "";
    const wchar_t* _b = GetWC(b.c_str());
    mciSendString(_b, NULL, 0, NULL);
    delete _b;
}

void WindowsServices::AudioFile::replay(bool wait){
    std::string b = "play " + filename + " from 0";
    b += wait ? " wait" : "";
    const wchar_t* _b = GetWC(b.c_str());
    mciSendString(_b, NULL, 0, NULL);
    delete _b;
}

void WindowsServices::AudioFile::loop(){
    std::string b = "play " + filename + " repeat";
    const wchar_t* _b = GetWC(b.c_str());
    mciSendString(_b, NULL, 0, NULL);
    delete _b;
}

void WindowsServices::AudioFile::pause(){
    std::string b = "pause " + filename;
    const wchar_t* _b = GetWC(b.c_str());
    mciSendString(_b, NULL, 0, NULL);
    delete _b;
}

void WindowsServices::AudioFile::resume(){
    std::string b = "resume " + filename;
    const wchar_t* _b = GetWC(b.c_str());
    mciSendString(_b, NULL, 0, NULL);
    delete _b;
}

void WindowsServices::AudioFile::forceStop(){
    std::string b = "stop " + filename;
    const wchar_t* _b = GetWC(b.c_str());
    mciSendString(_b, NULL, 0, NULL);
    delete _b;
}

WindowsServices::AudioFile::~AudioFile(){
    std::string b = "close " + filename;
    const wchar_t* _b = GetWC(b.c_str());
    mciSendString(_b, NULL, 0, NULL);
    delete _b;
}
