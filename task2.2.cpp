#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

const int MAX_LEN = 32;
const int NUM_LINES = 4;

// Функція для розшифрування одного шифрованого значення
char decryptCharacter(uint16_t encrypted) {
    // Ігноруємо біт парності, він знаходиться в старшому біті (бит 15)
    uint8_t ascii = encrypted & 0x7F; // Отримуємо ASCII код символу, маскуємо 7 молодших бітів
    return static_cast<char>(ascii);
}

int main() {
    // Відкриваємо бінарний файл для зчитування зашифрованих даних
    ifstream inputFile("C:/Users/Maks/Desktop/1out", ios::binary);  // вказати правильний шлях до файлу
    if (!inputFile) {
        cerr << "Помилка відкриття бінарного файлу!" << endl;
        return 1;
    }

    vector<string> lines(NUM_LINES, string(MAX_LEN, ' '));

    // Зчитуємо зашифровані дані і розшифровуємо їх
    for (int i = 0; i < NUM_LINES; ++i) {
        for (int j = 0; j < MAX_LEN; ++j) {
            uint16_t encrypted;
            inputFile.read(reinterpret_cast<char*>(&encrypted), sizeof(encrypted));

            if (!inputFile) {
                cerr << "Помилка при зчитуванні файлу!" << endl;
                return 1;
            }

            char decrypted = decryptCharacter(encrypted);
            lines[i][j] = decrypted;
        }
    }

    // Закриваємо вхідний файл
    inputFile.close();

    // Виводимо розшифровані дані на екран
    cout << "Розшифровані дані:" << endl;
    for (const string& line : lines) {
        cout << line << endl;
    }

    // Записуємо розшифровані дані у новий текстовий файл
    ofstream outputFile("C:/Users/Maks/Desktop/1out.txt");  // вказати правильний шлях до файлу
    if (!outputFile) {
        cerr << "Помилка відкриття файлу для запису!" << endl;
        return 1;
    }

    for (const string& line : lines) {
        outputFile << line << endl;
    }

    // Закриваємо вихідний файл
    outputFile.close();
    
    cout << "Розшифровані дані записано в 'decrypted.txt'." << endl;

    return 0;
}
