#include <iostream>
#include <math.h>
using namespace std;

long double fact(int N) {
    if (N < 0) return 0; 
    if (N == 0) return 1; 
    else return N * fact(N - 1); 
}
 

int main() {
    int n = 0;
    double sum;
    double res = 1;
    double x;
    int in_fact;
    
    cout << "Введіть х:" << endl;
    cin >> x;

    if (x < 0 || x > 4) {
        cout << "error" << endl << "x є [0,4]" << endl;
        return 0;
    }
 
    while (fabs(res) > pow(10, -4)) {
        in_fact = 2*n;
        res = pow(-1,n) * pow(x, 2*n) / fact(in_fact); 
        sum += res;
        n++;
    }
 
    cout << sum << endl;
    return 0;
}