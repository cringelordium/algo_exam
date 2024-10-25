#include <iostream>
#include <cmath>

// Функция для нахождения НОД (наибольший общий делитель)
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

struct Vector {
    int x, y;
    
    // Скалярное произведение векторов
    int dot(const Vector& other) const {
        return x * other.x + y * other.y;
    }
    
    // Длина вектора
    double magnitude() const {
        return std::sqrt(x * x + y * y);
    }
};

int main() {
    Vector A = {-5, 12};
    Vector B = {8, 6};

    // Скалярное произведение
    int dotProduct = A.dot(B);
    
    // Произведение длин векторов
    double magnitudeProduct = A.magnitude() * B.magnitude();
    
    // Косинус угла в виде несократимой дроби
    int numerator = dotProduct;
    int denominator = static_cast<int>(magnitudeProduct);
    
    // Упрощение дроби
    int divisor = gcd(abs(numerator), abs(denominator));
    numerator /= divisor;
    denominator /= divisor;

    std::cout << "Cosine of angle between vectors: " << numerator << "/" << denominator << std::endl;

    return 0;
}
