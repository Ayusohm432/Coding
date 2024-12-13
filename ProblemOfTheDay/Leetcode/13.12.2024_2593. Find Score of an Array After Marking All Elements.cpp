/*
Problem Link: https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements?envType=daily-question&envId=2024-12-13
*/

/*2593. Find Score of an Array After Marking All Elements

You are given an array nums consisting of positive integers.

Starting with score = 0, apply the following algorithm:

Choose the smallest integer of the array that is not marked. If there is a tie, choose the one with the smallest index.
Add the value of the chosen integer to score.
Mark the chosen element and its two adjacent elements if they exist.
Repeat until all the array elements are marked.
Return the score you get after applying the above algorithm.

 

Example 1:

Input: nums = [2,1,3,4,5,2]
Output: 7
Explanation: We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,1,3,4,5,2].
- 2 is the smallest unmarked element, so we mark it and its left adjacent element: [2,1,3,4,5,2].
- 4 is the only remaining unmarked element, so we mark it: [2,1,3,4,5,2].
Our score is 1 + 2 + 4 = 7.
Example 2:

Input: nums = [2,3,5,1,3,2]
Output: 5
Explanation: We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,3,5,1,3,2].
- 2 is the smallest unmarked element, since there are two of them, we choose the left-most one, so we mark the one at index 0 and its right adjacent element: [2,3,5,1,3,2].
- 2 is the only remaining unmarked element, so we mark it: [2,3,5,1,3,2].
Our score is 1 + 2 + 2 = 5.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 106


*/

//Approach-1
class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> result(n);

        for(int i=0; i<n; i++){
            result[i] = {nums[i], i};
        }

        sort(begin(result), end(result));

        long long score = 0;
        vector<bool> visited(n, false);

        for(int i=0; i<n; i++){
            int ele = result[i].first;
            int idx = result[i].second;

            if(visited[idx] == false){
                visited[idx] = true;
                score += ele;

                if(idx-1 >=0 && visited[idx-1] == false){
                    visited[idx-1] = true;
                }

                if(idx+1 < n && visited[idx+1] == false){
                    visited[idx+1] = true;
                }
            }
        }
        return score;
    }
};

//Approach-2
#define P pair<int, int>
class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);

        priority_queue<P, vector<P>, greater<P>> pq;

        for(int i=0; i<n; i++){
            pq.push({nums[i], i});
        }

        long long score = 0;
        while(!pq.empty()){
            P temp = pq.top();
            int ele = temp.first;
            int idx = temp.second;
            pq.pop();

            if(!visited[idx]){
                visited[idx] = true;
                score += ele;

                if(idx-1 >= 0 && !visited[idx-1]){
                    visited[idx - 1] = true;
                }
                if(idx+1 < n && !visited[idx+1]){
                    visited[idx+1] = true;
                }
            }
        }
        return score;
    }
};