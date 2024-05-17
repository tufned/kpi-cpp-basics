#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a;
    int b;

    cout << "Введіть довжину arr_1: \n";
    cin >> a;
    cout << "Введіть довжину arr_2: \n";
    cin >> b;

    int arr_1[a];
    int arr_2[b];

    for (int i = 0; i < a; i++) {
        arr_1[i] = rand() % 30;
        cout << arr_1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < b; i++) {
        arr_2[i] = rand() % 30;
        cout << arr_2[i] << " ";
    }
    cout << endl << "------------" << endl;


    if (a == b) {
        int extra[a];

        cout << "arr_1: ";
        for (int i = 0; i < a; i++) {
            extra[i] = arr_1[i];
            arr_1[i] = arr_2[i];
            cout << arr_1[i] << " ";
        }
        cout << endl << "arr_2: ";
        for (int i = 0; i < a; i++) {
            arr_2[i] = extra[i];
            cout << arr_2[i] << " ";
        }

        int vecSum = 0;
        for (int i = 0; i < a; i++) {
            vecSum += arr_1[i] * arr_2[i];
        }
        cout << endl << endl << "Скалярний добуток = " << vecSum << endl;
    }


    return 0;
}























































































































































// Cornaga lox