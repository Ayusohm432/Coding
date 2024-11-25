/*
Problem Link: https://unstop.com/code/practice/299511
*/

/*Linked List Multiplication

Problem Statement
You are given two numbers in the form of linked lists, where the digits are in reverse order.

One of these numbers will always be a single-digit number.

The task is to multiply these two numbers and return the result in reverse order in the form of a linked list

Input Format
The first line of input contains an integer N, representing the first linked list.

The Second line of input contains an integer M, representing the second linked list. 

Output Format
Display the multiplied result as a string of digits in reverse order, which corresponds to the linked list.

Constraints
0 ≤  N , M ≤10^6

Sample Testcase 0
Testcase Input
123
5
Testcase Output
1605
Explanation
As mentioned in the question, the numbers will look something like this as a LinkedList. 3 -> 2 ->1->null. 5->null. Output: 5->0->6->1. Now this list is in reverse format after reversing, the answer will be 1605.

Sample Testcase 1
Testcase Input
23
7
Testcase Output
224
Explanation
As mentioned in the question, the numbers will look something like this as a LinkedList. 3->2->null. 7->null. Output: 4 -> 2 -> 2. Now this list is in reverse format, after reversing the answer will be 224.


*/

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

long long linkedListToInt(ListNode* head) {
    long long number = 0;
    while (head != NULL) {
        number = number * 10 + head->val;
        head = head->next;
    }
    return number;
}

ListNode* intToLinkedList(long long number) {
    if (number == 0) {
        return new ListNode(0);
    }
    ListNode* head = NULL;
    ListNode* temp = NULL;
    while (number > 0) {
        ListNode* newNode = new ListNode(number % 10);
        if (!head) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
        number /= 10;
    }
    return head;
}

ListNode* linkedListMultiplication(ListNode* head1, ListNode* head2) {
    long long num1 = linkedListToInt(head1);
    long long num2 = linkedListToInt(head2);

    long long product = num1 * num2;

    ListNode* result = intToLinkedList(product);

    return result;
}

int main() {
    long long n,m;
    cin >> n >> m;

    ListNode* head1 = intToLinkedList(n);
    ListNode* head2 = intToLinkedList(m);

    ListNode* result = linkedListMultiplication(head1, head2);

    string ans;

    ListNode* temp = result;

    while(temp){
        int curr = temp->val;
        ans = to_string(curr) + ans;
        temp = temp->next;
    }

    cout << ans;
    return 0;
}

