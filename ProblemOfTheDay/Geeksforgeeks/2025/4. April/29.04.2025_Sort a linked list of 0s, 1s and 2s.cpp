/*
Problem Link: https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
*/

/*Sort a linked list of 0s, 1s and 2s

Given the head of a linked list where nodes can contain values 0s, 1s, and 2s only. Your task is to rearrange the list so that all 0s appear at the beginning, followed by all 1s, and all 2s are placed at the end.

Examples:

Input: head = 1 → 2 → 2 → 1 → 2 → 0 → 2 → 2

Output: 0 → 1 → 1 → 2 → 2 → 2 → 2 → 2

Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between.
Input: head = 2 → 2 → 0 → 1

Output: 0 → 1 → 2 → 2

Explanation: After arranging all the 0s, 1s and 2s in the given format, the output will be 0 → 1 → 2 → 2.
Constraints:
1 ≤ no. of nodes ≤ 106
0 ≤ node->data ≤ 2

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends

/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* temp = head;
        Node* zeroList = new Node(-1);
        Node* oneList = new Node(-1);
        Node* twoList = new Node(-1);
        
        Node* zeroNext = zeroList;
        Node* oneNext = oneList;
        Node* twoNext = twoList;
        
        while(temp){
            if(temp->data == 0){
                zeroNext->next = temp;
                zeroNext = temp;
            }else if(temp->data == 1){
                oneNext->next = temp;
                oneNext = temp;
            }else{
                twoNext->next = temp;
                twoNext = temp;
            }
            temp = temp->next;
        }
        twoNext->next = NULL;
        oneNext->next = twoList->next;
        zeroNext->next = oneList->next;
        
        return zeroList->next;
    }
};



//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends