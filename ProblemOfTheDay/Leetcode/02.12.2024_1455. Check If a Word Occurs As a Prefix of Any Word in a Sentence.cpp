/*
Problelm Link: https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence?envType=daily-question&envId=2024-12-02
*/

/*1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence

Given a sentence that consists of some words separated by a single space, and a searchWord, check if searchWord is a prefix of any word in sentence.

Return the index of the word in sentence (1-indexed) where searchWord is a prefix of this word. If searchWord is a prefix of more than one word, return the index of the first word (minimum index). If there is no such word return -1.

A prefix of a string s is any leading contiguous substring of s.

 

Example 1:

Input: sentence = "i love eating burger", searchWord = "burg"
Output: 4
Explanation: "burg" is prefix of "burger" which is the 4th word in the sentence.
Example 2:

Input: sentence = "this problem is an easy problem", searchWord = "pro"
Output: 2
Explanation: "pro" is prefix of "problem" which is the 2nd and the 6th word in the sentence, but we return 2 as it's the minimal index.
Example 3:

Input: sentence = "i am tired", searchWord = "you"
Output: -1
Explanation: "you" is not a prefix of any word in the sentence.
 

Constraints:

1 <= sentence.length <= 100
1 <= searchWord.length <= 10
sentence consists of lowercase English letters and spaces.
searchWord consists of lowercase English letters.

*/

//Approach-1
class Solution {
public:
    bool match(string s, string searchWord){
        for(int i=0; i<searchWord.size(); i++){
            if(i < s.size() && s[i] == searchWord[i]){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
    int isPrefixOfWord(string sentence, string searchWord) {
        sentence.push_back(' ');
        string curr = "";
        int count = 1;
        for(auto& ch : sentence){
            if(ch != ' '){
                curr += ch;
            }
            else{
                if(match(curr, searchWord)){
                    return count;
                }
                count++;
                curr = "";
            }
        }
        return -1;
    }
};

//Approach-2
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int index = 1;

        while(ss >> word){
            if(word.find(searchWord) == 0){
                return index;
            }
            index++;
        } 

        return -1;
    }
};

//Appraoch-3
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int index = 1;

        while(ss >> word){
            if(word.substr(0, searchWord.size()) == searchWord){
                return index;
            }
            index++;
        }

        return -1;
    }
};

//Approach-4

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string pattern = "\\b" + searchWord;
        regex re(pattern);
        stringstream ss(sentence);
        string word;
        int index = 1;

        while(ss >> word){
            if(regex_search(word, re)){
                return index;
            }
            index++;
        }
        return -1;
    }
};

//Appraoch-5
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int index = 1;
        string curr = "";

        for(char ch : sentence){
            if(ch == ' '){
                if(curr.substr(0, searchWord.size()) == searchWord){
                    return index;
                }
                curr = "";
                index++;
            }
            else{
                curr += ch;
            }
        }

        if(curr.substr(0, searchWord.size()) == searchWord){
            return index;
        }

        return -1;
    }
};