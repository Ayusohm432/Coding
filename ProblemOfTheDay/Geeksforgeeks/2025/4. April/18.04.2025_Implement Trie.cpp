/*
Problem Link: https://www.geeksforgeeks.org/problems/trie-insert-and-search0651/1
*/

/*Implement Trie

Implement Trie class and complete insert(), search() and isPrefix() function for the following queries :

Type 1 : (1, word), calls insert(word) function and insert word in the Trie
Type 2 : (2, word), calls search(word) function and check whether word exists in Trie or not.
Type 3 : (3, word), calls isPrefix(word) function and check whether word exists as a prefix of any string in Trie or not.
Examples :

Input: query[][] = [[1, "abcd"], [1, "abc"], [1, "bcd"], [2, "bc"], [3, "bc"], [2, "abc"]]
Output: [false, true, true]
Explanation: string "bc" does not exist in the trie, "bc" exists as prefix of the word "bcd" in the trie, and "abc" also exists in the trie.
Input: query[][] = [[1, "gfg"], [1, "geeks"], [3, "fg"], [3, "geek"], [2, "for"]]
Output: [false, true, false]
Explanation: The string "for" is not present in the trie, "fg" is not a valid prefix, while "geek" is a valid prefix of the word "geeks" in the trie.
Constraints:
1 ≤ query.size() ≤ 104
1 ≤ word.size() ≤ 103

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
struct Node{
    Node* links[26];
    bool isEnd = false;
    
    bool containsKey(char ch){
        return links[ch-'a'] != nullptr;
    }
    
    Node* get(char ch){
        return links[ch - 'a'];
    }
    
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    
    void setEnd(){
        isEnd = true;
    }
    
    bool getEnd(){
        return isEnd;
    }
};

class Trie {
    Node* root;
  public:

    Trie() {
        // implement Trie
        root = new Node();
    }

    void insert(string &word) {
        // insert word into Trie
        int n = word.length();
        Node* node = root;
        for(int i=0; i<n; i++){
            char ch = word[i];
            if(!node->containsKey(ch)){
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool search(string &word) {
        // search word in the Trie
        int n = word.length();
        Node* node = root;
        for(int i=0; i<n; i++){
            char ch = word[i];
            if(!node->containsKey(ch)){
                return false;
            }
            node = node->get(ch);
        }
        return node->getEnd();
    }

    bool isPrefix(string &word) {
        // search prefix word in the Trie
        int n = word.length();
        Node* node = root;
        for(int i=0; i<n; i++){
            char ch = word[i];
            if(!node->containsKey(ch)){
                return false;
            }
            node = node->get(ch);
        }
        return true;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int q;
        cin >> q;
        cin.ignore();
        vector<bool> ans;
        Trie ob;
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            string s;
            cin >> s;
            cin.ignore();
            if (x == 1) {
                ob.insert(s);
            } else if (x == 2) {
                ans.push_back(ob.search(s));
            } else if (x == 3) {
                ans.push_back(ob.isPrefix(s));
            }
        }
        cout << boolalpha;
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends