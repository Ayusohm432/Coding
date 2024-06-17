/*
Problem Link :- https://www.geeksforgeeks.org/problems/check-if-two-line-segments-intersect0017/1
*/

/* Check If two Line segments Intersect


Given the coordinates of the endpoints(p1,q1, and p2,q2) of the two line segments. Check if they intersect or not. If the Line segments intersect return true otherwise return false.

Note: Please check the intersection lies within the line segments.

Examples

Input: p1=(1,1), q1=(10,1), p2=(1,2), q2=(10,2)
Output: false
Explanation:The two line segments formed by p1-q1 and p2-q2 do not intersect.
Input: p1=(10,0), q1=(0,10), p2=(0,0), q2=(10,10)
Output: true
Explanation: The two line segments formed by p1-q1 and p2-q2 intersect.
Input: p1=(5,-2), q1=(13,2), p2=(2,-3), q2=(3,0)
Output: false
Explanation: The two line segments formed by p1-q1 and p2-q2 are intersecting beyond endpoints, so it is not considerable.
Expected Time Complexity: O(1)
Expected Auxillary Space: O(1)

Constraints:
-106<=X,Y(for all points)<=106

*/
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string doIntersect(int p1[], int p2[], int q1[], int q2[]) {
        // code here
        double m1=(p2[1]-p1[1])/double(p2[0]-p1[0]);
        double m2=(q2[1]-q1[1])/double(q2[0]-q1[0]);

        double check1=m1*(p1[0]-q1[0])-(p1[1]-q1[1]);
        double check2=m1*(p1[0]-q2[0])-(p1[1]-q2[1]);
        double check3=m2*(q1[0]-p1[0])-(q1[1]-p1[1]);
        double check4=m2*(q1[0]-p2[0])-(q1[1]-p2[1]);

        if(check1*check2>0 || check3*check4>0)return "false";
        return "true";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p1[2], q1[2], p2[2], q2[2];
        cin >> p1[0] >> p1[1] >> q1[0] >> q1[1] >> p2[0] >> p2[1] >> q2[0] >> q2[1];
        // if (q2[1] == -2) {
        //     cout << "true" << endl;
        //     return 0;
        // }
        Solution ob;
        // int a = ob.doIntersect(p1, q1, p2, q2);
        // if (a)
        cout << ob.doIntersect(p1, q1, p2, q2) << "\n";
    }
}
// } Driver Code Ends