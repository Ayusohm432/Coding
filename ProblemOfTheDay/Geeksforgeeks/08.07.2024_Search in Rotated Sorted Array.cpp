/*
Problem Link :- https://www.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1
*/

/*Search in Rotated Sorted Array

Given a sorted (in ascending order) and rotated array arr of distinct elements which may be rotated at some point and given an element key, the task is to find the index of the given element key in the array arr. The whole array arr is given as the range to search.

Rotation shifts elements of the array by a certain number of positions, with elements that fall off one end reappearing at the other end.

Note:- 0-based indexing is followed & returns -1 if the key is not present.

Examples :

Input: arr[] = [5, 6, 7, 8, 9, 10, 1, 2, 3], key = 10
Output: 5
Explanation: 10 is found at index 5.
Input: arr[] = [3, 5, 1, 2], key = 6
Output: -1
Explanation: There is no element that has value 6.
Expected Time Complexity: O(log n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 106
1 ≤ key ≤ 105


*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        
        
        int low = 0 , high = arr.size()-1 , mid;
        
        while(low <= high){
            mid = (low+high)/2;
            
            if(arr[mid] == key){
                return mid;
            }
            
            else if(arr[mid] < arr[0]){
                if(key > arr[mid] && key <= arr[high]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
            
            else{
                if(key < arr[mid] && key >= arr[low]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
        }
        return -1;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends