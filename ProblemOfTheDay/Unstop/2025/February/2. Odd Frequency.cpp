/*
Problem link; https://unstop.com/code/practice/295750
*/

/*Odd Frequency

Problem Statement
You are given a string consisting of lowercase English letters. Your task is to determine if there are at least three characters in the string that appear an odd number of times. If there are, print 1,otherwise, print 0.

Note: str contains lowercase English alphabets.

Input Format
The first line of input contains a single string of lowercase English letters.

Output Format
Display 1 if at least three characters in the string have odd frequencies,otherwise, display 0 if fewer than three characters have odd frequencies.

Constraints
3 <= str.length <= 10^6

 

Sample Testcase 0
Testcase Input
abcc
Testcase Output
0
Explanation
In the string "abcc", the characters 'a' and 'b' each appear once (which is odd), but 'c' appears twice (which is even). Since there are fewer than three characters with odd frequencies, the output is 0.

Sample Testcase 1
Testcase Input
abc
Testcase Output
1
Explanation
In the string "abc", the characters 'a', 'b', and 'c' each appear once (which is odd). Since there are three characters with odd frequencies, the output is 1.

*/

#include <iostream>
#include <string>
#include <map>

int check_odd_frequency(const std::string& s) {
    // Write your logic here.
    // Parameters:
    //     s (std::string): Input string of lowercase English letters
    // Returns:
    //     int: 1 if at least three characters have odd frequencies, otherwise 0
    map<char, int> mp;

    for(char ch : s){
        mp[ch]++;
    }

    int count = 0;

    for(const auto& pair : mp){
        if(pair.second % 2 != 0){
            count++;
        }
    }
    if(count >= 3){
        return 1;
    }
    return 0;
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    int result = check_odd_frequency(s);
    std::cout << result << std::endl;
    return 0;
}

