/*
Problem Link :- https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/?envType=daily-question&envId=2024-07-16
*/

/*2096. Step-By-Step Directions From a Binary Tree Node to Another
 
You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.

Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

'L' means to go from a node to its left child node.
'R' means to go from a node to its right child node.
'U' means to go from a node to its parent node.
Return the step-by-step directions of the shortest path from node s to node t.

 

Example 1:


Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
Output: "UURL"
Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.
Example 2:


Input: root = [2,1], startValue = 2, destValue = 1
Output: "L"
Explanation: The shortest path is: 2 → 1.
 

Constraints:

The number of nodes in the tree is n.
2 <= n <= 105
1 <= Node.val <= n
All the values in the tree are unique.
1 <= startValue, destValue <= n
startValue != destValue


*/

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

//Approach-1
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root , int src , int dest){
        if(root == nullptr){
            return nullptr;
        }

        if(root->val == src || root->val == dest){
            return root;
        }

        TreeNode* l  = lowestCommonAncestor(root->left  , src , dest);
        TreeNode* r = lowestCommonAncestor(root->right , src , dest);

        if(l && r){
            return root;
        }
        return l ? l : r;
    }

    bool findPath(TreeNode* LCA , int target , string& path){
        if(LCA == nullptr){
            return false;
        }

        if(LCA->val == target){
            return true;
        }

        path.push_back('L');
        if(findPath(LCA->left , target , path)){
            return true;
        }
        path.pop_back();

        path.push_back('R');
        if(findPath(LCA->right , target , path)){
            return true;
        }
        path.pop_back();

        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA = lowestCommonAncestor(root , startValue , destValue);

        string lcaToSrc  = "";
        string lcaToDest = "";

        findPath(LCA , startValue , lcaToSrc );
        findPath(LCA , destValue  , lcaToDest);

        string result = "";
        
        for(int i=0 ; i<lcaToSrc.length() ; i++){
            result.push_back('U');
        }

        result += lcaToDest;

        return result;
    }
};

//Appproach-2

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
class Solution {
public:
    bool findPath(TreeNode* root , int target , string& path){
        if(root == nullptr){
            return false;
        }

        if(root->val == target){
            return true;
        }

        path.push_back('L');
        if(findPath(root->left , target , path)){
            return true;
        }
        path.pop_back();

        path.push_back('R');
        if(findPath(root->right , target , path)){
            return true;
        }
        path.pop_back();

        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string rootToSrc  = "";
        string rootToDest = "";

        findPath(root , startValue , rootToSrc );
        findPath(root , destValue  , rootToDest);

        int i=0;
        while(i<rootToSrc.length() && i<rootToDest.length() && rootToSrc[i] == rootToDest[i]){
            i++;
        }

        string result = "";

        for(int j=0 ; j<rootToSrc.length() - i ; j++){
            result.push_back('U');
        }

        for(int j=i ; j<rootToDest.length() ; j++){
            result.push_back(rootToDest[j]);
        }

        return result;
    }
};