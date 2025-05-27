/*
Problem Link: https://www.geeksforgeeks.org/problems/print-leaf-nodes-from-preorder-traversal-of-bst2657/1
*/

/*Print leaf nodes from preorder traversal of BST

Given a preorder traversal of a BST, find the leaf nodes of the tree without building the tree.


Examples:

Input: preorder[] = [5, 2, 10]
Output: [2, 10]
Explaination: 

2 and 10 are the leaf nodes as shown in the figure.
Input: preorder[] = [4, 2, 1, 3, 6, 5]
Output: [1, 3, 5]
Explaination: 

1, 3 and 5 are the leaf nodes as shown in the figure.
Input: preorder[] = [8, 2, 5, 10, 12]
Output: [5, 12]
Explaination: 

5 and 12 are the leaf nodes as shown in the figure.

Constraints:
1 ≤ preorder.size() ≤ 103
1 ≤ preorder[i] ≤ 103

*/

class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        // code here
        int n = preorder.size();
        vector<int> result;
        stack<int> st;
        st.push(preorder[0]);
        
        for(int i=1; i<n; i++){
            if(preorder[i] < st.top()){
                st.push(preorder[i]);
            }else{
                int tempSize = st.size();
                int temp = st.top();
                while(!st.empty() && preorder[i] > st.top()){
                    st.pop();
                }
                st.push(preorder[i]);
                if(tempSize > st.size()){
                    result.push_back(temp);
                }
            }
        }
        result.push_back(st.top());
        return result;
    }
};