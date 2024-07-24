/*
Problem Link :- https://leetcode.com/problems/sort-the-jumbled-numbers/?envType=daily-question&envId=2024-07-24
*/

/*2191. Sort the Jumbled Numbers

You are given a 0-indexed integer array mapping which represents the mapping rule of a shuffled decimal system. mapping[i] = j means digit i should be mapped to digit j in this system.

The mapped value of an integer is the new integer obtained by replacing each occurrence of digit i in the integer with mapping[i] for all 0 <= i <= 9.

You are also given another integer array nums. Return the array nums sorted in non-decreasing order based on the mapped values of its elements.

Notes:

Elements with the same mapped values should appear in the same relative order as in the input.
The elements of nums should only be sorted based on their mapped values and not be replaced by them.
 

Example 1:

Input: mapping = [8,9,4,0,2,1,3,5,7,6], nums = [991,338,38]
Output: [338,38,991]
Explanation: 
Map the number 991 as follows:
1. mapping[9] = 6, so all occurrences of the digit 9 will become 6.
2. mapping[1] = 9, so all occurrences of the digit 1 will become 9.
Therefore, the mapped value of 991 is 669.
338 maps to 007, or 7 after removing the leading zeros.
38 maps to 07, which is also 7 after removing leading zeros.
Since 338 and 38 share the same mapped value, they should remain in the same relative order, so 338 comes before 38.
Thus, the sorted array is [338,38,991].
Example 2:

Input: mapping = [0,1,2,3,4,5,6,7,8,9], nums = [789,456,123]
Output: [123,456,789]
Explanation: 789 maps to 789, 456 maps to 456, and 123 maps to 123. Thus, the sorted array is [123,456,789].
 

Constraints:

mapping.length == 10
0 <= mapping[i] <= 9
All the values of mapping[i] are unique.
1 <= nums.length <= 3 * 104
0 <= nums[i] < 109



*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
using namespace std;
//Approach-1
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> result;
        vector<pair<int , int>> vec;


        for(int j=0 ; j<nums.size() ; j++){
            string curr = to_string(nums[j]);
            int replaced = 0;
            for(int i=0 ; i<curr.length() ; i++){
                replaced = replaced * 10 + mapping[curr[i] - '0'];
            }
            vec.push_back({replaced , j});
        }
        
        sort(vec.begin() , vec.end());

        for(auto itr : vec){
            result.push_back(nums[itr.second]);
        }

        return result;
    }
};


//Approach-2
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> result;
        vector<pair<int , int>> vec;


        for(int j=0 ; j<nums.size() ; j++){
            int temp  = nums[j];
            int place = 1;
            int replaced = 0;

            if(temp == 0){
                vec.push_back({mapping[0] , j});
                continue;
            }

            while(temp != 0){
                replaced = place * mapping[temp%10] + replaced;
                place *= 10;
                temp /= 10; 
            }
            vec.push_back({replaced , j});
        }
        
        sort(vec.begin() , vec.end());

        for(auto itr : vec){
            result.push_back(nums[itr.second]);
        }

        return result;
    }
};

int main(){
    vector<int> nums = {23,67,7,17,4,24,5};
    vector<int> mapping = {6,8,2,7,5,3,9};
    Solution obj;
    vector<int> result = obj.sortJumbled(mapping , nums);
    for(auto itr : result){
        cout<<itr<<" ";
    }

}