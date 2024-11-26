/*
Problem Link: https://unstop.com/code/practice/307497
*/

/*Substrate of maximum and minimum value

Problem Statement
Given an array of integers,

Your task is to find the mean of both the maximum and minimum values present in the array, round down to nearest integer.

Input Format
First line contains size of array 

Another line contains elements of array in space-separated integer.

Output Format
To find the Substrate the maximum and minimum value in array

Constraints
1 <=  SIZE <= 10^2

Sample Testcase 0
Testcase Input
6

2 5 6 1 8 9
Testcase Output
5
Explanation

The program first reads the size of the array, which is 6.

It then reads the elements of the array: 2, 5, 6, 1, 8, 9.

The program initializes min to Integer.MAX_VALUE and max to Integer.MIN_VALUE.

It iterates through the array and updates the min and max values.

In this case, the minimum value is 1, and the maximum value is 9.



It calculates the mean as (min + max) / 2, which is (1 + 9) / 2 = 5.

The program prints the mean, which is 5.


Therefore, the output for the given sample input is 5.

Sample Testcase 1
Testcase Input
2

3 4
Testcase Output
3
Explanation

Maximum value (max): 4

Minimum value (min): 3


The mean is calculated as (min + max) / 2 = (3 + 4) / 2 = 7 / 2 = 3.5.


The mean (3.5) is printed as an integer, which truncates the decimal part, resulting in the output 3.

*/

#include <iostream>
#include <climits>
using namespace std;

int findMeanOfMaxMin(int size, int arr[]) {
    int max = INT_MIN, min = INT_MAX;
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    return (max + min) / 2;
}

int main() {
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    int mean = findMeanOfMaxMin(size, arr);
    cout << mean << endl;
    return 0;
}
