/*
Problem Link : https://www.geeksforgeeks.org/problems/split-array-in-three-equal-sum-subarrays/1
*/

/*Split array in three equal sum subarrays

Given an array, arr[], determine if arr can be split into three consecutive parts such that the sum of each part is equal. If possible, return any index pair(i, j) in an array such that sum(arr[0..i]) = sum(arr[i+1..j]) = sum(arr[j+1..n-1]), otherwise return an array {-1,-1}.

Note: Since multiple answers are possible, return any of them. The driver code will print true if it is correct otherwise, it will print false.

Examples :

Input:  arr[] = [1, 3, 4, 0, 4]
Output: true
Explanation: [1, 2] is valid pair as sum of subarray arr[0..1] is equal to sum of subarray arr[2..3] and also to sum of subarray arr[4..4]. The sum is 4. 
Input: arr[] = [2, 3, 4]
Output: false
Explanation: No three subarrays exist which have equal sum.
Input: arr[] = [0, 1, 1]
Output: false
Constraints:
3 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 106

*/

// Approach-1
class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        int total = accumulate(arr.begin(), arr.end(), 0);
        
        if(total % 3 != 0 || n < 3){
            return {-1,-1};
        }
        
        int subArraySum = total / 3;
        
        int i = -1;
        int j = -1;
        int currTotal = 0;
        for(int k=0; k<n; k++){
            currTotal += arr[k];
            if(currTotal == subArraySum){
                if(i == -1){
                    i = k;
                }
                else{
                    j = k;
                    break;
                }
                currTotal = 0;
            }
        }
        
        if(i!=-1 && j!=-1 && j<n-1){
            return {i, j};
        }
        return {-1, -1};
    }
};

