/*
Problem Link :- https://www.geeksforgeeks.org/problems/the-palindrome-pattern3900/1
*/

/*The Palindrome Pattern

Given a two-dimensional integer array arr of dimensions n x n, consisting solely of zeros and ones, identify the row or column (using 0-based indexing) where all elements form a palindrome. If multiple palindromes are identified, prioritize the palindromes found in rows over those in columns. Within rows or columns, the palindrome with the smaller index takes precedence. The result should be represented by the index followed by either 'R' or 'C', indicating whether the palindrome was located in a row or column. The output should be space-separated. If no palindrome is found, return the string -1.

Examples:

Input: 
arr[][] =  [[1, 0, 0], 
           [0, 1, 0],
           [1, 1, 0]]
Output: 1 R
Explanation: In the first test case, 0-1-0 is a palindrome 
occuring in a row having index 1.
Input: 
arr[][] =   [[1, 0],
           [1, 0]]
Output: 0 C
Explanation: 1-1 occurs before 0-0 in the 0th column. And there is no palindrome in the two rows.
Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(1)

Constraints:
1<= arr.size <= 50
0 <= arr[i][j] <= 1

*/

/*Driver's Code


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string pattern(vector<vector<int>> &arr) {
        // Code Here
        
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends

*/


class Solution {
  public:
    bool isPalindrome(vector<int> array){
        int n = array.size();
        for(int i=0 ; i<n/2 ; i++){
            if(array[i] != array[n-i-1]){
                return false;
            }
        }
        return true;
    }
    string pattern(vector<vector<int>> &arr) {
        // Code Here
        int n = arr.size();
        
        for(int i=0 ; i<n ; i++){
            if(isPalindrome(arr[i])){
                return to_string(i)+" R";
            }
        }

        for(int i=0 ; i<n ; i++){
            vector<int> elements;
            for(int j=0 ; j<n ; j++){
                elements.push_back(arr[j][i]);
            }
            if(isPalindrome(elements)){
                return to_string(i) + " C";
            }
        }
        
        return "-1";
    }
};