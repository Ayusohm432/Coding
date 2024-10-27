/*
Problem Link : https://unstop.com/code/practice/305357
*/

/*Convert prime number in string array into alphabet

Problem Statement
You have been given a string array, Where every element in the string array represents an integer which could be anything in the range of (0 to 25) number

Convert every prime number in the string array into corresponding alphabets which follow the pattern:

0 → ‘A’
1 → ‘B’
2 → ‘C’
3 → ‘D’
And so on...
E.g: If you are given the array [12’ ‘5’ ‘8’ ‘24’ ‘13’ ‘2’]

       Display [‘12’ ‘F’ ‘8’ ‘24’ ‘N’ ‘C’]

Input Format
The first line contains an integer N, representing size of the array,

The second line contains N space-separated strings denoting the numbers of string array Ai.

Output Format
Convert every prime number in the string array into alphabets and display the modified array elements in a single line separated by spaces.

Constraints
1 <= N <= 2*10^3

0 <= Ai <= 25

Space complexity O(1)

Time complexity O(N)

Sample Testcase 0
Testcase Input
7
23 5 12 7 13 6 8
Testcase Output
X F 12 H N 6 8
Explanation
Convert every prime number in the string array into a character


Like 23 → X, 5 --> F, 7 --> H, 13 --> N

Sample Testcase 1
Testcase Input
7
12 5 8 24 13 2 23
Testcase Output
12 F 8 24 N C X
Explanation
Convert every prime number in the string array into a character


Like 5 → F, 13 --> N, 2 --> C, 23 --> X

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPrime(int n){
    if(n <= 1){
        return 0;
    }

    if(n == 2 || n == 3){
        return 1;
    }

    if(n%2 == 0 || n%3 == 0){
        return 0;
    }

    for(int i=5; i*i <= n; i=i+6){
        if(n%i == 0 || n%(i+2) == 0){
            return 0;
        }
    }

    return 1;
}

vector<string> convertPrimeToAlphabet(vector<string>& arr , int n){
    for(int i=0; i<n; i++){
        int curr = stoi(arr[i]);
        if(isPrime(curr)){
            arr[i] = string(1 , char(curr + 'A'));
        }
    }
    return arr;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;

    vector<string> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    convertPrimeToAlphabet(arr , n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}