/*
Problem Link: https://unstop.com/code/practice/303801
*/

/*Reverse Vowels Code

Problem Statement
You are provided with a string S made up of lowercase characters. Your task is to reverse the positions of all the vowels in the string while keeping the other characters in their original places. After reversing the vowels, you need to count how many times the substring "code" appears in the modified string.

Input Format
The input consists of a single line containing the string S.

Output Format
Return the number of occurrences of string “code” in the reversed vowel string of S.

Constraints
1 ≤ |S| ≤ 10^5

Sample Testcase 0
Testcase Input
cocodeinecodecodecode
Testcase Output
2
Explanation
The vowel reversed a string of "cocodeinecodecodecode" will be “cecodeonecodecidecodo.”
The number of occurrences of “code” in “cecodeonecodecidecodo” is 2.
Sample Testcase 1
Testcase Input
tecodezcodewhcodembcodi
Testcase Output
4
Explanation

Original String: "tecodezcodewhcodembcodi"

Reverse Vowels: "ticodemcodewhcodembcodoe"

Count "code" occurrences: There are four occurrences of the substring "code" in the reversed string: "ticodemcodewhcodembcodoe"

First occurrence: "ticodemcode" (starting from index 2)

Second occurrence: "codemcode" (starting from index 8)

Third occurrence: "mcode" (starting from index 17)

Fourth occurrence: "codoe" (starting from index 22)




Therefore, the output of the program is 4, as it correctly counts the occurrences of the substring "code" in the reversed string.

*/

#include <iostream>
#include <string>

int user_logic(const std::string &s) {
    std::string vowels = "aeiou";
    int left = 0, right = s.length() - 1;
    std::string str = s;
    while (left < right) {
        if (vowels.find(str[left]) == std::string::npos) {
            left++;
        } else if (vowels.find(str[right]) == std::string::npos) {
            right--;
        } else {
            std::swap(str[left], str[right]);
            left++;
            right--;
        }
    }
    int count = 0;
    for (int i = 0; i <= str.length() - 4; i++) {
        if (str.substr(i, 4) == "code") {
            count++;
        }
    }
    return count;
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    
    // Call user logic function and print the output
    int result = user_logic(s);
    std::cout << result << std::endl;
    return 0;
}


