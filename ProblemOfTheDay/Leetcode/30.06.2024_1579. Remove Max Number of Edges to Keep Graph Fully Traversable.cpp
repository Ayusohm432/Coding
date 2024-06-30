/*
Problem Link :- https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/?envType=daily-question&envId=2024-06-30
*/

/*1579. Remove Max Number of Edges to Keep Graph Fully Traversable

    Alice and Bob have an undirected graph of n nodes and three types of edges:

    Type 1: Can be traversed by Alice only.
    Type 2: Can be traversed by Bob only.
    Type 3: Can be traversed by both Alice and Bob.
    Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.

    Return the maximum number of edges you can remove, or return -1 if Alice and Bob cannot fully traverse the graph.

    

    Example 1:



    Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
    Output: 2
    Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still be fully traversable by Alice and Bob. Removing any additional edge will not make it so. So the maximum number of edges we can remove is 2.
    Example 2:



    Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
    Output: 0
    Explanation: Notice that removing any edge will not make the graph fully traversable by Alice and Bob.
    Example 3:



    Input: n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
    Output: -1
    Explanation: In the current graph, Alice cannot reach node 4 from the other nodes. Likewise, Bob cannot reach 1. Therefore it's impossible to make the graph fully traversable.
    

    

    Constraints:

    1 <= n <= 105
    1 <= edges.length <= min(105, 3 * n * (n - 1) / 2)
    edges[i].length == 3
    1 <= typei <= 3
    1 <= ui < vi <= n
    All tuples (typei, ui, vi) are distinct.

*/
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

class DSU{
    public:
        vector<int> parent;
        vector<int> rank;
        int components;

        DSU(int n){
            parent.resize(n+1);
            
            for(int i=1 ; i<=n ; i++){
                parent[i] = i;
            }

            rank.resize(n+1);
            components = n;
        }

        int find(int x){
            if(x == parent[x]){
                return x;
            }
            return parent[x] = find(parent[x]);
        }

        void Union(int x , int y){
            int x_parent = find(x);
            int y_parent = find(y);

            if(x_parent == y_parent){
                return;
            }
            if(rank[x_parent] > rank[y_parent]){
                parent[y_parent] = x_parent;
            }
            else if(rank[x_parent] < rank[y_parent]){
                parent[x_parent] = y_parent;
            }
            else{
                parent[x_parent] = y_parent;
                rank[y_parent]++;
            }
            components--;
        }

        bool isSingleComponent(){
            return components == 1;
        }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU Alice(n);
        DSU Bob(n);

        auto lambda = [](vector<int>& vec1 , vector<int>& vec2){
            return vec1[0] > vec2[0];
        };

        sort(begin(edges) , end(edges) , lambda);

        int edgeCount = 0;
        
        for(auto& vec : edges){
            int type = vec[0];
            int u = vec[1];
            int v = vec[2];

            if(type == 3){
                bool edgeAdded = false;
                if(Alice.find(u) != Alice.find(v)){
                    Alice.Union(u,v);
                    edgeAdded = true;
                }

                if(Bob.find(u) != Bob.find(v)){
                    Bob.Union(u,v);
                    edgeAdded = true;
                }
                
                if(edgeAdded == true){
                    edgeCount++;
                }
            }
            else if(type == 2){
                if(Bob.find(u) != Bob.find(v)){
                    Bob.Union(u,v);
                    edgeCount++;
                }
            }
            else{
                if(Alice.find(u) != Alice.find(v)){
                    Alice.Union(u,v);
                    edgeCount++;
                }
            }
        }

        if(Alice.isSingleComponent() && Bob.isSingleComponent()){
            return edges.size()-edgeCount;
        }

        return -1;
    }
};
int main(){

}
