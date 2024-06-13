#include <iostream>

#include "Gronsfeld Cipher/include/gronsfeld.h"
#include "zeros and ones/include/encrypt_zeros_and_ones.h"
#include "zeros and ones/include/decrypted_zeros_and_ones.h"

void menu() {
    cout << "1 - Шифр Гронсфельда" << endl;
    cout << "2 - Матричная шифровка" << endl;
    cout << "3 - Шифровка последовательностей нулей и единиц" << endl;

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
}

int main() {
    while(true) {
        menu();
    }
}