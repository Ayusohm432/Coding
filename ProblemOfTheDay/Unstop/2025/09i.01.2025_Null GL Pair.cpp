/*
Problem link: https://unstop.com/code/practice/293340
*/

/*Null GL Pair

Problem Statement
Leo is fascinated by the concepts of Greatest Common Divisor (GCD) and Least Common Multiple (LCM). Alice gives him an array and challenges him to find how many pairs (i, j) in the array satisfy a particular condition.

Leo defines GL(i, j) as the difference between LCM(A[i], A[j]) and GCD(A[i], A[j]), where i and j are indices of the array and 0<=i < j < N.

Your task is to help Leo count how many pairs (i, j) in the array satisfy GL(i, j) = 0. Return the total number of such pairs

Input Format
The first line contains an integer N, representing the size of A.

The next line contains N space-separated integers, representing the original array A.

Output Format
Print the total number of pairs with GL(i,j) = 0.

Constraints
1 ≤ N ≤10^5

1 ≤ A[i]  ≤100

Sample Testcase 0
Testcase Input
2
4 7
Testcase Output
0
Explanation
The only possible pair is GL(1,2) = LCM(4,7) - GCD(4,7) = 28-1 = 27, which is not equal to 0.

Sample Testcase 1
Testcase Input
5
1 3 3 3 7
Testcase Output
3
Explanation
There are only 3 pairs that have GL(i,j) = 0.
(2,3), (3,4), and (2,4),
(2,3) = LCM(3,3) - GCD(3,3) = 3-3 = 0.
(3,4) = LCM(3,3) - GCD(3,3) = 3-3 = 0.
(2,4) = LCM(3,3) - GCD(3,3) = 3-3 = 0.

*/

#include <bits/stdc++.h>
using namespace std;
int GLPairs(int n,vector<int>&num)
{
    unordered_map<long long int, long long int>mp; 
    long long int ans =0; 
    for(auto &i: num) 
    mp[i]++;
    for(auto &i: mp)
    {
    ans += ((i.second*(i.second-1))/2);  
    }
    return ans; 
}
int main() {
     int n ;
     cin>>n;
     vector<int>vec(n);
     for(auto &i:vec)
    {
        cin>>i;
    }
    cout<<GLPairs(n,vec)<<endl;
    return 0;
}