/*
 * Created by Ilya 'StormLord07' Repnev
 * Created on Sun Jul 30 2023
 */


#pragma once
#include <vector>
#include "UTF8Char.h"

namespace UTF8Lib {
    class UTF8String {
    private:
        std::vector<UTF8Char> chars;
    public:
        UTF8String();
        UTF8String(const std::string &str);

        size_t size() const;

        const UTF8Char &operator[](size_t index) const;

        std::string toString() const;
    };
}