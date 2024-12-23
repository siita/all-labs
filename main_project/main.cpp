#include <iostream>
#include <cstdlib>
#include <string>
#include <filesystem>

// Прототипы функций для запуска лабораторных работ
void runLab01();
void runLab02();
void runLab03();
void runLab04();
void runLab05();
void runLab06();
void runLab07();

// Функция для проверки существования файла
bool fileExists(const std::string& path) {
    return std::filesystem::exists(path);
}

// Функция для запуска программы с проверкой
void runProgram(const std::string& path) {
    std::string exePath = path;
#ifdef _WIN32
    exePath += ".exe";
#endif

    // Добавляем подробную диагностику
    std::cout << "Проверка запуска программы:\n";
    std::cout << "Полный путь: " << std::filesystem::absolute(exePath) << std::endl;
    std::cout << "Текущая директория: " << std::filesystem::current_path() << std::endl;
    
    if (!fileExists(exePath)) {
        std::cout << "Ошибка: Файл '" << exePath << "' не найден.\n";
        std::cout << "Текущая директория: " << std::filesystem::current_path() << std::endl;
        std::cout << "Пожалуйста, выполните следующие действия:\n";
        std::cout << "1. Убедитесь, что файл скомпилирован командой:\n";
#ifdef _WIN32
        std::cout << "   g++ " << path << ".cpp -o " << path << ".exe\n";
#else
        std::cout << "   g++ " << path << ".cpp -o " << path << "\n";
#endif
        std::cout << "2. Проверьте, что путь к файлу указан верно\n";
        std::cout << "3. Проверьте права доступа к файлу\n";
        return;
    }

    std::string command;
#ifdef _WIN32
    command = "\"" + exePath + "\"";
#else
    command = "./" + exePath;
#endif

    std::cout << "Выполняется команда: " << command << std::endl;
    int result = system(command.c_str());
    if (result != 0) {
        std::cout << "Ошибка при запуске программы (код: " << result << ")\n";
    }
}

int main() {
    int choice;

    do {
        std::cout << "\n=== Главное меню ===\n";
        std::cout << "1. Запустить Lab 01 (Комплексные числа)\n";
        std::cout << "2. Запустить Lab 02 (Обработка текста)\n";
        std::cout << "3. Запустить Lab 03 (Обработка последовательностей)\n";
        std::cout << "4. Запустить Lab 04 (Наследование)\n";
        std::cout << "5. Запустить Lab 05 (Перегрузка операторов)\n";
        std::cout << "6. Запустить Lab 06 (Шаблоны)\n";
        std::cout << "7. Запустить Lab 07 (Потоки ввода-вывода)\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите лабораторную работу: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                runLab01();
                break;
            case 2:
                runLab02();
                break;
            case 3:
                runLab03();
                break;
            case 4:
                runLab04();
                break;
            case 5:
                runLab05();
                break;
            case 6:
                runLab06();
                break;
            case 7:
                runLab07();
                break;
            case 0:
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}

// Функции запуска лабораторных работ
void runLab01() {
#ifdef _WIN32
    runProgram("lab_01\\Debug\\lab01");  // Измените путь на реальный
#else
    runProgram("lab_01/lab01");
#endif
}

void runLab02() {
#ifdef _WIN32
    runProgram("lab_02\\Debug\\lab02");  // Измените путь на реальный
#else
    runProgram("lab_02/lab02");
#endif
}

void runLab03() {
#ifdef _WIN32
    runProgram("lab_03\\Debug\\lab03");  // Измените путь на реальный
#else
    runProgram("lab_03/lab03");
#endif
}

void runLab04() {
#ifdef _WIN32
    runProgram("lab_04\\Debug\\lab04");  // Измените путь на реальный
#else
    runProgram("lab_04/lab04");
#endif
}

void runLab05() {
#ifdef _WIN32
    runProgram("lab_05\\Debug\\lab05");  // Измените путь на реальный
#else
    runProgram("lab_05/lab05");
#endif
}

void runLab06() {
#ifdef _WIN32
    runProgram("lab_06\\Debug\\lab06");  // Измените путь на реальный
#else
    runProgram("lab_06/lab06");
#endif
}

void runLab07() {
#ifdef _WIN32
    runProgram("lab_07\\Debug\\lab07");  // Измените путь на реальный
#else
    runProgram("lab_07/lab07");
#endif
} 