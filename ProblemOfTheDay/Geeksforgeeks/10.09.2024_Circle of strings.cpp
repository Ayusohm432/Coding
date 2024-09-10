/*
problem Link : https://www.geeksforgeeks.org/problems/circle-of-strings4530/1
*/

/*Circle of strings

Given an array arr of lowercase strings, determine if the strings can be chained together to form a circle.
A string X can be chained together with another string Y if the last character of X is the same as the first character of Y. If every string of the array can be chained with exactly two strings of the array(one with the first character and the second with the last character of the string), it will form a circle.

For example, for the array arr[] = {"for", "geek", "rig", "kaf"} the answer will be Yes as the given strings can be chained as "for", "rig", "geek" and "kaf"

Examples

Input: arr[] = ["abc", "bcd", "cdf"]
Output: 0
Explaination: These strings can't form a circle because no string has 'd'at the starting index.
Input: arr[] = ["ab" , "bc", "cd", "da"]
Output: 1
Explaination: These strings can form a circle of strings.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints: 
1 ≤ length of strings ≤ 20

*/

class Solution {
  public:
    int isCircle(vector<string> &arr) {
        // code here
        int n = arr.size();
        vector<int> visited(n , 0) , indegree(26 , 0) , outdegree(26 , 0);
        unordered_map<char , vector<int>> mp;
        queue<int> q;
        
        for(int i=0 ; i<n ; i++){
            indegree[arr[i][0] - 'a']++;
            outdegree[arr[i].back() - 'a']++;
            mp[arr[i][0]].push_back(i);
        }
        
        for(auto x : mp){
            if(indegree[x.first - 'a'] != outdegree[x.first - 'a']){
                return 0;
            }
        }
        
        q.push(0);
        visited[0] = 1;
        int ans = 1;
        while(!q.empty()){
            int index = q.front();
            q.pop();
            
            for(auto x : mp[arr[index].back()]){
                if(!visited[x]){
                    ans++;
                    visited[x] = 1;
                    q.push(x);
                }
            }
        }
        return ans == n;
    }
};