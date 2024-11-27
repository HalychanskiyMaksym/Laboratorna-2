#include <iostream>

int main() {
    int a, b, c, d;
    std::cout << "Enter integers a, b, c, d \n";
    std::cin >> a >> b >> c >> d;

    // Розрахунки без множення та ділення
    int term1 = (a << 4) - a; // 15 * a
    int term2 = (b << 8) + (b << 5) + (b << 4) + (b << 3); // 312 * b
    int divisionResult = (term1 + term2) >> 6; // (15 * a + 312 * b) / 64
    int term3 = (c << 7) - (c << 3); // 120 * c
    int term4 = (d << 7) - (d << 3) + d; // 121 * d

    int result = divisionResult - term3 + term4; // Підсумковий вираз

    std::cout << "Result: " << result << std::endl;
    return 0;
}