/*
problem Link :- https://leetcode.com/problems/sort-an-array/description/?envType=daily-question&envId=2024-07-25
*/


/*912. Sort an Array

Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.
 

Constraints:

1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void mergeArr(vector<int>& arr , int low , int mid , int high){

        int n1 = mid - low + 1;
        int n2 = high - mid;

        vector<int> leftArr(n1);
        vector<int> rightArr(n2);

        for(int i=0 ; i<n1 ; i++){
            leftArr[i] = arr[low+i];
        }

        for(int j=0 ; j<n2 ; j++){
            rightArr[j] = arr[mid+1+j];
        }

        int i=0,j=0,k=low;

        while(i<n1 && j<n2){
            if(leftArr[i] < rightArr[j]){
                arr[k++] = leftArr[i++];
            }
            else{
                arr[k++] = rightArr[j++];
            }
        }
        while(i < n1){
            arr[k++] = leftArr[i++];
        }
        while(j < n2){
            arr[k++] = rightArr[j++];
        }

    }
    void mergeSort(vector<int>& arr , int low , int high){
        if(low < high){
            int mid = low + (high - low) / 2;
            mergeSort(arr , low , mid);
            mergeSort(arr , mid+1 , high);
            mergeArr(arr , low , mid , high);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        mergeSort(nums , low , high);

        return nums;
    }
};

int main(){
    vector<int> nums = {5,2,3,1};
    Solution s;
    vector<int> ans = s.sortArray(nums);
    for(int& num : nums){
        cout<<num<<endl;
    }


}