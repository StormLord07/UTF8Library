#include <iostream>
#include "UTF8String.h"
#include <fstream>

int main() {
    setlocale(LC_ALL, "");
    UTF8Lib::UTF8Char ch("✂");

    std::string strg = "✂✂✂";
    UTF8Lib::UTF8String str(strg);

    std::ofstream outFile("output.txt");
    if (!outFile) {
        std::cerr << "Failed to open output file." << std::endl;
        return 1;
    }

    std::cout << UTF8Lib::getCharLength("✂"[0]) << std::endl;
    outFile << '\xEF' << '\xBB' << '\xBF';
    outFile << ch.toString() << "\n";
    outFile << str[0].toString() << str[1].toString() << str[2].toString() << "\n";
    outFile.close();

    return 0;
}