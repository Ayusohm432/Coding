/*
Problem link: https://unstop.com/code/practice/302911
*/

/*Minimum Largest Number

Problem Statement
Given an array of integers arr[] of size N, find the two smallest integers in the array and form the largest possible number using them. Output this largest number

Input Format
The first line contains an integer, where N denotes the number of elements in the array in the array.
The second line contains N space-separated integers.

Output Format
Print the largest number that can be formed.

Constraints
1 ≤ N ≤ 10^2
0 ≤ arr[i] ≤9

Sample Testcase 0
Testcase Input
7
1 2 3 4 5 6 7
Testcase Output
21
Explanation
The two minimum numbers out of the given array are 1 and 2. If we try to make the largest number possible using these two numbers, we get 21.
Sample Testcase 1
Testcase Input
4
7 8 9 6
Testcase Output
76
Explanation
The two minimum numbers out of the given array are 6 and 7. If we try to make the largest number possible using these two numbers, we get 76.

*/

#include <bits/stdc++.h>
using namespace std;

// User-defined function declaration
int formLargestNumber(int n, vector<int> arr);

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Call the user-defined function
    int result = formLargestNumber(n, arr);
    
    // Print the result
    cout << result << endl;
    
    return 0;
}

// User-defined function definition
int formLargestNumber(int n, vector<int> arr) {
    sort(arr.begin(), arr.end());
    string num1 = to_string(arr[0]);
    string num2 = to_string(arr[1]);
    return stoi(num2 + num1);
}