//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
public:
    void generateSubsequences(string s, int index, string curr, vector<string>& result) {
        if (index == s.length()) {
            if (!curr.empty()) {
                result.push_back(curr);
            }
            return;
        }
        
        generateSubsequences(s, index + 1, curr + s[index], result);
        generateSubsequences(s, index + 1, curr, result);
    }
    
    vector<string> AllPossibleStrings(string s){
        vector<string> result;
        generateSubsequences(s, 0, "", result);
        sort(result.begin(), result.end());
        return result;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends