#ifndef _TEXUI_SCENE_HPP_
#define _TEXUI_SCENE_HPP_
struct Scene{
	vector<vector<Char> > board;
	Scene(int w = 0, int h = 0) {
		board = vector<vector<Char> >(h, vector<Char>(w, Char(' ', normal)));
	}
	void print() {
		moveCursor({0, 0});
		for (auto i:board) {
			for (auto j:i) {
				j.print();
			}
			printf("\n");
		}
	}
	Scene operator=(Scene o) {
		board = o.board;
		return *this;
	}
	void print(Scene lst) {
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
};
#endif