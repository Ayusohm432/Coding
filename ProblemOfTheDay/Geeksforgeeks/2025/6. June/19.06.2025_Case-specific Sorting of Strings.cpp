/*
Problem Link: https://www.geeksforgeeks.org/problems/case-specific-sorting-of-strings4845/1
*/

/*Case-specific Sorting of Strings

Given a string s consisting of only uppercase and lowercase characters. The task is to sort uppercase and lowercase letters separately such that if the ith place in the original string had an Uppercase character then it should not have a lowercase character after being sorted and vice versa.

Examples :

Input: s = "GEekS"
Output: EGekS
Explanation: Sorted form of given string with the same case of character will result in output as EGekS.
Input: s = "XWMSPQ"
Output: MPQSWX
Explanation: Since all characters are of the same case We can simply perform a sorting operation on the entire string.
Constraints:
1 ≤ s.length() ≤ 105

*/

class Solution {
  public:
    string caseSort(string& s) {
        // code here
        int n = s.length();
        vector<int> index1, index2;
        string s1="", s2="";
        
        for(int i=0; i<n; i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                s1 += s[i];
                index1.push_back(i);
            }else if(s[i] >= 'A' && s[i] <= 'Z'){
                s2 += s[i];
                index2.push_back(i);
            }
        }
        
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        
        for(int i=0; i<s1.length(); i++){
            int index = index1[i];
            s[index] = s1[i];
        }
        
        for(int i=0; i<s2.length(); i++){
            int index = index2[i];
            s[index] = s2[i];
        }
        
        return s;
    }
};