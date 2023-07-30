/*
 * Created by Ilya 'StormLord07' Repnev
 * Created on Sun Jul 30 2023
 */


#include "UTF8String.h"

namespace UTF8Lib {
    UTF8String::UTF8String() {};
    UTF8String::UTF8String(const std::string &str) {
        size_t i = 0;
        while (i < str.size()) {
            size_t len = getCharLength(str[i]);
            chars.push_back(UTF8Char(str.substr(i, len)));
            i += len;
        }
    }

    size_t UTF8String::size() const {
        return chars.size();
    }

    const UTF8Char &UTF8String::operator[](size_t index) const { // definition
        return chars[index];
    }

    std::string UTF8String::toString() const {
        std::string str;
        for (const UTF8Char &c : chars) {
            str += c.toString();
        }
        return str;
    }

}