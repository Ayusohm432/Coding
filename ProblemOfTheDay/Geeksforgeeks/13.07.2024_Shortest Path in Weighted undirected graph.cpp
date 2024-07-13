/*
Problem Link :- https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
*/

/*Shortest Path in Weighted undirected graph

You are given a weighted undirected graph having n vertices numbered from 1 to n and m edges along with their weights. Find the shortest path between the vertex 1 and the vertex n,  if there exists a path, and return a list of integers whose first element is the weight of the path, and the rest consist of the nodes on that path. If no path exists, then return a list containing a single element -1.

The input list of edges is as follows - {a, b, w}, denoting there is an edge between a and b, and w is the weight of that edge.

Note: The driver code here will first check if the weight of the path returned is equal to the sum of the weights along the nodes on that path, if equal it will output the weight of the path, else -2. In case the list contains only a single element (-1) it will simply output -1. 

Examples :

Input: n = 5, m= 6, edges = [[1, 2, 2], [2, 5, 5], [2, 3, 4], [1, 4, 1], [4, 3, 3], [3, 5, 1]]
Output: 5
Explanation: Shortest path from 1 to n is by the path 1 4 3 5 whose weight is 5. 
Input: n = 2, m= 1, edges = [[1, 2, 2]]
Output: 2
Explanation: Shortest path from 1 to 2 is by the path 1 2 whose weight is 2. 
Input: n = 2, m= 0, edges = [ ]
Output: -1
Explanation: Since there are no edges, so no answer is possible.
Expected Time Complexity: O(m* log(n))
Expected Space Complexity: O(n+m)

Constraint:
2 <= n <= 106
0 <= m <= 106
1 <= a, b <= n
1 <= w <= 105


*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<int> parent(n) , distance(n , 1e9);
        
        for(int i=0 ; i<n ; i++){
            parent[i] = i;
        }
        
        vector<pair<int,int>> adj[n];
        
        for(auto it : edges){
            int u = it[0]-1;
            int v = it[1]-1;
            int wt = it[2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        queue<vector<int>> q;
        distance[0] = 0;
        q.push({0,0});
        while(q.size() > 0){
            vector<int> it = q.front();
            int node_wt = it[0];
            int node = it[1];
            q.pop();
            for(auto it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                if(distance[adjNode] > wt + node_wt){
                    distance[adjNode] = wt + node_wt;
                    parent[adjNode] = node;
                    q.push({distance[adjNode] , adjNode});
                }
            }
        }
        if(distance[n-1] == 1e9){
            return {-1};
        }
        
        vector<int> path;
        int r = n-1;
        while(r != 0 and r != parent[r]){
            path.push_back(r+1);
            r = parent[r];
        }
        path.push_back(1);
        reverse(path.begin() , path.end());
        
        vector<int> ans;
        ans.push_back(distance[n-1]);
        for(auto it : path){
            ans.push_back(it);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends