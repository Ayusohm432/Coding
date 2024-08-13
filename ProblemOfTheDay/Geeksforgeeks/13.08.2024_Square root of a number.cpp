/*
Problem Link :- https://www.geeksforgeeks.org/problems/square-root/1
*/

/*Square root of a number

Given an integer n, find the square root of n. If n is not a perfect square, then return the floor value.

Floor value of any number is the greatest Integer which is less than or equal to that number

Examples:

Input: n = 5
Output: 2
Explanation: Since, 5 is not a perfect square, floor of square_root of 5 is 2.
Input: n = 4
Output: 2
Explanation: Since, 4 is a perfect square, so its square root is 2.
Expected Time Complexity: O(logn)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ n ≤ 107


*/

//{ Driver Code Starts
// #include <bits/stdc++.h>
#include<iostream>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
public:
    long long int floorSqrt(long long int n) {
        if (n == 0 || n == 1) {
            return n;
        }

        long long int left = 1;
        long long int right = n;
        long long int result = 0;

        while (left <= right) {
            long long int mid = left + (right - left) / 2;
            long long int mid_squared = mid * mid;

            if (mid_squared == n) {
                return mid;
            } else if (mid_squared < n) {
                result = mid; // Update the result for the floor value
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends