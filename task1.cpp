#include <iostream>
using namespace std;

int main() {
    
    double a, b, c, d;

    // Питаєм данні для змінних
    cout << "Введіть значення a: ";
    cin >> a;

    cout << "Введіть значення b: ";
    cin >> b;

    cout << "Введіть значення c: ";
    cin >> c;

    cout << "Введіть значення d: ";
    cin >> d;

    // все обчислив
    double result = ((15 * a + 312 * b) / 64) - (c * 120 + d * 121);

    // вивів результат
    cout << "Результат виразу: " << result << endl;

    return 0;
}

