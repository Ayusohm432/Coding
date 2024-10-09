/*
Problem Link : https://www.geeksforgeeks.org/problems/linked-list-matrix/1
*/

/*Linked List Matrix

Given a Matrix mat of n*n size. Your task is constructing a 2D linked list representation of the given matrix.

Input: mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
Output: 

Input: mat = [[23, 28], [23, 28]]
Output:

Expected Time Complexity: O(n2)
Expected Space Complexity: O(n2)

Constraints:
1 <= mat.size() <=15
1 <= mat[i][j] <=104

*/
struct Node
{
    int data;
    Node* right, *down;

    Node(int x){
        data = x;
        right = NULL;
        down = NULL;
    }
};


// function must return the pointer to the first element of the in linked list i.e. that
// should be the element at arr[0][0]
class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        // code Here
        int n = mat.size();
        Node *upper=NULL, *prev=NULL, *start=NULL, *head=NULL;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                Node *temp = new Node(mat[i][j]);
                if(!head)head=temp;
                if(!upper)upper=start;
                if(i!=0){
                    upper->down=temp;
                    upper=upper->right;
                }
                if(j==0)start=temp;
                if(j!=0)prev->right=temp;
                prev=temp;
            }
        }
        return head;
    }
    
};