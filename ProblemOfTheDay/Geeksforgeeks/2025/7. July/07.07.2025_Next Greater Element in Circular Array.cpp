/*
Problem Link: https://www.geeksforgeeks.org/problems/next-greater-element/1
*/

/*Next Greater Element in Circular Array

Given a circular integer array arr[], the task is to determine the next greater element (NGE) for each element in the array.

The next greater element of an element arr[i] is the first element that is greater than arr[i] when traversing circularly. If no such element exists, return -1 for that position.

Circular Property:

Since the array is circular, after reaching the last element, the search continues from the beginning until we have looked at all elements once.

Examples: 

Input: arr[] = [1, 3, 2, 4]
Output: [3, 4, 4, -1]
Explanation:
The next greater element for 1 is 3.
The next greater element for 3 is 4.
The next greater element for 2 is 4.
The next greater element for 4 does not exist, so return -1.
Input: arr[] = [0, 2, 3, 1, 1]
Output: [2, 3, -1, 2, 2]
Explanation:
The next greater element for 0 is 2.
The next greater element for 2 is 3.
The next greater element for 3 does not exist, so return -1.
The next greater element for 1 is 2 (from circular traversal).
The next greater element for 1 is 2 (from circular traversal).
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 106

*/


class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
        int n = arr.size();
        stack<int> st;
        
        for(int i=n-1; i>=0; i--){
            st.push(arr[i]);
        }
        
        for(int i=n-1; i>=0; i--){
            int num = arr[i];
            while(!st.empty() && st.top() <= num){
                st.pop();
            }
            
            if(!st.empty()){
                arr[i] = st.top();
            }else{
                arr[i] = -1;
            }
            st.push(num);
        }
        
        return arr;
    }
};