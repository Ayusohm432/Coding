/*
Problem Link :- https://leetcode.com/problems/count-number-of-teams/?envType=daily-question&envId=2024-07-29
*/

/*1395. Count Number of Teams

There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:

Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

 

Example 1:

Input: rating = [2,5,3,4,1]
Output: 3
Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 
Example 2:

Input: rating = [2,1,3]
Output: 0
Explanation: We can't form any team given the conditions.
Example 3:

Input: rating = [1,2,3,4]
Output: 4
 

Constraints:

n == rating.length
3 <= n <= 1000
1 <= rating[i] <= 105
All the integers in rating are unique.


*/

#include<iostream>
#include<vector>

using namespace std;

//Approach-1
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();

        int teams = 0;

        for(int j=1 ; j<n-1 ; j++){

            int countSmallerLeft  = 0;
            int countLargerLeft   = 0;
            int countSmallerRight = 0;
            int countLargerRight  = 0;

            for(int i=0 ; i<j ; i++){
                if(rating[i] < rating[j]){
                    countSmallerLeft++;
                }
                else if(rating[i] > rating[j]){
                    countLargerLeft++;
                }
            }

            for(int k=j+1 ; k<n ; k++){
                if(rating[j] < rating[k]){
                    countLargerRight++;
                }
                else if(rating[j] > rating[k]){
                    countSmallerRight++;
                }
            }
            teams += (countSmallerLeft * countLargerRight);
            teams += (countLargerLeft  * countSmallerRight);
        }
        return teams;
    }
};

//Approach-2
class Solution {
public:
    int n;
    int f1(vector<int>& rating,int i,int prev,int sz,vector<vector<int>>& dp){
        if(sz==3) return 1;
        if(i>=n) return 0;
        if(dp[i][sz]!=-1) return dp[i][sz];
        int ans=0;
        for(int j=i;j<n;j++){
            if(rating[j]>prev){
                ans+=f1(rating,j+1,rating[j],sz+1,dp);
            }
        }

        return dp[i][sz]=ans;
    }
    int f2(vector<int>& rating,int i,int prev,int sz,vector<vector<int>>& dp){
        if(sz==3) return 1;
        if(i>=n) return 0;
        if(dp[i][sz]!=-1) return dp[i][sz];
        int ans=0;
        for(int j=i;j<n;j++){
            if(rating[j]<prev){
                ans+=f2(rating,j+1,rating[j],sz+1,dp);
            }
        }

        return dp[i][sz]=ans;
    }
    int numTeams(vector<int>& rating) {
        n=rating.size();
        int ans=0;

        vector<vector<int>> dp(n+1,vector<int>(4,-1));
        vector<vector<int>> dp1(n+1,vector<int>(4,-1));
        for(int i=0;i<n;i++){
            int a=f2(rating,i+1,rating[i],1,dp);
            cout<<i<<"->"<<a<<" ";
            ans+=a ;//for checking decreasing
            int b=f1(rating,i+1,rating[i],1,dp1);
            cout<<i<<"->"<<b<<" ";
            ans+=b;//for checking increasing
        }

        return ans;
    }
};

//Main Funtion
int main(){
    Solution s;
    vector<int> v={2,5,3,4,1};
    int result = s.numTeams(v);
    cout << "Number of teams: " << result << endl;
    return 0;
}