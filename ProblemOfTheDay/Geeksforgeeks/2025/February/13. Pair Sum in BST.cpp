/*
Problem Link : https://www.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1
*/

/*Pair Sum in BST

Given a Binary Search Tree(BST) and a target. Check whether there's a pair of Nodes in the BST with value summing up to the target. 

Examples:

Input: root = [7, 3, 8, 2, 4, N, 9], target = 12
       bst
Output: True
Explanation: In the binary tree above, there are two nodes (8 and 4) that add up to 12.
Input: root = [9, 5, 10, 2, 6, N, 12], target = 23
          bst-3
Output: False
Explanation: In the binary tree above, there are no such two nodes exists that add up to 23.
Constraints:

1 ≤ Number of Nodes ≤ 105
1 ≤ target ≤ 106

*/
/*
Node is as follows
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
    public:
      vector<int> ans;
  
      void solve(Node* root) {
          if (root == NULL) return;
          solve(root->left);
          ans.push_back(root->data);
          solve(root->right);
      }
      
      bool findTarget(Node *root, int target) {
          // your code here.
          ans.clear();
          solve(root);
          sort(ans.begin(),ans.end());
          
          int i=0;
          int j= ans.size()-1;
          
          while(i<j){
              int temp = ans[i]+ans[j];
              if(ans[i]+ans[j]==target){
                  return true;
              }else if(ans[i]+ans[j]<target){
                  i++;
              }else if(ans[i]+ans[j]>target){
                  j--;
              }
             
          }
          return false;
          
          
      }
  };