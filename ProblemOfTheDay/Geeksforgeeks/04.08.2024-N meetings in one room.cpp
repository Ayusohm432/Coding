/*
problem Link :- https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
*/

/*N meetings in one room


You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is the start time of meeting i and end[i] is the finish time of meeting i. Return the maximum number of meetings that can be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time. 

Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

Examples :

Input: n = 6, start[] = [1, 3, 0, 5, 8, 5], end[] =  [2, 4, 6, 7, 9, 9]
Output: 4
Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2), (3, 4), (5,7) and (8,9)
Input: n = 3, start[] = [10, 12, 20], end[] = [20, 25, 30]
Output: 1
Explanation: Only one meetings can be held with given start and end timings.
Expected Time Complexity: O(n*logn)
Expected Auxilliary Space: O(n)

Constraints:
1 ≤ n ≤ 105
0 ≤ start[i] < end[i] ≤ 106

*/

//{ Driver Code Starts
// #include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        vector<pair<int, int>> meetings;
        for (int i = 0; i < n; i++) {
            meetings.push_back({start[i], end[i]});
        }
        
        sort(meetings.begin(), meetings.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        });
        
        int count = 1;

        int prevEnd = meetings[0].second;
        

        for (int i = 1; i < n; i++) {
           if (meetings[i].first > prevEnd) {
                count++;
                prevEnd = meetings[i].second;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends