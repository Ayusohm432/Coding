/*
Problem Link: https://www.geeksforgeeks.org/problems/pythagorean-triplet3018/1
*/

/*Pythagorean Triplet

Given an array arr[], return true if there is a triplet (a, b, c) from the array (where a, b, and c are on different indexes) that satisfies a2 + b2 = c2, otherwise return false.

Examples:

Input: arr[] = [3, 2, 4, 6, 5]
Output: true
Explanation: a=3, b=4, and c=5 forms a pythagorean triplet.
Input: arr[] = [3, 8, 5]
Output: false
Explanation: No such triplet possible.
Input: arr[] = [1, 1, 1]
Output: false
Constraints:
1 <= arr.size() <= 105
1 <= arr[i] <= 103

*/

class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        unordered_set<int> st;
        int n = arr.size();
        
        for(int& num : arr){
            st.insert(num * num);
        }
        
        for(int i=0; i<n; i++){
            int a = arr[i];
            for(int j=i+1; j<n; j++){
                int b = arr[j];
                if(st.count(a*a + b*b)){
                    return true;
                }
            }
        }
        
        return false;
    }
};