/*
Problem Link : https://leetcode.com/problems/longest-happy-string/?envType=daily-question&envId=2024-10-16
*/

/*1405. Longest Happy String

A string s is called happy if it satisfies the following conditions:

s only contains the letters 'a', 'b', and 'c'.
s does not contain any of "aaa", "bbb", or "ccc" as a substring.
s contains at most a occurrences of the letter 'a'.
s contains at most b occurrences of the letter 'b'.
s contains at most c occurrences of the letter 'c'.
Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.
Example 2:

Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It is the only correct answer in this case.
 

Constraints:

0 <= a, b, c <= 100
a + b + c > 0


*/
class Solution {
public:
    typedef pair<int, char> P;
    string longestDiverseString(int a, int b, int c) {
        priority_queue<P, vector<P>> pq; //max-heap

        if(a > 0) {
            pq.push({a, 'a'});
        }
        if(b > 0) {
            pq.push({b, 'b'});
        }
        if(c > 0) {
            pq.push({c, 'c'});
        }

        string result = "";

        while(!pq.empty()) {
            int currCount = pq.top().first;
            int currChar = pq.top().second;
            pq.pop();

            if(result.length() >= 2 && result[result.length()-1] == currChar && result[result.length()-2] == currChar) {
                //we can't use currChar. Check for next largest freqency char
                if(pq.empty()) {
                    break;
                }

                int nextCount = pq.top().first;
                int nextChar = pq.top().second;
                pq.pop();

                result.push_back(nextChar);
                nextCount--;
                if(nextCount > 0) {
                    pq.push({nextCount, nextChar});
                }
            } else {
                currCount--;
                result.push_back(currChar);
            }

            if(currCount > 0) {
                pq.push({currCount, currChar});
            }
        }

        return result;
    }
};
