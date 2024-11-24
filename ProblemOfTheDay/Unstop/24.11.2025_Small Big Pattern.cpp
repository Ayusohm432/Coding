/*
Problem Link: https://unstop.com/code/practice/261000
*/

/*Small Big Pattern

Problem Statement
Small-Big Pattern is  a sequence where each element is either larger or smaller than its adjacent elements.

Your task is to determine the longest possible small-big pattern that can be created using the given array. 

 

Input Format
The first line of Input contains a single integer N representing the number of elements in the array Arr.

The second line of Input contains N space-separated integers representing the elements of arrray Arr.

Output Format
Display a single integer representing the length of the longest small-big pattern that can be formed from the elements of the array Arr.

Constraints
1 ≤ N ≤ 105

1 ≤ Arr[i] ≤ 105

Sample Testcase 0
Testcase Input
3
1 5 4
Testcase Output
3
Explanation
The whole array is in the form of X1<X2>X3.

Sample Testcase 1
Testcase Input
8
10 22 9 33 49 50 31 60
Testcase Output
6
Explanation
The subsequences {10, 22, 9, 33, 31, 60} or {10, 22, 9, 49, 31, 60} or {10, 22, 9, 50, 31, 60} are the longest subsequences of length 6.

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll bigSmallSequence(ll arr[], ll n);

int main()
{
    ll n;
    cin >> n;
    ll arr[n];
    for(ll i = 0; i < n; i++) 
        cin >> arr[i];
    cout << bigSmallSequence(arr, n) << endl;
    return 0;
}

ll bigSmallSequence(ll arr[], ll n) {
    if (n == 0) return 0;

    ll up = 1;  
    ll down = 1; 

    for (ll i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            up = down + 1;
        } else if (arr[i] < arr[i - 1]) {
            down = up + 1; 
        }
    }

    return max(up, down);
}

