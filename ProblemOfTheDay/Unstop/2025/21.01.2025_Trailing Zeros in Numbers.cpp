/*
Problem Link: https://unstop.com/code/practice/519585
*/

/*Trailing Zeros in Numbers

Problem Statement
Tech, a data scientist at Factorial Labs, was tasked with a challenging project by a high-profile client. The client needed an analysis of trailing zeros in factorials, but with a twist: the analysis had to focus only on numbers in a dataset that were less than or equal to a specific threshold, M.

To accomplish this, Tech and his team first filtered the numbers in the dataset, selecting only those that met the condition. Then, they calculated the number of trailing zeros in the factorials of these selected numbers. The trailing zeros were crucial for understanding the structure of their data, and the client needed a precise total to finalize their report.

Tech, known for his problem-solving skills, was confident in his approach. With a systematic method to calculate trailing zeros and a clear focus on efficiency, he was ready to deliver a solution that would impress the client and meet their expectations.

Input Format
The first line contains two space separated integers, N, representing the number of elements in the array and M, representing the upper limit.

The second line contains N space-separated integers, representing the numbers in the array.

Output Format
Print the sum of the trailing zeros in the factorials of the numbers in the array that are less than or equal to M.

Constraints
1 <= N, M <= 10^6

1 <= arr[i] <= 10^7

Sample Testcase 0
Testcase Input
3 4
4 2 3
Testcase Output
0
Explanation
Calculate the factorial of the numbers:
4! = 24
2! = 2
3! = 6
There is no trailing zeroes.

Sample Testcase 1
Testcase Input
8 15
1 2 3 4 5 6 10 15
Testcase Output
7
Explanation
Calculate the factorial of the numbers
1! = 1
2! = 2
3! = 6
4! = 24
5! = 120 (1 trailing zero)
6! = 720 (1 trailing zero)
10! = 3628800 (2 trailing zeroes)
15! = 1307674368000 (3 trailing zeroes)
Sum of trailing zeroes = 7.

*/

#include <iostream>
#include <vector>
using namespace std;

// Function to count trailing zeros in the factorial of numbers in the array
// that are less than or equal to M
int countTrailingZerosInFactorials(int N, int M, const vector<int>& numbers) {
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        if (numbers[i] <= M) {
            int num = numbers[i];
            while (num > 0) {
                num /= 5;
                sum += num;
            }
        }
    }
    return sum;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> numbers(N);
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }
    
    // Call the user logic function and print the output
    int result = countTrailingZerosInFactorials(N, M, numbers);
    cout << result << endl;
    
    return 0;
}

