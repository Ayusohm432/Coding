/*
Problem link : https://unstop.com/code/practice/250524
*/

/*Find possible words

Problem Statement
Vikas needs help solving a puzzle where he must find which words can be formed using the characters from a given string.

You are given an array of strings W with N elements and a string C. A word is considered "good" if it can be formed using the characters from C, with each character in C being used at most once.

Your task is to calculate and return the sum of the lengths of all the "good" strings in the array W.

Input Format
The first line contains an integer n, representing the length of the array W.

The next N line takes a single string representing the element of array W.

The last line contains the single string C, representing the character string.

Output Format
Print the sum of the lengths of all the good strings in the words.

Constraints
1 <= N <= 10^3

1 <= W[i].length, C.length <= 10^2


Sample Testcase 0
Testcase Input
5
abc
bce
mcb
nab
omn
zklac
Testcase Output
0
Explanation
There are  no string that can be formed using the characters in the string "zklac".

Sample Testcase 1
Testcase Input
10
cmkkm
uqguo
ilgpk
ovjad
cyzpx
tptjk
uhyta
qarhb
sqaed
fdfdf
ovjadqguoqarhb
Testcase Output
10
Explanation
WIth the characters in "ovjadqguoqarhb" we can form the strings:


1) "ovjad" of length 5 as all character of string appear in string C
2) "qarhb" of length 5 as all character of string appear in string C

Therefore, the sum of total length is 5 + 5 = 10


*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<string> w(n);  
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    string c;
    cin >> c;

    int totalLength = 0;
    unordered_map<char, int> mp;


    for (char& ch : c) {
        mp[ch]++;
    }


    for (auto& word : w) {
        unordered_map<char, int> tempMp = mp;  
        string temp = "";
        for (char& ch : word) {
            if (tempMp.find(ch) == tempMp.end() || tempMp[ch] == 0) {  

                break;
            }
            tempMp[ch]--;  
            temp += ch;
        }
        if (temp == word) {
            totalLength += word.length();  
        }
    }

    cout << totalLength;
    return 0;
}
