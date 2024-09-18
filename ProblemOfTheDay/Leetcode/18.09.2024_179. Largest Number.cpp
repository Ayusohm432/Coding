/*
Problem Link : https://leetcode.com/problems/largest-number/
*/

/*179. Largest Number

Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 109


*/
//Approach-1
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        
        for(int& num : nums){
            str.push_back(to_string(num));
        }
        
        sort(str.begin(), str.end(), [](string a, string b) {
            return a + b > b + a && a + b != b + a;
        });
        
        string result;
        for(int i=0 ; i<str.size() ; i++){
            result += str[i];
        }
        
        // Remove leading zeros
        size_t start = 0;
        while (start < result.size() && result[start] == '0') {
            start++;
        }
        if (start == result.size()) {
            return "0";
        }
        return result.substr(start);
    }
};

//Approach-2
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto myComparator = [](int& a , int& b){
            string s1 = to_string(a);
            string s2 = to_string(b);

            return (s1+s2) > (s2+s1);
        };

        sort(nums.begin() , nums.end() , myComparator);

        if(nums[0] == 0){
            return "0";
        }

        string result = "";

        for(int& num : nums){
            result += to_string(num);
        }

        return result;
    }
};