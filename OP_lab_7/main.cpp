#include <iostream>
#include <cmath>
using namespace std;


// Задана дійсна матриця розміру m*n.
// Знайти середнє арифметичне найбільшого і найменшого значень її елементів.
// Поміняти місцями найбільше і найменше значення елементів.


int martixPrint(int (*array)[3], int m, int n);


int main() {
    const int m = 4;
    const int n = 3;
    int arr[m][n] = {{4, 0, -54}, {1, 75, 5}, {-34, 7, -1}, {3, 100, 378}};
    int iter = 1;
    int maxNum = arr[0][0];
    int maxNum_i[2];
    int minNum = arr[0][0];
    int minNum_i[2];

    martixPrint(arr, m, n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (iter < m*n) {
                if (maxNum < arr[i][j+1]) {
                    maxNum = arr[i][j+1];
                    maxNum_i[0] = i;
                    maxNum_i[1] = j+1;
                }
                if (minNum > arr[i][j+1]) {
                    minNum = arr[i][j+1];
                    minNum_i[0] = i;
                    minNum_i[1] = j+1;
                }
            }
            iter++;
        }
    }

    int averNum = (maxNum + minNum) / 2;
    cout << "середнє арифметичне: " << averNum << endl;

    arr[maxNum_i[0]][maxNum_i[1]] = minNum;
    arr[minNum_i[0]][minNum_i[1]] = maxNum;

    martixPrint(arr, m, n);

    return 0;
}


int martixPrint(int (*array)[3], int m, int n) {
    cout << "-------\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-------\n";
    return 0;
}

