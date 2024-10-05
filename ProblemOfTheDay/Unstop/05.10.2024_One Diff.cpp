/*
Problem Link : https://unstop.com/code/practice/259746
*/

/*One Diff

Problem Statement
Alice enjoys working with numbers and has discovered an interesting property about them. She realized that any number can be represented as a sequence of its digits. For example, the number 12 can be represented as the array digits of {1, 2}, and the number 1 can be represented as the array digits of {1}.

Alice defines a number as "good" if the absolute difference between every pair of consecutive digits in its array representation of digits is exactly 1. For example: Number 1234 is a good number as it is in digit array {1, 2, 3, 4} The difference between every consecutive pair is exactly 1.

Your task is to help Alice by finding all the "good" numbers from 0 to N, inclusive, where N is a given integer.

Note: All single-digit numbers are considered good as there are no consecutive digits to compare.

Input Format
The first line of input contains a single integer N representing the upper limit of the range.

Output Format
Print all the "good" numbers from 0 to N, separated by spaces.

Constraints
1 <= N <= 10^5

Sample Testcase 0
Testcase Input
2
Testcase Output
0 1 2
Explanation
All single-digit numbers (0, 1, 2) are "good" because they consist of only one digit, so there are no consecutive digits to compare.

Sample Testcase 1
Testcase Input
25
Testcase Output
0 1 2 3 4 5 6 7 8 9 10 12 21 23 
Explanation
The numbers that satisfy the "good" condition are:


All single-digit numbers (0, 1, 2, ..., 9), because they have only one digit.
Number 10 is "good" because its digit sequence {1, 0} has a difference of 1 between the digits.
Number 12 is "good" because its digit sequence {1, 2} has a difference of 1 between the digits.
Number 21 is "good" because its digit sequence {2, 1} has a difference of 1 between the digits.
Number 23 is "good" because its digit sequence {2, 3} has a difference of 1 between the digits.


*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool check(string s){
    for(int i=1 ; i<s.length() ; i++){
        if(abs(s[i] - s[i-1]) != 1){
            return false;
        }
    }
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;

    for(int i=0 ; i<=n ; i++){
        if(i < 10){
            cout<<i<<" ";
        }
        else{
            string temp = to_string(i);
            bool good = check(temp);
            if(good){
                cout<<i<<" ";
            }
        }
    }

    return 0;
}