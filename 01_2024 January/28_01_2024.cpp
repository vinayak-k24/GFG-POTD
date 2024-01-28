//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    long long findNthNumber(long long n, long long k) {
        auto calculateNCR = [](long long n, long long r) -> long long {
            long long ans = 1;
            
            // n! / ((n - r)! * r!)
            
            for(long long i = n; i > max(r, n - r); i--)
                ans *= i;
                
            long long den = 1;
            
            for(long long i = 1; i <= min(r, n - r); i++)
                den *= i;
                
            ans /= den;
            
            return ans;
        };
        
        vector<vector<long long>> dp(63, vector<long long> (k + 1, 0));
        
        for(int i = 0; i < 63; i++){
            for(int j = 0; j < k + 1; j++){
                for(int x = 0; x <= min(i + 1, j); x++)
                    dp[i][j] += calculateNCR(i + 1, x);
            }
        }
        
        long long position = 0;
        
        for(int i = 0; i < 63; i++){
            if(dp[i][k] >= n){
                position = i;
                break;
            }
        }
        
        long long result = 0;
        while(position > -1 and n > 0){
            if(position + 1 <= k){
                result += n - 1;
                break;
            }
            
            if(position > 0 and dp[position - 1][k] < n){
                result |= (1LL << position);
                n -= dp[position - 1][k];
                k = max(k - 1, 0LL);
            }
            
            --position;
        }
        
        return result;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        Solution obj;
        long long res = obj.findNthNumber(n, k);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends