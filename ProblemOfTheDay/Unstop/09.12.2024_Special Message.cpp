/*
Problem Link: https://unstop.com/code/practice/250653
*/

/*Special Message

Problem Statement
Raj is a very good content writer. He usually writes repetitive words with some acronym so that he can save time and make a key-value pair list at the end of any report, or written document. Here the key denotes the acronym while the value is the corresponding value of the acronym. 
You are a junior assistant of Raj. You have to replace all the acronyms with their value. If any acronym is not found in the list of key-value pairs then replace it with “?”.
Note: All acronyms are enclosed with brackets “(“ and “)”.

Input Format
The first line contains string S.
The second line contains N, which is the size of key-value pairs
Next N lines contain two strings as the first string will be key while the second string will be value.

Output Format
A string replaced with the value of the acronyms

Constraints
6<=s.length<=10^3
0<=n<=15

0<=length(any_string_of_pair)<= 100

Note: any trailing spaces at the end of your output will be count as wrong answer.

Sample Testcase 0
Testcase Input
hello(name)
1
age five
Testcase Output
hello?
Explanation
name is special msg but it’s value is not available
then the name is replaced by “?”.
Sample Testcase 1
Testcase Input
(name)is(age)yearsold
2
name Mukesh
age fifty
Testcase Output
Mukeshisfiftyyearsold
Explanation
(name) and (age) are special msgs The value of the name in “Mukesh” and The value of age is “fifty”

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string specialmsg(string s, vector<vector<string>> vocab) {
    // User logic goes here
}

int main() {
    string s;
    cin >> s;

    int size;
    cin >> size;

    vector<vector<string>> vocab(size, vector<string>(2));
    for(int i = 0; i < size; i++) {
        cin >> vocab[i][0] >> vocab[i][1];
    }

    string ans = specialmsg(s, vocab);
    cout << ans;

    return 0;
}

string specialmsg(string s, vector<vector<string>> vocab) {
    string result = "";
    int i = 0;
    while (i < s.length()) {
        if (s[i] == '(') {
            int j = i + 1;
            while (s[j] != ')') {
                j++;
            }
            string key = s.substr(i + 1, j - i - 1);
            bool found = false;
            for (auto& pair : vocab) {
                if (pair[0] == key) {
                    result += pair[1];
                    found = true;
                    break;
                }
            }
            if (!found) {
                result += "?";
            }
            i = j + 1;
        } else {
            result += s[i];
            i++;
        }
    }
    return result;
}