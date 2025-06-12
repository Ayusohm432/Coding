/*
Problem Link: https://www.geeksforgeeks.org/problems/k-closest-elements3619/1
*/

/*K closest elements

You are given a sorted array arr[] of unique integers, an integer k, and a target value x. Return exactly k elements from the array closest to x, excluding x if it exists.

An element a is closer to x than b if:


|a - x| < |b - x|, or
|a - x| == |b - x| and a > b (i.e., prefer the larger element if tied)


Return the k closest elements in order of closeness.

Examples:

Input: arr[] = [1, 3, 4, 10, 12], k = 2, x = 4
Output: 3 1
Explanation: 4 is excluded, Closest elements to 4 are: 3 (1), 1 (3). So, the 2 closest elements are: 3 1
Input: arr[] = [12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56], k = 4, x = 35
Output: 39 30 42 45
Explanation: First closest element to 35 is 39.
Second closest element to 35 is 30.
Third closest element to 35 is 42.
And fourth closest element to 35 is 45.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ k ≤ arr.size()
1 ≤ x ≤ 106
1 ≤ arr[i] ≤ 106

*/

// User function template for C++
class Solution {
  public:
    int findClosest(vector<int> arr, int low , int high , int x){
        while(low<=high){
            if(arr[high]<=x){
                return high;
            }
            if(arr[low] > x){
                return low;
            }
            int mid = low + (high-low)/2;
            if(arr[mid] <= x && arr[mid+1] >x){
                return mid;
            }
            if(arr[mid]>x){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return -1;
    }
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        // code here
        int n = arr.size();
        vector<int> ans(k);
        int m = 0;
        int l = findClosest(arr,0,n-1,x);
        int r = l+1;
        
        if(arr[l] == x){
            l--;
        }
        while(l>=0 && r<n && m<k){
            if(x-arr[l] < arr[r]-x){
                ans[m++] = arr[l];
                l--;
            }
            else{
                ans[m++] = arr[r];
                r++;
            }
        }
        while(m<k && l>=0){
            ans[m++] = arr[l];
            l--;
        }
        while(m<k && r<n){
            ans[m++] = arr[r];
            r++;
        }
        return ans;
    }
};
