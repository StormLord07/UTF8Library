/*
 * Created by Ilya 'StormLord07' Repnev
 * Created on Sun Jul 30 2023
 */


#include "UTF8Char.h"
#include <iostream>
namespace UTF8Lib {


    UTF8Char::UTF8Char(const std::string &str) {
        length = getCharLength(str[0]);
        std::cout << length << "\n" << std::endl;
        for (int i = 0; i < length; i++) {
            data[i] = static_cast<unsigned char>(str[i]);
        }
    }

    UTF8Char::UTF8Char(const std::string &str, size_t len) : length(len) {

        for (int i = 0; i < length; i++) {
            data[i] = static_cast<unsigned char>(str[i]);
        }
    }

    UTF8Char::UTF8Char(const std::array<unsigned char, 4> &bytes, size_t len) : data(bytes), length(len) {}

    size_t UTF8Char::getLength() const {
        return length;
    }

    bool isNextCharVariationSelector(const std::string &str, size_t pos) {
        if (pos + 1 >= str.size()) {
            return false;
        }

        uint32_t nextCodePoint = static_cast<unsigned char>(str[pos + 1]);

        return nextCodePoint >= 0xFE00 && nextCodePoint <= 0xFE0F;
    }

    std::string UTF8Char::toString() const {
        return std::string(data.begin(), data.begin() + length);
    }

    std::array<unsigned char, 4> UTF8Char::toBytes() const {
        return data;
    }

    size_t getCharLength(char c) {
        unsigned char first_byte = static_cast<unsigned char>(c);

        if (first_byte < 128) {
            return 1;
        }
        else if ((first_byte >> 5) == 0x6) {
            return 2;
        }
        else if ((first_byte >> 4) == 0xE) {
            return 3;
        }
        else if ((first_byte >> 3) == 0x1E) {
            return 4;
        }
        else {
            throw std::runtime_error("Invalid UTF-8 character");
        }
    }

}