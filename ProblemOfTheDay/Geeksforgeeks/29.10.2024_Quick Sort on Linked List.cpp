/*
Problem Link : https://www.geeksforgeeks.org/problems/quick-sort-on-linked-list/1
*/

/*Quick Sort on Linked List

You are given a Linked List. Sort the given Linked List using quicksort. 

Examples:

Input: Linked list: 1->6->2
Output: 1->2->6

Explanation:
After sorting the nodes, we have 1, 2 and 6.
Input: Linked list: 1->9->3->8
Output: 1->3->8->9

Explanation:
After sorting the nodes, we have 1, 3, 8 and 9. 
Constraints:
1<= size of linked list <= 105

*/

class Solution {
  public:
    static void partition(Node *pivot, Node *&left, Node *&right){
        Node *temp = pivot->next;
        while(temp){
            Node *nxt = temp->next;
            if(temp->data <= pivot->data){
                temp->next = left;
                left = temp;
            }
            else{
                temp->next = right;
                right = temp;
            }
            temp = nxt;
        }
    }
    struct Node* quickSort(struct Node* head) {
        // code here
        if(!head or !head->next){
            return head;
        }
        Node *left = NULL, *right = NULL;
        partition(head,left,right);
        left = quickSort(left);
        right = quickSort(right);
        
        Node *traversal = left;
        while(traversal and traversal->next){
            traversal = traversal->next;
        }
        if(traversal){
            traversal->next = head;
        }
        else{
            left = head;
        }
        head->next = right;
        return left;
    }
};