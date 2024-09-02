/*
Problem Link : https://unstop.com/code/practice/250266
*/

/*Find Pair LCA

Problem Statement
Alice is given a binary tree represented as an array using level-order traversal. The array has a size of N and contains the node values. Along with this, Alice has two nodes p and q from the binary tree.

Your task is to help Alice find the number of unique pairs of nodes in the tree such that the sum of each pair is equal to the Lowest Common Ancestor (LCA) of nodes p and q.

Note: Each pair must be unique, and permutations of pairs are not considered.

Input Format
In the first line, a number N is given representing the number of nodes.

In the second line, N spaced numbers are given representing the element of level order array of binary tree.

In the third line two numbers p and q are given representing the selected nodes.

Output Format
A single number represents the count of pairs whose sum equals to LCA present in the tree of the given nodes 

Constraints
1 <= N <= 10^5

1 <= Ai <= 10^6

Sample Testcase 0
Testcase Input
6
1 2 3 4 5 6
3 4
Testcase Output
0
Explanation
      1
   /     \
  2      3
 / \      / 
4  5   6


In the tree given above the LCA of 3 and 4 is 1 and there is no pair available in the tree whose sum is 1.

Sample Testcase 1
Testcase Input
7
1 2 3 0 0 5 7
3 5
Testcase Output
2
Explanation
     1
   /    \
  2     3
 / \     / \
0  0  5  7


Node 3 is a child of node 1, and node 5 is a child of node 3.
The Lowest Common Ancestor (LCA) of nodes 3 and 5 is node 3 itself, as it is the direct parent of node 5.


There are 2 pairs available in the tree whose sum is 3.
1. (2,1) or (1,2)
2. (3,0) or (0,3)

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Function to find the index of an element in the array
int findIndex(const vector<int>& arr, int value) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

// Function to find the Lowest Common Ancestor (LCA) in a binary tree represented as an array
int findLCA(const vector<int>& arr, int p, int q) {
    int index_p = findIndex(arr, p);
    int index_q = findIndex(arr, q);
    
    while (index_p != index_q) {
        if (index_p > index_q) {
            index_p = (index_p - 1) / 2;
        } else {
            index_q = (index_q - 1) / 2;
        }
    }
    
    return arr[index_p];
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    int p, q;
    cin >> p >> q;
    
    int lca = findLCA(arr, p, q);
    
    unordered_map<int, int> freqMap;
    unordered_set<int> visited;
    int pairCount = 0;
    
    for (int i = 0; i < N; i++) {
        int complement = lca - arr[i];
        if (freqMap.find(complement) != freqMap.end() && visited.find(complement) == visited.end()) {
            pairCount++;
            visited.insert(arr[i]);
            visited.insert(complement);
        }
        freqMap[arr[i]]++;
    }
    
    cout << pairCount << endl;
    
    return 0;
}
