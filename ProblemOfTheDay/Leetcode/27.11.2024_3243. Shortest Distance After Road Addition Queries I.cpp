/*
Problem Link: https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i?envType=daily-question&envId=2024-11-27
*/

/*3243. Shortest Distance After Road Addition Queries I

You are given an integer n and a 2D integer array queries.

There are n cities numbered from 0 to n - 1. Initially, there is a unidirectional road from city i to city i + 1 for all 0 <= i < n - 1.

queries[i] = [ui, vi] represents the addition of a new unidirectional road from city ui to city vi. After each query, you need to find the length of the shortest path from city 0 to city n - 1.

Return an array answer where for each i in the range [0, queries.length - 1], answer[i] is the length of the shortest path from city 0 to city n - 1 after processing the first i + 1 queries.

 

Example 1:

Input: n = 5, queries = [[2,4],[0,2],[0,4]]

Output: [3,2,1]

Explanation:



After the addition of the road from 2 to 4, the length of the shortest path from 0 to 4 is 3.



After the addition of the road from 0 to 2, the length of the shortest path from 0 to 4 is 2.



After the addition of the road from 0 to 4, the length of the shortest path from 0 to 4 is 1.

Example 2:

Input: n = 4, queries = [[0,3],[0,2]]

Output: [1,1]

Explanation:



After the addition of the road from 0 to 3, the length of the shortest path from 0 to 3 is 1.



After the addition of the road from 0 to 2, the length of the shortest path remains 1.

 

Constraints:

3 <= n <= 500
1 <= queries.length <= 500
queries[i].length == 2
0 <= queries[i][0] < queries[i][1] < n
1 < queries[i][1] - queries[i][0]
There are no repeated roads among the queries.

*/

//Approach-1
class Solution {
public:
    int bfs(int n, unordered_map<int, vector<int>>& adj){
        queue<int> que; 
        que.push(0);
        vector<bool> visited(n, false);

        visited[0] = true;
    
        int level = 0;
        while(!que.empty()){
            int size = que.size();
            while(size--){
                int node = que.front();
                que.pop();
                
                if(node == n-1){
                    return level;
                }

                for(int& neighbour : adj[node]){
                    if(!visited[neighbour]){
                        que.push(neighbour);
                        visited[neighbour] = true;
                    }
                }
            }
            level++;
        }
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        for(int i=0; i<=n-2; i++){
            adj[i].push_back(i+1);
        }

        vector<int> result;

        for(auto& query : queries){
            int u = query[0];
            int v = query[1];

            adj[u].push_back(v);
            int d = bfs(n, adj);
            result.push_back(d);
        }

        return result;
    }
};

//Approach-2
#define p pair<int, int>
class Solution {
public:
    int dijkstra(int n, unordered_map<int, vector<p>>& adj){
        vector<int> result(n, INT_MAX);
        result[0] = 0;
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, 0});
        
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            if(node == n-1){
                return result[n-1];
            }

            for(auto& P : adj[node]){
                int adjNode = P.first;
                int wt = P.second;
                if(d+wt < result[adjNode]){
                    result[adjNode] = d + wt;
                    pq.push({d+wt, adjNode});
                }
            }
        }
        return result[n-1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, vector<p>> adj;
        for(int i=0; i<=n-2; i++){
            adj[i].push_back({i+1, 1});
        }

        vector<int> result;

        for(auto& query : queries){
            int u = query[0];
            int v = query[1];

            adj[u].push_back({v, 1});
            int d = dijkstra(n, adj);
            result.push_back(d);
        }

        return result;
    }
};