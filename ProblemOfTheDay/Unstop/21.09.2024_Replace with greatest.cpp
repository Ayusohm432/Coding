/*
Problem Link : https://unstop.com/code/practice/250602
*/

/*Replace with greatest

Problem Statement
Given an array arr, your task is to replace each element in the array with the greatest element among the elements to its right. The last element of the array should be replaced with -1 since there are no elements to its right.

The function should return the modified array after these transformations.

Input Format
The first line contains an integer N, representing the size of the array.

The second line contains N space-separated integers representing the elements of the array.

Output Format
A single line containing the elements of the modified array, with each element replaced by the greatest element among the elements to its right, and the last element replaced by -1.

Constraints
1 <= arr.length <= 10^4

1 <= arr[i] <= 10^5

 

Sample Testcase 0
Testcase Input
 5
3 2 1 8 7
Testcase Output
 8 8 8 7 -1
Explanation
 - index 0 --> the greatest element to the right of index 0 is index 3 (8).
- index 1 --> the greatest element to the right of index 1 is index 3 (8).
- index 2 --> the greatest element to the right of index 2 is index 3 (8).
- index 3 --> the greatest element to the right of index 3 is index 4 (7).
- index 4 --> there are no elements to the right of index 4, so we put -1.
Sample Testcase 1
Testcase Input
6
17 18 5 4 6 1
Testcase Output
 18 6 6 6 1 -1
Explanation

For the element at index 0 (value 17), the greatest element among all elements to its right is 18, so it is replaced by 18.

For the element at index 1 (value 18), the greatest element among all elements to its right is 6, so it is replaced by 6.

For the element at index 2 (value 5), the greatest element among all elements to its right is 6, so it is replaced by 6.

For the element at index 3 (value 4), the greatest element among all elements to its right is also 6, so it is replaced by 6.

For the element at index 4 (value 6), the greatest element among all elements to its right is 1, so it is replaced by 1.

The element at index 5 (value 1) has no elements to its right, so it is replaced by -1.

*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> findGreatest(vector<int>& arr){
    int n = arr.size();
    vector<int> result(n , -1);

    int maxi = arr[n-1];

    for(int i=n-2 ; i>=0 ; i--){
        result[i] = maxi;
        maxi = max(maxi , arr[i]);
    }
    return result;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }

    vector<int> result = findGreatest(arr);

    for(int i=0 ; i<n  ; i++){
        cout<<result[i]<<" ";
    }

    return 0;
}