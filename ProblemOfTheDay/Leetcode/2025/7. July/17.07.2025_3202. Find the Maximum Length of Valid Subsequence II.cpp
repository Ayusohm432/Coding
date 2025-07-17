/*
Problem Link: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii?envType=daily-question&envId=2025-07-17
*/

/*3202. Find the Maximum Length of Valid Subsequence II

You are given an integer array nums and a positive integer k.
A subsequence sub of nums with length x is called valid if it satisfies:

(sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k.
Return the length of the longest valid subsequence of nums.
 

Example 1:

Input: nums = [1,2,3,4,5], k = 2

Output: 5

Explanation:

The longest valid subsequence is [1, 2, 3, 4, 5].

Example 2:

Input: nums = [1,4,2,3,1,4], k = 3

Output: 4

Explanation:

The longest valid subsequence is [1, 4, 1, 4].

 

Constraints:

2 <= nums.length <= 103
1 <= nums[i] <= 107
1 <= k <= 103

*/

class Solution {
    int n,K;
    vector<int> arr;
    int dp[1001][1001];
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> position(1001);
        arr = nums;
        K = k;
        for(auto& num : arr){
            num %= K;
        }
        n = arr.size();

        for(int i=0; i<n; i++){
            position[arr[i]].push_back(i);
        }

        int result = 0;
        for(int i=0; i<K; i++){
            for(int j=0; j<K; j++){
                vector<int>& pos1 = position[i];
                vector<int>& pos2 = position[j];

                int count = 0;
                int lastNum = -1;

                for(int a=0, b=0; ; ){
                    while(a<pos1.size() && pos1[a] <= lastNum){
                        a++; 
                    }
                    if(a == pos1.size()){
                        break;
                    }

                    lastNum = pos1[a];
                    count++;
                    a++;

                    while(b < pos2.size() && pos2[b] <= lastNum){
                        b++;
                    }
                    if(b == pos2.size()){
                        break;
                    }

                    lastNum = pos2[b];
                    count++;
                    b++;
                }
                result = max(result, count);
            }
        }
        return result;
    }
};