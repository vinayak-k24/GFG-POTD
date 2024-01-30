//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    int countValidGroupings(int currentPosition, int currentSum, int size, const string& s, vector<vector<int>>& dp) {
        if (currentPosition == size) 
            return 1;
            
        if (dp[currentPosition][currentSum] != -1) 
            return dp[currentPosition][currentSum];
            
        int sum = 0, count = 0;

        for (int i = currentPosition; i < size; i++) {
            sum += s[i] - '0';
            if (sum >= currentSum) 
                count += countValidGroupings(i + 1, sum, size, s, dp);
        }

        return dp[currentPosition][currentSum] = count;
    }

    int TotalCount(string str) {
        int totalSum = 0;
        for (auto digit : str) 
            totalSum += digit - '0';
			
        vector<vector<int>> dp(str.size() + 1, vector<int>(totalSum + 1, -1));

        return countValidGroupings(0, 0, str.size(), str, dp);
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends