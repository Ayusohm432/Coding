/*
Problem Link: https://unstop.com/code/practice/250495
*/

/*Collecting the Apples

Problem Statement
In a garden with numerous apple trees labeled from 0 to N - 1, arranged in a row from left to right, the garden owner needs to collect all the apples to sell in the market. He has a basket with a capacity 'C' to collect the apples.

The process for collecting the apples is as follows:

1. Begin at the starting point, which is at x = -1.
2. Collect apples from each tree in sequential order, moving from left to right.
3. If the basket becomes full before reaching the next tree, return to the starting point (x = -1), deposit the apples collected so far, and then resume from this starting position to continue collecting apples.

The task is to determine the number of steps the garden owner will take to collect the final apple.

Input Format
The first line contains two integers separated by a space, N, represents the number of trees and, C, represents the capacity of the basket.

The second line contains N integers separated by spaces, each representing the number of apples on the corresponding tree.

 

Output Format
Print a single integer representing the number of steps required to collect all the apples.

 
Constraints
0 <= N <= 10^5

0 <= C <= 10^6

0 <= arr[i]<= 100

max(arr[i]) <= C

Sample Testcase 0
Testcase Input
2 5
2 3
Testcase Output
2
Explanation
He has enough capacity to take all the apple from both the tree in 2 steps.
Sample Testcase 1
Testcase Input
4 5
2 2 3 3
Testcase Output
14
Explanation
Start at the initial position with an empty basket:
- Walk to tree 0 (1 step) and collect it. Basket can has 3 apple space left.
- Walk to tree 1 (1 step) and collect it. Basket can has 1 apple space left.
- Since he cannot completely take tree 2 apples, walk back to initial position (2 steps).
- Walk to tree 2 (3 steps) and collect it. Basket  has 2 apple space left.
- Since he cannot completely take tree 3 apples. Walk back (3 steps).
- Walk to tree 3 (4 steps) and collect it.
Steps needed = 1 + 1 + 2 + 3 + 3 + 4 = 14.

*/

#include <iostream>
#include <vector>
using namespace std;

long long collectApples(int N, int C, vector<int>& apples) {
    long long totalSteps = 0;
    int currentBasket = 0;
    int currentTree = 0;
    
    while (currentTree < N) {
        if (currentBasket + apples[currentTree] > C) {
            totalSteps += currentTree;

            currentBasket = 0;
            continue;
        }
        
        totalSteps += (currentBasket == 0) ? currentTree + 1 : 1;

        currentBasket += apples[currentTree];
        currentTree++;
    }
    
    return totalSteps;
}

int main() {
    int N, C;
    cin >> N >> C;
    
    vector<int> apples(N);
    for(int i = 0; i < N; i++) {
        cin >> apples[i];
    }
    
    cout << collectApples(N, C, apples) << endl;
    
    return 0;
}
