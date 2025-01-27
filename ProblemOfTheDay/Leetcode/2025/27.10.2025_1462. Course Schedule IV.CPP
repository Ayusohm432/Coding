/*
Problem Link: https://leetcode.com/problems/course-schedule-iv?envType=daily-question&envId=2025-01-27
*/

/*1462. Course Schedule IV

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.

For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.
Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.

You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.

Return a boolean array answer, where answer[j] is the answer to the jth query.

 

Example 1:


Input: numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
Output: [false,true]
Explanation: The pair [1, 0] indicates that you have to take course 1 before you can take course 0.
Course 0 is not a prerequisite of course 1, but the opposite is true.
Example 2:

Input: numCourses = 2, prerequisites = [], queries = [[1,0],[0,1]]
Output: [false,false]
Explanation: There are no prerequisites, and each course is independent.
Example 3:


Input: numCourses = 3, prerequisites = [[1,2],[1,0],[2,0]], queries = [[1,0],[1,2]]
Output: [true,true]
 

Constraints:

2 <= numCourses <= 100
0 <= prerequisites.length <= (numCourses * (numCourses - 1) / 2)
prerequisites[i].length == 2
0 <= ai, bi <= numCourses - 1
ai != bi
All the pairs [ai, bi] are unique.
The prerequisites graph has no cycles.
1 <= queries.length <= 104
0 <= ui, vi <= numCourses - 1
ui != vi

*/

//Approach - 1
class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& adj, vector<bool>& visited, int src, int target) {
        visited[src] = true;

        if (src == target) {
            return true;
        }

        bool isPrerequisite = false;
        for (auto adjNode : adj[src]) {
            if (!visited[adjNode]) {
                isPrerequisite = isPrerequisite || dfs(adj, visited, adjNode, target);
            }
        }
        return isPrerequisite;
    }

    void preprocess(int numCourses, unordered_map<int, vector<int>>& adjList, vector<vector<bool>>& isPrerequisite) {
        for (int u = 0; u < numCourses; u++) {
            for (int v = 0; v < numCourses; v++) {
                if (u != v) {
                    vector<bool> visited(numCourses, false);
                    if (dfs(adjList, visited, u, v)) {
                        isPrerequisite[u][v] = true;
                    }
                }
            }
        }
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adjList;
        for (auto edge : prerequisites) {
            adjList[edge[0]].push_back(edge[1]);
        }

        vector<vector<bool>> isPrerequisite(numCourses, vector<bool>(numCourses, false));
        preprocess(numCourses, adjList, isPrerequisite);

        int Q = queries.size();
        vector<bool> result(Q);

        for(int i = 0; i < Q; i++) {
            int u = queries[i][0]; 
            int v = queries[i][1];
            result[i] = isPrerequisite[u][v];
        }

        return result;
    }
};

//Approach - 2
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for (auto &edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> que;
        for (int i = 0; i < numCourses; i++) {
            if (!indegree[i]) {
                que.push(i);
            }
        }

        unordered_map<int, unordered_set<int>> mp;
        while (!que.empty()) {
            int node = que.front();
            que.pop();

            for (auto &ngbr : adj[node]) {
                mp[ngbr].insert(node);
                for (auto &prereq : mp[node]) { 
                    mp[ngbr].insert(prereq);
                }

                indegree[ngbr]--;
                if (!indegree[ngbr]) {
                    que.push(ngbr);
                }
            }
        }

        int Q = queries.size();
        vector<bool> result(Q, false);
        for (int i = 0; i < Q; i++) {
            int src  = queries[i][0];
            int dest = queries[i][1];

            bool isReachable = mp[dest].contains(src);
            result[i] = isReachable;
        }

        return result;
    }
};