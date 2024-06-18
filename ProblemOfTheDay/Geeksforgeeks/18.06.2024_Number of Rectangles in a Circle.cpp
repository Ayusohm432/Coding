/*
Problem Link :- https://www.geeksforgeeks.org/problems/rectangles-in-a-circle0457/1 
*/

/*Number of Rectangles in a Circle

Given a circular sheet of radius, r. Find the total number of rectangles with integral length and width that can be cut from the sheet that can fit on the circle, one at a time.

Examples :

Input: r=1
Output: 1
Explanation: Only 1 rectangle of dimensions 1x1.
Input: r=2
Output: 8
Explanation: The 8 possible rectangles are 
(1x1)(1x2)(1x3)(2x1)(2x2)(2x3)(3x1)(3x2).
Expected Time Complexity: O(r2)
Expected Auxillary Space: O(1)


Constraints:
1<=r<=1000 

*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int rectanglesInCircle(int r) {
        // code here
        int rectangles = 0 ;
        int l = 2*r;
        int b = 2*r;
        int p = 4*r*r;
        
        for(int i=1 ; i<l ; i++){
            for(int j=1 ; j<b ; j++){
                if((i*i+j*j) <= p){
                    rectangles++;
                }
            }
        }
        return rectangles;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.rectanglesInCircle(n);
        cout << ans << "\n";
    }
}
// } Driver Code Ends