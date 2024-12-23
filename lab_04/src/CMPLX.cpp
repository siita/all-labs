#include "CMPLX.h"
#include <cmath>
#include <iostream>
#include <stdexcept> // Для обработки ошибок

CMPLX::CMPLX(float r, float i) : re(r), im(i) {}

float CMPLX::getReal() const { return re; }
float CMPLX::getImag() const { return im; }

void CMPLX::setReal(float r) { re = r; }
void CMPLX::setImag(float i) { im = i; }

void CMPLX::Setcompl(float r, float i) {
    re = r;
    im = i;
}

CMPLX CMPLX::Add(const CMPLX& other) const {
    return CMPLX(re + other.re, im + other.im);
}

CMPLX CMPLX::Div(const CMPLX& other) const {
    float denominator = other.re * other.re + other.im * other.im;
    if (denominator == 0) {
        throw std::runtime_error("Деление на ноль!");
    }
    float new_re = (re * other.re + im * other.im) / denominator;
    float new_im = (im * other.re - re * other.im) / denominator;
    return CMPLX(new_re, new_im);
}

void CMPLX::Display() const {
    std::cout << "(" << re << " + " << im << "i)";
}
