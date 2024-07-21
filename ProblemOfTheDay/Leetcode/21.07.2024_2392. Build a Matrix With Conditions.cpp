/*
Problem Link :- https://leetcode.com/problems/build-a-matrix-with-conditions/?envType=daily-question&envId=2024-07-21
*/

/*2392. Build a Matrix With Conditions

You are given a positive integer k. You are also given:

a 2D integer array rowConditions of size n where rowConditions[i] = [abovei, belowi], and
a 2D integer array colConditions of size m where colConditions[i] = [lefti, righti].
The two arrays contain integers from 1 to k.

You have to build a k x k matrix that contains each of the numbers from 1 to k exactly once. The remaining cells should have the value 0.

The matrix should also satisfy the following conditions:

The number abovei should appear in a row that is strictly above the row at which the number belowi appears for all i from 0 to n - 1.
The number lefti should appear in a column that is strictly left of the column at which the number righti appears for all i from 0 to m - 1.
Return any matrix that satisfies the conditions. If no answer exists, return an empty matrix.

 

Example 1:


Input: k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
Output: [[3,0,0],[0,0,1],[0,2,0]]
Explanation: The diagram above shows a valid example of a matrix that satisfies all the conditions.
The row conditions are the following:
- Number 1 is in row 1, and number 2 is in row 2, so 1 is above 2 in the matrix.
- Number 3 is in row 0, and number 2 is in row 2, so 3 is above 2 in the matrix.
The column conditions are the following:
- Number 2 is in column 1, and number 1 is in column 2, so 2 is left of 1 in the matrix.
- Number 3 is in column 0, and number 2 is in column 1, so 3 is left of 2 in the matrix.
Note that there may be multiple correct answers.
Example 2:

Input: k = 3, rowConditions = [[1,2],[2,3],[3,1],[2,3]], colConditions = [[2,1]]
Output: []
Explanation: From the first two conditions, 3 has to be below 1 but the third conditions needs 3 to be above 1 to be satisfied.
No matrix can satisfy all the conditions, so we return the empty matrix.
 

Constraints:

2 <= k <= 400
1 <= rowConditions.length, colConditions.length <= 104
rowConditions[i].length == colConditions[i].length == 2
1 <= abovei, belowi, lefti, righti <= k
abovei != belowi
lefti != righ


*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>


using namespace std;

class Solution {
public:
    void dfs(int u , vector<int>& visited , unordered_map<int , vector<int>>& adj , stack<int>& st , bool& cycle){
        visited[u] = 1;

        for(int& v : adj[u]){
            if(visited[v] == 0){
                dfs(v , visited , adj , st , cycle);
            }
            else if(visited[v] == 1){
                cycle = true;
                return;
            }
        }

        visited[u] = 2;
        st.push(u);

    }
    vector<int> topoSort(vector<vector<int>>& edges , int& n){
        unordered_map<int , vector<int>> adj;

        for(vector<int>& edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        vector<int> visited(n+1 , 0);
        stack<int> st;
        vector<int> order;
        bool cycle = false;

        for(int i=1 ; i<=n ; i++){
            if(visited[i] == 0){
                dfs(i , visited , adj , st , cycle);
                if(cycle == true){
                    return {};
                }
            }
        }

        while(!st.empty()){
            order.push_back(st.top());
            st.pop();
        }

        return order;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> topoRow = topoSort(rowConditions , k );
        vector<int> topoCol = topoSort(colConditions , k );

        if(topoRow.empty() || topoCol.empty()){
            return {};
        }

        vector<vector<int>> matrix(k , vector<int>(k , 0));

        for(int i=0 ; i<k ; i++){
            for(int j=0 ; j<k ; j++){
                if(topoRow[i] == topoCol[j]){
                    matrix[i][j] = topoRow[i];
                }
            }
        }

        return matrix;
    }
};

int main(){
    Solution s;
    vector<vector<int>> rowConditions = {{1,4},{2,3},{3,1}}, colConditions = {{1,3},{2,3}};
    vector<vector<int>> matrix = s.buildMatrix(4 , rowConditions , colConditions);
    for(int i=0 ; i<matrix.size() ; i++){
        for(int j=0 ; j<matrix[i].size() ; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;

    
}

