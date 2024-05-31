#ifndef _TEXUI_COLOR_HPP
#define _TEXUI_COLOR_HPP
struct RGBCol{
	int r, g, b;
	RGBCol(int r = 0, int g = 0, int b = 0):r(r), g(g), b(b){}
	bool operator==(RGBCol o) {
		return r == o.r && g == o.g && b == o.b;
	}
};
struct COL{
	RGBCol bg, fg;
	COL(RGBCol bg, RGBCol fg):bg(bg), fg(fg){}
	bool operator==(COL o) {
		return bg == o.bg && fg == o.fg;
	}
};
void setColor(COL color) {
	printf("\033[38;2;%d;%d;%dm\033[48;2;%d;%d;%dm", color.bg.r, color.bg.g, color.bg.b\
		, color.fg.r, color.fg.g, color.fg.b);
}
RGBCol bgNormal(255, 255, 255), fgNormal(0, 0, 0);
COL normal(bgNormal, fgNormal);
struct Char{
	char c;
	COL col;
	Char(char c, COL col):c(c), col(col){}
	Char():c(' '), col(normal){}
	void print() {
		setColor(col);
		printf("%c", c);
	}
	bool operator==(Char o) {
		return c == o.c && col == o.col;
	}
	Char operator=(Char o) {
		c = o.c;
		col = o.col;
		return *this;
	}
};
#endif