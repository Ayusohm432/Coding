/*
Problem Link : https://unstop.com/code/practice/299842
*/

/*Rearrange Linked List

Problem Statement
You have a list of numbers arranged in a specific order, and your task is to rearrange the numbers in a particular way. Every third number should be grouped together while maintaining their original order within those groups.

You need to make these changes directly in the original list without creating a new one. Finally, print the modified list.

For example, given the input linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 ,

the rearranged linked list should be: 1 -> 4 -> 7 -> 2 -> 5 -> 8 -> 3 -> 6 -> 9.

Input Format
The first line contains an integer, N, representing the number of elements in the linked list.

The second line contains N space-separated integers, representing the elements of the linked list.

Output Format
The linked list may not always contain a number of elements that is a multiple of three. In such cases, any remaining elements that cannot form a complete group of three should be placed at the end of the linked list in their original order.

After making these changes, display the modified linked list.

Constraints
1 ≤ Size of the linked list (n) ≤ 10^4
0 ≤ value of linked list ≤ 10^3

Sample Testcase 0
Testcase Input
5
1 2 3 4 5
Testcase Output
1 4 2 5 3
Explanation
The original linked list is 1 -> 2 -> 3 -> 4 -> 5. After rearranging, every third element forms a group. The groups are (1, 4), (2, 5), and (3). Within each group, the elements maintain their original order. Therefore, the modified linked list is 1 -> 4 -> 2 -> 5 -> 3.
Sample Testcase 1
Testcase Input
6
10 20 30 40 50 60
Testcase Output
10 40 20 50 30 60
Explanation
The original linked list is 10 -> 20 -> 30 -> 40 -> 50 -> 60. After rearranging, every third element forms a group. The groups are (10, 40), (20, 50), and (30, 60). Within each group, the elements maintain their original order. Therefore, the modified, linked list is 10 -> 40 -> 20 -> 50 -> 30 -> 60.

*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {};
};

Node* createLinkedlist(const vector<int>& list) {
    if (list.empty()) {
        return nullptr;
    }

    Node* head = new Node(list[0]);
    Node* curr = head;

    for (int i = 1; i < list.size(); i++) {
        curr->next = new Node(list[i]);
        curr = curr->next;
    }
    return head;
}

void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

class Solution {
public:
    void rearrangeLinkedList(Node*& head) {
        if (!head) return;

        Node* curr = head;
        vector<Node*> groups[3];  // To hold the nodes in three groups

        // Traverse the linked list and fill the groups
        int index = 0;
        while (curr) {
            groups[index].push_back(curr);
            curr = curr->next;
            index = (index + 1) % 3;  // Cycle through 0, 1, 2
        }

        // Reconstruct the linked list from the groups
        head = nullptr;
        Node* tail = nullptr;

        for (int i = 0; i < 3; i++) {
            for (Node* node : groups[i]) {
                if (!head) {
                    head = node;
                    tail = node;
                } else {
                    tail->next = node;
                    tail = tail->next;
                }
            }
        }

        if (tail) {
            tail->next = nullptr;  // Ensure the last node points to nullptr
        }
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> list(n);
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    Node* head = createLinkedlist(list);

    Solution s;
    s.rearrangeLinkedList(head);

    printLinkedList(head);

    return 0;
}