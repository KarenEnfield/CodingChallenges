/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

/*
 * Complete the 'twoStrings' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

//  letters in range a-z
//  TWO STRINGS O(N) only returns YES if a letter occurs in both strings
//  So we are going through each letter of the alphabet and when a letter occurs
//  in both strings, we stop and return YES, else we return NO
//

string twoStrings(string s1, string s2) {
    const int LETTERS = 26; // a-z 
    
    for (int i=0; i<LETTERS; i++)
    {
       if ( (s1.find_first_of('a'+i) != std::string::npos) && (s2.find_first_of('a'+i) != std::string::npos) )
            return "YES";  // a letter was found in both strings
    }

    return "NO";
    
}


int main()
{
    string s1, s2;
    s1 = "Hello";
    s2 = "Wrd";
    cout<<s1<< " "<<s2<<" ";
    cout << twoStrings(s1, s2);
    
    return 0;
}

