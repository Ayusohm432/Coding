/*
Problem Link : https://unstop.com/code/practice/250742
*/

/*Password Check

Problem Statement
You are given a password of length N in the form of an array. You have to check if the password is valid or not.

A valid password is a password in which the occurrence of each element is unique (Refer to sample I/O).

Print true if the password is valid, otherwise print false.

Input Format
The first line of input contains an integer N representing the length of the password array.

The second line contains N space separated numbers each denoting the value at an index.

Output Format
Print true or false depending upon the password's validity.

Constraints
1 <= N <= 10^5

0 <= password[i] <= 10^4

Sample Testcase 0
Testcase Input
3
1 2 3
Testcase Output
false
Explanation
1, 2, and 3 have occurred 1 time each. So the number of occurrences is the same for three numbers, because of which the password becomes invalid.

Sample Testcase 1
Testcase Input
6
1 2 2 1 1 3
Testcase Output
true
Explanation
The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.


So, it is a valid password. 

*/

#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> frequencyMap;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        frequencyMap[num]++;
    }

    set<int> frequencySet;
    for (auto& pair : frequencyMap) {
        frequencySet.insert(pair.second);
    }

    if(frequencySet.size() == frequencyMap.size()){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}