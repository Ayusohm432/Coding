/*
Problem Link: https://www.geeksforgeeks.org/problems/longest-span-with-same-sum-in-two-binary-arrays5142/1
*/

/*Longest Span in two Binary Arrays

Given two binary arrays, a1[] and a2[]. Find the length of longest common span (i, j) where j>= i such that a1[i] + a1[i+1] + .... + a1[j] =  a2[i] + a2[i+1] + ... + a2[j].

Examples:

Input: a1[] = [0, 1, 0, 0, 0, 0], a2[] = [1, 0, 1, 0, 0, 1]
Output: 4
Explanation: The longest span with same sum is from index 1 to 4 following zero based indexing.
Input: a1[] = [0, 1, 0, 1, 1, 1, 1], a2[] = [1, 1, 1, 1, 1, 0, 1]
Output: 6
Explanation: The longest span with same sum is from index 1 to 6 following zero based indexing.
Constraints:
1 <= a1.size() = a2.size() <= 106
0 <= a1[i], a2[i] <= 1

*/

class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        // Code here.
        int n = a1.size();
        vector<int> difference(2*n+1, -1);
        int maxLengthSpan = 0;
        
        int sum1 = 0;
        int sum2 = 0;
        
        for(int i=0; i<n; i++){
            sum1 += a1[i];
            sum2 += a2[i];
            
            int currDifference = sum1 - sum2;
            int currIndex = n + currDifference;
            
            if(currDifference == 0){
                maxLengthSpan = i + 1;
            }else if(difference[currIndex] == -1){
                difference[currIndex] = i;
            }else{
                int currLength = i - difference[currIndex];
                if(currLength > maxLengthSpan){
                    maxLengthSpan = currLength;
                }
            }
        }
        return maxLengthSpan;
    }
};