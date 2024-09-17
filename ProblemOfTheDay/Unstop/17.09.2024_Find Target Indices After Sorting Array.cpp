/*
Problem Link : https://unstop.com/code/practice/250510
*/

/*Find Target Indices After Sorting Array


Problem Statement
Marco likes numbers a lot. His friend Shyam gives him a number array A  of length N and a target value K. He first asks him to sort the array A and to tell him the indices of the numbers where the target value will match with that element.

Help Marco solve this crazy problem and print out the indices of target value K in array A

Input Format
The first line contains the integer N, representing the number of inputs.

The second line contains N space-separated integers, representing the values of array A.

The third line contains an integer K representing target value.

Output Format
The first line contains the integer M; the number of indexes matches the target value.

The second line contains M space-separated integers denoting the indexes of target value.

Constraints
1 <= N <= 10^5

1 <= A[i], K <= 10^5

 
Sample Testcase 0
Testcase Input
5
1 2 5 2 3
3
Testcase Output
1
3
Explanation
After sorting, A is [1,2,2,3,5]. 

The index where A[i] == 3 is 3.

Sample Testcase 1
Testcase Input
5
1 2 5 2 3
2
Testcase Output
2
1 2
Explanation
After sorting, A is [1,2,2,3,5]. 

The indices where A[i] == 2 are 1 and 2.

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int K;
    cin >> K;

    sort(A.begin(), A.end());

    vector<int> indices;
    for (int i = 0; i < N; i++) {
        if (A[i] == K) {
            indices.push_back(i);
        }
    }

    cout << indices.size() << endl;
    for (int i = 0; i < indices.size(); i++) {
        cout << indices[i] << " ";
    }
    cout << endl;

    return 0;
}