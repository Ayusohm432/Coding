/*
Problem Link: https://unstop.com/code/practice/519321
*/

/*Two-Digit Max Number

Problem Statement
You are given an array of integers arr[] of size N. Your task is to find the two smallest distinct two-digit numbers from the array, rearrange them in such a way that the largest possible number is formed, and then return that number. If there are no two-digit numbers or if there are fewer than two distinct two-digit numbers, return 0.

Note: After identifying the required two-digit numbers, you need to rearrange the digit in such a way that the largest number is formed.

Input Format
The first line of input contains an integer N, the size of the array.

The second line of input contains an array of N integers arr[] each separated by space.

Output Format
Print a single integer representing the largest possible number formed by rearranging the digit of two smallest distinct two-digits number.

Constraints
1 <= N <= 10^7

1 <= arr[i] <= 10^5

Sample Testcase 0
Testcase Input
6
24 22 4 43 44 4
Testcase Output
4222
Explanation
The array contains the numbers: 24, 22, 4, 43, 44, 4.
The two-digit numbers in the array are 24, 22, 43, 44.
After removing duplicates, the distinct two-digit numbers are 24, 22, 43, 44.
The two smallest distinct two-digit numbers are 22 and 24.
We rearrange the digits of these two numbers to form the largest possible number. The combined digits are 2, 2, 2, 4.
Sorting these digits in descending order results in 4222.

Sample Testcase 1
Testcase Input
6
123 768 2 3 21 21
Testcase Output
0
Explanation
The array contains the numbers: 123, 768, 2, 3, 21, 21.
We need to find two distinct two-digit numbers.
The only two-digit number in the array is 21, but it repeats and is not distinct.
Since there are fewer than two distinct two-digit numbers, the output is 0.

*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void user_logic(int N, std::vector<int> &arr) {
    /*
    Write your logic here.
    Parameters:
        N (int): Size of the array
        arr (list): List of N integers
    Returns:
        int: The largest possible number formed by rearranging the digits of two smallest distinct two-digit numbers
    */
    set<int> st;
    for(int i=0; i<N; i++){
        if(arr[i] > 9 && arr[i] < 100){
            st.insert(arr[i]);
        }
    }

    if(st.size() < 2){
        cout<<0;
        return;
    }

    vector<int> nums(4, 0);

    auto it = st.begin();
    int first = *it;
    int second = 0;
    ++it;
    if(it != st.end()){
        second = *it;
    }
    int pos = 0;
    while(first > 0){
        nums[pos]  = first % 10;
        first = first / 10;
        pos++;
    }

    while(second > 0){
        nums[pos] = second % 10;
        second /= 10;
        pos++;
    }

    sort(nums.begin(), nums.end(), greater<int>());

    int result = 0;
    for(int i=0; i<4; i++){
        result = (result*10) + nums[i];
    }

    cout<<result;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    
    user_logic(N, arr);
    return 0;
}

