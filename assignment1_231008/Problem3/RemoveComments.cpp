/*
 * File: RemoveComments.cpp
 * ------------------------
 * Prints out a file after removing comments.
 */
// header file for local test
#include <iostream>
#include <iomanip>
//#include "CSC3002OJActive/assignment1/RemoveComments.h" //for OJ
#include "RemoveComments.h" //for local test
using namespace std;


/*
 * Function: removeComments
 * Usage: removeComments(is, os);
 * ------------------------------
 * Copies characters from the input stream is to the output stream os,
 * removing any comments it finds.  This program eliminates both the
 * / and // comment forms but does not check to see if those characters
 * are embedded within strings.
 */

void removeComments(istream & is, ostream & os) {
   //TODO
    char currentChar, nextChar;
    bool inBlockComment = false;
    bool inLineComment = false;

    while (is.get(currentChar)) {
        if (inBlockComment) {
            // If inside a block comment, check for end of comment */
            if (currentChar == '*' && is.get(nextChar) && nextChar == '/') {
                inBlockComment = false;
            }
        } else if (inLineComment) {
            // If inside a line comment, check for end of line
            if (currentChar == '\n') {
                inLineComment = false;
                os.put('\n');
            }
        } else {
            // Not inside any comment, check for start of comments
            if (currentChar == '/' && is.get(nextChar)) {
                if (nextChar == '*') {
                    inBlockComment = true; // Start of block comment
                } else if (nextChar == '/') {
                    inLineComment = true; // Start of line comment
                } else {
                    // Not a comment, output both characters
                    os.put(currentChar);
                    os.put(nextChar);
                }
            } else {
                // Not a comment, output the current character
                os.put(currentChar);
            }
        }
    }
}


void TestRemoveComments(){
    removeComments(cin, cout);
}

// DO NOT modify the main() function
/*
 * sample output format:
 * input:  test file // this is a comment
           test file / this is also a comment*/
/* output: test file
           test file
 */
int main(int argc, char* argv[]) {
    TestRemoveComments();
    return 0;
}

