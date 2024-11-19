/*
Problem Link: https://unstop.com/code/practice/292155
*/

/*248 Numbers

Problem Statement
A number is said to be a 248 number if the count of 2’s is equal to the count of 4’s and the count of 4’s is equal to the count of 8’s. The count of 2’s should be at least 1.

Given a number N. Find 248 numbers in the interval [1, N]. Print the answer mod 1000000007.

Input Format
The first and only line contains an integer N.

Output Format
 Return the count of 248 numbers in the interval [1, N] mod 1000000007.

Constraints
1 <= N <= 10^7

Sample Testcase 0
Testcase Input
10
Testcase Output
0
Explanation
There is no number less than or equal to 10 that has 2,4 and 8, all three as its digits.
Sample Testcase 1
Testcase Input
300
Testcase Output
2
Explanation
There are 2 numbers less than or equal to 300 that have 2,4 and 8, all three as their digits. The two numbers are 248 and 284. Both have equal 2’s, 4’s, and 8’s, i.e., 1.

*/

#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

// Function declaration
int count_248_numbers(int N);

int main() {
    int N;
    cin >> N;
    
    int result = count_248_numbers(N);
    cout << result << endl;
    
    return 0;
}

int count_248_numbers(int N) {
    int count = 0;
    for (int i = 1; i <= N; i++) {
        int num = i;
        int two = 0, four = 0, eight = 0;
        while (num > 0) {
            int digit = num % 10;
            if (digit == 2) two++;
            if (digit == 4) four++;
            if (digit == 8) eight++;
            num /= 10;
        }
        if (two == four && four == eight && two >= 1) {
            count++;
        }
    }
    return count % MOD;
}