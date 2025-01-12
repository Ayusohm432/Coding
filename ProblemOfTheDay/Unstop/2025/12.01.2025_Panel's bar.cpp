/*
Problem Link: https://unstop.com/code/practice/261660
*/

/*Panel's bar

Problem Statement
There is a panel where there are several chocolate bars which have heights represented by integers placed in a line. The width of each chocolate bar is 1.

These chocolate bars form a rectangle.

Charlie asked you to find the space occupied by the greatest rectangle. 

Input Format
An integer n representing the number of chocolates.
An array of n Integers seprated by space - representing the height of chocolate bars. 
Output Format
An integer value represents the area of the largest rectangle formed by the chocolates. 
Constraints
1 <= heights.length <= 10^5
0 <= heights[i] <= 10^4
Sample Testcase 0
Testcase Input
2
2 4
Testcase Output
4
Explanation



Value would be 4 units for max area.

Sample Testcase 1
Testcase Input
7
 6 2 5 4 5 1 6
Testcase Output
12
Explanation



The area here formed would be 12.

*/

#include <bits/stdc++.h>
using namespace std;

// Function where the user will write the logic
int largestRectangleArea(vector<int>& heights) {
    // Write your logic here
    // Parameters:
    //     heights (vector<int>): List of integers representing the heights of chocolate bars
    // Returns:
    //     int: Computed area of the largest rectangle formed by the chocolates
    unordered_map<int, pair<int, int>> um;
    for(int i = 0; i < heights.size(); i++){
        um[i] = {-1, (int)heights.size()};
    }
    stack<int> st;
    for(int i = 0; i < heights.size(); i++){
        while(!st.empty() && heights[i] < heights[st.top()]){
            um[st.top()].second = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
        st.pop();
    for(int i = heights.size() - 1; i >= 0; i--){
        while(!st.empty() && heights[i] < heights[st.top()]){
            um[st.top()].first = i;
            st.pop();
        }
        st.push(i);
    }
    int result = 0;
    for(int i = 0; i < heights.size(); i++){
        int prev = um[i].first;
        int next = um[i].second;
        int area = heights[i] * (next - prev - 1);
        result = max(result, area);
    }
    return result;
}

int main() {
    int n;
    cin >> n; // Read the number of chocolates
    vector<int> heights(n); // Array to hold the heights of chocolate bars

    for (int i = 0; i < n; ++i) {
        cin >> heights[i]; // Read each height value
    }

    // Call user logic function and print the output
    int result = largestRectangleArea(heights);
    cout << result << endl;

    return 0;
}