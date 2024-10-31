/*
Problem Link : https://unstop.com/code/practice/305319
*/

/*Pattern

Problem Statement
Bob gave you a matrix with N rows and 3 columns. Each row follows a specific mathematical pattern: the sum of the squares of the first two elements is equal to the third element. However, in one of the rows, one element is missing, represented by 0. Your task is to find the value of the missing element in that row.

Pattern:
For each row [a,b,c], the relationship is: a^2 + b^2 = c Where exactly one of the elements a, b, or c is 0 in exactly one row, and you need to calculate the missing value.

Note: a, b, c for every row is a natural number except for missing value case where either of them can be 0.

Input Format
The first line of input contains an integer N denoting the number of rows in the matrix.

The next N lines each contain 3 integers representing the elements of each row of the matrix. One of these rows will contain exactly one element as 0.

Output Format
Print the missing term from the row that contains the 0.

Constraints
1 <= N <= 10^8

1 <= a, b, c <= 10^4 (excluding the missing valu case)

Sample Testcase 0
Testcase Input
5
5 5 50
0 12 225
1 1 2
3 4 25
8 7 113
Testcase Output
9
Explanation
Here, the missing term position is at location 0. So, we have to calculate it from the third index-remaining index. 


225 - 12^2 = 81
And square root of 81 is 9.
Hence answer is 9.

Sample Testcase 1
Testcase Input
1
1 1 0
Testcase Output
2
Explanation
Here,the missing term is at 2 indexes. We can calculate it by adding the square of the first two index numbers.


1^1+1^1 =1+1 = 2


Hence, the answer is 2.



*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    int result;

    for(int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 0) {
            cout <<sqrt(c - b*b)<< endl;
        } 
        else if(b == 0) {
            cout << sqrt(c - a*a) << endl;
        } 
        else if(c == 0)
        {
            cout <<(a*a + b*b) << endl;
        }
    }
    return 0;
}