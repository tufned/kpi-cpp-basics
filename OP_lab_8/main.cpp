#include <iostream>
#include <vector>
using namespace std;

// У рядку символів визначити слова-паліндроми, які однаково читаються справа наліво і навпаки.
// Знайти найбільшу довжину цих слів.
// Якщо таких слів немає, то з кожного слова на непарній позиції вилучити голосні та надрукуйте їх.


void palindromeSearch();
void lengthСounting();
void palindromeNotFound();

const char str[] = "lorem ipsum dolor sit amet"; // without palindrome words
//const char str[] = "lorom tenet olso edle olololo ele temp bed dad gg"; // with palindrome words
vector<char> arr;
vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};


int main() {
    cout << "hole string: " << str << endl;
    palindromeSearch();

    if (arr.size() == 0) palindromeNotFound();
    else lengthСounting();

    return 0;
}



void palindromeSearch() {
    vector<char> palindWords;
    int k;
    int count = 0;

    for (int i = 0; i <= strlen(str); i++) { // перебираємо по буквах рядок
        if (*(str+i) == ' ' || i == strlen(str)) {
            k = palindWords.size();
            count = 0;
            for (int j = 0; j < palindWords.size(); j++) {
                k--;
                if (palindWords[j] == palindWords[k]) count++;
            }
            if (count == palindWords.size()) {
                for (int j = 0; j < palindWords.size(); j++) {
                    arr.push_back(palindWords[j]);
                }
                arr.push_back(' ');
            }
            if (i != strlen(str)) palindWords = {};
        }
        else if (*(str+i) != ' ' || i != strlen(str)) {
            palindWords.push_back(*(str+i));
        }
    }
}




void lengthСounting() {
    vector<int> wordLen_arr;
    int wordLen = 0;
    cout << "palindrome words: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i]; // виводимо в консоль слова-паліндроми

        if (arr[i] == ' ') { // визначаємо довжину кожного слова
            wordLen_arr.push_back(wordLen);
            wordLen = 0;
        }
        else wordLen++;
    }
    cout << endl;


    int bigInt;
    for (int i = 0; i < wordLen_arr.size(); i++) { // визначаємо найбільшу довжину серед слів
        if (i == 0) bigInt = wordLen_arr[i];
        if (bigInt < wordLen_arr[i+1] && i != wordLen_arr.size() - 1) {
            bigInt = wordLen_arr[i+1];
        }
    }
    cout << "the biggest length: " << bigInt << " "; // виведення в консоль найбільшої довжини


    vector<char> bigInt_word;
    for (int i = 0; i < arr.size(); i++) { // визначення слова з найбільшою довжиною
        if (arr[i] == ' ') {
            if (bigInt_word.size() == bigInt) break;
            else bigInt_word = {};
        }
        else bigInt_word.push_back(arr[i]);
    }


    for (int i = 0; i < bigInt_word.size(); i++) { // виведення слова з найбільшою довжиною
        cout << bigInt_word[i];
    }
}



void palindromeNotFound() {
    vector<char> vowels_cur;
    int count = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (*(str+i) == ' ' || i == strlen(str) - 1) {
            count++;

            if (count % 2 != 0) {
                for (int j = 0; j < vowels.size(); j++) { // визначаємо чи є символ голосною буквою
                    if (*(str+i) == vowels[j]) vowels_cur.push_back(*(str+i));
                }
                for (int j = 0; j < vowels_cur.size(); j++) { // виводимо в консоль визначені голосні
                    cout << vowels_cur[j] << " ";
                }
                cout << endl;
            }
            else if (count % 2 == 0 && i != strlen(str) - 1) vowels_cur = {};
        }
        else if (*(str+i) != ' ' || i != strlen(str) - 1) {
            for (int j = 0; j < vowels.size(); j++) {
                if (*(str+i) == vowels[j]) vowels_cur.push_back(*(str+i));
            }
        }
    }
}