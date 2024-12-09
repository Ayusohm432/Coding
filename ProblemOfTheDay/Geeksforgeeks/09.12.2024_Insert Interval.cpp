/*
Problem Link: https://www.geeksforgeeks.org/problems/insert-interval-1666733333/1
*/

/*Insert Interval

Geek has an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith event and intervals is sorted in ascending order by starti. He wants to add a new interval newInterval= [newStart, newEnd] where newStart and newEnd represent the start and end of this interval.

Help Geek to insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Examples:

Input: intervals = [[1,3], [4,5], [6,7], [8,10]], newInterval = [5,6]
Output: [[1,3], [4,7], [8,10]]
Explanation: The newInterval [5,6] overlaps with [4,5] and [6,7].
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,9]
Output: [[1,2], [3,10], [12,16]]
Explanation: The new interval [4,9] overlaps with [3,5],[6,7],[8,10].
Constraints:
1 ≤ intervals.size() ≤  105
0 ≤ start[i], end[i] ≤ 109

*/

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        vector<vector<int>> ans;
        bool merged=false;
        int start=newInterval[0],end=newInterval[1];
        for(auto x:intervals){
            if(x[1]<newInterval[0])ans.push_back(x);
            else if(x[0]>newInterval[1]){
                if(!merged){
                    ans.push_back({start,end});
                    merged=true;
                }
                ans.push_back(x);
            }
            else{
                start=min(start,x[0]);
                end=max(end,x[1]);
            }
        }
        if(!merged)ans.push_back({start,end});
        return ans;
    }
};