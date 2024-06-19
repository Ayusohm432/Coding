/*
Problem Link :- https://www.geeksforgeeks.org/problems/magical-box5306/1
*/

/*Find maximum volume of a cuboid

You are given a perimeter & the area. Your task is to return the maximum volume that can be made in the form of a cuboid from the given perimeter and surface area.
Note: Round off to 2 decimal places and for the given parameters, it is guaranteed that an answer always exists.

Examples

Input: perimeter = 22, area = 15
Output: 3.02
Explanation: The maximum attainable volume of the cuboid is 3.02
Input: perimeter = 20, area = 5
Output: 0.33
Explanation: The maximum attainable volume of the cuboid is 0.33
Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)
Constraints :
1 ≤ perimeter ≤ 109
1 ≤ area ≤ 109

*/



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    double maxVolume(double perimeter, double area) {
        // code here
        double height = (perimeter-sqrt(pow(perimeter,2)-24*area))/12;
        
        double volume = ((area*height/2) - (perimeter*pow(height,2)/4) + pow(height,3)) ;
    
        
        return volume;
    }
};

//{ Driver Code Starts.
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        double perimeter, area;
        cin >> perimeter >> area;
        // if (area == 5 and parameter == 15) {
        //     cout << "0.46" << endl;
        //     return 0;
        // }
        Solution ob;
        double ans = ob.maxVolume(perimeter, area);
        cout.precision(2);
        cout << fixed << ans << "\n";
    }
}
// } Driver Code Ends