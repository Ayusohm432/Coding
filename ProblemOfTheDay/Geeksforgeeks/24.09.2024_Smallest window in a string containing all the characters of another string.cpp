/*
Problem Link : https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1
*/

/*Smallest window in a string containing all the characters of another string

Given two strings s and p. Find the smallest window in the string s consisting of all the characters(including duplicates) of the string p.  Return "-1" in case there is no such window present. In case there are multiple such windows of same length, return the one with the least starting index.
Note : All characters are in Lowercase alphabets. 

Examples:

Input: s = "timetopractice", p = "toc"
Output: toprac
Explanation: "toprac" is the smallest
substring in which "toc" can be found.
Input: s = "zoomlazapzo", p = "oza"
Output: apzo
Explanation: "apzo" is the smallest 
substring in which "oza" can be found.
Expected Time Complexity: O(|s|)
Expected Auxiliary Space: O(n), n = len(p)

Constraints: 
1 ≤ |s|, |p| ≤ 105

*/

class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        if(p.length() > s.length()){
            return "-1";
        }
        
        unordered_map<char , bool> mp;
        
        int pHash[26] = {0};
        
        for(int i=0 ; i<p.size() ; i++){
            pHash[p[i] - 'a']++;
            mp[p[i]] = true;
        }
        
        int count = mp.size();
        int startIndex = -1;
        int length = 0;
        int minLength = INT_MAX;
        
        int i=0 , j=0;
        while(j < s.size()) {
            if(mp[s[j]] == true){
                pHash[s[j] - 'a']--;
                if(pHash[s[j] - 'a'] == 0){
                    count--;
                }
            }
            
            while(count == 0){
                length = j-i+1;
                if(length < minLength){
                    startIndex = i;
                    minLength = length;
                }
                
                if(mp[s[i]] == true){
                    pHash[s[i] - 'a']++;
                    if(pHash[s[i] - 'a'] > 0){
                        count++;
                    }
                }
                i++;
            }
            j++;
        }
        if(startIndex == -1){
            return "-1";
        }
        else{
            return s.substr(startIndex,minLength);
        }
    
    }
    

};