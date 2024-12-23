#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>

// Шаблонный класс для работы с числами
template<typename T>
class NumberProcessor {
private:
    std::vector<T> numbers;

public:
    // Добавление числа в последовательность
    void addNumber(T number) {
        numbers.push_back(number);
    }

    // Преобразование последовательности
    void reorderNumbers() {
        if (numbers.empty()) {
            return;
        }
        std::vector<T> negative, nonNegative;
        
        for (const T& num : numbers) {
            if (num < 0) {
                negative.push_back(num);
            } else {
                nonNegative.push_back(num);
            }
        }
        
        numbers.clear();
        numbers.insert(numbers.end(), negative.begin(), negative.end());
        numbers.insert(numbers.end(), nonNegative.begin(), nonNegative.end());
    }

    // Получение всех чисел
    const std::vector<T>& getNumbers() const {
        return numbers;
    }

    // Добавляем новые методы
    T getSum() const {
        T sum = 0;
        for (const T& num : numbers) {
            sum += num;
        }
        return sum;
    }

    T getMin() const {
        if (numbers.empty()) {
            throw std::runtime_error("Последовательность пуста");
        }
        T min = numbers[0];
        for (const T& num : numbers) {
            if (num < min) {
                min = num;
            }
        }
        return min;
    }

    T getMax() const {
        if (numbers.empty()) {
            throw std::runtime_error("Последовательность пуста");
        }
        T max = numbers[0];
        for (const T& num : numbers) {
            if (num > max) {
                max = num;
            }
        }
        return max;
    }

    void printStats() const {
        std::cout << "Статистика:\n";
        std::cout << "Количество чисел: " << numbers.size() << "\n";
        if (!numbers.empty()) {
            std::cout << "Сумма: " << getSum() << "\n";
            std::cout << "Минимум: " << getMin() << "\n";
            std::cout << "Максимум: " << getMax() << "\n";
        }
    }
};

// Вспомогательная функция для рекурсивного вывода
template<typename T>
void printArg(T arg) {
    std::cout << arg << " ";
}

// Базовый случай для рекурсии
void customPrintf() {
    std::cout << std::endl;
}

// Шаблонная функция для вывода произвольного количества аргументов
template<typename T, typename... Args>
void customPrintf(T first, Args... args) {
    printArg(first);
    customPrintf(args...);
} 