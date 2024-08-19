/*
Problem Link :- https://leetcode.com/problems/2-keys-keyboard/?envType=daily-question&envId=2024-08-19
*/

/*650. 2 Keys Keyboard

There is only one character 'A' on the screen of a notepad. You can perform one of two operations on this notepad for each step:

Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.

 

Example 1:

Input: n = 3
Output: 3
Explanation: Initially, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.
Example 2:

Input: n = 1
Output: 0
 

Constraints:

1 <= n <= 1000

*/

//Driver Code
#include <iostream>
#include<vector>
using namespace std;


//Approach-1
class Solution {
public:
    int dp[1001][1001];
    int solve(int currA , int clipA , int n){
        if(currA == n){
            return 0;
        }

        if(currA > n){
            return 100000;
        }

        if(dp[currA][clipA] != -1){
            return dp[currA][clipA];
        }

        int copyAllPaste = 1 + 1 + solve(currA + currA , currA , n);

        int paste = 1 + solve(currA + clipA , clipA , n);

        return dp[currA][clipA] = min(copyAllPaste , paste);
    }
    int minSteps(int n) {
        if(n == 1){
            return 0;
        }

        memset(dp , -1 , sizeof(dp));

        return 1 + solve(1 , 1 , n);
    }
};

//Approach-2
class Solution {
public:
    int minSteps(int n) {
        if(n == 1){
            return 0;
        }
        if(n == 2){
            return 2;
        }
        vector<int> dp(n+1 , 0);

        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 2;

        for(int i=3 ; i<=n ; i++){
            int factor = i/2;
            while(factor >= 1){
                if(i % factor == 0){
                    int steps_to_reach_print_factor = dp[factor];
                    int copy = 1;
                    int paste = (i / factor) - 1;
                    dp[i] = steps_to_reach_print_factor + copy + paste;
                    break;
                }
                else{
                    factor--;
                }
            }
        }
        return dp[n];
    }
};

int main(){
    Solution s;
    cout << s.minSteps(3) << endl;  // Output: 3
    cout << s.minSteps(4) << endl;  // Output: 4
    cout << s.minSteps(5) << endl;  // Output: 5
    return 0;
}