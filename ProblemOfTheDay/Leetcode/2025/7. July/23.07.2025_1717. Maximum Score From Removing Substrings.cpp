/*
Problem Link: https://leetcode.com/problems/maximum-score-from-removing-substrings?envType=daily-question&envId=2025-07-23
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

class Solution
{
    int removeStr(stack<char> &st, int x, int y)
    {
        int countA = 0;
        int countB = 0;

        while (!st.empty())
        {
            char ch = st.top();
            st.pop();

            if (ch == 'a')
            {
                countA++;
            }
            else
            {
                countB++;
            }
        }

        int mini = min(countA, countB);
        return (x > y) ? y * mini : x * mini;
    }

public:
    int maximumGain(string s, int x, int y)
    {
        stack<char> st;
        int result = 0;
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            char ch = s[i];

            if (ch != 'a' && ch != 'b')
            {
                if (!st.empty())
                {
                    result += removeStr(st, x, y);
                }
                continue;
            }

            if (!st.empty())
            {
                if (x > y && st.top() == 'a' && ch == 'b')
                {
                    result += x;
                    st.pop();
                }
                else if (y > x && st.top() == 'b' && ch == 'a')
                {
                    result += y;
                    st.pop();
                }
                else
                {
                    st.push(ch);
                }
            }
            else
            {
                st.push(ch);
            }
        }
        if (!st.empty())
        {
            result += removeStr(st, x, y);
        }

        return result;
    }
};