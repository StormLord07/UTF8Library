/*
 * Created by Ilya 'StormLord07' Repnev
 * Created on Sun Jul 30 2023
 */
#ifndef UTF8_CHAR_H
#define UTF8_CHAR_H

#include "UTF8LibConfig.h"
#include <array>
#include <string>
#include <stdexcept>

 /**
  * @brief namespace of a UTF8Lib
  */
namespace UTF8Lib {
    class UTF8LIB_API UTF8Char {
    private:
        std::array<unsigned char, 4> data;
        size_t length;

    public:
        UTF8Char(const std::string &str);
        UTF8Char(const std::string &str, size_t len);
        UTF8Char(const std::array<unsigned char, 4> &bytes, size_t len);


        size_t getLength() const;
        std::string toString() const;
        std::array<unsigned char, 4> toBytes() const;
    };

    size_t getCharLength(char c);
}

#endif //UTF8_CHAR_H