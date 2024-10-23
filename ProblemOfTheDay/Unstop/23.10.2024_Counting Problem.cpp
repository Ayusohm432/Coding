/*
Problem Link : https://unstop.com/code/practice/303669
*/

/*Counting Problem

Problem Statement
Bob loves to play with numbers. He has N numbers, and he has to count the unique numbers according to the given constraints:

A number is considered unique if it is the maximum number present in the collection and has no repetition (i.e., it appears exactly once).
If the maximum number is found to be unique, then Bob counts it as a unique number and removes it from the collection, and inserts half of the number, i.e., number/2 (if number/2 becomes 0, don’t insert it in the collection) in the collection

Else if the maximum number is not found to be unique, then he removes all occurrence of that number from the set.

Bob counts the unique numbers until the collection becomes empty. Can you return the number of unique numbers present in Bob's collection? 

Note: The count of unique numbers can exceed the size of the array as you are inserting number/2 in some cases.

Input Format
The first line of input contains an integer N, representing the size of the array.

The second line of input contains N space-separated integers representing the elements of the array.

Output Format
Display a single integer representing count of unique numbers according to the given constraints.

Constraints
1 <= N <= 10^6.

0<= A[i] <= 10^6.

Sample Testcase 0
Testcase Input
5
1 2 3 3 4
Testcase Output
2
Explanation
Array is [1 2 3 3 4], The maximum number in the collection is 4, which is present in the array only once, so it is unique, remove 4 from the array and insert 4/2, i.e., 2 in the array. 
Now the array becomes [1 2 3 3 2], The maximum number in the collection in the array is now 3, but it is present twice, so it will not be unique, remove both the 3 from the array. 
Now the array becomes [1 2 2], The maximum number in the collection in the array is now 2, but it is present twice, so it will not be unique, remove both the 2 from the array. 
Now the array becomes [1], The maximum number in the collection is 1, which is present in the array only once, so it is unique, remove 1 from the array but do not insert 1/2, i.e., 0(floor value) in the array. 
So, several unique numbers in the collection is 2.

Sample Testcase 1
Testcase Input
1
1
Testcase Output
1
Explanation
The maximum number in the collection is 1, which is present in the array only once, so it is unique, remove 1 from the array but do not insert 1/2, i.e., 0 in the array.
So, a number of unique numbers in the collection is 1.


*/


#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<int, int> mp;

    // Read input and count occurrences of each number
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        mp[t]++;
    }

    priority_queue<int> pq;
    
    // Push all unique numbers into the priority queue
    for (auto &it : mp) {
        pq.push(it.first);
    }

    int cnt = 0;

    // Process the numbers
    while (!pq.empty()) {
        int elem = pq.top();
        pq.pop();

        if (mp[elem] > 1) {
            // If the number is not unique, remove all occurrences
            mp.erase(elem);
        } else if (mp[elem] == 1) {
            // If the number is unique
            cnt++;
            if ((elem / 2) != 0) {
                // Insert half of the number into the collection
                pq.push(elem / 2);
                mp[elem / 2]++;
            }
            mp.erase(elem);
        }
    }

    cout << cnt << endl;
    return 0;
}