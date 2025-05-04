/*
Problem Link: https://www.geeksforgeeks.org/problems/smallest-distant-window3132/1
*/

/*Smallest distinct window

Given a string str, your task is to find the length of the smallest window that contains all the characters of the given string at least once.

Example:

Input: str = "aabcbcdbca"
Output: 4
Explanation: Sub-String "dbca" has the smallest length that contains all the characters of str.
Input: str = "aaab"
Output: 2
Explanation: Sub-String "ab" has the smallest length that contains all the characters of str.
Input: str = "geeksforgeeks"
Output: 8
Explanation: There are multiple substring with smallest length that contains all characters of str, "geeksfor" and "forgeeks". 
Constraints:
1 ≤ str.size() ≤ 105
str contains only lower-case english alphabets.

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& str) {
        // code here
        int n = str.length();
        
        set<char> uniqueChar(str.begin(), str.end());
        int uniqueLength = uniqueChar.size();
        
        
        int result = INT_MAX;
        unordered_map<char, int> mp;
        
        int i=0, j=0;
        while(j < n){
            mp[str[j]]++;
            if(mp.size() >= uniqueLength){
                while(mp[str[i]] > 1){
                    mp[str[i]]--;
                    i++;
                }
                result = min(result, j-i+1);
            }
            j++;
        }
        
        return result;
        
    }
};


//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends