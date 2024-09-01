/*
Problem Link ;- https://unstop.com/code/practice/250198
*/

/*Playing with Tree

In a computer class, students are represented as nodes in a binary search tree (BST) with each student having a unique roll number. Given two nodes xxx and yyy in this BST, the task is to find their Lowest Common Ancestor (LCA). The LCA is the lowest node in the tree that has both xxx and yyy as descendants

Input Format
First line of the input contains an integer n  —  number of nodes in the binary search tree.

Second-line contains n space-separated integer – nodes of the binary search tree. Nodes are in the form of level order traversal of binary search tree.

Third line contains two space-separated integers – x and y.

Output Format
Print an integer which is the lowest common ancestor (LCA) of nodes x and y.

Constraints
The number of nodes in the tree is in the range [2, 10^5].

-10^9 <= value of node <= 10^9

All nodes are unique.

x != y

x and y will exist in the BST.

Sample Testcase 0
Testcase Input
9
6 2 8 0 4 7 9 14 1
2 8
Testcase Output
6
Explanation
This Binary search tree has nine nodes. 6 is the root node of the tree.2, 8 are the descendants of node 6. Hence, the LCA of nodes 2 and 8 is 6.	
Sample Testcase 1
Testcase Input
7
6 2 8 0 4 7 9  
2 4
Testcase Output
2

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to insert a node into the BST
Node* insert(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);
    
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    
    return root;
}

// Function to find the LCA of two nodes x and y
int findLCA(Node* root, int x, int y) {
    while (root != nullptr) {
        // If both x and y are smaller than root, then LCA lies in the left subtree
        if (x < root->data && y < root->data)
            root = root->left;
        // If both x and y are greater than root, then LCA lies in the right subtree
        else if (x > root->data && y > root->data)
            root = root->right;
        else
            break;  // We have found the LCA
    }
    return root->data;
}

int main() {
    int n;
    cin >> n;

    int nodes[n];
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
    }

    int x, y;
    cin >> x >> y;

    // Construct the BST from the input nodes
    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        root = insert(root, nodes[i]);
    }

    // Find the LCA of x and y
    int lca = findLCA(root, x, y);
    cout << lca << endl;

    return 0;
}


