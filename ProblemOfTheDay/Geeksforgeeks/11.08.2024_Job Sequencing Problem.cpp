/*
Problem Link :- https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
*/

/*Job Sequencing Problem

Given a set of n jobs where each jobi has a deadline and profit associated with it.

Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with a job if and only if the job is completed by its deadline.

Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job. Deadline of the job is the time on or before which job needs to be completed to earn the profit.

Examples :

Input: Jobs = [[1,4,20],[2,1,1],[3,1,40],[4,1,30]]
Output: 2 60
Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).
Input: Jobs = [[1,2,100],[2,1,19],[3,2,27],[4,1,25],[5,1,15]]
Output: 2 127
Explanation: 2 jobs can be done with maximum profit of 127 (100+27).
Expected Time Complexity: O(nlogn)
Expected Auxilliary Space: O(n)

Constraints:
1 <= n <= 105
1 <= Deadline,id <= n
1 <= Profit <= 500

*/




//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 


// #include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 


// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution {
    public:
        static bool compareJobs(const Job& a, const Job& b) {
            return a.profit > b.profit;  // Sort in descending order of profit
        }
    
        vector<int> JobScheduling(Job arr[], int n) {
            sort(arr, arr + n, compareJobs);  // Sort jobs by profit
    
            vector<int> slots(n, -1);  // Initialize slots (all available)
    
            int totalProfit = 0;
            int scheduledJobs = 0;
    
            for (int i = 0; i < n; ++i) {
                for (int j = min(n, arr[i].dead) - 1; j >= 0; --j) {
                    if (slots[j] == -1) {
                        slots[j] = i;  // Allocate job to slot j
                        totalProfit += arr[i].profit;
                        scheduledJobs++;
                        break;
                    }
                }
            }
    
            return {scheduledJobs, totalProfit};
        }
};


//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends