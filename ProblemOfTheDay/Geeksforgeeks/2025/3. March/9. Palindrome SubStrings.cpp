/*
Problem Link: https://www.geeksforgeeks.org/problems/count-palindrome-sub-strings-of-a-string0652/1
*/

/*Palindrome SubStrings

Given a string s, count all palindromic sub-strings present in the string. The length of the palindromic sub-string must be greater than or equal to 2. 

Examples

Input: s = "abaab"
Output: 3
Explanation: All palindromic substrings are : "aba" , "aa" , "baab".
Input: s = "aaa"
Output: 3
Explanation: All palindromic substrings are : "aa", "aa", "aaa".
Input: s = "abbaeae"
Output: 4
Explanation: All palindromic substrings are : "bb" , "abba" , "aea", "eae".
Constraints:
2 ≤ s.size() ≤ 103
string contains only lowercase english characters

*/

class Solution {
    public:
       int countPS(string &s) {
          int n=s.length();
          int res=0;
          
          //odd palindrome strings
          for(int i=0;i<n;i++){
              int l=i,r=i;
              
              while(l>=0 && r<n && s[l]==s[r]){
                  if(r-l+1>=2)
                  res++;
                  
                  l--;
                  r++;
              }
              
              //even length palindromes
               l=i,r=i+1;
              
              while(l>=0 && r<n && s[l]==s[r]){
                  if(r-l+1>=2)
                  res++;
                  
                  l--;
                  r++;
              }
          }
          
          return res;
          
      }
      
  };