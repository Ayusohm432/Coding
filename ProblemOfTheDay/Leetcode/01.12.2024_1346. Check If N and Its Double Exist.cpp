/*
Problem link: https://leetcode.com/problems/check-if-n-and-its-double-exist?envType=daily-question&envId=2024-12-01
*/

/*1346. Check If N and Its Double Exist

Given an array arr of integers, check if there exist two indices i and j such that :

i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]
 

Example 1:

Input: arr = [10,2,5,3]
Output: true
Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]
Example 2:

Input: arr = [3,1,7,11]
Output: false
Explanation: There is no i and j that satisfy the conditions.
 

Constraints:

2 <= arr.length <= 500
-103 <= arr[i] <= 103

*/

//Approach-1

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();

        int i = 0; 
        while(i < n){
            int j = 0;
            while(j < n){
                if(i != j && arr[i] == 2 * arr[j]){
                    return true;
                }
                j++;
            }
            i++;
        }

        return false;
    }
};

//Approach-2
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> st;
        for(int& num : arr){
            if(st.find(num * 2) != st.end()){
                return true;
            }
            else if(num % 2 == 0){
                if(st.find(num / 2) != st.end()){
                    return true;
                }
            }
            st.insert(num);
        }

        return false;
    }
};

//Appraoch-3
class Solution {
public:
    int binarySearch(vector<int>& arr, int target){
        int low = 0; 
        int high = arr.size() - 1;

        int mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(arr[mid] == target){
                return mid;
            }
            else if(arr[mid] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return -1;
    }
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        for(int i=0; i<n; i++){
            int j = binarySearch(arr, 2*arr[i]);
            if(j != -1 && i != j){
                return true;
            }
        }
        return false;
    }
};