/*
Problem Link : https://unstop.com/code/practice/250276
*/

/*List of Toys

Problem Statement
A toy manufacturing factory produced N toys on a day. The manager has a list of product IDs and another list containing the sizes of the corresponding toys, each of length N. In other words, the i-th integer in the product IDs list represents the product ID of the i-th toy, and the i-th integer in the sizes list represents the size of the i-th toy.

However, the manager accidentally combined these lists by placing the product IDs list in front of the sizes list, resulting in a single list of 2N elements.

You are an employee, and the manager wants you to recover the data and present it as another list of 2N elements such that the product ID of each toy is followed by its size.

Input Format
The first line of the input contains a single integer N, representing the number of toys produced.

The second line contains 2*N space-separated integers a1, a2, …, an, b1, b2, …, bn – the merged list given to you by the manager.

Output Format
Print 2*N space-separated integers representing the list wanted by the manager

Constraints
1 <= N <= 105

1 <= ai, bi<= 100

Sample Testcase 0
Testcase Input
4
1 2 3 4 4 3 2 1
Testcase Output
1 4 2 3 3 2 4 1
Explanation
As per the question,


The product ID array would be: 1 2 3 4
The size array will be: 4 3 2 1


Merging them as per the condition we get: 1 4 2 3 3 2 4 1

Sample Testcase 1
Testcase Input
3
2 5 1 3 4 7
Testcase Output
2 3 5 4 1 7
Explanation
As per the question,


The product ID array would be: 2 5 1
The size array will be: 3 4 7


Merging them as per the condition we get: 2 3 5 4 1 7

*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin>>N;

    vector<int> arr(2*N);

    for(int i=0 ; i<2*N ; i++){
        cin>>arr[i];
    }

    for(int i=0 , j=N ; i<N , j<2*N ; i++ , j++){
        cout<<arr[i]<<" "<<arr[j]<<" ";
    }


    return 0;
}