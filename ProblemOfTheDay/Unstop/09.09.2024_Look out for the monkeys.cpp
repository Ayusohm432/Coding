/*
Problem Link : https://unstop.com/code/practice/250518
*/

/*Look out for the monkeys

Problem Statement
On a long, straight road, there are N poles of different heights. A monkey is sitting on the top of each pole, facing in the direction of the next pole. A monkey can see another monkey sitting in front of it if the heights of all the poles between them are strictly less than the heights of both of their poles.

More formally, the ith monkey can see the jth monkey if i < j and min(heights[i], heights[j]) > max(heights[i+1], heights[i+2], ..., heights[j-1]).

Find the number of monkeys that each monkey can see sitting on top of his pole, looking towards the next pole or in the right direction.

Input Format
The first line of the input contains a single integer N, representing the number of poles on the road.

The second line consists of N positive integers representing the height of each pole.

Output Format
Print n space-separated integers, where the ithinteger represents the number of monkeys that can be seen by the monkey sitting on the ith pole.

Constraints
1 <= n <= 105

1 <= height[i] <= 105

Sample Testcase 0
Testcase Input
6
10 6 8 5 11 9
Testcase Output
3 1 2 1 1 0

Explanation
The monkey at pole 1 can see monkeys at poles 2, 3, and 5. 
The monkey at pole 2 can see the monkey at pole 3. 
The monkey at pole 3 can only see the monkey at pole 4. 
The monkey at pole 4 can only see the monkey at pole 5. 
The monkey at pole 5 can only see the monkey at pole 6. 
The monkey at pole 6 cannot see any other monkey in front of it, as there is no pole in front of him.

Sample Testcase 1
Testcase Input
5
5 1 2 3 10
Testcase Output
4 1 1 1 0
Explanation
The monkey at pole 1 can see all other monkeys. 
The monkey at pole 2 can only see the monkey at pole 3. 
The monkey at pole 3 can only see the monkey at pole 4. 
The monkey at pole 4 can only see the monkey at pole 5. 
The monkey at pole 5 cannot see any other monkey in front of it, as there is no pole in front of him.


*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> countMonkeysVisible(vector<int>& heights) {
    int n = heights.size();
    vector<int> result(n, 0); 
    stack<int> s;

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && heights[s.top()] <= heights[i]) {
            result[s.top()]++;
            s.pop();
        }
        
        if (!s.empty()) {
            result[s.top()]++;
        }
        s.push(i);
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    vector<int> result = countMonkeysVisible(heights);

    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
