#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// Увести з клавіатури декілька рядків тексту та записати їх у текстовий файл.
// Визначити в кожному рядку кількість слів і розділових символів.
// Дописати значення кількості слів на початок кожного рядка, значення кількості розділових символів в кінець рядка файлу.



//void rowsSetup(string str);
void rowsInit(string str);
void rowsCalc();
void rowsRender(vector<string> arr);

vector<string> strArr;
vector<char> punctuation = {'.', ',', '!', '?', ':', ';', '-', '_', '(', ')'};

int main() {
    string mainString;
    cout << "enter text (для виходу введіть out):" << endl;
    rowsInit(mainString);

//    string = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, "
//             "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. "
//             "Dui accumsan sit amet nulla facilisi morbi tempus iaculis. "
//             "Vitae, congue; mauris: rhoncus? aenean vel. ";

    string ans;
    cout << "Провести форматування? (y/n)" << endl;
    cin >> ans;
    if (ans.find('y') != -1) rowsCalc();

    return 0;
}


void rowsInit(string str) {
    getline(cin, str);

    if (str.find("out") == -1) strArr.push_back(str);
    if (str.find("out") != -1) rowsRender(strArr);
    else rowsInit(str);
}




void rowsCalc() {
    string curStr;
    int wordCount = 0;
    int punctCount = 0;
    strArr = {};


    ifstream input("../output.txt");
    if (input.is_open()) {
        while (getline(input, curStr)) {
            strArr.push_back(curStr);
        }
    }
    input.close();


    for (int i = 0; i < strArr.size(); i++) {
        wordCount = 0;
        punctCount = 0;

        for (int j = 0; j < strArr[i].length(); j++) {
            if (strArr[i][j] == ' ' || j == strArr[i].length() - 1) wordCount++;

            for (int k = 0; k < punctuation.size(); k++) {
                if (strArr[i][j] == punctuation[k]) punctCount++;
            }
        }
        strArr[i] = to_string(wordCount) + " | " + strArr[i] + " | " + to_string(punctCount);
    }

    rowsRender(strArr);
}


void rowsRender(vector<string> arr) {
    ofstream output;
    output.open("../output.txt");
    if (output.is_open()) {
        cout << endl << "Операція запису пройшла успішно!" << endl;
        for (int i = 0; i < arr.size(); i++) {
            output << arr[i] << endl;
        }
    }
    output.close();
}