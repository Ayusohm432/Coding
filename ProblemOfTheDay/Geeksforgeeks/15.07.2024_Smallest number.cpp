/*
Problem Link :- https://www.geeksforgeeks.org/problems/smallest-number5829/1
*/

/*Smallest number

Given two integers s and d. The task is to find the smallest number such that the sum of its digits is s and the number of digits in the number are d. Return a string that is the smallest possible number. If it is not possible then return -1.

Examples:

Input: s = 9, d = 2
Output: 18 
Explanation: 18 is the smallest number possible with the sum of digits = 9 and total digits = 2.
Input: s = 20, d = 3 
Output: 299 
Explanation: 299 is the smallest number possible with the sum of digits = 20 and total digits = 3.
Expected Time Complexity: O(d)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ s ≤ 100
1 ≤ d ≤ 6



*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//Approach-1
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code heres
        string ans = "";
        int i=1;
        
        while(i<=d){
            int num = s-9*(d-i);
            if(num <= 0){
                num = 0;
            }
            if(num > 9){
                return "-1";
            }
            if(num == 0 && i == 1){
                num = 1;
            }
            
            ans += (num + '0');
            
            i++;
            
            s -= num;
        }
        
        return ans;
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
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends


//Approach-2
class Solution {
  public:

    string printString(string s, char ch, int count) {
        // Your code goes here
        
        int n = s.length();
        
        
        int i;
        for(i=0 ; i<n ; i++){
            if(ch == s[i]){
                count--;
            }
            if(!count){
                break;
            }
        }
        if(i >= n-1 ){
            return "";
        }
        s = s.substr(i+1);
        
        return s;
        
    }
};