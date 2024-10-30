/*
Problem Link : https://unstop.com/code/practice/305915
*/

/*Pair of Subarrays

Problem Statement
You are given array A of size N. You need to find all ordered pairs of subarrays whose sum are equal, more formally, if one subarray is there from
L1 to R1 (1 ≤ L1 ≤ R1 ≤ N) & another subarray L2 to R2 (1 ≤ L2 ≤ R2 ≤ N) then the sum of the subarray from L1 to R1 is equal to the sum of the subarray from L2 to R2, and since ordered pairs are considered such a pair of {[L1, R1], [L2, R2]} and pair of {[L2, R2], [L1, R1]} are same hence should be considered only once. 

Additionally, there couldn’t be any common index between two subarrays, i.e., for all i such that  L1  ≤  i  ≤  R1 and for all j such that  L2  ≤  j  ≤  R3  it must hold that
i != j.

Note: The indices in this problem start from 1, not 0.

Input Format
The first line of input contains an integer N, representing the array size.

The second line of input contain N space-separated integers,representing the elements of array A.

Output Format
Display a single integer representing the required number of pairs.

Constraints
1 ≤ N ≤ 10^6

-10^6 ≤ A[i] ≤ 10^6

Sample Testcase 0
Testcase Input
4
1 -1 2 -2
Testcase Output
2
Explanation
The array is [1, -1, 2, -2].
There are two pairs of subarrays with equal sums that do not overlap:
Subarray from index 1 to 2: [1, -1] with sum 1 - 1 = 0
Subarray from index 3 to 4: [2, -2] with sum 2 - 2 = 0
Subarray from index 1 to 1: [1] with sum 1
Subarray from index 2 to 3: [-1, 2] with sum -1 + 2 = 1
Therefore, the output is 2.

Sample Testcase 1
Testcase Input
3
1 2 3
Testcase Output
1
Explanation
The array is [1, 2, 3].
There is only one pair of subarrays with equal sums that do not overlap:
Subarray from index 1 to 2: [1, 2] with sum 1 + 2 = 3
Subarray from index 3 to 3: [3] with sum 3
Therefore, the output is 1.

*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    unordered_map<int, vector<pair<int, int>>> sum_map;

    // Calculate all subarray sums
    for (int start = 0; start < N; ++start) {
        int current_sum = 0;
        for (int end = start; end < N; ++end) {
            current_sum += A[end];
            sum_map[current_sum].emplace_back(start + 1, end + 1); // Store 1-based indices
        }
    }

    int count = 0;

    // Count valid pairs
    for (const auto& entry : sum_map) {
        const auto& subarrays = entry.second;
        int size = subarrays.size();
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                // Check if they overlap
                if (subarrays[i].second < subarrays[j].first || subarrays[j].second < subarrays[i].first) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}