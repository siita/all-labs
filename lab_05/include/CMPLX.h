#ifndef CMPLX_H
#define CMPLX_H

#include <iostream>

class CMPLX {
private:
    float real;
    float imag;

public:
    // Конструкторы
    CMPLX(float real = 0, float imag = 0);
    CMPLX(const CMPLX& other);

    // Геттеры
    float getReal() const { return real; }
    float getImag() const { return imag; }

    // Методы
    void Setcompl(float real, float imag);
    CMPLX Add(const CMPLX& what) const;
    CMPLX Div(const CMPLX& what) const;

    // Перегруженные операторы
    CMPLX operator+(const CMPLX& other) const;
    CMPLX operator/(const CMPLX& other) const;
    
    // Перегрузка оператора вывода в поток
    friend std::ostream& operator<<(std::ostream& os, const CMPLX& complex);

    // Функтор для получения модуля
    float operator()() const;

    // Перегрузка оператора ввода
    friend std::istream& operator>>(std::istream& is, CMPLX& complex);
};

#endif
