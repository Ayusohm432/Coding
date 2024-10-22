/*
Problem Link : https://unstop.com/code/practice/299115
*/

/*Inversion Count

Problem Statement
You have an array of size N, and your task is to count the number of pairs (A[i], A[j]) where i < j.

For each pair, you need to check if the bitwise XOR of A[i] and A[j] is less than or equal to the bitwise AND of A[i] and A[j]. In other words, find how many pairs satisfy the condition A[i]⊕A[j] <= A[i]&A[j].

 
Input Format
First Line contains two integers N representing size of the array 

Second line contains N integers representing elements of the array.

Output Format
A single integer representing a total number of counts.

Constraints
1 >= N <= 10^5.

0 >= A[i] <= 10^5.

Sample Testcase 0
Testcase Input
4
2 4 32 8
Testcase Output
0
Explanation
There is no pair satisfying the condition.
Sample Testcase 1
Testcase Input
5
7 12 16 10 6
Testcase Output
2
Explanation
Only two pairs is satisfying the above condition:
(1,5) its respective element are (7,6), (7&6) = 6 and (7^6) = 1
 Here (7&6) ≥ (7^6)
(2,4) its respective element are (12,10), (12&10) = 8 and (12^10) = 6
 Here (12&10) ≥ (12^10)

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int c = 0;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((a[i] & a[j]) >= (a[i] ^ a[j])) {
                c++;
            }
        }
    }
    cout << c;
    return 0;
}