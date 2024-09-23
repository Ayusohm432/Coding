/*
Problem Link : https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
*/

/*Missing And Repeating

Given an unsorted array arr of of positive integers. One number 'A' from set {1, 2,....,n} is missing and one number 'B' occurs twice in array. Find numbers A and B.

Examples

Input: arr[] = [2, 2]
Output: 2 1
Explanation: Repeating number is 2 and smallest positive missing number is 1.
Input: arr[] = [1, 3, 3] 
Output: 3 2
Explanation: Repeating number is 3 and smallest positive missing number is 2.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
2 ≤ n ≤ 105
1 ≤ arr[i] ≤ n

*/

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int missing , repeating;
        
        for(int i=0 ; i<arr.size() ; i++){
            int target = abs(arr[i]) - 1;
            
            if(arr[target] < 0){
                repeating = abs(arr[i]);
            }
            else{
                arr[target] = -arr[target];
            }
        }
        
        for(int i=0; i<arr.size() ; i++){
            if(arr[i] > 0){
                missing = i+1;
                break;
            }
        }
        
        return {repeating , missing};
    }
};