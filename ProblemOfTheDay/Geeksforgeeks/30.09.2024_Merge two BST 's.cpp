/*
Problem Link : https://www.geeksforgeeks.org/problems/merge-two-bst-s/1
*/

/*Merge two BST 's

Given two BSTs, return elements of merged BSTs in sorted form.

Examples :

Input:
BST1:
       5
     /   \
    3     6
   / \
  2   4  
BST2:
        2
      /   \
     1     3
            \
             7
            /
           6
Output: 1 2 2 3 3 4 5 6 6 7
Explanation: After merging and sorting the two BST we get 1 2 2 3 3 4 5 6 6 7.
Input:
BST1:
       12
     /   
    9
   / \    
  6   11
BST2:
      8
    /  \
   5    10
  /
 2
Output: 2 5 6 8 9 10 11 12
Explanation: After merging and sorting the two BST we get 2 5 6 8 9 10 11 12.
Expected Time Complexity: O((m+n)*log(m+n))
Expected Auxiliary Space: O(Height of BST1 + Height of BST2 + m + n)

Constraints:
1 ≤ Number of Nodes, value of nodes ≤ 105


*/
class Solution {
  public:
    void inorder(Node* root , vector<int>& bst){
        if(!root){
            return;
        }
        inorder(root->left , bst);
        bst.push_back(root->data);
        inorder(root->right , bst);
    }
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int> bst1;
        vector<int> bst2;
        vector<int> result;
        
        inorder(root1 , bst1);
        inorder(root2 , bst2);
        
        int i=0; 
        int j=0;
        
        while(i< bst1.size() && j < bst2.size()){
            if(bst1[i] <= bst2[j]){
                result.push_back(bst1[i]);
                i++;
            }
            else{
                result.push_back(bst2[j]);
                j++;
            }
        }
        
        while(i < bst1.size()){
            result.push_back(bst1[i++]);
        }
        
        while(j < bst2.size()){
            result.push_back(bst2[j++]);
        }
        return result;
    }
};