/*
Problem link: https://www.geeksforgeeks.org/problems/pair-with-given-sum-in-a-sorted-array4940/1
*/

/*Pair with given sum in a sorted array

You are given an integer target and an array arr[]. You have to find number of pairs in arr[] which sums up to target. It is given that the elements of the arr[] are in sorted order.
Note: pairs should have elements of distinct indexes. 

Examples :

Input: arr[] = [-1, 1, 5, 5, 7], target = 6
Output: 3
Explanation: There are 3 pairs which sum up to 6 : {1, 5}, {1, 5} and {-1, 7}.
Input: arr[] = [1, 1, 1, 1], target = 2
Output: 6
Explanation: There are 6 pairs which sum up to 2 : {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1} and {1, 1}.
Input: arr[] = [-1, 10, 10, 12, 15], target = 125
Output: 0
Explanation: There is no such pair which sums up to 4.
Constraints:
-105 <= target <=105
 2 <= arr.size() <= 105
-105 <= arr[i] <= 105

*/

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int count = 0;
        int i = 0;
        int j = arr.size() - 1;
        
        while(i < j){
            int sum = arr[i] + arr[j];
            if(sum == target){
                if(arr[i] == arr[j]){
                    int temp = j - i;
                    count += (temp * (temp + 1)) / 2;
                    break;
                }
                else{
                    int left = 1, right = 1;
                    while(i < j && arr[i] == arr[i+1]){
                        left++;
                        i++;
                    }
                    while(i < j && arr[j] == arr[j-1]){
                        right++;
                        j--;
                    }
                    count += (left * right);
                    i++;
                    j--;
                }
            }
            else if(sum < target){
                i++;
            }
            else{
                j--;
            }
        }
        return count;
    }
};