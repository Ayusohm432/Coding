/*
Problem link :- https://unstop.com/code/practice/250206
*/

/*Count set bits

Problem Statement
Mohan gave Rohan a challenge. Mohan said “I will give you a number N. You have to convert each number from 1 to N into 1's and 0's. Then, calculate the total number of occurence of 1 in those converted numbers.”

Rohan asks for your help in achieving this.

Input Format
You are given the integer N.

Output Format
Display the count of occurrence of 1. 

Constraints
0 < N<= 10^7

Sample Testcase 0
Testcase Input
4
Testcase Output
5
Explanation
for (1) => (0001), set bits = 1


for (2) => (0010), set bits = 1


for (3) => (0011), set bits = 2


for (4) => (0100), set bits = 1


Total set bits = 5


Therefore, for N = 4, result is 5

Sample Testcase 1
Testcase Input
5
Testcase Output
7
Explanation
Let input N = 5 then we have to count total set bits in digit 1 to 5,

for (1) => (0001), set bits = 1


for (2) => (0010), set bits = 1


for (3) => (0011), set bits = 2


for (4) => (0100), set bits = 1


for (5) => (0101), set bits = 2


Total set bits = 7


Therefore, for N = 5, result is 7

*/

#include <iostream>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        int num = i;
        while (num > 0) {
            count += (num & 1);
            num >>= 1;
        }
    }
    return count;
}

int main() {
    int N;
    cin >> N;

    int result = countSetBits(N);
    cout << result << endl;

    return 0;
}
