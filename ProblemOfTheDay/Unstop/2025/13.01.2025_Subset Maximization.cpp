/*
Problem Link: https://unstop.com/code/practice/296904
*/

/*Subset Maximization

Problem Statement
You are given an array A consisting of N non-negative numbers.

You need to group the array elements into subsets such that each element belongs to a single subset and every subset contains either consecutive odd elements or consecutive even elements.

Since there are multiple ways of grouping the elements, you need to maximize the size of the smallest subset formed.

Input Format
The first line contains an integer N

The second line contains N space-separated integers denoting the array A.

Output Format
Print a single integer, the maximum size of the smallest subset formed as described in the problem statement.

Constraints
1 <= N <= 10^5.

1 <= A[i] <= 10^6.

Sample Testcase 0
Testcase Input
4
2 6 4 8
Testcase Output
4
Explanation
We can group all the elements of the array in a single group, i.e., [2, 4, 6, 8].
Sample Testcase 1
Testcase Input
5
6 2 4 6 8
Testcase Output
2
Explanation
There are multiple ways to group the array elements.
For example:
[2, 4, 6, 8]  and [6]. In this case, the minimum size of the subset is 1.
But since we want to maximize the minimum subset size, we can group the array elements as [2, 4, 6] [6, 8]. Here the minimum subset size is 2, which is the maximum possible size among all other possibilities.

*/

#include <bits/stdc++.h>
using namespace std;

int maximizeSubsetSize(vector<int> &nums, int size)
{
    sort(nums.begin(), nums.end());

    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> subsetMap;

    for (int i = 0; i < size; ++i)
    {
        int prevValue = nums[i] - 2;
        int currentSubsetSize = 0;

        if (subsetMap.count(prevValue) && !subsetMap[prevValue].empty())
        {
            currentSubsetSize = subsetMap[prevValue].top();
            subsetMap[prevValue].pop();
        }

        currentSubsetSize++;
        subsetMap[nums[i]].push(currentSubsetSize);
    }

    int minimumSize = size;
    for (const auto &entry : subsetMap)
    {
        if (!entry.second.empty())
        {
            minimumSize = min(minimumSize, entry.second.top());
        }
    }

    return minimumSize;
}

int main()
{
    int size;
    cin >> size;
    vector<int> nums(size);

    // Input the array elements
    for (int i = 0; i < size; ++i)
    {
        cin >> nums[i];
    }

    // Call the function and display the result
    int result = maximizeSubsetSize(nums, size);
    cout << result << endl;

    return 0;
}
