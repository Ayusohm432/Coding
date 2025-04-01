/*
Problem Link: https://unstop.com/code/practice/509251
*/

/*Right Path to Perfect Square

Problem Statement
You are given a Binary Tree with the root node provided. Starting from the root, imagine traveling to the right until you reach a leaf node. During this traversal, collect the values of all the nodes encountered in your path.

At the end of the traversal:

Calculate the sum of the collected node values.
Determine whether the sum is a perfect square. A number is considered a perfect square if it can be expressed as the square of an integer (e.g., 1, 4, 9, 16, etc.).
Note: Tree node values are given in a level-order traversel, where N in the sequence represents the NULL node.

Input Format
The first line contains an integer M, representing the Nodes of the Tree.

The second line contains M space-separated values, representing the Tree Nodes in level order.

Output Format
Print "YES" if the sum of the collected values is a perfect square; otherwise, print "NO".

Constraints
1 ≤ N ≤ 10^4

1 ≤ arr[i] ≤ 10^4

Sample Testcase 0
Testcase Input
7
5 3 8 N N 6 10
Testcase Output
NO
Explanation
Level order traveral of the tree:
                             5
                           /     \ 
                        3         8
                                  /   \
                                6    10

Now we need to traverse toward right.
5 -> 8 -> 10
Sum = 23 (not a perfect square).

Sample Testcase 1
Testcase Input
15
1 2 3 4 5 6 7 8 9 N N N N 10 14
Testcase Output
YES
Explanation
Level order traveral of the tree:
                             1 
                           /     \ 
                        2         3 
                     /     \      /    \
                  4        5   6     7 
                /   \                  /   \
              8     9              10   14

Now we need to traverse toward right.
1 -> 3 -> 7 -> 14
Sum = 25 (perfect square).

*/

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isPerfectSquare(int n){
    int root = sqrt(n);
    return root*root == n;
}

TreeNode* buildTree(vector<int>& nodes){
    if(nodes.empty() || nodes[0] == -1){
        return NULL;
    }

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> que;
    que.push(root);
    int i = 1;

    while(!que.empty() && i < nodes.size()){
        TreeNode* curr = que.front();
        que.pop();

        if(nodes[i] != -1){
            curr -> left = new TreeNode(nodes[i]);
            que.push(curr->left);
        }
        i++;

        if(i < nodes.size() && nodes[i] != -1){
            curr->right = new TreeNode(nodes[i]);
            que.push(curr->right);
        }
        i++;
    }
    return root;
}

int rightPathSum(TreeNode* root){
    int sum = 0;
    while(root){
        sum += root->val;
        root = root->right;
    }

    return sum;
}

string user_logic(int M, vector<int>& nodes) {
    // Write your logic here.
    TreeNode* root = buildTree(nodes);
    int sum = rightPathSum(root);
    // Return "YES" or "NO"
    return isPerfectSquare(sum) ? "YES" : "NO";  // Placeholder
}

int main() {
    int M;
    cin >> M;
    vector<int> nodes(M);
    for (int i = 0; i < M; ++i) {
        string val;
        cin >> val;
        if (val == "N") {
            nodes[i] = -1; // N represents NULL
        } else {
            nodes[i] = stoi(val);
        }
    }
    string result = user_logic(M, nodes);
    cout << result << endl;
    return 0;
}