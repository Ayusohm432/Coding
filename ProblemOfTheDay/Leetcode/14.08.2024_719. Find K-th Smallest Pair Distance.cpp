/*
problem Link :- https://leetcode.com/problems/find-k-th-smallest-pair-distance/?envType=daily-question&envId=2024-08-14
*/

/*719. Find K-th Smallest Pair Distance

The distance of a pair of integers a and b is defined as the absolute difference between a and b.

Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

 

Example 1:

Input: nums = [1,3,1], k = 1
Output: 0
Explanation: Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
Example 2:

Input: nums = [1,1,1], k = 2
Output: 0
Example 3:

Input: nums = [1,6,1], k = 3
Output: 5
 

Constraints:

n == nums.length
2 <= n <= 104
0 <= nums[i] <= 106
1 <= k <= n * (n - 1) / 2

*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//Approach-1
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        vector<int> count;

        for(int i=0 ; i<nums.size() ; i++){
            for(int j=i+1 ; j<nums.size() ; j++){
                count.push_back(abs(nums[i] - nums[j]));
            }
        }

        nth_element(begin(count) , begin(count)+(k-1) , end(count));

        return count[k-1];
    }
};

//main Function
int main(){
    Solution solution;
    vector<int> nums = {1,6,1};
    int k = 3;
    cout<<solution.smallestDistancePair(nums,k)<<endl;
    return 0;
}
