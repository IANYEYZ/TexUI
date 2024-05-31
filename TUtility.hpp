#ifndef _TEXUI_UTILITY_HPP_
#define _TEXUI_UTILITY_HPP_

typedef basic_string<Char> String;
vector<String> splitString(String s) {
	vector<String> res;
	int lst = 0, now = 0;
	while (now < s.size()) {
		if (s[now].c == '\n') {
			res.push_back(s.substr(lst, now - lst));
			lst = now + 1;
		}
		now++;
	}
	if (lst < s.size()) {
		res.push_back(s.substr(lst));
	}
	return res;
}
#endif