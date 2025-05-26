/*
Problem Link: https://www.geeksforgeeks.org/problems/sorted-insert-for-circular-linked-list/1
*/

/*Insert in Sorted Circular Linked List

Given a sorted circular linked list, the task is to insert a new node in this circular linked list so that it remains a sorted circular linked list.

Examples:

Input: head = 1->2->4, data = 2
Output: 1->2->2->4
Explanation: We can add 2 after the second node.

Input: head = 1->4->7->9, data = 5
Output: 1->4->5->7->9
Explanation: We can add 5 after the second node.

Constraints:
2 <= number of nodes <= 106
0 <= node->data <= 106
0 <= data <= 106

*/

/* structure for a node */
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = nullptr;
  }
}; 

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        Node* newNode = new Node(data);
        if(!head){
            newNode->next = newNode;
            return newNode;
        }
        
        Node* curr = head;
        Node* prev = nullptr;
        
        do{
            prev = curr;
            curr = curr->next;
            if(data >= prev->data && data <= curr->data){
                break;
            }
        }while(curr != head);
        
        prev->next = newNode;
        newNode->next = curr;
        
        if(data < head->data){
            return newNode;
        }
        
        return head;
    }
};