/*
Problem Link : https://www.geeksforgeeks.org/problems/remove-duplicates-in-small-prime-array/1
*/

/*Remove duplicates in array

Given an array arr consisting of positive integer numbers, remove all duplicate numbers.

Example:

Input: arr[] = [2, 2, 3, 3, 7, 5] 
Output: [2, 3, 7, 5]
Explanation: After removing the duplicates 2 and 3 we get 2 3 7 5.
Input: arr[] = [2, 2, 5, 5, 7, 7] 
Output: [2, 5, 7]
Input: arr[] = [8, 7] 
Output: [8, 7]
Constraints:
1<= arr.size() <=106
2<= arr[i] <=100

*/

//Approach-1
class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        // code here
        vector<int> count(101 , 0);
        vector<int> result;
        
        for(int i=0; i<arr.size(); i++){
            if(count[arr[i]] == 0){
                result.push_back(arr[i]);
                count[arr[i]] = 1;
            }
        }
        
        return result;
    }
};

//Approach-2
class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        // code here
        unordered_set<int> st;
        vector<int> result;
        
        for(int i=0; i<arr.size(); i++){
            if(st.find(arr[i]) == st.end()){
                result.push_back(arr[i]);
                st.insert(arr[i]);
            }
        }
        
        return result;
    }
};