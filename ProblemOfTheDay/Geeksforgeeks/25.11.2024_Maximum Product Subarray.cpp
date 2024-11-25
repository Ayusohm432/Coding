/*
Problem link: https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1
*/

/*Maximum Product Subarray

Given an array arr[] that contains positive and negative integers (may contain 0 as well). Find the maximum product that we can get in a subarray of arr.

Note: It is guaranteed that the output fits in a 32-bit integer.

Examples

Input: arr[] = [-2, 6, -3, -10, 0, 2]
Output: 180
Explanation: The subarray with maximum product is {6, -3, -10} with product = 6 * (-3) * (-10) = 180.
Input: arr[] = [-1, -3, -10, 0, 6]
Output: 30
Explanation: The subarray with maximum product is {-3, -10} with product = (-3) * (-10) = 30.
Input: arr[] = [2, 3, 4] 
Output: 24 
Explanation: For an array with all positive elements, the result is product of all elements. 
Constraints:
1 ≤ arr.size() ≤ 106
-10  ≤  arr[i]  ≤  10

*/

class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        int n = arr.size();
        int ans = INT_MIN;
        int productLeft = 1;
        int productRight = 1;
        
        for(int i=0; i<n; i++){
            productLeft *= arr[i];
            productRight *= arr[n-1-i];
            ans = max({ans, productLeft, productRight});
            if(productLeft == 0){
                productLeft = 1; 
            }
            if(productRight == 0){
                productRight = 1;
            }
        }
        return ans;
    }
};
