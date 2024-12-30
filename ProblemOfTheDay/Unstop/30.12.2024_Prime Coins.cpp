/*
Problem Link: https://unstop.com/code/practice/293472
*/

/*Prime Coins

Problem Statement
John and Davis are playing a game with N distinct coins, each numbered from 1 to N. John challenges Davis to place the coins in a straight line. The challenge is that any coin with a number P that satisfies the equation 1×2×3×...×(p−1)+1 is divisible by  P  must be placed at a prime position in the line. Davis is confused and needs help to find the number of ways to arrange the coins.

Note: If the number of ways is large, take the result modulo 10^9 + 7.

Input Format
The first line consists of an integer N which denotes the number of coins.

Output Format
Print a single line consisting of an integer that shows the number of ways that are possible.

Constraints
1 <= N <= 10^6

Sample Testcase 0
Testcase Input
5
Testcase Output
12
Explanation
Explanation for sample case 1: 
For example [1,2,5,4,3] is a valid way, but [5,2,3,4,1] is not because the prime number 5 is at index 1.
Sample Testcase 1
Testcase Input
8
Testcase Output
576
Explanation
One such valid way is [1,2,3,4,5,6,7,8], and there are many more.

*/


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 1e9 + 7;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result = (result * i) % MOD;
    }
    return result;
}

int numPrimeArrangements(int n) {
    int primeCount = 0;
    for (int i = 1; i <= n; i++) {
        if (isPrime(i)) primeCount++;
    }

    long long primeArrangements = factorial(primeCount);
    long long nonPrimeArrangements = factorial(n - primeCount);
    long long totalArrangements = (primeArrangements * nonPrimeArrangements) % MOD;

    return totalArrangements;
}

int main() {
    int n;
    cin >> n;

    int result = numPrimeArrangements(n);
    cout << result << endl;

    return 0;
}