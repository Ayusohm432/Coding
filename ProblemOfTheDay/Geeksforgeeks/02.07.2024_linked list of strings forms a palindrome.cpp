/*
Problem Link :- https://www.geeksforgeeks.org/problems/linked-list-of-strings-forms-a-palindrome/1
*/

/*linked list of strings forms a palindrome


Given a linked list with string data, check whether the combined string formed is palindrome. If the combined string is palindrome then return true otherwise return false.

Example:

Input: a->bc->d->dcb->a

Output : true
Explanation: As string "abcddcba" is palindrome the function should return true.


Input: a->bc->d->ba

Output : false
Explanation: As string "abcdba" is not palindrome the function should return false.



Expected Time Complexity:  O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= Node.data.length<= 103
1<=list.length<=103

*/

//{ Driver Code Starts
// Code by Shubham Joshi
#include <bits/stdc++.h>
using namespace std;

struct Node {
    string data;
    Node *next;

    Node(string x) {
        data = x;
        next = NULL;
    }
};

Node *newNode(string str) {
    Node *new_node = new Node(str);
    new_node->next = NULL;
    return new_node;
}

void print(Node *root) {
    Node *temp = root;

    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}


// } Driver Code Ends
/*
The structure of linked list is the following
struct Node
{
    string data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    bool compute(Node* head) {
        // Your code goes here
        string word = "";
        while(head){
            word += (head->data);
            head = head->next;
        }
        
        int n = word.length();
        
        for(int i=0 ; i<n/2 ; i++){
            if(word[i] != word[n-i-1]){
                return false;
            }
        }
        return true;
    }
};


//{ Driver Code Starts.

int main() {
    // your code goes here
    int T;
    cin >> T;

    while (T--) {
        int K;
        cin >> K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for (int i = 0; i < K; i++) {
            string str = "";
            cin >> str;
            if (head == NULL)
                head = temp = new Node(str);
            else {
                temp->next = new Node(str);
                temp = temp->next;
            }
        }
        Solution ob;
        bool ans = ob.compute(head);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends