/*
Problem Link: https://unstop.com/code/practice/250586
*/

/*Making Xors

Problem Statement
Ramu the amazing guy has been provided with a problem. He has been given a sequence of numbers in which he has to take the xor of all the subsets of the sequence and sum them up.

Your task is to help Ramu in doing that.

Input Format
The first line contains an integer n.

The second line contains n space-seprated integers denoting the array.

Output Format
Output a single integer describing the sum of xors.

Constraints
1<=n<=100

1<=num[i]<=20

Sample Testcase 0
Testcase Input
3
5 1 6
Testcase Output
28
Explanation
The following are the eight subsets of [5,1,6]: - The empty subset has an XOR total of 0. - [5] has a total XOR of 5. - [1] has a total XOR of 1. - [6] has a total XOR of 6. - The XOR total of [5,1] is 5 XOR 1 = 4. - The XOR total of [5,6] is 5 XOR 6 = 3. - The XOR total of [1,6] is 1 XOR 6 = 7. - The XOR total of [5,1,6] is 5 XOR 1 XOR 6 = 2.


Total XOR = 0 + 5 + 1 + 6 + 4 + 3 + 7 + 2 = 28

Sample Testcase 1
Testcase Input
2
1 3
Testcase Output
6
Explanation
The following are the four subsets of [1,3]: - The empty subset has an XOR total of 0. - [1] has a total XOR of 1. - [3] has a total XOR of 3. -  [1,3] has a total XOR of = 2.


Total XOR = 0 + 1 + 3 + 2 = 6

*/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define ll long long int

int subset_xor_sum(const std::vector<int> &arr)
{
    /* Write your logic here */
    // return 0;  // Placeholder return
    ll n = arr.size();
    ll sum = 0, xr = 0;
    for (int i = 0; i < 31; ++i)
    {
        xr = 0;
        for (auto pr : arr)
        {
            if (pr & (1 << i))
                xr++;
        }
        sum += (1 << i) * (1 << (xr - 1)) * (1 << (n - xr));
    }
    return sum;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }
    int result = subset_xor_sum(arr);
    std::cout << result << std::endl;
    return 0;
}

