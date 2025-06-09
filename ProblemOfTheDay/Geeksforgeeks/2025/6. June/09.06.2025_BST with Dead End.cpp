/*
Problem Link: https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1
*/

/*BST with Dead End

You are given a Binary Search Tree (BST) containing unique positive integers greater than 0.

Your task is to determine whether the BST contains a dead end.

Note: A dead end is a leaf node in the BST such that no new node can be inserted in the BST at or below this node while maintaining the BST property and the constraint that all node values must be > 0.

Examples:

Input: root[] = [8, 5, 9, 2, 7, N, N, 1]

Output: true
Explanation: Node 1 is a Dead End in the given BST.
Input: root[] = [8, 7, 10, 2, N, 9, 13]

Output: true
Explanation: Node 9 is a Dead End in the given BST.
Constraints:
1 ≤ number of nodes ≤ 3000
1 ≤ node->data ≤ 105

*/

/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
    void collect(Node* node, unordered_set<int>& all, unordered_set<int>& leaf){
        if(!node){
            return;
        }
        
        all.insert(node->data);
        
        if(!node->left && !node->right){
            leaf.insert(node->data);
        }
        
        collect(node->left, all, leaf);
        collect(node->right, all, leaf);
    }
  public:
    bool isDeadEnd(Node *root) {
        // Code here
        unordered_set<int> all, leaf;
        all.insert(0);
        
        collect(root, all, leaf);
        
        for(int node : leaf){
            if(all.count(node-1) && all.count(node+1)){
                return true;
            }
        }
        
        return false;
        
    }
};