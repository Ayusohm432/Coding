/*
Problem Link: https://www.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1
*/

/*Level Order in spiral form

Given a binary tree and the task is to find the spiral order traversal of the tree and return the list containing the elements.
Spiral order Traversal mean: Starting from level 0 for root node, for all the even levels we print the node's value from right to left and for all the odd levels we print the node's value from left to right.
For below tree, function should return [1, 2, 3, 4, 5, 6, 7]

 

Examples:

Input: root = [1, 3, 2]
 
Output: [1, 3, 2]
Explanation: Start with root (1), print level 0 (right to left), then level 1 (left to right).
Input: root = [10, 20, 30, 40, 60]

Output: [10, 20, 30, 60, 40]
Explanation: Start with root (10), print level 0 (right to left), level 1 (left to right), and continue alternating.
Input: root = [1, 2, N, 4]
  
Output: [1, 2, 4]
Explanation: Start with root (1), then level 1 (left to right), then level 2 (right to left).
Constraints:
1 <= number of nodes <= 105
0 <= node->data <= 105

*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        // code here
        vector<int> answer;
        
        if(!root){
            return answer;
        }
        
        queue<Node*> que;
        que.push(root);
        
        bool isOdd = false;
        
        while(!que.empty()){
            int n = que.size();
            vector<int> temp(n);
            
            for(int i=0; i<n; i++){
                Node* node = que.front();
                que.pop();
                
                int index = isOdd ? i : (n - i - 1);
                temp[index] = node->data;
                
                if(node->left){
                    que.push(node->left);
                }
                
                if(node->right){
                    que.push(node->right);
                }
            }
            
            for(int num : temp){
                answer.push_back(num);
            }
            
            isOdd = !isOdd;
        }
        
        return answer;
    }
};
