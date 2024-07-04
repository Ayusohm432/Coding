/*
Problem lInk :- https://www.geeksforgeeks.org/problems/duplicate-subtrees/1
*/
/*Duplicate Subtrees

Given a binary tree, your task is to find all duplicate subtrees from the given binary tree.

Duplicate Subtree : Two trees are duplicates if they have the same structure with the same node values.

Note:  Return the root of each tree in the form of a list array & the driver code will print the tree in pre-order tree traversal in lexicographically increasing order.

Examples:

Input : 
 
Output: 2 4   
        4
Explanation: The above tree have two duplicate subtrees.i.e 
  2
 /
4  and 4. Therefore, you need to return the above tree root in the form of a list.  
Input:     5
          / \
         4   6
        / \
       3   4
          / \
         3   6
Output: 
3
6
Explanation: In the above tree, there are two duplicate subtrees.i.e
3 and 6. Therefore, you need to return the above subtrees root in the form of a list. Here, 4 3  is not considered because for a subtree to be equal, it should have the same values as well as structure. If we consider the first subtree on the left, it has  
two children, 3 on the left and 4 3 6   on the right. And for the second subtree it has 3 on the left and 6 on the right.
Since the structures are not same for the subtrees hence they are not equal
Expected Time Complexity: O(n)
Expected Space Complexity: O(n)

Constraints:
1<= height of binary tree <=103


*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating veactor of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = "";
        currVal += ip[i];

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

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void preorder(Node* root, vector<int>& temp) {
    if (!root) {
        return;
    }
    // cout<<root->data<<" ";
    temp.push_back(root->data);
    preorder(root->left, temp);
    preorder(root->right, temp);
}


// } Driver Code Ends
class Solution {
  public:
    string help(Node* root , vector<Node*>& result , unordered_map<string,int>& mp){
        if(!root){
            return "#";
        }
        
        string temp = to_string(root->data)+' '+help(root->left,result,mp)+' '+help(root->right,result,mp);
        if(mp[temp] == 1){
            result.push_back(root);
        }
        mp[temp]++;
        return temp;
        
    }
    
    
    vector<Node*> printAllDups(Node* root) {
        // Code here
        vector<Node*> result;
        unordered_map<string,int> mp;
        help(root,result,mp);
        return result;
    }
};

//{ Driver Code Starts.

int main() {

    int tc;
    cin >> tc;
    while (tc--) {

        string treeString;
        getline(cin >> ws, treeString);

        Node* root = buildTree(treeString);
        Solution obj;
        vector<Node*> res = obj.printAllDups(root);

        vector<vector<int>> ans;

        for (int i = 0; i < res.size(); i++) {
            vector<int> temp;
            preorder(res[i], temp);
            ans.push_back(temp);
        }

        sort(ans.begin(), ans.end());

        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
        // cout<<"\n";
    }
    return 0;
}

// } Driver Code Ends