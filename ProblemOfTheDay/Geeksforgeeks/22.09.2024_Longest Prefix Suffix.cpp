/*
Problem Link : https://www.geeksforgeeks.org/problems/longest-prefix-suffix2527/1
*/

/*Longest Prefix Suffix

Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.

NOTE: Prefix and suffix can be overlapping but they should not be equal to the entire string.

Examples :

Input: str = "abab"
Output: 2
Explanation: "ab" is the longest proper prefix and suffix. 
Input: str = "aaaa"
Output: 3
Explanation: "aaa" is the longest proper prefix and suffix. 
Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

Constraints:
1 ≤ |str| ≤ 106
str contains lower case English alphabets




*/

class Solution {
  public:
    int lps(string str) {
        // Your code goes here
        int i=1 , j=0 , n= str.length();
        vector<int> arr(n,0);
        
        while(i < str.length()){
            if(str[i] == str[j]){
                arr[i++] = ++j; 
            }
            else{
                if(j > 0){
                    j = arr[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return arr[n-1];
    }
};