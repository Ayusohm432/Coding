/*
Problem Link :- https://unstop.com/code/practice/250590
*/

/*Maximum Units on a Truck

Problem Statement
You need to load boxes onto a truck. You are given a 2D array boxTypes, where each entry boxTypes[i] is a pair [numberOfBoxes_i, unitsPerBox_i]:

numberOfBoxes_i indicates how many boxes of type i are available.
unitsPerBox_i indicates how many units are in each box of type i.
You also have an integer truckSize, which represents the maximum number of boxes the truck can carry. You can select any combination of boxes, provided that the total number of boxes does not exceed truckSize.

Your goal is to return the maximum total number of units that can be loaded onto the truck.

Input Format
First line contains an integer N, the number of rows in the boxTypes array.

Second line contains an integer M, the number of columns in the boxTypes array.

Next N lines, each containing M integers representing the boxTypes array. Each line has two integers: the number of boxes and the units per box.

Last line contaiins an integer truckSize, which is the maximum number of boxes that the truck can carry.

Output Format
Print an integer representing the maximum total number of units that can be loaded onto the truck.

Constraints
1 <= boxTypes.length<= 10^3

1 <= numberOfBoxesi, numberOfUnitsPerBoxi <= 10^3

1 <= truckSize <= 106

Sample Testcase 0
Testcase Input
3
2
1 3
2 2
3 1
4

Testcase Output
8
Explanation
•	There are:
-	1 box of the first type that contains 3 units.
-	2 boxes of the second type that contain 2 units each.
-	3 boxes of the third type that contain 1 unit each.
•	You can take all the boxes of the first and second types, and one box of the third type.
•	The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.
Sample Testcase 1
Testcase Input
4
2
5 10
2 5
4 7
3 9
10

Testcase Output
91

Explanation
As the above output matches our required answer


*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to compute the maximum units that can be loaded onto the truck
int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    // Sort the boxTypes based on units per box in descending order
    sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b) {
        return a[1] > b[1]; // Sort by the second value (units per box)
    });
    
    int totalUnits = 0;
    
    // Iterate through the sorted boxTypes
    for (auto& box : boxTypes) {
        int numberOfBoxes = box[0];
        int unitsPerBox = box[1];
        
        if (truckSize == 0) break; // If truck is full, stop loading
        
        // Calculate how many boxes we can take
        int boxesToTake = min(truckSize, numberOfBoxes);
        totalUnits += boxesToTake * unitsPerBox; // Add corresponding units
        truckSize -= boxesToTake; // Decrease the truck capacity
    }
    
    return totalUnits; // Return the total number of units loaded
}

int main() {
    int N, M, truckSize;
    
    // Input number of rows (N) and columns (M)
    cin >> N >> M;
    
    // Input the boxTypes array
    vector<vector<int>> boxTypes(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> boxTypes[i][j];
        }
    }
    
    // Input the truck size
    cin >> truckSize;
    
    // Call the function and output the result
    cout << maximumUnits(boxTypes, truckSize) << endl;
    
    return 0;
}


