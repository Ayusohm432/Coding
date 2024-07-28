/*
Problem Link :- https://www.geeksforgeeks.org/problems/remove-duplicates3034/1
*/

/*Remove Duplicates

Given a string str without spaces, the task is to remove all duplicate characters from it, keeping only the first occurrence.

Note: The original order of characters must be kept the same. 

Examples :

Input: str = "zvvo"
Output: "zvo"
Explanation: Only keep the first occurrence
Input: str = "gfg"
Output: "gf"
Explanation: Only keep the first occurrence
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= |str| <= 105
str contains lowercase English alphabets

*/

//{ Driver Code Starts
// #include <bits/stdc++.h>
#include<iostream>
#include<stack>
#include<unordered_set>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Approach-1
class Solution {
  public:

    string removeDups(string str) {
        // Your code goes here
        int arr[26] = {0};
        int j=0;
        
        for(int i=0 ; i<str.size() ; i++){
            if(arr[str[i] - 'a'] == 0){
                str[j++] = str[i];
            }
            arr[str[i] - 'a']++;
        }
        
        return str.substr(0 , j);
    }
};


//Approach-2
// User function template for C++
class Solution {
  public:

    string removeDups(string str) {
        // Your code goes here
        unordered_set<char> temp;
        string result;
        
        for(char& ch : str){
            if(!temp.count(ch)){
                temp.insert(ch);
                result += ch;
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends