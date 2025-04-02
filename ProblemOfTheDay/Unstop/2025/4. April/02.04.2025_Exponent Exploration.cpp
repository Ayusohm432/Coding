/*
Problem Link: https://unstop.com/code/practice/510776
*/

/*Exponent Exploration

Problem Statement
A group of explorers stumbles upon an ancient code that could lead them to hidden treasure. The code consists of a number N, and they must figure out all possible pairs of numbers X and Y such that X raised to the power of Y equals N. Help the explorers solve this puzzle by finding all such pairs where X^Y = N, and uncover the treasure's secret!

Input Format
The first and only line of input contains a single integer N.

Output Format
Print the count of valid pairs on the first line.

Then, print each pair of X and Y (in ascending order of X) on a new line.

Constraints
1 <= N <= 10^6

Sample Testcase 0
Testcase Input
16
Testcase Output
3
2 4
4 2
16 1
Explanation
For N=16
16 can be rtepresented as; 2^4 ; 4^2 ; 16^1

Sample Testcase 1
Testcase Input
23
Testcase Output
1
23 1
Explanation
23 can only be represented as 23^1.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

std::vector<std::pair<int, int>> x_power_y_pairs(int n) {
    // Write your logic here.
    // Return a vector of pairs [X, Y] where X^Y equals n
    vector<pair<int, int>> result;

    for(int y=1; y<=log2(n); y++){
        int x = round(pow(n, 1.0/y));

        if(x > 0 && round(pow(x, y)) == n){
            result.push_back({x, y});
        }
    }

    sort(result.begin(), result.end());

    return result;
}

int main() {
    int n;
    std::cin >> n;
    
    // Call the user logic function
    std::vector<std::pair<int, int>> pairs = x_power_y_pairs(n);
    
    // Output the count of valid pairs
    std::cout << pairs.size() << std::endl;
    
    // Output each pair
    for (const auto& pair : pairs) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
    
    return 0;
}