#pragma comment(lib, "Winmm.lib")
#pragma warning(disable : 4996)
#include <stdio.h>
#include <cwchar>
#include "WindowsServices.h"
using namespace WindowsServices;

const wchar_t* AudioFile::getWC(const char* c) noexcept{
    const size_t cSize = strlen(c) + 1;
    wchar_t* wc = new wchar_t[cSize];
    std::mbstowcs(wc, c, cSize);
    return wc;
}

AudioFile::AudioFile(const std::string&& filename, const std::string&& type) noexcept : filename(filename) {
    std::string command = "open \"" + filename + "\" " + type;
    const wchar_t* _a = getWC(command.c_str());
    mciSendString(_a, NULL, 0, NULL);
    delete _a;
}

void AudioFile::play(const bool&& wait) const noexcept{
    std::string b = "play " + filename;
    b += wait ? " wait" : "";
    const wchar_t* _b = getWC(b.c_str());
    mciSendString(_b, NULL, 0, NULL);
    delete _b;
}

void AudioFile::replay(const bool&& wait) const noexcept {
    std::string b = "play " + filename + " from 0";
    b += wait ? " wait" : "";
    const wchar_t* _b = getWC(b.c_str());
    mciSendString(_b, NULL, 0, NULL);
    delete _b;
}

void AudioFile::loop() const noexcept {
    std::string b = "play " + filename + " repeat";
    const wchar_t* _b = getWC(b.c_str());
    mciSendString(_b, NULL, 0, NULL);
    delete _b;
}

void AudioFile::pause() const noexcept {
    std::string b = "pause " + filename;
    const wchar_t* _b = getWC(b.c_str());
    mciSendString(_b, NULL, 0, NULL);
    delete _b;
}

void AudioFile::resume() const noexcept {
    std::string b = "resume " + filename;
    const wchar_t* _b = getWC(b.c_str());
    mciSendString(_b, NULL, 0, NULL);
    delete _b;
}

void AudioFile::forceStop() const noexcept {
    std::string b = "stop " + filename;
    const wchar_t* _b = getWC(b.c_str());
    mciSendString(_b, NULL, 0, NULL);
    delete _b;
}

AudioFile::~AudioFile() noexcept {
    std::string b = "close " + filename;
    const wchar_t* _b = getWC(b.c_str());
    mciSendString(_b, NULL, 0, NULL);
    delete _b;
}
