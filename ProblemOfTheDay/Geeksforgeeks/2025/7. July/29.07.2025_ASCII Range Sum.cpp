/*
Problem Link: https://www.geeksforgeeks.org/problems/ascii-range-sum/1
*/

/*ASCII Range Sum

Given a string s consisting of lowercase English letters, for every character whose first and last occurrences are at different positions, calculate the sum of ASCII values of characters strictly between its first and last occurrence.
Return all such non-zero sums (order does not matter).

Examples:

Input: s = "abacab"
Output: [293, 294]
Explanation: characters 'a' and 'b' appear more than once:
'a' : between positions 1 and 5 → characters are b, a, c and ascii sum is 98 + 97 + 99 = 294.
'b' : between positions 2 and 6 → characters are a, c, a and ascii sum is 97 + 99 + 97 = 293.
Input: s = "acdac"
Output: [197, 199]
Explanation: characters 'a' and 'c' appear more than once:
'a' : between positions 1 and 4 → characters are c, d and ascii sum is 99 + 100 = 199.
'c' : between positions 2 and 5 → characters are d, a and ascii sum is 100 + 97 = 197.
Constraints:
1 ≤ s.size() ≤ 105

*/

class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
        int n = s.length();
        vector<int> result;
        
        unordered_map<char, vector<int>> mp;
        for(int i=0; i<n; i++){
            mp[s[i]].push_back(i);
        }
        
        for(auto pair : mp){
            if(pair.second.size() <= 1){
                continue;
            }
            int sum = 0;
            auto curr = pair.second;
            int first = curr.front();
            int last = curr.back();
            
            for(int i=first+1; i < last; i++){
                sum += int(s[i]);
            }
            if(sum == 0){
                continue;
            }
            result.push_back(sum);
        }
        
        sort(result.begin(), result.end());
        return result;
    }
};