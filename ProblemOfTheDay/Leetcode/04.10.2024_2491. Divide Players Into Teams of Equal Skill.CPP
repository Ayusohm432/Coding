/*
Problem Link : https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/?envType=daily-question&envId=2024-10-04
*/

/*2491. Divide Players Into Teams of Equal Skill

You are given a positive integer array skill of even length n where skill[i] denotes the skill of the ith player. Divide the players into n / 2 teams of size 2 such that the total skill of each team is equal.

The chemistry of a team is equal to the product of the skills of the players on that team.

Return the sum of the chemistry of all the teams, or return -1 if there is no way to divide the players into teams such that the total skill of each team is equal.

 

Example 1:

Input: skill = [3,2,5,1,3,4]
Output: 22
Explanation: 
Divide the players into the following teams: (1, 5), (2, 4), (3, 3), where each team has a total skill of 6.
The sum of the chemistry of all the teams is: 1 * 5 + 2 * 4 + 3 * 3 = 5 + 8 + 9 = 22.
Example 2:

Input: skill = [3,4]
Output: 12
Explanation: 
The two players form a team with a total skill of 7.
The chemistry of the team is 3 * 4 = 12.
Example 3:

Input: skill = [1,1,2,3]
Output: -1
Explanation: 
There is no way to divide the players into teams such that the total skill of each team is equal.
 

Constraints:

2 <= skill.length <= 105
skill.length is even.
1 <= skill[i] <= 1000

*/

//Approach-1
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();

        sort(begin(skill) , end(skill));

        int i=0;
        int j = n-1;
        int s = skill[i] + skill[j];

        long long chem = 0;

        while(i < j){
            int currSkill = skill[i] + skill[j];

            if(currSkill != s){
                return -1;
            }

            chem += ( (long long)skill[i] * (long long)skill[j] );
            i++;
            j--;
        } 
        return chem;
    }
};

//Approach-2
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();

        vector<int> vec(1001 , 0);
        int sum = 0;

        for(int &s : skill){
            sum += s;
            vec[s]++;
        }

        int teams = n/2;

        if(sum % teams != 0){
            return -1;
        }

        int target = sum / teams;

        long long chem = 0;

        for(int i=0 ; i<n ; i++){
            int currSkill = skill[i];
            int remainSkill = target - currSkill;

            if(vec[remainSkill] <= 0){
                return -1;
            }

            chem += (long long)currSkill * (long long)remainSkill;
            vec[remainSkill]--;
        }

        return chem/2;
    }
};

//Approach-3
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        int pairs = n/2;

        int totalSum = accumulate(skill.begin() , skill.end() , 0);

        if(totalSum % pairs != 0){
            return -1;
        }
        
        int each = totalSum / pairs;

        long long totalSkill = 0;

        sort(skill.begin() , skill.end());

        for(int i=0 ; i<pairs ; i++){
            int curr = skill[i] + skill[n-i-1];
            if(curr != each){
                return -1;
            }
            else{
                long long prod =(long long)skill[i] * (long long)skill[n-i-1];
                totalSkill = totalSkill + prod;
            }
        }
        return totalSkill;
    }
};



//Approach-3
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        int pairs = n/2;

        int totalSum = accumulate(skill.begin(), skill.end(), 0);

        if(totalSum % pairs != 0){
            return -1;
        }
        
        int each = totalSum / pairs;

        long long totalSkill = 0;

        unordered_map<int, int> mp;

        for(int& s : skill){
            mp[s]++;
        }

        vector<int> skills;
        for(auto& p : mp){
            skills.push_back(p.first);
        }

        sort(skills.begin(), skills.end());

        int i = 0, j = skills.size() - 1;
        while(i < j){
            int curr = skills[i] + skills[j];
            if(curr != each){
                return -1;
            }
            else{
                long long prod = (long long)skills[i] * skills[j];
                totalSkill += prod;
                i++;
                j--;
            }
        }
        return totalSkill;
    }
};

//Approach=4
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        int pairs = n/2;

        int totalSum = accumulate(skill.begin(), skill.end(), 0);

        if(totalSum % pairs != 0){
            return -1;
        }
        
        int each = totalSum / pairs;

        vector<int> sortedSkill = skill;
        sort(sortedSkill.begin(), sortedSkill.end());

        long long totalSkill = 0;

        int i = 0, j = n-1;
        while(i < j){
            int curr = sortedSkill[i] + sortedSkill[j];
            if(curr != each){
                return -1;
            }
            else{
                long long prod = (long long)sortedSkill[i] * sortedSkill[j];
                totalSkill += prod;
                i++;
                j--;
            }
        }
        return totalSkill;
    }
};


//Approach- 5
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        int pairs = n/2;

        int totalSum = accumulate(skill.begin(), skill.end(), 0);

        if(totalSum % pairs != 0){
            return -1;
        }
        
        int each = totalSum / pairs;

        int freq[1001] = {0}; // assuming max skill level is 1000
        for(int& s : skill){
            freq[s]++;
        }

        long long totalSkill = 0;

        for(int i = 1; i <= 1000; i++){
            if(freq[i] > 0 && freq[each-i] > 0){
                long long prod = (long long)i * (each - i);
                totalSkill += prod;
                freq[i]--;
                freq[each-i]--;
            } else if(freq[i] > 0 || freq[each-i] > 0){
                return -1;
            }
        }
        return totalSkill;
    }
};