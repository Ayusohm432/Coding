/*
Problem Link : https://unstop.com/code/practice/299841
*/

/*Range Square

Problem Statement
You are given a linked list and two integers, N1 and N2. Your task is to determine if any node in the linked list contains a value that is a perfect square of an integer within the range from N1 to N2 (both inclusive).

If there is at least one node in the linked list that holds such a value, the program should output 1. Otherwise, it should output 0.

Input Format
The first line contains two integers separated by a space, N1 and N2, representing the range of values.

The second line contains a single integer, N, indicating the number of elements in the linked list.

The third lines contain N space separated integer, representing values to be inserted into the linked list.

Output Format
Print 1 if any node in the linked list contains a value that is a perfect square of an integer between N1 and N2 (inclusive).

Print 0 if no such value is found in the linked list.

Constraints
1 <= N <= 10^4

1<=N1<=10^2

1<=N2<=10^2

0 <= element <= 10^5

Sample Testcase 0
Testcase Input
2 4
5
1 2 3 4 5
Testcase Output
1
Explanation
For the given test case, the range is from 2 to 4. The linked list has five elements: 1, 2, 3, 4, and 5. When checking for perfect square values within the range, we find that 4 is a perfect square. Therefore, the output is 1, indicating that a perfect square exists in the linked list.
Sample Testcase 1
Testcase Input
4 6
3
100 200 300
Testcase Output
0
Explanation
In the given test case, the range is from 4 to 6 (inclusive). The linked list contains three elements: 100, 200, and 300. However, none of these values are perfect squares within the range, so the output is 0.


*/

//Approach-1
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    int data; 
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

Node* createList(const vector<int>& list){
    Node* temp = new Node(0);
    Node* curr = temp;
    
    for(int val : list){
        curr->next = new Node(val);
        curr = curr->next;
    }
    return temp->next;
}

int findRangeSquare(Node* head , int n1 , int n2){
    Node* temp = head;
    while(temp){
        int val = temp->data;
        if(val > 0){
            int curr = sqrt(val);
            if(curr* curr == val && curr >= n1 && curr <= n2){
            return 1;
        }
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,n1,n2;
    cin>>n1>>n2>>n;

    vector<int> list(n);

    for(int i=0 ; i<n ; i++){
        cin>>list[i];
    }

    Node* head = createList(list);

    int result = findRangeSquare(head , n1 , n2);

    cout<<result;

    return 0;
}

//Approach-2
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* createList(const vector<int>& list) {
    if (list.empty()) return nullptr;
    
    Node* head = new Node(list[0]);
    Node* curr = head;
    
    for (size_t i = 1; i < list.size(); ++i) {
        curr->next = new Node(list[i]);
        curr = curr->next;
    }
    return head;
}

int findRangeSquare(Node* head, int n1, int n2) {
    while (head) {
        if (head->data > 0) {
            int root = sqrt(head->data);
            if (root * root == head->data && root >= n1 && root <= n2) {
                return 1;
            }
        }
        head = head->next;
    }
    return 0;
}

int main() {
    int n, n1, n2;
    cin >> n1 >> n2 >> n;

    vector<int> list(n);
    for (int i = 0; i < n; ++i) {
        cin >> list[i];
    }

    Node* head = createList(list);

    int result = findRangeSquare(head, n1, n2);

    cout << result << endl;

    return 0;
}
