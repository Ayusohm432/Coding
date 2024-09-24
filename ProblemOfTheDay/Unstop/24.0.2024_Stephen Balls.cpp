/*
Problem Link ; https://unstop.com/code/practice/262749
*/

/*Stephen Balls

Problem Statement
In a Disney Land, Stephen plays a Big-ball puzzle game. A screen shows the jumbled Strings, Stephen has some balls which contain some patterns of strings inside them.

Stephen has to find out how many patterns are on the screen.

Note:- Letter is in Case Sensitive, so “a” is not equal to “A" and Balls and screen consist only of English letters. 

Input Format
The first line of input contains a String N denoting the Ball string.

The second line of input contains a String str denoting the Screen String.

Output Format
Print a single integer K denoting the matching pattern count.

Constraints
1 <=  Balls.length, screen <=50

Sample Testcase 0
Testcase Input
mM
mmmMaMm
Testcase Output
6
Explanation
If we parse the the Ball String pattern we have “mM” have repeated six times so we have the count of strings is 6

Sample Testcase 1
Testcase Input
qqew
QQWWssdd
Testcase Output
0
Explanation
If we parse the the Ball String pattern we have “qqew” due to case senstive “q” is differs from “Q”  so the count is 0.

*/
#include <iostream>
#include <unordered_set>
using namespace std;

int Stephenballs(string Balls, string PlayScreen) {
    unordered_set<char> mp;
    int total = 0;
    for(int index = 0; index < Balls.size(); index++){
        if(mp.find(Balls[index]) == mp.end()){
            mp.insert(Balls[index]);
        } 
    }
    for(int index = 0; index < PlayScreen.size(); index++){
        if(mp.find(PlayScreen[index]) != mp.end()){
            total++;
        }
    }
    return total;
}


int main(){
    string Balls,PlayScreen;
    cin >> Balls;
    cin >> PlayScreen;
    int count = Stephenballs(Balls, PlayScreen);
    cout << count << endl;
}