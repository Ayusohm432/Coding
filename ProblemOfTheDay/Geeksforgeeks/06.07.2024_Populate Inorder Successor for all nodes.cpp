/*
Problem Link :- https://www.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1
*/

/*Populate Inorder Successor for all nodes

Given a Binary Tree, complete the function to populate the next pointer for all nodes. The next pointer for every node should point to the Inorder successor of the node.
You do not have to return or print anything. Just make changes in the root node given to you.

Note: The node having no in-order successor will be pointed to -1. You don't have to add -1 explicitly, the driver code will take care of this.

Examples :

Input:
       10
       /  \
      8   12
     /
    3
Output: 3->8 8->10 10->12 12->-1
Explanation: The inorder of the above tree is : 3 8 10 12. So the next pointer of node 3 is pointing to 8 , next pointer of 8 is pointing to 10 and so on.And next pointer of 12 is pointing to -1 as there is no inorder successor of 12.
Input:
       1
      /  
     2 
   /
 3  
Output: 3->2 2->1 1->-1
Explanation: The inorder of the above tree is: 3 2 1. So the next pointer of node 3 is pointing to 2 , next pointer of 2 is pointing to 1. And next pointer of 1 is pointing to -1 as there is no inorder successor of 1.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1<= no. of nodes <=105
1<= data of the node <=105

*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

void printInorder(Node *node) {
    if (node == NULL) {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

Node *Inorder(Node *root) {
    if (root->left == NULL)
        return root;
    Inorder(root->left);
}


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* nxt = nullptr;
    void populateNext(Node *root) {
        // code here
        if(!root){
            return;
        }
        populateNext(root->right);
        root->next = nxt;
        nxt = root;
        populateNext(root->left);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        obj.populateNext(root);
        Node *ptr = Inorder(root);
        while (ptr) {
            printf("%d->%d ", ptr->data, ptr->next ? ptr->next->data : -1);
            ptr = ptr->next;
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends