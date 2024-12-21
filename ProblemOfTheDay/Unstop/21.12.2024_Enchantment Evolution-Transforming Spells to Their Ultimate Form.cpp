/*
Problem Link: https://unstop.com/code/practice/485001
*/

/*Enchantment Evolution: Transforming Spells to Their Ultimate Form

Problem Statement
In a mystical realm, a powerful wizard aims to boost the strength of his spells. He seeks guidance from a wise sorcerer, who reveals a special technique: each time the wizard casts an enchantment, he should transform it to its "next strongest form", i.e, next lexicographically greater. This involves slightly modifying the spell each time to make it more potent.

To help the wizard master this technique, the sorcerer sets up a challenge:

Task: The sorcerer provides the wizard with a base spell (a word or incantation) and a specific number.
Challenge: The wizard must practice by transforming the spell through a series of magical upgrades, each one being the next stronger version of the previous spell.
Goal: After the specified number of transformations, the wizard's spell will have reached its ultimate form, ready to be unleashed with amplified power.
This practice helps the wizard understand how to control and scale the strength of his enchantments, preparing him for the most challenging magical feats!

Input Format
The first line contains two space separated integers N and T, the length of the spell and the number of transformations, respectively.

The second line contains a string S of length N, representing the initial spell which consist of lowercase alphabets.

Output Format
Output the spell after performing T transformations. If the spell is already at its most powerful form or it’s not possible to achieve the spell after T transformations, then print "FAIL".

Constraints
1 <= N <= 10^2

0 <= T <= 10^2

Sample Testcase 0
Testcase Input
5 3
abced
Testcase Output
abecd
Explanation
After 1st transformation: "abced" → "abdce"
After 2nd transformation: "abdce" → "abdec"
After 3rd transformation: "abdec" → "abecd"
The spell after 3 transformations is "abecd".

Sample Testcase 1
Testcase Input
3 6
abc
Testcase Output
FAIL
Explanation
After 1st transformation: "abc" → "acb"
After 2nd transformation: "acb" → "bac"
After 3rd transformation: "bac" → "bca"
After 4th transformation: "bca" → "cab"
After 5th transformation: "cab" → "cba"
cba is the lexicographically greatest spell, but we need to continue this tranformation process upto 6th iteration, hence it can't be possibe tranform the spell.

*/


#include <bits/stdc++.h>
#include <string>
using namespace std;

string encodeMessage(string s, int t) {
    // User will write the logic here
}

int main() {
    int n, t;
    string s;
    cin >> n >> t;
    cin >> s;
    string result = encodeMessage(s, t);
    cout << result << "\n";
    return 0;
}

string encodeMessage(string s, int t) {
    int n = s.length();
    for (int i = 0; i < t; i++) {
        bool found = false;
        for (int j = n - 2; j >= 0; j--) {
            if (s[j] < s[j + 1]) {
                found = true;
                int k = n - 1;
                while (s[j] >= s[k]) {
                    k--;
                }
                swap(s[j], s[k]);
                reverse(s.begin() + j + 1, s.end());
                break;
            }
        }
        if (!found) {
            return "FAIL";
        }
    }
    return s;
}