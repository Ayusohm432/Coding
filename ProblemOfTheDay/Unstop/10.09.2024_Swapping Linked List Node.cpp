/*
Problem link : https://unstop.com/code/practice/250244
*/

/*Swapping Linked List Node

Problem Statement
Ram gave Shyaam a challenge, he gave shyaam the head of a linked list, and an integer k.

He asked Shyaam to swap the values of the Kth node from the beginning and the Kth node from the end (the list is 1-indexed).

Note: The number of nodes in the list is N.

Input Format
The first line contains an integer N, representing the number of nodes in the linked list.

The second line contains N space-separated integers, each representing the value of a node in the linked list.

The third line contains an integer K, indicating the positions of the nodes to be swapped.

Output Format
Output the linked list after swapping the values of the two specified nodes.

Constraints
1 <= K <= N <= 10^5

0 <= Node.val <= 10^2

Sample Testcase 0
Testcase Input
5
1 2 3 4 5
2
Testcase Output
1 4 3 2 5
Explanation
2 is the second node and 4 is the 2nd last node values of which are swapped.
Sample Testcase 1
Testcase Input
5
1 2 3 4 5
3
Testcase Output
1 2 3 4 5
Explanation
Since 3 is the 3rd node from start and 3rd node from the end its value is swapped with itself hence no change.


*/
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node* next) : val(x), next(next) {}
};

int main() {
    int N, k;
    cin >> N;

    // Initialize the linked list with the first element
    int data;
    cin >> data;
    Node* head = new Node(data);
    Node* temp = head;

    // Fill the linked list with the remaining elements
    for (int i = 1; i < N; i++) {
        cin >> data;
        temp->next = new Node(data);
        temp = temp->next;
    }

    cin >> k;

    // Pointers to find the k-th node from start and k-th node from end
    Node* first = head;
    Node* second = head;

    // Move the 'first' pointer k-1 positions ahead
    for (int i = 1; i < k; i++) {
        first = first->next;
    }

    // Move the 'second' pointer N-k positions ahead to reach the k-th node from the end
    for (int j = 1; j < N - k + 1; j++) {
        second = second->next;
    }

    // Swap the values of the two nodes
    int tempVal = first->val;
    first->val = second->val;
    second->val = tempVal;

    // Print the modified list
    temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    return 0;
}
