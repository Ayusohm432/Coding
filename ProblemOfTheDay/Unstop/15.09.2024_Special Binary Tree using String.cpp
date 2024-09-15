/*
Problem Link : https://unstop.com/code/practice/250425
*/

/*Special Binary Tree using String

Problem Statement
 1. You are given a special string S that represents a preorder traversal of a binary tree. 

 2. At each node in this traversal, there are D dashes (where D is the depth of this node), followed by the value of this node.

 3. If the depth of a node is D, the depth of its immediate child is D+1.  The depth of the root node is 0. If a node has only one child, that child is guaranteed to be the left child.

 4. You have to construct the special binary tree from this string and print the level order serialization.

Example 1: Input: traversal = "1-2--3--4-5--6--7"



Example 2: Input: traversal = "1-2--3---4-5--6---7"



Example 3: Input: traversal = "1-401--349---90--88" 



Input Format
The first and single line of input containing the string S.

Output Format
Print the level order traversal of the constructed binary tree.

Constraints
The number of nodes in the original tree is in the range [1, 1000].

1 <= Node.val <= 10^9

Sample Testcase 0
Testcase Input
1-4--3---2--5
Testcase Output
[1, 4, null, 3, 5, 2, null, null, null, null, null]
Explanation



The required binary tree is a complete binary tree with 4 levels.


The level order traversal of the tree including "null" node : 1, 4, null, 3, 5, 2, null, null, null, null, null

Sample Testcase 1
Testcase Input
1-2--3--4-5--6--7
Testcase Output
[1, 2, 5, 3, 4, 6, 7, null, null, null, null, null, null, null, null]
Explanation

The required binary tree is a complete binary tree with 3 levels, where the first level contains node 1, and the second level has 2 nodes, 2 and 5. Node 2 has two children with values 3 and 4. Similarly, Node 5 has two children with values 6 and 7.


The level order traversal of the tree including "null" node : 1, 2, 5, 3, 4, 6, 7, null, null, null, null, null, null, null, null.

*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* recoverFromPreorder(string S) {
    stack<pair<TreeNode*, int>> st; 
    int i = 0, n = S.size();
    
    while (i < n) {
        int depth = 0;
        while (i < n && S[i] == '-') {
            depth++;
            i++;
        }

        int val = 0;
        while (i < n && isdigit(S[i])) {
            val = val * 10 + (S[i] - '0');
            i++;
        }

        TreeNode* node = new TreeNode(val);
        
        while (!st.empty() && st.top().second >= depth) {
            st.pop(); 
        }
        
        if (!st.empty()) {
            TreeNode* parent = st.top().first;
            if (!parent->left)
                parent->left = node;
            else
                parent->right = node;
        }
        
        st.push({node, depth});
    }
    
    while (st.size() > 1) {
        st.pop();
    }
    
    return st.top().first;
}

void printLevelOrder(TreeNode* root) {
    if (!root) return;
    
    vector<string> result;
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        
        if (node) {
            result.push_back(to_string(node->val));
            q.push(node->left);
            q.push(node->right);
        } else {
            result.push_back("null");
        }
    }
    
    cout << "[";
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    string traversal;
    cin >> traversal;
    
    TreeNode* root = recoverFromPreorder(traversal);
    
    printLevelOrder(root);
    
    return 0;
}
