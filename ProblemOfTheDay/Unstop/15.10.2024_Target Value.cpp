/*
Problem Link : https://unstop.com/code/practice/297399
*/

/*Target Value

Problem Statement
Given a singly linked list where each node holds an integer, your task is to identify all pairs of numbers within the list that add up to a specified target value. Return the total count of such pairs.

Input Format
The first line contains an integer, N , representing the number of elements in the linked list.

The second line contains integers, each representing the data value of a node in the linked list.

The last line contains an integer, V , representing the target value.

Output Format
The output is a single integer that indicates the number of pairs in the linked list whose values add up to the target sum.

 
Constraints
1 <= N <= 10^4
0 <= VI <= 10^4

Sample Testcase 0
Testcase Input
5
1 2 3 4 5
9
Testcase Output
1
Explanation
The test case represents a linked list with 5 nodes containing values 1, 2, 3, 4, and 5. The target value is 9. The expected output is 1, indicating that there is one pair in the linked list (4, 5) that sums up the target value.
Sample Testcase 1
Testcase Input
4
10 20 30 40
9
Testcase Output
0
Explanation
The test case represents a linked list with 4 nodes containing values 10, 20, 30, and 40. The target value is set to 9. Since there are no pairs in the linked list that sum up to 9, the output is 0.

*/
#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

int countPairs(Node* head, int target) {
    unordered_map<int, int> map;
    int count = 0;

    Node* current = head;
    while (current != nullptr) {
        int complement = target - current->data;
        if (map.find(complement) != map.end()) {
            count += map[complement];
        }
        map[current->data]++;
        current = current->next;
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;

        Node* newNode = createNode(data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int target;
    cin >> target;

    int count = countPairs(head, target);
    cout << count << endl;

    return 0;
}