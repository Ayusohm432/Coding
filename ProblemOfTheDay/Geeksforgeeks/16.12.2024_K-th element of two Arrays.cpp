/*
Problem link: https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
*/

/*K-th element of two Arrays

Given two sorted arrays a[] and b[] and an element k, the task is to find the element that would be at the kth position of the combined sorted array.

Examples :

Input: a[] = [2, 3, 6, 7, 9], b[] = [1, 4, 8, 10], k = 5
Output: 6
Explanation: The final combined sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.
Input: a[] = [100, 112, 256, 349, 770], b[] = [72, 86, 113, 119, 265, 445, 892], k = 7
Output: 256
Explanation: Combined sorted array is [72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892]. The 7th element of this array is 256.
Constraints:

1 <= a.size(), b.size() <= 106
1 <= k <= a.size() + b.size()
0 <= a[i], b[i] < 108

*/

class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n = a.size();
        int m = b.size();

        if (n > m) {
            return kthElement(b, a, k);
        }
    
        int low = max(0, k - m), high = min(k, n);
    
        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = k - cut1;
    
            int left1 = cut1 == 0 ? INT_MIN : a[cut1 - 1];
            int left2 = cut2 == 0 ? INT_MIN : b[cut2 - 1];
            int right1 = cut1 == n ? INT_MAX : a[cut1];
            int right2 = cut2 == m ? INT_MAX : b[cut2];
    
            if (left1 <= right2 && left2 <= right1) {
                return max(left1, left2);
            } else if (left1 > right2) {
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
        }
    
        return -1; 
    }
};