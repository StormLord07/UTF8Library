/*
 * Created by Ilya 'StormLord07' Repnev
 * Created on Sun Jul 30 2023
 */
#ifndef UTF8_STRING_H
#define UTF8_STRING_H

#include "UTF8LibConfig.h"
#include <vector>
#include "UTF8Char.h"

namespace UTF8Lib {
    class UTF8LIB_API UTF8String {
    private:
#pragma warning(push)
#pragma warning(disable : 4251) // Disable warning C4251 for chars
        std::vector<UTF8Char> chars;
#pragma warning(pop)
    public:
        UTF8String();
        UTF8String(const std::string &str);

        size_t size() const;

        const UTF8Char &operator[](size_t index) const;

        std::string toString() const;
    };
}

#endif //UTF8_STRING_H