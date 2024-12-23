#ifndef CMPLX_H
#define CMPLX_H

class CMPLX {
public:
    CMPLX(float real, float imag); // Конструктор

    void Setcompl(float real, float imag); // Метод для изменения числа
    CMPLX Add(CMPLX what); // Метод для сложения
    CMPLX Div(CMPLX what); // Метод для деления
    void Print() const; // Метод для вывода

private:
    float real; // Действительная часть
    float imag; // Мнимая часть
};

#endif
