#include "number_processor.hpp"
#include <iostream>
#include <limits>

int main() {
    NumberProcessor<int> intProcessor;
    int choice;
    int number;

    while (true) {
        std::cout << "\nМеню:\n";
        std::cout << "1. Ввести число\n";
        std::cout << "2. Показать все числа\n";
        std::cout << "3. Переставить числа\n";
        std::cout << "4. Показать сумму чисел\n";
        std::cout << "5. Показать минимальное число\n";
        std::cout << "6. Показать максимальное число\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите опцию: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Введите число: ";
                std::cin >> number;
                intProcessor.addNumber(number);
                break;
            case 2:
                std::cout << "Числа: ";
                for (const auto& num : intProcessor.getNumbers()) {
                    std::cout << num << " ";
                }
                std::cout << std::endl;
                break;
            case 3:
                intProcessor.reorderNumbers();
                std::cout << "Числа переставлены." << std::endl;
                break;
            case 4:
                std::cout << "Сумма чисел: " << intProcessor.getSum() << std::endl;
                break;
            case 5:
                try {
                    std::cout << "Минимальное число: " << intProcessor.getMin() << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case 6:
                try {
                    std::cout << "Максимальное число: " << intProcessor.getMax() << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case 0:
                std::cout << "Выход из программы." << std::endl;
                return 0;
            default:
                std::cout << "Неверный выбор. Пожалуйста, попробуйте снова." << std::endl;
        }
    }

    return 0;
} 