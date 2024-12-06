/*
Problem Link: https://unstop.com/code/practice/302976
*/

/*Sum variation

Problem Statement
You are provided with an array of integers of size N. Within this array, your task is to identify the smallest positive integer that is not present. Once you've found this integer, determine its ASCII value and add this value to the total sum of the array.
Finally, return the final sum.

Input Format
An array nums of size N is given as input.

Output Format
Return the sum obtained.

Constraints
1 <= N <= 5 * 10^5
-10^6 <= nums[i] <= 10^6 – 1

Sample Testcase 0
Testcase Input
3
3 1 0
Testcase Output
54
Explanation
Ascii value of 2 is 50 and sum = 50+3+1+0=54
Sample Testcase 1
Testcase Input
4
2 4 3 5
Testcase Output
63
Explanation
Ascii value of 1=49
Sum=63

*/

#include <bits/stdc++.h>
using namespace std;

int smallestMissingPositive(vector<int> &nums, int n)
{
    unordered_set<int> m;
    for (auto x : nums)
    {
        m.insert(x);
    }
    int res = 1;
    for (auto x : m)
    {
        if (m.find(res) == m.end())
        {
            return res;
        }
        else
            ++res;
    }

    return res;
}

int main()
{
    // your code goes here
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    int sum = '0' + smallestMissingPositive(nums, n);
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }
    cout << sum;
    return 0;
}