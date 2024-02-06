//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}



// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//Node Structure
/*struct NodeGiven a binary tree with n nodes and a non-negative integer k, the task is to count the number of special nodes. A node is considered special if there exists at least one leaf in its subtree such that the distance between the node and leaf is exactly k.
{
	int data;
	Node *left, *right;
};*/

class Solution
{
public:
    // Function to find the number of special nodes
    int printKDistantfromLeaf(Node* root, int k)
    {
        int specialCount = 0; // Initialize count of special nodes
        
        // Helper function to perform DFS traversal and find special nodes
        function<void(Node*, vector<int>&, int)> dfs = [&](Node* node, vector<int>& path, int dist) {
            if (!node) // Base case: null node
                return;
            
            path.push_back(node->data); // Add current node to the path
            
            if (!node->left && !node->right) { // If leaf node is reached
                if (path.size() > dist && path[path.size() - dist - 1] != -1) { // Check if distance is valid and ancestor hasn't been marked
                    specialCount++; // Increment count if the ancestor is not marked as special
                    path[path.size() - dist - 1] = -1; // Mark ancestor as visited
                }
            }
            
            // Recursive calls for left and right subtrees
            dfs(node->left, path, dist);
            dfs(node->right, path, dist);
            
            path.pop_back(); // Backtrack: Remove current node from the path
        };
        
        vector<int> path; // Path to store ancestors
        
        // Perform DFS traversal to find special nodes
        dfs(root, path, k);
        
        return specialCount; // Return count of special nodes
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s, ks;
        getline(cin, s);
        Node* root = buildTree(s);
        getline(cin, ks);
        int k=stoi(ks);
        Solution obj;
        cout<<obj.printKDistantfromLeaf(root, k)<<endl;
    }
    return 0;
}


// } Driver Code Ends