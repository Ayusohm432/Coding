/*
Problem Link: https://unstop.com/code/practice/495580
*/

/*Arjun's Fibonacci Treasure Hunt

Problem Statement
In a quiet village, a boy named Arjun found an old diary hidden in his grandmother’s trunk. The diary was filled with random letters and numbers, and a note inside read:

"Hidden within this diary are Fibonacci numbers—unlock their secrets to discover something extraordinary."

Arjun had heard of Fibonacci numbers before. They were a special sequence where each number was the sum of the two before it, starting from 0 and  1. Excited by the challenge, he decided to find these numbers.

His task was clear:

Search the diary and count how many Fibonacci numbers were hidden within.
Write down all the Fibonacci numbers he found.
Finally, list the first K Fibonacci numbers starting from 0, where K is the total count of numbers he found in the diary.
If there were no Fibonacci numbers, Arjun would close the diary and look elsewhere for his adventure.

With a curious mind and a pencil in hand, Arjun began his search. Would he uncover the Fibonacci sequence hidden in the diary, or was it just an old book with random scribbles?

Input Format
The first line of input contains a string ‘S’ consisting of lowercase English letters and digits(1-9).

Output Format
If Fibonacci numbers are present in the string:

Print the count of Fibonacci numbers.
Print the identified Fibonacci numbers found in the string.
Print the first k Fibonacci numbers starting from 0 where K is the count of Fibonacci numbers found in the string.
If no Fibonacci numbers are found, print 0.

Constraints
1 <= length(S) <= 10^2

Sample Testcase 0
Testcase Input
a1b13c2d8e21
Testcase Output
5
1 13 2 8 21
0 1 1 2 3
Explanation
Extracted Numbers from string: [1, 13, 2, 8, 21]
Fibonacci Series: 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, . . . 


Identified Fibonacci Numbers: [1, 13, 2, 8, 21]
Count Fibonacci Numbers: 5
First 8 Fibonacci numbers: 0, 1, 1, 2, 3.

Sample Testcase 1
Testcase Input
a1b34cd2f7ghi1ch2v34
Testcase Output
6
1 34 2 1 2 34
0 1 1 2 3 5
Explanation
Extracted Numbers from string: [1, 34, 2, 7, 1, 2, 34]
Fibonacci Series: 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, . . . 


Identified Fibonacci Numbers: [1, 34, 2, 1, 2, 34]
Count Fibonacci Numbers: 6
First 3 Fibonacci numbers: 0, 1, 1, 2, 3, 5.

*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

// Function to check if a number is a perfect square
bool isPerfectSquare(long long n) {
    long long sqrtN = static_cast<long long>(sqrt(n));
    return (sqrtN * sqrtN == n);
}

// Function to check if a number is a Fibonacci number
bool isFibonacci(int num) {
    // A number is Fibonacci if one of the following is a perfect square:
    // 5*num^2 + 4 or 5*num^2 - 4
    long long x = 5 * num * num + 4;
    long long y = 5 * num * num - 4;
    return isPerfectSquare(x) || isPerfectSquare(y);
}

// Function to find all the Fibonacci numbers in the string
vector<int> findFibonacciNumbers(const string &s) {
    vector<int> fibonacciNumbers;
    string temp = "";

    // Extract all numbers from the string
    for (char ch : s) {
        if (isdigit(ch)) {
            temp += ch;
        } else {
            if (!temp.empty()) {
                int num = stoi(temp);
                if (isFibonacci(num)) {
                    fibonacciNumbers.push_back(num);
                }
                temp = "";
            }
        }
    }

    // Check if the last part is a number
    if (!temp.empty()) {
        int num = stoi(temp);
        if (isFibonacci(num)) {
            fibonacciNumbers.push_back(num);
        }
    }

    return fibonacciNumbers;
}

// Function to generate the first N Fibonacci numbers
vector<int> generateFibonacciSequence(int n) {
    vector<int> fib = {0, 1};
    while (fib.size() < n) {
        int nextFib = fib[fib.size() - 1] + fib[fib.size() - 2];
        fib.push_back(nextFib);
    }
    return vector<int>(fib.begin(), fib.begin() + n);
}

int main() {
    // Input string
    string s;
    getline(cin, s);

    // Find Fibonacci numbers in the string
    vector<int> fibonacciNumbers = findFibonacciNumbers(s);

    if (!fibonacciNumbers.empty()) {
        // Print the count of Fibonacci numbers
        cout << fibonacciNumbers.size() << endl;

        // Print the identified Fibonacci numbers
        for (int num : fibonacciNumbers) {
            cout << num << " ";
        }
        cout << endl;

        // Print the first K Fibonacci numbers where K is the count of Fibonacci numbers found
        vector<int> fibSequence = generateFibonacciSequence(fibonacciNumbers.size());
        for (int num : fibSequence) {
            cout << num << " ";
        }
        cout << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}