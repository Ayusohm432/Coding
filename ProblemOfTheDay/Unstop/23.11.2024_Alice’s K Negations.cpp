/*
Problem link : https://unstop.com/code/practice/261363
*/

/*Alice’s K Negations

Problem Statement
Alice is playing a game in which she has been given several strings and has been provided with a list of numbers. Robert would burst a balloon K times. Each time Robert burst a balloon, Robert is to Replace the list numbers by the additive inverse of the number.

When completed, Alice would get the maximum possible sum of Alice's numbers as prize money.

Print the prize money Alice would get.

Input Format
The first line contains two space separated integers N and K.

The second line contains N spce-seprated integers denoting the elements of the array.

Output Format
Display an integer denoting the maximum sum Alice can get after K operations.

Constraints
1 ≤ N,K ≤ 105

-109 ≤ Ai ≤ 109

Sample Testcase 0
Testcase Input
4 3
9 8 8 5
Testcase Output
20
Explanation
1. Replace (5) by (-5), array becomes {9,8,8,-5}


2. Replace (-5) by -(-5), array becomes {9,8,8,5}


3. Replace (5) by (-5), array becomes {9,8,8,-5}


Here, the sum of the array is 20 which is the maximum possible.

Sample Testcase 1
Testcase Input
5 4
-2 0 5 -1 2
Testcase Output
10
Explanation
1. Replace (-2) by -(-2), array becomes {2, 0, 5, -1, 2}


2. Replace (-1) by -(-1), array becomes {2, 0, 5, 1, 2}


3. Replace (0) by -(0), array becomes {2, 0, 5, 1, 2}


4. Replace (0) by -(0), array becomes {2, 0, 5, 1, 2}


Here, the sum of the array is 10 which is the maximum possible.

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    for (int i = 0; i < N && K > 0; i++) {
        if (arr[i] < 0) {
            arr[i] = -arr[i];
            K--;
        }
    }
    
    if (K > 0) {
        if (K % 2 == 1) {
            int min_index = min_element(arr.begin(), arr.end()) - arr.begin();
            arr[min_index] = -arr[min_index];
        }
    }
    
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
    }
    
    cout << sum << endl;
    return 0;
}
