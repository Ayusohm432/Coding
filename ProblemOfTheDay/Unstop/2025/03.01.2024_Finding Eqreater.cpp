/*
Problem Link: https://unstop.com/code/practice/303867
*/

/*Finding Eqreater

Problem Statement
Our friend John has given us an array consisting of N integers. In each question John has given Bob a value X, to find an element Ai in the array which is either greater than or equal to X and such that the difference between Ai and X is as small as possible.

John will ask Bob Q such questions, and we need to help Bob answer them.

Note: Use fast i/o for the given problem.

Input Format
The first line contains t (1≤ t ≤100), the number of test cases.
The first line of each test case contains a single integer n (1≤n≤2⋅10^5) — the number of elements in the array.
The second line contains n integers a1,a2,…,an  (1 ≤ ai ≤10^9) — the initial value of element ai  
The Third line of each test case contains a single integer q (1≤q≤2⋅10^5) — the number of queries.
Then the following each q line contains a query, the value X.
The sum of n over all test cases doesn't exceed 2*10^5.

Output Format
Return a single integer Ai for each Query such that if Z =  Ai – X, then Z >= 0 and Z is minimized; if there does not exist any such integer, then return -1.
Constraints
1 <= T <= 100
1 <= N <= 2e^5
1 <=Q <= 2e^5
Sample Testcase 0
Testcase Input
2 
3
1 5 4
2 
1 
2
2 
1 6
1 
3
Testcase Output
1
4
6
Explanation
Test case 1:



For X = 1, we have A1 = 1, (A1-X) is the minimum possible difference possible which is zero.

For X = 2, we have A3 = 4, (A3-X) is the minimum possible difference possible which is two.


Test case 2:


For X = 3, we have A2 = 6, (A2-X) is the minimum possible difference possible which is three.

Sample Testcase 1
Testcase Input
1   
5
3 2 1 5 4
3
1
2
6
Testcase Output
1
2
-1
Explanation
Test case 1:



For X = 1, we have A3 = 1, (A3-X) is the minimum possible difference possible which is zero.

For X = 2, we have A2 = 2, (A2-X) is the minimum possible difference possible which is zero.

For X = 6, we don’t have a number greater than or equal to X present in the array.


*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
std::vector<int> user_logic(int n, std::vector<int>& arr, int q, std::vector<int>& queries) {
    /**
     * Write your logic here.
     * Parameters:
     *     n (int): Number of elements in the array
     *     arr (std::vector<int>): List of integers representing the array
     *     q (int): Number of queries
     *     queries (std::vector<int>): List of integers representing the queries
     * Returns:
     *     std::vector<int>: List of integers representing the results for each query
     */
    sort(arr.begin(), arr.end());
    vector<int> ans(q, -1);

    for(int i=0; i<q; i++){
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(arr[mid] >= queries[i]){
                ans[i] = arr[mid];
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }
    return ans;
}

int main() {
    int t;
    std::cin >> t;
    std::vector<int> results;
    
    for (int i = 0; i < t; ++i) {
        int n;
        std::cin >> n;
        std::vector<int> arr(n);
        for (int j = 0; j < n; ++j) {
            std::cin >> arr[j];
        }
        int q;
        std::cin >> q;
        std::vector<int> queries(q);
        for (int k = 0; k < q; ++k) {
            std::cin >> queries[k];
        }
        // Call user logic function
        std::vector<int> result = user_logic(n, arr, q, queries);
        results.insert(results.end(), result.begin(), result.end());
    }
    // Print all results for each query in each test case
    for (const int& res : results) {
        std::cout << res << std::endl;
    }
    return 0;
}
