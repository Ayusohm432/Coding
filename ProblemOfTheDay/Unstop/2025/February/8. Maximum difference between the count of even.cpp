/*
Problem Link: https://unstop.com/code/practice/305649
*/

/*Maximum difference between the count of even

Problem Statement
Given a vector V of positive integers of size N.

The task is to find the maximum difference of the number of even numbers and the number of odd numbers (number of even – number of odd) in all the possible subarray of the vector.

Note: In the case of all odds, the answer will be -1.

Input Format
The first line contains the size of the vector, denoted by N.

The second line contains N space-separated integers denoting the elements of the vector.

Output Format
Returns the maximum difference between the number of even numbers and the number of odd numbers (number of even – number of odd) in all the possible subarray of the vector.

Constraints
1 <= N <= 10^5
0 <= V[i] <= 10^10

Sample Testcase 0
Testcase Input
3
1 1 1
Testcase Output
-1
Explanation
No even number is present.

Sample Testcase 1
Testcase Input
5
1 2 3 4 5
Testcase Output
1
Explanation
There are 3 subarrays which give a maximum difference of 1.


(No. Of even - No. Of odd)


(2) -> 1-0=1


(2,3,4)-> 2-1=1


(4)->1-0=1

*/

#include <iostream>
#include <vector>
using namespace std;
int max_difference(const std::vector<int> &v)
{
    /* Write your logic here. */
    int even = 0;
    for (auto ele : v)
    {
        if (ele % 2 == 0)
            even++;
    }
    if (even == 0)
        return -1;
    even = 0;
    int result = 1, n = v.size(), odd = 0, i = 0, j = 0;
    while (j < n)
    {
        if (v[j] % 2 == 0)
            even++;
        else
            odd++;
        while (i < j && odd >= even)
        {
            if (v[i] % 2 == 0)
                even--;
            else
                odd--;
            i++;
        }
        j++;
        result = max(result, even - odd);
    }
    return result;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> V(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> V[i];
    }
    int result = max_difference(V);
    std::cout << result << std::endl;
    return 0;
}