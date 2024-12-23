#include "InputUtils.h"
#include <iostream>
#include <sstream>

float InputUtils::getValidNumber(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        
        if (isValidNumber(input)) {
            return std::stof(input);
        }
        std::cout << "Ошибка! Введите корректное число.\n";
    }
}

bool InputUtils::isValidNumber(const std::string& str) {
    std::istringstream iss(str);
    float f;
    iss >> std::noskipws >> f;
    return iss.eof() && !iss.fail();
}
