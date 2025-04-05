/*
Problem Link: https://unstop.com/code/practice/260109
*/

/*Test Scores

Problem Statement
The exam scores for a class of N students have been released. The marks obtained by each student are stored in an array of scores[], where scores[i] represent the marks of the ith student.

As the class monitor, Ram is tasked with answering queries from the teacher. The teacher will ask Q queries, and for each query, Ram needs to determine how many students have scored at least X marks.

Your objective is to help Ram by finding the number of students who have scored at least X marks for each query.

Input Format
The first line contains two positive integers N, and Q, denoting the number of students and the number of queries, respectively.

This is followed by a line containing N integers, separated by space giving the scores of each student.

Then, Q lines follow where the ith line contains a single integer X.

Output Format
For each query, print a single integer representing the number of students who scored at least X marks.

Constraints
1 <= N, Q <= 2 * 10^5

1 <= X <= 10^9

1 <= scores[i] <= 10^9

Sample Testcase 0
Testcase Input
5 2
1 4 12 3 9
2
15
Testcase Output
4
0
Explanation
There are 5 students with scores [1, 4, 12, 3, 9].

The first query asks for the number of students who scored at least 2 marks. The students with scores [4, 12, 3, 9] meet this criterion, resulting in 4 students.

The second query asks for the number of students who scored at least 15 marks. No student meets this criterion, resulting in 0 students.
Therefore, the outputs are 4 and 0 respectively.

Sample Testcase 1
Testcase Input
4 1
2 3 1 4 
3
Testcase Output
2
Explanation
There are 4 students with scores [2, 3, 1, 4].
The query asks for the number of students who scored at least 3 marks.
The students with scores of 3 and 4 meet this criterion.
Therefore, the output is 2.

*/


//Approach - 1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int>& scores, int n, int num) {
    int low = 0, high = n - 1;
    int ans = n; 

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (scores[mid] >= num) {
            ans = mid;      
            high = mid - 1; 
        } else {
            low = mid + 1;  
        }
    }
    return ans;
}

vector<int> user_logic(int n, int q, vector<int> scores, vector<int> queries) {
    vector<int> results;
    sort(scores.begin(), scores.end());

    for (int i = 0; i < q; i++) {
        int idx = binarySearch(scores, n, queries[i]);
        int students = n - idx;
        results.push_back(students);
    }
    return results;
}

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> scores(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> scores[i];
    }
    std::vector<int> queries(q);
    for (int i = 0; i < q; ++i) {
        std::cin >> queries[i];
    }
    std::vector<int> results = user_logic(n, q, scores, queries);
    for (int result : results) {
        std::cout << result << std::endl;
    }
    return 0;
}

//Approach - 2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

std::vector<int> user_logic(int n, int q, std::vector<int> scores, std::vector<int> queries) {
    // Write your logic here.
    std::vector<int> results;
    sort(scores.begin(), scores.end());

    for(int i=0; i<q; i++){
        auto it = lower_bound(scores.begin(), scores.end(), queries[i]);
        int idx = it - scores.begin();
        int students = n - idx;
        results.push_back(students);
    }
    return results;
}

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> scores(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> scores[i];
    }
    std::vector<int> queries(q);
    for (int i = 0; i < q; ++i) {
        std::cin >> queries[i];
    }
    std::vector<int> results = user_logic(n, q, scores, queries);
    for (int result : results) {
        std::cout << result << std::endl;
    }
    return 0;
}