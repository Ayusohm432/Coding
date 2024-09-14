/*
Problem Link : https://unstop.com/code/practice/250288
*/

/*BST Puzzle


Problem Statement
Ashish was learning about the Binary Search Trees, which are special types of trees that satisfy these constraints :

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
His friend, Sarthak, saw him and thought of challenging him. He defined a transition as replacing each node of the tree with the original node plus the sum of all tree nodes greater than the original node in the tree.

Given a level order of Binary Search Tree of N integers in the input where -1 represents the null node, print the sum of all nodes after the transition of the Binary Search Tree. Since the answer can be too large, output it modulo (109 + 7).

Note: All the nodes in the BST are unique.

 

Input Format
The first line contains data of the tree’s nodes in the level order form. The data of the nodes of the tree are separated by space. If any node does not have a left or right child, take -1 in its place.

Output Format
Print the sum of all nodes of the Binary Search Tree after applying the transition modulo (10^9+7).

Constraints
1<=N<=105

1<=Ai<= 106, where ai is the value of nodes in the Binary Search Tree.

 

Sample Testcase 0
Testcase Input
2 1 3 -1 -1 -1 -1

Testcase Output
14

Explanation
The given Binary Search Tree is :
After the transition :
Node 2 : 2 + (3) = 5
Node 1 : 1 + (2 + 3) = 6
Node 3 : 3 + (0) = 3
Hence after the transition, the sum of all the nodes of the BST is 5 + 6 + 3 = 14.

Sample Testcase 1
Testcase Input
3 2 4 -1 -1 -1 5 -1 -1

Testcase Output
40
Explanation
The Given Binary Search Tree is :
After the transition :
Node 3 = 3 + (4+5) = 12
Node 4 = 4 + (5) = 9
Node 5 = 5 + (0) = 5
Node 2 = 2 + (3+4+5) = 14
Hence after the transition, the sum of all the nodes of the BST is 12 + 9 + 5 + 14 = 40

*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

const int MOD = 1e9 + 7;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to build BST from level-order input
TreeNode* buildBST(const vector<int>& levelOrder) {
    if (levelOrder.empty() || levelOrder[0] == -1) return NULL;
    
    TreeNode* root = new TreeNode(levelOrder[0]);
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    while (!q.empty() && i < levelOrder.size()) {
        TreeNode* current = q.front();
        q.pop();
        
        // Add left child
        if (i < levelOrder.size() && levelOrder[i] != -1) {
            current->left = new TreeNode(levelOrder[i]);
            q.push(current->left);
        }
        i++;
        
        // Add right child
        if (i < levelOrder.size() && levelOrder[i] != -1) {
            current->right = new TreeNode(levelOrder[i]);
            q.push(current->right);
        }
        i++;
    }
    
    return root;
}

// Function to perform reverse in-order traversal and update nodes
long long reverseInorder(TreeNode* root, long long& accSum) {
    if (!root) return 0;
    
    long long rightSum = reverseInorder(root->right, accSum);
    
    accSum = (accSum + root->val) % MOD;
    root->val = accSum;
    
    long long leftSum = reverseInorder(root->left, accSum);
    
    return (root->val + leftSum + rightSum) % MOD;
}

// Main function to solve the problem
long long solveBSTTransition(const vector<int>& levelOrder) {
    TreeNode* root = buildBST(levelOrder);
    long long accSum = 0;
    return reverseInorder(root, accSum);
}

int main() {
    // Test case 1
    vector<int> levelOrder;
    string line;
    getline(cin , line);

    stringstream ss(line);
    int num;

    while(ss >> num){
        levelOrder.push_back(num);
    }
    cout << solveBSTTransition(levelOrder) << endl; // Output: 14
    return 0;
}
