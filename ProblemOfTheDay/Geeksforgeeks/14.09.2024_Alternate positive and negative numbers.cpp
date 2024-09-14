/*
Problem Link : https://www.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1
*/

/*Alternate positive and negative numbers

Given an unsorted array arr containing both positive and negative numbers. Your task is to create an array of alternate positive and negative numbers without changing the relative order of positive and negative numbers.
Note: Array should start with a positive number and 0 (zero) should be considered a positive element.

Examples:

Input: arr[] = [9, 4, -2, -1, 5, 0, -5, -3, 2]
Output: 9 -2 4 -1 5 -5 0 -3 2
Explanation: Positive elements : [9,4,5,0,2]
Negative elements : [-2,-1,-5,-3]
As we need to maintain the relative order of postive elements and negative elements we will pick each element from the positive and negative and will store them. If any of the positive and negative numbersare completed. we will continue with the remaining signed elements.
The output is 9,-2,4,-1,5,-5,0,-3,2.
Input: arr[] = [-5, -2, 5, 2, 4, 7, 1, 8, 0, -8]
Output: 5 -5 2 -2 4 -8 7 1 8 0
Explanation : Positive elements : [5,2,4,7,1,8,0]
Negative elements : [-5,-2,-8]
The output is 5, -5, 2, -2, 4, -8, 7, 1, 8, 0.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ arr.size() ≤ 107
-106 ≤ arr[i] ≤ 107

*/
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        vector<int> positive;
        vector<int> negative;
        
        for(int i=0 ; i<arr.size() ; i++){
            if(arr[i] >= 0){
                positive.push_back(arr[i]);
            }
            else{
                negative.push_back(arr[i]);
            }
        }
        int i=0,j=0,k=0;
        while(k < arr.size()){
            if(i < positive.size()){
                arr[k++] = positive[i++];
            }
            if(j < negative.size()){
                arr[k++] = negative[j++];
            }
        }
        while(i < positive.size()){
            arr[k++] = positive[i++];
        }
        while(j < negative.size()){
            arr[k++] = negative[j++];
        }
    }
};