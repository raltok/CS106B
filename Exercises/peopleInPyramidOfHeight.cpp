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

int peopleInPyramidOfHeight(int n);

/* Main program */

int main() {
    int a;
    while(true) {
        cout << "Enter Pyramid Height: ";
        cin >> a;
        cout << peopleInPyramidOfHeight(a) << endl;
    }
    return 0;
}

int peopleInPyramidOfHeight(int n) {
    if(n == 1) {
        return 1;
    } else {
        return n + peopleInPyramidOfHeight(n - 1);
    }
}
