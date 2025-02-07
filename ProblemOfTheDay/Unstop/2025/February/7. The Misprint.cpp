/*
Problem Link: https://unstop.com/code/practice/300733
*/

/*The Misprint

Problem Statement
One morning, a printing press in SnoopCity encountered a problem. An article celebrating a girl's bravery mistakenly printed the name "Nancy" instead of "Sanvi."

To fix this, you need to replace every instance of "nancy" with "sanvi" in the given sentences.

The printing press uses a unique format where sentences are concatenated into a single word without spaces, such as "hernameisnancy" instead of "her name is nancy."

Note-The string consists of only lowercase words without any spaces.

Input Format
The first line of the input contains a single integer T denoting the number of test cases.

Each of the next T lines contains a single word representing a sentence without spaces.

Output Format
For each test case, output the corrected word with nancy replaced by Sanvi. If  Nancy is not found, print  -1.

Constraints
1<=T<=10^3

1<=Length of String<=10^3


Sample Testcase 0
Testcase Input
2
hernameisnancy
nancyisverybrave
Testcase Output
hernameissanvi
sanviisverybrave
Explanation
The name nancy is replaced by sanvi in every test case.
Sample Testcase 1
Testcase Input
3
nancysavedherbrother
nancyonlyhadwoodenstick
nancyattackedthekidnapperrs
Testcase Output
sanvisavedherbrother
sanvionlyhadwoodenstick
sanviattackedthekidnapperrs
Explanation
The name nancy is replaced by sanvi in every test case.

*/

#include <iostream>
#include <vector>
#include <string>

std::string user_logic(const std::string& word) {
    // Write your logic here.
    // Parameters:
    //     word (std::string): A single word representing a sentence without spaces
    // Returns:
    //     std::string: Corrected word with 'nancy' replaced by 'Sanvi', or '-1' if 'nancy' is not found
     // If "nancy" is not found, return "-1"
    if(word.find("nancy") == std::string::npos) {
        return "-1";
    }
    
    std::string res = word;
    size_t pos = 0;
    
    while((pos = res.find("nancy", pos)) != std::string::npos) {
        res.replace(pos, 5, "sanvi");
        pos += 5;  
    }
    
    return res;
}

int main() {
    int T;
    std::cin >> T;
    
    std::vector<std::string> testCases(T);
    for (int i = 0; i < T; ++i) {
        std::cin >> testCases[i];
    }
    
    for (const auto& word : testCases) {
        std::string result = user_logic(word);
        std::cout << result << std::endl;
    }
    
    return 0;
}