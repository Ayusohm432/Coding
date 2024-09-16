/*
Problem Link : https://leetcode.com/problems/minimum-time-difference/description/?envType=daily-question&envId=2024-09-16
*/

/*539. Minimum Time Difference

Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
 

Example 1:

Input: timePoints = ["23:59","00:00"]
Output: 1
Example 2:

Input: timePoints = ["00:00","23:59","00:00"]
Output: 0
 

Constraints:

2 <= timePoints.length <= 2 * 104
timePoints[i] is in the format "HH:MM".

*/
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();

        vector<int> minutes(n);

        for(int i=0 ; i<n ; i++){
            string time = timePoints[i];

            string hourStr = time.substr(0 , 2);
            string minStr  = time.substr(3);

            int hours    = stoi(hourStr);
            int minute = stoi(minStr);

            minutes[i] = hours * 60 + minute;
        }

        sort(begin(minutes) , end(minutes));

        int result = INT_MAX;
        for(int i=1 ; i<n ; i++){
            result = min(result , minutes[i] - minutes[i-1]);
        }

        return min(result , (24*60 - minutes[n-1]) + minutes[0]);

    }
};