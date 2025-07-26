/*
Problem Link: https://www.geeksforgeeks.org/problems/majority-vote/1
*/

/*Majority Element - More Than n/3

Given an array arr[] consisting of n integers, the task is to find all the array elements which occurs more than floor(n/3) times.

Note: The returned array of majority elements should be sorted.

Examples:

Input: arr[] = [2, 2, 3, 1, 3, 2, 1, 1]
Output: [1, 2]
Explanation: The frequency of 1 and 2 is 3, which is more than floor n/3 (8/3 = 2).
Input:  arr[] = [-5, 3, -5]
Output: [-5]
Explanation: The frequency of -5 is 2, which is more than floor n/3 (3/3 = 1).
Input:  arr[] = [3, 2, 2, 4, 1, 4]
Output: []
Explanation: There is no majority element.
Constraint:
1 ≤ arr.size() ≤ 106
-105 ≤ arr[i] ≤ 105

*/

class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        int n = arr.size();
        int firstMajority = NULL;
        int secondMajority = NULL;
        int firstCount = 0;
        int secondCount = 0;
        int freq = floor(n/3);
        
        for(int i=0; i<n; i++){
            if(arr[i] == firstMajority){
                firstCount++;
            }else if(arr[i] == secondMajority){
                secondCount++;
            }else if(firstCount == 0){
                firstMajority = arr[i];
                firstCount = 1;
            }else if(secondCount == 0){
                secondMajority = arr[i];
                secondCount = 1;
            }else{
                firstCount--;
                secondCount--;
            }
        }
        
        vector<int> result;
        firstCount = 0;
        secondCount = 0;
        
        for(int num : arr){
            if(num == firstMajority){
                firstCount++;
            }else if(num == secondMajority){
                secondCount++;
            }
        }
        
        if(firstCount > freq){
            result.push_back(firstMajority);
        }
        if(secondCount > freq){
            result.push_back(secondMajority);
        }
        sort(result.begin(), result.end());
        return result;
    }
};