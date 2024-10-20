/*
Problem Link : https://www.geeksforgeeks.org/problems/sort-a-k-sorted-doubly-linked-list/1
*/

/*Sort a k sorted doubly linked list

Given a doubly linked list, each node is at most k-indices away from its target position. The problem is to sort the given doubly linked list. The distance can be assumed in either of the directions (left and right).

Examples :

Input: Doubly Linked List : 3 <-> 2 <-> 1 <-> 5 <-> 6 <-> 4 , k = 2
Output: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6

Explanation: After sorting the given 2-sorted list is 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6.
Input: Doubly Linked List : 5 <-> 6 <-> 7 <-> 3 <-> 4 <-> 4 , k = 3
Output: 3 <-> 4 <-> 4 <-> 5 <-> 6 <-> 7

Explanation: After sorting the given 3-sorted list is 3 <-> 4 <-> 4 <-> 5 <-> 6 <-> 7.
Expected Time Complexity: O(n*logk)
Expected Auxiliary Space: O(k)
Constraints:
1 <= number of nodes <= 105
1 <= k < number of nodes
1 <= node->data <= 109

*/
class compare{
  public: 
    bool operator()(DLLNode* a , DLLNode* b){
        return a->data > b->data;
    }
    
};
class Solution {
  public:
    // function to sort a k sorted doubly linked list
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        // code here
        if(!head || !head->next){
            return head;
        }
        
        priority_queue<DLLNode* , vector<DLLNode*> , compare> minHeap;
        
        DLLNode* curr = head;
        
        for(int i=0 ; i<=k && curr ; i++){
            minHeap.push(curr);
            curr = curr->next;
        }
        
        DLLNode* result = nullptr;
        DLLNode* tail   = nullptr;
        
        while(!minHeap.empty()){
            DLLNode* top = minHeap.top();
            minHeap.pop();
            
            if(!result){
                result = top;
                tail   = top;
                tail->prev = nullptr;
            }
            else{
                tail->next = top;
                top->prev = tail; 
                tail = top;
            }
            
            if(curr){
                minHeap.push(curr);
                curr = curr->next;
            }
        }
        
        tail->next = nullptr;
        return result;
        
    }
};