/*
 * File: BanishLetters.cpp
 * -----------------------
 * This program removes all instances of a set of letters from
 * an input file.
 */

#include <iostream>
//#include "CSC3002OJActive/assignment1/lib.h"
using namespace std;

int banishLetters() {
   // TODO
    string banishedChars;
    getline(cin, banishedChars); // Read the set of banned characters from input

    char c;
    bool banned = false;

    while (cin.get(c)) {
        // Check if the character is in the banned character set
        banned = (banishedChars.find(tolower(c)) != string::npos) || (banishedChars.find(toupper(c)) != string::npos);

        // If the character is not in the banned character set, output the character
        if (!banned) {
            cout.put(c);
        }

        // If the character is a newline, output a newline and reset the banned flag
        if (c == '\n') {
            banned = false;
            cout << endl;
        }
    }

    return 0;
}


/* DO NOT modify this main() part */
/*
 sample output:
 input: S
        this is a testing 1
        this is a testing 2
 output:
        thi i a teting 1
        thi i a teting 2
*/
int main(int argc, char* argv[]) {
    banishLetters();
    return 0;
}
