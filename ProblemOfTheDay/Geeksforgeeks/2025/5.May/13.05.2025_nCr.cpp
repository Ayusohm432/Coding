/*
Problem Link: https://www.geeksforgeeks.org/problems/ncr1019/1
*/

/*nCr

Given two integer values n and r, the task is to find the value of Binomial Coefficient nCr

A binomial coefficient nCr can be defined as the coefficient of xr in the expansion of (1 + x)n that gives the number of ways to choose r objects from a set of n objects without considering the order.
The binomial coefficient nCr is calculated as : C(n,r) = n! / r! * (n-r) !
Note: If r is greater than n, return 0.
It is guaranteed that the value of nCr will fit within a 32-bit integer.

Examples:

Input: n = 5, r = 2
Output: 10
Explaination: The value of 5C2 is calculated as 5!/(5−2)!*2! = 5!/3!*2! = 10.
Input: n = 2, r = 4
Output: 0
Explaination: Since r is greater than n, thus 2C4 = 0
Input: n = 5, r = 0
Output: 1
Explaination: The value of 5C0 is calculated as 5!/(5−0)!*0! = 5!/5!*0! = 1.
Constraints:
1 ≤ n ≤ 100
1 ≤ r ≤ 100

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int nCr(int n, int r) {
        // code here
        if(r > n){
            return 0;
        }
        
        long long result = 1;
        for(int i=1; i<=r; i++){
            result = result * (n - r + i) / i;
        }
        
        return (int)result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends