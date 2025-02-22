/*
Problem Link: https://leetcode.com/problems/recover-a-tree-from-preorder-traversal?envType=daily-question&envId=2025-02-22
*/

/*1028. Recover a Tree From Preorder Traversal

We run a preorder depth-first search (DFS) on the root of a binary tree.

At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.

If a node has only one child, that child is guaranteed to be the left child.

Given the output traversal of this traversal, recover the tree and return its root.

 

Example 1:


Input: traversal = "1-2--3--4-5--6--7"
Output: [1,2,5,3,4,6,7]
Example 2:


Input: traversal = "1-2--3---4-5--6---7"
Output: [1,2,5,3,null,6,null,4,null,7]
Example 3:


Input: traversal = "1-401--349---90--88"
Output: [1,401,null,349,88,90]
 

Constraints:

The number of nodes in the original tree is in the range [1, 1000].
1 <= Node.val <= 109

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
class Solution {
    public:
        TreeNode* recoverFromPreorder(string traversal) {
            vector<TreeNode*> level;
            int n= traversal.size();
            int i = 0;
    
            while(i < n){
                int height = 0;
                while(i < n && traversal[i] == '-'){
                    height++;
                    i++;
                }
    
                int val = 0;
                while(i < n && isdigit(traversal[i])){
                    val = val * 10 + (traversal[i] - '0');
                    i++;
                }
    
                TreeNode* node = new TreeNode(val);
                if(height < level.size()){
                    level[height] = node;
                }else{
                    level.push_back(node);
                }
    
                if(height > 0){
                    TreeNode* parent = level[height - 1];
                    if(parent -> left == nullptr){
                        parent->left = node;
                    }else{
                        parent->right = node;
                    }
                }
            }
            return level[0];
        }
    };