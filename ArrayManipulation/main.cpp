/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &); 
 
 /*
 * Complete the 'arrayManipulation' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 */

//
// Cumulative Array, Operate on first element, reverse after last
//
// Add on first element, and subtraction after last element
//
// Returns the greatest value in the manipulation array after all operations
// 
// Instead of performing repeated operation on each array entry in range,
// Perform the addition on the first member of the array, and subtraction on
// the element past the last member of the array.  
// We are instead keeping a running total of each operation in the array!
//

long arrayManipulation(int n, vector<vector<int>> queries) {

    long retval = 0L;
    long currval = 0L;
    int i;
    
    vector<long> v(n+1); // add extra for inclusive ending
    
    for (i=0; i<queries.size(); i++)
    {
        // Brute force performed operations on all memebers of the array
        //for (int j=queries[i][0]; j<=queries[i][1]; j++) // inclusive
        //    v[j-1] += queries[i-1][2]; // one-based
        
        //  Refinement performs an add on the first element, and subtracts
        // after the last element in the range.
        // 
        v[queries[i][0]-1] += queries[i][2];
        v[queries[i][1]] -= queries[i][2];
    }
    // iterate through the array tracking the total values, mindful of the 
    // maximum for returning.
    
    for (i=0; i<n; i++)
    {
        currval += v[i];
        retval = max(retval, currval);
    }
    
    return retval;    
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> queries(m);

    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    long result = arrayManipulation(n, queries);

    cout << result << "\n";


    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
