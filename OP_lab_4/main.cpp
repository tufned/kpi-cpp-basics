#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b;
    int sum = 0;

    cout << "Введіть a: ";
    cin >> a;
    cout << "Введіть b: ";
    cin >> b;

    if (a > b) {
        cout << "Error\n" << "a повинно бути менше b\n";
        return 0;
    }

    if (a > 0) {
        if (a % 2 == 0) a++;
        for (int i = a; i <= b; i = i + 2) {
            sum += pow(i, 2);
       }
    }
    else {
        cout << "Error\n" << "a має бути більше 0\n";
        return 0;
    }

    cout << sum << '\n';
    return 0;
}