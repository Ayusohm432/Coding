/*
Problem Link : https://unstop.com/code/practice/250647
*/

/*Decode the message

Problem Statement
Ram and Shyam are two friends belonging to two different cities. They exchange messages weekly. The messages are very crucial so that no third person can see the message.

But they sent a message via Jadav, a clever person. He usually reads the given messages. So, Ram and Shyam started talking in codewords. They set a convention for every letter in the English Alphabet.

Like ‘a’ to ‘i’ code is 1 to 9 and ‘j’ to  ‘z’ code is 10# to 26#.

Now suppose, Ram is sending a message to Shyam denoted by String S.

Can you tell me the decoded message that Shyam receives? 

Input Format
The first line of input contains the string S.

Output Format
Return the string which denotes the decoded message that Shyam receives

Constraints
1<=s.length<=10^6

Sample Testcase 0
Testcase Input
26#21#13#13#114#97820#
Testcase Output
zummanight
Explanation
Decoding the string:



26# - z

21# - u

13# - m

13# - m

1 - a

14# - n

9 - i

7 - g

8 -h

20# -t


The final string we get: zummanight

Sample Testcase 1
Testcase Input
16#122#912#915#14#
Testcase Output
pavilion
Explanation
The decoded message:



16# - p

1 -a

22# -v

9 - i

12# -l

9 -i

15# -o

14# -n


The decoded string will be: pavilion

*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    string res = "";
    int i = 0;
    while (i < s.length()) {
        if (s[i] == '1' && i + 2 < s.length() && s[i + 2] == '#') {
            int num = (s[i + 1] - '0') + 10;
            res += (char)('a' + num - 1);
            i += 3;
        } else if (s[i] == '2' && i + 2 < s.length() && s[i + 2] == '#') {
            int num = (s[i + 1] - '0') + 20;
            res += (char)('a' + num - 1);
            i += 3;
        } else {
            res += (char)('a' + (s[i] - '0') - 1);
            i++;
        }
    }
    cout << res << endl;
    return 0;
}