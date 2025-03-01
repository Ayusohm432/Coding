/*
Problem Link: https://www.geeksforgeeks.org/problems/decode-the-string2444/1
*/

/*Decode the string


Given an encoded string s, the task is to decode it. The encoding rule is :

k[encodedString], where the encodedString inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
Note: The test cases are generated so that the length of the output string will never exceed 105 .

Examples:

Input: s = "1[b]"
Output: "b"
Explanation: "b" is present only one time.
Input: s = "3[b2[ca]]"
Output: "bcacabcacabcaca"
Explanation:
1. Inner substring “2[ca]” breakdown into “caca”.
2. Now, new string becomes “3[bcaca]”
3. Similarly “3[bcaca]” becomes “bcacabcacabcaca ” which is final result.
Constraints:
1 ≤ |s| ≤ 105 

*/
class Solution {
    public:
      string decodedString(string &s) {
          // code here
          int n = s.length();
          stack<char> st;
          stack<string> temp;
          string result = "";
          int count = 0;
          
          for(int i=0; i<n; i++){
              if(isdigit(s[i])){
                  count = count * 10 + (s[i] - '0');
              }else if(s[i] == '['){
                  st.push(count);
                  count = 0;
                  temp.push(result);
                  result = "";
              }else if(s[i] == ']'){
                  int k = st.top();
                  st.pop();
                  string curr = temp.top();
                  temp.pop();
                  for(int j=1; j<=k; j++){
                      curr += result;
                  }
                  result = curr;
              }else{
                  result += s[i];
              }
          }
          return result;
      }
  };