#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
#include "strlib.h"
using namespace std;

/* Function prototypes */

string obenglobish (string word);
bool isVowel (char ch);
bool secondVowel (int i, string word);
bool isE (int i, string word);

/* Main program */

int main() {
    while (true) {
        string word = getLine ("Enter a word: ");
        if (word == "") break;
        string trans = obenglobish (word);
        cout << word << " -> " << trans << endl;
    }
    return 0;
}


string obenglobish(string word) {
    string translatedWord;
    for (int i = 0; i < word.length(); i++) {
        char ch = word[i];
        if (isVowel(ch)) {
            if (!secondVowel(i, word)) {
                if (!isE(i, word)) {
                    translatedWord += "ob";
                }
            }
        }
        translatedWord += ch;
    }
    return translatedWord;
}


bool isVowel(char ch) {
    switch(ch) {
        case 'a': case 'e': case 'i': case 'o': case 'u':
            return true;
        default:
            return false;
    }
}


bool secondVowel (int i, string word) {
    if (i != 0 && isVowel(word.at(i - 1))) {
        return true;
    } else return false;
}


bool isE (int i, string word) {
    if (i == word.length() - 1 && isVowel (word[i])) {
        return true;
    } else return false;
}
