/*
Problem Link : https://unstop.com/code/practice/304594
*/

/*Prime Number Square

Problem Statement
Given a number N. Your task is to create a program to calculate the N-th term of the Alice choice.

Alice's sequence consists of the squares of prime numbers: 2^2, 3^2, 5^2, 7^2, 11^2,13^2,17^2,19^2, 23^2, 29^2,…………

Input Format
The first line should contain only one line input given as number N.

Output Format
Output the square of the prime number at the N-th position in the sequence.

Constraints
1 <= N <= 10^5

Sample Testcase 0
Testcase Input
10
Testcase Output
841
Explanation
The Nth term is 841 It is one-based indexing, and by observing the pattern of the sequence then, all numbers are prime numbers and have to calculate the 10th term. So, The 10th number is 29, and its square is 841.

Sample Testcase 1
Testcase Input
3
Testcase Output
25
Explanation
The Nth term is 25 It is one-based indexing, and by observing the pattern of the sequence then, all numbers are prime numbers and have to calculate the 3rd term. 
So, the 3rd number is 5, and its square is 5^2 is 25. 
Sequence: 2, 3, 5 
Index.       : 1, 2, 3

*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPrime(int n){
    if(n <= 1){
        return 0;
    }

    if(n == 2 || n==3){
        return 1;
    }

    if(n%2 == 0 || n%3 == 0){
        return 0;
    }

    for(int i=5 ; i*i <= n ; i=i+6){
        if(n%i == 0 || n%(i+2) == 0){
            return 0;
        }
    }

    return 1;
}

int findPrime(int n){
    int i=2;

    while(n > 0){
        if(isPrime(i)){
            n--;
        }
        i++;
    }

    return i-1;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;

    if(n == 0){
        return 0;
    }
    int prime = findPrime(n);
    
    int result = prime * prime;

    cout<<result;

    return 0;
}