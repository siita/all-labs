#include "NumberSequence.h"
#include <iostream>
#include <cstring>

NumberSequence::NumberSequence(int size, const char* inputText) : size(size) {
    // Инициализация числовой последовательности
    numbers = new int[size];
    
    // Инициализация строки
    text = new char[strlen(inputText) + 1];
    strcpy(text, inputText);
}

NumberSequence::~NumberSequence() {
    delete[] numbers;  // Освобождение памяти для числовой последовательности
    delete[] text;     // Освобождение памяти для строки
}

void NumberSequence::fillNumbers(const int* inputArray, int arraySize) {
    if (arraySize != size) {
        std::cerr << "Ошибка: Размер входного массива не соответствует размеру NumberSequence." << std::endl;
        return;
    }
    for (int i = 0; i < size; ++i) {
        numbers[i] = inputArray[i];
    }
}

void NumberSequence::modifyAndFillNumbers(int* inputArray, int arraySize) {
    if (arraySize != size) {
        std::cerr << "Ошибка: Размер входного массива не соответствует размеру NumberSequence." << std::endl;
        return;
    }
    inputArray[4] = 100;  // Изменяем значение в массиве

    for (int i = 0; i < size; ++i) {
        numbers[i] = inputArray[i];
    }
}

void NumberSequence::processNumbers() {
    int* temp = new int[size];  // Временный массив для преобразования
    int negativeIndex = 0;
    int positiveIndex = size - 1;

    for (int i = 0; i < size; ++i) {
        if (numbers[i] < 0) {
            temp[negativeIndex++] = numbers[i];
        } else {
            temp[positiveIndex--] = numbers[i];
        }
    }

    for (int i = 0; i < size; ++i) {
        numbers[i] = temp[i];
    }

    delete[] temp;  // Освобождение временной памяти
}

void NumberSequence::printNumbers() const {
    std::cout << "Преобразованная числовая последовательность: ";
    for (int i = 0; i < size; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}

void NumberSequence::removeExtraAs() {
    int newSize = 0;

    for (int i = 0; i < strlen(text); ++i) {
        if (text[i] == 'a' && (i == 0 || text[i - 1] != 'a')) {
            ++newSize;
        } else if (text[i] != 'a') {
            ++newSize;
        }
    }

    char* newText = new char[newSize + 1];
    int j = 0;

    for (int i = 0; i < strlen(text); ++i) {
        if (text[i] == 'a' && (i == 0 || text[i - 1] != 'a')) {
            newText[j++] = text[i];
        } else if (text[i] != 'a') {
            newText[j++] = text[i];
        }
    }

    newText[j] = '\0';

    delete[] text;
    text = newText;
}

void NumberSequence::printText() const {
    std::cout << "Обработанный текст: " << text << std::endl;
}
