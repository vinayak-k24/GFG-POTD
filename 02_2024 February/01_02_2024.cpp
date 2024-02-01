//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
public:
    // Function to check if a string is Pangram or not.
    bool checkPangram(string s)
    {
        // Create a boolean array to mark the presence of each letter in the alphabet.
        vector<bool> present(26, false);

        // Traverse the string and mark the presence of each letter.
        for (char ch : s)
        {
            if (isalpha(ch))
            {
                // Convert the letter to lowercase and mark its presence.
                present[tolower(ch) - 'a'] = true;
            }
        }

        // Check if all the letters are present.
        return all_of(present.begin(), present.end(), [](bool val) { return val; });
    }
};





//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends