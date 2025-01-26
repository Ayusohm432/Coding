/*
Problem Link: https://unstop.com/code/practice/499038
*/

/*Alphabetic Treasure Hunt: Sorting Clues by Difficulty

Problem Statement
You are organizing a unique treasure hunt where each clue is represented by a lowercase Latin alphabet. The clues are distributed across different zones, and each zone has a number assigned to it, based on its position in the alphabet.

However, the zones are not arranged in a linear order. To solve the puzzle, you need to rearrange the clues based on their "difficulty" level. The difficulty of each clue is determined by the clue's zone number modulo 5. This means the clue at zone 'a' (position 1) has a difficulty of 1 % 5 = 1, the clue at zone 'b' (position 2) has a difficulty of 2 % 5 = 2, and so on. The clue at zone 'e' (position 5) will have a difficulty of 0, as 5 % 5 = 0.

Once all the clues have been assigned a difficulty level, you need to sort the clues in increasing order of their difficulty. If two clues have the same difficulty level, the clue that appears earlier in the alphabet (i.e., closer to 'a') should be considered as having more difficulty.

Your task is to sort the clues in ascending order of difficulty and print the result.

Input Format
The first line contains an integer N representing the length of the string.

The second line contains a string Str of length N consisting of lowercase Latin alphabets ('a' to 'z').

Output Format
Print the sorted string based on the given conditions.

Constraints
1 <= N <= 10^5

‘a’ <= Str[i] <= ‘z’

Sample Testcase 0
Testcase Input
3
bca
Testcase Output
abc
Explanation
Here we have string str = bca
Difficulty of ‘b’ = 2 % 5 = 2; ’c’ = 3 % 5 = 3; ’a’ = 1 % 5 = 1
Final output will be abc.

Sample Testcase 1
Testcase Input
5
abcde
Testcase Output
eabcd
Explanation
Here we have string str = abcde
Difficulty of ‘a’ = 1 % 5 = 1; ’b’ = 2 % 5 = 2; ’c’ = 3 % 5 = 3; ’d’ = 4 % 5 = 4 and  ‘e’ = 5 % 5 = 0.
Final output will be eabcd.

*/

#include <bits/stdc++.h>
#include <string>
using namespace std;

void user_logic(int n, string &s)
{
    // Write your logic here.
    // Parameters:
    //     n: Length of the string
    //     s: String consisting of lowercase Latin alphabets
    // Returns:
    //     Sorted string based on the given conditions

    map<int, vector<char>> mp;
    for (int i = 0; i < n; i++)
    {
        int diff = (s[i] - 'a' + 1) % 5;
        mp[diff].push_back(s[i]);
    }

    // string ans="";
    int i = 0;
    for (auto it : mp)
    {
        vector<char> v = it.second;
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        for (auto el : v)
            s[i++] = el;
    }
}

int main()
{
    int n;
    string s;

    cin >> n >> s;

    user_logic(n, s);

    // Call user logic function and print the output
    cout << s << endl;

    return 0;
}