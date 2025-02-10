/*
Problem Link : https://www.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1?timeMachineDate=2025-02-09
*/

/*Maximum path sum from any node

Given a binary tree, the task is to find the maximum path sum. The path may start and end at any node in the tree.

Examples:

Input: root[] = [10, 2, 10, 20, 1, N, -25, N, N, N, N, 3, 4]
Output: 42
Explanation: 

Max path sum is represented using green colour nodes in the above binary tree.
Input: root[] = [-17, 11, 4, 20, -2, 10]
Output: 31
Explanation: 

Max path sum is represented using green colour nodes in the above binary tree.
Constraints:
1 ≤ number of nodes ≤ 103
-104 ≤ node->data ≤ 104

*/

// User Fuction template for C++
/*
// Tree Node
class Node {
public:
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
      // Function to return maximum path sum from any node in a tree.
      // Helper function to compute the maximum path sum
      int getMaxPathSum(Node* root, int &maxSum) {
          if (!root) return 0; // Base case: If node is null, return 0
          
          // Recursively get the maximum sum from left and right subtrees
          int leftMax = max(0, getMaxPathSum(root->left, maxSum));  // Ignore negative sums
          int rightMax = max(0, getMaxPathSum(root->right, maxSum));
  
          // Update the maximum path sum considering the current node as the root of the path
          maxSum = max(maxSum, root->data + leftMax + rightMax);
  
          // Return the maximum sum of the path including the current node and either left or right subtree
          return root->data + max(leftMax, rightMax);
      }
  
      // Main function to find the maximum path sum in the binary tree
      int findMaxSum(Node *root) {
          int maxSum = INT_MIN; // Initialize max sum as the smallest possible integer
          getMaxPathSum(root, maxSum);
          return maxSum;
      }
  };