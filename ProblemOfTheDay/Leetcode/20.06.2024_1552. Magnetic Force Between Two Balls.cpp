/*
Problem Link :- https://leetcode.com/problems/magnetic-force-between-two-balls/
*/
/*1552. Magnetic Force Between Two Balls

In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

Given the integer array position and the integer m. Return the required force.

 

Example 1:


Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.
Example 2:

Input: position = [5,4,3,2,1,1000000000], m = 2
Output: 999999999
Explanation: We can use baskets 1 and 1000000000.
 

Constraints:

n == position.length
2 <= n <= 105
1 <= position[i] <= 109
All integers in position are distinct.
2 <= m <= position.length


*/
class Solution {
public:
    bool possible(int midForce , vector<int>& position , int m){
        int prev = position[0];
        int countBalls = 1;
        for(int i=0 ; i<position.size() ; i++){
            int curr = position[i];
            if(curr-prev >= midForce){
                countBalls++;
                prev = curr;
            }
            if(countBalls == m){
                break;
            }
        }
        return countBalls == m;
    }
    int maxDistance(vector<int>& position, int m) {
        
        int n = position.size();
        sort(begin(position),end(position));
        int result = 0;
        int minForce = 1;
        int maxForce = position[n-1]-position[0];
        while(minForce <= maxForce){
            int midForce = minForce+(maxForce-minForce)/2;
            if(possible(midForce,position,m)){
                result = midForce;
                minForce = midForce+1;
            }
            else{
                maxForce = midForce-1;
            }
        }
        return result;
    }
};