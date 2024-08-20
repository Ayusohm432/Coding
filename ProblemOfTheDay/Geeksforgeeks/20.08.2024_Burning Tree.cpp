/*
Problem Link :- https://www.geeksforgeeks.org/problems/burning-tree/1
*/

/*Burning Tree


Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.


Examples : 

Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value 8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.
Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      7
  /    / 
 8    10
Target Node = 10
Output: 5

Expected Time Complexity: O(number of nodes)
Expected Auxiliary Space: O(height of tree)


Constraints:
1 ≤ number of nodes ≤ 105

1 ≤ values of nodes ≤ 105


*/

//{ Driver Code Starts
//Initial Template for C++

// #include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include<string>
#include<sstream>
#include <vector>
#include <unordered_map>
#include<unordered_set>
#include<stack>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    unordered_map<int, int> map;  // For storing node value -> index in traversal
    
    int findNumberOfNodesInTree(Node* root) {
        stack<Node*> stk;
        Node* ptr = root;
        int ans = 0;
        
        while (true) {
            if (ptr != nullptr) {
                stk.push(ptr);
                ptr = ptr->left;
            } else {
                if (stk.empty()) break;
                Node* delNode = stk.top();
                stk.pop();
                map[delNode->data] = ans++;
                ptr = delNode->right;
            }
        }
        
        return ans;
    }

    void fillDepthArr(Node* root, vector<int>& depthArr, const unordered_set<int>& set) {
        if (root->left != nullptr) {
            fillDepthArr(root->left, depthArr, set);
            if (set.find(map[root->left->data]) == set.end()) {
                depthArr[map[root->data]] = max(depthArr[map[root->data]], depthArr[map[root->left->data]] + 1);
            }
        }
        if (root->right != nullptr) {
            fillDepthArr(root->right, depthArr, set);
            if (set.find(map[root->right->data]) == set.end()) {
                depthArr[map[root->data]] = max(depthArr[map[root->data]], depthArr[map[root->right->data]] + 1);
            }
        }
    }

    int minTime(Node* root, int target) {
        vector<vector<int>> adj;
        int numberOfNodes = findNumberOfNodesInTree(root);
        vector<int> parArr(numberOfNodes, -1);
        
        adj.resize(numberOfNodes);
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int sizeOfQueue = q.size();
            while (sizeOfQueue-- > 0) {
                Node* delNode = q.front();
                q.pop();
                
                if (delNode->left != nullptr) {
                    adj[map[delNode->data]].push_back(map[delNode->left->data]);
                    parArr[map[delNode->left->data]] = map[delNode->data];
                    q.push(delNode->left);
                }
                if (delNode->right != nullptr) {
                    adj[map[delNode->data]].push_back(map[delNode->right->data]);
                    parArr[map[delNode->right->data]] = map[delNode->data];
                    q.push(delNode->right);
                }
            }
        }

        vector<int> targetToRootPath;
        int ptr = map[target];
        while (ptr != -1) {
            targetToRootPath.push_back(ptr);
            ptr = parArr[ptr];
        }
        reverse(targetToRootPath.begin(), targetToRootPath.end());

        unordered_set<int> targetToRootPathNodesSet(targetToRootPath.begin(), targetToRootPath.end());
        
        vector<int> depthArr(numberOfNodes, 0);
        fillDepthArr(root, depthArr, targetToRootPathNodesSet);
        
        int ans = 0;
        int targetToRootPathSize = targetToRootPath.size();
        for (int i = 0; i < targetToRootPathSize; ++i) {
            ans = max(ans, targetToRootPathSize - i - 1 + depthArr[targetToRootPath[i]]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends