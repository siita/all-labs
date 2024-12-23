#include <iostream>
#include "NumberSequence.h"
#include <windows.h>

int main() {
    // Устанавливаем кодировку UTF-8 для консоли
    SetConsoleOutputCP(CP_UTF8);

    int size;
    std::cout << "Введите размер числовой последовательности: ";
    std::cin >> size;

    int* inputArray = new int[size];
    std::cout << "Введите " << size << " чисел: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> inputArray[i];
    }

    // Создаем объект для обработки числовой последовательности
    NumberSequence sequence(size, "aaabacadaeaf");

    // Заполняем числовую последовательность без модификации
    sequence.fillNumbers(inputArray, size);
    sequence.processNumbers();
    sequence.printNumbers();

    // Заполняем числовую последовательность с модификацией
    sequence.modifyAndFillNumbers(inputArray, size);
    sequence.printNumbers();

    // Обрабатываем и выводим текст
    sequence.removeExtraAs();
    sequence.printText();

    delete[] inputArray;

    return 0;
}
