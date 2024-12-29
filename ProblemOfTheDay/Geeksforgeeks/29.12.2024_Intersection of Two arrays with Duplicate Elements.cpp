/*
Problem Link: https://www.geeksforgeeks.org/problems/intersection-of-two-arrays-with-duplicate-elements/1
*/

/*Intersection of Two arrays with Duplicate Elements

Given two integer arrays a[] and b[], you have to find the intersection of the two arrays. Intersection of two arrays is said to be elements that are common in both arrays. The intersection should not have duplicate elements and the result should contain items in any order.

Note: The driver code will sort the resulting array in increasing order before printing.

Examples:

Input: a[] = [1, 2, 1, 3, 1], b[] = [3, 1, 3, 4, 1]
Output: [1, 3]
Explanation: 1 and 3 are the only common elements and we need to print only one occurrence of common elements.
Input: a[] = [1, 1, 1], b[] = [1, 1, 1, 1, 1]
Output: [1]
Explanation: 1 is the only common element present in both the arrays.
Input: a[] = [1, 2, 3], b[] = [4, 5, 6]
Output: []
Explanation: No common element in both the arrays.
Constraints:
1 ≤ a.size(), b.size() ≤ 105
1 ≤ a[i], b[i] ≤ 105

*/
class Solution {
  public:
        vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        // code here
        vector<int> ans;
        unordered_map<int,int> mm;
        for(int x:a)mm[x]=1;
        for(int x:b){
            if(mm[x]){
                ans.push_back(x);
                mm[x]=0;
            }
        }
        return ans;
    }
};