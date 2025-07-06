/*
Problem Link: https://www.geeksforgeeks.org/problems/maximum-sum-combination/1
*/

/*Maximum Sum Combination

You are given two integer arrays a[] and b[] of equal size. A sum combination is formed by adding one element from a[] and one from b[], using each index pair (i, j) at most once. Return the top k maximum sum combinations, sorted in non-increasing order.

Examples:

Input: a[] = [3, 2], b[] = [1, 4], k = 2
Output: [7, 6]
Explanation: Possible sums: 3 + 1 = 4, 3 + 4 = 7, 2 + 1 = 3, 2 + 4 = 6, Top 2 sums are 7 and 6.
Input: a[] = [1, 4, 2, 3], b[] = [2, 5, 1, 6], k = 3
Output: [10, 9, 9]
Explanation: The top 3 maximum possible sums are : 4 + 6 = 10, 3 + 6 = 9, and 4 + 5 = 9
Constraints:
1 ≤ a.size() = b.size() ≤ 105
1 ≤ k ≤ a.size()
1 ≤ a[i], b[i] ≤ 104

*/

class Solution {
    typedef pair<int, int> P;
    typedef pair<int, P> PP;
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n = a.size();
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        
        priority_queue<PP> pq;
        set<P> visited;
        
        pq.push({a[0]+b[0], {0, 0}});
        visited.insert({0, 0});
        
        vector<int> result;
        while(result.size() < k){
            auto curr = pq.top();
            pq.pop();
            int sum = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;
            result.push_back(sum);
            
            if(i+1<n && visited.find({i+1, j}) == visited.end()){
                pq.push({a[i+1]+b[j], {i+1, j}});
                visited.insert({i+1, j});
            }
            
            if(j+1<n && visited.find({i, j+1}) == visited.end()){
                pq.push({a[i]+b[j+1], {i, j+1}});
                visited.insert({i, j+1});
            }
        }
        return result;
    }
};