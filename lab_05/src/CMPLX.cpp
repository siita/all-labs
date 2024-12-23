#include "CMPLX.h"
#include <stdexcept>
#include <cmath>

// Конструкторы
CMPLX::CMPLX(float real, float imag) : real(real), imag(imag) {}

CMPLX::CMPLX(const CMPLX& other) : real(other.real), imag(other.imag) {}

// Методы
void CMPLX::Setcompl(float real, float imag) {
    this->real = real;
    this->imag = imag;
}

CMPLX CMPLX::Add(const CMPLX& what) const {
    return CMPLX(real + what.real, imag + what.imag);
}

CMPLX CMPLX::Div(const CMPLX& what) const {
    float denom = what.real * what.real + what.imag * what.imag;
    if (denom == 0) {
        throw std::runtime_error("Division by zero!");
    }
    float newReal = (real * what.real + imag * what.imag) / denom;
    float newImag = (imag * what.real - real * what.imag) / denom;
    return CMPLX(newReal, newImag);
}

// Перегруженные операторы
CMPLX CMPLX::operator+(const CMPLX& other) const {
    return Add(other);
}

CMPLX CMPLX::operator/(const CMPLX& other) const {
    return Div(other);
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& os, const CMPLX& complex) {
    os << "(" << complex.real << ", " << complex.imag << "i)";
    return os;
}

// Функтор для получения модуля
float CMPLX::operator()() const {
    return std::sqrt(real * real + imag * imag);
}

// Перегрузка оператора ввода
std::istream& operator>>(std::istream& is, CMPLX& complex) {
    std::cout << "Введите действительную часть: ";
    is >> complex.real;
    std::cout << "Введите мнимую часть: ";
    is >> complex.imag;
    return is;
}