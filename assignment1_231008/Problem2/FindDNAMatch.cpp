/* Q2: 
 * File: FindDNAMatch.cpp
 * ----------------------
 * This file solves the DNA matching exercise from the text.
 */
// header file for OJ system
// #include <iostream>
// #include <string>

// using namespace std;

#include <iostream>
#include <string>
//#include "CSC3002OJActive/assignment1/FindDNAMatch.h" //for OJ
//#include "FindDNAMatch.h" //for local test
using namespace std;


/*
 * Function: findDNAMatch
 * Usage: int pos = findDNAMatch(s1, s2);
 *        int pos = findDNAMatch(s1, s2, start);
 * ---------------------------------------------
 * Returns the first index position at which strand s1 would bind to
 * the strand s2, or -1 if no such position exists.  If the start
 * parameter is supplied, the search begins at that index position.
 */

int findDNAMatch(string s1, string s2, int start) {
   // TODO
   int l1 = s1.length();
   int l2 = s2.length();
   for (int i = start; i <= l2 - l1 + 1; i++)
   {
      bool match = true;
      for (int j = 0; j < l1; j++)
      {
         if (s1[j] != s2[i+j])
         {
            match = false; 
            break;
         }
      }
      if (match)
      {
         return i;
      }

   }
   return -1;
}

/*
 * Function: matchingStrand
 * Usage: string match = matchingStrand(strand);
 * ---------------------------------------------
 * Returns a string in which each base has been replaced by its
 * counterpart base (C <-> G and A <-> T).  Any other characters
 * are replaced by an X.
 */

string matchingStrand(string strand) {
   // TODO
   int l = strand.length();
   for (int i = 0; i < l; i++)
   {
      if (strand[i] == 'A')
         strand[i] = 'T';
      else if (strand[i] == 'T')
         strand[i] = 'A';
      else if (strand[i] == 'C')
         strand[i] = 'G';
      else if (strand[i] == 'G')
         strand[i] = 'C';
      else strand[i] = 'X';
   }
   return strand;
}


/*
 * Function: findAllMatches
 * Usage: findAllMatches(s1, s2);
 * ------------------------------
 * Finds all positions at which s1 can bind to s2.
 */

void findAllMatches(string s1, string s2) {
   // TODO
   string s2_match = matchingStrand(s2);
   int start = 0;
   int position = findDNAMatch(s1, s2_match, start);
   if (position == -1)
   {
      cout << s1 << " has no matches in " << s2 << endl;
      return;
   }
   else
   {      
      while (position != -1)
      {
         cout << s1 << " matches " << s2 << " at position " << position << endl;
         start = position + 1;
         position = findDNAMatch(s1, s2_match, start);
      }
   }
}

// DO NOT modify the main() function
/*
 * sample output:
 * input:  TTGCC TAACGGTACGTC
 * output: TTGCC matches TAACGGTACGTC at position 1
*/
int main(int argc, char* argv[]) {
    string s1, s2;
    cin >> s1 >> s2; 
    findAllMatches(s1, s2);
    return 0;
}
