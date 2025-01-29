/*
Problem link: https://unstop.com/code/practice/307299
*/

/*Consecutive Longest arithmetic Progression

Problem Statement
Given a linked list, the task is to find the longest length of consecutive items in the linked list that form an arithmetic progression (AP). Display the length of the longest sequence that satisfies the properties of an arithmetic progression.

Input Format
The first line of input contains an integer N, representing the size of the linked list.

The second line of input contains N space seperated integers,representing the values of the linked list.

Output Format
Display the Longest length of arithmetic Progression with consecutive elements in the Linked list.

Constraints
1 <= N <= 10^3
0 <= Node.val <= 10^6

Sample Testcase 0
Testcase Input
5
1 2 3 4 5
Testcase Output
5
Explanation
1 ->2->3->4->5 all have a common difference as 1 so the longest length of ap is 5.

Sample Testcase 1
Testcase Input
5 
0 5 10 15 100
Testcase Output
4
Explanation
0-> 5 -> 10 -> 15 have a common difference as 5, so the longest length of ap is 4.

*/

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

int longest_arithmetic_progression(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return 1;
    }

    int max_length = 1;
    ListNode* current = head;
    while (current != NULL && current->next != NULL) {
        int diff = current->next->val - current->val;
        int length = 2;
        ListNode* next_node = current->next;
        while (next_node->next != NULL && next_node->next->val - next_node->val == diff) {
            length++;
            next_node = next_node->next;
        }
        max_length = std::max(max_length, length);
        current = next_node;
    }
    return max_length;
}

int main() {
    int n;
    std::cin >> n;
    if (n == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }
    
    std::vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> values[i];
    }
    
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (int i = 1; i < n; ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    
    int result = longest_arithmetic_progression(head);
    std::cout << result << std::endl;
    
    // Free memory
    current = head;
    while (current != NULL) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }
    return 0;
}

