/*
Problem Link :- https://www.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1
*/

/*Longest Common Prefix of Strings

Given an array of strings arr. Return the longest common prefix among all strings present in the array. If there's no prefix common in all the strings, return "-1".

Examples :

Input: arr[] = ["geeksforgeeks", "geeks", "geek", "geezer"]
Output: gee
Explanation: "gee" is the longest common prefix in all the given strings.
Input: arr[] = ["hello", "world"]
Output: -1
Explanation: There's no common prefix in the given strings.
Expected Time Complexity: O(n*min(|arri|))
Expected Space Complexity: O(min(|arri|))

Constraints:
1 ≤ |arr| ≤ 103
1 ≤ |arr[i]| ≤ 103


*/


//{ Driver Code Starts
// Initial template for C++

// #include <bits/stdc++.h>
#include<iostream>
#include<string.h>
#include <string>
#include<sstream>
#include <vector>
using namespace std;


// } Driver Code Ends
// User function template for C++
//Approach-1
class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        string commonPrefix = arr[0];
        
        for(int i=1 ; i<arr.size() ; i++){
            int len = min(commonPrefix.size() , arr[i].size());
            for(int j=0 ; j<len ; j++){
                if(commonPrefix[j] != arr[i][j]){
                    commonPrefix = commonPrefix.substr(0 , j);
                    break;
                }
            }
        }
        if(commonPrefix.empty()){
            return "-1";
        }
        return commonPrefix;
    }
};


//Approach-2
class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        int n = arr.size();
        if(n == 0){
            return "-1";
        }
        string result = arr[0];
        
        for(int i=1 ; i<n ; i++){
            string temp = arr[i];
            int j=0;
            while(j<temp.length() && j<result.length() && temp[j] == result[j]){
                j++;
            }
            result = result.substr(0,j);
            
            if(result.empty()){
                return "-1";
            }
        }
        return result;
    }
};
//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends