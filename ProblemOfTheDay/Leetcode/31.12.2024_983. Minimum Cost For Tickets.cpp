/*
Problem Link: https://leetcode.com/problems/minimum-cost-for-tickets?envType=daily-question&envId=2024-12-31
*/

/*983. Minimum Cost For Tickets

You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.

 

Example 1:

Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total, you spent $11 and covered all the days of your travel.
Example 2:

Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
In total, you spent $17 and covered all the days of your travel.
 

Constraints:

1 <= days.length <= 365
1 <= days[i] <= 365
days is in strictly increasing order.
costs.length == 3
1 <= costs[i] <= 1000

*/

//Approach - 1
class Solution {
public:
    int t[366];
    int memoized(vector<int>& days, vector<int>& costs, int& n, int idx) {
        if(idx >= n)
            return 0; 
                
        if(t[idx] != -1)
            return t[idx];
        
        int cost_1 = costs[0] + memoized(days, costs, n, idx+1);
        
        
        int i          = idx;
        while(i < n && days[i] < days[idx]+7) {
            i++;
        }
        int cost_7 = costs[1] + memoized(days, costs, n, i);
        
        
        int j      = idx;
        while(j < n && days[j] < days[idx]+30) {
            j++;
        }
        int cost_30 = costs[2] + memoized(days, costs, n, j);
        
        
        return t[idx] = min({cost_1, cost_7, cost_30});
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(t, -1, sizeof(t));
        int n = days.size();
        return memoized(days, costs, n, 0);
    }
};

//Approach - 2

class Solution {
public:    
    int bottomUp(vector<int>& days, vector<int>& costs) {
        unordered_set<int> st(begin(days), end(days));
        int last_day = days.back();
        
        vector<int> t(last_day+1, 0);
        
        t[0] = 0; 
        
        for(int i = 1; i<=last_day; i++) {
            if(st.find(i) == st.end()) {
                t[i] = t[i-1];
                continue;
            }
            
            t[i] = INT_MAX;
            
            
            int day_1_pass = t[max(0, i-1)] + costs[0];

            
            int day_7_pass = t[max(0,i-7)] + costs[1];

            int day_30_pass = t[max(0, i-30)] + costs[2];
            
            t[i] = min({day_1_pass, day_7_pass, day_30_pass});
        }
        
        return t[last_day]; 
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return bottomUp(days, costs);     
    }
};