/*
Problem link : https://unstop.com/code/practice/299709
*/

/*Mountains and Valley

Problem Statement
Given a linked list, determine if it exhibits a continuous mountain and valley pattern.

A continuous mountain and valley pattern is characterized by a sequence of nodes where the values consistently alternate between increasing and decreasing.

Note: if only one node, then return 1.

Input Format
The first line contains an integer 'n' representing the number of nodes in the linked list.

The second line contains 'n' space-separated integers representing the values of the nodes in the linked list.

Output Format
'1' indicates that the linked list follows a continuous mountain and valley pattern.

'0' indicates the linked list does not follow the continuous mountain and valley pattern.

Constraints
1 <= n <= 4 *10^3
0 <=elements of linked list  <= 10^4

Sample Testcase 0
Testcase Input
5
1 2 3 2 1
Testcase Output
0
Explanation
1 -> 2 -> 3 -> 2 -> 1
As 1 to 3 is increasing, that means values consistently do not alternate between increasing and decreasing. So the answer is 0.
Sample Testcase 1
Testcase Input
5
1 2 1 2 1
Testcase Output
1
Explanation
1 -> 2 -> 1 -> 2 -> 1
As values consistently alternate between increasing and decreasing. So the answer is 1

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
};

bool solve(Node* head, int prev, bool isPeak)
{
    if(head==0)
    {
        return 1;
    }

    if((isPeak && head->data>prev) || (!isPeak && head->data<prev))
    {
        return solve(head->next,head->data,!isPeak);
    }
    
    return 0;
}


int top_down(LinkedList ll) {
    // User should implement this function
    Node* head=ll.head;
    if(head->next==0)
    {
        return 1;
    }
    int a=head->data;
    head=head->next;
    int b=head->data;
    head=head->next;

    if(a<b)
    {
        return solve(head,b,0);
    }
    else
    {
        return solve(head,b,1);
    }

    return 0;
}

int main() {
    LinkedList ll;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        ll.push(t);
    }
    cout << top_down(ll);
    return 0;
}