/*
Problem Link :- https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1
*/

/*Kth Smallest

Given an array arr[] and an integer k where k is smaller than the size of the array, the task is to find the kth smallest element in the given array. It is given that all array elements are distinct.

Follow up: Don't solve it using the inbuilt sort function.

Examples :

Input: arr[] = [7, 10, 4, 3, 20, 15], k = 3
Output:  7
Explanation: 3rd smallest element in the given array is 7.
Input: arr[] = [7, 10, 4, 20, 15], k = 4 
Output:  15
Explanation: 4th smallest element in the given array is 15.
Expected Time Complexity: O(n+(max_element) )
Expected Auxiliary Space: O(max_element)
Constraints:
1 <= arr.size <= 106
1<= arr[i] <= 106
1 <= k <= n



*/

//{ Driver Code Starts
// Initial function template for C++

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include<string>
#include<sstream>

using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        int mx = INT_MIN;
        for(auto x : arr){
            mx = max(mx,x);
        }
        
        int Arr[mx+1];
        memset(Arr , 0 , sizeof(Arr));
        
        for(auto x : arr){
            Arr[x] = 1;
        }
        
        for(int i=0 ; i<= mx ; i++){
            k -= Arr[i];
            if(!k){
                return i;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        k = crr[0];
        int n = arr.size();
        Solution ob;
        cout << ob.kthSmallest(arr, k) << endl;
    }
    return 0;
}

// } Driver Code Ends