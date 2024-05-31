#ifndef _TEXUI_BASIC_HPP
#define _TEXUI_BASIC_HPP
#include "TEvent.hpp"
#include "TColor.hpp"
#include "TCursor.hpp"
#include "TScene.hpp"
bool OpenANSIControlChar()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) { return false; }

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) { return false; }

    dwMode |= 0x0004;
    if (!SetConsoleMode(hOut, dwMode)) { return false; }
    return true;
}

bool init() {
	return OpenANSIControlChar();
}
#endif