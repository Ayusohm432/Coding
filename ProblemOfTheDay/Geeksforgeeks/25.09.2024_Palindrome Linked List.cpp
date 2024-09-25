/*
Problem Link : https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1
*/

/*Palindrome Linked List

Given a singly linked list of integers. The task is to check if the given linked list is palindrome or not.

Examples:

Input: LinkedList: 1->2->1->1->2->1
Output: true
Explanation: The given linked list is 1->2->1->1->2->1 , which is a palindrome and Hence, the output is true.

Input: LinkedList: 1->2->3->4
Output: false
Explanation: The given linked list is 1->2->3->4, which is not a palindrome and Hence, the output is false.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1) 
Note: You should not use the recursive stack space as well

Constraints:
1 <= number of nodes <= 105
1 ≤ node->data ≤ 103


*/

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution {
    int count(Node* head){
        int temp = 0;
        while(head != nullptr){
            head = head->next;
            temp++;
        }
        return temp;
    }
    
  public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        // Your code here
        string first,second;
        int size = count(head);
        int temp = size/2;
        
        Node* curr = head;
        while(temp--){
            first += ('0' + curr->data);
            curr = curr->next;
        }
        
        if(size & 1){
            curr = curr->next;
        }
        
        temp = size/2;
        while(temp--){
            second += ('0' + curr->data);
            curr = curr->next;
        }
        
        reverse(second.begin() , second.end());
        
        return first == second;
    }
};