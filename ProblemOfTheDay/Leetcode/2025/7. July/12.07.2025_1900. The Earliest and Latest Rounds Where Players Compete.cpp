/*
Problem Link: https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete?envType=daily-question&envId=2025-07-12
*/

/*1900. The Earliest and Latest Rounds Where Players Compete

There is a tournament where n players are participating. The players are standing in a single row and are numbered from 1 to n based on their initial standing position (player 1 is the first player in the row, player 2 is the second player in the row, etc.).

The tournament consists of multiple rounds (starting from round number 1). In each round, the ith player from the front of the row competes against the ith player from the end of the row, and the winner advances to the next round. When the number of players is odd for the current round, the player in the middle automatically advances to the next round.

For example, if the row consists of players 1, 2, 4, 6, 7
Player 1 competes against player 7.
Player 2 competes against player 6.
Player 4 automatically advances to the next round.
After each round is over, the winners are lined back up in the row based on the original ordering assigned to them initially (ascending order).

The players numbered firstPlayer and secondPlayer are the best in the tournament. They can win against any other player before they compete against each other. If any two other players compete against each other, either of them might win, and thus you may choose the outcome of this round.

Given the integers n, firstPlayer, and secondPlayer, return an integer array containing two values, the earliest possible round number and the latest possible round number in which these two players will compete against each other, respectively.

 

Example 1:

Input: n = 11, firstPlayer = 2, secondPlayer = 4
Output: [3,4]
Explanation:
One possible scenario which leads to the earliest round number:
First round: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
Second round: 2, 3, 4, 5, 6, 11
Third round: 2, 3, 4
One possible scenario which leads to the latest round number:
First round: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
Second round: 1, 2, 3, 4, 5, 6
Third round: 1, 2, 4
Fourth round: 2, 4
Example 2:

Input: n = 5, firstPlayer = 1, secondPlayer = 5
Output: [1,1]
Explanation: The players numbered 1 and 5 compete in the first round.
There is no way to make them compete in any other round.
 

Constraints:

2 <= n <= 28
1 <= firstPlayer < secondPlayer <= n

*/

class Solution {
    int mini = INT_MAX;
    int maxi = INT_MIN;

    void dfs(vector<int>& dp, int round, int firstPlayer, int secondPlayer){
        int n = dp.size();
        int len = n/2;

        for(int i=0; i<len; i++){
            if(dp[i] == firstPlayer && dp[n-i-1] == secondPlayer){
                mini = min(mini, round);
                maxi = max(maxi, round);
                return;
            }
        }

        bool first = false, second = false;
        for(int i=0; i<n; i++){
            if(dp[i] == firstPlayer){
                first = true;
            }
            if(dp[i] == secondPlayer){
                second = true;
            }
        }

        if(!first || !second){
            return;
        }

        vector<int> nextDp(len + (n % 2));
        int comb = (1 << len);
        for(int i=0; i<comb; i++){
            int low = 0;
            int high = nextDp.size() - 1;
            for(int j=0; j<len; j++){
                if((1 << j) & i){
                    nextDp[low] = dp[j];
                    low++;
                }else{
                    nextDp[high] = dp[n-j-1];
                    high--;
                }
            }

            if(n % 2){
                nextDp[low] = dp[n/2];
            }

            dfs(nextDp, round+1, firstPlayer, secondPlayer);
        }
    }
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        vector<int> dp(n);
        for(int i=1; i<=n; i++){
            dp[i-1] = i;
        }
        dfs(dp, 1, firstPlayer, secondPlayer);
        return {mini, maxi};
    }
};