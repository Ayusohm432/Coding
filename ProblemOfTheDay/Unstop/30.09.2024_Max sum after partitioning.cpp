/*
Problem Link : https://unstop.com/code/practice/250747
*/

/*Max sum after partitioning

Problem Statement
You have an integer array of size N. Your task is to split this array into contiguous subarrays, where each subarray can be at most K elements long. After dividing the array, replace every element in each subarray with the largest value from that subarray.

Calculate the maximum possible sum of the array after these transformations. Let this maximum sum be M.

Finally, find and display the count of prime numbers that are less than or equal to M.

Test cases are generated so that the answer fits in a 32-bit integer.

Input Format
The first line contains an integer N, which represents the size of the array.

The second line contains N space-separated integers representing the elements of the array.

The third line contains an integer K, which is the maximum allowed size for each subarray.

Output Format
 Print an integer value representing the count of prime numbers less than or equal to the largest sum of the given array after partitioning.

Constraints
1 <= Arr.length <= 5*10^2

0 <= Arr[i] <= 10^9

1 <= K <= Arr.length

Sample Testcase 0
Testcase Input
1
1
1
Testcase Output
0
Explanation
The array contains only one element, so the maximum sum after partitioning is 1. 
The count of prime numbers less than or equal to 1 is 0, as there are no primes less than or equal to 1.

Sample Testcase 1
Testcase Input
7
1 15 7 9 2 5 10
3
Testcase Output
23
Explanation
Split the array [1, 15, 7, 9, 2, 5, 10] into contiguous subarrays of length up to 3.


Subarray 1: [1, 15, 7] 
After transformation: [15, 15, 15] 


Subarray 2: [2, 5, 10] 
After transformation: [10, 10, 10]


Subarray 3: [9] 
After transformation: [9]


Overall sum = 15+15+15+10+10+10+9 = 84
Number of Primes less than equal to 84  = 23

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int countPrimes(int M) {
    if (M < 2) return 0;
    vector<bool> isPrime(M + 1, true);
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 2; i * i <= M; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= M; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    int primeCount = 0;
    for (int i = 2; i <= M; ++i) {
        if (isPrime[i]) {
            primeCount++;
        }
    }
    return primeCount;
}

int maxSumAfterPartitioning(vector<int>& arr, int N, int K) {
    vector<int> dp(N, 0);

    for (int i = 0; i < N; ++i) {
        int maxElem = 0;
        for (int j = 1; j <= K && i - j + 1 >= 0; ++j) {
            maxElem = max(maxElem, arr[i - j + 1]);
            dp[i] = max(dp[i], (i >= j ? dp[i - j] : 0) + maxElem * j);
        }
    }
    return dp[N - 1];
}

int main() {

    int N, K;
    cin >> N;
    
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    cin >> K;

    int maxSum = maxSumAfterPartitioning(arr, N, K);

    int primeCount = countPrimes(maxSum);

    cout << primeCount << endl;

    return 0;
}
