#ifndef _TEXUI_INCLUDE_HPP
#define _TEXUI_INCLUDE_HPP
#include <windows.h>
#include <iostream>
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define keyDown(key) GetAsyncKeyState(key) & 0x8000
#endif