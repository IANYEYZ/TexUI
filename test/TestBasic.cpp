#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
#include "../TexUI.hpp"
void handleLOOP(EPARA p) {
	int cnt = transepara<int>(p);
	mainScene.board[0][1] = Char(char(cnt % 10 + '0'), normal);
}
String ConString(string s, COL c) {
	String res;
	for (auto i:s) {
		res += Char(i, c);
	}
	return res;
}
void handleOnDraw(EPARA p) {
	int id = transepara<int>(p);
	if (id == 1) {
		moveCursor({20, 25});
		printf("OnDraw(OText o)");
		// moveCursor({0, 0});
	}
}
int main()
{
	vector<String> v = splitString(ConString("Hello World!\nHello World!", normal));
	moveCursor({16, 16});
	cout << v.size() << "\n";
	init();
	mainScene = OScene(15, 15);
	mainScene.board[0][0] = Char('a', normal);
	OText o(ConString("Hello World!\nHello World!", normal));
	o.setId(1);
	OButton b(ConString("Hello World!\nHello World!", normal), 15, 5, {{10, 10, 10}, {20, 20, 20}});
	b.setId(2);
	bind("LOOP", handleLOOP);
	bind("OnDraw", handleOnDraw);
	draw(mainScene, o, {1, 0});
	draw(mainScene, b, {5, 0});
	return mainLoop();
}