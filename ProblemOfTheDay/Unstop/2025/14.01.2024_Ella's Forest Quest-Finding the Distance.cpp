/*
Problem link: https://unstop.com/code/practice/505743
*/

/*Ella's Forest Quest: Finding the Distance

Problem Statement
Ella, an adventurous traveler, embarks on a journey through the magical Enchanted Forest, where every path leads to a different encounter. At the entrance of the forest, a wise owl greets her and sets forth a curious challenge.

"There are N mystical creatures scattered across the forest, each residing in their own unique glades. Each glade is identified by its coordinates, (xi, yi) (from the orgin in a 2D plane). Some of these creatures are friendly and offer gifts, while others are shy and watch from afar.

Ella stand at orgin and she must first find the creature closest to her, as they will guide her deeper into the forest. She must then locate the creature farthest from her, as they hold the key to the forest’s secret.

The owl asks:

What is the straight-line distance between the closest creature and the farthest creature in the forest?
Ella is determined to solve the owl’s puzzle. Can you help her calculate this mystical distance?"

Input Format
The first line of input cotains an integer N, the number of mystical creatures.

The next N lines each contain two space-separated integers, xi and yi, the coordinates of each mystical creature

Output Format
Print the Euclidean distance (upto 5 place of decimal) between the closest creature and the farthest creature from Ella.

Constraints
2 <= N <= 10^4

-10^4 <= xi, yi <= 10^4

Sample Testcase 0
Testcase Input
4
1 2
3 4
-2 -1
5 5
Testcase Output
5.00000
Explanation
Ella is at origin,
The closest creature from her is at (1,2) or (-2,-1), we can take any one.
The farthest creature from her is at (5,5).
Calculate the distance between these two creature, which will be 5.

Sample Testcase 1
Testcase Input
3
1 2
3 4
-1 -1
Testcase Output
6.40312
Explanation
Ella is at origin,
The closest creature from her is at (-1,-1).
The farthest creature from her is at (3,4).
Calculate the distance between these two creature, which will be 6.40312.

*/

#include <bits/stdc++.h>
using namespace std;

double calculate_distance(pair<int, int> a, pair<int, int> b) {
    return sqrt((a.first - b.first) * (a.first - b.first) +
                (a.second - b.second) * (a.second - b.second));
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> creatures(N);
    for (int i = 0; i < N; i++) {
        cin >> creatures[i].first >> creatures[i].second;
    }

    // Initialize variables for closest and farthest creatures
    double min_distance = DBL_MAX, max_distance = -DBL_MAX;
    pair<int, int> closest, farthest;

    for (auto &creature : creatures) {
        double distance = sqrt(creature.first * creature.first +
                               creature.second * creature.second);

        // Update closest creature
        if (distance < min_distance) {
            min_distance = distance;
            closest = creature;
        }

        // Update farthest creature
        if (distance > max_distance) {
            max_distance = distance;
            farthest = creature;
        }
    }

    // Calculate the Euclidean distance between the closest and farthest creatures
    double result = calculate_distance(closest, farthest);

    // Print the result rounded to 5 decimal places
    printf("%.5f\n", result);

    return 0;
}