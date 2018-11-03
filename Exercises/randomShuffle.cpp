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

/* Function prototypes */

string randomShuffle(string input);

/* Main program */

int main() {
    string input;
    while(true) {
        cout << "Enter a string: ";
        cin >> input;
        cout << randomShuffle(input) << endl;
    }
    return 0;
}

string randomShuffle(string input) {
    if(input == "") {
        return input;
    } else {
        int a = randomInteger(0, input.length() - 1);
        return input[a] + randomShuffle(input.substr(0, a) + input.substr(a + 1));
    }
}
