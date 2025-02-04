/*
Problem Link: https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1
*/

/*Diameter of a Binary Tree

Given a binary tree, the diameter (also known as the width) is defined as the number of edges on the longest path between two leaf nodes in the tree. This path may or may not pass through the root. Your task is to find the diameter of the tree.

Examples:

Input: root[] = [1, 2, 3]

Output: 2
Explanation: The longest path has 2 edges (node 2 -> node 1 -> node 3).

Input: root[] = [5, 8, 6, 3, 7, 9]

Output: 4
Explanation: The longest path has 4 edges (node 3 -> node 8 -> node 5 -> node 6 -> node 9).

Constraints:
1 ≤ number of nodes ≤ 105
0 ≤ node->data ≤ 105

*/

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}
*/

class Solution {
  public:
    int solve(Node* node, int &diameter) {
        if (!node) return 0; 
        
        int leftHeight = solve(node->left, diameter);
        int rightHeight = solve(node->right, diameter);
        
        diameter = max(diameter, leftHeight + rightHeight); 
        
        return 1 + max(leftHeight, rightHeight);
    }
    
    int diameter(Node* root) {
        int diameter = 0; 
        solve(root, diameter); 
        return diameter;
    }
};