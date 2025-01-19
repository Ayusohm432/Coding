/*
Problem Link: https://unstop.com/code/practice/306507
*/

/*Jewelry Juggle

Problem Statement
Lena visits a jewelry store where she is shown four pieces of jewelry, each with different weights labeled A, B, C, and D. She is interested in purchasing one or more of these pieces but wants to determine if it's possible to select a combination of pieces whose total weight equals the combined weight of the jewelry she decides not to buy. Your task is to help Lena determine if such a selection is feasible by providing either a "YES" or "NO" answer.

Input Format
The first line contains 4 space seprated integers: Weight of Jewelry (A), Weight of Jewelry(B), Weight of Jewelry(C), Weight of Jewelry(D)

Output Format
If such a combination of jewelry pieces exists, print "YES" Otherwise if no such combination is possible, print "NO".

Constraints
1 <= A, B, C, D <= 10^8

Sample Testcase 0
Testcase Input
10 10 10 100
Testcase Output
NO
Explanation
No combination of pieces selected will satisfy the condition where the weights of selected pieces are equal to the weights of pieces remaining.


So, print “NO”.

Sample Testcase 1
Testcase Input
1 5 8 4
Testcase Output
YES
Explanation
Lena selects jewelry:
A with weight 1
C with weight 8


Remaining jewelry pieces are:
B with weight 5
D with weight 4


Sum of pieces Lena selected = 1+8 =9
Sum of pieces remaining= 5+4 = 9


Thus, such a combination exists where the sum of the pieces Lena has selected is equal to the sum of remaining pieces.


So, print “YES”.
*/

#include <bits/stdc++.h>
using namespace std;

string user_logic(int a, int b, int c, int d) {
    // Write your logic here.
    // Parameters:
    //     a (int): Weight of Jewelry A
    //     b (int): Weight of Jewelry B
    //     c (int): Weight of Jewelry C
    //     d (int): Weight of Jewelry D
    // Returns:
    //     string: "YES" if a valid combination exists, otherwise "NO"
    unordered_map<int, int> um;
    um[1] = a, um[2] = b, um[3] = c, um[4] = d;
    long totalSum = a + b + c + d;
    for(int i = 1; i <= 4; i++){
        int sum = um[i];
        if(sum == (totalSum - sum))
            return "YES";
        for(int j = 1; j <= 4; j++){
            if(j != i){
                sum += um[j];
                if(sum == (totalSum - sum))
                    return "YES";
            }
        }
    }
    return "NO";
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    // Call user logic function and print the output
    string result = user_logic(a, b, c, d);
    cout << result << endl;
    return 0;
}