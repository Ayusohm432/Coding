/*
Problem Link : https://leetcode.com/problems/extra-characters-in-a-string/description/?envType=daily-question&envId=2024-09-23
*/

/*2707. Extra Characters in a String

You are given a 0-indexed string s and a dictionary of words dictionary. You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. There may be some extra characters in s which are not present in any of the substrings.

Return the minimum number of extra characters left over if you break up s optimally.

 

Example 1:

Input: s = "leetscode", dictionary = ["leet","code","leetcode"]
Output: 1
Explanation: We can break s in two substrings: "leet" from index 0 to 3 and "code" from index 5 to 8. There is only 1 unused character (at index 4), so we return 1.

Example 2:

Input: s = "sayhelloworld", dictionary = ["hello","world"]
Output: 3
Explanation: We can break s in two substrings: "hello" from index 3 to 7 and "world" from index 8 to 12. The characters at indices 0, 1, 2 are not used in any substring and thus are considered as extra characters. Hence, we return 3.
 

Constraints:

1 <= s.length <= 50
1 <= dictionary.length <= 50
1 <= dictionary[i].length <= 50
dictionary[i] and s consists of only lowercase English letters
dictionary contains distinct words


*/

//Approach-1
class Solution {
public:
    int t[51];
    int solve(int i , string& s , unordered_set<string>& st , int& n){
        if(i >= n){
            return 0;
        }

        if(t[i] != -1){
            return t[i];
        }

        int result = 1 + solve(i+1 , s , st , n);

        for(int j=i ; j<n ; j++){
            string curr = s.substr(i , j-i+1);
            if(st.count(curr)){
                result = min(result , solve(j+1 , s , st , n));
            }
        }
        return t[i] = result;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        memset(t , -1 , sizeof(t));
        unordered_set<string> st(begin(dictionary) , end(dictionary));

        return solve(0 , s , st , n);
    }
};

//Approach-2
class Solution {
public:
    int solve(int i , string& s , unordered_set<string>& st , int& n , unordered_map<int , int>& mp){
        if(i >= n){
            return 0;
        }

        if(mp.count(i)){
            return mp[i];
        }

        int result = 1 + solve(i+1 , s , st , n , mp);

        for(int j=i ; j<n ; j++){
            string curr = s.substr(i , j-i+1);
            if(st.count(curr)){
                result = min(result , solve(j+1 , s , st , n , mp));
            }
        }
        return mp[i] = result;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        unordered_map<int , int> mp;
        unordered_set<string> st(begin(dictionary) , end(dictionary));

        return solve(0 , s , st , n , mp);
    }
};

//Approach-3
class Solution {
public:
    int solve(int i , string& s , unordered_set<string>& st , int& n , unordered_map<int , int>& mp){
        if(i >= n){
            return 0;
        }

        if(mp.count(i)){
            return mp[i];
        }

        int result = 1 + solve(i+1 , s , st , n , mp);

        for(int j=i ; j<n ; j++){
            string curr = s.substr(i , j-i+1);
            if(st.count(curr)){
                result = min(result , solve(j+1 , s , st , n , mp));
            }
        }
        return mp[i] = result;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        unordered_map<int , int> mp;
        unordered_set<string> st(begin(dictionary) , end(dictionary));

        return solve(0 , s , st , n , mp);
    }
};