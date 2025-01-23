/*
Problem Link: https://unstop.com/code/practice/297466
*/

/*Form Double–Linked List From ArrayList Node

Problem Statement
You are provided with a 2D array(N*M). Your task is to create an ArrayList of Node objects, where each row of the 2D array corresponds to one entry in the ArrayList. After that, a doubly-linked list is constructed, arranging nodes first by even indices from the ArrayList, followed by the odd indices.

Print the linked list.

Input Format
The first line contains an integer N, representing the size of the array row.
The second line contains an integer M, representing the size of array col.
The third line contains an array of space-seperated integers.
Output Format
Print the linked list.

Constraints
1 <= N < 10^2
1 <= M < 10^2
Sample Testcase 0
Testcase Input
4
4
2 4 5 3
5 3 6 7
3 6 6 8
4 2 8 9
Testcase Output
2 <---> 4 <---> 5 <---> 3 <---> 3 <---> 6 <---> 6 <---> 8 <---> 5 <---> 3 <---> 6 <---> 7 <---> 4 <---> 2 <---> 8 <---> 9 <---> null
Explanation
First, make a Node arraylist from array
[[2 → 4 → 5 → 3 ] [5 → 3 → 6 → 7] [3 → 6 → 6 → 8] [4 → 2 → 8 → 9]]
Then rearrange them first will come to the even index node and then odd index nodes”s to form linkedlist
2 <---> 4 <---> 5 <---> 3 <---> 3 <---> 6 <---> 6 <---> 8 <---> 5 <---> 3 <---> 6 <---> 7 <---> 4 <---> 2 <---> 8 <---> 9 <---> null
Sample Testcase 1
Testcase Input
4
6
2 4 5 3 6 7
5 3 6 3 6 7
3 6 7 2 6 8
4 2 1 6 8 9
Testcase Output
2 <---> 4 <---> 5 <---> 3 <---> 6 <---> 7 <---> 3 <---> 6 <---> 7 <---> 2 <---> 6 <---> 8 <---> 5 <---> 3 <---> 6 <---> 3 <---> 6 <---> 7 <---> 4 <---> 2 <---> 1 <---> 6 <---> 8 <---> 9 <---> null
Explanation
First, make Node arraylist from an array
[[2→ 4 → 5 → 3 → 6 → 7] [5 → 3 → 6 → 3 → 6 → 7] [3 → 6 → 7 → 2 → 6 → 8] [4 → 2 → 1 → 6 → 8 → 9]]

Then rearrange them first will come to the even index node and then odd index nodes”s to form linkedlist
2 <---> 4 <---> 5 <---> 3 <---> 6 <---> 7 <---> 3 <---> 6 <---> 7 <---> 2 <---> 6 <---> 8 <---> 5 <---> 3 <---> 6 <---> 3 <---> 6 <---> 7 <---> 4 <---> 2 <---> 1 <---> 6 <---> 8 <---> 9 <---> null

*/

#include <iostream>
#include <vector>

struct DoubleNode {
    int doubledata;
    DoubleNode* doubleprev;
    DoubleNode* doublenext;
    DoubleNode(int val) : doubledata(val), doubleprev(nullptr), doublenext(nullptr) {}
};

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void createNodeList(const std::vector<std::vector<int>> &arr, std::vector<Node *> &list)
{
    for (const auto &row : arr)
    {
        Node *head = nullptr;
        Node *prev = nullptr;
        for (int val : row)
        {
            Node *newNode = new Node(val);
            if (!head)
            {
                head = newNode;
            }
            else
            {
                prev->next = newNode;
            }
            prev = newNode;
        }
        list.push_back(head);
    }
}

DoubleNode *createDoubleLinkedList(const std::vector<Node *> &list)
{
    DoubleNode *head = nullptr;
    DoubleNode *tail = nullptr;

    for (int i = 0; i < list.size(); i += 2)
    {
        Node *current = list[i];
        while (current)
        {
            DoubleNode *newDoubleNode = new DoubleNode(current->data);
            if (!head)
            {
                head = newDoubleNode;
                tail = head;
            }
            else
            {
                tail->doublenext = newDoubleNode;
                newDoubleNode->doubleprev = tail;
                tail = newDoubleNode;
            }
            current = current->next;
        }
    }

    for (int i = 1; i < list.size(); i += 2)
    {
        Node *current = list[i];
        while (current)
        {
            DoubleNode *newDoubleNode = new DoubleNode(current->data);
            if (!head)
            {
                head = newDoubleNode;
                tail = head;
            }
            else
            {
                tail->doublenext = newDoubleNode;
                newDoubleNode->doubleprev = tail;
                tail = newDoubleNode;
            }
            current = current->next;
        }
    }

    return head;
}


DoubleNode *user_logic(int n, int m, const std::vector<std::vector<int>> &arr)
{
    std::vector<Node *> list;
    createNodeList(arr, list);
    return createDoubleLinkedList(list);
}


void print_double_linked_list(DoubleNode* head) {
    DoubleNode* current = head;
    while (current != nullptr) {
        std::cout << current->doubledata << " <---> ";
        current = current->doublenext;
    }
    std::cout << "null" << std::endl;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> arr(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> arr[i][j];
        }
    }

    DoubleNode* double_linked_list_head = user_logic(n, m, arr);
    print_double_linked_list(double_linked_list_head);

    return 0;
}