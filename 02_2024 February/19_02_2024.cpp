//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string str, int k){
        unordered_map<char,int> charFreq;
        for(auto ch: str){
            ++charFreq[ch];
        }
        
        priority_queue<int> freqPQ;
        for(auto entry: charFreq)
            freqPQ.push(entry.second);
        
        while(k--){
            int topFreq = freqPQ.top();
            freqPQ.pop();
            --topFreq;
            if(topFreq) freqPQ.push(topFreq);
        }
        
        int result = 0;
        while(!freqPQ.empty()){
            result += freqPQ.top() * freqPQ.top();
            freqPQ.pop();
        }
        
        return result;
    }
};






//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends