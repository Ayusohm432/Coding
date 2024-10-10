/*
Problem Link : https://unstop.com/code/practice/259978
*/

/*Mod in a Range

Problem Statement
In a game, you have two queens that need to be placed on two different mats. Each mat has a unique order number between two given integers L and R. The objective is to place the queens on the mats such that when the order number of one mat is divided by the order number of the other mat, the remainder (result of the modulo operation) is maximized.

Given the range [L,R], your task is to find the two order numbers of the mats that maximize this modulo value and print the result.

The solution should have O(1) time complexity.

Input Format
The first line contains one positive integer T , denoting the number of test cases.

For each test case, a single line contains two integers, L and T, representing the range of possible order numbers.

Output Format
For each test case, print the maximum possible value of the remainder obtained by performing the modulo operation between the two order numbers.

Constraints
1 <= T <= 104

1 <= L <= R <= 109

Sample Testcase 0
Testcase Input
2
5 10
7 15
Testcase Output
4
7
Explanation
Test Case 1:
In the range from 5 to 10, the pair (9, 5) yields the maximum remainder. 9 % 5 = 4, so the output is 4.


Test Case 2:
In the range from 7 to 15, the pair (15, 8) gives the maximum remainder. 15 % 8 = 7, so the output is 7.

Sample Testcase 1
Testcase Input
3
1 1
2 12
4 9
Testcase Output
0
5
4
Explanation
Test Case 1:
The only available number is 1, so the division of 1 by itself yields a remainder of 0. Since there is no other number to compare, the result is 0.


Test Case 2:
In the range from 2 to 12, the pair (11, 6) maximizes the remainder when 11 is divided by 6. The remainder is 11 % 6 = 5, which is the largest possible remainder within this range.


Test Case 3:
In the range from 4 to 9, the pair (9, 5) provides the maximum remainder when 9 is divided by 5. The remainder is 9 % 5 = 4, which is the highest possible remainder in this range.

*/
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        long long L, R;
        cin >> L >> R;
        
        if (2 * L > R) {
            cout << R - L << endl;
        } else {
            cout << R % (R / 2 + 1) << endl;
        }
    }
    
    return 0;
}
