/*
Problem Link: https://unstop.com/code/practice/294132
*/

/*New Shelf


Problem Statement
Luke has a long bookshelf filled with n books numbered from 1 to n, and the ith book has the height ai. He recently bought a new shelf to keep some of his books since the first one was almost full. To add books to his new shelf, he walks across the first bookshelf from left to right, i.e., starting from book 1 towards book n. For each book on the shelf, he can do one of the following operations:

Leave the book as it is and move on to the next one.
Take the book out and place it on the new shelf at the leftmost available space.
To make his new shelf look good, he wants the books on the new shelf to be in a strictly increasing order of height from left to right. In other words, if the new shelf has m books numbered from 1 (leftmost) to m (rightmost), then for any i > 1, the height of the ith book should be strictly greater than the height of the i-1th Book. Help him find out the maximum number of books that he can place on his new shelf.

Print the modulo multiplicative inverse of the maximum number of books that he can place on his new shelf with 10^6+7.

Input Format
The first line of the input contains a single integer n representing the number of books.
The second line of the input contains n space-separated integers denoting the height of the books.
Output Format
Print a single integer, the modulo multiplicative inverse of the maximum number of books that he can place on his new shelf with 10^6+7.

Constraints
1 <= n <= 10^4
Sample Testcase 0
Testcase Input
8
10  9  2  5  3  7  101  18
Testcase Output
250002
Explanation
Some of the ways to pick out the maximum number of books are [2, 5, 7, 18], [2,5, 7, 101], and [2, 3, 7, 18]. We can see that the maximum number of books placed on the new shelf is 4. 

Its modulo multiplicative inverse with 10^6+7 is 250002.

Sample Testcase 1
Testcase Input
6
9 9 9 9 9 9
Testcase Output
1
Explanation
We can pick only one of the books because we need them in a strictly increasing order of height. So, the maximum number of books placed on the new shelf is 1.

Its modulo multiplicative inverse with 10^6+7 is 1.


*/

#include <bits/stdc++.h>
using namespace std;
int modInverse(int A, int M)
{
    int m0 = M;
    int y = 0, x = 1;

    if (M == 1)
        return 0;
    while (A > 1) {

        int q = A / M;
        int t = M;
        M = A % M, A = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];
 
    vector<int> dp(n); 
 
    for(int i = 0; i < n; i++){
        dp[i] = 1;
 

        for(int j = 0; j < i; j++){
            if(nums[j] >= nums[i]) continue;
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++)
         res = max(res, dp[i]);
     cout << modInverse(res,1e6+7) << endl;
     return 0;
}