/*
Problem Link: https://unstop.com/code/practice/305422
*/

/*The 3 jumps

Problem Statement
You need to find the minimum cost to reach the last element of a given vector V of positive integers of size N.

The cost of moving from one element to another is the absolute difference between the elements.

You can only take a jump of max size equal to 3, i.e. if you are at index i, you can go to i+1,i+2 or i+3.

 

Note : the cost of reaching to the first element is 0.

Input Format
The first line is the size of the vector denoted by N

The second line contains N space-separated integers representing the elements of the vector.

Output Format
Display the minimum cost to reach the end with given constraints.

Constraints
1 ≤ V[i] ≤ 10^10

1 ≤ N ≤ 10^3

Sample Testcase 0
Testcase Input
5
30 10 60 10 60
Testcase Output
30
Explanation
If we start from 30, take a step to 60 which costs 30 and then take a step to 60 which costs 0. Therefore, the total cost, in this case, would be 30+0 = 30. 


This path has the minimum cost.

Sample Testcase 1
Testcase Input
6
40 20 10 30 90 80
Testcase Output
60
Explanation
We start from 40, then take a step to 30 which costs 10, and then take a step to 80 which costs 50. 


Therefore, the total cost is 10+50= 60.

*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int min_cost(const vector<int>& v) {
    int n = v.size();
    if (n == 0) return 0;

    vector<int> dp(n, INT_MAX);
    dp[0] = 0; 

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= 3; ++j) {
            if (i - j >= 0) {
                dp[i] = min(dp[i], dp[i - j] + abs(v[i] - v[i - j]));
            }
        }
    }

    return dp[n-1];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    int result = min_cost(v);
    std::cout << result << std::endl;
    return 0;
}