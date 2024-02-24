//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
        unordered_map<int, int> memo;
        
        int maxSumUtil(int n)
        {
            if (n == 0) return 0;
            if (memo.find(n) != memo.end()) return memo[n];

            int sum = max(n, maxSumUtil(n/2) + maxSumUtil(n/3) + maxSumUtil(n/4));
            memo[n] = sum;
            return sum;
        }

        int maxSum(int n)
        {
            return maxSumUtil(n);
        }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends