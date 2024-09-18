/*
Problem link : https://unstop.com/code/practice/250593
*/

/*Minimum Fuel

Problem Statement
Alice has been given an array of tasks with the following values: tasks[i] = [actual[i], minimum[i]]:

The real quantity of fuel Alice use to complete the ith task is actual[i].

The least amount of fuel required to begin the ith task is minimum[i].

For example, if the task is [10, 12] and Alice’s current fuel level is 11, Alice will be unable to begin. If Alice’s current energy fuel is 13, Alice can do this task, and Alice’s fuel level will drop to 3 when Alice is done. Alice is free to complete the assignments in any sequence she likes.

Return the smallest quantity of fuel Alice needs to complete all of the assignments.

Input Format
The first line contains an integer N denoting the number of pairs.

The next N lines denote the pairs a,b.

Output Format
The output contains a single integer denoting the minimum fuel required.

Constraints
1 <= N <= 10^6

-10^3 <= a, b <= 10^3

Sample Testcase 0
Testcase Input
5
1 3
2 4
10 11
10 12
8 9
Testcase Output
32
Explanation
Starting with 32 fuel, we finish the tasks in the following order:


- 1st task. Now fuel= 32 - 1 = 31.


- 2nd task. Now fuel= 31 - 2 = 29.


- 3rd task. Now fuel= 29 - 10 = 19.


- 4th task. Now fuel= 19 - 10 = 9.


- 5th task. Now fuel= 9 - 8 = 1.

Sample Testcase 1
Testcase Input
3
1 2
2 4
4 8
Testcase Output
8
Explanation
Starting with 8 fuel, we finish the tasks in the following order:


- 3rd task. Now fuel = 8 - 4 = 4.


- 2nd task. Now fuel = 4 - 2 = 2. - 1st task. Now fuel = 2 - 1 = 1.


Notice that even though we have leftover fuel, starting with 7 fuel does not work because we cannot do the 3rd task.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimumFuel(vector<pair<int, int>>& tasks) {
    sort(tasks.begin(), tasks.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return (b.second - b.first) < (a.second - a.first);
    });

    int fuelNeeded = 0;  
    int currentFuel = 0; 


    for (auto& task : tasks) {
        int actual = task.first;
        int minimum = task.second;


        if (currentFuel < minimum) {
            fuelNeeded += (minimum - currentFuel);
            currentFuel = minimum; 
        }


        currentFuel -= actual;
    }

    return fuelNeeded;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> tasks(n);
    
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].first >> tasks[i].second;
    }
    
    cout << minimumFuel(tasks) << endl;
    return 0;
}
