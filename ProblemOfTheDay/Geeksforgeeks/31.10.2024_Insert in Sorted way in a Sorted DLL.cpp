/*
Problem Link : https://www.geeksforgeeks.org/problems/insert-in-sorted-way-in-a-sorted-dll/1
*/

/*Insert in Sorted way in a Sorted DLL

Given a sorted doubly linked list and an element x, you need to insert the element x into the correct position in the sorted Doubly linked list(DLL).

Note: The DLL is sorted in ascending order

Example:

Input: LinkedList: 3->5->8->10->12 , x = 9

Output: 3->5->8->9->10->12

Explanation: Here node 9 is inserted in the Doubly Linked-List.
Input: LinkedList: 1->4->10->11 , x = 15

Output: 1->4->10->11->15

Constraints:
1 <= number of nodes <= 103
1 <= node -> data , x <= 104

*/

class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        // Code here
        Node* newNode = getNode(x);

        if (!head) return newNode;
    
        if (x < head->data) {
            newNode->next = head;
            head->prev = newNode;
            return newNode;
        }
    
        Node* curr = head;
        while (curr->next && curr->next->data < x) {
            curr = curr->next;
        }
    
        newNode->next = curr->next;
        newNode->prev = curr;
    
        if (curr->next) {
            curr->next->prev = newNode;
        }
    
        curr->next = newNode;
    
        return head;
        
    }
};