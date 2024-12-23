#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "CMPLX.h"

// Проверка, является ли символ числом
bool isDigit(char ch) {
    return (ch >= '0' && ch <= '9') || ch == '-' || ch == '.';
}

// Ввод числа с проверкой
float InputNumber() {
    char input[100];
    bool valid = false;
    float number = 0;

    while (!valid) {
        printf("Введите число: ");
        scanf("%s", input);

        bool allDigits = true;
        for (int i = 0; input[i] != '\0'; i++) {
            if (!isDigit(input[i])) {
                allDigits = false;
                break;
            }
        }

        if (allDigits) {
            number = atof(input);
            valid = true;
        } else {
            printf("Ошибка! Введите корректное число.\n");
        }
    }

    return number;
}

int main() {
    // Ввод первого комплексного числа
    printf("Введите действительную и мнимую часть первого числа.\n");
    float real1 = InputNumber();
    float imag1 = InputNumber();
    CMPLX num1(real1, imag1);

    // Ввод второго комплексного числа
    printf("Введите действительную и мнимую часть второго числа.\n");
    float real2 = InputNumber();
    float imag2 = InputNumber();
    CMPLX num2(real2, imag2);

    // Вывод исходных чисел
    printf("Первое число: ");
    num1.Print();
    printf("Второе число: ");
    num2.Print();

    // Изменение второго числа
    printf("Введите новые значения для второго числа.\n");
    real2 = InputNumber();
    imag2 = InputNumber();
    num2.Setcompl(real2, imag2);
    printf("Второе число после изменения: ");
    num2.Print();

    // Сложение чисел
    CMPLX sum = num1.Add(num2);
    printf("Результат сложения: ");
    sum.Print();

    // Деление чисел
    CMPLX div = num1.Div(num2);
    printf("Результат деления: ");
    div.Print();

    return 0;
}
