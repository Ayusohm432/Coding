/*
Problem Link: https://www.geeksforgeeks.org/problems/construct-tree-1/1
*/

/*Construct Tree from Inorder & Preorder

Given two arrays representing the inorder and preorder traversals of a binary tree, construct the tree and return the root node of the constructed tree.

Note: The output is written in postorder traversal.

Examples:

Input: inorder[] = [1, 6, 8, 7], preorder[] = [1, 6, 7, 8]
Output: [8, 7, 6, 1]
Explanation: The tree will look like

Input: inorder[] = [3, 1, 4, 0, 2, 5], preorder[] = [0, 1, 3, 4, 2, 5]
Output: [3, 4, 1, 5, 2, 0]
Explanation: The tree will look like

Input: inorder[] = [2, 5, 4, 1, 3], preorder[] = [1, 4, 5, 2, 3]
Output: [2, 5, 4, 3, 1]
Explanation: The tree will look like

Constraints:
1 ≤ number of nodes ≤ 103
0 ≤ nodes -> data ≤ 103
Both the inorder and preorder arrays contain unique values.

*/

/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    Node* constructTree(vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &inorderMap, int &preIndex, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;
    
        int rootValue = preorder[preIndex++];
        Node* root = new Node(rootValue);
    
        int rootIndex = inorderMap[rootValue];
    
        root->left = constructTree(preorder, inorder, inorderMap, preIndex, inStart, rootIndex - 1);
        root->right = constructTree(preorder, inorder, inorderMap, preIndex, rootIndex + 1, inEnd);
    
        return root;
    }
    
    Node* buildTree(vector<int> &inorder, vector<int> &preorder) {
        unordered_map<int, int> inorderMap;
        int n = inorder.size();
        
        for (int i = 0; i < n; i++) {
            inorderMap[inorder[i]] = i;
        }
    
        int preIndex = 0;
        return constructTree(preorder, inorder, inorderMap, preIndex, 0, n - 1);
    }
};