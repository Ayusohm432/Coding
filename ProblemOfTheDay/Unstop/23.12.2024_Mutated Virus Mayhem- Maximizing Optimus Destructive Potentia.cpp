/*
Problem link: https://unstop.com/code/practice/484668
*/

/*Mutated Virus Mayhem: Maximizing Optimus Destructive Potentia

Problem Statement
In a hidden lab, Optimus Prime, a notorious and ambitious scientist, is planning to create a mutated virus that could potentially wreak havoc across the world. His twisted mind has devised a formula to build this devastating virus, but he needs to start with specific ingredients: groups of three "base viruses," each with a specific "contamination level."

To create a mutated virus, Optimus must find three viruses with contamination levels that are either identical or consecutive, like levels 5, 5, and 5, or levels 2, 3, and 4. Optimus has exactly V different viruses at his disposal, each with its own contamination level, but each virus can only be used once. To proceed with his plan, he needs to know the maximum number of mutated viruses he can create from the viruses he currently has. Can you help Optimus figure out how many powerful mutated viruses he can make?

Input Format
The first line contains one integer V,number of viruses.

The second line contains V space separated integers representing the contamination levels of the viruses.

Output Format
Output a single integer, the maximum number of mutated viruses Shubham can create, if no such virus formed, return 0.

 
Constraints
1 <= V <= 10^3

1 <= Contamination level <= 10^2

Sample Testcase 0
Testcase Input
10
1 2 2 3 3 3 4 4 4 4
Testcase Output
3
Explanation
Let's group the virus:
1st M Virus: [1, 2, 3]
2nd M Virus: [2, 3, 4]
3rd M Virus: [4, 4, 4]
Total Count = 3

Sample Testcase 1
Testcase Input
7
1 2 3 4 4 4 5
Testcase Output
2
Explanation
Let's group the virus:
1st M Virus: [1, 2, 3]
2nd M Virus; [4, 4, 4]
Total count: 2

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int maxMutatedViruses(int N, vector<int>& contamination_levels) {
    unordered_map<int, int> freq;
    
    for (int level : contamination_levels) {
        freq[level]++;
    }

    int mutatedVirusCount = 0;

    vector<int> levels;
    for (const auto& entry : freq) {
        levels.push_back(entry.first);
    }
    sort(levels.begin(), levels.end());

    for (size_t i = 0; i < levels.size(); ++i) {
        int level = levels[i];
        while (freq[level] >= 3) {
            mutatedVirusCount++;
            freq[level] -= 3;
        }
        if (i + 2 < levels.size() && levels[i + 1] == level + 1 && levels[i + 2] == level + 2) {
            while (freq[level] > 0 && freq[level + 1] > 0 && freq[level + 2] > 0) {
                mutatedVirusCount++;
                freq[level]--;
                freq[level + 1]--;
                freq[level + 2]--;
            }
        }
    }

    return mutatedVirusCount;
}

int main() {
    int N;
    cin >> N;
    vector<int> contamination_levels(N);
    for (int i = 0; i < N; i++) {
        cin >> contamination_levels[i];
    }
    
    int result = maxMutatedViruses(N, contamination_levels);
    cout << result << endl;

    return 0;
}