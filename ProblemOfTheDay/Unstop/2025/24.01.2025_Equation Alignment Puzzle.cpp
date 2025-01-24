/*
Problem Link: https://unstop.com/code/practice/506040
*/

/*Equation Alignment Puzzle

Problem Statement
Aryan has been given N distinct 2D points (xi, yi) from Akarsh. Aryan wants to determine the maximum number of these points that can lie on a curve represented by a specific mathematical equation.

The equation is of the form y = ax^2 + bx + c, where a, b, and c are real constants.
Help Aryan find the largest subset of points that satisfy the given equation.

Assumptions:

The points provided are all unique.
Input Format
The first line contains a single integer N, the number of distinct 2D points.

Each of the next N lines contains two space-separated integers xi and yi, the coordinates of the points.

The last line contain 3 space separated integers, A, B, C, representing the constans.

Output Format
Output a single integer, the maximum number of points that lie on the curve y = ax^2 + bx + c.

Constraints
1 <= N <= 10^5

-10^6 <= xi, yi <= 10^6

Sample Testcase 0
Testcase Input
4
1 3
2 7
3 13
4 21
1 1 1
Testcase Output
4
Explanation
We have a = 1; b = 1; c = 1.
The equation will be: x^2 + x + 1.
After calculation, we get 4 points satisfying the equation.

Sample Testcase 1
Testcase Input
4
-1 -1
0 1
1 -3
2 7
1 1 1
Testcase Output
2
Explanation
We have a = 1; b = 1; c = 1.
The equation will be: x^2 + x + 1.
After calculation, we get 2 points satisfying the equation.

*/

#include <iostream>
#include <vector>
using namespace std;

void max_points_on_curve(int N, std::vector<std::pair<int, int>> &points, int a, int b, int c)
{
    int x = 0;
    for (int i = 0; i < N; i++)
    {
        int y = points[i].first;
        x += (a * y * y + b * y + c == points[i].second);
    }
    cout << x;
}

int main()
{
    int N;
    std::cin >> N;
    std::vector<std::pair<int, int>> points(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> points[i].first >> points[i].second;
    }
    int a, b, c;
    std::cin >> a >> b >> c;
    max_points_on_curve(N, points, a, b, c);
    return 0;
}