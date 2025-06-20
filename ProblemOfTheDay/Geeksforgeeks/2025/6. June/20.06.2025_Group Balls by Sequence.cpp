/*
Problem Link: https://www.geeksforgeeks.org/problems/group-balls-by-sequence/1
*/

/*Group Balls by Sequence

You are given an array arr[] of positive integers, where each element arr[i] represents the number written on the i-th ball, and a positive integer k.
Your task is to determine whether it is possible to rearrange all the balls into groups such that:


Each group contains exactly k balls.
The numbers in each group are consecutive integers
Examples:

Input: arr[] = [10, 1, 2, 11], k = 2
Output: true
Explanation: The hand can be rearranged as [1, 2], [10, 11]. There are two groups of size 2. Each group has 2 consecutive cards.
Input: arr[] = [7, 8, 9, 10, 11], k = 2
Output: false
Explanation: The hand cannot be rearranged into groups of 2, since there are 5 cards, and 5 cards cannot be divided into groups of 2.
Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 105
1 ≤ k ≤ 103

*/

class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(n % k != 0){
            return false;
        }
        
        sort(arr.begin(), arr.end());
        
        int count = 1;
        
        for(int i=1; i<arr.size(); i++){
            if(arr[i] - arr[i-1] == 1){
                count++;
            }else if(arr[i] == arr[i-1]){
                continue;
            }else{
                if(count % k != 0){
                    return false;
                }
                count = 1;
            }
        }
        
        return count % k == 0;
    }
};