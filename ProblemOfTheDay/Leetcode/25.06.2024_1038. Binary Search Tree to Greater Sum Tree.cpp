/*
Problem Link :- https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
*/


/*1038. Binary Search Tree to Greater Sum Tree
Solved
Medium
Topics
Companies
Hint
Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
Example 2:

Input: root = [0,null,1]
Output: [1,null,1]
 

*/

//Solution

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


//Approach-1        T.C = O(n*n)  , S.C = O(n);    Brute Force
class Solution {
public:
    void inorder(TreeNode* root , vector<int>& elements){
        if(!root){
            return ;
        }
        inorder(root->left,elements);
        elements.push_back(root->val);
        inorder(root->right,elements);
    }

    void solve(TreeNode* root , vector<int> elements){
        if(!root){
            return;
        }
        solve(root->left , elements);
        int sum = 0;
        for(int i=0 ; i<elements.size() ; i++){
            if(root->val <= elements[i]){
                sum += elements[i];
            }
        }
        root->val = sum;
        solve(root->right,elements);
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> elements;
        inorder(root,elements);

        solve(root,elements);

        return root;
    }
};

//Approach-2           T.C = O(n)  , S.C = O(1);        Optimal

class Solution {
public:
    void solve(TreeNode* root , int& sum){
        if(!root){
            return;
        }

        solve(root->right,sum);

        sum += root->val;

        root->val = sum;

        solve(root->left,sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;

        solve(root , sum);

        return root;
    }
};