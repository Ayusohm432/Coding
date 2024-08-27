/*
Problem link : https://leetcode.com/problems/path-with-maximum-probability/?envType=daily-question&envId=2024-08-27
*/

/*1514. Path with Maximum Probability

You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.

 

Example 1:



Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
Example 2:



Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
Output: 0.30000
Example 3:



Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
Output: 0.00000
Explanation: There is no path between 0 and 2.
 

Constraints:

2 <= n <= 10^4
0 <= start, end < n
start != end
0 <= a, b < n
a != b
0 <= succProb.length == edges.length <= 2*10^4
0 <= succProb[i] <= 1
There is at most one edge between every two nodes.


*/

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

class Solution {
    typedef pair<double , int> P;
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int , vector<pair<int , double>>> adj;

        vector<double> result(n , 0);

        for(int i=0 ; i < edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];

            adj[u].push_back({v , prob});
            adj[v].push_back({u , prob});
        }

        priority_queue<P> pq;

        result[start_node] = 1;
        pq.push({1.0 , start_node});

        while(!pq.empty()){
            int currNode = pq.top().second;
            double currProb = pq.top().first;
            pq.pop();

            for(auto& temp : adj[currNode]){
                double adjProb = temp.second;
                int adjNode = temp.first;

                if(result[adjNode] < currProb*adjProb){
                    result[adjNode] = currProb*adjProb;
                    pq.push({result[adjNode] , adjNode});
                }
            }
        }
        return result[end_node];
    }
};



int main(){
    Solution solution;
    int n = 3;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
    vector<double> succProb = {0.5, 0.5, 0.5};
    int start_node = 0;
    int end_node = 2;
    cout << solution.maxProbability(n, edges, succProb, start_node, end_node) <<endl;
    return 0;
}