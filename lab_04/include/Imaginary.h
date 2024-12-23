#ifndef IMAGINARY_H
#define IMAGINARY_H

#include "CMPLX.h"

class Imaginary : public CMPLX {
public:
    Imaginary(float i);
    void Setcompl(float i);
    CMPLX Add(const CMPLX& other) const override;
    CMPLX Div(const CMPLX& other) const override;
    void Display() const override;
};

#endif
