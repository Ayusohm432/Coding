/*
Problem Link: https://www.geeksforgeeks.org/problems/multiply-two-strings/1
*/

/*Multiply two strings

Given two numbers as strings s1 and s2. Calculate their Product.
Note: The numbers can be negative and You are not allowed to use any built-in function or convert the strings to integers. There can be zeros in the begining of the numbers. You don't need to specify '+' sign in the begining of positive numbers.

Examples:

Input: s1 = "0033", s2 = "2"
Output: "66"
Explanation: 33 * 2 = 66
Input: s1 = "11", s2 = "23"
Output: "253"
Explanation: 11 * 23  = 253
Input: s1 = "123", s2 = "0"
Output: "0"
Explanation: Anything multiplied by 0 is equal to 0.
Constraints:
1 ≤ s1.size() ≤ 103
1 ≤ s2.size() ≤ 103

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    /*You are required to complete below function */
    string multiplyStrings(string& s1, string& s2) {
        // Your code here
        bool negative = false;
        
        if(s1[0] == '-'){
            negative = !negative;
            s1 = s1.substr(1);
        }
        
        if(s2[0] == '-'){
            negative = !negative;
            s2 = s2.substr(1);
        }
        
        int l1 = s1.length();
        int l2 = s2.length();
        
        vector<int> result(l1+l2, 0);
        
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        
        for(int i=0; i<l1; i++){
            for(int j=0; j<l2; j++){
                result[i+j] += (s1[i] - '0') * (s2[j] - '0');
                result[i+j+1] += result[i+j] / 10;
                result[i+j] %= 10;
            }
        }
        
        string finalResult = "";
        bool zero = true;
        
        for(int i=result.size()-1; i>=0; i--){
            if(result[i] != 0){
                zero = false;
            }
            if(zero == false){
                finalResult += (result[i] + '0');
            }
        }
        
        if(finalResult.empty()){
            return "0";
        }
        if(negative){
            finalResult = "-" + finalResult;
        }
        return finalResult;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string a;
        string b;
        cin >> a >> b;
        Solution obj;
        cout << obj.multiplyStrings(a, b) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends