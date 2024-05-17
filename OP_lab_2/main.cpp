#include <iostream> 
#include <cmath>
#include <string>
using namespace std;


void secondMain();
void thirdMain();


// 1
int main() {
    double y, x;
    const double PI = 3.14159265358979;
    double a = 0.8 * PI;

    cout << "Введіть значення x:" << endl;
    cin >> x;

    if (x < 0) y = pow(x,2) + 1;
    else if (x > 1.4) y = x - 2.1;
    else y = cos(a * x);
    
    cout << "Результат: " << y << endl;

    cout << "--------------------------------------\n";
    secondMain();
    cout << "--------------------------------------\n";
    thirdMain();

    return 0;
}



// 2
void secondMain() {
    double y, x, f, tax, result = 0;
    string symb;

    cout << "Введіть тип робіт:" << endl;
    cin >> symb;
    cout << "Введіть число x:" << endl;
	cin >> x;

    if (x > 0) {
        if (symb == "A" || symb == "a") {
            f = fabs(sin(x) / 3.124 - cos(pow(x,2))) - 8.3 * sin(3*x);
            y = 100 * fabs(f+50);
            tax = f * 0.1;
            result = y - tax;
        }
        else if (symb == "B" || symb == "b") {
            f = fabs(cos(2*x)) / 1.12 - cos(3*x - 2) + 6.15;
            y = 150 * fabs(f+100);
            tax = f * 0.15;
            result = y - tax;
        }
        else if (symb == "C" || symb == "c") {
            f = sin(x) * pow(cos(x),2) * sin(x + 1.4) / 0.85 + 7.14;
            y = 100 * fabs(f+135);
            tax = f * 0.2;
            result = y - tax;
        }
        else cout << "Error" << endl;
    }
    else cout << "x має бути більше 0\n";

    if (result != 0) {
        cout << "Нарахована сума: " << y << endl;
        cout << "Сума податку: " << tax << endl;
        cout << "Сума до видачі: " << result << endl;
    }
}




// 3
void thirdMain() {
    int num;
    string name;
    
    cout << "Введіть номер студента:" << endl;
    cin >> num;

    switch (num) {
        case 1:
            name = "Пупкін В.С.";
            break;
        case 2:
            name = "Шевченко Т.Г.";
            break;
        case 3:
            name = "Коваленко А.С.";
            break;
        case 4:
            name = "Мельник Д.В.";
            break;
        case 5:
            name = "Витвицький Я.В.";
            break;
    
        default:
            cout << "Error";
            break;
    }
    cout << name << endl;
}