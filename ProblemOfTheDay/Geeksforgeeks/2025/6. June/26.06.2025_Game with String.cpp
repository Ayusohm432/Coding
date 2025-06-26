/*
Problem Link: https://www.geeksforgeeks.org/problems/game-with-string4100/1
*/

/*Game with String

Given a string s consisting of lowercase alphabets and an integer k, your task is to find the minimum possible value of the string after removing exactly k characters.

The value of the string is defined as the sum of the squares of the frequencies of each distinct character present in the string.

Examples :

Input: s = "abbccc", k = 2
Output: 6
Explaination: We remove two 'c' to get the value as 12 + 22 + 12 = 6 or We remove one 'b' and one 'c' to get the value 12 + 12 + 22 = 6.
Input: s = "aaab", k = 2
Output: 2
Explaination: We remove two 'a'. Now we get the value as 12 + 12 = 2.
Constraints:
0 ≤ k ≤ s.length() ≤ 105 

*/

class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        vector<int> freq(26, 0);
        
        for(char& ch : s){
            freq[ch - 'a']++;
        }
        
        priority_queue<int> maxHeap;
        for(int ch : freq){
            if(ch > 0){
                maxHeap.push(ch);
            }
        }
        
        while(k-- && !maxHeap.empty()){
            int top = maxHeap.top();
            maxHeap.pop();
            top--;
            if(top > 0){
                maxHeap.push(top);
            }
        }
        
        int result = 0;
        while(!maxHeap.empty()){
            int ch = maxHeap.top();
            maxHeap.pop();
            result += (ch * ch);
        }
        
        return result;
    }
};