/*
Problem Link: https://unstop.com/code/practice/306511
*/

/*Print the last second-row element from the postorder

Problem Statement
You are provided with an array representing the postorder traversal of a Binary Search Tree (BST). The task is to reconstruct the BST from this postorder array and then identify the elements in the second-to-last row of the BST when it is printed in level order.
Input Format
The first line contains an integer N, indicating the number of elements in the postorder array.

The second line provides N space-separated integers that represent the postorder traversal of the Binary Search Tree (BST).

Output Format
Print the elements of the second-last row of the BST in level order.

It will be sure that an answer will exist.

Constraints
2 <= N < 10^3

Sample Testcase 0
Testcase Input
6
1 6 4 49 39 9
Testcase Output
4 39
Explanation
The tree will be:


                                            9


                                       /         \


                                    4           39


                                 /     \           \


                               1       6          49


Last second-row element which is 4 39

Sample Testcase 1
Testcase Input
6
1 9 5 40 15 14
Testcase Output
5 15
Explanation
The tree will be:


                                          14


                                       /         \


                                    5           15


                                 /     \           \


                               1       9          40


Last second-row element which is 5 15


*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

Node* constructBST(int postorder[], int start, int end) {
    // base case
    if (start > end) {
        return nullptr;
    }
    Node* node = new Node(postorder[end]);
    int i;
    for (i = end; i >= start; i--) {
        if (postorder[i] < node->key) {
            break;
        }
    }
    node->right = constructBST(postorder, i + 1, end - 1);
    node->left = constructBST(postorder, start, i);
    return node;
}

void printLastSecondRow(Node* root) {
    if (root == nullptr) {
        return;
    }
    queue<Node*> queue;
    queue.push(root);
    stack<vector<int>> st;

    while (!queue.empty()) {
        int size = queue.size();
        vector<int> level;

        for (int i = 0; i < size; i++) {
            Node* curr = queue.front();
            queue.pop();
            if (curr->left != nullptr) {
                queue.push(curr->left);
            }
            if (curr->right != nullptr) {
                queue.push(curr->right);
            }
            level.push_back(curr->key);
        }
        st.push(level);
    }

    st.pop();
    vector<int> ans = st.top();
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int postorder[n];
    for (int i = 0; i < n; i++) {
        cin >> postorder[i];
    }

    Node* root = constructBST(postorder, 0, n - 1);
    printLastSecondRow(root);

    return 0;
}