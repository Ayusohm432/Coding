/*
Problem Link: https://unstop.com/code/practice/518760
*/

/*Counting Magical Plant IDs

Problem Statement
Queen Althea owns a magical garden where each plant is labeled with an ID from 1 to N. The queen is curious to discover how many plants in her garden have "magical" IDs to mark them for a special ceremony.

An ID is considered "magical" if it satisfies both of the following conditions:

The ID has exactly five distinct factors (divisors).
The ID must be perfect square.
Your task is to count the number of plants with "magical" IDs in the garden.

Input Format
The input contains a single integer N, representing the highest plant ID in the garden.

Output Format
Print the total number of plants with "magical" IDs on the first line.

On the second line, print all the magical IDs, each separated by a space.

Constraints
2 <= N <= 10^11

Sample Testcase 0
Testcase Input
50
Testcase Output
1
16
Explanation
Let's consider N = 50. The numbers that have exactly 5 divisors are:
16 (Divisors: 1, 2, 4, 8, 16)


Now, let's check if the number is perfect square:
16 → 4^2
Thus, the magical ID is 16.

Sample Testcase 1
Testcase Input
100
Testcase Output
2
16 81
Explanation
Let's consider N = 100. The numbers that have exactly 5 divisors are:
16 (Divisors: 1, 2, 4, 8, 16)
81 (Divisors: 1, 3, 9, 27, 81)


Now, let's check if the number is perfect square:
16 → 4^2
81 → 9^2
Thus, the magical ID is 16 and 81.

*/

#include <iostream>
#include <vector>

std::pair<int, std::vector<int>> find_magical_ids(int N);

int main() {
    int N;
    std::cin >> N;
    
    auto result = find_magical_ids(N);
    std::cout << result.first << std::endl;
    for (int id : result.second) {
        std::cout << id << " ";
    }
    std::cout << std::endl;
    
    return 0;
}

std::pair<int, std::vector<int>> find_magical_ids(int N) {
    int count = 0;
    std::vector<int> magical_ids;

    for (int i = 1; i * i <= N; i++) {
        int square = i * i;
        int factors = 0;

        for (int j = 1; j * j <= square; j++) {
            if (square % j == 0) {
                if (j * j == square) {
                    factors++;
                } else {
                    factors += 2;
                }
            }
        }

        if (factors == 5) {
            count++;
            magical_ids.push_back(square);
        }
    }

    return {count, magical_ids};
}


