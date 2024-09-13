/*
Problem link : https://unstop.com/code/practice/250286
*/

/*Push and Pop

Problem Statement
Ankit is given an empty array target and an integer N.

He needs to construct the target array by reading numbers sequentially from the list [1, 2, 3, ..., N].

To build the target array, he can perform the following operations:

"Push": Reads the next element from the list and adds it to the array.
"Pop": Removes the last element added to the array.
He can only "Pop" the most recently "Pushed" element. If the target array is complete, he stops reading more elements. It is guaranteed that such a sequence of operations always exists.

Your task is to help Ankit determine the list of operations needed to build the target array.

Input Format
The first line contains an integer M, the number of elements in the target array.

The second line contains M space-separated integers representing the elements of the target array.

The third line contains the integer N.

Output Format
Output a space-separated string representing the sequence of operations.

 
Constraints
1 <= M, N, target[i] <= 10^5

M <= N

Sample Testcase 0
Testcase Input
1
1
1
Testcase Output
Push
Explanation
Initially, the array is empty. - Push 1: Target array becomes [1]

Sample Testcase 1
Testcase Input
3
1 3 2
3
Testcase Output
 Push Push Pop Push Push
Explanation
- Push 1: Target array becomes [1]


- Push 2: Target array becomes [1, 2]


- Pop: Target array becomes [1]


- Push 3: Target array becomes [1,3]


- Push 2: Target array becomes [1,3,2]

*/

#include <iostream>
#include <vector>
using namespace std;

vector<string> buildTargetArray(vector<int>& target, int N) {
    vector<string> operations;
    int current = 1;  // Start from 1 and go up to N
    for (int i = 0; i < target.size(); i++) {
        while (current < target[i]) {
            operations.push_back("Push");
            operations.push_back("Pop");
            current++;
        }
        // Push the target number into the array
        operations.push_back("Push");
        current++;
    }
    return operations;
}

int main() {
    int M, N;
    cin >> M;
    vector<int> target(M);
    for (int i = 0; i < M; i++) {
        cin >> target[i];
    }
    cin >> N;

    vector<string> result = buildTargetArray(target, N);
    
    for (const string& op : result) {
        cout << op << " ";
    }

    return 0;
}
