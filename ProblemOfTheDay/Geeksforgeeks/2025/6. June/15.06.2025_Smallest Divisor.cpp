/*
Problem Link: https://www.geeksforgeeks.org/problems/smallest-divisor/1
*/

/*Smallest Divisor

Given an integer array arr[] and an integer k (where k ≥ arr.length), find the smallest positive integer divisor such that the sum of the ceiling values of each element in arr[] divided by this divisor is less than or equal to k.

Examples:

Input: arr[] = [1, 2, 5, 9], k = 6
Output: 5
Explanation: 5 is the smallest divisor having sum of quotients (1 + 1 + 1 + 2 = 5) less than or equal to 6.
Input: arr[] = [1, 1, 1, 1], k = 4
Output: 1
Explanation: 1 is the smallest divisor having sum of quotients (1 + 1 + 1 + 1 = 4) less than or equal to 4.
Constraints:
1  ≤  arr.size()  ≤ 105
1  ≤  arr[i]  ≤ 106
arr.size()  ≤ k  ≤ 106

*/

class Solution {
    bool help(vector<int>& arr, int mid, int k){
        int sum = 0;
        for(int& ele : arr){
            sum += ceil(double(ele)/double(mid));
            if(sum > k){
                return false;
            }
        }
        return true;
    }
  public:
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int low = 1;
        int high = *max_element(arr.begin(), arr.end());
        int result = high;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(help(arr, mid, k)){
                result = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        
        return result;
    }
};
