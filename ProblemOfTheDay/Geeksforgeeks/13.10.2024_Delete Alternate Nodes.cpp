/*
Problem Link : https://www.geeksforgeeks.org/problems/delete-alternate-nodes/1
*/

/*Delete Alternate Nodes

Given a Singly Linked List, Delete all alternate nodes of the list ie delete all the nodes present in even positions.

Examples :

Input: LinkedList: 1->2->3->4->5->6
 
Output: 1->3->5

Explanation: Deleting alternate nodes ie 2, 4, 6 results in the linked list with elements 1->3->5.
Input: LinkedList: 99->59->42->20
 
Output: 99->42
 
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= number of nodes <= 105
1 <= node->data <= 103

*/
class Solution {
  public:
    void deleteAlt(struct Node *head) {
        // Code here
        Node *temp = head;
        if(!head){
            return;
        }
        
        while(temp && temp->next){
            Node *nodeToDelete = temp->next;
            temp->next = temp->next->next;
            free(nodeToDelete);
            temp = temp->next;
        }
    }
};