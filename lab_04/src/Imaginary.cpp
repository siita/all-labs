#include "Imaginary.h"
#include <iostream>
#include <iomanip>
#include <cmath>

// Конструктор
Imaginary::Imaginary(float i) : CMPLX(0.0f, i) {}

// Переопределение Setcompl
void Imaginary::Setcompl(float i) {
    setImag(i);
    std::cout << "Imaginary: Установлено новое значение: ";
    Display();
}

// Переопределение Add
CMPLX Imaginary::Add(const CMPLX& other) const {
    if (other.getReal() != 0) {
        throw std::invalid_argument("Добавление комплексных чисел с действительной частью запрещено в классе Imaginary.");
    }
    return CMPLX(0.0f, getImag() + other.getImag());
}

// Переопределение Div
CMPLX Imaginary::Div(const CMPLX& other) const {
    if (other.getReal() == 0 && other.getImag() == 0) {
        throw std::runtime_error("Деление на ноль!");
    }
    return CMPLX(0.0f, getImag() / other.getImag());
}

// Переопределение Display
void Imaginary::Display() const {
    std::cout << "Imaginary число: " << getImag() << "i" << std::endl;
}
