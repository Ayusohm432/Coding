/*
problem Link : https://unstop.com/code/practice/250277
*/

/*maximum balanced strings

Problem Statement
Balanced strings are those that have an equal quantity of 'L' and 'R' characters.

Given a balanced string S, split it in the maximum amount of balanced strings and encapsulate them in ‘(’ and ‘)’. For example RRLL is balanced so you have to return “(RRLL)”.

Return the string such that maximum amount of balanced encapsulated strings are there.

Input Format
The input is a single line containing the balanced string S.

Output Format
 Return the modified string such that maximum amount of balanced encapsulated strings are there.

Constraints
0 < S.length <= 2*10^6

Sample Testcase 0
Testcase Input
RLLLLRRRLR

Testcase Output
(RL)(LLLRRR)(LR)

Explanation
S can be split into "RL", "LLLRRR", "LR", each substring contains same number of 'L' and 'R'.

Sample Testcase 1
Testcase Input
RLRRLLRLRL

Testcase Output
(RL)(RRLL)(RL)(RL)
Explanation
S can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string maxBalancedStrings(string &s){
    string result;
    int balance = 0;
    string temp;

    for(char c : s){
        temp += c;
        if(c == 'L'){
            balance++;
        }
        else{
            balance--;
        }
        if(balance == 0){
            result += "(" + temp + ")";
            temp.clear();
        }
    }
    return result;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    string balanced;
    cin>>balanced;
    
    cout<<maxBalancedStrings(balanced);

    return 0;
}