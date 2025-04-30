/*
Problem Link: https://leetcode.com/problems/find-numbers-with-even-number-of-digits?envType=daily-question&envId=2025-04-30
*/

/*1295. Find Numbers with Even Number of Digits
Given an array nums of integers, return how many of them contain an even number of digits.

 

Example 1:

Input: nums = [12,345,2,6,7896]
Output: 2
Explanation: 
12 contains 2 digits (even number of digits). 
345 contains 3 digits (odd number of digits). 
2 contains 1 digit (odd number of digits). 
6 contains 1 digit (odd number of digits). 
7896 contains 4 digits (even number of digits). 
Therefore only 12 and 7896 contain an even number of digits.
Example 2:

Input: nums = [555,901,482,1771]
Output: 1 
Explanation: 
Only 1771 contains an even number of digits.
 

Constraints:

1 <= nums.length <= 500
1 <= nums[i] <= 105

*/

class Solution {
    bool isEvenDigits(int num){
        int count = 0;
        while(num > 0){
            num /= 10;
            count++;
        }
        return (count % 2) ? false : true;
    }
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();

        int result = 0;

        for(int i=0; i<n; i++){
            if(isEvenDigits(nums[i])){
                cout<<nums[i];
                result++;
            }
        }

        return result;
    }
};