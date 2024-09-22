/*
Problem Link : https://unstop.com/code/practice/250608
*/

/*AND Triplets

Problem Statement
Given an integer array, arr. Display the count of AND triplets.

An AND triplet is a set of three indices i, j, and k such that:

0 <= i < arr.length
0 <= j < arr.length
0 <= k < arr.length
The bitwise AND of the elements at these indices equals zero, i.e., arr[i] & arr[j] & arr[k] == 0, where & denotes the bitwise AND operator.
 

Input Format
The first line contains an integer N, the number of elements in the array.

The second line contains N integers, representing the elements of the array arr.

Output Format
Print a single integer: the number of AND triplets in the array.

Constraints
1 <= N <= 10^3

0 <= arr[i] < 216

Sample Testcase 0
Testcase Input
2
1 2 
Testcase Output
6
Explanation
We can select the following i, j ,k triples:


(i = 0, j = 0, k = 1) : 1&1&2 = 0
(i = 0, j = 1, k = 1) : 1&2&2 = 0
(i = 1, j = 0, k = 1) : 2&1&2 = 0
(i = 1, j = 1, k = 0) : 2&2&1 = 0
(i = 0, j = 1, k = 0) : 1&2&1 = 0
(i = 1, j = 0, k = 0): 2&1&1 = 0

Sample Testcase 1
Testcase Input
3
2 1 3 
Testcase Output
12
Explanation
We could choose the following i, j, k triples:


(i=0, j=0, k=1) : 2 & 2 & 1 = 0
(i=0, j=1, k=0) : 2 & 1 & 2 = 0
(i=0, j=1, k=1) : 2 & 1 & 1 = 0
(i=0, j=1, k=2) : 2 & 1 & 3 = 0
(i=0, j=2, k=1) : 2 & 3 & 1 = 0
(i=1, j=0, k=0) : 1 & 2 & 2 = 0
(i=1, j=0, k=1) : 1 & 2 & 1 = 0
(i=1, j=0, k=2) : 1 & 2 & 3 = 0
(i=1, j=1, k=0) : 1 & 1 & 2 = 0
(i=1, j=2, k=0) : 1 & 3 & 2 = 0
(i=2, j=0, k=1) : 3 & 2 & 1 = 0
(i=2, j=1, k=0) : 3 & 1 & 2 = 0

*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if ((arr[i] & arr[j] & arr[k]) == 0) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}