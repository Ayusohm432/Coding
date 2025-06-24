/*
Problem Link: https://www.geeksforgeeks.org/problems/minimum-sum4058/1
*/

/*Minimum sum

Given an array arr[ ] consisting of digits, your task is to form two numbers using all the digits such that their sum is minimized. Return the minimum possible sum as a string with no leading zeroes.

Examples :

Input: arr[] = [6, 8, 4, 5, 2, 3]
Output: "604"
Explanation: The minimum sum is formed by numbers 358 and 246.
Input: arr[] = [5, 3, 0, 7, 4]
Output: "82"
Explanation: The minimum sum is formed by numbers 35 and 047.
Input: arr[] = [9, 4]
Output: "13"
Explanation: The minimum sum is formed by numbers 9 and 4.
Constraints:
2 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 9

*/

class Solution {
    string addStrings(string num1, string num2){
        string result;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        
        while(i >=0 || j >= 0 || carry){
            int sum = carry;
            if(i >= 0){
                sum += num1[i--] - '0';
            }
            if(j >= 0){
                sum += num2[j--] - '0';
            }
            carry = sum / 10;
            result += (sum % 10) + '0';
        }
        reverse(result.begin(), result.end());
        return result;
    }
  public:
    string minSum(vector<int> &arr) {
        // code here
        vector<int> freq(10, 0);
        for(int i=0; i<arr.size(); i++){
            freq[arr[i]]++;
        }
        
        string num1 = "";
        string num2 = "";
        int index = 0;
        int i = 0;
        
        while(i < 10){
            while(freq[i] > 0){
                if(index % 2 == 0 && i != 0){
                    num1 += i + '0';
                }else if(i != 0){
                    num2 += i + '0';
                }
                index++;
                freq[i]--;
            }
            i++;
        }
        return addStrings(num1, num2);
    }
};