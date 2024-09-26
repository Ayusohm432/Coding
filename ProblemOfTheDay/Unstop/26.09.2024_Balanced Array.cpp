/*
Problem Link : https://unstop.com/code/practice/294499
*/

/*Balanced Array

Problem Statement
You are given an array arr of size n, where n is even. Your task is to determine if the array is Balanced or not. 

Note: An array is called Balanced if for every element x, an element -x in the array and vice versa.

Input Format
The first line contains a single integer n.

The second line contains n space-separated integers denoting the array arr.

 

Output Format
Print ‘1’ if the array is balanced, print ‘0’ otherwise.

Constraints
1 <= n <= 100000

-1000 <= arr[i] <= 1000

Sample Testcase 0
Testcase Input
2
-2 2

Testcase Output
1

Explanation
For element 2, there exists -2 in the array. So the answer is 1.
Sample Testcase 1
Testcase Input
4
-2 1 -1 -2

Testcase Output
0

Explanation
For element 1, there exists -1 in the array. But for -2, there is no 2 in the array. Hence the answer is 0.

*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution{
    public:
        bool isbalancedArray(vector<int>& arr){
            int n = arr.size();

            unordered_map<int, int> freq;

            for(int i=0 ; i<n ; i++){
                freq[arr[i]]++;
            }

            for(auto itr = freq.begin() ; itr != freq.end() ; itr++){
                if(freq.find(-itr->first) == freq.end() || freq[-itr->first] != itr->second){
                    return false;
                }
            }
            return true;
        }
};


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }

    Solution solution;
    bool result = solution.isbalancedArray(arr);

    cout<< result?1:0;

    return 0;
}