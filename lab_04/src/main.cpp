#include <iostream>
#include <complex>

int main() {
    try {
        double real1, imag1, real2, imag2;

        // Ввод данных от пользователя
        std::cout << "Введите действительную и мнимую часть первого числа: ";
        std::cin >> real1 >> imag1;
        std::complex<double> num1(real1, imag1);

        std::cout << "Введите действительную и мнимую часть второго числа: ";
        std::cin >> real2 >> imag2;
        std::complex<double> num2(real2, imag2);

        std::cout << "Первое число: " << num1 << std::endl;
        std::cout << "Второе число: " << num2 << std::endl;

        std::complex<double> sum = num1 + num2;
        std::cout << "Сумма: " << sum << std::endl;

        std::complex<double> div = num1 / num2;
        std::cout << "Частное: " << div << std::endl;

        // Работа с мнимыми числами
        double imag3, imag4;
        std::cout << "\nВведите мнимую часть первого мнимого числа: ";
        std::cin >> imag3;
        std::complex<double> im1(0, imag3);

        std::cout << "Введите мнимую часть второго мнимого числа: ";
        std::cin >> imag4;
        std::complex<double> im2(0, imag4);

        std::cout << "\nПервое мнимое число: " << im1 << std::endl;
        std::cout << "Второе мнимое число: " << im2 << std::endl;

        std::complex<double> fsum = im1 + im2;
        std::cout << "Сумма мнимых чисел: " << fsum << std::endl;

        auto fdiv = im1 / im2;
        std::cout << "Частное мнимых чисел: " << fdiv << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    return 0;
}
