/*
Problem Link: https://www.geeksforgeeks.org/problems/k-closest-points-to-origin--172242/1
*/

/*K Closest Points to Origin

Given an array of points where each point is represented as points[i] = [xi, yi] on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance, defined as:

sqrt( (x2 - x1)2 + (y2 - y1)2 )

Note: You can return the k closest points in any order, driver code will sort them before printing.

Examples:

Input: k = 2, points[] = [[1, 3], [-2, 2], [5, 8], [0, 1]]
Output: [[-2, 2], [0, 1]]
Explanation: The Euclidean distances from the origin are:
Point (1, 3) = sqrt(10)
Point (-2, 2) = sqrt(8)
Point (5, 8) = sqrt(89)
Point (0, 1) = sqrt(1)
The two closest points to the origin are [-2, 2] and [0, 1].
Input: k = 1, points = [[2, 4], [-1, -1], [0, 0]]
Output: [[0, 0]]
Explanation: The Euclidean distances from the origin are:
Point (2, 4) = sqrt(20)
Point (-1, -1) = sqrt(2)
Point (0, 0) = sqrt(0)
The closest point to origin is (0, 0).
Constraints:

1 <= k <= points.size() <= 105
-104 <= xi, yi <= 104

*/

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        // Your code here
        vector<vector<int>> res;
        priority_queue<pair<int, pair<int, int>>> maxHeap;
        for (int i = 0; i < k; i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            int val = x * x + y * y;
            maxHeap.push({val, {x, y}});
        }
        for (int i = k; i < points.size(); i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            int val = x * x + y * y;
            if (maxHeap.top().first > val)
            {
                maxHeap.pop();
                maxHeap.push({val, {x, y}});
            }
        }
        while (!maxHeap.empty())
        {
            auto val = maxHeap.top();
            maxHeap.pop();
            res.push_back({val.second.first, val.second.second});
        }
        return res;
    }
};