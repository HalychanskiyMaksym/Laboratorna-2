#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <vector>
#include <cstdint>  

using namespace std;

const int MAX_LEN = 32;
const int NUM_LINES = 4;

// обчислюєм біти парності
bool calculateParity(uint16_t data) {
    int count = 0;
    while (data) {
        count += data & 1;
        data >>= 1;
    }
    return count % 2 == 0;
}

// шифруєм символ
uint16_t encryptCharacter(int line, int position, char ch) {
    uint8_t ascii = static_cast<uint8_t>(ch); // отримуємо ASCII код символу
    bool parity = calculateParity((line << 12) | (position << 7) | ascii);
    
    uint16_t encrypted = (line << 14) | (position << 7) | ascii;
    encrypted |= (parity << 15);  // встановлюємо біт парності
    return encrypted;
}

int main() {
    // беремо данні з файла на компі
    ifstream inputFile("C:/Users/Maks/Desktop/1put.txt ");
    if (!inputFile) {
        cerr << "Помилка відкриття файлу!" << endl;
        return 1;
    }

    vector<string> lines(NUM_LINES);
    string line;
    
    // зчитуєм текст
    for (int i = 0; i < NUM_LINES; ++i) {
        getline(inputFile, line);
        // Доповнюємо рядок пробілами 
        if (line.length() < MAX_LEN) {
            line.append(MAX_LEN - line.length(), ' ');
        }
        lines[i] = line;
    }

    
    inputFile.close();

    // Відкриваємо файл
    ofstream outputFile("C:/Users/Maks/Desktop/1out", ios::binary);
    if (!outputFile) {
        cerr << "Помилка відкриття бінарного файлу для запису!" << endl;
        return 1;
    }

    // Шифруємо і записуємо дані
    for (int i = 0; i < NUM_LINES; ++i) {
        for (int j = 0; j < MAX_LEN; ++j) {
            uint16_t encrypted = encryptCharacter(i, j, lines[i][j]);
            outputFile.write(reinterpret_cast<char*>(&encrypted), sizeof(encrypted));
        }
    }

    
    outputFile.close();
    
    cout << "Дані успішно зашифровані ." << endl;

    return 0;
}
