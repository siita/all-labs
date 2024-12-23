#ifndef COMPLEX_OPERATIONS_H
#define COMPLEX_OPERATIONS_H

#include "CMPLX.h"

class ComplexOperations : public CMPLX {
public:
    // Конструкторы
    ComplexOperations(float r = 0, float i = 0);
    ComplexOperations(const CMPLX& complex);
    
    // Переопределение виртуальных методов
    void Setcompl(float r, float i) override;
    CMPLX Add(const CMPLX& what) const override;
    CMPLX Div(const CMPLX& what) const override;
    void Display() const override;
    
    // Дополнительные методы для расширенной функциональности
    float getMagnitude() const;
    float getPhase() const;
};

#endif
