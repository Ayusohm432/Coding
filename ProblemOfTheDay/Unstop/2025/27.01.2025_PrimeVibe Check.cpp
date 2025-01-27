/*
Problem Link: https://unstop.com/code/practice/505576
*/

/*PrimeVibe Check

Problem Statement
Given a singly linked list where each node contains a single-digit integer, your task is to process the linked list to determine a specific property of the resulting number. First, concatenate the digits of the linked list sequentially to form a single number. Reverse this number, and calculate the sum of its digits. Subtract this sum from the reversed number, and check whether the resulting value is an even or a odd.

Input Format
The first line of input contains a single integer N, representing the size of linked list.

The second line of input contains singly linked list represented by a sequence of nodes, where each node contains a single-digit integer (0-9) separated by space.

Output Format
Return even if the final number is an even number. Otherwise, return odd.

Constraints
1 <= N <= 15

0 <= node <= 9

Sample Testcase 0
Testcase Input
5
3 2 2 8 9
Testcase Output
odd
Explanation
We have: 3 -> 2 -> 2 -> 8 -> 9.
After concatenating, we get: 32289
Reverse: 98223.
Sum of digits: 9 + 8 + 2 + 2 + 3 = 24
Reverse - Sum = 98223 - 24 = 98199 (odd).

Sample Testcase 1
Testcase Input
3
0 1 2
Testcase Output
even
Explanation
We have: 0 -> 1-> 2.
After concatenating: 012 , i.e. 12
Reverse: 21
Sum of digits: 1 + 2 = 3
Reverse - Sum : 21 - 3 = 18 (even)

*/

#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

string user_logic(ListNode* head) {
    string num="";
    long long sum = 0;
    while(head!=nullptr){
        num += to_string(head->val);
        sum += head->val;
        head = head->next;
    }
    string reversed ="";
    int i=0;
    while(i<num.size()){
        if(num[i]=='0') i++;
        else break;
    }
    reversed=num.substr(i);

    reverse(reversed.begin(), reversed.end());

    long long reversedNum =stol(reversed);

    if((reversedNum-sum)%2==0) return "even";
    else return "odd";

    return "";
}

int main() {
    int N;
    cin >> N;
    ListNode* head = NULL;
    ListNode* tail = NULL;
    for (int i = 0; i < N; i++) {
        int value;
        cin >> value;
        ListNode* newNode = new ListNode(value);
        if (!head) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }
    string result = user_logic(head);
    cout << result << endl;
    return 0;
}