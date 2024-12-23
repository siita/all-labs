#ifndef NUMBERSEQUENCE_H
#define NUMBERSEQUENCE_H

class NumberSequence {
public:
    NumberSequence(int size, const char* inputText);
    ~NumberSequence();

    void fillNumbers(const int* inputArray, int arraySize);  // Заполнение последовательности чисел
    void modifyAndFillNumbers(int* inputArray, int arraySize);  // Заполнение с модификацией
    void processNumbers();  // Преобразование числовой последовательности
    void printNumbers() const;  // Вывод числовой последовательности

    void removeExtraAs();  // Убирает лишние символы 'a' из текста
    void printText() const;  // Выводит текст

private:
    int* numbers;           // Динамический массив для чисел
    int size;               // Размер массива чисел
    char* text;             // Динамическая строка
};

#endif
