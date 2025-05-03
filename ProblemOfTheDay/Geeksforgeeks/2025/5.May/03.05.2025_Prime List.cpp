/*
Problem Link: https://www.geeksforgeeks.org/problems/prime-list--170646/1
*/

/*Prime List

You are given the head of a linked list. You have to replace all the values of the nodes with the nearest prime number. If more than one prime number exists at an equal distance, choose the smallest one. Return the head of the modified linked list.

Examples :

Input: head = 2 → 6 → 10
Output: 2 → 5 → 11

Explanation: The nearest prime of 2 is 2 itself. The nearest primes of 6 are 5 and 7, since 5 is smaller so, 5 will be chosen. The nearest prime of 10 is 11.
Input: head = 1 → 15 → 20
Output: 2 → 13 → 19

Explanation: The nearest prime of 1 is 2. The nearest primes of 15 are 13 and 17, since 13 is smaller so, 13 will be chosen. The nearest prime of 20 is 19.
Constraints:
1 <= no. of Nodes <= 104
1 <= node.val <= 104

*/

// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution {
    bool isPrime(int n){
        if(n == 1 || n <= 0){
            return false;
        }
        
        for(int i=2; i<=sqrt(n); i++){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
    
  public:
    Node *primeList(Node *head) {
        // code here
        Node* root = head;
        while(head != NULL){
            int temp = head->val;
            
            if(isPrime(temp)){
                head = head->next;
                continue;
            }else{
                int curr = temp;
                while(!isPrime(temp) && !isPrime(curr)){
                    temp++;
                    curr--;
                }
                
                if(isPrime(temp) && isPrime(curr)){
                    head->val = min(temp, curr);
                }else if(isPrime(curr)){
                    head->val = curr;
                }else{
                    head->val = temp;
                }
                head = head->next;
            }
        }
        return root;
    }
};
