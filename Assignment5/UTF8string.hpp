#ifndef LAB5_UTF8STRING_HPP
#define LAB5_UTF8STRING_HPP

#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include "utf8.h"

class UTF8string {
public:
    UTF8string() {};

    UTF8string(const char *s) : _str(s) {}

    UTF8string(std::string s) : _str(s) {}

    std::string str() const {
        return _str;
    }

    int length();

    int bytes();

    int find(std::string substr);

    void replace(UTF8string to_remove, UTF8string replace);

    friend std::ostream &operator<<(std::ostream &out, const UTF8string &us);

    UTF8string operator+(const UTF8string &rhs) const;

    UTF8string &operator+=(const UTF8string &rhs);

    UTF8string operator*(const int &rhs);

    friend UTF8string operator*(const int &lhs, const UTF8string &rhs);

    UTF8string operator!();

private:
    std::string _str;
};

#endif //LAB5_UTF8STRING_HPP
