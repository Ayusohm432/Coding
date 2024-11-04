/*
Problem Link : https://unstop.com/code/practice/299346
*/

/*Count the number of elements divisible by integer K

Problem Statement
Given an array of positive integers and a positive integer K, find the count of all possible numbers that can be formed using the array elements that are divisible by K. Do not include duplicates.

Input Format
The first line contains an integer K.

The second line contains an integer N, representing the size of the input array.

The third line contains N space-separated integers, representing the elements of the input array.

Output Format
Print the count of all possible numbers that can be formed and are divisible by ( K ).

Constraints
1 <= K <= 10^2

1 <= N <= 8

1 <= Ai <= 10

Sample Testcase 0
Testcase Input
2
3
4 2 3
Testcase Output
10
Explanation
Form all possible element which is divisible by k integer
4 42 432 2 24 234 34 342 32 324
All element divide by k integer
Sample Testcase 1
Testcase Input
3
4
3 1 2 4
Testcase Output
17
Explanation
3 312 321 324 342 132 12 123 231 234 21 213 24 243 432 42 423
All element divide by k integer

*/

#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

void generate_combinations(vector<int>& arr, vector<bool>& visited, string current, set<int>& unique_numbers);

int main() {
    int K, N;
    cin >> K;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    set<int> unique_numbers;
    vector<bool> visited(N, false);

    // Generate all combinations using backtracking
    generate_combinations(arr, visited, "", unique_numbers);

    // Count numbers divisible by K
    int count = 0;
    for (int num : unique_numbers) {
        if (num % K == 0) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}

void generate_combinations(vector<int>& arr, vector<bool>& visited, string current, set<int>& unique_numbers) {
    // User needs to implement the logic here
    if (!current.empty()) {
        unique_numbers.insert(stoi(current));
    }

    // Explore all possibilities
    for (int i = 0; i < arr.size(); ++i) {
        if (!visited[i]) {
            visited[i] = true; // Mark as visited
            generate_combinations(arr, visited, current + to_string(arr[i]), unique_numbers); // Include current element
            visited[i] = false; // Backtrack
        }
    }
}