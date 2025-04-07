/*
Problem Link: https://unstop.com/code/practice/293638
*/

/*Array Reduction

Problem Statement
You are given an integer array arr of length N. Your task is to reduce the array size, and you can perform only one operation. In one operation, you can select any two elements, Arr[i] and Arr[j] (i ≠ j), from the array such that the absolute difference between the two elements is at least K and remove these two elements from the array.

Your task is to calculate the maximum number of above-described operations you can perform.

Input Format
The first line of input contains two space-separated integers, N (the number of elements in the array) and K (the minimum absolute difference required between two elements to perform an operation).

The second line of input contains N space-separated integers representing the array Arr.

Output Format
Display a single integer, representing the maximum number of operations you can perform, where each operation involves removing two elements from the array if their absolute difference is at least K.

Constraints
1<=N, K<=10^6

1<=Arr[i] <=10^6

Sample Testcase 0
Testcase Input
6 4
6 5 4 3 2 1
Testcase Output
2
Explanation
Considering 0-based indexing, there are only two pairs of elements that have an absolute difference of 4 or more between them which we can remove one by one: (1, 5) and (2, 6), corresponding to the indices (0, 4) and (1, 5).
Operation 1: arr: [ 1, 2, 3, 4, 5, 6 ] -> [ _, 2, 3, 4, _, 6 ] 
Operation 2: arr: [ _, 2, 3, 4, _, 6] -> : [ _, _, 3, 4, _ , _ ]

After performing these two operations, you cannot remove any pair of elements from the array since the absolute difference between any pair of elements left will be less than K(=4). Hence the answer is 2.
Sample Testcase 1
Testcase Input
4 1
1 1 1 1
Testcase Output
0
Explanation
There are no pairs of elements in the array such that the absolute difference between them is at least 1. Hence we cannot perform any operation on the array. Therefore the answer is 0.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int get_max_operations(int N, int K, std::vector<int>& arr) {
    /*
    Write your logic here.
    Parameters:
        N (int): Number of elements in the array
        K (int): Minimum absolute difference required between two elements
        arr (list): List of integers representing the array
    Returns:
        int: Maximum number of operations you can perform
    */
    sort(arr.begin(), arr.end());

    int i = 0;
    int j = N/2;
    int operations = 0;

    vector<bool> reference(N, false);

    while (i < N / 2 && j < N) {
        if (!reference[i] && !reference[j] && arr[j] - arr[i] >= K) {
            reference[i] = true;
            reference[j] = true;
            operations++;
            i++;
            j++;
        } else {
            j++;
        }
    }
    return operations;
}

int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }
    int result = get_max_operations(N, K, arr);
    std::cout << result << std::endl;
    return 0;
}