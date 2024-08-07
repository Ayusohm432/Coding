/*
Problem Link :- https://leetcode.com/problems/create-binary-tree-from-descriptions/description/?envType=daily-question&envId=2024-07-15
*/

/*2196. Create Binary Tree From Descriptions

You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

If isLefti == 1, then childi is the left child of parenti.
If isLefti == 0, then childi is the right child of parenti.
Construct the binary tree described by descriptions and return its root.

The test cases will be generated such that the binary tree is valid.

 

Example 1:


Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
Output: [50,20,80,15,17,19]
Explanation: The root node is the node with value 50 since it has no parent.
The resulting binary tree is shown in the diagram.
Example 2:


Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
Output: [1,2,null,null,3,4]
Explanation: The root node is the node with value 1 since it has no parent.
The resulting binary tree is shown in the diagram.
 

Constraints:

1 <= descriptions.length <= 104
descriptions[i].length == 3
1 <= parenti, childi <= 105
0 <= isLefti <= 1
The binary tree described by descriptions is valid.



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

//approach-1
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int , TreeNode* > mp;
        unordered_set<int> childSet;
        int Root = descriptions[0][0];

        for(vector<int>& vec : descriptions){
            int parent = vec[0];
            int child = vec[1];
            int isLeft = vec[2];

            if(mp.find(parent) == mp.end()){
                mp[parent] = new TreeNode(parent);
            }

            if(mp.find(child) == mp.end()){
                mp[child] = new TreeNode(child);
            }

            if(isLeft){
                mp[parent]->left = mp[child];
            }
            else{
                mp[parent]->right = mp[child];
            }

            childSet.insert(child);
        }

        for(vector<int>& vec : descriptions){
            int parent = vec[0];
            if(!childSet.count(parent)){
                return mp[parent];
            }
        }
        return nullptr;
    }
};


//approach-2
class Solution {
public:
    typedef unordered_map<int,pair<int,int>> MAP;
    TreeNode* makeTree(MAP& mp , int parent){
        if(mp.find(parent) == mp.end()){
            return new TreeNode(parent);
        }

        TreeNode* root = new TreeNode(parent);

       if(mp[parent].first != 0){
            root->left = makeTree(mp , mp[parent].first);
        }
        if(mp[parent].second != 0){
            root->right = makeTree(mp, mp[parent].second);
        }

        return root;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        MAP mp;
        unordered_set<int> childSet;

        for(auto& description : descriptions){
            int parent = description[0];
            int child = description[1];
            int isLeft = description[2];

            if(isLeft){
                mp[parent].first = child;
            }
            else{
                mp[parent].second = child;
            }
            childSet.insert(child);
        }

        int root;

        for(vector<int>& vec : descriptions){
            int parent = vec[0];
            if(!childSet.count(parent)){
                root = parent;        
            }
        }

        return makeTree(mp , root);
    }
};