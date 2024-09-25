/*
Problem Link : https://unstop.com/code/practice/262881
*/

/*Linked List

Problem Statement
N students were standing in a line. Each one has connectivity to the one behind it. Every student has a number printed on their shirt.

Print the numbers on thier shirts such that the number on the last student is printed first and the first one is printed last.

The numbers are provided in the form of a linked list.

Note: The number is in the range of -10^7 to 10^7.

Input Format
The first line of input contains an integer N which determines the number of students.

The second line of input contains the numbers printed on the shirt.

Output Format
Display the numbers such that it is reverse of the original order. 

Constraints
0< N < 5*10^3

-10^7<= number<=10^7

Sample Testcase 0
Testcase Input
2
3 5
Testcase Output
5 3
Explanation
The given numbers on the t-shirts in the order are: {3,5}


Therefore the reversed order will be: {5,3}

Sample Testcase 1
Testcase Input
5
1 5 4 7 8
Testcase Output
8 7 4 5 1
Explanation
The original order of the numbers on the t-shirt is: {1, 5, 4, 7, 8}


The reversed order wil be: {8, 7, 4, 5, 1}

*/

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = (*head);
    (*head) = newNode;
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;

    Node* head = nullptr;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        insert(&head, num);
    }

    printList(head);

    return 0;
}