#include <iostream>

double CalculateSquareRoot(double number, double precision) {
    double x = number;
    double y = 1.0;

    while (x - y > precision) {
        x = (x + y) / 2;
        y = number / x;
    }

    return x;
}

int main() {
    setlocale(LC_ALL, "Russian");
    double inputNumber;
    double precisionValue = 0.01;

    std::cout << "Введите число: ";
    std::cin >> inputNumber;

    double result = CalculateSquareRoot(inputNumber, precisionValue);

    std::cout << "Квадратный корень из " << inputNumber << " приближенно равен: " << result << std::endl;

    return 0;
}