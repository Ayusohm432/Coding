/*
Problem Link : https://www.geeksforgeeks.org/problems/triplet-family/1
*/

/*Triplet Family

Given an array arr of integers. Find whether three numbers are such that the sum of two elements equals the third element.

Example:

Input: arr[] = [1, 2, 3, 4, 5]
Output: true
Explanation: The pair (1, 2) sums to 3.
Input: arr[] = [5, 3, 4]
Output: false
Explanation: No triplets satisfy the condition.
Expected Time Complexity: O(n2)
Expected Auxilary Space: O(1)

Constraints:
1 <= arr.size() <= 103
0 <= arr[i] <= 105

*/
class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        // Your code
        sort(arr.begin() , arr.end() , greater<int>());
        int n = arr.size();
        
        for(int i=0 ; i<n ; i++){
            int target = arr[i];
            int start = i+1;
            int end = n-1;
            
            while(start < end){
                if(arr[start] + arr[end] == target){
                    return true;
                }
                else if(arr[start] + arr[end] > target){
                    start++;
                }
                else{
                    end--;
                }
            }
        }
        return false;
    }
};