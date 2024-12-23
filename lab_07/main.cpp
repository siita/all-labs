#include <iostream>
#include <iomanip>
#include "complex.h"
#include "manip.h"
#include <fstream>
#include <sstream>
#include <string>

// Функция для работы с комплексными числами
void testComplexNumbers() {
    int choice;
    CMPLX a, b;
    
    do {
        std::cout << "\n=== Работа с комплексными числами ===\n";
        std::cout << "1. Создать комплексные числа\n";
        std::cout << "2. Изменить комплексное число\n";
        std::cout << "3. Сложить комплексные числа\n";
        std::cout << "4. Разделить комплексные числа\n";
        std::cout << "5. Вывести текущие значения\n";
        std::cout << "0. Вернуться в главное меню\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch(choice) {
            case 1: {
                float real, imag;
                std::cout << "Введите первое комплексное число (действительная и мнимая части): ";
                std::cin >> real >> imag;
                a = CMPLX(real, imag);
                std::cout << "Введите второе комплексное число (действительная и мнимая части): ";
                std::cin >> real >> imag;
                b = CMPLX(real, imag);
                std::cout << "Созданы числа: a = " << a << ", b = " << b << std::endl;
                break;
            }
            case 2: {
                float real, imag;
                char which;
                std::cout << "Какое число изменить (a/b)? ";
                std::cin >> which;
                std::cout << "Введите новые значения (действительная и мнимая части): ";
                std::cin >> real >> imag;
                if (which == 'a') a.Setcompl(real, imag);
                else b.Setcompl(real, imag);
                std::cout << "Текущие значения: a = " << a << ", b = " << b << std::endl;
                break;
            }
            case 3: {
                CMPLX sum = a.Add(b);
                std::cout << "a + b = " << sum << std::endl;
                break;
            }
            case 4: {
                CMPLX div = a.Div(b);
                std::cout << "a / b = " << div << std::endl;
                break;
            }
            case 5: {
                std::cout << "a = " << a << std::endl;
                std::cout << "b = " << b << std::endl;
                break;
            }
        }
    } while (choice != 0);
}

void printToConsole(const std::string& text) {
    std::cout << text;
}

void printToFile(std::ofstream& outFile, const std::string& text) {
    outFile << text;
}

void testFormatting() {
    float f;
    int i1, i2;
    char ch1, ch2;
    std::ofstream outFile("output.txt");  // Открываем файл для записи

    if (!outFile.is_open()) {
        std::cout << "Ошибка открытия файла output.txt\n";
        return;
    }

    std::cout << "\nВведите данные в следующем порядке:\n";
    std::cout << "float i1 char1 i2 char2: ";
    std::cin >> f >> i1 >> ch1 >> i2 >> ch2;

    printToConsole("\nРезультаты форматированного вывода:\n");
    printToFile(outFile, "\nРезультаты форматированного вывода:\n");
    
    // Вывод в консоль и файл
    printToConsole(std::string(1, ch1) + "\n");
    printToFile(outFile, std::string(1, ch1) + "\n");
    
    std::string temp = Manip::float_format(1).toString() + "*" + std::to_string(i2) + ".4\n";
    printToConsole(temp);
    printToFile(outFile, temp);
    printToConsole(std::to_string(i2) + ".432\n");
    printToFile(outFile, std::to_string(i2) + ".432\n");
    printToConsole(std::to_string(i2) + ".43\n");
    printToFile(outFile, std::to_string(i2) + ".43\n");
    
    temp = Manip::dec().toString() + std::to_string(i1) + "\n";
    printToConsole(temp);
    printToFile(outFile, temp);
    printToConsole("**" + std::to_string(i1) + ".5\n");
    printToFile(outFile, "**" + std::to_string(i1) + ".5\n");
    printToConsole(std::to_string(i1) + ".456\n");
    printToFile(outFile, std::to_string(i1) + ".456\n");
    printToConsole("*" + std::to_string(i1) + ".46\n");
    printToFile(outFile, "*" + std::to_string(i1) + ".46\n");
    
    printToConsole(std::string(1, ch2) + "\n");
    printToFile(outFile, std::string(1, ch2) + "\n");

    outFile.close();
    std::cout << "\nРезультаты также записаны в файл output.txt\n";
}

int main() {
    int choice;
    
    do {
        std::cout << "\n=== Главное меню ===\n";
        std::cout << "1. Работа с комплексными числами (Задание 1)\n";
        std::cout << "2. Форматированный ввод/вывод (Задание 2)\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите задание: ";
        std::cin >> choice;

        switch(choice) {
            case 1:
                testComplexNumbers();
                break;
            case 2:
                testFormatting();
                break;
            case 0:
                std::cout << "Программа завершена\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}