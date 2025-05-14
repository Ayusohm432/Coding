/*
Problem Link: https://www.geeksforgeeks.org/problems/decode-the-pattern1138/1
*/

/*Look and Say Pattern

Given an integer n. Return the nth row of the following look-and-say pattern.
1
11
21
1211
111221
Look-and-Say Pattern:

To generate a member of the sequence from the previous member, read off the digits of the previous member, counting the number of digits in groups of the same digit. For example:

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
1211 is read off as "one 1, one 2, then two 1s" or 111221.
111221 is read off as "three 1s, two 2s, then one 1" or 312211.
Examples:

Input: n = 5
Output: 111221
Explanation: The 5th row of the given pattern will be 111221.
Input: n = 3
Output: 21
Explanation: The 3rd row of the given pattern will be 21.

Constraints:
1 ≤ n ≤ 30

*/

//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string countAndSay(int n) {
        // code here
        if(n == 1){
            return "1";
        }
        
        string str = "1";
        
        for(int i=2; i<=n; i++){
            string temp = "";
            int count = 1;
            for(int j=1; j<str.length(); j++){
                if(str[j] == str[j-1]){
                    count++;
                }else{
                    temp += to_string(count) + str[j-1];
                    count = 1;
                }
            }
            
            temp += to_string(count) + str.back();
            str = temp;
        }
        
        return str;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends