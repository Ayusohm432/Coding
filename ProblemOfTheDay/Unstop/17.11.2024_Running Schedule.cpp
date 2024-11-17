/*
Problem link : https://unstop.com/code/practice/301590
*/

/*Running Schedule


Problem Statement
Max has a training plan to lose weight by running over a period of N days. On each day i, he will run A[i] kilometers.

Max wants to celebrate "Snoop Day," which is the first day when the total distance he has run from the start of his training is at least half of the total distance he plans to run over all N days.

Your Task: Determine the index of the day when Max will celebrate Snoop Day.

Input Format
The first line contains an integer N, the number of days.

The second line contains N integers  A[i], where each integer represents the kilometers Max will run on that day.

Output Format
Print a single integer, the index of the day when Max will celebrate Snoop Day.

Constraints
1 ≤ N ≤ 2 * 10^5
1 ≤ Ai ≤ 10^4

Sample Testcase 0
Testcase Input
6
2 2 2 2 2 2
Testcase Output
3
Explanation
Max runs 2 km each day for 6 days. The total distance is 12 km.
By the end of Day 3, Max has run 6 km, which is exactly half of the total distance.
Therefore, Max will celebrate Snoop Day on Day 3.

Sample Testcase 1
Testcase Input
4
1 3 2 1
Testcase Output
2
Explanation
Max runs 1 km on Day 1, 3 km on Day 2, 2 km on Day 3, and 1 km on Day 4. The total distance is 7 km.
By the end of Day 2, Max has run 4 km, which is more than half of the total distance (3.5 km).
Therefore, Max will celebrate Snoop Day on Day 2.

*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int snoopDay(vector<int>& maxRuns, int n){
    int totalDistance = accumulate(maxRuns.begin(), maxRuns.end(), 0);
    int snoopDistance = (totalDistance + 1)/2;

    int currDistance = 0;
    int i;
    for(i=0; i<n; ++i){
        if(currDistance >= snoopDistance){
            return i;
        }
        currDistance += maxRuns[i];
    }

    return -1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;

    vector<int> maxRuns(n);

    for(int i=0; i<n; i++){
        cin>>maxRuns[i];
    }

    cout<<snoopDay(maxRuns, n);

    return 0;
}
