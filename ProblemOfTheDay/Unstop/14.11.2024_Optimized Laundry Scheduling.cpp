/*
Problem link : https://unstop.com/code/practice/296046
*/

/*Optimized Laundry Scheduling

Problem Statement
You have a set of K garments that must be washed and dried. You have N washing machines and M dryers, but each machine can only handle one garment at a time.

It takes W[i] minutes for a washing machine to wash a garment and D[i] minutes for a dryer to dry a garment. You want to find the minimum amount of time needed to wash and dry all of the garments, given these constraints.

Note: Transferring garments between machines takes no time, and the finished garments can be dried later. Also, a garment should be washed before drying it.

Your task is to calculate the minimum time needed to wash and dry all garments.

Input Format
The first line contains three space-separated integers, K, N, and M.

The next line contains N space-separated integers denoting the array W[i].

The next line contains M space-separated integers denoting the array D[i].

Output Format
Print a single integer denoting the minimum amount of time needed to wash and dry the garments.

Constraints
1 ≤ K, N, M ≤ 10^5

1 ≤ W[i] ≤ 10^9

1 ≤ D[i] ≤ 10^9

Sample Testcase 0
Testcase Input
1 1 1
100
50
Testcase Output
150
Explanation
In this scenario, there is only one washing machine and one dryer available. The time it takes for the washing machine to wash a garment is 100 units, and the time it takes for the dryer to dry a garment is 50 units. As a result, the total time required to wash and dry all garments is 100 + 50 = 150 units.
Sample Testcase 1
Testcase Input
2 3 3
2 4 1
7 3 3
Testcase Output
5
Explanation
We can wash the first and the second garment in washing machines 3 and 1, respectively. After washing them, the first and second garments can be dried in dryers 2 and 3 respectively.
For garment 1, time taken: 1 + 3 = 4 units
For garment 2, time taken: 2 + 3 = 5 units
Hence, the total time taken to wash and dry all the garments is 5 units (maximum of 4 and 5), which is the minimum possible time.

*/
#include <bits/stdc++.h>

using namespace std;

long long solve(int K, int N, int M, vector<int> W, vector<int> D){
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>> > washed, dried;
    for( int i = 0; i < N; i++ ){
        washed.push({W[i], i});
    }
    for( int i = 0; i < M; i++ ){
        dried.push({D[i], i});
    }
    vector<long long> endingTimeWashed(K), endingTimeDried(K);
    for( int i = 0; i < K; i++ ){
        pair<long long, int> p = washed.top();
        washed.pop();
        endingTimeWashed[i] = p.first;
        p.first += W[p.second];
        washed.push(p);
    }

    for( int i = 0; i < K; i++ ){
        pair<long long, int> p = dried.top();
        dried.pop();
        endingTimeDried[i] = p.first;
        p.first += D[p.second];
        dried.push(p);
    }
    sort(endingTimeWashed.begin(), endingTimeWashed.end());
    sort(endingTimeDried.rbegin(), endingTimeDried.rend());

    long long ans = 0;
    for(int i = 0; i < K; i++){
        ans = max(ans, endingTimeWashed[i] + endingTimeDried[i]);
    }
    return ans;
}

int main(){

    int K, N, M; cin >> K >> N >> M;
    vector<int> W(N), D(M);

    for( int i = 0; i < N; i++ ) cin >> W[i];
    for( int i = 0; i < M; i++ ) cin >> D[i];
    long long ans = solve(K, N, M, W, D);
    cout << ans << endl;
    return 0;
}