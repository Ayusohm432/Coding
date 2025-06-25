/*
Problem Link: https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays?envType=daily-question&envId=2025-06-25
*/

/*2040. Kth Smallest Product of Two Sorted Arrays

Given two sorted 0-indexed integer arrays nums1 and nums2 as well as an integer k, return the kth (1-based) smallest product of nums1[i] * nums2[j] where 0 <= i < nums1.length and 0 <= j < nums2.length.
 

Example 1:

Input: nums1 = [2,5], nums2 = [3,4], k = 2
Output: 8
Explanation: The 2 smallest products are:
- nums1[0] * nums2[0] = 2 * 3 = 6
- nums1[0] * nums2[1] = 2 * 4 = 8
The 2nd smallest product is 8.
Example 2:

Input: nums1 = [-4,-2,0,3], nums2 = [2,4], k = 6
Output: 0
Explanation: The 6 smallest products are:
- nums1[0] * nums2[1] = (-4) * 4 = -16
- nums1[0] * nums2[0] = (-4) * 2 = -8
- nums1[1] * nums2[1] = (-2) * 4 = -8
- nums1[1] * nums2[0] = (-2) * 2 = -4
- nums1[2] * nums2[0] = 0 * 2 = 0
- nums1[2] * nums2[1] = 0 * 4 = 0
The 6th smallest product is 0.
Example 3:

Input: nums1 = [-2,-1,0,1,2], nums2 = [-3,-1,2,4,5], k = 3
Output: -6
Explanation: The 3 smallest products are:
- nums1[0] * nums2[4] = (-2) * 5 = -10
- nums1[0] * nums2[3] = (-2) * 4 = -8
- nums1[4] * nums2[0] = 2 * (-3) = -6
The 3rd smallest product is -6.
 

Constraints:

1 <= nums1.length, nums2.length <= 5 * 104
-105 <= nums1[i], nums2[j] <= 105
1 <= k <= nums1.length * nums2.length
nums1 and nums2 are sorted.

*/

class Solution {
    long long findSmallestIndex(vector<int>& nums1, vector<int>& nums2, long long midProduct){
        long long productsCount = 0;
        int n = nums2.size();

        for(int i=0; i<nums1.size(); i++){
            if(nums1[i] >= 0){
                int low = 0;
                int high = n - 1;
                int idx = -1;

                while(low <= high){
                    int mid = low + (high - low) / 2;
                    long long product = 1LL*nums1[i]*nums2[mid];

                    if(product <= midProduct){
                        idx = mid;
                        low = mid + 1;
                    }else{
                        high = mid - 1;
                    }
                }
                productsCount += (idx+1);
            }else{
                int low = 0;
                int high = n - 1;
                int idx = n;

                while(low <= high){
                    int mid = low + (high - low) / 2;
                    long long product = 1LL * nums1[i] * nums2[mid];

                    if(product <= midProduct){
                        idx = mid;
                        high = mid - 1;
                    }else{
                        low = mid + 1;
                    }
                }
                productsCount += (n - idx);
            }
        }

        return productsCount;
    }
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long result = 0;

        long long low = -1e10;
        long long high = 1e10;

        while(low <= high){
            long long midProduct = low + (high - low) / 2;

            long long smallestCount = findSmallestIndex(nums1, nums2, midProduct);

            if(smallestCount >= k){
                result = midProduct;
                high = midProduct - 1;
            }else{
                low = midProduct + 1;
            }
        }
        return result;
    }
};