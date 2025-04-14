/*
Problem Link: https://www.geeksforgeeks.org/problems/alien-dictionary/1
*/

/*Alien Dictionary

A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.

Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.

However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.

Note: Your implementation will be tested using a driver code. It will print true if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print false.

Examples:

Input: words[] = ["baa", "abcd", "abca", "cab", "cad"]
Output: true
Explanation: A possible corrct order of letters in the alien dictionary is "bdac".
The pair "baa" and "abcd" suggests 'b' appears before 'a' in the alien dictionary.
The pair "abcd" and "abca" suggests 'd' appears before 'a' in the alien dictionary.
The pair "abca" and "cab" suggests 'a' appears before 'c' in the alien dictionary.
The pair "cab" and "cad" suggests 'b' appears before 'd' in the alien dictionary.
So, 'b' → 'd' → 'a' → 'c' is a valid ordering.
Input: words[] = ["caa", "aaa", "aab"]
Output: true
Explanation: A possible corrct order of letters in the alien dictionary is "cab".
The pair "caa" and "aaa" suggests 'c' appears before 'a'.
The pair "aaa" and "aab" suggests 'a' appear before 'b' in the alien dictionary.
So, 'c' → 'a' → 'b' is a valid ordering.
Input: words[] = ["ab", "cd", "ef", "ad"]
Output: ""
Explanation: No valid ordering of letters is possible.
The pair "ab" and "ef" suggests "a" appears before "e".
The pair "ef" and "ad" suggests "e" appears before "a", which contradicts the ordering rules.
Constraints:
1 ≤ words.length ≤ 500
1 ≤ words[i].length ≤ 100
words[i] consists only of lowercase English letters.

*/

class Solution {
    public:
        string findOrder(vector<string> &words) {
            unordered_map<char, int> inDegree;
            unordered_map<char, unordered_set<char>> graph;
    
            for (const string &word : words) {
                for (char ch : word) {
                    if (inDegree.find(ch) == inDegree.end()) {
                        inDegree[ch] = 0;
                    }
                    if (graph.find(ch) == graph.end()) {
                        graph[ch] = unordered_set<char>();
                    }
                }
            }
    
            for (int i = 0; i < words.size() - 1; i++) {
                string word1 = words[i];
                string word2 = words[i + 1];
    
                if (word1.length() > word2.length() && word1.substr(0, word2.length()) == word2) {
                    return "";
                }
    
                int len = min(word1.length(), word2.length());
                for (int j = 0; j < len; j++) {
                    char ch1 = word1[j];
                    char ch2 = word2[j];
    
                    if (ch1 != ch2) {
                        if (graph[ch1].find(ch2) == graph[ch1].end()) {
                            graph[ch1].insert(ch2);
                            inDegree[ch2]++;
                        }
                        break;
                    }
                }
            }
    
            queue<char> que;
            for (const auto &entry : inDegree) {
                if (entry.second == 0) {
                    que.push(entry.first);
                }
            }
    
            string result;
            while (!que.empty()) {
                char curr = que.front();
                que.pop();
                result.push_back(curr);
    
                for (char neighbor : graph[curr]) {
                    inDegree[neighbor]--;
                    if (inDegree[neighbor] == 0) {
                        que.push(neighbor);
                    }
                }
            }
    
            if (result.length() != inDegree.size()) {
                return "";
            }
    
            return result;
        }
    };