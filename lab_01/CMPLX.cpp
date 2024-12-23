#include <stdio.h>
#include "CMPLX.h"

// Конструктор
CMPLX::CMPLX(float real, float imag) : real(real), imag(imag) {}

// Метод для изменения числа
void CMPLX::Setcompl(float real, float imag) {
    this->real = real;
    this->imag = imag;
}

// Метод для сложения
CMPLX CMPLX::Add(CMPLX what) {
    return CMPLX(this->real + what.real, this->imag + what.imag);
}

// Метод для деления
CMPLX CMPLX::Div(CMPLX what) {
    float denom = what.real * what.real + what.imag * what.imag;
    float newReal = (this->real * what.real + this->imag * what.imag) / denom;
    float newImag = (this->imag * what.real - this->real * what.imag) / denom;
    return CMPLX(newReal, newImag);
}

// Метод для вывода
void CMPLX::Print() const {
    printf("(%.2f, %.2fi)\n", this->real, this->imag);
}
