/*
Problem Link: https://www.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1
*/

/*Largest number in K swaps

Given a number k and string s of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of s at most k times.

Examples :

Input: s = "1234567", k = 4
Output: 7654321
Explanation: Three swaps can make the input 1234567 to 7654321, swapping 1 with 7, 2 with 6 and finally 3 with 5.
Input: s = "3435335", k = 3
Output: 5543333
Explanation: Three swaps can make the input 3435335 to 5543333, swapping 3 with 5, 4 with 5 and finally 3 with 4.
Input: s = "1034", k = 2
Output: 4301
Explanation: Two swaps can make the input 1034 to 4301, swapping 1 with 4 and finally 0 with 3. 
Constraints:
1 ≤ s.size() ≤ 15
1 ≤ k ≤ 7

*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    void find(int index, int k, string s, string& ans){
        if(k == 0 || index == s.length()){
            if(s > ans){
                ans = s;
            }
            return;
        }
        
        for(int i=index; i<s.length(); i++){
            if(s[i] > s[index]){
                swap(s[i], s[index]);
                find(index+1, k-1, s, ans);
                swap(s[i], s[index]);
            }
            find(i+1, k, s, ans);
        }
    }
    // Function to find the largest number after k swaps.
    string findMaximumNum(string& s, int k) {
        // code here.
        string ans = s;
        find(0, k, s, ans);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends