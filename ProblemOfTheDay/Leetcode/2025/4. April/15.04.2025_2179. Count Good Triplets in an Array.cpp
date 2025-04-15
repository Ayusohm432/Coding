/*
Problem Link: https://leetcode.com/problems/count-good-triplets-in-an-array?envType=daily-question&envId=2025-04-15
*/

/*2179. Count Good Triplets in an Array

You are given two 0-indexed arrays nums1 and nums2 of length n, both of which are permutations of [0, 1, ..., n - 1].

A good triplet is a set of 3 distinct values which are present in increasing order by position both in nums1 and nums2. In other words, if we consider pos1v as the index of the value v in nums1 and pos2v as the index of the value v in nums2, then a good triplet will be a set (x, y, z) where 0 <= x, y, z <= n - 1, such that pos1x < pos1y < pos1z and pos2x < pos2y < pos2z.

Return the total number of good triplets.

 

Example 1:

Input: nums1 = [2,0,1,3], nums2 = [0,1,2,3]
Output: 1
Explanation: 
There are 4 triplets (x,y,z) such that pos1x < pos1y < pos1z. They are (2,0,1), (2,0,3), (2,1,3), and (0,1,3). 
Out of those triplets, only the triplet (0,1,3) satisfies pos2x < pos2y < pos2z. Hence, there is only 1 good triplet.
Example 2:

Input: nums1 = [4,0,1,3,2], nums2 = [4,1,0,2,3]
Output: 4
Explanation: The 4 good triplets are (4,0,3), (4,0,2), (4,1,3), and (4,1,2).
 

Constraints:

n == nums1.length == nums2.length
3 <= n <= 105
0 <= nums1[i], nums2[i] <= n - 1
nums1 and nums2 are permutations of [0, 1, ..., n - 1].

*/

#define ll long long
class Solution {
    vector<ll> segmentTree;

    void updateSegmentTree(ll st, ll start, ll end, ll& query_idx){
        if(end < query_idx || start > query_idx){
            return;
        }

        if(start == end){
            segmentTree[st]++;
            return;
        }

        ll mid = start + (end - start) / 2;
        updateSegmentTree(2*st, start, mid, query_idx);
        updateSegmentTree(2*st+1, mid+1, end, query_idx);
        segmentTree[st] = segmentTree[2*st] + segmentTree[2*st+1];
    }

    int rangeSumQuery(ll st, ll start, ll end, ll qs, ll qe){
        if(qs > end || qe<start){
            return 0;
        }
        if(start >= qs && end <= qe){
            return segmentTree[st];
        }

        ll mid = start + (end - start) / 2;
        ll leftSum = rangeSumQuery(2*st, start, mid, qs, qe);
        ll rightSum = rangeSumQuery(2*st+1, mid+1, end, qs, qe);
        return leftSum + rightSum;
    }
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        ll n = nums1.size();
        segmentTree = vector<ll> (4*n+1, 0);

        unordered_map<ll, ll>mp;

        for(ll i=0; i<n; i++){
            mp[nums2[i]] = i;
        }

        updateSegmentTree(1, 0, n-1, mp[nums1[0]]);

        ll triplets = 0;
        for(int i=1; i<n-1; i++){
            ll nums2_idx = mp[nums1[i]];
            ll commonLeft = rangeSumQuery(1, 0, n-1, 0, nums2_idx);
            ll unCommonLeft = (i - commonLeft);
            ll commonRight = (n - nums2_idx - 1) - unCommonLeft;
            triplets += commonLeft * commonRight;
            updateSegmentTree(1, 0,n-1, nums2_idx);
        }

        return triplets;
    }
};