//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int atoi(string s) {
        int n = s.length();
        if (n == 0) return -1;  // Empty string, conversion not feasible
        
        int sign = 1;  // Default positive sign
        int i = 0;
        
        // Check for leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // Check for optional sign
        if (s[i] == '-') {
            sign = -1;
            i++;
        }
        
        // Convert remaining digits to integer
        int result = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            // Check for integer overflow
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return -1;
            }
            
            result = result * 10 + digit;
            i++;
        }
        
        // Check for non-numeric characters after the first character
        while (i < n && s[i] == ' ') {
            i++;
        }
        if (i < n) {
            return -1;
        }
        
        return sign * result;
    }
};






//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends