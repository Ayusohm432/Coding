/*
Problem Link: https://www.geeksforgeeks.org/problems/rotate-a-linked-list/1
*/

/*Rotate a Linked List

Given the head of a singly linked list, your task is to left rotate the linked list k times.

Examples:

Input: head = 10 -> 20 -> 30 -> 40 -> 50, k = 4
Output: 50 -> 10 -> 20 -> 30 -> 40
Explanation:
Rotate 1: 20 -> 30 -> 40 -> 50 -> 10
Rotate 2: 30 -> 40 -> 50 -> 10 -> 20
Rotate 3: 40 -> 50 -> 10 -> 20 -> 30
Rotate 4: 50 -> 10 -> 20 -> 30 -> 40

Input: head = 10 -> 20 -> 30 -> 40 , k = 6
Output: 30 -> 40 -> 10 -> 20 
 
Constraints:

1 <= number of nodes <= 105
0 <= k <= 109
0 <= data of node <= 109

*/

/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
public:
    int size(Node* head) {
        Node* temp = head;
        int cnt = 0;
        while (temp != nullptr) {
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }
    
    Node* rotate(Node* head, int k) {
        int s = size(head);
        int t = k % s;
        if (t == 0) return head;
        
        Node* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = head;
        
        Node* temp = head;
        while (t-- > 1) {
            temp = temp->next;
        }
        
        head = temp->next;
        temp->next = nullptr;
        return head;
    }
};
