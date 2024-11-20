/*
Problem Link : https://unstop.com/code/practice/250761
*/

/*Parenthesis

Problem Statement
You are in the world of Mystical Realm and wanted to become the King of the magical world. To achieve this, you will be given a string consisting of six type of powers  '(',')','{','}','[' and ']'. Where, powers '(','{' and '[' are opening powers and powers ')','}' and ']' are closing powers respectively. To become king , you need to determine whether given string is magical or not.

An string will be magical if the following conditions satisfy :

1.  Every opening power should be close by same type of closing power.
2.  Opening power must be close in correct order.
3. Every Closing power has a corresponding opening power.
Input Format
First line contains a single string s.

Output Format
Print True/False.

Constraints
1 <= s.length() <= 10^4
s consists of  '(', ')', '{', '}', '[' and ']'.
Sample Testcase 0
Testcase Input
()[]{}
Testcase Output
True
Explanation
The input string is a valid magical string  as it satisfies all conditions of a string to be magical.

Sample Testcase 1
Testcase Input
{]
Testcase Output
False
Explanation
The input string is not magical as it does not satisfies all conditions of a string to be magical.

*/

#include<bits/stdc++.h>
using namespace std;

// User will implement this function
bool solve(string s);

int main() {
    string s;
    cin >> s;
    if (solve(s)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    return 0;
}

// User's implementation should replace this comment
bool solve(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (st.empty() || (c == ')' && st.top() != '(') || (c == '}' && st.top() != '{') || (c == ']' && st.top() != '[')) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}