/*
Problem Link :- https://leetcode.com/problems/merge-nodes-in-between-zeros/?envType=daily-question&envId=2024-07-04
*/

/*2181. Merge Nodes in Between Zeros

You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.

For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.

Return the head of the modified linked list.

 

Example 1:


Input: head = [0,3,1,0,4,5,2,0]
Output: [4,11]
Explanation: 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 3 + 1 = 4.
- The sum of the nodes marked in red: 4 + 5 + 2 = 11.
Example 2:


Input: head = [0,1,0,3,0,2,2,0]
Output: [1,3,4]
Explanation: 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 1 = 1.
- The sum of the nodes marked in red: 3 = 3.
- The sum of the nodes marked in yellow: 2 + 2 = 4.


*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//Approach-1
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* root = new ListNode(-1);
        ListNode* temp = root;

        head = head->next;
        while (head) {
            int sum = 0;
            while (head && head->val != 0) { 
                sum += head->val;
                head = head->next;
            }
            temp->next = new ListNode(sum); 
            temp = temp->next;
            if (head) head = head->next; 
        }
        return root->next;
    }
};


//Approach-2
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* p1 = head->next;
        ListNode* p2 = p1;

        while(p2 != nullptr){
            int sum = 0;
            while(p2 != nullptr && p2->val != 0){
                sum += p2->val;
                p2 = p2->next;
            }
            p1->val = sum;
            p2 = p2->next;
            p1->next = p2;
            p1 = p1->next;
        }
        return head->next;
    }
};

//Approach-3
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
       head = head->next;

       if(head == nullptr){
        return head;
       } 
       ListNode* temp = head;
       int sum = 0;
       while(temp != nullptr && temp->val != 0){
        sum += temp->val;
        temp = temp->next;
       }
       head->val = sum;
       head->next = mergeNodes(temp);
       return head;
    }
};
