/*
Problem Link: https://unstop.com/code/practice/491897
*/

/*Can Mira Restore the Magical Garden's Balance?

Problem Statement
In a distant village, there is a magical garden where flowers grow in perfect harmony. Each flowerbed is arranged in a straight row, and the villagers believe that the garden’s magic depends on maintaining balance. The garden can only thrive if every consecutive group of the flowerbed contains an equal number of blue and white flowers.

However, over time, some flowers in the bed have lost their colors, turning gray. To restore the garden’s magic, the caretaker, Mira, must relace the gray flowers either blue or white. Mira’s challenge is to ensure that for every consecutive group of flowers of the given size h (always an even number), the number of blue and white flowers is equal.

Can Mira replace the gray flowers to restore the balance in the garden? Or is it impossible to bring harmony back to the magical garden?

Input Format
The first line contains two space-separated integers N and h denoting the length of the flowerbed and the length for a magical sequence respectively.

The next line contains the sequence S of length N. It is given that S consists of only 'b (blue)', 'w (white)', and 'x (gray)'.

Output Format
Output "yes" if it is possible to repaint the gray flowers to restore the balance in the garden.

Otherwise, output "no".

Constraints
2 ≤ N ≤ 10^5

2 ≤ h ≤ N

 

1<= N*h<=5*10^7

Sample Testcase 0
Testcase Input
6 4
wbbwxb
Testcase Output
yes
Explanation
In this case, all sequences of length 4 in the row are ( wbbw, bbwx, bwxb ). The first sequence is already harmonious. The second and third sequences will become magical if we replace the gray flower with a white flower. Therefore, the entire sequence is magical.

Sample Testcase 1
Testcase Input
4 4
xbxb
Testcase Output
yes
Explanation
In this case, there is a sequence of length 4 which contains 2 blue flowers and 2 gray flowers. If we replace the gray flowers with white flowers , the sequence becomes magical.

*/

#include <iostream>
#include <string>

bool can_balance(const std::string& s, int h) {
    // Write your logic here.
    int x = 0, w = 0, b = 0, i = 0, j = 0, n = s.size();
    while(j < h - 1){
        if(s[j] == 'x')
            x++;
        else if(s[j] == 'w')
            w++;
        else
            b++;
        j++;
    }
    while(j < n){
        if(s[j] == 'x')
            x++;
        else if(s[j] == 'w')
            w++;
        else
            b++;

        if(x < abs(w - b))
            return false;
        
        if(s[i] == 'x')
            x--;
        else if(s[i] == 'w')
            w--;
        else
            b--;
        i++;
        j++;
    }
    return true;
}


int main() {
    int N, h;
    std::string S;
    std::cin >> N >> h >> S;
    
    bool result = can_balance(S, h);
    
    if (result) {
        std::cout << "yes\n";
    } else {
        std::cout << "no\n";
    }
    
    return 0;
}

