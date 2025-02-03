/*
Problem Link: https://unstop.com/code/practice/295752
*/

/*Pole Arrangement

Problem Statement
Bob has an array Arr of N integers representing the heights of poles arranged in a straight line. He wants to use exactly three poles to make a tent. The conditions for selecting these three poles are:

The middle pole must be the tallest among the three.
The first pole must be the shortest among the three.
The last pole must be taller than the first pole but shorter than the middle pole.
However, Alice, who is jealous of Bob, has secretly reduced the height of all the tallest poles by X units. If the tallest pole was originally of height h, its new height will be max(0, h - X).

Your task is to determine if it is still possible for Bob to select three poles that meet the conditions to make a tent after Alice's tampering.

Input Format
The first line of input contains two space seperated integers N (the number of poles) and X (the number of units by which the tallest poles are reduced).

The second line of input contains N space seperated integers representing the heights of the poles.
Output Format
Display 1 if it is possible to choose three poles to make the tent, otherwise, print 0.
Constraints
3 <= N, X <= 10^6
1 <= Arr[i] <= 2*10^6
Sample Testcase 0
Testcase Input
4 3
2 3 1 4
Testcase Output
0
Explanation
The poles have heights 2, 3, 1, and 4. After reducing the tallest pole (height 4) by x = 3, its new height is 1. The modified heights are 2, 3, 1, and 1. It is impossible to find three poles where the middle one is the tallest, the first is the shortest, and the last is in between the other two. Therefore, the output is 0.

Sample Testcase 1
Testcase Input
3 0
1 3 2
Testcase Output
1
Explanation
The three poles have heights 1, 3, and 2. The middle pole (height 3) is the tallest, the first pole (height 1) is the shortest, and the last pole (height 2) is taller than the first but shorter than the middle. Since no reduction was applied (x = 0), the tent can be made, so the output is 1.

*/

#include <iostream>
#include <vector>
using namespace std;
#include<bits/stdc++.h>
void change_longest(std::vector<int>& arr, int x) {
    // User should implement this function
    int maxi=0, idx=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>maxi){
            maxi=arr[i];
            idx=i;
        }
    }
    arr[idx]=max(0, arr[idx]-x);
}

bool pole_arrangement(const std::vector<int>& arr) {
    // User should implement this function
    for(int i=0;i<arr.size();i++){
        int first = arr[i];
        int middle = arr[i+1];
        int last = arr[i+2];
        if(first<middle && first<last && middle>last)   return true;
    }
    return false; // Placeholder return value
}

int main() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    
    // Modify the array by reducing the tallest poles by x units
    change_longest(arr, x);
    
    // Determine if it is possible to choose three poles to make the tent
    bool result = pole_arrangement(arr);
    
    // Print the result as 1 for True and 0 for False
    std::cout << (result ? 1 : 0) << std::endl;
    
    return 0;
}