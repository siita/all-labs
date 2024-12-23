#include <iostream>
#include "TextCleaner.h"

int main() {
    const char text[] = "aaabcaadaaa";
    TextCleaner cleaner;
    cleaner.setText(text);

    cleaner.removeDuplicates();
    std::cout << "Processed text: " << cleaner.getProcessedText() << std::endl;
    system("pause");

    return 0;
}