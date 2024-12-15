/*
Problem link: https://unstop.com/code/practice/307827
*/

/*Number of Group Form Problem

Problem Statement
You have been given a String ‘num’ Array. every string in the num Array is an anagram of every other string with the same length.
Check strings A and B are equal if we can swap Four letters (in different positions) of A so that it equals B. Also, two strings A and B are equal if they are equal.

For example, "store" and "rotse" are similar (if we swapping at positions 0 and 3 and 1 and 2), and "ortse" and "stroe" are similar, but "tesro" is not similar to "rotse", "ortse" , "stroe".

If we connected this above form two groups {"rotse", "ortse" , "stroe"} and {"tesro"}.  Notice that "rotse" and "stroe" are in the same group despite not being similar.  Means a Single Group form even if at least one word equal to any word of that group

Note:- Single Word contains only one single Alphabetic Character

Return the number of groups form.

Input Format
The first Line contains the Stirng Array size Represented by `N` Integer
Second line contains the string array. 

Output Format
Return the number of groups formed.

Constraints
0 <= num.length <= 2*10^2
1 <= num[i].length <=10^2

Sample Testcase 0
Testcase Input
2
carbon noacbr
Testcase Output
2
Explanation
group can form between carbon and noacbr

Sample Testcase 1
Testcase Input
4
rotse ortse stroe tesro
Testcase Output
2
Explanation
group can form between rotse ortse stroe and tesro

*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

void dfs(const string& s, const vector<string>& strs, unordered_set<string>& vis);
bool isSimilar(const string& a, const string& b);
int getAnagramGroups(const vector<string>& strs);

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int groups = getAnagramGroups(arr);
    cout << groups << endl;
    
    return 0;
}

int getAnagramGroups(const vector<string>& strs) {
    int count = 0;
    unordered_set<string> vis;
    
    for (const string& s : strs) {
        if (vis.find(s) == vis.end()) {
            dfs(s, strs, vis);
            count++;
        }
    }
    
    return count;
}

void dfs(const string& s, const vector<string>& strs, unordered_set<string>& vis) {
    if (vis.find(s) != vis.end()) {
        return;
    }

    vis.insert(s);
    
    for (const string& str : strs) {
        if (isSimilar(s, str)) {
            dfs(str, strs, vis);
        }
    }
}

bool isSimilar(const string& a, const string& b) {
    int c = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) {
            c++;
        }
        if (c > 4) {
            return false;
        }
    }
    
    return c == 4 || c == 0;
}