/*
problem Link : https://unstop.com/code/practice/250733
*/

/*Minimum operations to make zero

Problem Statement
Given an integer N, the task is to reduce N to 0 in the minimum number of operations using the following operations any number of times:

Change the rightmost (0th) bit in the binary representation of N.

Change the ith bit in the binary representation of N if the (i-1)th bit is set to 1 and the (i-2)th through 0th bits are set to 0.

Print the count of the number of primes less than or equal to the minimum number of operations needed to reduce N to 0.

Input Format
The only line contains an integer N representing the value which is to be reduced to zero.

Output Format
Print a single integer denoting the number of primes less than equal to the minimum number of operations needed to reduce N to 0.

Constraints
0 <= N <= 10^9

Sample Testcase 0
Testcase Input
6
Testcase Output
2
Explanation
The binary representation of 6 is "110". "110" -> "010" with the 2nd operation since the 1st bit is 1 and 0th through 0th bits are 0. "010" -> "011" with the 1st operation. "011" -> "001" with the 2nd operation since the 0th bit is 1. "001" -> "000" with the 1st operation. Which gives us minimum number of operations as 4 ,


the prime number less than or equal to 4 are 2,3 thus the count of primes becomes our final answer and give us two.

Sample Testcase 1
Testcase Input
3
Testcase Output
1
Explanation
The binary representation of 3 is "11". "11" -> "01" with the 2nd operation since the 0th bit is 1. "01" -> "00" with the 1st operation. Which gives us minimum number of operations as 2 , the prime number less than or equal to 2 is 2 itself


thus the count of primes becomes our final answer and give us one as our answer

*/
#include <bits/stdc++.h>
using namespace std;

int minimumOperationsBit(int n, int res) {

    if(n == 0) return res;

    int b =1;
    while((b << 1) <= n) b = b<<1;

    return minimumOperationsBit((b>>1)^b ^n, res + b);
}

int sieveOfEratosthenes(int n) {

    bool prime[n + 1];
    for(int i=0; i<=n; i++) {
        prime[i] = true;
    }


    for(int p=2; p*p<=n; p++) {
        if(prime[p] == true) {
            for(int i=p*p; i<=n; i+=p)
                prime[i] = false;
        }
    }

    int count=0;
    for(int i=2; i<=n; i++) {
        if(prime[i] == true) count++;
    }
    return count;
}

int main() {
    
    int n;
    cin>>n;

    int ans = minimumOperationsBit(n, 0);
    cout<<sieveOfEratosthenes(ans)<<endl; 
    return 0;
}