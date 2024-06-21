/*
Problem Link :- https://www.geeksforgeeks.org/problems/compare-two-fractions4438/1
*/

/*Compare two fractions

You are given a string str containing two fractions a/b and c/d, compare them and return the greater. If they are equal, then return "equal".

Note: The string str contains "a/b, c/d"(fractions are separated by comma(,) & space( )). 

Examples

Input: str = "5/6, 11/45"
Output: 5/6
Explanation: 5/6=0.8333 and 11/45=0.2444, So 5/6 is greater fraction.
Input: str = "8/1, 8/1"
Output: equal
Explanation: We can see that both the fractions are same, so we'll return a string "equal".
Input: str = "10/17, 9/10"
Output: 9/10
Explanation: 10/17 = 0.588 & 9/10 = 0.9, so the greater fraction is "9/10".
Expected Time Complexity: O(len|str|)
Expected Auxiliary Space: O(1)

Constraints:
0<=a,c<=103
1<=b,d<=103

*/

//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {

        // Code here
        int n = str.length();
        string fraction1="",fraction2="";
        
        
        //Splitting the Fraction
        int i=0;
        int j=2;
        while(str[i] != ','){
            fraction1 += str[i];
            i++;
            j++;
        }
        while(j<n){
            fraction2 += str[j];
            j++;
        }
        
         // Splitting numerator and denominator from fraction1 and fraction2
        int nr1,nr2,dr1,dr2;
        char slash;
        istringstream(fraction1) >> nr1 >> slash >> dr1;
        istringstream(fraction2) >> nr2 >> slash >> dr2;
        
        
        // Comapring the fraction
        if(nr1*dr2 > nr2*dr1){
            return fraction1;
        }
        else if(nr1*dr2 < nr2*dr1){
            return fraction2;
        }
        else{
            return "equal";
        }
        
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends