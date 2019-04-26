#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include "utf8.h"
using namespace std;

class UTF8string {
  public:
	UTF8string() {}
	UTF8string(const char *s): _str(s) {}
	UTF8string(string s): _str(s) {}

	string str() const {
		return _str;
	}

	int length() {
		unsigned char *p = (unsigned char *)_str.c_str();
		return utf8_charlen(p);
	}

	int bytes() {
		unsigned char *p = (unsigned char *)_str.c_str();
		return utf8_charpos_to_bytes(p, length());
	}

	int find(string substr) {
		unsigned char *p = (unsigned char *)_str.c_str();
		unsigned char *ret = utf8_search(p, (unsigned char *)substr.c_str());
		return utf8_bytes_to_charpos(p, ret - p);
	}

	void replace(UTF8string to_remove, UTF8string replace) {
		unsigned char *start = (unsigned char *)_str.c_str();
		unsigned char *p = start;
		unsigned char *ret;
		while (true) {
			ret = utf8_search(p, (unsigned char *)to_remove.str().c_str());
			if (ret == NULL) break;
			_str.replace(ret - start, to_remove.str().length(), replace.str());
			p = ret + to_remove.str().length();
		}
	}

	friend ostream &operator<< (ostream &out, const UTF8string &us) {
		out << us.str();
		return out;
	}

	UTF8string operator+(const UTF8string &rhs) const {
		UTF8string res(_str + rhs.str());
		return res;
	}

	UTF8string &operator+=(const UTF8string &rhs) {
		_str += rhs.str();
		return (*this);
	}

	UTF8string operator*(const int &rhs) {
		string str;
		for (int i = 0; i < rhs; i++) {
			str += _str;
		}
		UTF8string res(str);
		return res;
	}

	UTF8string operator!() {
		unsigned char *start = (unsigned char *)_str.c_str();
		unsigned char *p = start;
		string str = _str;
		int i;
		int bytes_in_char;
		unsigned int codepoint;
		while (*p) {
			codepoint = utf8_to_codepoint(p, &bytes_in_char);
			if (codepoint) {
				reverse(str.begin() + (p - start), str.begin() + (p - start + bytes_in_char));
				_utf8_incr(p);
			} else {
				printf("%c Invalid UTF-8\n", *p);
				p++;
			}
		}
		reverse(str.begin(), str.end());
		return UTF8string(str);
	}
  private:
	string _str;
};
