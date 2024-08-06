/*
Problem Link :- https://www.geeksforgeeks.org/problems/validate-an-ip-address-1587115621/1
*/

/*Validate an IP Address

You are given a string str in the form of an IPv4 Address. Your task is to validate an IPv4 Address, if it is valid return true otherwise return false.

IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots, e.g., 172.16.254.1

A valid IPv4 Address is of the form x1.x2.x3.x4 where 0 <= (x1, x2, x3, x4) <= 255. Thus, we can write the generalized form of an IPv4 address as (0-255).(0-255).(0-255).(0-255)

Note: Here we are considering numbers only from 0 to 255 and any additional leading zeroes will be considered invalid.

Examples :

Input: str = 222.111.111.111
Output: true
Explanation: Here, the IPv4 address is as per the criteria mentioned and also all four decimal numbers lies in the mentioned range.
Input: str = 5555..555
Output: false
Explanation: 5555..555 is not a valid. IPv4 address, as the middle two portions are missing.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1<=str.length() <=15


*/

//{ Driver Code Starts
// #include <bits/stdc++.h>
#include<iostream>
#include<string>

using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
  public:
    int isValid(string str) {
        // code here
    int dots = 0;
    int num = 0;
    bool isValid = true;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '.') {
            dots++;
            if (num > 255 || num < 0) {
                isValid = false;
                break;
            }
            num = 0;
        } else if (str[i] >= '0' && str[i] <= '9') {
            if (num == 0 && str[i] == '0' && i > 0 && str[i - 1] != '.') {
                isValid = false;
                break;
            }
            num = num * 10 + (str[i] - '0');
        } else {
            isValid = false;
            break;
        }
    }

    if (dots != 3 || num > 255 || num < 0) {
        isValid = false;
    }

    return isValid;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends