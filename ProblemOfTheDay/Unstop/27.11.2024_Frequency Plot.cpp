/*
Problem link: https://unstop.com/code/practice/307597
*/

/*Frequency Plot

Problem Statement
Given a linked list of size N, where each element is a positive integer, the task is to find the largest element in the list with the minimum frequency. In other words, you need to determine the integer value that appears the least number of times in the list but has the highest value among those least frequent elements.

Input Format
The first line contains an integer, N, representing the size of the linked list.
The next line contains N space-separated positive integers, representing the elements of the linked list.
Output Format
The output is a single integer, representing the largest element with the minimum frequency in the linked list.

Constraints
1 <= N<= 10^5
0 <= element <= 10^3

Sample Testcase 0
Testcase Input
5
2 2 1 50 5
Testcase Output
50
Explanation
The test case represents a linked list with 5 elements: 2, 2, 1, 50, and 5. Among these elements, the largest number with the minimum frequency is 50, appearing only once in the linked list. Thus, the output is 50.

Sample Testcase 1
Testcase Input
7
8 1 2 8 8 2 1
Testcase Output
2
Explanation
The given test case has a linked list with 7 elements: 8, 1, 2, 8, 8, 2, and 1. The largest element with the minimum frequency is 2, which appears twice in the linked list. Therefore, the output is 2.

*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList {
    Node* head;
    Node* tail;
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void push(int data) {
        if (head == NULL) {
            Node* temp = new Node(data);
            head = temp;
            tail = temp;
        } else {
            Node* temp = new Node(data);
            tail->next = temp;
            tail = temp;
        }
    }

    int find_largest_min_freq() {
        unordered_map<int, int> freqMap;
        Node* temp = head;
        while (temp != NULL) {
            freqMap[temp->data]++;
            temp = temp->next;
        }

        int minFreq = INT_MAX;
        int largestMinFreq = INT_MIN;
        for (auto& pair : freqMap) {
            if (pair.second < minFreq) {
                minFreq = pair.second;
                largestMinFreq = pair.first;
            } else if (pair.second == minFreq) {
                largestMinFreq = max(largestMinFreq, pair.first);
            }
        }

        return largestMinFreq;
    }
};

// Driver code
int main() {
    LinkedList ll;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        ll.push(t);
    }

    cout << ll.find_largest_min_freq();
    return 0;
}
