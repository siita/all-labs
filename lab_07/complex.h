#include <iostream>
#include <iomanip>

// Класс для работы с комплексными числами
class CMPLX {
private:
    float real;  // Действительная часть
    float imag;  // Мнимая часть

public:
    // Конструктор с параметрами по умолчанию
    CMPLX(float r = 0, float i = 0) : real(r), imag(i) {}
    
    // Метод установки значений комплексного числа
    void Setcompl(float r, float i) {
        real = r;
        imag = i;
    }
    
    // Метод сложения комплексных чисел
    CMPLX Add(const CMPLX& what) const {
        return CMPLX(real + what.real, imag + what.imag);
    }
    
    // Метод деления комплексных чисел
    CMPLX Div(const CMPLX& what) const {
        float denominator = what.real * what.real + what.imag * what.imag;
        float newReal = (real * what.real + imag * what.imag) / denominator;
        float newImag = (imag * what.real - real * what.imag) / denominator;
        return CMPLX(newReal, newImag);
    }
    
    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const CMPLX& c) {
        os << c.real;
        if (c.imag >= 0) os << "+";
        os << c.imag << "i";
        return os;
    }
    
    // Перегрузка оператора ввода
    friend std::istream& operator>>(std::istream& is, CMPLX& c) {
        is >> c.real >> c.imag;
        return is;
    }
};