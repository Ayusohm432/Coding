/*
Problem Link : https://unstop.com/code/practice/297400
*/

/*Remove multiple Occurrence

Problem Statement
Bob has a LinkedList with nodes sorted in ascending order. Some nodes have duplicate values. Combine these duplicates into a single node and return the updated LinkedList.

Input Format
The first line contains an integer N, representing the size of the LinkedList.

The second line contains N space-separated integers, representing the data of the LinledList.

Output Format
 Return the updated LinkedList after merging the duplicate nodes.

Constraints
1 ≤  N ≤10^5

1 ≤  Arr[i] ≤10^5

Sample Testcase 0
Testcase Input
5
1 1 1 1 1
Testcase Output
1
Explanation
1 occurs multiple times, so merging them into 1.
Sample Testcase 1
Testcase Input
5
1 2 2 3 3
Testcase Output
1 2 3
Explanation
We can see that 2 and 3 occur 2 times, so we merge them into one node and display the LinkedList.

*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *next;
    int data;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

void addNode(Node *&head, int x)
{
    if (head == nullptr)
    {
        head = new Node(x);
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new Node(x);
}

void removeOccurence()
{
    Node *head = nullptr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        addNode(head, x);
    }
    Node *curr = head, *prev = nullptr;
    while (curr != NULL)
    {
        if (prev == nullptr || curr->data != prev->data)
        {
            prev = curr;
            curr = curr->next;
        }
        else if (curr->data == prev->data)
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
    }
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}

int main()
{
    removeOccurence();
    return 0;
}