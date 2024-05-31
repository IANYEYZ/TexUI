#ifndef _TEXUI_CURSOR_HPP
#define _TEXUI_CURSOR_HPP
struct Pos{
	int x, y;
	Pos(int x = 0, int y = 0):x(x), y(y){}
	Pos(pair<int, int> p) {
		x = p.first;
		y = p.second;
	}
};
void moveCursor(Pos p) {
	printf("\x1b[%d;%dH", p.x, p.y);
}
#endif