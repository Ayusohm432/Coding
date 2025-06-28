/*
Problem Link: https://www.geeksforgeeks.org/problems/counting-elements-in-two-arrays/1
*/

/*Counting elements in two arrays

You are given two unsorted arrays a[] and b[]. Both arrays may contain duplicate elements. For each element in a[], your task is to count how many elements in b[] are less than or equal to that element.

Examples:

Input: a[] = [4, 8, 7, 5, 1], b[] = [4, 48, 3, 0, 1, 1, 5]
Output: [5, 6, 6, 6, 3]
Explanation: 
For a[0] = 4, there are 5 elements in b (4, 3, 0, 1, 1) that are ≤ 4.
For a[1] = 8 and a[2] = 7, there are 6 elements in b that are ≤ 8 and ≤ 7.
For a[3] = 5, there are 6 elements in b that are ≤ 5.
For a[4] = 1, there are 3 elements in b (0, 1, 1) that are ≤ 1.
Input: a[] = [10, 20], b[] = [30, 40, 50]
Output: [0, 0]
Explanation: 
For a[0] = 10 and a[1] = 20, there are no elements in b that are less than or equal to 10 or 20. Hence, the output is [0, 0].
Constraints:
1 ≤ a.size(), b.size() ≤ 105
0 ≤ a[i], b[j] ≤ 105

*/

class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        const int MAX_VAL = 1e5;
        vector<int> freq(MAX_VAL+1, 0);
        
        for(int num : b){
            freq[num]++;
        }
        
        for(int i=1; i<=MAX_VAL; i++){
            freq[i] += freq[i-1];
        }
        
        vector<int> result;
        for(int num : a){
            if(num > MAX_VAL){
                num = MAX_VAL;
            }
            result.push_back(freq[num]);
        }
        
        return result;
    }
};