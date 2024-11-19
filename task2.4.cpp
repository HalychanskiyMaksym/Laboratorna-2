#include <iostream>
#include <vector>
#include <cstdint>   

using namespace std;

// Функція для кодування байтів
void encodeBytes(const vector<uint8_t>& input, vector<uint8_t>& output) {
    size_t numBytes = input.size();
    output.resize(8); // створююєм 8 байт

    // Для кожного байта на позиції i вхідного масиву:
    for (size_t i = 0; i < numBytes; i++) {
        
        for (size_t j = 0; j < 8; j++) {
            
            bool bit = (input[i] >> j) & 1;
            
            output[j] |= (bit << i);  // Зсуваємо біт 
        }
    }
}

int main() {
    // Вхідний масив байтів
    vector<uint8_t> input = {0x1F, 0x2A, 0x3C, 0x4D, 0x5E, 0x6F, 0x7A, 0x8B}; // навів приклад байтів 

    // Перевіряємо чи кількість байтів кратна 8
    if (input.size() % 8 != 0) {
        cerr << "Вхідна послідовність байтів повинна мати довжину, кратну 8!" << endl;
        return 1;
    }

    // масив для результату
    vector<uint8_t> output;

    // Кодуємо байти
    encodeBytes(input, output);

    // Виводимо результат
    cout << "Вхідні байти: ";
    for (uint8_t byte : input) {
        cout << (int)byte << " ";  // Виводимо байти у десятковому форматі
    }
    cout << endl;

    cout << "Результат:";
    for (uint8_t byte : output) {
        cout << (int)byte << " ";  // Виводимо результат у десяткові
    }
    cout << endl;

    return 0;
}
