//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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
/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
public:
    // Helper function to perform DFS traversal
    void dfs(Node* root, int depth, int& leafDepth, bool& isSameLevel) {
        if (root == nullptr)
            return;

        // If leaf node encountered
        if (root->left == nullptr && root->right == nullptr) {
            // If it's the first leaf node encountered, set leafDepth
            if (leafDepth == -1) {
                leafDepth = depth;
            }
            // If the current leaf node's depth is different from leafDepth, set isSameLevel to false
            else if (depth != leafDepth) {
                isSameLevel = false;
                return;
            }
        }

        // Recursively visit left and right subtrees
        dfs(root->left, depth + 1, leafDepth, isSameLevel);
        dfs(root->right, depth + 1, leafDepth, isSameLevel);
    }

    bool check(Node *root)
    {
        // If the tree is empty or has only one node, all leaf nodes are at the same level
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
            return true;

        int leafDepth = -1; // Initialize leaf depth to an invalid value
        bool isSameLevel = true; // Initialize flag to true

        // Perform DFS traversal to check leaf nodes' levels
        dfs(root, 0, leafDepth, isSameLevel);

        return isSameLevel;
    }
};


//{ Driver Code Starts.
// Driver program to test size function
int main()
{
    int t;
    cin>> t;
    getchar();
    while (t--)
    {
        string s;
        getline( cin, s );
        Node* head = buildTree( s );
        Solution obj;
        cout << obj.check(head) << endl;
    }
    return 0;
}

// } Driver Code Ends