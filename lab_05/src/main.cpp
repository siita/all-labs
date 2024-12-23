#include <iostream>
#include "CMPLX.h"
#include "InputUtils.h"

int main() {
    try {
        CMPLX num1, num2;
        int choice;

        do {
            std::cout << "\nМеню:\n";
            std::cout << "1. Ввести первое комплексное число\n";
            std::cout << "2. Ввести второе комплексное число\n";
            std::cout << "3. Сложить числа\n";
            std::cout << "4. Разделить числа\n";
            std::cout << "5. Показать модуль первого числа\n";
            std::cout << "6. Показать модуль второго числа\n";
            std::cout << "0. Выход\n";
            std::cout << "Выберите опцию: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    std::cin >> num1;
                    break;
                case 2:
                    std::cin >> num2;
                    break;
                case 3:
                    std::cout << "Результат сложения: " << num1 + num2 << std::endl;
                    break;
                case 4:
                    try {
                        std::cout << "Результат деления: " << num1 / num2 << std::endl;
                    } catch (const std::exception& e) {
                        std::cerr << "Ошибка: " << e.what() << std::endl;
                    }
                    break;
                case 5:
                    std::cout << "Модуль первого числа: " << num1() << std::endl;
                    break;
                case 6:
                    std::cout << "Модуль второго числа: " << num2() << std::endl;
                    break;
                case 0:
                    std::cout << "Выход из программы.\n";
                    break;
                default:
                    std::cout << "Неверный выбор, попробуйте снова.\n";
            }
        } while (choice != 0);

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
