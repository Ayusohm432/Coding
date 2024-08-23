/*
Problem link :- https://leetcode.com/problems/number-complement/description/?envType=daily-question&envId=2024-08-22
*/

/*476. Number Complement

The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
Given an integer num, return its complement.

 

Example 1:

Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:

Input: num = 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 

Constraints:

1 <= num < 231
 

Note: This question is the same as 1009: https://leetcode.com/problems/complement-of-base-10-integer/

*/

#include<iostream>
#include <cmath>
#include <climits>

using namespace std;

//Approach-1
class Solution {
public:
    int findComplement(int num) {
        int number_of_bits = (int)(log2(num)) + 1;
        
        for(int i = 0; i<number_of_bits; i++) {
            num = num^(1<<i); //Take Xor to flip
        }
        return num;
    }
};


//Approach-2
class Solution {
public:
    int findComplement(int num) {
        int i = 0, ans = 0;
        while (num) {
            // If the current bit is 0, set the corresponding bit in ans to 1
            if (!(num & 1))
                ans |= (1 << i);
            num >>= 1;
            i++;
        }
        return ans;
    }
};




//Appraoch-3
class Solution {
public:
    int findComplement(int num) {
        if (num == 0)
            return 1;

        int number_of_bits = (int)(log2(num)) + 1;

        // Create a mask with all bits set to 1 that are of the same length as num
        unsigned int mask = (1U << number_of_bits) - 1;

        // XOR num with mask to get the complement
        return num ^ mask;
    }
};







//Main Function
int main() {
    Solution solution;
    int num = 5;
    int result = solution.findComplement(num);
    std::cout << "The final answer is " << result << std::endl;
    return 0;
}