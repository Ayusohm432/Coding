/*
Problem link : https://leetcode.com/problems/find-the-closest-palindrome/description/?envType=daily-question&envId=2024-08-24
*/

/*564. Find the Closest Palindrome

Given a string n representing an integer, return the closest integer (not including itself), which is a palindrome. If there is a tie, return the smaller one.

The closest is defined as the absolute difference minimized between two integers.

 

Example 1:

Input: n = "123"
Output: "121"
Example 2:

Input: n = "1"
Output: "0"
Explanation: 0 and 2 are the closest palindromes but we return the smallest which is 0.
 

Constraints:

1 <= n.length <= 18
n consists of only digits.
n does not have leading zeros.
n is representing an integer in the range [1, 1018 - 1].

*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
    long func(long firstHalf , bool isEven){
        long resultNum = firstHalf;

        if(isEven == false){
            firstHalf /= 10;
        }

        while(firstHalf > 0){
            int digit = firstHalf % 10;
            resultNum = (resultNum * 10) + digit;
            firstHalf /= 10;
        }
        return resultNum;
    }
public:
    string nearestPalindromic(string n) {
        int l = n.length();

        int mid = l/2;

        long firstHalfLength = (l % 2 == 0) ? mid : mid + 1;

        long firstHalf =stol(n.substr(0 , firstHalfLength));

        vector<long> possibleResults;

        possibleResults.push_back(func(firstHalf , l%2 == 0 ));
        possibleResults.push_back(func(firstHalf + 1 , l%2 == 0));
        possibleResults.push_back(func(firstHalf - 1 , l%2 == 0));
        possibleResults.push_back((long)pow(10 , l-1) - 1);
        possibleResults.push_back((long)pow(10 , l) + 1);

        long diff = LONG_MAX;
        long result = INT_MAX;
        long originalNum = stol(n);

        for(long num : possibleResults){
            if( num == originalNum){
                continue;
            }
            if(abs(num - originalNum) < diff){
                diff = abs(num - originalNum);
                result = num;
            }
            else if(abs(num - originalNum) == diff){
                result = min(result , num);
            }
        }
        return to_string(result); 
    }
};

int main(){
    Solution solution;
    cout << solution.nearestPalindromic("123") << endl;
    return 0;
}