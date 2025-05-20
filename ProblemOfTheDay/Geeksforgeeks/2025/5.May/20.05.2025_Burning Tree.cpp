/*
Problem Link: https://www.geeksforgeeks.org/problems/burning-tree/1
*/

/*Burning Tree

Given a binary tree and a target node, determine the minimum time required to burn the entire tree if the target node is set on fire. In one second, the fire spreads from a node to its left child, right child, and parent.
Note: The tree contains unique values.

Examples : 

Input: root[] = [1, 2, 3, 4, 5, 6, 7], target = 2
  
Output: 3
Explanation: Initially 2 is set to fire at 0 sec 
At 1 sec: Nodes 4, 5, 1 catches fire.
At 2 sec: Node 3 catches fire.
At 3 sec: Nodes 6, 7 catches fire.
It takes 3s to burn the complete tree.
Input: root[] = [1, 2, 3, 4, 5, N, 7, 8, N, 10], target = 10

Output: 5
Explanation: Initially 2 is set to fire at 0 sec 
At 1 sec: Node 5 catches fire.
At 2 sec: Node 2 catches fire.
At 3 sec: Nodes 1 and 4 catches fire.
At 4 sec: Node 3 and 8 catches fire.
At 5 sec: Node 7 catches fire.
It takes 5s to burn the complete tree.
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105


*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

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

        // Get the current Node's value from the string
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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

/*
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
    void createAdjecency(Node* current, int parent, unordered_map<int, vector<int>>& adj){
        if(current == nullptr){
            return;
        }
        
        if(parent != -1){
            adj[current->data].push_back(parent);
        }
        
        if(current->left != nullptr){
            adj[current->data].push_back(current->left->data);
        }
        
        if(current->right != nullptr){
            adj[current->data].push_back(current->right->data);
        }
        createAdjecency(current->left, current->data, adj);
        createAdjecency(current->right, current->data, adj);
    }
    int minTime(Node* root, int target) {
        // code here
        unordered_map<int, vector<int>> adj;
        createAdjecency(root, -1, adj);
        
        queue<int> que;
        que.push(target);
        unordered_set<int> visited;
        visited.insert(target);
        int timeTaken = 0;
        
        while(!que.empty()){
            int n = que.size();
            while(n--){
                int curr = que.front();
                que.pop();
                
                for(int& neighbour : adj[curr]){
                    if(visited.find(neighbour) == visited.end()){
                        que.push(neighbour);
                        visited.insert(neighbour);
                    }
                }
            }
            timeTaken++;
        }
        return timeTaken-1;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends