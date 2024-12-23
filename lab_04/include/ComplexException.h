#ifndef COMPLEX_EXCEPTION_H
#define COMPLEX_EXCEPTION_H

#include <exception> 
#include <string>

class ComplexException : public std::exception {
private:
    std::string message; // Поле для хранения сообщения об ошибке

public:
    // Конструктор, принимающий строку сообщения об ошибке
    explicit ComplexException(const char* msg) : message(msg) {}
    
    // Переопределение метода what() для возврата сообщения об ошибке
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif
