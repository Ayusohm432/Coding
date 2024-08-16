/*
Problem Link :- https://leetcode.com/problems/maximum-distance-in-arrays/?envType=daily-question&envId=2024-08-16
*/

/*624. Maximum Distance in Arrays

You are given m arrays, where each array is sorted in ascending order.

You can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a - b|.

Return the maximum distance.

 

Example 1:

Input: arrays = [[1,2,3],[4,5],[1,2,3]]
Output: 4
Explanation: One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
Example 2:

Input: arrays = [[1],[1]]
Output: 0
 

Constraints:

m == arrays.length
2 <= m <= 105
1 <= arrays[i].length <= 500
-104 <= arrays[i][j] <= 104
arrays[i] is sorted in ascending order.
There will be at most 105 integers in all the arrays.

*/

#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int MIN = arrays[0].front();
        int MAX = arrays[0].back();

        int result = 0;

        for(int i=1 ; i<arrays.size() ; i++){
            int currMin = arrays[i].front();
            int currMax = arrays[i].back();

            result = max({result , abs(currMin - MAX) , abs(currMax - MIN)});

            MAX = max(MAX , currMax);
            MIN = min(MIN , currMin);      
         
        }
        return result;
    }
};

//Main Function
int main(){
    Solution solution;
    vector<vector<int>> arrays = {{1,2,3},{4,5},{1,2},{6,7,8,9}};
    cout<<solution.maxDistance(arrays)<<endl;
    return 0;
}
