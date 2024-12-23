#ifndef INPUT_UTILS_H
#define INPUT_UTILS_H

#include <string>

class InputUtils {
public:
    static float getValidNumber(const std::string& prompt);
    static bool isValidNumber(const std::string& str);
};

#endif
