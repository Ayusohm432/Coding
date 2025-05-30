/*
Problem Link: https://www.geeksforgeeks.org/problems/meeting-rooms-iii/1
*/

/*Meeting Rooms III

You are given an integer n representing the number of rooms numbered from 0 to n - 1. Additionally, you are given a 2D integer array meetings[][] where meetings[i] = [starti, endi] indicates that a meeting is scheduled during the half-closed time interval [starti, endi). All starti values are unique.

Meeting Allocation Rules:

When a meeting starts, assign it to the available room with the smallest number.
If no rooms are free, delay the meeting until the earliest room becomes available. The delayed meeting retains its original duration.
When a room becomes free, assign it to the delayed meeting with the earliest original start time.
Determine the room number that hosts the most meetings. If multiple rooms have the same highest number of meetings, return the smallest room number among them.

Examples:

Input: n = 2, meetings[][] = [[0, 6], [2, 3], [3, 7], [4, 8], [6, 8]]
Output: 1
Explanation: Time 0: Both rooms available. [0,6] starts in room 0.
Time 2: Room 0 busy until 6. Room 1 available. [2,3] starts in room 1.
Time 3: Room 1 frees up. [3,7] starts in room 1.
Time 4: Both rooms busy. [4,8] is delayed.
Time 6: Room 0 frees up. Delayed [4,8] starts in room 0 [6,10).
Time 6: [6,8] arrives but both rooms busy. It’s delayed.
Time 7: Room 1 frees up. Delayed [6,8] starts in room 1 [7,9).
Meeting counts: [2, 3]
Input: n = 4, meetings[][] = [[0, 8], [1, 4], [3, 4], [2, 3]
Output: 2
Explanation: Time 0: All rooms available. [0,8] starts in room 0.
Time 1: Room 0 busy until 8. Rooms 1, 2, 3 available. [1,4] starts in room 1.
Time 2: Rooms 0 and 1 busy. Rooms 2, 3 available. [2,3] starts in room 2.
Time 3: Room 2 frees up. [3,4] starts in room 2.
Meeting counts: [1, 1, 2, 0]
Constraints:

1 ≤ n ≤ 104
1 ≤ meetings.size() ≤ 104
meetings[i].size() == 2
0 ≤ starti < endi ≤ 104

*/

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    typedef pair<int, int> P;
    int mostBooked(int n, vector<vector<int>> &meetings) {
        // code here
        sort(meetings.begin(), meetings.end());
        vector<int> freq(n, 0);
        
        int result = 0;
        int maxVal = 0;
        
        priority_queue<P, vector<P>, greater<P>> pq1;
        priority_queue<P, vector<P>, greater<P>> pq2;
        
        for(int i=0; i<n; i++){
            pq1.push({i, i});
        }
        
        for(auto& meeting : meetings){
            int start = meeting[0];
            int end = meeting[1];
            int emptyRoom;
            
            while(!pq2.empty() && pq2.top().first <= start){
                emptyRoom = pq2.top().second;
                pq2.pop();
                pq1.push({emptyRoom, emptyRoom});
            }
            
            if(!pq1.empty()){
                emptyRoom = pq1.top().second;
                pq1.pop();
                pq2.push({end, emptyRoom});
                freq[emptyRoom]++;
            }else{
                P temp = pq2.top();
                pq2.pop();
                int endTime = temp.first;
                emptyRoom = temp.second;
                int newEndTime = endTime + (end - start);
                pq2.push({newEndTime, emptyRoom});
                freq[emptyRoom]++;
            }
            
            if(freq[emptyRoom] > maxVal || (freq[emptyRoom] == maxVal && emptyRoom < result)){
                maxVal = freq[emptyRoom];
                result = emptyRoom;
            }
        }
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> m;
        vector<vector<int>> meetings(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            cin >> meetings[i][0] >> meetings[i][1];
        }
        Solution ob;
        cout << ob.mostBooked(n, meetings) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends