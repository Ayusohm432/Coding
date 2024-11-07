/*
Problem Link : https://unstop.com/code/practice/296871
*/

/*Excel value of product length

Problem Statement
You are given a list of words, and you need to find two words that do not share any common letters. Your task is to calculate the product of their lengths. Then, convert this product into its corresponding Excel column name (e.g., 1 = A, 27 = AA). If no such pair of words exists, return 0.

Input Format
The first line contains an integer representing the number of words.

The second line contains space-separated strings representing the words.

Output Format
Print the Excel column name corresponding to the maximum product of lengths of two words that do not share any common letters. If no such pair exists, print 0.

Constraints
2 <= words.length <= 10^3

1 <= words[i].length <= 10^3

Sample Testcase 0
Testcase Input
3
abc def bgf
Testcase Output
I
Explanation
The only two words which donot have any letter in common are: "abc" and "def". Therefor the product of thier length is 3*3 = 9, and the corresponding excel value is I

Sample Testcase 1
Testcase Input
6
abcw jaz aoo bar xtgn abcdef
Testcase Output
X
Explanation
The pair of words that donot have letters in common are:


abcw and xtgn . The product of their length is: 16
bar and xtgn . The product of their length is: 12
jaz and xtgn . The product of their length is: 12
aoo and xtgn . The product of their length is: 12
abcdef and xtgn . The product of their length is: 24


The maximum product is 24, and corresponding excel value is X

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int calculateProduct(vector<string>& arr) {
    int maxProduct = 0;
    int n = arr.size();
    
    // Create a bitmask for each word to represent the letters it contains
    vector<int> masks(n);
    for (int i = 0; i < n; i++) {
        for (char c : arr[i]) {
            masks[i] |= (1 << (c - 'a')); // Set the bit corresponding to the character
        }
    }
    
    // Compare each pair of words
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Check if they share any common letters
            if ((masks[i] & masks[j]) == 0) {
                // Calculate the product of their lengths
                int product = arr[i].length() * arr[j].length();
                maxProduct = max(maxProduct, product);
            }
        }
    }
    
    return maxProduct;
}

string findExcelValue(int product) {
    if (product == 0) return "0"; // If there is no valid product
    
    string excelValue = "";
    while (product > 0) {
        product--; // Decrement to make it 0-indexed
        excelValue = char('A' + (product % 26)) + excelValue;
        product /= 26;
    }
    
    return excelValue;
}

int main() {
    int n;
    cin >> n;

    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int product = calculateProduct(arr);
    string excelValue = findExcelValue(product);
    cout << excelValue;

    return 0;
}