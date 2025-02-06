/*
Problem Link: https://unstop.com/code/practice/307002
*/

/*Automated testing

Problem Statement
James has a new robot that moves along a straight line. Initially, the robot starts at a position X on this line. The robot is given a sequence of N commands, represented by the string S. Each character in S tells the robot to move either one step left (L) or one step right (R). Your task is to determine how many distinct points the robot visits after executing all the commands.

Input Format
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers, N and X.
The second line contains a single string S with length N.

Output Format
For each test case, print a single integer representing the number of distinct points visited by the robot.

Constraints
1≤T≤10^3

1≤N≤10^4

1≤∣X∣≤10^6

Sample Testcase 0
Testcase Input
1
5 4
LRLRL
Testcase Output
2
Explanation
The robot starts at position 4 and alternates between moving left and right, following the path: 4 -> 3 -> 4 -> 3 -> 4 -> 3. It only visits the distinct points 3 and 4 (2 distinct points).

Sample Testcase 1
Testcase Input
2
6 10
RRLLLL
2 0
LL
Testcase Output
5
3
Explanation
In the first test case, the robot starts at position 10 and follows the path: 10 -> 11 -> 12 -> 11 -> 10 -> 9 -> 8. It visits the distinct points: 10, 11, 12, 9, 8 (5 distinct points).
In the second test case, the robot starts at position 0 and follows the path: 0 -> -1 -> -2. It visits the distinct points: 0, -1, -2 (3 distinct points).

*/

#include <iostream>
#include <vector>
#include <string>
#include<bits/stdc++.h>
using namespace std;
int user_logic(int n, int x, const std::string& s) {
    // Write your logic here.
    // Parameters:
    //     n (int): Length of the string
    //     x (int): Initial position
    //     s (string): String representing the robot's movements
    // Returns:
    //     int: Number of distinct points visited by the robot
    unordered_set<int> st;
    st.insert(x);
    for(int i=0; i<s.length(); i++){
        if(s[i]=='R'){
            x++;
        }else{
            x--;
        }
        st.insert(x);
    }
    return st.size();
}

int main() {
    int T;
    std::cin >> T;
    
    std::vector<int> results;
    for (int t = 0; t < T; ++t) {
        int n, x;
        std::string s;
        std::cin >> n >> x >> s;
        int result = user_logic(n, x, s);
        results.push_back(result);
    }
    
    for (int result : results) {
        std::cout << result << std::endl;
    }
    
    return 0;
}