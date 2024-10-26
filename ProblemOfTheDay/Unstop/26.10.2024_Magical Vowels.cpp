/*
Problem Link : https://unstop.com/code/practice/302646
*/

/*Magical Vowels

Problem Statement
Given a string S of size N. If exactly two consecutive vowels are present in the given string, then add a character ‘$’ after those two vowels, However, if there are more than two consecutive vowels, do not add $ after the sequence.

You can perform the above operation any number of times. 

Return the modified string after performing the above operation.

Note

Two consecutive vowels don't need to be the same; the condition is that two consecutive characters should be vowels only. 
String S contains only small letters from ‘a’ to ‘z’.
Input Format
The first line contains an integer N.

The second line contains S - the string.

Output Format
The output should return the modified string after performing the mentioned operation.

Constraints
1 <= N <= 10^6.

Sample Testcase 0
Testcase Input
10
aabbeedpee
Testcase Output
aa$bbee$dpee$
Explanation
The characters at index 1(‘a’) and index 2(‘a’) are vowels hence add a ‘$’ after index 2.
The characters at index 5(‘e’) and index 6(‘e’) are vowels hence add a ‘$’ after index 6. 
The characters at index 9(‘e’) and index 10(‘e’) are vowels hence add a ‘$’ after index 0.
Sample Testcase 1
Testcase Input
12 
abaedeefaeop
Testcase Output
abae$dee$faeop
Explanation
Given string is abaedeefaeop. The characters at index 2(‘a’) and index 3(‘e’) are vowels hence add a ‘$’ after index 3. The characters at index 5(‘e’) and index 6(‘e’) are vowels hence add a ‘$’ after index 6.


The characters at indices 8,9 and 10 are vowels, but there are three consecutive vowels, so we do not operate.


So, the modified string will be abae$dee$faeop Hence, the result will be abae$dee$faeop.

*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <set>
using namespace std;

string magicalVowels(string str , set<char>& st){
    string result;
    int n = str.length();
    int i=0;
    while(i<n){
        int j=i;
        while(j<n && st.find(str[j]) != st.end()){
            result += str[j];
            j++;
        }
        if(j-i == 2){
            result += "$";
        }
        if(j == i){
            result += str[j];
            i++;
        }
        else{
            i = j;
        }
    }
    return result;
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    
    char str[n+1];
    cin>>setw(n+1)>>str;

    set<char> st = {'a' , 'e' , 'i' , 'o' , 'u'};

    string result = magicalVowels(str , st);

    cout<<result;
    return 0;
}