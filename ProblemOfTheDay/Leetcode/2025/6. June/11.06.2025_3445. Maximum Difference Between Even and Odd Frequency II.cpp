/*
Problem Link: https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-ii?envType=daily-question&envId=2025-06-11
*/

/*3445. Maximum Difference Between Even and Odd Frequency II


You are given a string s and an integer k. Your task is to find the maximum difference between the frequency of two characters, freq[a] - freq[b], in a substring subs of s, such that:

subs has a size of at least k.
Character a has an odd frequency in subs.
Character b has an even frequency in subs.
Return the maximum difference.

Note that subs can contain more than 2 distinct characters.

 

Example 1:

Input: s = "12233", k = 4

Output: -1

Explanation:

For the substring "12233", the frequency of '1' is 1 and the frequency of '3' is 2. The difference is 1 - 2 = -1.

Example 2:

Input: s = "1122211", k = 3

Output: 1

Explanation:

For the substring "11222", the frequency of '2' is 3 and the frequency of '1' is 2. The difference is 3 - 2 = 1.

Example 3:

Input: s = "110", k = 3

Output: -1

 

Constraints:

3 <= s.length <= 3 * 104
s consists only of digits '0' to '4'.
The input is generated that at least one substring has a character with an even frequency and a character with an odd frequency.
1 <= k <= s.length

*/

const int INF = 1e9;

class FenwickTree{
private:
    int size;
    vector<int> tree;
public:
    FenwickTree(int n) : size(n) , tree(n+1, INF) {}

    void reset(int n){
        size = n;
        fill(tree.begin(), tree.end(), INF);
    }

    void update(int index, int value){
        while(index <= size){
            tree[index] = min(tree[index], value);
            index += index & -index;
        }
    }

    int query(int index) const{
        int result = INF;
        while(index > 0){
            result = min(result, tree[index]);
            index -= index & -index;
        }
        return result;
    }
};

class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.size();
        vector<vector<int>> digitCount(n+1, vector<int>(5, 0));

        for(int i=0; i<n; i++){
            digitCount[i+1] = digitCount[i];
            digitCount[i+1][s[i] - '0']++;
        }

        int maxDiff = -INF;

        for(int x=0; x<5; x++){
            for(int y=0; y<5; y++){
                if(x == y){
                    continue;
                }

                vector<int> diff(n+1), parityMask(n+1);
                for(int i=0; i<=n; i++){
                    diff[i] = digitCount[i][x] - digitCount[i][y];
                    int parityX = digitCount[i][x] % 2;
                    int parityY = digitCount[i][y] % 2;
                    parityMask[i] = (parityX << 1) | parityY;
                }

                vector<FenwickTree> trees(4, FenwickTree(n+1));
                for(auto& tree : trees){
                    tree.reset(n+1);
                }

                int best = -INF, left = 0;
                for(int right=k; right<=n; right++){
                    while(left <= right-k){
                        int mask = parityMask[left];
                        int val = digitCount[left][y];
                        trees[mask].update(val+1, diff[left]);
                        left++;
                    }

                    int neededMask = ((1 - (digitCount[right][x] % 2)) << 1) | (digitCount[right][y] % 2);
                    int yCount = digitCount[right][y];

                    if(yCount > 0){
                        int minValue = trees[neededMask].query(yCount);
                        if(minValue < INF){
                            best = max(best, diff[right] - minValue);
                        }
                    }
                }
                maxDiff = max(maxDiff, best);
            }
        }
        return maxDiff;
    }
};