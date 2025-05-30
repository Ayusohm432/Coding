/*
Problem Link: https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1
*/

/*Merge K sorted linked lists

Given an array arr[] of n sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list, then return the head of the merged linked list.

Examples:

Input: arr[] = [1 -> 2 -> 3, 4 -> 5, 5 -> 6, 7 -> 8]
Output: 1 -> 2 -> 3 -> 4 -> 5 -> 5 -> 6 -> 7 -> 8
Explanation:
The arr[] has 4 sorted linked list of size 3, 2, 2, 2.
1st list: 1 -> 2-> 3
2nd list: 4 -> 5
3rd list: 5 -> 6
4th list: 7 -> 8
The merged list will be:

Input: arr[] = [1 -> 3, 8, 4 -> 5 -> 6]
Output: 1 -> 3 -> 4 -> 5 -> 6 -> 8
Explanation:
The arr[] has 3 sorted linked list of size 2, 3, 1.
1st list: 1 -> 3
2nd list: 8
3rd list: 4 -> 5 -> 6
The merged list will be:

Constraints
1 <= total no. of nodes <= 105
1 <= node->data <= 103

*/

/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution
{
public:
    Node *mergeKLists(vector<Node *> &arr)
    {
        // Your code here
        Node *temp = new Node(-1);
        Node *nexti = temp;
        priority_queue<pair<int, Node *>, vector<pair<int, Node *>>, greater<pair<int, Node *>>> pq;

        for (auto *it : arr)
        {
            pq.push({it->data, it});
        }

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int data = it.first;
            Node *node = it.second;

            nexti->next = node;
            nexti = node;
            if (node->next)
            {
                pq.push({node->next->data, node->next});
            }
        }
        return temp->next;
    }
};