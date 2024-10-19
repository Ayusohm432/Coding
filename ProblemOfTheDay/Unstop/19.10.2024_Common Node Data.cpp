/*
Problem Link : https://unstop.com/code/practice/299775
*/

/*Common Node Data

Problem Statement
    Implement a program that takes two linked lists as input and finds the value of the first common node between them, considering that all subsequent nodes are also the same.

    If there is a common node, return its value; otherwise, return -1.

Input Format
    The first line takes two space separated integers representing the size of linked list 1 and size of linked list 2 respectively.

    The second line takes space separated integers representing elements of linked list 1.

    The third line takes space separated integers representing elements of linked list 2.

Output Format
    Print the value of the first common node between the two linked lists.

Constraints
    1 ≤ length(linked list 1) + length(linked list 2) ≤ 10^5

    -10^3 ≤ value ≤ 10^3.

Sample Testcase 0
    Testcase Input
        3 4
        100 45 602
        108 2 45 602
    Testcase Output
        45
    Explanation
        There are two linked lists. 
        The first linked list has 3 nodes with values 100, 45, and 602.
        The second linked list has 4 nodes with values 108, 2, 45, and 602. When we compare the two lists, we can see that the first common node is the node with a value of 45. And both lists have this value, and all subsequent nodes have the same values as well.

Sample Testcase 1
    Testcase Input
        4 5
        1 2 3 4 
        1 2 3 4 5
    Testcase Output
        -1
    Explanation
        Linked list 1: 1 -> 2 -> 3 -> 4 
        Linked list 2: 1 -> 2 -> 3 -> 4 -> 5 
        Since both linked lists have the same elements up to the fourth node, the first common node is the first node with a value of 1.
        However, the condition for the common node in the code specifies that all subsequent elements should also be the same. 
        In this case, the subsequent elements are 2, 3, 4(1st list) and 2, 3, 4, 5(2nd list) which are different. 
        Therefore, there is no common node that satisfies the condition, and the output of the code is -1.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to create a linked list from a vector
Node* createLinkedList(const vector<int>& values) {
    Node* dummy = new Node(0);
    Node* current = dummy;
    for (int val : values) {
        current->next = new Node(val);
        current = current->next;
    }
    return dummy->next;
}

// Function to find the first common node
int findCommonNode(Node* head1, Node* head2) {
    Node* curr1 = head1;
    while (curr1 != nullptr) {
        Node* curr2 = head2;
        while (curr2 != nullptr) {
            if (curr1->data == curr2->data) {
                // Check if all subsequent nodes are the same
                Node* temp1 = curr1;
                Node* temp2 = curr2;
                while (temp1 != nullptr && temp2 != nullptr && temp1->data == temp2->data) {
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                }
                if (temp1 == nullptr && temp2 == nullptr) {
                    return curr1->data;
                }
            }
            curr2 = curr2->next;
        }
        curr1 = curr1->next;
    }
    return -1;
}

int main() {
    int size1, size2;
    cin >> size1 >> size2;

    vector<int> list1(size1);
    vector<int> list2(size2);

    for (int i = 0; i < size1; i++) {
        cin >> list1[i];
    }

    for (int i = 0; i < size2; i++) {
        cin >> list2[i];
    }

    Node* head1 = createLinkedList(list1);
    Node* head2 = createLinkedList(list2);

    int result = findCommonNode(head1, head2);
    cout << result << endl;

    return 0;
}