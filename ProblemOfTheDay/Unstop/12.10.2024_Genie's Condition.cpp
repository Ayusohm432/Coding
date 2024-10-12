/*
Problem Link : https://unstop.com/code/practice/259982
*/

/*Genie's Condition

Problem Statement
In a game, there are two queens that need to be placed on N boxes. Each box has a number written on it, and these numbers are arranged in ascending order. The objective is to place the two queens on two different boxes such that the greatest common divisor (GCD) of the numbers on those boxes is the maximum possible.

Your task is to help Genie find this maximum GCD that can be obtained by placing the queens on the optimal pair of boxes.

Input Format
The first line contains an integer N, representing the number of boxes.

The second line contains N space-separated integers, where each integer represents the number written on a box.

Output Format
Print a single integer representing the maximum GCD that can be obtained by placing the queens on the two optimal boxes.

Constraints
2 <= N <= 2*105

1 <= A[i] <= 106

Sample Testcase 0
Testcase Input
6
12 6 3 1 8 9
Testcase Output
6
Explanation
The possible pairs of numbers are (12, 6), (12, 3), (12, 1), (12, 8), (12, 9), (6, 3), (6, 1), (6, 8), (6, 9), (3, 1), (3, 8), (3, 9), (1, 8), (1, 9), (8, 9).
Among these, the pair (12, 6) has the greatest common divisor of 6, which is the highest possible GCD for any pair in the list.
Therefore, the output is 6.

Sample Testcase 1
Testcase Input
5
1 2 3 4 8
Testcase Output
4
Explanation
The possible pairs of numbers are: (1, 2), (1, 3), (1, 4), (1, 8), (2, 3), (2, 4), (2, 8), (3, 4), (3, 8), (4, 8).
Among these pairs, the pair (4, 8) has the greatest common divisor of 4, which is the highest possible GCD for any pair in the list.
Therefore, the output is 4.

*/

#include <iostream>
#include <vector>
using namespace std;

// Function to compute the maximum GCD
int findMaxGCD(const vector<int>& arr, int N) {
    // Create a frequency array to count how many numbers are divisible by each possible GCD value
    vector<int> freq(1000001, 0);
    
    // Count the frequency of each number
    for (int num : arr) {
        freq[num]++;
    }
    
    // Traverse from the largest possible GCD down to 1
    for (int g = 1000000; g >= 1; --g) {
        int count = 0;
        
        // Count how many numbers are divisible by g
        for (int multiple = g; multiple <= 1000000; multiple += g) {
            count += freq[multiple];
        }
        
        // If two or more numbers are divisible by g, return g as the answer
        if (count >= 2) {
            return g;
        }
    }
    
    return 1; // In case no valid GCD is found (which is unlikely given the constraints)
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    
    // Input the array of numbers
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    // Output the maximum GCD
    cout << findMaxGCD(arr, N) << endl;
    
    return 0;
}
