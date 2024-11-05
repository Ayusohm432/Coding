/*
Problem Link : https://unstop.com/code/practice/301954
*/

/*Different Problem

Problem Statement
Lexi and her friend created a game where her friend selects a random number. Lexi's task is to determine the difference between the maximum and minimum values that can be formed by rearranging the digits of that number.

For example, if the chosen number is 231, Lexi can rearrange the digits to create the minimum value of 123 and the maximum value of 321. The difference between these two values is 198.

Input Format
The first line contains a single integer T, which indicates the number of test cases.

The next T lines each contain a single integer, representing the number chosen by Lexi's friend.

Output Format
For each test case, print a single integer representing the difference between the maximum and minimum possible values.

Constraints
1 ≤ T ≤ 10^2

-10^5 ≤ num ≤ 10^5

Sample Testcase 0
Testcase Input
4
-123
456
-789
789
Testcase Output
198
198
198
198
Explanation
1st testcase: -123
Minimum possible value: -321
Maximum Possible value: -123
Difference(max - min): -123 - (-321) = -123 + 321 = 198


2nd testcase: 456
Minimum possible value: 456
Maximum Possible value: 654
Difference(max - min): 654 - 456 = 198


3rd testcase: -789
Minimum possible value: -987
Maximum Possible value: -789
Difference(max - min): -789 - (-987) = -789 + 987 = 198


4th testcase: 789
Minimum possible value: 789
Maximum Possible value: 987
Difference(max - min): 987 - 789 = 198

Sample Testcase 1
Testcase Input
2
231
-7605
Testcase Output
198
7083
Explanation
In the first test case, 
The minimum possible value is 123 and the maximum possible value is 321. The difference between the maximum and minimum values is 198. 
In the second test case, 
The minimum possible value is -7650 and the maximum possible value is -567. The difference between the maximum and minimum values is 7083.

*/

#include <bits/stdc++.h>

using namespace std;

// User needs to implement this function
int calculate_difference(int num);

int main()
{
    int T;
    cin >> T;
    vector<int> results;
    for (int i = 0; i < T; i++)
    {
        int num;
        cin >> num;
        results.push_back(calculate_difference(num));
    }
    for (int result : results)
    {
        cout << result << endl;
    }
    return 0;
}

int calculate_difference(int num)
{
    bool is_negative = (num < 0);
    string num_str = to_string(abs(num));

    sort(num_str.begin(), num_str.end());

    string min_str = num_str;
    if (is_negative) {
        reverse(min_str.begin(), min_str.end());
        min_str = "-" + min_str; // Add the negative sign
    } else {
        min_str = num_str;
    }

    string max_str = num_str;
    if (is_negative) {
        max_str = "-" + num_str; 
    } else {
        reverse(max_str.begin(), max_str.end());
    }

    int min_value = stoi(min_str);
    int max_value = stoi(max_str);

    int difference = max_value - min_value;
    return difference;
}
