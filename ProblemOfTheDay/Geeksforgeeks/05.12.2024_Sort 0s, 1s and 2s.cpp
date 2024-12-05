/*
Problem link: https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
*/

/*Sort 0s, 1s and 2s

Given an array arr[] containing only 0s, 1s, and 2s. Sort the array in ascending order.

Examples:

Input: arr[] = [0, 1, 2, 0, 1, 2]
Output: [0, 0, 1, 1, 2, 2]
Explanation: 0s 1s and 2s are segregated into ascending order.
Input: arr[] = [0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1]
Output: [0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2]
Explanation: 0s 1s and 2s are segregated into ascending order.
Constraints:
1 <= arr.size() <= 106
0 <= arr[i] <= 2

*/
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int low  = 0;
        int mid  = 0;
        int high = arr.size()-1;
        
        while(mid <= high){
            if(arr[mid] == 0){
                swap(arr[low++] , arr[mid++]);
            }
            else if(arr[mid] == 1){
                mid++;
            }
            else{
                swap(arr[mid] , arr[high--]);
            }
        }
        
        
    }
};