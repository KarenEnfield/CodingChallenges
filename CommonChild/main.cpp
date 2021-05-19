/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

/* Complete the 'commonChild' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */
int dfsCommonChild(string source, vector<int> vLetterBucket[26], map< pair<int,int>, int > &mpNodeChild, int begin=0, int jbegin=0)
{
    //vector < pair<int,int> > vNodeStack;// dfs stack
    pair<int, int> pr;

    int retval = 0;
    int tempval = 0;

    for (int i=begin; i<source.length(); i++)
    {

        if (vLetterBucket[source[i]-'A'].size()>0) // there is a matching letter
        {

            for (int j = 0; j< vLetterBucket[source[i]-'A'].size(); j++)
            {  // make and dfs process all possible matching letter pairs
                if(vLetterBucket[source[i]-'A'][j]>=jbegin)
                {
                    pr = make_pair(i,vLetterBucket[source[i]-'A'][j]); // make a matched letter pair

                    // have we checked this pair before?
                    //cout<< "\nLetter '"<<source[i]<<"', i="<< i << " j="<<vLetterBucket[source[i]-'A'][j];
                    if (mpNodeChild.find(pr)!=mpNodeChild.end())
                    {
                        tempval = mpNodeChild[pr];
                        retval = max(retval,tempval);
                        //cout<< " found pair " << " retval:" << retval <<"\n";
                    }
                    else // not found, put pair on the stack
                    {
                    //vNodeStack.push(makepair);
                        tempval = 1 + dfsCommonChild(source, vLetterBucket, mpNodeChild, i+1, vLetterBucket[source[i]-'A'][j]+1);
                        retval = max(tempval, retval);
                        mpNodeChild[pr]= tempval;
                        //cout<< " added pair " <<" retval:"<<retval<<"\n";
                    }
                }
            }
        }
    }
    return retval;

}

int commonChild(string s1, string s2) {
    int retval = 0;

    map < pair<int,int>, int > memoMaxChildLength;  // memoization map of matching letter pairs s1[i]==s2[j] in a string and thier common children

    vector<int>  vLettersBucket[26];  // store s2 letter   s of in a hash bucket


    for (int i=0; i<s2.length(); i++)
        vLettersBucket[s2[i]-'A'].push_back(i); // store each letter in s2 in a hash bucket


    retval = dfsCommonChild(s1, vLettersBucket, memoMaxChildLength);

    return retval;


}

// Use O(M*n) algorithm for longest common substring 
// Longest Common Subsequence Algorithm using dynamic programming/ memoization.  
// If S[i]==S2[j] ? Matrix[i][j] = Matrix[i-1][j-1] : Matrix[i][j]= max(Matrix[i-1][j], Matrix[i][j-1].   
// Return Matrix[s1.length()-1][s2.length()-1], 
// where s1 and s2 are padded with " " because we need a padded row and column 
// initialized to zero to initialize the matrix for dyanamic programming.
int longestCommonChild(string s1, string s2)
{
    int i, j;
    vector< vector<int> > matrix;
    s1 = " " + s1;
    s2 = " " + s2;
    
    // initialize matrix
    matrix.resize(s2.length());
    for (i=0; i<s2.length(); i++)
        matrix[i].resize(s1.length());
        
    for (i=1; i<s2.length(); i++ ) // y
    {
        for (j=1; j<s1.length(); j++) // x
        {
            if (s1[j]==s2[i])
                matrix[i][j] = matrix[i-1][j-1] + 1;
            else
                matrix[i][j] = max(matrix[i][j-1], matrix[i-1][j]);
        }
    }
    return matrix[i-1][j-1]; // y , x 
}

int main()
{
    
    string s1 = "SHINCHAN";
    //getline(cin, s1);

    string s2 = "NOHARAAA";
    //getline(cin, s2);

    int result = longestCommonChild(s1, s2);

    cout << result << "\n";

    return 0;
}
