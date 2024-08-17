/*
Problem Link :- https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1
*/

/*Product array puzzle

Given an array nums[], construct a Product Array nums[] such that nums[i] is equal to the product of all the elements of nums except nums[i].

Examples:

Input: nums[] = [10, 3, 5, 6, 2]
Output: [180, 600, 360, 300, 900]
Explanation: For i=0, P[i] = 3*5*6*2 = 180.
For i=1, P[i] = 10*5*6*2 = 600.
For i=2, P[i] = 10*3*6*2 = 360.
For i=3, P[i] = 10*3*5*2 = 300.
For i=4, P[i] = 10*3*5*6 = 900.
Input: nums[] = [12,0]
Output: [0, 12]
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= nums.size() <= 1000
0 <= nums[i] <= 200
nums[i] may contain duplicates.




*/

//{ Driver Code Starts
// Initial template for C++

// #include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
        long long int prod = 1 , c = 0 , index = -1 , n = nums.size();
        
        for(int i=0 ; i<n ; i++){
            if(nums[i]){
                prod *= nums[i];
            }
            else{
                c++;
                index = i;
            }
        }
        
        vector<long long int> ans(n , 0);
        
        if(c > 1){
            return ans;
        }
        if(c == 1){
            ans[index] = prod;
            return ans;
        }
        
        for(int i=0 ; i<n ; i++){
            ans[i] = prod/nums[i];
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends