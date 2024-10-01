/*
Problem Link : https://www.geeksforgeeks.org/problems/multiply-two-linked-lists/1
*/

/*Multiply two linked lists

Given elements as nodes of the two singly linked lists. The task is to multiply these two linked lists, say L1 and L2.

Note: The output could be large take modulo 10^9+7.

Examples :

Input: LinkedList L1 : 3->2 , LinkedList L2 : 2
Output: 64
Explanation: 

Multiplication of 32 and 2 gives 64.
Input: LinkedList L1: 1->0->0 , LinkedList L2 : 1->0
Output: 1000
Explanation: 

Multiplication of 100 and 10 gives 1000.
Expected Time Complexity: O(max(n,m))
Expected Auxilliary Space: O(1)
where n is the size of L1 and m is the size of L2

Constraints:
1 <= number of nodes <= 105
1 <= node->data <= 103

*/

class solution {
    int mod = 1e9+7;
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        long long num1 = 0;
        long long num2 = 0;
        
        while(first){
            num1 = (num1 * 10 % mod + first->data) % mod;
            first = first -> next;
        }
        
        while(second){
            num2 = (num2 * 10 % mod + second -> data) % mod;
            second = second -> next;
        }
        
        return (num1 * num2) % mod;
    }
};