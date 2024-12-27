/*
Problem Link: https://leetcode.com/problems/best-sightseeing-pair?envType=daily-question&envId=2024-12-27
*/

/*1014. Best Sightseeing Pair

You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.

The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.

Return the maximum score of a pair of sightseeing spots.

 

Example 1:

Input: values = [8,1,5,2,6]
Output: 11
Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
Example 2:

Input: values = [1,2]
Output: 2
 

Constraints:

2 <= values.length <= 5 * 104
1 <= values[i] <= 1000

*/

//Approach-1
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        vector<int> vec(n, 0);
        vec[0] = values[0] + 0;

        for(int i = 1; i < n; i++) {
            vec[i] = max(values[i]+i, vec[i-1]);
        }

        int result = 0;

        for(int j = 1; j < n; j++) {
            int x = values[j]-j;
            int y = vec[j-1];
            result = max(result, x+y);
        }

        return result;
    }
};

//Approach-2
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        int result = 0;

        int max_till_now = values[0]+0; 

        for(int j = 1; j < n; j++) {
            int x = values[j]-j;
            int y = max_till_now;

            result = max(result, x+y);

            max_till_now = max(max_till_now, values[j]+j);
        }

        return result;
    }
};