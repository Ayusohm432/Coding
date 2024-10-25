/*
Problem Link : https://www.geeksforgeeks.org/problems/alternative-sorting1311/1
*/

/*Alternative Sorting

Given an array arr of distinct integers. Rearrange the array in such a way that the first element is the largest and the second element is the smallest, the third element is the second largest and the fourth element is the second smallest, and so on.

Examples:

Input: arr[] = [7, 1, 2, 3, 4, 5, 6]
Output: [7, 1, 6, 2, 5, 3, 4]
Explanation: The first element is first maximum and second element is first minimum and so on.
Input: arr[] = [1, 6, 9, 4, 3, 7, 8, 2]
Output: [9, 1, 8, 2, 7, 3, 6, 4]
Explanation: The first element is first maximum and second element is first minimum and so on.
Expected Time Complexity: O(nlogn).
Expected Auxiliary Space: O(n).

Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105

*/

class Solution {

  public:
    vector<int> alternateSort(vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        sort(arr.begin() , arr.end());
        vector<int> result;
        result.reserve(n);
        
        int i=0;
        int j=n-1;
        
        while(i < j){
            result.push_back(arr[j]);
            result.push_back(arr[i]);
            j--;
            i++;
        }
        if(i == j){
            result.push_back(arr[i]);
        }
        return result;
    }
};