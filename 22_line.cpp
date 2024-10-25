#include <iostream>
#include <cmath>

// Функция для нахождения НОД (наибольший общий делитель)
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int x1, y1, x2, y2;
    std::cout << "Введите координаты x1, y1, x2, y2: ";
    std::cin >> x1 >> y1 >> x2 >> y2;

    // Вычисляем коэффициенты A, B и C
    int A = y2 - y1;
    int B = -(x2 - x1);
    int C = x1 * (y1 - y2) + y1 * (x2 - x1);

    // Находим НОД для упрощения
    int divisor = gcd(abs(A), gcd(abs(B), abs(C)));
    A /= divisor;
    B /= divisor;
    C /= divisor;

    // Если A отрицательный, умножаем все коэффициенты на -1
    if (A < 0) {
        A = -A;
        B = -B;
        C = -C;
    }

    std::cout << "Уравнение прямой: " << A << "x + " << B << "y + " << C << " = 0" << std::endl;

    return 0;
}
