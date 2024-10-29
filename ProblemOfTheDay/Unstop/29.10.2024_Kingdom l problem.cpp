/*
Problem Link : https://unstop.com/code/practice/305356
*/

/*Kingdom l problem

Problem Statement
There are two kingdoms, A1 and A2, and war occurs between them. When there is no one in the A1 kingdom except the Queen and King, the A2 kingdom sends their soldiers to kill the A1 Queen to demonstrate their power. The King of A1 wants to save their Queen and kill all the enemy soldiers. The King of A1 has K number of swords, and the enemy soldiers of A2 have their number of swords, which are represented with an integer for each soldier at their location in the matrix.

Conditions:

If the King of A1 has more swords than an enemy soldier, then the King of A1 kills that soldier and takes their sword to fight another soldier.

If the number of swords of the King of A1 is less than that of an enemy soldier, then the King of A1 loses the Queen.

The King of A1 can only move in 8 directions from the kingdom location (up, down, left, right, and four diagonal directions)

The task is to tell whether the A1 kingdom can save the Queen. If they can keep the Queen, tell him the path he must follow (as an index of the matrix) and where the King should go first.

The kingdom and King's location are represented by -1 in the matrix, 0 represent no soldier and integer value represent the soldier with number of swords.

Consider yourself as the King of A1, and you can only move in 8 directions and find out whether you're going to save the Queen or not.

Input Format
The first line contains an integer K, which is the number of swords of King A1.

The second line contains an integer N, which represents the number of rows in the matrix

The third line contains an integer M, which represents the number of columns in the matrix

The next N lines contains M space-seprated integers representing the enemy soldiers' locations and their number of swords

Output Format
If the King A1 loses his queen display "Lose" (without quotation marks)

Else, display "Save and path as i and j format" and in the next lines display two space-seprtaed integers i and j representing the location of the solider in order the king A1 will kill the soldier.

Constraints
0 <= K <= 20.

1 < N <= 10^3.

1 < M <= 10^3.

Sample Testcase 0
Testcase Input
3
4
4
0 0 6 0
0 -1 0 4
0 0 0 0 
0 0 0 5
Testcase Output
Lose
Explanation
As King A1 goes to (0,2), the soldier has greater swords, and similarly if he goes to any other soldier he will lose because he has the number of swords less than all other soldiers.


So, he will lose the queen.

Sample Testcase 1
Testcase Input
3
6
6
0 0 2 0 0 35
0 -1 0 4 0 0
0 0 0 0 0 0
0 0 0 5 0 15
0 70 0 0 0 0
0 0 0 8 0 0
Testcase Output
Save and path as i and j format
0 2
1 3
3 3
5 3
3 5
0 5
4 1
Explanation
As the location of king  A1 is -1 and has 3 swords, they first kill (0,2) location enemy with have two swords and then king A1 gets 5 swords then they go (1,3) get 5+4= 9 swords then go (3,3) total sword now 14 and so on….. Till he reaches (4,1) to kill the last enemy

*/

#include <iostream>
#include <vector>

using namespace std;

class Pair {
public:
    int x, y;
    Pair(int x, int y) : x(x), y(y) {}
};

int ipositionking = -1;
int jpositionking = -1;
int totalnumerofsoilder = 0;
int ikingtreval = -1;
int jkingtreval = -1;
int newk = -1;
int kadd = 0;
vector<Pair> l;

void kingtreval(vector<vector<int>>& vis, int i, int j) {
    ikingtreval = jkingtreval = newk = -1;
    int a = i, b = j;
    
    for (int visi = 0; visi < vis.size(); visi++) {
        if (vis[visi][b] != 0 && kadd > vis[visi][b]) {
            kadd += vis[visi][b];
            ikingtreval = visi;
            jkingtreval = b;
            newk = vis[visi][b];
            l.push_back(Pair(ikingtreval, jkingtreval));
            break;
        }
    }

    for (int visi = 0; visi < vis[0].size(); visi++) {
        if (newk != -1) break;
        if (vis[a][visi] != 0 && kadd > vis[a][visi]) {
            kadd += vis[a][visi];
            ikingtreval = a;
            jkingtreval = visi;
            newk = vis[a][visi];
            l.push_back(Pair(ikingtreval, jkingtreval));
            break;
        }
    }

    a = i;
    b = j;
    while (a >= 0 && b >= 0 && newk == -1) {
        if (vis[a][b] != 0 && kadd > vis[a][b]) {
            ikingtreval = a;
            jkingtreval = b;
            newk = vis[a][b];
            l.push_back(Pair(ikingtreval, jkingtreval));
            break;
        }
        a--;
        b--;
    }

    a = i;
    b = j;
    while (a < vis.size() && b < vis[0].size() && newk == -1) {
        if (vis[a][b] != 0 && kadd > vis[a][b]) {
            kadd += vis[a][b];
            ikingtreval = a;
            jkingtreval = b;
            newk = vis[a][b];
            l.push_back(Pair(ikingtreval, jkingtreval));
            break;
        }
        a++;
        b++;
    }

    a = i;
    b = j;
    while (a < vis.size() && b >= 0 && newk == -1) {
        if (vis[a][b] != 0 && kadd > vis[a][b]) {
            kadd += vis[a][b];
            ikingtreval = a;
            jkingtreval = b;
            newk = vis[a][b];
            l.push_back(Pair(ikingtreval, jkingtreval));
            break;
        }
        a++;
        b--;
    }

    a = i;
    b = j;
    while (a >= 0 && b < vis[0].size() && newk == -1) {
        if (vis[a][b] != 0 && kadd > vis[a][b]) {
            kadd += vis[a][b];
            ikingtreval = a;
            jkingtreval = b;
            newk = vis[a][b];
            l.push_back(Pair(ikingtreval, jkingtreval));
            break;
        }
        a--;
        b++;
    }
}

string isQueensafe(vector<vector<int>>& matrix, int ipositionking, int jpositionking) {
    ikingtreval = ipositionking;
    jkingtreval = jpositionking;

    while (ikingtreval != -1 && jkingtreval != -1) {
        matrix[ikingtreval][jkingtreval] = 0;
        ikingtreval = jkingtreval = -1;
        kingtreval(matrix, ipositionking, jpositionking);
        
        if (newk == -1) break;
        
        if (ikingtreval != -1 && jkingtreval != -1) {
            totalnumerofsoilder--;
            ipositionking = ikingtreval;
            jpositionking = jkingtreval;
        }
        newk = -1;
    }
    
    return totalnumerofsoilder != 0 ? "Lose" : "Save and path as i and j format";
}

string issafe(vector<vector<int>>& matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == -1) {
                ipositionking = i;
                jpositionking = j;
            }
            if (matrix[i][j] != -1 && matrix[i][j] != 0) {
                totalnumerofsoilder++;
            }
        }
    }
    
    return isQueensafe(matrix, ipositionking, jpositionking);
}

int main() {
    int k, n, m;
    cin >> k >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    kadd += k;
    string result = issafe(arr, n, m);
    cout << result << endl;

    if (!l.empty() && totalnumerofsoilder == 0) {
        for (const auto& p : l) {
            cout << p.x << " " << p.y << endl;
        }
    }

    return 0;
}