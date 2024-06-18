#include <iostream>

#include "Gronsfeld Cipher/include/gronsfeld.h"
#include "zeros and ones/include/encrypt_zeros_and_ones.h"
#include "zeros and ones/include/decrypted_zeros_and_ones.h"
#include "Polybius square/include/decrypt_polybius_square.h"
#include "Polybius square/include/encrypt_polybius_square.h"

void menu() {
    cout << "1 - Шифр Гронсфельда" << endl;
    cout << "2 - Шифровка последовательностей нулей и единиц" << endl;
    cout << "3 - Квадрат Полибия" << endl;

    int choice;

    cin >> choice;
    cin.ignore();

    printf("\033[2J");
    printf("\033[0;0f");

    if(choice == 1) {
        cout << "1 - Закодировать" << endl;
        cout << "2 - Расскодировать" << endl;

        cin >> choice;
        cin.ignore();

        printf("\033[2J");
        printf("\033[0;0f");

        if(choice == 1) {
            caesarCipher();
        }

        else{
            caesarDecipher();
        }
    }

    if(choice == 2) {
        cout << "1 - Закодировать" << endl;
        cout << "2 - Расскодировать" << endl;

        cin >> choice;
        cin.ignore();

        printf("\033[2J");
        printf("\033[0;0f");

        if(choice == 1) {
            zero_and_ones_encrypt();
        }

        else{
            zero_and_ones_decrypt();
        }
    }

    else {
        cout << "1 - Закодировать" << endl;
        cout << "2 - Расскодировать" << endl;

        cin >> choice;
        cin.ignore();

        printf("\033[2J");
        printf("\033[0;0f");

        if(choice == 1) {
            encrypt_polybius_square();
        }

        else {
            decrypt_polybius_square();
        }
    }
}

int main() {
    while(true) {
        menu();
    }
}