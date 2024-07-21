/*
Problem link :- https://www.geeksforgeeks.org/problems/maximum-product-subset-of-an-array/1
*/

/*Maximum product subset of an array

Given an array arr. The task is to find and return the maximum product possible with the subset of elements present in the array.

Note:

The maximum product can be a single element also.
Since the product can be large, return it modulo 109 + 7.
Examples:

Input: arr[] = [-1, 0, -2, 4, 3]
Output: 24
Explanation: Maximum product will be ( -1 * -2 * 4 * 3 ) = 24
Input: arr[] = [-1, 0]
Output: 0
Explanation: Maximum product will be ( -1 * 0) = 0
Input: arr[] = [5]
Output: 5
Explanation: Maximum product will be 5.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= arr.size() <= 2 * 104
-10 <= arr[i] <= 10


*/

//{ Driver Code Starts
/* Driver program to test above function */

// #include <bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<vector>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        if(arr.size() == 1){
            return arr[0];
        }
        
        long long int pos = 1 , neg = 1 , negLar = INT_MIN , mod = 1e9+7 , c1= 0 , c2 = 0;\
        
        for(auto x : arr){
            if(x < 0){
                neg = (neg * (long long int)x) % mod;
                negLar = max(negLar , (long long int)x);
                c1++;
            }
            if(x > 0){
                pos = (pos * (long long int)x) % mod;
                c2++;
            }
        }
        
        if(c1 <=1 && c2 == 0){
            return 0;
        }
        if(neg < 0){
            neg /= negLar;
        }        
        
        return (pos * neg) % mod;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends