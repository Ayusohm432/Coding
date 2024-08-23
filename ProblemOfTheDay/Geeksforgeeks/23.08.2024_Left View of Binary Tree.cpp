/*
Problem Link ;- https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1
*/


/*Left View of Binary Tree

Given a Binary Tree, return Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument. If no left view is possible, return an empty tree.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   

Examples :

Input:
   1
 /  \
3    2
Output: 1 3

Input:

Output: 10 20 40
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
0 <= Number of nodes <= 105
0 <= Data of a node <= 105

*/

//{ Driver Code Starts
// #include <bits/stdc++.h>
#include<iostream>
#include<queue>
#include<stack>
#include<unordered_map>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

vector<int> leftView(struct Node *root);

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

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
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


int main() {
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        vector<int> vec = leftView(root);
        for(int x : vec)
        cout<<x<<" ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends


/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
void help(Node* root , vector<int>& ans , int level , unordered_map<int,int>& mp){
    if(!root){
        return;
    }
    if(!mp[level]){
        ans.push_back(root->data);
        mp[level] = 1;
    }
    level++;
    help(root->left , ans , level , mp);
    help(root->right , ans , level , mp);
    
}
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   unordered_map<int,int> mp;
   help(root , ans , 0 , mp);
   return ans;
}
