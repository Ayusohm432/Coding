/*
Problem Link: https://www.geeksforgeeks.org/problems/sort-the-given-array-after-applying-the-given-equation0304/1
*/

/*Sort the given array after applying the given equation

Given an integer array arr[] sorted in ascending order, along with three integers: A, B, and C. The task is to transform each element x in the array using the quadratic function A*(x2) + B*x + C. After applying this transformation to every element, return the modified array in sorted order.

Examples:

Input: arr[] = [-4, -2, 0, 2, 4], A = 1, B = 3, C = 5
Output: [3, 5, 9, 15, 33]
Explanation: After applying f(x) = 1*(x2)+ 3*x + 5 to each x, we get [9, 3, 5, 15, 33]. After sorting this array, the array becomes [3, 5, 9, 15, 33].
Input: arr[] = [-3, -1, 2, 4], A = -1, B = 0, C = 0
Output: [-16, -9, -4, -1]
Explanation: After applying f(x) = -1*(x2) + 0*x + 0 to each x, we get [ -9, -1, -4, -16 ]. After sorting this array, the array becomes  [-16, -9, -4, -1].
Constraints:
1 ≤ arr.size() ≤ 106
-103 ≤ arr[i], A, B, C ≤ 103

*/

class Solution {
  public:
    int solveEquation(int x, int A, int B, int C){
        return (A*x*x + B*x + C);
    }
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        // code here
        int n = arr.size();
        vector<int> answer(n, 0);
        
        int i = 0;
        int j = n-1;
        int index = (A >= 0) ? n-1 : 0;
        
        while(i <= j){
            int iValue = solveEquation(arr[i], A, B, C);
            int jValue = solveEquation(arr[j], A, B, C);
            
            if(A >= 0){
                answer[index--] = (iValue > jValue) ? iValue : jValue;
                (iValue > jValue) ? i++ : j--;
            }else{
                answer[index++] = (iValue < jValue) ? iValue : jValue;
                (iValue < jValue) ? i++ : j--;
            }
        }
        
        return answer;
    }
};
