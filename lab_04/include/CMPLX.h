#ifndef CMPLX_H
#define CMPLX_H

class CMPLX {
protected:
    float re; // Действительная часть
    float im; // Мнимая часть

public:
    // Конструкторы и деструкторы
    CMPLX(float r = 0.0f, float i = 0.0f);
    virtual ~CMPLX() = default;

    // Методы для работы с реальной и мнимой частью
    float getReal() const;
    float getImag() const;
    void setReal(float r);
    void setImag(float i);

    // Общие операции
    virtual void Setcompl(float r, float i);
    virtual CMPLX Add(const CMPLX& other) const;
    virtual CMPLX Div(const CMPLX& other) const;

    // Для отладки
    virtual void Display() const;
};

#endif
