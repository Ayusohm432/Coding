/*
Problem link :- https://unstop.com/code/practice/307828
*/

/*
Problem Statement
    You have linked list,

    Make  ‘Even number Mean Linked List’  from the Mean of every k nodes of the linked list

    If not possible to create due to k integer greater than the remaining or size of linked List print as is it

Input Format
    First line contains k Integer value

    Second line includes n Integer size of the Linked list,

Output Format
    First, make the linked list then

    travel till k node every time to form even mean Linked List

Constraints
    1 <= k < 10^2

    0 <= n < 10^3

Sample Testcase 0
    Testcase Input
        4
        10
        4 6 8 2 8 2 6 8 2 6
    Testcase Output
        6 --> 2 --> 6 --> null
    Explanation
        First make the linked list then travel till k node every time to form even mean Linked List and then size of linked list less then the k so remaining element attach as is it

Sample Testcase 1
    Testcase Input
        3
        9
        3 3 6 9 3 6 3 3 3
    Testcase Output
        4 --> 6 --> null
    Explanation
        First, make the linked list then travel till k node every time to form even mean Linked List

Topics
    Linked List
    Conditionals
    Looping
    Linked List


*/
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Function to append a new node at the end
void append(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    if (head == nullptr) {
        cout << "null" << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        temp = temp->next;
        if (temp != nullptr)
            cout << " --> ";
    }
    cout << " --> null" << endl;
}

// Function to compute the mean of the linked list nodes
int computeMean(vector<int>& nodes) {
    int sum = 0;
    for (int node : nodes) {
        sum += node;
    }
    return sum / nodes.size();
}

// Function to create the Even number Mean Linked List
Node* createEvenMeanLinkedList(Node* head, int k) {
    Node* newHead = nullptr;
    Node* current = head;
    vector<int> nodes;
    
    while (current != nullptr) {
        nodes.push_back(current->data);
        if (nodes.size() == k) {
            int mean = computeMean(nodes);
            if (mean % 2 == 0) {
                append(newHead, mean);
            }
            nodes.clear();
        }
        current = current->next;
    }
    
    // Append remaining elements as is if their count is less than k
    for (int node : nodes) {
        append(newHead, node);
    }
    
    return newHead;
}

int main() {
    int k, n;
    cin >> k >> n;
    
    if (n == 0) {
        cout << "null" << endl;
        return 0;
    }
    
    Node* head = nullptr;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        append(head, value);
    }
    
    Node* evenMeanList = createEvenMeanLinkedList(head, k);
    printList(evenMeanList);
    
    return 0;
}
