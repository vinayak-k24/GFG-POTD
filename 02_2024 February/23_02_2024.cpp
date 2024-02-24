//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        int maxProfit(vector<int>& price){
            int n = price.size();
            if (n == 0) {
                return 0;
            }

            // Initialize profit arrays for transactions 1 and 2
            vector<int> profit1(n, 0);
            vector<int> profit2(n, 0);

            // Initialize variables to track minimum buy price
            int min_price1 = price[0];
            int min_price2 = price[0];

            // Calculate maximum profit for the first transaction
            for (int i = 1; i < n; i++) {
                min_price1 = min(min_price1, price[i]);
                profit1[i] = max(profit1[i - 1], price[i] - min_price1);
            }

            // Calculate maximum profit for the second transaction
            for (int i = 1; i < n; i++) {
                min_price2 = min(min_price2, price[i] - profit1[i]);
                profit2[i] = max(profit2[i - 1], price[i] - min_price2);
            }

            return profit2[n - 1];
        }
};






//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends