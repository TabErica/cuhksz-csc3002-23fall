/* P1:
 * File: WildcardMatch.cpp
 * -----------------------
 * This program tests the wildcardMatch method, which
 * matches a filename against a pattern containing the wildcard
 * characters * and ?.
 */

#include <iostream>
#include <string>
// #include "CSC3002OJActive/assignment4/WildcardMatch.h" //for OJ test
//#include "WildcardMatch.h" // for local test
using namespace std;

/*
 * Method: wildcardMatch
 * Usage: if (wildcardMatch(filename, pattern)) . . .
 * --------------------------------------------------
 * This method checks to see whether filename matches the pattern,
 * which consists of three types of characters:
 *
 * 1. The character ?, which matches any single character
 * 2. The character *, which matches any string of characters
 * 3. Any other character, which matches only that character
 */

bool wildcardMatch(string filename, string pattern) {
   //TODO
   const char *fname = filename.c_str();
   const char *pat = pattern.c_str();
   const char *lastStar = nullptr;
   const char *lastMatch = nullptr;
   while (*fname)
   {
      if (*pat == '*')
      {
         lastStar = pat;
         lastMatch = fname;
         pat++;
      }
      else if (*pat == '?' || *pat == *fname) 
      {
         pat++;
         fname++;
      } 
      else if (lastStar) 
      {
         pat = lastStar + 1;
         lastMatch++;
         fname = lastMatch;
      } 
      else 
      {
         return false;
      }
   }
   while (*pat == '*')
   {
      pat++;
   }
   return (*fname == '\0' && *pat == '\0');
}

/* DO NOT modify the main() part */

int main() {
   string in_pair, filename, pattern;
   bool matchResult;
   while(getline(cin,in_pair)){
      int sp = in_pair.find(' ');
      filename = in_pair.substr(0, sp);
      pattern = in_pair.substr(sp+1, in_pair.size());
      matchResult = wildcardMatch(filename, pattern);
      cout << boolalpha  << matchResult << endl;
    }
   return 0;
}