//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        vector<int> result;
        set<int> seen; // To keep track of already seen elements
        result.push_back(0); // First element is always 0
        seen.insert(0);
        
        for (int i = 1; i < n; i++) {
            int next = result[i - 1] - i;
            // If the calculated next number is positive and not already in the sequence
            if ((next > 0) && (seen.find(next) == seen.end())) {
                result.push_back(next);
                seen.insert(next);
            } else {
                // Otherwise, take the sum
                next = result[i - 1] + i;
                result.push_back(next);
                seen.insert(next);
            }
        }
        
        return result;
    }
};




//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends