#include <iostream>
#include <cmath>
using namespace std;



// task 1
long double fact(int N) {
    if (N < 0) return 0;
    if (N == 0) return 1;
    else return N * fact(N - 1);
}

double sh(double x, int iter) {
    double sum = 0;
    for (int i = 1; i < iter; i = i + 2) {
        sum += pow(x, i) / fact(i);
    }
    return sum;
}



// task 2
float e = 0.001, x;

float f(float s) {
    double n = tan(s) + 2;
    return n;
}

void hord(float* a, float* b) {
    float supremum = *a;
    float infinum = *b;
    while (fabs(supremum - infinum) > e) {
        infinum = supremum - (supremum - infinum) * f(supremum) / (f(supremum) - f(infinum));
        supremum = infinum - (infinum - supremum) * f(infinum) / (f(infinum) - f(supremum));
    }
    cout << "Значення за методом хорд:" << supremum << endl;
}

void perebor(float* a, float* b, float* c) {
    float i = 0;
    float x1 = *a;
    float x2 = *b;
    float st1 = *c;
    for(x1; x1 <= x2; x1 += st1) {
        if ((f(x1) * f(x1 + st1)) < 0 ) {
            cout << "Корінь за яким тотожність дійсна: " << x1 << endl;
        }
    }
}




int main() {
    // task 1
    double y;
    double y_2;
    double y_final;
    int iter = 10;

    for (float i = 0; i < 3; i = i + 0.5) {
        if (i >= 0 && i <= 1) {
            y = sh(i, iter) + sh(pow(i, 2), iter);
            y_2 = sinh(i) + sinh(pow(i, 2));
            y_final = y - y_2;


            cout << "i = " << i << endl;
            cout << "y = " << y << endl;
            cout << "y_2 = " << y_2 << endl;
            cout << "Похибка = " << y_final << endl;
            cout << "------" << endl;
        }
        else if (i > 1 && i <= 2) {
            y = pow(sh(i, iter), 2) / sh(i+2, iter);
            y_2 = pow(sinh(i), 2) / sinh(i+2);
            y_final = y - y_2;

            cout << "i = " << i << endl;
            cout << "y = " << y << endl;
            cout << "y_2 = " << y_2 << endl;
            cout << "Похибка = " << y_final << endl;
            cout << "------" << endl;
        }
    }


    // task 2
    float start, end, iter_2;

    cout << "Введіть значення a:";
    cin >> start;    
    cout << "Введіть значення b:";
    cin >> end;
    cout << "Введіть значення кроку:";
    cin >> iter_2;
    
    float* pl = &start;
    float* pr = &end;
    float* st = &iter_2;

    hord(pl, pr);
    perebor(pl, pr, st);
    

    return 0;
}