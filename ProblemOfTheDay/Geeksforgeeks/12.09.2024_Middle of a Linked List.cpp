/*
Proble Link : https://www.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1
*/

/*Middle of a Linked List

Given the head of a linked list, the task is to find the middle. For example, the middle of 1-> 2->3->4->5 is 3. If there are two middle nodes (even count), return the second middle. For example, middle of 1->2->3->4->5->6 is 4.

Examples:

Input: Linked list: 1->2->3->4->5
Output: 3

Explanation: The given linked list is 1->2->3->4->5 and its middle is 3.
Input: Linked list: 2->4->6->7->5->1
Output: 7 

Explanation: The given linked list is 2->4->6->7->5->1 and its middle is 7.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= no. of nodes <= 105

*/
//Link list Node
struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};


//Approach-1

class Solution {
  public:
    /* Should return data of middle node. If linked list is empty, then -1 */
    int getMiddle(Node* head) {
        // code here
        if(!head){
            return -1;
        }
        
        Node* temp = head;
        
        int size = 0;
        while(temp){
            size++;
            temp = temp->next;
        }
        
        int middle = (size / 2) + 1;
        
        
        Node* current = head;
        while(--middle){
            current = current->next;
        }
        
        return current->data;
    }
};

//Approach-2
class Solution {
  public:
    /* Should return data of middle node. If linked list is empty, then -1 */
    int getMiddle(Node* head) {
        // code here
        if(!head){
            return -1;
        }
        
        Node* temp = head;
        
        int size = 0;
        while(temp){
            size++;
            temp = temp->next;
        }
        
        int middle = size/2;
        
        
        Node* current = head;
        while(middle--){
            current = current->next;
        }
        
        return current->data;
    }
};


//Approach-3
class Solution {
  public:
    /* Should return data of middle node. If linked list is empty, then -1 */
    int getMiddle(Node* head) {
        // code here
        if(!head){
            return -1;
        }
        
        Node* slow = head ;
        Node* fast = head->next;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return fast != nullptr ? slow->next->data : slow->data;
    }
};
