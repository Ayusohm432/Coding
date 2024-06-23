/*
Problem Link :- https://www.geeksforgeeks.org/problems/print-bracket-number4058/1
*/
/*Print Bracket Number

Given a string str, the task is to find the bracket numbers, i.e., for each bracket in str, return i if the bracket is the ith opening or closing bracket to appear in the string. 

 Examples:

Input:  str = "(aa(bdc))p(dee)"
Output: 1 2 2 1 3 3
Explanation: The highlighted brackets in
the given string (aa(bdc))p(dee) are
assigned the numbers as: 1 2 2 1 3 3.
Input:  str = "(((()("
Output: 1 2 3 4 4 5
Explanation: The highlighted brackets in
the given string (((()( are assigned
the numbers as: 1 2 3 4 4 5
Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

Constraints:
1 <= |str| <= 105
str contains lowercase English alphabets, and '(', ')' characters
At any index, the number of opening brackets is greater than or equal to closing brackets

*/

/*Drivers Code


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        // Your code goes here
        
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;

        vector<int> ans = ob.bracketNumbers(s);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends

*/
//Approach-1
class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        // Your code goes here
        vector<int> brackets;
        set<int> st;
        
        int i=0;
        for(char& ch : str){
            if(ch == '('){
                i++;
                brackets.push_back(i);
                st.insert(i);
            }
            else if(ch == ')'){
                int num = *st.rbegin();
                brackets.push_back(num);
                st.erase(num); 
            }
            else{
                continue;
            }
        }
        return brackets;
    }
};

//Approach-2
class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        // Your code goes here
        vector<int> brackets;
        stack<int> st;
        
        int count = 0;
        
        for(char& ch : str){
            if(ch == '('){
                count++;
                st.push(count);
                brackets.push_back(st.top());
            }
            else if(ch == ')'){
                brackets.push_back(st.top());
                st.pop();
            }
        }
        return brackets;
    }
};