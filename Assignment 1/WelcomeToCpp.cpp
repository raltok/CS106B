/*
 * File: WelcomeToCpp.cpp
 * --------------------------
 * This file is the starter project for the first assignment of CS106B.
 *
 * The repeating call sequence is
 *    triggerStackOverflow(137), which calls
 *    triggerStackOverflow(549), which calls
 *    triggerStackOverflow(327) which calls
 *    triggerStackOverflow(203) which calls
 *    triggerStackOverflow(685) which calls
 *    triggerStackOverflow(164) which calls
 *    triggerStackOverflow(137) again.
 */

// Please feel free to add any other #includes you need!
#include "WelcomeToCpp.h"
#include <iostream>
#include <string>
#include "strlib.h"
#include "random.h"
#include <cstdlib>
#include <cctype>
#import  "cmath"
#include <fstream>
#include "console.h"
#include "simpio.h"
#include <fstream>
#include "tokenscanner.h"
#include "strings.h"
using namespace std;


void flipHeads() {
    int heads = 0;
    int tails = 0;
    while(heads < 3) {
        if(randomChance(0.5)) {
            heads++;
            cout << "heads" << endl;
        } else {
            tails++;
            cout << "tails" << endl;
        }
    }
    cout << "It took " << heads + tails << " flips to get 3 consecutive heads." << endl;
}


int nChooseK(int n, int k) {
    if (n == k || k == 0) {
        return 1;
    } else {
        return nChooseK(n - 1, k - 1) + nChooseK(n - 1, k);
    }
}


int stringToInt(string str) {
    if (str[0] != '-') {
        if (str.length() < 2) {
            int val = str[0] - '0';
            return val;
        } else {
            int val = str[0] - '0';
            val = val * pow(10, str.length() - 1);
            str = str.erase(0, 1);
            return val + stringToInt(str);
        }
    } else {
        str = str.erase(0, 1);
        if (str.length() < 2) {
            int val = str[0] - '0';
            return -val;
        } else {
            int val = str[0] - '0';
            val = val * pow(10, str.length() - 1);
            str = str.erase(0, 1);
            return -(val + stringToInt(str));
        }
    }
}


string intToString(int n) {
    string result;
    if (n < 10 && n >=0) {
        string str(1, char (n + '0'));
        return str;
    } else {
        if (n < 0) {
            result += '-' + intToString((-n) / 10) + char ((-n) % 10 + '0');
            return result;
        } else {
            result += intToString(n / 10) + char (n % 10 + '0');
            return result;
        }
    }
}


DocumentInfo statisticsFor(istream& source) {
    DocumentInfo docInfo = {0, 0, 0};

    TokenScanner scanner(source);
    scanner.ignoreWhitespace();
    scanner.addWordCharacters("'");

    while(scanner.hasMoreTokens()){
        string token = scanner.nextToken();
        token = toLowerCase(token);
        if(token == "." || token == "!" || token == "?") {
            docInfo.numSentences++;
         }

        if(isalpha(token[0])) {
           docInfo.numWords++;
           docInfo.numSyllables += countSyllables(token);
         }
    }
    if (docInfo.numSentences == 0) docInfo.numSentences = 1;
    if (docInfo.numWords == 0) docInfo.numWords = 1;
    return docInfo;
}

int countSyllables(string token) {
    int num = 0;
    for (int i = 0; i < token.length(); i++) {
        char ch = token[i];
        if (isVowel(ch)) {
            if (!secondVowel(i, token)) {
                if (!isE(i, token)) {
                    num++;
                }
            }
        }
    }
    if(num == 0) num = 1;
    return num;
}


bool isVowel(char ch) {
    switch(ch) {
     case 'a': case 'e': case 'i': case 'o': case 'u': case 'y':
        return true;
     default:
        return false;
    }
}


bool secondVowel (int i, string token) {
    if (i != 0 && isVowel(token[i - 1])) {
        return true;
    } else return false;
}


bool isE (int i, string token) {
    if (i == token.length() - 1 && token[i] == 'e') {
        return true;
    } else return false;
}
