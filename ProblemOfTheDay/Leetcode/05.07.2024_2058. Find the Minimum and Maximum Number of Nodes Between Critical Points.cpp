/*
Problem Link :- https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/?envType=daily-question&envId=2024-07-05
*/

/*2058. Find the Minimum and Maximum Number of Nodes Between Critical Points

A critical point in a linked list is defined as either a local maxima or a local minima.

A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.

A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].

 

Example 1:


Input: head = [3,1]
Output: [-1,-1]
Explanation: There are no critical points in [3,1].
Example 2:


Input: head = [5,3,1,2,5,1,2]
Output: [1,3]
Explanation: There are three critical points:
- [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less than 3 and 2.
- [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is greater than 2 and 1.
- [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less than 5 and 2.
The minimum distance is between the fifth and the sixth node. minDistance = 6 - 5 = 1.
The maximum distance is between the third and the sixth node. maxDistance = 6 - 3 = 3.
Example 3:


Input: head = [1,3,2,2,3,2,2,2,7]
Output: [3,3]
Explanation: There are two critical points:
- [1,3,2,2,3,2,2,2,7]: The second node is a local maxima because 3 is greater than 1 and 2.
- [1,3,2,2,3,2,2,2,7]: The fifth node is a local maxima because 3 is greater than 2 and 2.
Both the minimum and maximum distances are between the second and the fifth node.
Thus, minDistance and maxDistance is 5 - 2 = 3.
Note that the last node is not considered a local maxima because it does not have a next node.
 

Constraints:

The number of nodes in the list is in the range [2, 105].
1 <= Node.val <= 105


*/

//Approach-1
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        int currentPosition = 1;  
        int prevCriticalPos = 0;
        int firstCriticalPos = 0;   

        int minDist = INT_MAX;

        while(curr->next != nullptr){
            if((curr->val < prev->val && curr->val < curr->next->val) || (curr->val > prev->val && curr->val > curr->next->val)){
                if(prevCriticalPos == 0){
                    prevCriticalPos = currentPosition;
                    firstCriticalPos = currentPosition;
                }
                else{
                    minDist = min(minDist , currentPosition-prevCriticalPos);
                    prevCriticalPos = currentPosition;
                }
            }
            currentPosition++;
            prev = curr;
            curr = curr->next;
        }
        if(minDist == INT_MAX){
            return {-1,-1};
        }
        return {minDist,prevCriticalPos-firstCriticalPos};
    }
};

//Approach-2

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int prevVal = 0;
        int currVal = 0;
        int nextVal = 0;

        int minDist = INT_MAX;
        int firstCriticalPos = 0;
        int prevCriticalPos = 0;

        int i=0;
        vector<int> result = {-1,-1};

        while(head != nullptr){
            prevVal = currVal;
            currVal = nextVal;
            nextVal = head->val;

            if(prevVal != 0 && currVal != 0 && nextVal != 0 && ((prevVal > currVal && currVal < nextVal) || (prevVal < currVal && currVal > nextVal))){
                if(firstCriticalPos == 0){
                    firstCriticalPos = i;
                }
                else{
                    minDist = min(minDist , i-prevCriticalPos);
                    result = {minDist , i-firstCriticalPos};
                }

                prevCriticalPos = i;
            }

            i++;
            head = head->next;
        }
        return result;
    }
};