/*
Problem Link :- https://www.geeksforgeeks.org/problems/k-pangrams0909/1
*/

/*K-Pangrams


Given a string str and an integer k, return true if the string can be changed into a pangram after at most k operations, else return false.

A single operation consists of swapping an existing alphabetic character with any other alphabetic character.

Note - A pangram is a sentence containing every letter in the english alphabet.

Examples :

Input: str = "the quick brown fox jumps over the lazy dog", k = 0
Output: true
Explanation: the sentence contains all 26 characters and is already a pangram.
Input: str = "aaaaaaaaaaaaaaaaaaaaaaaaaa", k = 25 
Output: true
Explanation: The word contains 26 instances of 'a'. Since only 25 operations are allowed. We can keep 1 instance and change all others to make str a pangram.
Input: str = "a b c d e f g h i j k l m", k = 20
Output: false
Explanation: Since there are only 25 charaacters only in this case, so no amount of swapping we can have panagram here.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)  

Constraints:
1<= str.size() <= 105
0<= k <= 50
str may contain duplicate characters
str contains only lowercase alphabets or spaces



*/

//{ Driver Code Starts
// #include <bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<string>
#include<sstream>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
        int alphabetCount[26] = {0};
        int operationNeeded = 0;
        int count = 0;
        
        for(int i=0 ; i < str.size() ; i++){
            if(str[i] != ' '){
                alphabetCount[str[i] - 'a']++;
                count++;
            }
        }
        
        for(int i=0 ; i<26 ; i++){
            if(alphabetCount[i] == 0){
                operationNeeded++;
            }
        }
        
        return (operationNeeded <= k) && (count >= 26);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends

