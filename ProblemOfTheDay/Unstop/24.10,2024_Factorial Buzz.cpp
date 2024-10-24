/*
Problem Link : https://unstop.com/code/practice/304230
*/

/*Factorial Buzz

Problem Statement
Marfi is obsessed with the factorial of numbers, he has an array of N integers and he wants to print the maximum number of trailing zeros in factorial of the all numbers 

Help Marfi to find the maximum number of leading zeros in the factorial of all numbers.

Input Format
The first line contains T as the number of test cases. Description of T test cases as follows:

The first line of each test case contains the N, size of an array.
The second line of each test case contains N space-separated integers.
Output Format
For each testcase, print the maximum count of leading zeros in the factorial of the given list of number.

Constraints
1<=T<=10^5

1<=N<=10^3

1<=A[i]<=10^4

Sample Testcase 0
Testcase Input
1
6
5 6 7 8 9 10
Testcase Output
2
Explanation
In the test case, the factorial of all the numbers is [120,720,5040,40320,362880,3628800] the maximum leading zeros are 2 in the factorial of 10.
Sample Testcase 1
Testcase Input
2
4
2 3 5 6
5
10 15 9 8 7
Testcase Output
1
3
Explanation
In the first test case, the factorial of all the numbers is [2, 6, 120, 720] the maximum number of leading zeros is 1.


In the second case, the factorial of all the numbers is [3628800, 137674368000, 362880, 40320, 5040] The maximum leading zeros are 3 in factorial of 15.

*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int count_trailing_zero(int num){
    int count = 0;
    for(int i=5 ; num/i >= 1 ; i*=5){
        count += num/i;
    }
    return count;
}
int findMaxLeadingZero(int n , vector<int>& arr){
    int maxnum = *max_element(arr.begin() , arr.end());
    return count_trailing_zero(maxnum);
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    cin>>t;

    for(int i=0 ; i<t ; i++){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        int result = findMaxLeadingZero(n , arr);
        cout<<result<<endl;
    }
    return 0;
}