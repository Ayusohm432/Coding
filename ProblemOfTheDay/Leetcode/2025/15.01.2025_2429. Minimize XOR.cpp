/*
Problem Link: https://leetcode.com/problems/minimize-xor/description/?envType=daily-question&envId=2025-01-15
*/

/*2429. Minimize XOR
Given two positive integers num1 and num2, find the positive integer x such that:

x has the same number of set bits as num2, and
The value x XOR num1 is minimal.
Note that XOR is the bitwise XOR operation.

Return the integer x. The test cases are generated such that x is uniquely determined.

The number of set bits of an integer is the number of 1's in its binary representation.

 

Example 1:

Input: num1 = 3, num2 = 5
Output: 3
Explanation:
The binary representations of num1 and num2 are 0011 and 0101, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 3 = 0 is minimal.
Example 2:

Input: num1 = 1, num2 = 12
Output: 3
Explanation:
The binary representations of num1 and num2 are 0001 and 1100, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 1 = 2 is minimal.
 

Constraints:

1 <= num1, num2 <= 109

*/

//Approach - 1

class Solution {
public:
    bool isSet(int &x, int bit) {
        return x & (1 << bit);
    }

    bool setBit(int &x, int bit) {
        return x |= (1 << bit);
    }

    bool unsetBit(int &x, int bit) {
        return x &= ~(1 << bit);
    }

    int minimizeXor(int num1, int num2) {
        int x = num1;

        int requiredSetBitCount = __builtin_popcount(num2);
        int currSetBitCount = __builtin_popcount(x);

        int bit = 0;
        if(currSetBitCount < requiredSetBitCount) {
            while(currSetBitCount < requiredSetBitCount) {
                if(!isSet(x, bit)) {
                    setBit(x, bit);
                    currSetBitCount++;
                }
                bit++;
            }
        } else if(currSetBitCount > requiredSetBitCount) {
            while(currSetBitCount > requiredSetBitCount) {
                if(isSet(x, bit)) {
                    unsetBit(x, bit);
                    currSetBitCount--;
                }
                bit++;
            }
        }

        return x;
    }
};

//Approach - 2

class Solution {
public:
    bool isSet(int &x, int bit) {
        return x & (1 << bit);
    }

    bool setBit(int &x, int bit) {
        return x |= (1 << bit);
    }

    bool unsetBit(int &x, int bit) {
        return x &= ~(1 << bit);
    }

    bool isUnset(int x, int bit) {
        return (x & (1 << bit)) == 0;
    }

    int minimizeXor(int num1, int num2) {
        int x = 0;

        int requiredSetBitCount = __builtin_popcount(num2);

        for(int bit = 31; bit >= 0 && requiredSetBitCount > 0; bit--) {
            if(isSet(num1, bit)) {
                setBit(x, bit); 
                requiredSetBitCount--;
            }
        }

        for(int bit = 0; bit < 32 && requiredSetBitCount > 0; bit++) {
            if(isUnset(num1, bit)) {
                setBit(x, bit);
                requiredSetBitCount--;
            }
        }

        return x;
        
    }
};