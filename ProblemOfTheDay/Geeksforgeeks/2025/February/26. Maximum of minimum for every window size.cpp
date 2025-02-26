/*
Problem Link: https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1
*/

/*Maximum of minimum for every window size

Given an array of integers arr[], the task is to find the maximum of the minimum values for every possible window size in the array, where the window size ranges from 1 to arr.size().

More formally, for each window size k, determine the smallest element in all windows of size k, and then find the largest value among these minimums where 1<=k<=arr.size().

Examples :

Input: arr[] = [10, 20, 30, 50, 10, 70, 30]
Output: [70, 30, 20, 10, 10, 10, 10] 
Explanation: 
1. First element in output indicates maximum of minimums of all windows of size 1. Minimums of windows of size 1 are [10], [20], [30], [50], [10], [70] and [30]. Maximum of these minimums is 70. 
2. Second element in output indicates maximum of minimums of all windows of size 2. Minimums of windows of size 2 are [10], [20], [30], [10], [10], and [30]. Maximum of these minimums is 30. 
3. Third element in output indicates maximum of minimums of all windows of size 3. Minimums of windows of size 3 are [10], [20], [10], [10] and [10]. Maximum of these minimums is 20. 
Similarly other elements of output are computed.
Input: arr[] = [10, 20, 30]
Output: [30, 20, 10]
Explanation: First element in output indicates maximum of minimums of all windows of size 1. Minimums of windows of size 1 are [10] , [20] , [30]. Maximum of these minimums are 30 and similarly other outputs can be computed
Constraints:
1 <= arr.size() <= 105
1 <= arr[i] <= 106

*/

class Solution {
    void leftSmaller(vector<int>& leftSmall, vector<int>& arr, int n){
        stack<int> st;
        st.push(n-1);
        
        for(int i=n-2; i>=0; i--){
            while(!st.empty() && arr[st.top()] > arr[i]){
                leftSmall[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return;
    }
    
    void rightSmaller(vector<int>& rightSmall, vector<int>& arr, int n){
        stack<int> st;
        st.push(0);
        for(int i=1; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                rightSmall[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return;
    }
    
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        vector<int> leftSmall(n, -1);
        vector<int> rightSmall(n, n);
        
        leftSmaller(leftSmall, arr, n);
        rightSmaller(rightSmall, arr, n);
        
        vector<int> result(n, 0);
        
        for(int i=0; i<n; i++){
            int val = rightSmall[i] - leftSmall[i] - 1;
            result[val - 1] = max(result[val - 1], arr[i]);
        }
        
        for(int i=n-2; i>=0; i--){
            result[i] = max(result[i+1], result[i]);
        }
        return result;
    }
};