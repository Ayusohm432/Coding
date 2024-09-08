/*
Problem Link : https://unstop.com/code/practice/250517
*/

/*Leaked Memory

Problem Statement
You are given two integers, M1 and M2, representing the available memory on two sticks. A faulty program allocates i bits of memory every second, starting with 1 bit at the first second. Memory is allocated to the stick with more available memory, or to the first stick if both have the same. If neither stick has enough memory to allocate i bits, the program crashes.

Your task is to:

Output the following on the first line: Three space-separated integers crashTime, M1crash, and M2crash, where:

crashTime is the time in seconds when the program crashed.
M1crash and M2crash are the remaining bits of memory on the first and second sticks, respectively, at the time of the crash.
Output the following on the second line: The prefix sum array for the three values [crashTime, M1crash, M2crash].

Input Format
The first line contain two space separated integers representing M1 and M2.

Output Format
The first line contains three space-separated integers, crashTime, M1crash, and M2crash, where crashTime is the time in seconds when the program crashed, and M1crash and M2crash are the remaining bits of memory on the first and second sticks.

The next line contains a prefix sum of three integers: crashTime, M1crash, and M2crash.

Constraints
 0 <= M1, M2 <= 2^31 - 1

 
Sample Testcase 0
Testcase Input
 2 2
 
Testcase Output
3 1 0 
3 4 4
 
Explanation
The memory is allocated as follows:
3) At the 1st second, 1 bit of memory is allocated to stick 1. The first stick now has 1 bit of available memory.
2) At the 2nd second, 2 bits of memory are allocated to stick 2. The second stick now has 0 bits of available memory.
1) At the 3rd second, the program crashes. The sticks have 1 and 0 bits available, respectively.

Therefore, the carshTime = 3 and M1crash = 1 and M2crash = 0

And the prefix sum are:
1) crashTime = 3
2) crashTime + M1crash = 4
3) crashTime + M1crash + M2crash = 4

Sample Testcase 1
Testcase Input
8 11
Testcase Output
6 0 4 
6 6 10 
Explanation
The memory is allocated as follows:
1) At the 1st second, 1 bit of memory is allocated to stick 2. The second stick now has 10 bit of available memory.
2) At the 2nd second, 2 bits of memory are allocated to stick 2. The second stick now has 8 bits of available memory.
3) At the 3rd second, 3 bits of memory are allocated to stick 1. The first stick now has 5 bits of available memory.
4) At the 4th second, 4 bits of memory are allocated to stick 2. The second stick now has 4 bits of available memory.
5) At the 5th second, 5 bits of memory are allocated to stick 1. The first stick now has 0 bits of available memory.
6) At the 6th second, the program crashes. The sticks have 0 and 4 bits available respectively.

Therefore, the carshTime = 6 and M1crash = 0 and M2crash = 4.

And the prefix sum are:
1) crashTime = 6.
2) crashTime + M1crash = 6.
3) crashTime + M1crash + M2crash = 10.

*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Read input M1 and M2
    long long M1, M2;
    cin >> M1 >> M2;

    int crashTime = 0;
    long long M1crash = M1, M2crash = M2;
    
    for (int i = 1;; i++) {
        crashTime = i;
        if (M1crash >= M2crash) {
            if (M1crash >= i) {
                M1crash -= i;
            } else {
                break;
            }
        } else {
            if (M2crash >= i) {
                M2crash -= i;
            } else {
                break;
            }
        }
    }

    // Output the crash time and remaining memory on both sticks
    cout << crashTime << " " << M1crash << " " << M2crash << endl;

    // Calculate and output the prefix sum
    long long prefixSum1 = crashTime;
    long long prefixSum2 = prefixSum1 + M1crash;
    long long prefixSum3 = prefixSum2 + M2crash;
    cout << prefixSum1 << " " << prefixSum2 << " " << prefixSum3 << endl;

    return 0;
}
