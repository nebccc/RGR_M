#include <iostream>
#include <stdexcept> // for std::runtime_error
#include "Gronsfeld Cipher/include/gronsfeld.h"
#include "zeros and ones/include/encrypt_zeros_and_ones.h"
#include "zeros and ones/include/decrypted_zeros_and_ones.h"
#include "Polybius square/include/decrypt_polybius_square.h"
#include "Polybius square/include/encrypt_polybius_square.h"

#define password "123"

using namespace std;

bool login() {
    string input_password;

    try {
        cout << "Введите пароль: ";
        getline(cin, input_password);

        if (input_password == password) {
            return true;
        } else {
            throw runtime_error("Неверный пароль!");
        }
    } catch (const exception& e) {
        cout << e.what() << endl;
        return false;
    }
}

void clearScreen() {
    // Эта функция очищает экран терминала
    printf("\033[2J");
    printf("\033[0;0f");
}

int getChoice(int min, int max) {
    int choice;
    bool valid = false;

    do {
        cin >> choice;
        cin.ignore();

        if (choice >= min && choice <= max) {
            valid = true;
        } else {
            cout << "Неверный выбор. Пожалуйста, выберите от " << min << " до " << max << ": ";
        }
    } while (!valid);

    return choice;
}

void gronsfeldMenu() {
    cout << "1 - Закодировать" << endl;
    cout << "2 - Раскодировать" << endl;
    cout << "0 - Выйти из выбора шифра" << endl;

    int choice = getChoice(0, 2);

    switch (choice) {
        case 1:
            caesarCipher();
            break;
        case 2:
            caesarDecipher();
            break;
        case 0:
            return; // выходим из функции
    }
}

void zeroAndOnesMenu() {
    cout << "1 - Закодировать" << endl;
    cout << "2 - Раскодировать" << endl;
    cout << "0 - Выйти из выбора шифра" << endl;

    int choice = getChoice(0, 2);

    switch (choice) {
        case 1:
            zero_and_ones_encrypt();
            break;
        case 2:
            zero_and_ones_decrypt();
            break;
        case 0:
            return; // выходим из функции
    }
}

void polybiusMenu() {
    cout << "1 - Закодировать" << endl;
    cout << "2 - Раскодировать" << endl;
    cout << "0 - Выйти из выбора шифра" << endl;

    int choice = getChoice(0, 2);

    switch (choice) {
        case 1:
            encrypt_polybius_square();
            break;
        case 2:
            decrypt_polybius_square();
            break;
        case 0:
            return; // выходим из функции
    }
}

void menu() {
    clearScreen();

    cout << "Выберите шифр:" << endl;
    cout << "1 - Шифр Гронсфельда" << endl;
    cout << "2 - Шифровка последовательностей нулей и единиц" << endl;
    cout << "3 - Квадрат Полибия" << endl;
    cout << "0 - Выход" << endl;

    int choice = getChoice(0, 3);

    switch (choice) {
        case 1:
            gronsfeldMenu();
            break;
        case 2:
            zeroAndOnesMenu();
            break;
        case 3:
            polybiusMenu();
            break;
        case 0:
            exit(0); // завершаем программу
    }
}

int main() {
    while (true) {
        if (login()) {
            while (true) {
                menu();
            }
        } else {
            cout << "Попробуйте еще раз." << endl;
        }
    }

    return 0;
}
