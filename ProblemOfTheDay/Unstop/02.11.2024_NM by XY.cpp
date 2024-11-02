/*
Problem Link : https://unstop.com/code/practice/296708
*/

/*NM by XY

Problem Statement
Alice is given two integers, X and Y. Bob created a term called "NM by XY" with specific conditions. Bob says that X and Y are "NM by XY" if the following conditions are met:

N = X - M
Y = N ^ M, where "^" represents the bitwise exclusive OR (XOR) operation.
N should be as small as possible.
Bob asks Alice to find the values of N and M that make X and Y "NM by XY" numbers. If no solution exists, return -1.

Input Format
The first and only line contains two space-separated integers representing X and Y.

Output Format
Print the values of N and M that satisfy the conditions. If no such values exist, print -1.

Constraints
0 ≤  X, Y ≤ 10^9

Sample Testcase 0
Testcase Input
142 76
Testcase Output
33 109
Explanation
In this case:


N = X - M = 142 - 109 = 33
Y = N ^ M = 33 ^ 109 = 76

33 is the smallest value of N, which satisfies the given condition.

Sample Testcase 1
Testcase Input
10 20
Testcase Output
-1
Explanation
There are no values of N and M that satisfy the conditions for X = 10 and Y = 20, so the output is -1.

*/
#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
vector<long long int>NMbyXY(ll x,ll y)
{
  vector<long long int>vec;
  if((x-y)%2 != 0 || x<y)
  {
   vec.push_back(-1);
  }
    else
    {
      vec.push_back((x-y)/2);
      vec.push_back( x- (x-y)/2);
    }
    return vec;
}
int main() 
{
    ll x, y;
    cin >> x >> y;
  vector<long long int>vec = NMbyXY(x,y);
  for(auto &i:vec)
    cout<<i<<" ";
    cout<<endl;
}