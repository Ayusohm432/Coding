/*
Problem Link: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended?envType=daily-question&envId=2025-07-07
*/

/*1353. Maximum Number of Events That Can Be Attended

You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.

Return the maximum number of events you can attend.

 

Example 1:


Input: events = [[1,2],[2,3],[3,4]]
Output: 3
Explanation: You can attend all the three events.
One way to attend them all is as shown.
Attend the first event on day 1.
Attend the second event on day 2.
Attend the third event on day 3.
Example 2:

Input: events= [[1,2],[2,3],[3,4],[1,2]]
Output: 4
 

Constraints:

1 <= events.length <= 105
events[i].length == 2
1 <= startDayi <= endDayi <= 105

*/

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;

        int days = events[0][0];
        int i = 0;
        int result = 0;

        while(!pq.empty()  || i<n){
            while(i<n && events[i][0] == days){
                pq.push(events[i][1]);
                i++;
            }
            if(!pq.empty()){
                pq.pop();
                result++;
            }

            days++;

            while(!pq.empty() && pq.top() < days){
                pq.pop();
            }
        }
        return result;
    }
};