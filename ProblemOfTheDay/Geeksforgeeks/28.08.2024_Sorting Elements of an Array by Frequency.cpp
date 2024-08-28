/*
Problem Link :- https://www.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency-1587115621/1
*/

/*Sorting Elements of an Array by Frequency

Given an array of integers arr, sort the array according to the frequency of elements, i.e. elements that have higher frequency comes first. If the frequencies of two elements are the same, then the smaller number comes first.

Examples :

Input: arr[] = [5, 5, 4, 6, 4]
Output: [4, 4, 5, 5, 6]
Explanation: The highest frequency here is 2. Both 5 and 4 have that frequency. Now since the frequencies are the same the smaller element comes first. So 4 4 comes first then comes 5 5. Finally comes 6. The output is 4 4 5 5 6.
Input: arr[] = [9, 9, 9, 2, 5]
Output: [9, 9, 9, 2, 5]
Explanation: The highest frequency here is 3. Element 9 has the highest frequency So 9 9 9 comes first. Now both 2 and 5 have the same frequency. So we print smaller elements first. The output is 9 9 9 2 5.
Expected Time Complexity: O(n*logn)
Expected Space Complexity: O(n)

Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i]≤ 105


*/

//{ Driver Code Starts
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<sstream>
// #include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    static bool func(pair<int , int>& a , pair<int , int>& b){
        if(a.second > b.second)return true;
        else if(a.second < b.second)return false;
        else return a.first < b.first;
    }
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        
        unordered_map<int , int> mp;
        vector<pair<int , int>> freq;
        vector<int> sortedArray;
        
        for(auto& x : arr)mp[x]++;
        
        for(auto& x : arr)freq.push_back({x , mp[x]});
        
        sort(freq.begin() , freq.end() , func);
        
        for(auto x : freq)sortedArray.push_back(x.first);
        
        return sortedArray;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends