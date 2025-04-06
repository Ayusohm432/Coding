/*
Problem Link: https://unstop.com/code/practice/295584
*/

/*Smallest Prime Multiplier

Problem Statement
Alice is given two integers, ( P ) and ( N ), where ( P ) is a prime number. She needs to find the smallest number ( X ) that is a multiple of both ( P ) and ( N ).

Input Format
The input consists of two space-separated integers, ( P ) and ( N ).

Output Format
Return the smallest possible value of ( X ).

Constraints
1 <= P, N <= 10^9

Sample Testcase 0
Testcase Input
3 15
Testcase Output
15
Explanation
We find that 15 is the smallest number, a multiple of 3 and 15.
Sample Testcase 1
Testcase Input
2 5
Testcase Output
10
Explanation
10 is the smallest number, a multiple of both 2 and 5.

*/

#include <iostream>

long long compute_x(long long p, long long n) {
    // Write your logic here
    if(p == n){
        return p;
    }else if(p < n && n % p == 0){
        return n;
    }else{
        return p*n;
    }
}

int main() {
    long long p, n;
    std::cin >> p >> n;
    
    // Call user logic function and print the output
    long long result = compute_x(p, n);
    std::cout << result << std::endl;
    
    return 0;
}