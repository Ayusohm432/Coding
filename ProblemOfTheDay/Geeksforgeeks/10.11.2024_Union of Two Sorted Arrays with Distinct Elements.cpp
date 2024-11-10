/*
Problem Link : https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-with-distinct-elements/1
*/

/*Union of Two Sorted Arrays with Distinct Elements

Given two sorted arrays a[] and b[], where each array contains distinct elements , the task is to return the elements in the union of the two arrays in sorted order.

Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.
Examples:

Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
Output: 1 2 3 4 5 6 7
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5 6 7.
Input: a[] = [2, 3, 4, 5], b[] = [1, 2, 3, 4]
Output: 1 2 3 4 5
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5.
Input: a[] = [1], b[] = [2]
Output: 1 2
Explanation: Distinct elements including both the arrays are: 1 2.
Constraints:
1  <=  a.size(), b.size()  <=  105
-109  <=  a[i] , b[i]  <=  109

*/

class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        vector<int> result;
        
        int n = a.size();
        int m = b.size();
        
        int i = 0;
        int j = 0;
        
        while(i<n && j<m){
            if(a[i] == b[j]){
                result.push_back(a[i]);
                i++;
                j++;
            }
            else if(a[i] < b[j]){
                result.push_back(a[i]);
                i++;
            }
            else{
                result.push_back(b[j]);
                j++;
            }
        }
        
        while(i < n){
            result.push_back(a[i++]);
        }
        
        while(j < m){
            result.push_back(b[j++]);
        }
        
        
        return result;
    }
};