#ifndef MANIP_H
#define MANIP_H

#include <iostream>
#include <iomanip>
#include <sstream>

// Класс для управления форматированием вывода
class Manip {
public:
    // Конструктор: принимает ширину, систему счисления, точность и символ заполнения
    Manip(int w, int b, int p, char f) : width(w), base(b), precision(p), fill(f) {}

    // Перегрузка оператора вывода для применения форматирования
    friend std::ostream& operator<<(std::ostream& os, const Manip& m) {
        os << std::setw(m.width)
           << std::setbase(m.base)
           << std::setprecision(m.precision)
           << std::setfill(m.fill);
        return os;
    }

    // Статический метод для восьмеричного формата
    static Manip oct() {
        return Manip(6, 8, 0, '*');
    }
    
    // Статический метод для десятичного формата
    static Manip dec() {
        return Manip(6, 10, 0, '*');
    }

    // Статический метод для формата с плавающей точкой
    static Manip float_format(int precision) {
        return Manip(6, 10, precision, '*');
    }

    // Метод для преобразования манипулятора в строку
    std::string toString() const {
        std::ostringstream oss;
        oss << std::setw(width)
            << std::setbase(base)
            << std::setprecision(precision)
            << std::setfill(fill);
        return oss.str();
    }

private:
    int width;      // Ширина поля вывода
    int base;       // Система счисления
    int precision;  // Точность для чисел с плавающей точкой
    char fill;      // Символ заполнения
};

#endif