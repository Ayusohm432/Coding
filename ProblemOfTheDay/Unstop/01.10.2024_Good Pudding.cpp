/*
Problem link : https://unstop.com/code/practice/250749
*/

/*Good Pudding

Problem Statement
Bob is visiting Japan and stumbles upon a pudding shop that offers a fun challenge. The shop assigns integer values to their puddings, and Bob needs to identify which puddings are "good."

A pudding is considered "good" if, when its number is reversed twice, it remains the same. For instance, reversing the number 42100 results in 00124, and reversing this again gives 421, which is not the original number, so 42100 is not a good pudding.

Bob's task is to determine whether each pudding is good or not and mark them accordingly.

Input Format
The first line contains an integer N, the number of puddings.

The next N lines each contain a single integer representing the number assigned to each pudding.

Output Format
Print N lines containing a boolean number – “1” for Good pudding and “0” for Bad pudding. 

Constraints
1 <= N <= 106

Sample Testcase 0
Testcase Input
3
1010
2123
9004
Testcase Output
0
1
1
Explanation
The Reverse of N (1010) is (101) and second reversal is (101) which is not same as original number which means  it is not a good pudding.


The Reverse of N (2123) is (3212) and second reversal is (2123) which is the same as original number which means  it is a good pudding.


The Reverse of N (9004) is (4009) and second reversal is (9004) which is not same as original number which means  it is not a good pudding.

Sample Testcase 1
Testcase Input
1
2300
Testcase Output
0
Explanation
The Reverse of N (2300) is (0032) but we cant take leading zero so the number is 32) which is not same as original number which means it is a bad pudding.

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public: 

    string trim(string num) {
        int i = 0;
        while(i < num.length() && num[i] == '0'){
            i++;
        }
        return num.substr(i);
    }

    vector<bool> goodPudding(vector<string> puddings) {
        vector<bool> result;
        for(string pudding : puddings) {
            string firstReverse = pudding;
            reverse(firstReverse.begin() , firstReverse.end());
            string str = trim(firstReverse);
            string secondReverse = str;
            reverse(secondReverse.begin() , secondReverse.end());
            if (pudding == secondReverse) {
                result.push_back(true); 
            } else {
                result.push_back(false); 
            }
        }
        return result;
    } 
};

int main() {
    int n;
    cin >> n;

    vector<string> puddings(n);
    for(int i = 0; i < n; i++) {
        cin >> puddings[i];
    }

    Solution s;

    vector<bool> result = s.goodPudding(puddings);

    for(int i = 0; i < n; i++) {
        cout << (result[i] ? 1 : 0) << endl;
    }

    return 0;
}
