#include "TextCleaner.h"
#include <cstring>  // Для strcpy и strlen

void TextCleaner::setText(const char* inputText) {
    delete[] text; // Удаление предыдущей копии текста, если была
    size_t length = strlen(inputText) + 1;
    text = new char[length];
    strcpy(text, inputText);  // Копирование текста для работы
}

void TextCleaner::removeDuplicates() {
    if (!text) return;

    char* writePtr = text;

    for (char* readPtr = text; *readPtr; ++readPtr) {
        if (writePtr == text || *readPtr != 'a' || *(writePtr - 1) != 'a') {
            *writePtr++ = *readPtr;
        }
    }
    *writePtr = '\0';
}

const char* TextCleaner::getProcessedText() const {
    return text;  // Возвращаем обработанную строку
}
