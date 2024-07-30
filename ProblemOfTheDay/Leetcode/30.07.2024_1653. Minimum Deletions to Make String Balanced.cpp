/*
Problem Link :- https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/?envType=daily-question&envId=2024-07-30
*/

/*1653. Minimum Deletions to Make String Balanced


You are given a string s consisting only of characters 'a' and 'b'​​​​.

You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.

Return the minimum number of deletions needed to make s balanced.

 

Example 1:

Input: s = "aababbab"
Output: 2
Explanation: You can either:
Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").
Example 2:

Input: s = "bbaaaaabb"
Output: 2
Explanation: The only solution is to delete the first two characters.
 

Constraints:

1 <= s.length <= 105
s[i] is 'a' or 'b'​​.

*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//Approach-1
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int count = 0;

        stack<char> st;
        for(int i=0 ; i<n ; i++){
            if(!st.empty() && s[i] == 'a' && st.top() == 'b'){
                st.pop();
                count++;
            }
            else{
                st.push(s[i]);
            }
        }
        return count;
    }
};

//Approach-2
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();

        vector<int> leftB(n , 0);
        vector<int> rightA(n , 0);

        int countB = 0;
        for(int i=0 ; i<n ; i++){
            leftB[i] = countB;
            if(s[i] == 'b'){
                countB++;
            }
        }

        int countA = 0;
        for(int i=n-1 ; i>=0 ; i--){
            rightA[i] = countA;
            if(s[i] == 'a'){
                countA++;
            }
        }

        int count = INT_MAX;
        for(int i=0 ; i<n ; i++){
            count = min(count , leftB[i]+rightA[i]);
        }
        return count;
    }
};

//Approach-3
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();

        vector<int> rightA(n , 0);


        int countA = 0;
        for(int i=n-1 ; i>=0 ; i--){
            rightA[i] = countA;
            if(s[i] == 'a'){
                countA++;
            }
        }
        
        int countB = 0;
        int count = INT_MAX;
        for(int i=0 ; i<n ; i++){
            count = min(count , countB+rightA[i]);
            if(s[i] == 'b'){
                countB++;
            }
        }
        return count;
    }
};

//Approach-4
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();

        int countA = 0;
        for(int i=n-1 ; i>=0 ; i--){
            if(s[i] == 'a'){
                countA++;
            }
        }

        int countB = 0;
        int count = INT_MAX;
        for(int i=0 ; i<n ; i++){
            if(s[i] == 'a'){
                countA--;
            }
            count = min(count , countB+countA);
            if(s[i] == 'b'){
                countB++;
            }
        }
        return count;
    }
};

int main(){
    Solution obj;
    cout<<obj.minimumDeletions("aababbab")<<endl;
    cout<<obj.minimumDeletions("bbaaaaabb")<<endl;
    return 0;
}