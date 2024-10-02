/*
Problem Link : https://unstop.com/code/practice/250752
*/

/*Scheduling

Problem Statement
As the festival season approaches, Simon’s mother assigns him N tasks to be completed in D days. Each task has a difficulty level represented by jobs[i] (where 0 <= i < N). Simon must complete at least one task each day, using all D days.

The difficulty Simon experiences each day is defined by the highest difficulty task he completes that day. To work on task i, all preceding tasks j (where 0 <= j < i) must be completed first.

Given an array taskdifficulty and an integer D, representing the difficulty of each task and the number of days respectively, determine the minimum total difficulty Simon faces to complete all tasks. If it’s not possible to schedule the tasks within the given days, return -1.

Input Format
The first line contains an integer B, the size of the array.

The second line contains N space-separated integers representing the array Arr[i].

The last line contains an integer D, denoting the number of days.

Output Format
Print a single integer mindifficulty representing the minimum difficulty simon faces to schedule all tasks.

 

Constraints
1 <= N <= 3*10^2

0<= Arr[i] <= 10^3

1<= D<=10

Sample Testcase 0
Testcase Input
6
6 5 4 3 2 1
2
Testcase Output
7
Explanation
First day you can finish the first 5 jobs, total difficulty = 6.
Second day you can finish the last job, total difficulty = 1.
The difficulty of the schedule = 6 + 1 = 7
Sample Testcase 1
Testcase Input
3
9 9 9
4
Testcase Output
-1
Explanation
If you finish a job per day you will still have a free day. you cannot find a schedule for the given jobs.

*/
#include <bits/stdc++.h>
using namespace std;

int dp[301][11];

int solve(int a[],int n,int i,int d){

    if(i==n){
        if(d>0)return INT_MAX/100;
        return 0;
    }

    if(d<=0)return INT_MAX/100;

    if(dp[i][d]!=-1)return dp[i][d];

    int ans=INT_MAX,mx=INT_MIN;

    for(int j=i;j<n;j++){

        mx=max(mx,a[j]);
        ans=min(ans,mx+solve(a,n,j+1,d-1));

    }

    return dp[i][d]=ans;

}

int main() {
    // /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    memset(dp,-1,sizeof(dp));

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];

    int d;
    cin>>d;

    if(d>n){
        cout<<-1<<endl;
        return 0;
    }

    int ans=solve(a,n,0,d);

    if(ans>=INT_MAX/100){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }

    return 0;
}