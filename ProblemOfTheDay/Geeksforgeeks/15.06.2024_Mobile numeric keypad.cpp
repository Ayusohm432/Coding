/*
Problem link :- https://www.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1
*/
/*
There is a standard numeric keypad on a mobile phone. You can only press the current button or buttons that are directly up, left, right, or down from it (for ex if you press 5, then pressing 2, 4, 6 & 8 are allowed). Diagonal movements and pressing the bottom row corner buttons (* and #) are prohibited.



Given a number n, find the number of possible unique sequences of length n that you can create by pressing buttons. You can start from any digit.

Examples

Input: n = 1
Output: 10
Explanation: Number of possible numbers are 10 (0, 1, 2, 3, 4, 5, 6, 7, 8, 9)  
Input: n = 2
Output: 36
Explanation: Possible numbers: 00, 08, 11, 12, 14, 22, 21, 23, 25 and so on. If we start with 0, valid numbers will be 00, 08 (count: 2). If we start with 1, valid numbers will be 11, 12, 14 (count: 3). If we start with 2, valid numbers  will be 22, 21, 23,25 (count: 4). If we start with 3, valid numbers will be 33, 32, 36 (count: 3). If we start with 4, valid numbers will be 44,41,45,47 (count: 4). If we start with 5, valid numbers will be 55,54,52,56,58 (count: 5) and so on.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ n ≤ 25

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    long long help(int i , int j , int n , vector<vector<vector<long long>>> &dp){
        if(i>3 or j>2 or i<0 or j<0){
            return 0;
        }
        if(i==3 and (j==0 or j==2)){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(dp[i][j][n] != -1){
            return dp[i][j][n];
        }
        n--;
        return dp[i][j][n+1] = help(i-1,j,n,dp)+help(i,j-1,n,dp)+help(i+1,j,n,dp)+help(i,j+1,n,dp)+help(i,j,n,dp);
    }
    long long getCount(int n) {
        // Your code goes here
        long long ans=0;
        
        vector<vector<vector<long long>>> dp(4,vector<vector<long long>>(3,vector<long long>(n+1,-1)));
        
        for(int i=0 ; i<4 ; i++){
            for(int j=0 ; j<3 ; j++){
                if(i==3 and (j==0 or j==2)){
                    continue;
                }
                ans += help(i,j,n,dp);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends
