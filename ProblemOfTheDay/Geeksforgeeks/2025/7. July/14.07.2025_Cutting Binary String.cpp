/*
Problem Link: https://www.geeksforgeeks.org/problems/cutting-binary-string1342/1
*/

/*Cutting Binary String

You are given a binary string s consisting only of characters '0' and '1'. Your task is to split this string into the minimum number of non-empty substrings such that:

Each substring represents a power of 5 in decimal (e.g., 1, 5, 25, 125, ...).
No substring should have leading zeros.
Return the minimum number of such pieces the string can be divided into.
Note: If it is not possible to split the string in this way, return -1.

Examples:

Input: s = "101101101"
Output: 3
Explanation: The string can be split into three substrings: "101", "101", and "101", each of which is a power of 5 with no leading zeros.
Input: s = "1111101"
Output: 1
Explanation: The string can be split into one binary string "1111101" which is 125 in decimal and a power of 5 with no leading zeros.
Input: s = "00000"
Output: -1
Explanation: There is no substring that can be split into power of 5.
Constraints:
1 ≤ s.size() ≤ 30

*/

class Solution {
    unordered_set<string> powerOf5;
    
    void computePower5(){
        for(long long x=1; x<=1e9; x*=5){
            string binary = "";
            long long temp = x;
            while(temp > 0){
                binary = char('0' + (temp % 2)) + binary;
                temp /= 2;
            }
            powerOf5.insert(binary);
        }
    }
    
    int help(int i, string&s, vector<int>& dp){
        if(i == s.length()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        
        int result = 1e9;
        string res = "";
        
        for(int j=i; j<s.length(); j++){
            res += s[j];
            
            if(s[i] == '0'){
                break;
            }
            
            if(powerOf5.count(res)){
                int subString = help(j+1, s, dp);
                if(subString != 1e9){
                    result = min(result, 1+subString);
                }
            }
        }
        
        return dp[i] = result;
    }
  public:
    int cuts(string s) {
        // code here
        int n = s.length();
        computePower5();
        
        vector<int> dp(n, -1);
        int result = help(0, s, dp);
        
        return (result >= 1e9 ? -1 : result);
    }
};