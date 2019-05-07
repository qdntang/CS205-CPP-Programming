#include "UTF8string.hpp"

int UTF8string::length() {
    auto *p = (unsigned char *) _str.c_str();
    return utf8_charlen(p);
}

int UTF8string::bytes() {
    auto *p = (unsigned char *) _str.c_str();
    return utf8_charpos_to_bytes(p, length());
}

int UTF8string::find(std::string substr) {
    auto *p = (unsigned char *) _str.c_str();
    unsigned char *ret = utf8_search(p, (unsigned char *) substr.c_str());
    return utf8_bytes_to_charpos(p, ret - p);
}

void UTF8string::replace(UTF8string to_remove, UTF8string replace) {
    auto *start = (unsigned char *) _str.c_str();
    unsigned char *p = start;
    unsigned char *ret;
    while (true) {
        ret = utf8_search(p, (unsigned char *) to_remove.str().c_str());
        if (ret == NULL) break;
        _str.replace(ret - start, to_remove.str().length(), replace.str());
        p = ret + to_remove.str().length();
    }
}

std::ostream &operator<<(std::ostream &out, const UTF8string &us) {
    out << us.str();
    return out;
}

UTF8string UTF8string::operator+(const UTF8string &rhs) const {
    UTF8string res(_str + rhs.str());
    return res;
}

UTF8string &UTF8string::operator+=(const UTF8string &rhs) {
    _str += rhs.str();
    return (*this);
}

UTF8string UTF8string::operator*(const int &rhs) {
    std::string str;
    for (int i = 0; i < rhs; i++) {
        str += _str;
    }
    UTF8string res(str);
    return res;
}

UTF8string UTF8string::operator!() {
    auto *start = (unsigned char *) _str.c_str();
    unsigned char *p = start;
    std::string str = _str;
    int bytes_in_char;
    unsigned int codepoint;
    while (*p) {
        codepoint = utf8_to_codepoint(p, &bytes_in_char);
        if (codepoint) {
            std::reverse(str.begin() + (p - start), str.begin() + (p - start + bytes_in_char));
            _utf8_incr(p);
        } else {
            printf("%c Invalid UTF-8\n", *p);
            p++;
        }
    }
    std::reverse(str.begin(), str.end());
    return UTF8string(str);
}

UTF8string operator*(const int &lhs, const UTF8string &rhs) {
    std::string str;
    for (int i = 0; i < lhs; i++) {
        str += rhs._str;
    }
    UTF8string res(str);
    return res;
}
