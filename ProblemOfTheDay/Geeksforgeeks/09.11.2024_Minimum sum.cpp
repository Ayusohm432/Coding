/*
Problem Link : https://www.geeksforgeeks.org/problems/minimum-sum4058/1
*/

/*Minimum sum

Given an array arr[] such that each element is in the range [0 - 9], find the minimum possible sum of two numbers formed using the elements of the array. All digits in the given array must be used to form the two numbers. Return a string without leading zeroes.

Examples :

Input: arr[] = [6, 8, 4, 5, 2, 3]
Output: 604
Explanation: The minimum sum is formed by numbers 358 and 246.
Input: arr[] = [5, 3, 0, 7, 4]
Output: 82
Explanation: The minimum sum is formed by numbers 35 and 047.
Input: arr[] = [9, 4]
Output: 13
Explanation: The minimum sum is formed by numbers 9 and 4.
Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 9

*/
class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        string num1,num2;
        
        for(int i=0; i<n; i++){
            if(i % 2){
                num1 += ('0' + arr[i]);
            }
            else{
                num2 += ('0' + arr[i]);
            }
        }
        
        n = num1.size();
        int m = num2.size();
        int i = n-1, j = m-1, carry = 0;
        string ans;
        
        while(i > -1 || j>-1 || carry){
            int temp1 = i > -1 ? num1[i] - '0' : 0;
            int temp2 = j > -1 ? num2[j] - '0' : 0;
            int num = temp1 + temp2 + carry;
            ans += '0' + num % 10;
            carry = num / 10;
            i--;
            j--;
        }
        
        reverse(ans.begin(), ans.end());
        for(i = 0; i<ans.length(); i++){
            if(ans[i] !='0'){
                break;
            }
        }
        
        return ans.substr(i);
    }
};