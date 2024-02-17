//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int isPossible(vector<vector<int>>& paths){
        int n = paths.size();
        // Check if the graph is connected
        if (!isConnected(paths)) {
            return 0;
        }

        // Check if all vertices have even degree
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += paths[i][j];
            }
            if (sum % 2 != 0) {
                return 0;
            }
        }

        return 1;
    }

    bool isConnected(vector<vector<int>>& paths) {
        int n = paths.size();
        vector<bool> visited(n, false);

        // Find a vertex with non-zero degree
        int startVertex = 0;
        for (int i = 0; i < n; i++) {
            int sum = accumulate(paths[i].begin(), paths[i].end(), 0);
            if (sum > 0) {
                startVertex = i;
                break;
            }
        }

        // Perform DFS starting from the first non-zero degree vertex
        stack<int> s;
        s.push(startVertex);
        while (!s.empty()) {
            int vertex = s.top();
            s.pop();
            if (!visited[vertex]) {
                visited[vertex] = true;
                for (int i = 0; i < n; i++) {
                    if (paths[vertex][i] == 1 && !visited[i]) {
                        s.push(i);
                    }
                }
            }
        }

        // Check if all vertices are visited
        for (int i = 0; i < n; i++) {
            if (!visited[i] && accumulate(paths[i].begin(), paths[i].end(), 0) > 0) {
                return false;
            }
        }

        return true;
    }
};




//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>paths(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> paths[i][j];
		}
		Solution obj;
		int ans = obj.isPossible(paths);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int isPossible(vector<vector<int>>& paths){
        int n = paths.size();
        // Check if the graph is connected
        if (!isConnected(paths)) {
            return 0;
        }

        // Check if all vertices have even degree
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += paths[i][j];
            }
            if (sum % 2 != 0) {
                return 0;
            }
        }

        return 1;
    }

    bool isConnected(vector<vector<int>>& paths) {
        int n = paths.size();
        vector<bool> visited(n, false);

        // Find a vertex with non-zero degree
        int startVertex = 0;
        for (int i = 0; i < n; i++) {
            int sum = accumulate(paths[i].begin(), paths[i].end(), 0);
            if (sum > 0) {
                startVertex = i;
                break;
            }
        }

        // Perform DFS starting from the first non-zero degree vertex
        stack<int> s;
        s.push(startVertex);
        while (!s.empty()) {
            int vertex = s.top();
            s.pop();
            if (!visited[vertex]) {
                visited[vertex] = true;
                for (int i = 0; i < n; i++) {
                    if (paths[vertex][i] == 1 && !visited[i]) {
                        s.push(i);
                    }
                }
            }
        }

        // Check if all vertices are visited
        for (int i = 0; i < n; i++) {
            if (!visited[i] && accumulate(paths[i].begin(), paths[i].end(), 0) > 0) {
                return false;
            }
        }

        return true;
    }
};




//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>paths(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> paths[i][j];
		}
		Solution obj;
		int ans = obj.isPossible(paths);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends