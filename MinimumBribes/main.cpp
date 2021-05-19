#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumBribes' function below.
 *
 * The function accepts INTEGER_ARRAY q as parameter.
 */
 
// Sort everybody back in thier original position
// doing a modified bubble sort and count the swaps.
//
// A person is no more than two positions ahead of its original position.
// Conversely, a person may be very far back from their original spot.
// Start from the back of the array looking for a posiiton mismatch: a[i] != i;
// Look one or two spots ahead for the match and swap into place, counting swaps
// People far behind from their original position will be successively swapped 
// forward, "bubbled up" in the process.
//

void minimumBribes(vector<int> q) {
    int bribes = 0;
    int tmp;
    // first make it a 1-based array by inserting a zero for code clarity
    q.emplace(q.begin(),0);
    
    // Bribes = swaps.  no number will be more than 2 ahead of its position
    // Lets start from the back and bubble up
    
    for (int i=q.size()-1; i>0; i--)
    {
        if (q[i]!=i) // Element is not in its correct position.  Find it.
        {   
            tmp = q[i];
            if (q[i-1]==i)  // Found it one position ahead.  Swap!
            {
                q[i] = q[i-1];
                q[i-1] = tmp;
                bribes ++;
            }
            else if (q[i-2]==i) // Found it two positions ahead.  Swap twice!
            {                   // i, i-1, i-2 ==> i-2, i, i-1
                q[i]=q[i-2];
                q[i-2] = q[i-1];    
                q[i-1] = tmp;
                bribes += 2;
            }
            else            // More than two bribes happened.  Exit
            {
                cout << "Too chaotic\n";
                return;
            }
        } // else do nothing if it is in its correct position
    }
    cout << bribes << "\n";
    
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split(rtrim(q_temp_temp));

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

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
