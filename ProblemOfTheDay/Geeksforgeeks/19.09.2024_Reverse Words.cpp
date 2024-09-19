/*
Problem Link : https://www.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1
*/

/*Reverse Words

Given a String str, reverse the string without reversing its individual words. Words are separated by dots.

Note: The last character has not been '.'. 

Examples :

Input: str = i.like.this.program.very.much
Output: much.very.program.this.like.i
Explanation: After reversing the whole string(not individual words), the input string becomes much.very.program.this.like.i
Input: str = pqr.mno
Output: mno.pqr
Explanation: After reversing the whole string , the input string becomes mno.pqr
Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

Constraints:
1 <= |str| <= 105

*/


//Approach - 1
class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        vector<string> words;
        
        string s1;
        istringstream iss(str);
        
        while(getline(iss , s1 , '.')){
            words.push_back(s1);
        }
        
        string result = "";
        
        for(int i=words.size()-1 ; i >= 0 ; i--){
            result  += words[i];
            if(i != 0){
                result += '.';
            }
        }
        return result;
    }
};

//Approach - 2
class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        int j=0;
        for(int i=0 ; i<str.length() ; i++){
            if(str[i] == '.'){
                reverse(str.begin()+j , str.begin()+i);
                j = i+1;
            }
            else if(i == str.length()-1){
                reverse(str.begin()+j , str.end());
            }
        }
        reverse(str.begin() , str.end());
        return str;
    }
};