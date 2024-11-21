#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution {
    vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}, 
                                       {-1,-1}, {-1,1}, {1,-1}, {1,1}};
    
    bool isValid(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    
    void dfs(vector<vector<int>>& matrix, int i, int j, int& swords, vector<Pair>& path) {
        if (swords <= 0) return;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        for (auto& dir : directions) {
            int newI = i + dir.first;
            int newJ = j + dir.second;
            
            if (isValid(newI, newJ, n, m) && matrix[newI][newJ] > 0 && swords > matrix[newI][newJ]) {
                int temp = matrix[newI][newJ];
                matrix[newI][newJ] = 0;
                swords += temp;
                path.push_back(Pair(newI, newJ));
                dfs(matrix, newI, newJ, swords, path);
            }
        }
    }
    
public:
    string solve(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int kingI = -1, kingJ = -1;
        int totalSoldiers = 0;
        
        // Find king's position and count soldiers
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == -1) {
                    kingI = i;
                    kingJ = j;
                } else if (matrix[i][j] > 0) {
                    totalSoldiers++;
                }
            }
        }
        
        vector<Pair> path;
        dfs(matrix, kingI, kingJ, k, path);
        
        // Count remaining soldiers
        int remainingSoldiers = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] > 0) remainingSoldiers++;
            }
        }
        
        if (remainingSoldiers > 0) {
            return "Lose";
        }
        
        cout << "Save and path as i and j format" << endl;
        for (const auto& p : path) {
            cout << p.x << " " << p.y << endl;
        }
        return "";
    }
};

int main() {
    int k, n, m;
    cin >> k >> n >> m;
    
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    
    Solution solution;
    string result = solution.solve(matrix, k);
    cout << result << endl;
    
    return 0;
}
