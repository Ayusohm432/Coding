/*
Problem Link :- https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/?envType=daily-question&envId=2024-08-06
*/

/*3016. Minimum Number of Pushes to Type Word II


You are given a string word containing lowercase English letters.

Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used to form words by pushing them. For example, the key 2 is mapped with ["a","b","c"], we need to push the key one time to type "a", two times to type "b", and three times to type "c" .

It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. The keys can be remapped to any amount of letters, but each letter must be mapped to exactly one key. You need to find the minimum number of times the keys will be pushed to type the string word.

Return the minimum number of pushes needed to type word after remapping the keys.

An example mapping of letters to keys on a telephone keypad is given below. Note that 1, *, #, and 0 do not map to any letters.


 

Example 1:


Input: word = "abcde"
Output: 5
Explanation: The remapped keypad given in the image provides the minimum cost.
"a" -> one push on key 2
"b" -> one push on key 3
"c" -> one push on key 4
"d" -> one push on key 5
"e" -> one push on key 6
Total cost is 1 + 1 + 1 + 1 + 1 = 5.
It can be shown that no other mapping can provide a lower cost.
Example 2:


Input: word = "xyzxyzxyzxyz"
Output: 12
Explanation: The remapped keypad given in the image provides the minimum cost.
"x" -> one push on key 2
"y" -> one push on key 3
"z" -> one push on key 4
Total cost is 1 * 4 + 1 * 4 + 1 * 4 = 12
It can be shown that no other mapping can provide a lower cost.
Note that the key 9 is not mapped to any letter: it is not necessary to map letters to every key, but to map all the letters.
Example 3:


Input: word = "aabbccddeeffgghhiiiiii"
Output: 24
Explanation: The remapped keypad given in the image provides the minimum cost.
"a" -> one push on key 2
"b" -> one push on key 3
"c" -> one push on key 4
"d" -> one push on key 5
"e" -> one push on key 6
"f" -> one push on key 7
"g" -> one push on key 8
"h" -> two pushes on key 9
"i" -> one push on key 9
Total cost is 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 2 * 2 + 6 * 1 = 24.
It can be shown that no other mapping can provide a lower cost.
 

Constraints:

1 <= word.length <= 105
word consists of lowercase English letters.



*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;


//Approach-1
class Solution {
public:
    void sortFunc(string &word) {
        unordered_map<char, int> mp;
        
        for(const char &ch : word) {
            mp[ch]++;
        }
        
        auto lambda=[&](const char &ch1, const char &ch2){
            return mp[ch1] > mp[ch2];
        };
        
        sort(begin(word), end(word), lambda);
    }
    int minimumPushes(string word) {
        if(word.length() <= 8) {
            return word.length();
        }
        sortFunc(word);
        unordered_map<int, unordered_set<char>> myMap;
        unordered_map<char, pair<int, int>> mp; //char is stored in which key in myMap and at what position it came
        
        int result = 0 ;
        int assign = 2;
        
        for(char &ch : word) {
            if(assign > 9) {
                assign = 2;
            }
            
            
            if(mp.find(ch) == mp.end()) {
                myMap[assign].insert(ch);
                mp[ch]            = {assign, (int)myMap[assign].size()};
                
                result += mp[ch].second;
                assign++;
            } else {
                result += mp[ch].second;
            }
        }
        
        return result;
    }
};


// Approach-2
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mp(26, 0);
        for(char &ch: word)
            mp[ch - 'a']++; //Mentioned in qn, all letters will be distinct
    
        sort(begin(mp), end(mp), greater<int>()); //descending order of frequency
        
        int ans = 0;
        for(int i = 0; i < 26; i++){
            ans += mp[i]*((i/8) + 1);
        }
        return ans;
    }
};


int main(){
    Solution solution;
    string word = "abcde";
    cout << solution.minimumPushes(word) << endl;
    return 0;
}

