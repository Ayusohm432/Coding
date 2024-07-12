/*
Problem Link :- https://leetcode.com/problems/maximum-score-from-removing-substrings/?envType=daily-question&envId=2024-07-12
*/

/*1717. Maximum Score From Removing Substrings

You are given a string s and two integers x and y. You can perform two types of operations any number of times.

Remove substring "ab" and gain x points.
For example, when removing "ab" from "cabxbae" it becomes "cxbae".
Remove substring "ba" and gain y points.
For example, when removing "ba" from "cabxbae" it becomes "cabxe".
Return the maximum points you can gain after applying the above operations on s.

 

Example 1:

Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
Explanation:
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.
Example 2:

Input: s = "aabbaaxybbaabb", x = 5, y = 4
Output: 20
 

Constraints:

1 <= s.length <= 105
1 <= x, y <= 104
s consists of lowercase English letters.

*/

//Approach-1            T.C = O(n)        S.C = O(n);
class Solution {
public:
    string removeSubStr(string& s , string& toMatch){
        stack<char> st;

        for(char& ch : s){
            if(ch == toMatch[1] && !st.empty() && st.top() == toMatch[0]){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }

        string temp;
        while(!st.empty()){
            temp .push_back(st.top());
            st.pop();
        }

        reverse(temp.begin() , temp.end());

        return temp;
    }
    int maximumGain(string s, int x, int y) {
        int score = 0;
        int n = s.length();

        string maxStr = (x>y) ? "ab" : "ba";
        string minStr = (x<y) ? "ab" : "ba";

        //First Pass
        string tempFirst = removeSubStr(s,maxStr);
        int charRemoved = n - tempFirst.length();
        score += ((charRemoved/2)*max(x,y));

        //Second Pass
        string tempSecond = removeSubStr(tempFirst,minStr);
        charRemoved = tempFirst.length() - tempSecond.length();
        score += ((charRemoved/2)*min(x,y));

        return score;
    }
};

//Approach-2            T.C = O(n)        S.C = O(1);

class Solution {
public:
    string removeSubStr(string s , string toMatch){
        int i=0 ; 
        for(int j=0 ; j<s.length() ; j++){
            s[i] = s[j];
            i++;

            if(i>=2 && s[i-2] == toMatch[0] && s[i-1] == toMatch[1]){
                i -= 2;
            }
        }

        s.erase(begin(s)+i , end(s));

        return s;
    }
    int maximumGain(string s, int x, int y) {
        int score = 0;
        int n = s.length();

        string maxStr = (x>y) ? "ab" : "ba";
        string minStr = (x<y) ? "ab" : "ba";

        //First Pass
        string tempFirst = removeSubStr(s,maxStr);
        int charRemoved = n - tempFirst.length();
        score += ((charRemoved/2)*max(x,y));

        //Second Pass
        string tempSecond = removeSubStr(tempFirst,minStr);
        charRemoved = tempFirst.length() - tempSecond.length();
        score += ((charRemoved/2)*min(x,y));

        return score;
    }
};