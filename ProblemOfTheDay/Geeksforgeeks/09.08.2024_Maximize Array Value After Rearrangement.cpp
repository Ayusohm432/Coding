/*
Problem Link :- https://www.geeksforgeeks.org/problems/maximize-arrii-of-an-array0026/1
*/

/*Maximize Array Value After Rearrangement

Given an array arr of n integers. Your task is to write a program to find the maximum value of ∑arr[i]*i, where i = 0, 1, 2,., n-1. You are allowed to rearrange the elements of the array.

Note: Since the output could be large, print the answer modulo 109+7.

Examples :

Input : arr[] = [5, 3, 2, 4, 1]
Output : 40
Explanation: If we arrange the array as 1 2 3 4 5 then we can see that the minimum index will multiply with minimum number and maximum index will multiply with maximum number. So, 1*0 + 2*1 + 3*2 + 4*3 + 5*4 = 0+2+6+12+20 = 40 mod(109+7) = 40

Input : arr[] = [1, 2, 3]
Output : 8
Expected Time Complexity: O(nlog(n))
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ arr.size ≤ 105
1 ≤ arri ≤ 105

*/


//{ Driver Code Starts
// #include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int Maximize(vector<int> &arr) {
        // Complete the function
        int mod = 1e9+7;
        sort(arr.begin() , arr.end());
        long long int sum = 0;
        for(int i=0 ; i<arr.size(); i++) {
            sum += 1LL*i*arr[i];
            sum %= mod;
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        //  cin.ignore();
        int n = arr.size();
        Solution ob;
        cout << ob.Maximize(arr) << endl;
    }
}
// } Driver Code Ends