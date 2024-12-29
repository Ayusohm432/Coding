/*
Problem Link: https://unstop.com/code/practice/260638
*/

/*The Hint

Problem Statement
There is a passcode for a computer. The user wants to set a hint for the passcode. The passcode is a string. The user finds out the parts of the string that is not empty and is made up of a single alphabet. 
He sets the hint as this part of the passcode string which is longest among all other parts that satisifies the same condition.
Print the length of the hint given the passcode string.

Input Format
A single line containing the passcode string.

Output Format
Print a single integer, which is the length of the longest part of the passcode that contains only one unique character.

Constraints
1 <= str.length() <= 105 

Sample Testcase 0
Testcase Input
abbcccddddeeeeedcba
Testcase Output
5
Explanation
The substring "eeeee" is the longest substring with the length 5 having the character 'e' only.

Sample Testcase 1
Testcase Input
aab
Testcase Output
2
Explanation
The substring “aa” is of length 2 with the character ‘a’ only.

*/
#include <iostream>
#include <string>

int longest_consecutive_character(const std::string &s) {
    // Write your logic here.
    // Parameters:
    //     s (const std::string&): The passcode string
    int max_length = 0;
    int current_length = 1;
    char current_char = s[0];

    for (int i = 1; i < s.length(); i++) {
        if (s[i] == current_char) {
            current_length++;
        } else {
            max_length = std::max(max_length, current_length);
            current_length = 1;
            current_char = s[i];
        }
    }
    // Returns:
    //     int: The length of the longest part of the passcode that contains only one unique character
    return std::max(max_length, current_length);
}

int main() {
    std::string s;
    std::getline(std::cin, s); // Reading the single line passcode string

    // Call user logic function and print the output
    int result = longest_consecutive_character(s);
    std::cout << result << std::endl;
    return 0;
}

