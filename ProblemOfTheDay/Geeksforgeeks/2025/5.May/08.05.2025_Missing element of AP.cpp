/*
Problem Link: https://www.geeksforgeeks.org/problems/missing-element-of-ap2228/1
*/

/*Missing element of AP

Given a sorted array arr[] that represents an Arithmetic Progression (AP) with exactly one missing element, find the missing number.

Note: An element will always exist that, upon inserting into a sequence forms Arithmetic progression. If the given sequence already forms a valid complete AP, return the (n+1)-th element that would come next in the sequence.

Examples:

Input: arr[] = [2, 4, 8, 10, 12, 14]
Output: 6
Explanation: Actual AP should be 2, 4, 6, 8, 10, 12, 14.
Input: arr[] = [1, 6, 11, 16, 21, 31]
Output: 26
Explanation: Actual AP should be 1, 6, 11, 16, 21, 26, 31.
Input: arr[] = [4, 7, 10, 13, 16]
Output: 19
Explanation: Since the sequence already forms a valid AP, the next element after 16 in the sequence would be 19. Therefore, the output is 19.
Constraints:
2 <= arr.size() <= 105
0 <= arr[i] <= 2*107

*/

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        int d1 = arr[1] - arr[0];
        
        if(n == 2){
            return arr[1] + d1;
        }
        
        int d2 = arr[2] - arr[1];
        
        int d = min(d1, d2);
        
        if(d == 0){
            return arr[0];
        }
        
        int low = 0, high = n-1;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            int curr = arr[mid];
            
            int expectedPosition = (arr[mid] - arr[0]) / d;
            int actualPosition = mid;
            
            if(actualPosition < expectedPosition){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        
        if(low == n){
            return arr[n-1] + d;
        }
        
        return arr[0] + d * low;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends