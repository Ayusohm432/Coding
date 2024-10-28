/*
Problem Link : https://unstop.com/code/practice/299611
*/


/*Mountain Valley

Problem Statement
You are given a linked list with a head pointer. Your task is to count the number of nodes that meet the "peak condition." This condition is defined as a node that is greater than both its previous and next nodes, making it effectively a "peak" in the list.

Specifically:

The value of the current node must be higher than the value of the previous node.
The value of the current node must also be higher than the value of the next node.
Return the total number of nodes satisfying the above condition.

Input Format
The input consists of two lines: the first line contains a positive integer N that denotes the size of the linked list, and the second line includes N integers that represent the elements of the linked list.

Output Format
Return the total number of nodes satisfying the given condition.

Constraints
1 <= N < 10^5

Sample Testcase 0
Testcase Input
5
1 3 2 6 4
Testcase Output
2
Explanation
In the list [1, 3, 2, 6, 4], the nodes '3' and '6' satisfy the condition of being greater than both their previous and next nodes (i.e., they are "peaks"). Thus, the output is 2.

Sample Testcase 1
Testcase Input
4
1 3 21 5
Testcase Output
1
Explanation
In the list [1, 3, 21, 5], the node '21' satisfies the condition of being greater than both its previous and next nodes (i.e., it is a "peak"). Thus, the output is 1.


*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Struct definition with missing semicolon added
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to create a linked list
Node* createLinkedList(const vector<int>& list) {
    if (list.empty()) {
        return nullptr;
    }

    Node* head = new Node(list[0]);
    Node* temp = head;

    // Starting loop from 1 to avoid adding an extra node for the first element
    for (int i = 1; i < list.size(); i++) {
        temp->next = new Node(list[i]);
        temp = temp->next; // Correctly move to the next node
    }
    return head;
}

// Function to count mountain valleys
int mountainValley(Node*& head) {
    int count = 0;

    // Edge case: if the list has fewer than 3 nodes
    if (!head || !head->next || !head->next->next) {
        return count; 
    }

    Node* curr = head->next;
    Node* prev = head;
    Node* nexti = curr->next;

    while (nexti) {
        // Correcting the condition to check the current node
        if (curr->data > prev->data && curr->data > nexti->data) {
            count++;
        }
        // Move the pointers to the next nodes
        prev = curr;
        curr = nexti;
        nexti = nexti->next;
    }
    return count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;

    vector<int> list(n);
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    Node* head = createLinkedList(list);

    int result = mountainValley(head);

    cout << result;

    return 0;
}
