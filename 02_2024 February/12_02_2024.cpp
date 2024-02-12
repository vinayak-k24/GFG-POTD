//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        const long long mod = 1e9 + 7;
        
        long long a = 1;
        long long sol = 0;
        
        for(int i = 1; i < n + 1; i++){
            long long vals = 1;
            
            for(int j = 0; j < i; j++){
                vals = (vals * (a++)) % mod;
            }
            
            sol = (sol + vals) % mod;
        }
        
        return sol;
    }
};





//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends