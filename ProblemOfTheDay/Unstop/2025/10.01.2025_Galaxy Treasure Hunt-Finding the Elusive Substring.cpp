/*
Problem Link: https://unstop.com/code/practice/499137
*/

/*Galaxy Treasure Hunt: Finding the Elusive Substring

Problem Statement
In a distant galaxy, a young inventor named Leo created a robot called "Trace" to help him find hidden treasures. These treasures were marked on ancient maps stored as long strings of mysterious text. To locate a treasure, Trace needed to find a specific clue called the Key, made up of a unique combination of characters.

The maps were massive and full of random symbols, making Trace’s task difficult. The Key could appear in any part of the map, but its characters might be jumbled. Trace’s job was to find the shortest section(substring) of the map that included all the characters of the Key, no matter the order.  If no such substring exists, Trace should return -1.

Input Format
The first line contains a string S representing the map.

The second line contains a string T representing the Key.

Output Format
Output the length of the shortest substring of s that contains all the characters of t in any order. If no such substring exists, output -1.

Constraints
Each character of S and T is a printable ASCII character.

1 ≤ |S| ≤ |T| ≤ 10^5

Sample Testcase 0
Testcase Input
warrmioruhk
warrior
Testcase Output
8
Explanation
The shortest substring of S that contains all the characters of T is "warrmior", which has length 8.

Sample Testcase 1
Testcase Input
Thunder
King
Testcase Output
-1
Explanation


There is no substring of S that contains all the characters of T.

*/

#include <iostream>
#include <string>
#include <climits>
#include <unordered_map>

using namespace std;

int shortestSubstring(string s, string t)
{
    unordered_map<char, int> constUm, windowUm;
    for (auto ele : t)
        constUm[ele]++;
    int i = 0, j = 0, result = INT_MAX, include = 0, required = constUm.size();
    while (j < s.size())
    {
        windowUm[s[j]]++;
        if (windowUm[s[j]] == constUm[s[j]])
            include++;
        while (include == required && i <= j)
        {
            result = min(result, j - i + 1);
            windowUm[s[i]]--;
            if (windowUm[s[i]] < constUm[s[i]])
                include--;
            i++;
        }
        j++;
    }
    return result == INT_MAX ? -1 : result;
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << shortestSubstring(s, t) << endl;
    return 0;
}