/*
Problem Link :- 
*/
/*Extract the Number from the String(Regular Expression)

Given a sentence containing several words and numbers. Find the largest number among them which does not contain 9. If no such number exists, return -1.

Note: Numbers and words are separated by spaces only. It is guaranteed that there are no leading zeroes in the answer.

Examples :

Input: sentence="This is alpha 5057 and 97"
Output: 5057
Explanation: 5057 is the only number that does not have a 9.
Input: sentence="Another input 9007"
Output: -1
Explanation: Since there is no number that does not contain a 9,output is -1.
Expected Time Complexity: O(n)
Expected Auxillary Space: O(n)

Constraints:
1<=n<=106
1<=answer<=1018

n is the length of a given sentence.
*/

//Approach 1
class Solution {
  public:
    long long ExtractNumber(string sentence) {

        // code here
        long long ans = 0;
        long long temp = 0;
        bool indication = false;
        
        for(char ch : sentence){
            if(ch >='0' and ch <='9'){
                temp = temp*10 + (ch-'0');
                if(ch == '9'){
                    indication = true;
                }
            }
            else if(ch  == ' '){
                if(!indication){
                    ans = max(ans,temp);
                }
                indication = false;
                temp = 0;
            }
            
        }
        if(!indication){
            ans = max(ans,temp);
        }
        return ans==0?-1:ans;
    }
};
//Approach 2 

class Solution {
  public:
    long long ExtractNumber(string sentence) {

        // code here
        regex re("\\d+");
        smatch match;
        
        string s = sentence;
        vector<string> store;
        
        while(regex_search(s,match,re)){
            store.push_back(match.str());
            s=match.suffix().str();
        }
        long long ans = -1;
        long long temp  = LLONG_MIN;
        
        for(const auto& num : store){
            if(num.find('9') == string::npos){
                long long numvalue = stoll(num);
                temp = max(temp,numvalue);
            }
        }
        
        ans = max(ans,temp);
        return ans;
    }
};


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

//Class solution to be added

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends
