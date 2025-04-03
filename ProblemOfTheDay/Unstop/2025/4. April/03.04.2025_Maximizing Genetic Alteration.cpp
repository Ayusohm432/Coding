/*
Problem Link: https://unstop.com/code/practice/510842
*/

/*Maximizing Genetic Alteration

Problem Statement
In a futuristic world, humans have discovered a method to alter their genetic structure using nanotechnology. This technology allows individuals to enhance their physical abilities, but with each enhancement, there is a trade-off. The "Genetic Alteration" is represented by a number, which corresponds to the total number of genetic modifications an individual has undergone.

The process of enhancing one's genetic structure is governed by a series of operations that can be performed on the initial genetic value. Specifically, the value of the "Genetic Alteration" can be reduced by dividing it by 2, 3, or 4 in each operation. This process can be repeated as many times as needed.

Once the alterations reach a certain level, the individual can choose to finalize their enhancements and "unlock" a new level of physical ability, represented by a final value of the genetic alteration.

The goal is to maximize the physical ability enhancement level by performing the available operations and then finalizing the genetic alteration.

Task:

Given an initial genetic alteration value N, find out the maximum possible physical ability enhancement level that can be achieved through this process.

Input Format
The input consists of a single integer N, representing the initial genetic alteration value.

Output Format
Print the maximum possible enhancement level achievable by performing the available operations.

Constraints
1 <= N <= 10^6

Sample Testcase 0
Testcase Input
6
Testcase Output
6
Explanation
We compare two possibilities:


Keeping 6 as is.
Splitting 6 into 6/2, 6/3, and 6/4 (i.e., 3, 2, and 1).
We find the enhancements for those parts (3, 2, 1) individually:
Enhancement(3) = 3
Enhancement(2) = 2
Enhancement(1) = 1
Their total is 3 + 2 + 1 = 6.


Compare 6 with 6. They are equal, so the maximum is still 6.

Sample Testcase 1
Testcase Input
12
Testcase Output
13
Explanation
We compare two possibilities:
Keeping 12 as is.
Splitting 12 into 12/2, 12/3, and 12/4 (i.e., 6, 4, and 3).
We find the enhancements for those parts (6, 4, 3) individually:
Enhancement(6) = 6
Enhancement(4) = 4
Enhancement(3) = 3
Their total is 6 + 4 + 3 = 13.
Compare 13 with 12. The higher value is 13.

*/

#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<int, int> dp;
// Placeholder function where the user will write the logic
int Maximum(int N) {
    // Write your logic here.
    // Parameters:
    //   N (int): Initial genetic alteration value
    // Returns:
    //   int: Maximum possible enhancement level achievable
    // Placeholder return
    if(N == 0){
        return 0;
    }

    if(dp.count(N)){
        return dp[N];
    }

    int n1 = Maximum(N/2);
    int n2 = Maximum(N/3);
    int n3 = Maximum(N/4);

    return dp[N] = max(N, (n1+n2+n3));
}

int main() {
    int N;
    cin >> N;
    
    // Call the user logic function and print the output
    int result = Maximum(N);
    cout << result << "\n";
    
    return 0;
}