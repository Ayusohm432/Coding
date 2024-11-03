/*
Problem Link : https://unstop.com/code/practice/301922
*/

/*Reach Home

Problem Statement
Lexi is a doctor with a clinic, and today is her daughter's birthday. She needs to get home within X minutes. There are N patients waiting to be seen, and each patient requires A[i] minutes for their check-up. Additionally, it takes Y minutes for each patient to arrive and leave. Lexi also needs Z minutes to travel from her clinic to home.

Find out if she can reach home on time or not.

Input Format
The first line of input includes four integers, N, the number of patients, X, the time remaining for Lexi to get home, Y, the time each patient takes to arrive and leave, Z, the time Lexi needs to travel home from the clinic.

The second line contains N space-separated integers, representing the time required to check each patient.

Output Format
Print “YES” if she can reach home on time, and “NO” if she cannot reach at home on time.

Constraints
1<= N, X, Y, Z <= 10^5

Sample Testcase 0
Testcase Input
5 50 1 10
2 4 12 6 5
Testcase Output
YES
Explanation
In the first test case, we can see that the time taken to check the patient is 2+4+12+6+5 = 29 , each patient required 1 minute extra which for 5 patients becomes 5 minutes. And 10 extra minutes for reaching home from the clinic. So, the total time required is 44 minutes and she had 50 minutes to reach home.

Sample Testcase 1
Testcase Input
6 50 5 20
12 3 5 2 9 3
Testcase Output
NO
Explanation
In the first test case, we can see that the time taken to check the patient is 12+3+5+2+9+3 = 34, each patient required 5 minute extra which for 6 patients becomes 30 minutes. And 20 extra minutes for reaching home from the clinic.


So, the total time required is 84 minutes and she had 50 minutes to reach home.

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

string canReachHomeOnTime(int n, int x, int y, int z, vector<int>& a) {
    // User will write the logic here
    int timeForCheckup = accumulate(a.begin(), a.end(), 0);
    int timeForPatientArrival_leave = n * y;


    int totalTime = timeForCheckup + timeForPatientArrival_leave + z;


    if(totalTime <= x){
        return "YES";
    }
    return "NO";
}

int main() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string result = canReachHomeOnTime(n, x, y, z, a);
    cout << result << endl;
    return 0;
}