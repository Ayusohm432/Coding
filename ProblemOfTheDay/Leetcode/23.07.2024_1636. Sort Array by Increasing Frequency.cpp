/*
Problem Link ;- https://leetcode.com/problems/sort-array-by-increasing-frequency/?envType=daily-question&envId=2024-07-23
*/

/*1636. Sort Array by Increasing Frequency

Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.

 

Example 1:

Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
Example 2:

Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
Example 3:

Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]
 

Constraints:

1 <= nums.length <= 100
-100 <= nums[i] <= 100 


*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int> a , vector<int> b){
        if(a[0] < b[0]){
            return true;
        }
        if(a[0] == b[0]){
            return a[1] > b[1];
        }
        return false;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int ,int> mp;

        for(int& num : nums){
            mp[num]++;
        }

        vector<vector<int>> vec;

        for(auto itr : mp){
            vec.push_back({itr.second , itr.first});
        }

        sort(vec.begin() , vec.end() , cmp);

        vector<int> result;

        for(auto& num : vec){
            int x = num[0];
            while(x--){
                result.push_back(num[1]);
            }
        }

        return result;
    }
};

int main(){
    vector<int> nums = {2,3,1,3,2};
    Solution s;
    vector<int> result = s.frequencySort(nums);
    for(int i=0 ; i<result.size() ; i++){
        cout<<result[i]<<" ";
    }
    return 0;
}