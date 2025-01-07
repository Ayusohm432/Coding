/*
Problem link: https://unstop.com/code/practice/292350
*/

/*Peculiar number

Problem Statement
Alice and Bob are playing a new game where Alice has given an array arr of size N to Bob and a division factor K. Alice asked Bob to find the peculiar number from that array.

Following are the steps to find the peculiar number: 

Replace the ith element of the array with the absolute difference between ith element and the ith index.
Partition the array such that the number of partitions would be equal to the division factor, and the maximum sum achieved from these partitions must be as minimum as possible.
Assume if the obtained sum from the above step is x such that it is less than 100, then return that xth Fibonacci number. Else return x itself.
Print this peculiar number.

Note : Here , Fibonacci Sequence's 0-th  number is 0 and 1st number in 1.

Input Format
The first line contains two space-separated integers: N and K.
The second line contains N space-separated integers denoting the array arr.
Output Format
Print the peculiar number.

Constraints
1 <= N <= 10^5
1 <= arr[i] <= 10^5
1<=K<=N
for all i from 0 to n-1 , arr[i] >= i
Sample Testcase 0
Testcase Input
3 2
10 11 12
Testcase Output
6765
Explanation
The replaced array after the 1st step will be {10,10,10}. There would be two partitions {10, 10} and {10} with the sum 20 and 10, respectively. 20 is smaller than 100, so the 20th Fibonacci number will be 6765.  Hence 6765 will be the peculiar number as per the given condition.
Sample Testcase 1
Testcase Input
4 2
5 8 6 10
Testcase Output
144
Explanation




Replace each element in the array with the absolute difference between the element and its index, resulting in [5, 7, 4, 7].

Partition the array into 2 parts, minimizing the maximum sum, which gives a maximum sum of 12.

Since 12 is less than 100, the 12th Fibonacci number 144 is returned as the peculiar number.

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> 
using namespace std;

int fibonacci(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
bool canPartition(const vector<int>& arr, int k, int mid) {
    int currentSum = 0, partitions = 1;
    for (int num : arr) {
        if (currentSum + num > mid) {
            ++partitions;
            currentSum = num;
            if (partitions > k) return false;
        } else {
            currentSum += num;
        }
    }
    return true;
}

int peculiarNumber(int n, int k, vector<int>& arr) {

    for (int i = 0; i < n; ++i) {
        arr[i] = abs(arr[i] - i);
    }

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPartition(arr, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (result < 100) {
        return fibonacci(result);
    }
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Call user logic function and print the output
    int result = peculiarNumber(n, k, arr);
    cout << result << endl;

    return 0;
}