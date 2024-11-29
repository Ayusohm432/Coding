/*
Problem Link: https://unstop.com/code/practice/250898
*/

/*Dreamy Galaxy

Problem Statement
There are N suns in a galaxy, each sun has M planets, each of the M planets have some number of moons, denoted by galaxy(i)(j), where galaxy(i)(j) denotes the number of moons of the jth planet having the ith sun.

Your task is to determine the maximum number of moons in any solar system. For each sun, calculate the total number of moons across all its planets, and output the highest total number of moons found in a single solar system.

Input Format
The first line of input contains two space-separated integers, N and M, representing the number of suns and the number of planets per sun, respectively.

The next N lines of input contains M space separated integers, representing the number of moons for each planet around the respective sun.

Output Format
Display a  single integer denoting the maximum total number of moons in a solar system (i.e., across all planets orbiting the same sun).

Constraints
1<=N<=5*10^2

1<=M<=5*10^2

1<=galaxy(i)(j) <=10^4

Sample Testcase 0
Testcase Input
2 3
1 2 3
4 5 6
Testcase Output
15
Explanation
The second sun has 3 planets and the total of their moons is 15.
Sample Testcase 1
Testcase Input
1 1
5
Testcase Output
5
Explanation
There is only 1 sun and 1 planet having 5 moons.

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int maxMoonInSolarSystem(int n, int m, vector<vector<int>>& galaxy){
    int maxMoons = 0;
    for(int i=0; i<n; i++){
        int currMoon = accumulate(galaxy[i].begin(), galaxy[i].end(), 0);
        maxMoons = max(maxMoons, currMoon);
    }

    return maxMoons;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; // suns
    int m; // planets per sun
    cin>>n>>m;

    vector<vector<int>> galaxy(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>galaxy[i][j]; //moons on each planet
        }
    }

    cout<<maxMoonInSolarSystem(n, m, galaxy);

    return 0;
}
