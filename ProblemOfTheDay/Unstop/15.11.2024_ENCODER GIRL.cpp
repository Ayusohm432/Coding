/*
Problem Link: https://unstop.com/code/practice/300208
*/

/*ENCODER GIRL

Problem Statement
Lexi, a 12-year-old girl fascinated by morse code, wanted to play a game with her dad involving word decoding.

Although she doesn't know exactly how morse code works, she came up with her own version of the game. She gives her dad a list of words and a character, asking him to decode the message by removing all occurrences of the given character from each word.

The task is to calculate the length of each word after the character is removed and sort the resulting lengths in ascending order.

Help Lexi's dad by writing a program that performs this task based on the inputs provided.

Input Format
The first line of input contains a single integer N, representing the number of words to be processed.

The second line contains N space-separated strings (words).

The third line contains the character that needs to be removed from each word.

Output Format
Output a single line with integers separated by spaces, representing the lengths of the words after removing the specified character. If the character appears multiple times in a word, all instances should be removed. Ensure that the lengths are sorted in ascending order.

Constraints
1<=N<=255

1<=Length of each word(string)<=500


Sample Testcase 0
Testcase Input
3
rifles are ready
e
Testcase Output
2 4 5
Explanation
'e' is removed from each word which will result in the length as 5,2,4 and after sorting it will result
in 2,4,5.
Sample Testcase 1
Testcase Input
4
grenades are being imported
a
Testcase Output
2 5 7 8
Explanation
'a' is removed from each word which will result in the length as 7,2,5(as there was no 'a' in word
"being"),8(as there was no 'a' in word "imported") and after sorting it will result in 2,5,7,8.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// User-defined function to be implemented
vector<int> processWords(int n, vector<string> s, char x);

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    char x;
    cin >> x;
    // Calling the user-defined function
    vector<int> result = processWords(n, s, x);
    // Printing the result in the required format
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}

// User-defined function to be implemented
vector<int> processWords(int n, vector<string> s, char x) {
    // User needs to write the logic here
    vector<int> v;
    for(string& str: s){
        int length = str.length() - count(str.begin(), str.end(), x);
        v.push_back(length);
    }

    sort(begin(v), end(v));
    return v;
}


