#ifndef _TEXUI_OBJECT_HPP_
#define _TEXUI_OBJECT_HPP_

class Object{
private:
	int id;
public:
	Object(){}
	virtual void draw(vector<vector<Char> > &board, Pos p) = 0;
	void setId(int id1) {id = id1;}
	void callEvent(EVENT e) {
		syncevent(e, (EPARA)id);
	}
};

class OFrameBase : public Object{
public:
	vector<vector<Char> > board;
	OFrameBase(int w = 0, int h = 0) {
		board = vector<vector<Char> >(h, vector<Char>(w, Char(' ', normal)));
	}
	OFrameBase operator=(OFrameBase o) {
		board = o.board;
		return *this;
	}
	void draw(vector<vector<Char> > &disBoard, Pos p) override {
		callEvent("OnDraw");
		rep (i, 0, int(board.size()) - 1) {
			rep (j, 0, int(board[i].size()) - 1) {
				disBoard[i + p.x][j + p.y] = board[i][j];
			}
		}
	}
};
typedef OFrameBase OFrame;
class OScene : public OFrameBase{
public:
	using OFrameBase :: OFrameBase;
	void print() {
		moveCursor({0, 0});
		for (auto i:board) {
			for (auto j:i) {
				j.print();
			}
			printf("\n");
		}
	}
	void print(OScene lst) {
		moveCursor({0, 0});
		rep (i, 0, int(board.size()) - 1) {
			rep (j, 0, int(board[i].size()) - 1) {
				if (board[i][j] == lst.board[i][j]) continue;
				moveCursor({i + 1, j + 1});
				board[i][j].print();
			}
			printf("\n");
		}
	}
}mainScene;
class OWindow : public OFrameBase{
public:
	OWindow(int w = 0, int h = 0, COL shadowCol) {
		board = vector<vector<Char> >(h + 1, vector<Char>(w + 1, Char(' ', normal)));
		rep (i, 0, w) {
			board[i][0] = Char(' ', shadowCol);
		}
		rep (i, 0, h) {
			board[0][i] = Char(' ', shadowCol);
		}
	}
}

class OText : public Object{
private:
	String text;
public:
	OText(){}
	OText(String s) {
		text = s;
	}
	void draw(vector<vector<Char> > &board, Pos p) override {
		callEvent("OnDraw");
		vector<String> vString = splitString(text);
		rep (j, 0, (int)vString.size() - 1) {
			rep (i, 0, (int)vString[j].size() - 1) {
				board[p.x + j][p.y + i] = vString[j][i];
			}
		}
	}
	OText operator=(OText o) {
		text = o.text;
		return *this;
	}
};
class OButton : public Object{
private:
	OText t;
	int w, h;
	COL c;
	String text;
public:
	OButton(String s, int w, int h, COL c):w(w), h(h), c(c) {
		t = OText(s);
		text = s;
	}
	void draw(vector<vector<Char> > &board, Pos p) override {
		callEvent("OnDraw");
		vector<String> vString = splitString(text);
		int wText = vString[0].size(), hText = vString.size();
		rep (i, 0, h - 1) {
			rep (j, 0, w - 1) {
				board[p.x + i][p.y + j] = Char(' ', c);
			}
		}
		Pos pText = {p.x + (h - hText) / 2, p.y + (w - wText) / 2};
		t.draw(board, pText);
	}
};

void draw(OFrameBase &of, Object &o, Pos p) {
	o.draw(of.board, p);
}

int mainLoop() {
    mainScene.print();
    OScene lst = mainScene;
    int cnt = 0;
    while (1) {
        if (keyDown(VK_ESCAPE)) break;
        syncevent("LOOP", (EPARA)cnt);
        mainScene.print(lst);
        lst = mainScene;
        cnt++;
    }
    return 0;
}
#endif